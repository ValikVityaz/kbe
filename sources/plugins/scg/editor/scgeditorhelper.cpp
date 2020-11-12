#include "scgeditorhelper.h"
#include "scgobject.h"
#include "scgnode.h"
#include "scgbus.h"
#include "scgcontour.h"
#include "scgpair.h"

#include <QTextStream>
#include <QVector>

QHash<QString, QString> SCgEditorHelper::typeMap = {
    //const perm
    { "node/const/perm/general", "sc_node_not_relation" },
    { "node/const/perm/terminal", "sc_node_abstract" },
    { "node/const/perm/struct", "sc_node_struct" },
    { "node/const/perm/tuple", "sc_node_tuple" },
    { "node/const/perm/role", "sc_node_role_relation" },
    { "node/const/perm/relation", "sc_node_norole_relation" },
    { "node/const/perm/group", "sc_node_class" },

    //var perm
    { "node/var/perm/general", "sc_node_not_relation" },
    { "node/var/perm/terminal", "sc_node_abstract" },
    { "node/var/perm/struct", "sc_node_struct" },
    { "node/var/perm/tuple", "sc_node_tuple" },
    { "node/var/perm/role", "sc_node_role_relation" },
    { "node/var/perm/relation", "sc_node_norole_relation" },
    { "node/var/perm/group", "sc_node_class" },

    { "sc_node_not_relation", "node/-/perm/general" },
    { "sc_node_abstract", "node/-/perm/terminal" },
    { "sc_node_struct", "node/-/perm/struct" },
    { "sc_node_tuple", "node/-/perm/tuple" },
    { "sc_node_role_relation", "node/-/perm/role" },
    { "sc_node_norole_relation", "node/-/perm/relation" },
    { "sc_node_class", "node/-/perm/group" },

    { "pair/const/-/perm/noorien", "<=>" },
    { "pair/const/-/perm/orient", "=>"},
    { "pair/const/fuz/perm/orient/membership", "-/>"},
    { "pair/const/neg/perm/orient/membership", "-|>"},
    { "pair/const/pos/perm/orient/membership", "->"},
    { "pair/const/fuz/temp/orient/membership", "~/>" },
    { "pair/const/neg/temp/orient/membership", "~|>" },
    { "pair/const/pos/temp/orient/membership", "~>" },

    { "<=>", "pair/const/-/perm/noorien" },
    { "=>", "pair/const/-/perm/orient" },
    { "-/>", "pair/const/fuz/perm/orient/membership" },
    { "-|>", "pair/const/neg/perm/orient/membership" },
    { "->", "pair/const/pos/perm/orient/membership" },
    { "~/>", "pair/const/fuz/temp/orient/membership" },
    { "~|>", "pair/const/neg/temp/orient/membership" },
    { "~>", "pair/const/pos/temp/orient/membership" },

    { "pair/var/-/perm/noorien", "_<=>" },
    { "pair/var/-/perm/orient", "_=>"},
    { "pair/var/fuz/perm/orient/membership", "_-/>"},
    { "pair/var/neg/perm/orient/membership", "_-|>"},
    { "pair/var/pos/perm/orient/membership", "_->"},
    { "pair/var/fuz/temp/orient/membership", "_~/>" },
    { "pair/var/neg/temp/orient/membership", "_~|>" },
    { "pair/var/pos/temp/orient/membership", "_~>" },

    { "_<=>", "pair/var/-/perm/noorien" },
    { "_=>", "pair/var/-/perm/orient" },
    { "_-/>", "pair/var/fuz/perm/orient/membership" },
    { "_-|>", "pair/var/neg/perm/orient/membership" },
    { "_->", "pair/var/pos/perm/orient/membership" },
    { "_~/>", "pair/var/fuz/temp/orient/membership" },
    { "_~|>", "pair/var/neg/temp/orient/membership" },
    { "_~>", "pair/var/pos/temp/orient/membership" },

    { ">", "pair/-/-/-/orient" },
    { "<>", "pair/-/-/-/noorient" },

    { "pair/-/-/-/orient", ">" },
    { "pair/-/-/-/noorient", "<>" },
};

QString getGroup(QString, QString);

const QString SCgEditorHelper::END_LINE = "\n";
const QString SCgEditorHelper::END_PART_SENT = ";\n";
const QString SCgEditorHelper::END_SENT = ";;\n";
const QString SCgEditorHelper::SCG_COMMENT = "// SCG_FORMAT";

