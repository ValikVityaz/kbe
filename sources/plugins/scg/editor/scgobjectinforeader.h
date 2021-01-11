#pragma once

#include "scgeditorhelper.h"

#include <QString>
#include <QList>
#include <QVector>
#include <QPointF>
#include <QMap>
#include <QSet>
#include <QHash>
#include <QPair>
#include <QTextStream>

#include <editor/scs/scs_parser.hpp>

class SCgObjectInfo;

//! Reads and stores SCgObjectInfo structures from QDomDocument.
//! NOTE: only *.gwf files are supported.
class SCgObjectInfoReader
{
public:
    typedef QList<SCgObjectInfo*>       ObjectInfoList;
    typedef QMap<int, ObjectInfoList>   TypeToObjectsMap;

    /*!
     * @param isOwner true, if created object must delete all created structures(takes ownership).
     */
    SCgObjectInfoReader(bool isOwner = true);

    //! Automaticaly calls method \ref read() for document @p document.
    explicit SCgObjectInfoReader(QIODevice *dev, QIODevice *layoutdev, bool isOwner = true);

    virtual ~SCgObjectInfoReader();

    /*! Reads info from specified document @p document.
     * NOTE: this method must be called before any access to elements.
     * @see SCgObjectInfoReader(const QDomDocument& document).
     * @return If read successfully returns true. @see lastError().
     */
    bool read(QIODevice *dev, QIODevice *layoutDev);

    //! @return Last error message
    const QString& lastError() const
    {
        return mLastError;
    }

    /**
     * \defgroup accessFunctions Access Functions
     * @{
     */
    const TypeToObjectsMap& objectsInfo() const
    {
        return mObjectsInfo;
    }

    /**@}*/


private:
    //! hold all read object info
    TypeToObjectsMap mObjectsInfo;
    scs::Parser parser;
    QMap<scs::ElementHandle, scs::ElementHandle> parents;
    QMap<int, scs::ElementHandle> contours;
    QHash<QString, int> ids;
    QMap<scs::ElementHandle, QString> aliases;

    QMap<scs::ElementHandle, QPair<scs::ElementHandle, scs::ElementHandle>> edges;
    QMap<scs::ElementHandle, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>> outEdges;
    QMap<scs::ElementHandle, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>> inEdges;
    QTextStream scsStream;
    QTextStream scgStream;

    /**
     * \defgroup parseF Parse Functions
     * @{
     */
    void parseNode(const scs::ElementHandle &node, const scs::ElementHandle &scgNode);
    void parsePair(const scs::ElementHandle &pair, const scs::ElementHandle &scsPair);
    void parseBus(const scs::ElementHandle &bus);
    void parseContour(const scs::ElementHandle &contour);

    QVector<QPointF> getPoints(const scs::ElementHandle &set);

    static QString convertType(ScType type);

    void addEdge(const scs::ElementHandle &edge, const scs::ElementHandle &start, const scs::ElementHandle &end);
    QPair<scs::ElementHandle, scs::ElementHandle> getEdge(const scs::ElementHandle &el);
    QVector<QPair<scs::ElementHandle, scs::ElementHandle>> getIn(const scs::ElementHandle &el);
    QVector<QPair<scs::ElementHandle, scs::ElementHandle>> getOut(const scs::ElementHandle &el);
    scs::ElementHandle findRelValByIdtf(const scs::ElementHandle &el, QString idtf, bool out = true);

    /**@}*/

    QHash<QString, QString> getRelValues(const scs::ElementHandle &el);

    //! Deletes all read info.
    void del();

    //! Holds true if this object takes ownership of created info structures.
    bool mIsOwner;

    QString mLastError;

    QPair<qint32, qint32> mVersion;
    QString getId(QString idtf);
    QString getParentId(const scs::ElementHandle &el);
};
