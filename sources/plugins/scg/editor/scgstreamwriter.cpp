#include "scgstreamwriter.h"

#include "scgobject.h"
#include "scgnode.h"
#include "scgbus.h"
#include "scgcontour.h"
#include "scgpair.h"

#include "scgtextitem.h"
#include "scgeditorhelper.h"

#include <QDebug>

const QString SCgStreamWriter::END_LINE = "\n";
const QString SCgStreamWriter::END_PART_SENT = ";\n";
const QString SCgStreamWriter::END_SENT = ";;\n";
const QString SCgStreamWriter::TAB = "\t";

SCgStreamWriter::SCgStreamWriter() {}

void SCgStreamWriter::startWriting(QIODevice *device, QIODevice *layoutDevice)
{
    scs.setDevice(device);
    scg.setDevice(layoutDevice);
}

void SCgStreamWriter::finishWriting()
{
    for (auto obj : waitlist) {
        status[obj] = 0;
        if (obj->type() == SCgPair::Type) {
            SCgPair *pair = static_cast<SCgPair *>(obj);
            if (pair->beginObject()->type() == SCgPair::Type ||
                    pair->beginObject()->type() == SCgContour::Type)
            {
                deps[pair].push_back(pair->beginObject());
            }
            if (pair->endObject()->type() == SCgPair::Type ||
                    pair->endObject()->type() == SCgContour::Type)
            {
                deps[pair].push_back(pair->endObject());
            }
        } else if (obj->type() == SCgContour::Type)
        {
            for (auto ch : children[obj->id()]) {
                if (ch->type() == SCgPair::Type || ch->type() == SCgContour::Type) {
                    deps[obj].push_back(ch);
                }
            }
        }
    }
    for (auto obj : waitlist)
        writeObjectWithDeps(obj);
}

void SCgStreamWriter::writeObjectWithDeps(SCgObject *obj)
{
    enum {STATUS_NOT_QUEUED, STATUS_QUEUED, STATUS_PROCESSED, STATUS_WRITTEN};

    if (status[obj] == STATUS_WRITTEN) return;

    // DFS
    QStack<SCgObject *> stack;
    stack.push_front(obj);
    status[obj] = STATUS_QUEUED;
    while (!stack.isEmpty())
    {
        SCgObject *cur = stack.front();
        if (status[cur] == STATUS_PROCESSED)
        {
            writeObject(cur);
            status[cur] = STATUS_WRITTEN;
            stack.pop_front();
        } else
        {
            for (auto dep : deps[cur])
            {
                if (status[dep] == STATUS_NOT_QUEUED)
                {
                    stack.push_front(dep);
                    status[dep] = STATUS_QUEUED;
                }
            }
            status[cur] = STATUS_PROCESSED;
        }
    }
}

void SCgStreamWriter::processObject(SCgObject *obj) {
    int parId = obj->parentId();
    if (obj->type() == SCgPair::Type || obj->type() == SCgContour::Type) {
        // Delay writing to figure out the order of desired output
        waitlist.push_back(obj);
        if (parId != 0) {
            children[parId].push_back(obj);
        }
        return;
    }
    if (parId != 0) {
        children[parId].push_back(obj);
        return;
    }

    writeObject(obj);
}

void SCgStreamWriter::writeObject(SCgObject *obj)
{
    switch (obj->type())
    {
    case SCgNode::Type:
        writeNode(obj);
        break;
    case SCgPair::Type:
        writePair(obj);
        break;
    case SCgBus::Type:
        writeBus(obj);
        break;
    case SCgContour::Type:
        writeContour(obj);
        break;
    default:
        break;
    }
}

void SCgStreamWriter::writeNode(SCgObject *obj)
{
    SCgNode *node = static_cast<SCgNode*>(obj);

    QString idtf = helper.getIdtf(obj);
    QString scgIdtf = helper.getSCgIdtf(obj);

    // scs
    if (node->contentType() == 0) {
        scs.write(idtf + " <- " + convertType(node->typeAlias()) + END_SENT);
    } else {
        QString content;
        if (node->contentType() == 4) {
            content = node->contentData().toByteArray().toBase64();
        } else {
            content = node->contentData().toString();
        }
        scs.write(idtf + " = " + linkWrap(content) + END_SENT);
    }

    // scg
    RelationValueVector values;
    values.push_back({ "nrel_scg_representation", scgIdtf });
    writeSCgProperties(idtf, values);

    values.clear();
    values.push_back({ "nrel_x", linkWrap(node->scenePos().x()) });
    values.push_back({ "nrel_y", linkWrap(node->scenePos().y()) });
    if (idtf != "") {
        values.push_back({ "nrel_idtf_pos", linkWrap(node->idtfPos()) });
    }
    if (node->contentType() != 0) {
        values.push_back({ "nrel_content_type", linkWrap(node->contentType()) });
        values.push_back({ "nrel_content_mime_type", linkWrap(node->contentMimeType()) });
        values.push_back({ "nrel_content_visible", node->isContentVisible() ? "1" : "0" });
        values.push_back({ "nrel_content_filename", linkWrap(node->contentFileName()) });
    }
    writeSCgProperties(scgIdtf, values);
}

