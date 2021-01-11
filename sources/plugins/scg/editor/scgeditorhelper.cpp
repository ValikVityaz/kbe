#include "scgeditorhelper.h"
#include "scgobject.h"
#include "scgnode.h"
#include "scgbus.h"
#include "scgcontour.h"
#include "scgpair.h"

#include <QTextStream>
#include <QVector>

SCgEditorHelper::SCgEditorHelper()
{
}

QString SCgEditorHelper::getIdtf(QString base)
{
    return base + QString::number(count[base]++);
}

QString SCgEditorHelper::makeAlias(QString base) {
    return "@" + base;
}

QString SCgEditorHelper::makeTemp(QString base) {
    return ".." + base;
}

QString SCgEditorHelper::getIdtf(SCgObject *obj)
{
    // Check if idtf is already defined.
    uint64_t id = obj->id();
    if (names.find(id) != names.end()) return names[id];

    // Check if idtf is user-defined
    QString name = obj->idtfValue();
    if (!name.isEmpty()) {
        if (obj->type() == SCgPair::Type || obj->type() == SCgContour::Type) {
            name = makeAlias(name);
        }
        names[id] = name;
        return names[id];
    }

    // Define idtf when it is not user-defined
    if (obj->type() == SCgNode::Type) {
        SCgNode *node = static_cast<SCgNode*>(obj);
        if (node->contentType() != 0) {
            name = getAlias("link");
            names[id] = name;
        } else {
            SCgAlphabet &alphabet = SCgAlphabet::getInstance();
            QStringList splittedAlias = obj->typeAlias().split("/");
            bool isVar = splittedAlias.at(1) == alphabet.aliasFromConstCode(SCgAlphabet::Var);
            if (isVar) {
                names[id] = getTemp("_node");
            } else {
                names[id] = getTemp("node");
            }
        }
    } else if (obj->type() == SCgPair::Type) {
        names[id] = getAlias("pair");
    } else if (obj->type() == SCgBus::Type) {
        names[id] = getTemp("bus");
    } else if (obj->type() == SCgContour::Type) {
        names[id] = getAlias("contour");
    }
    return names[id];
}

QString SCgEditorHelper::getSCgIdtf(SCgObject *obj) {
    if (obj->type() != SCgNode::Type && obj->type() != SCgPair::Type) return getIdtf(obj);

    uint64_t id = obj->id();
    if (scgNames.find(id) == scgNames.end()) {
        if (obj->type() == SCgNode::Type) scgNames[id] = getTemp("scgNode");
        if (obj->type() == SCgPair::Type) scgNames[id] = getAlias("scgPair");
    }

    return scgNames[id];
}

QString SCgEditorHelper::getAlias(QString base)
{
    return makeAlias(getIdtf(base));
}

QString SCgEditorHelper::getTemp(QString base)
{
    return makeTemp(getIdtf(base));
}
