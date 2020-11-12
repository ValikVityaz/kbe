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
    static const QString IDTF_PATTERN;
    static const QString NUMBER_PATTERN;
    static const QString SCG_COMMENT;
    static const QString PAIR_SCS_PATTERN;
    static const QString PAIR_GWF_PATTERN;
    static const QString BUS_GWF_PATTERN;
    static const QString CONTOUR_SCS_PATTERN;
    static const QString CONTOUR_GWF_PATTERN;
    static const QString CONTOUR_END_SCS_PATTERN;
    static const QString END_LINE;
    static const QString END_PART_SENT;
    static const QString END_SENT;
    static QHash<QString, QString> typeMap;

    static QString convertType(QString type);

    SCgEditorHelper();

    QString getIdtf(QString prefix);

    QString getIdtf(SCgObject *obj);

    QString getSCgIdtf(SCgObject *obj);

    QString getConnector(SCgPair *pair);

    QString getPairString(SCgObject *obj);
    QString getContourString(SCgObject *obj);
    QString getId(QString idtf);
    QString getBusString(SCgObject *bus);
    QString getAlias(QString base);
    QString getTemp(QString base);

    void addEdge(scs::ElementHandle, scs::ElementHandle, scs::ElementHandle);
    QPair<scs::ElementHandle, scs::ElementHandle> getEdge(scs::ElementHandle);
    QVector<QPair<scs::ElementHandle, scs::ElementHandle>> getIn(scs::ElementHandle);
    QVector<QPair<scs::ElementHandle, scs::ElementHandle>> getOut(scs::ElementHandle);
    scs::ElementHandle findRelByIdtf(scs::ElementHandle, QString idtf, scs::Parser parser, bool out = true);
private:

    QMap<scs::ElementHandle, QPair<scs::ElementHandle, scs::ElementHandle>> *edges;
    QMap<scs::ElementHandle, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>> *outEdges;
    QMap<scs::ElementHandle, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>> *inEdges;

    QHash<QString, int> count;
    QHash<int, QString> names;
    QHash<int, QString> scgNodeNames;
    QHash<QString, int> ids;
    QHash<QString, int> infoMap;
    int cnt = 1;
    static QString getPairString(QString idtf, QString scgIdtf, QString start, QString end, QString type, QString startRatio, QString endRatio, QString idtfPosX, QString idtfPosY, QString points);
    static QString getBusString(bool isRegEx, QString idtf, QString owner, QString points);
    static QString getContourString(bool isRegEx, QString idtf, QString points);
};