void SCgStreamWriter::writePair(SCgObject *obj)
{
    QString idtf = helper.getIdtf(obj);
    SCgPair *pair = static_cast<SCgPair*>(obj);

    QString scgIdtf = helper.getSCgIdtf(obj);

    // scs
    SCgObject *begin = pair->beginObject(),
            *end = pair->endObject();
    if (begin->type() == SCgBus::Type) begin = static_cast<SCgBus*>(begin)->owner();
    if (end->type() == SCgBus::Type) end = static_cast<SCgBus*>(end)->owner();

    QString buf;
    QTextStream s(&buf);
    s << idtf << " = (" << helper.getIdtf(begin) << " " <<
         convertType(obj->typeAlias()) << " " << helper.getIdtf(end) << ")" << END_SENT;
    scs.write(s.readAll());

    //scg
    begin = pair->beginObject();
    end = pair->endObject();
    buf = QString();
    s.setString(&buf);
    s << scgIdtf << " = (" << helper.getSCgIdtf(begin) << " " <<
         convertType(obj->typeAlias()) << " " << helper.getSCgIdtf(end) << ")" << END_SENT;
    scg.write(s.readAll());

    RelationValueVector values;
    values.push_back({ "nrel_scg_representation", scgIdtf });
    writeSCgProperties(idtf, values);

    values.clear();
    values.push_back({ "nrel_start_ratio", linkWrap(pair->beginDot()) });
    values.push_back({ "nrel_end_ratio", linkWrap(pair->endDot()) });
    writeSCgProperties(scgIdtf, values);

    QVector<QPointF> points = pair->scenePoints();
    points.pop_back();
    points.pop_front();
    writePoints(scgIdtf, points, false);
}

void SCgStreamWriter::writeBus(SCgObject *obj)
{
    QString idtf = helper.getIdtf(obj);
    SCgBus *bus = static_cast<SCgBus *>(obj);

    QString buf;
    QTextStream s(&buf);

    // scg
    s << idtf + END_LINE;
    s << TAB + "<- concept_scg_bus" + END_PART_SENT;
    s << TAB + "=> nrel_owner: " + helper.getSCgIdtf(bus->owner()) + END_SENT;
    scg.write(s.readAll());

    QVector<QPointF> points = bus->scenePoints();
    points.pop_front();
    writePoints(idtf, points, false);
}

void SCgStreamWriter::writeContour(SCgObject *obj)
{
    QString idtf = helper.getIdtf(obj);
    SCgContour *contour = static_cast<SCgContour *>(obj);

    QString buf;
    QTextStream s(&buf);

    s << idtf + " <- concept_scg_contour" + END_SENT;

    auto vec = children[obj->id()];

    if (vec.size() > 0) {
        s << idtf << " => nrel_including: {" << END_LINE;
        for (int i = 0; i < vec.size() - 1; i++) {
            s << TAB << helper.getSCgIdtf(vec[i]) << END_PART_SENT;
        }
        s << TAB << helper.getSCgIdtf(vec[vec.size() - 1]) << END_LINE;
        s << "}" << END_SENT;
    }
    scg.write(s.readAll());

    QVector<QPointF> points = contour->scenePoints();
    writePoints(idtf, points, true);

    scs.write(idtf + " = [*" + END_LINE);
    scs.indent.append(TAB);
    foreach(SCgObject *obj, children[obj->id()]) {
        if (obj->type() != SCgPair::Type)
            writeObject(obj);
    }
    scs.indent.chop(1);
    scs.write("*]" + END_SENT);
}

void SCgStreamWriter::writeSCgProperties(QString const & idtf, RelationValueVector const & relations)
{
    int size = relations.size();
    assert(size != 0);
    QString buf;
    QTextStream s(&buf);
    s << idtf << END_LINE;
    for (int i = 0; i < size; i++) {
        auto relPair = relations[i];
        s << TAB << "=> " << relPair.first << ": " << relPair.second << (i == size - 1 ? END_SENT : END_PART_SENT);
    }
    scg.write(s.readAll());
}

