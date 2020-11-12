#include "scgstreamwriter.h"

#include "scgobject.h"
#include "scgnode.h"
#include "scgbus.h"
#include "scgcontour.h"
#include "scgpair.h"

#include "scgtextitem.h"
#include "scgeditorhelper.h"

#include <QDebug>

SCgStreamWriter::SCgStreamWriter()
{
    helper = SCgEditorHelper();
}

void SCgStreamWriter::startWriting(QIODevice *device, QIODevice *layoutDevice)
{
    scsWriter = std::make_unique<StreamWriter>(device);
    scgWriter = std::make_unique<StreamWriter>(layoutDevice);

    //*scsWriter << SCgEditorHelper::SCG_COMMENT << "\n";
}


void SCgStreamWriter::writeWaitlist()
{
    foreach(SCgContour *contour, contourWaitlist) {
        writeContour(contour);
    }
}

void SCgStreamWriter::finishWriting()
{
    writeWaitlist();
}

void SCgStreamWriter::processObject(SCgObject *obj) {
    int parId = obj->parentId();
    if (parId != 0 && obj->type() != SCgPair::Type) {
        contourChildren[parId].push_back(obj);
        return;
    }

    if (obj->type() == SCgContour::Type) {
        contourWaitlist.push_back(static_cast<SCgContour *>(obj));
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
    QString TAB = "\t";
    QString END_LINE = "\n";
    QString END_SENT = ";;\n";
    QString END_PART_SENT = ";\n";
    SCgNode *node = static_cast<SCgNode*>(obj);
    QString idtf = helper.getIdtf(obj);
    QString scgIdtf = helper.getSCgIdtf(obj);
    int idtfPos = node->idtfPos();
    scsWriter->write(idtf + " <- " + helper.convertType(node->typeAlias()) + ";;\n");

    QString buf;
    QTextStream s(&buf);
    s << (idtf + " => nrel_scg_editor_representation: " + scgIdtf + END_SENT);
    s << (scgIdtf + END_LINE);
    double x = node->scenePos().x();
    double y = node->scenePos().y();
    s << (TAB + "=> nrel_x: " + (x >= 0 ? QString::number(x) : "neg_" + QString::number(abs(x))) + END_PART_SENT);
    s << (TAB + "=> nrel_y: " + (y >= 0 ? QString::number(y) : "neg_" + QString::number(abs(y))));
    if (idtf != "") {
        s << (END_PART_SENT + TAB + "=> nrel_idtf_pos: " + QString::number(idtfPos));
    }
    s << (END_SENT);
    s << (END_LINE);
    scgWriter->write(s.readAll());
}

void SCgStreamWriter::writePair(SCgObject *obj)
{
    QString TAB = "\t";
    QString END_LINE = "\n";
    QString END_SENT = ";;\n";
    QString END_PART_SENT = ";\n";

    QString idtf = helper.getIdtf(obj);
    QString scgIdtf = helper.getSCgIdtf(obj);
    SCgPair *pair = static_cast<SCgPair*>(obj);
    SCgObject *begin = pair->beginObject(),
            *end = pair->endObject();
    if (begin->type() == SCgBus::Type) begin = static_cast<SCgBus*>(begin)->owner();
    if (end->type() == SCgBus::Type) end = static_cast<SCgBus*>(end)->owner();
    scsWriter->write(idtf + " = (" + helper.getIdtf(begin) + " " +
                     SCgEditorHelper::convertType(obj->typeAlias()) + " " + helper.getIdtf(end) + ");;\n");

    begin = pair->beginObject();
    end = pair->endObject();
    QString buf;
    QTextStream s(&buf);

    s << (scgIdtf + " = (" + helper.getSCgIdtf(begin) + " " +
        SCgEditorHelper::convertType(obj->typeAlias()) + " " +
        helper.getSCgIdtf(end) + ")" + END_SENT);
    s << idtf + " => nrel_scg_editor_representation: " + scgIdtf + END_SENT;
    s << scgIdtf + END_LINE;
    s << TAB + "=> nrel_start_ratio: " + QString::number(pair->beginDot()) + END_PART_SENT;
    s << TAB + "=> nrel_end_ratio: " + QString::number(pair->endDot()) + END_SENT;
    int size = pair->points().size();
    QVector<QString> names(size);
    for (int i = 0; i < size; i++) {
        names[i] = helper.getTemp(helper.getIdtf("point"));
    }
    s << scgIdtf + " => nrel_decomposition: {" + END_LINE;
    for (int i = 0; i < size - 1; i++) {
        s << TAB + names[i] + END_PART_SENT;
    }
    s << TAB + names[size - 1] + END_LINE;
    s << "}" + END_SENT;
    for (int i = 1; i < size - 1; i++) {
        double x = pair->pointAt(i).x();
        double y = pair->pointAt(i).y();
        s << names[i] + " => nrel_x: " + (x >= 0 ? QString::number(x) : "neg_" + QString::number(abs(x))) +
             "; => nrel_y: " + (y >= 0 ? QString::number(y) : "neg_" + QString::number(abs(y))) + END_SENT;
        s << names[i] + " => nrel_basic_sequence: " + names[i - 1] + END_SENT;
    }
    s << names[size - 1] + " => nrel_basic_sequence: " + names[size - 2] + END_SENT;
    s << END_LINE;
    scgWriter->write(s.readAll());
}

void SCgStreamWriter::writeBus(SCgObject *obj)
{
    QString TAB = "\t";
    QString END_LINE = "\n";
    QString END_SENT = ";;\n";
    QString END_PART_SENT = ";\n";

    QString idtf = helper.getIdtf(obj);
    SCgBus *bus = static_cast<SCgBus *>(obj);

    QString buf;
    QTextStream s(&buf);

    s << idtf + END_LINE;
    s << TAB + "<- concept_scg_bus" + END_PART_SENT;
    s << TAB + "=> nrel_adjacent: " + helper.getSCgIdtf(bus->owner()) + END_SENT;

    int size = bus->points().size();
    QVector<QString> names(size);
    bool isOwnerNode = (bus->owner()->type() == SCgNode::Type);
    for (int i = 0; i < size; i++) {
        if (i == 0 && isOwnerNode) {
            names[i] = helper.getSCgIdtf(bus->owner());
            continue;
        }
        names[i] = helper.getIdtf("point");
    }
    s << idtf + " => nrel_decomposition: {" + END_LINE;
    for (int i = 0; i < size - 1; i++) {
        s << TAB + names[i] + END_PART_SENT;
    }
    s << TAB + names[size - 1] + END_LINE;
    s << "}" + END_SENT;

    for (int i = 1; i < size; i++) {
        double x = bus->pointAt(i).x();
        double y = bus->pointAt(i).y();
        s << names[i] + " => nrel_x: " + (x >= 0 ? QString::number(x) : "neg_" + QString::number(abs(x))) +
             "; => nrel_y: " + (y >= 0 ? QString::number(y) : "neg_" + QString::number(abs(y))) + END_SENT;
        s << names[i] + " => nrel_basic_sequence: " + names[i - 1] + END_SENT;
    }
    s << END_LINE;

    scgWriter->write(s.readAll());
}

void SCgStreamWriter::writeContour(SCgObject *obj)
{
    QString TAB = "\t";
    QString END_LINE = "\n";
    QString END_SENT = ";;\n";
    QString END_PART_SENT = ";\n";

    QString idtf = helper.getIdtf(obj);
    SCgContour *contour = static_cast<SCgContour *>(obj);

    QString buf;
    QTextStream s(&buf);

    s << idtf + " <- concept_scg_contour" + END_SENT;

    auto vec = contourChildren[obj->id()];

    if (vec.size() > 0) {
        s << idtf << " => nrel_including: {" << END_LINE;
        for (int i = 0; i < vec.size() - 1; i++) {
            s << TAB << helper.getSCgIdtf(vec[i]) << END_PART_SENT;
        }
        s << TAB << helper.getSCgIdtf(vec[vec.size() - 1]) << END_LINE;
        s << "}" << END_SENT;
    }

    int size = contour->scenePoints().size();
    QVector<QString> names(size);
    for (int i = 0; i < size; i++) {
        names[i] = helper.getTemp(helper.getIdtf("point"));
    }
    s << idtf + " => nrel_decomposition: {" + END_LINE;
    for (int i = 0; i < size - 1; i++) {
        s << TAB + names[i] + END_PART_SENT;
    }
    s << TAB + names[size - 1] + END_LINE;
    s << "}" + END_SENT;

    names.push_front(names[names.size() - 1]);
    size = names.size();
    for (int i = 1; i < size; i++) {
        double x = contour->scenePoints().at(i - 1).x();
        double y = contour->scenePoints().at(i - 1).y();
        s << names[i] + " => nrel_x: " + (x >= 0 ? QString::number(x) : ("neg_" + QString::number(abs(x)))) +
             "; => nrel_y: " + (y >= 0 ? QString::number(y) : ("neg_" + QString::number(abs(y)))) + END_SENT;
        s << names[i] + " => nrel_basic_sequence: " + names[i - 1] + END_SENT;
    }
    s << END_LINE;
    scgWriter->write(s.readAll());

    scsWriter->write(idtf + " = [*" + END_LINE);
    scsWriter->indentLvl++;
    foreach(SCgObject *obj, contourChildren[obj->id()]) {
        writeObject(obj);
    }

    scsWriter->indentLvl--;
    scsWriter->write("*]" + END_SENT);
}

QString SCgStreamWriter::convertType(QString type) {
    return SCgEditorHelper::convertType(type);
}