SCgEditorHelper::SCgEditorHelper()
{
    edges = new QMap<scs::ElementHandle, QPair<scs::ElementHandle, scs::ElementHandle>>();
    inEdges = new QMap<scs::ElementHandle, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>>();
    outEdges = new QMap<scs::ElementHandle, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>>();
}

QString SCgEditorHelper::getIdtf(QString base)
{
    return base + QString::number(count[base]++);
}

QString SCgEditorHelper::getAlias(QString base) {
    return "@" + base;
}

QString SCgEditorHelper::getTemp(QString base) {
    return ".." + base;
}

void SCgEditorHelper::addEdge(scs::ElementHandle edge, scs::ElementHandle src, scs::ElementHandle trg)
{
    (*edges).insert(edge, qMakePair(src, trg));

    if ((*outEdges).find(src) == (*outEdges).end()) {
        (*outEdges).insert(src, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>());
    }
    (*outEdges)[src].push_back(qMakePair(edge, trg));

    if ((*inEdges).find(trg) == (*inEdges).end()) {
        (*inEdges).insert(trg, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>());
    }
    (*inEdges)[trg].push_back(qMakePair(edge, src));
}

QPair<scs::ElementHandle, scs::ElementHandle> SCgEditorHelper::getEdge(scs::ElementHandle elHandle)
{
    return (*edges)[elHandle];
}

QVector<QPair<scs::ElementHandle, scs::ElementHandle>> SCgEditorHelper::getIn(scs::ElementHandle elHandle)
{
    return (*inEdges)[elHandle];
}

QVector<QPair<scs::ElementHandle, scs::ElementHandle>> SCgEditorHelper::getOut(scs::ElementHandle elHandle)
{
    return (*outEdges)[elHandle];
}

scs::ElementHandle SCgEditorHelper::findRelByIdtf(scs::ElementHandle el, QString idtf, scs::Parser parser, bool out)
{
    auto edgePairs = (out ? getOut(el) : getIn(el));
    for (auto pair : edgePairs) {
        for (auto pair2 : getIn(pair.first)) {
            auto rel = pair2.second;
            if (QString::fromStdString(parser.GetParsedElement(rel).GetIdtf()) == idtf) return pair.second;
        }
    }
    return scs::ElementHandle();
}

QString SCgEditorHelper::getIdtf(SCgObject *obj)
{
    uint64_t id = obj->id();
    if (names.find(id) != names.end()) return names[id];

    QString name;
    if (obj->idtfValue().length() != 0) {
        name = obj->idtfValue();
        if (obj->type() == SCgPair::Type || obj->type() == SCgContour::Type) {
            name = getAlias(name);
        }
        return name;
    }

    switch (obj->type())
    {
    case SCgNode::Type:
        name = "node";
        break;
    case SCgPair::Type:
        name = "pair";
        break;
    case SCgBus::Type:
        name = "bus";
        break;
    case SCgContour::Type:
        name = "contour";
        break;
    default:
        break;
    }

    if (obj->type() == SCgNode::Type) {
        SCgAlphabet &alphabet = SCgAlphabet::getInstance();
        QStringList splittedAlias = obj->typeAlias().split("/");
        bool isVar = splittedAlias.at(1) == alphabet.aliasFromConstCode(SCgAlphabet::Var);
        if (isVar) name = '_' + name;
    }
    name = getIdtf(name);

    if (obj->type() == SCgPair::Type || obj->type() == SCgContour::Type) {
        name = getAlias(name);
    } else {
        name = getTemp(name);
    }

    names[obj->id()] = name;
    return name;
}

QString SCgEditorHelper::getSCgIdtf(SCgObject *obj) {
    if (obj->type() != SCgNode::Type && obj->type() != SCgPair::Type) return getIdtf(obj);

    uint64_t id = obj->id();
    if (scgNodeNames.find(id) == scgNodeNames.end()) {
        if (obj->type() == SCgNode::Type) scgNodeNames[id] = getTemp(getIdtf("scgNode"));
        if (obj->type() == SCgPair::Type) scgNodeNames[id] = getAlias(getIdtf("scgPair"));
    }

    return scgNodeNames[id];
}

QString SCgEditorHelper::convertType(QString type) {
    const QString NOT_SUPPORTED = "not_supported_";
    if (!typeMap.contains(type)) {
        if (type.startsWith(NOT_SUPPORTED)) {
            type.remove(0, NOT_SUPPORTED.length());
        } else {
            type.insert(0, NOT_SUPPORTED);
        }
        return type;
    }
    return typeMap[type];
}

QString SCgEditorHelper::getId(QString idtf) {
    if (ids.find(idtf) == ids.end()) ids[idtf] = cnt++;
    return QString::number(ids[idtf]);
}