void SCgStreamWriter::writePoints(QString const & idtf, QVector<QPointF> const & points, bool cyclic)
{
    QString buf;
    QTextStream s(&buf);

    int size = points.size();
    QVector<QString> names(size);
    for (int i = 0; i < size; i++) {
        names[i] = helper.getTemp("point");
    }
    s << idtf + " => nrel_decomposition: {" + END_LINE;
    for (int i = 0; i < size; i++) {
        if (i < size - 1) {
            s << TAB + names[i] + END_PART_SENT;
        } else {
            s << TAB + names[size - 1] + END_LINE;
        }
    }
    s << "}" + END_SENT;
    scg.write(s.readAll());
    for (int i = 0; i < size; i++) {
        RelationValueVector values;
        values.push_back({ "nrel_x", linkWrap(points.at(i).x()) });
        values.push_back({ "nrel_y", linkWrap(points.at(i).y()) });
        if (i > 0) {
            values.push_back({ "nrel_basic_sequence", names[i - 1] });
        } else if (cyclic) {
            values.push_back({ "nrel_basic_sequence", names[size - 1] });
        }
        writeSCgProperties(names[i], values);
    }
}

QString SCgStreamWriter::linkWrap(QString const & idtf)
{
    return "[" + idtf + "]";
}

QString SCgStreamWriter::linkWrap(int number)
{
    return "[" + QString::number(number) + "]";
}

QString SCgStreamWriter::linkWrap(double number)
{
    return "[" + QString::number(number) + "]";
}

QString SCgStreamWriter::convertType(QString const & type)
{
    static const QHash<QString, QString> types =
    {
        //const perm
        { "node/const/perm/general", "sc_node" },
        { "node/const/perm/terminal", "sc_node_abstract" },
        { "node/const/perm/struct", "sc_node_struct" },
        { "node/const/perm/tuple", "sc_node_tuple" },
        { "node/const/perm/role", "sc_node_role_relation" },
        { "node/const/perm/relation", "sc_node_norole_relation" },
        { "node/const/perm/group", "sc_node_class" },
        { "node/const/perm/super_group", "sc_node" }, //not supported

        //var perm
        { "node/var/perm/general", "sc_node" },
        { "node/var/perm/terminal", "sc_node_abstract" },
        { "node/var/perm/struct", "sc_node_struct" },
        { "node/var/perm/tuple", "sc_node_tuple" },
        { "node/var/perm/role", "sc_node_role_relation" },
        { "node/var/perm/relation", "sc_node_norole_relation" },
        { "node/var/perm/group", "sc_node_class" },
        { "node/var/perm/super_group", "sc_node" }, //not supported

        { "pair/const/-/perm/noorien", "<=>" },
        { "pair/const/-/perm/orient", "=>"},
        { "pair/const/fuz/perm/orient/membership", "-/>"},
        { "pair/const/neg/perm/orient/membership", "-|>"},
        { "pair/const/pos/perm/orient/membership", "->"},
        { "pair/const/fuz/temp/orient/membership", "~/>" },
        { "pair/const/neg/temp/orient/membership", "~|>" },
        { "pair/const/pos/temp/orient/membership", "~>" },
        { "pair/const/-/temp/noorien", "<=>" }, //not supported
        { "pair/const/-/temp/orient", "=>"}, //not supported

        { "pair/var/-/perm/noorien", "_<=>" },
        { "pair/var/-/perm/orient", "_=>"},
        { "pair/var/fuz/perm/orient/membership", "_-/>"},
        { "pair/var/neg/perm/orient/membership", "_-|>"},
        { "pair/var/pos/perm/orient/membership", "_->"},
        { "pair/var/fuz/temp/orient/membership", "_~/>" },
        { "pair/var/neg/temp/orient/membership", "_~|>" },
        { "pair/var/pos/temp/orient/membership", "_~>" },
        { "pair/var/-/temp/noorien", "_<=>" }, //not supported
        { "pair/var/-/temp/orient", "_=>"}, //not supported

        { "pair/-/-/-/orient", ">" },
        { "pair/-/-/-/noorient", "<>" },
    };

    return types[type];
}

SCgStreamWriter::StreamWriter::StreamWriter()
{
}

SCgStreamWriter::StreamWriter::StreamWriter(QIODevice *device) : stream(device)
{
}

void SCgStreamWriter::StreamWriter::write(QString s)
{
    QTextStream temp(&s);
    while (!temp.atEnd())
        stream << indent << temp.readLine() << END_LINE;
}

void SCgStreamWriter::StreamWriter::setDevice(QIODevice *device)
{
    stream.setDevice(device);
}
