#pragma once

#include <QString>
#include <QHash>
#include <QStack>

#include <editor/scs/scs_parser.hpp>

class SCgObject;
class SCgPair;

class SCgEditorHelper
{
public:
    SCgEditorHelper();

    QString getIdtf(QString prefix);
    QString getIdtf(SCgObject *obj);
    QString getSCgIdtf(SCgObject *obj);
    QString getAlias(QString base);
    QString getTemp(QString base);
    static QString makeAlias(QString base);
    static QString makeTemp(QString base);
private:
    QHash<QString, int> count;
    QHash<int, QString> names;
    QHash<int, QString> scgNames;
    int cnt = 1;
};
