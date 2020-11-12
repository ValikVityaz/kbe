#pragma once

#include "scgeditorhelper.h"

#include <QDomDocument>
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
    QMap<ScType, QString> types = {
        { ScType::EdgeUCommonConst, "pair/const/-/perm/noorien" },
        { ScType::EdgeDCommonConst, "pair/const/-/perm/orient" },
        { ScType::EdgeAccessConstFuzPerm, "pair/const/fuz/perm/orient/membership" },
        { ScType::EdgeAccessConstNegPerm, "pair/const/neg/perm/orient/membership" },
        { ScType::EdgeAccessConstPosPerm, "pair/const/pos/perm/orient/membership" },
        { ScType::EdgeAccessConstFuzTemp, "pair/const/fuz/temp/orient/membership" },
        { ScType::EdgeAccessConstNegTemp, "pair/const/neg/temp/orient/membership" },
        { ScType::EdgeAccessConstPosTemp, "pair/const/pos/temp/orient/membership" },

        { ScType::EdgeUCommonVar, "pair/var/-/perm/noorien" },
        { ScType::EdgeDCommonVar, "pair/var/-/perm/orient" },
        { ScType::EdgeAccessVarFuzPerm, "pair/var/fuz/perm/orient/membership" },
        { ScType::EdgeAccessVarNegPerm, "pair/var/neg/perm/orient/membership" },
        { ScType::EdgeAccessVarPosPerm, "pair/var/pos/perm/orient/membership" },
        { ScType::EdgeAccessVarFuzTemp, "pair/var/fuz/temp/orient/membership" },
        { ScType::EdgeAccessVarNegTemp, "pair/var/neg/temp/orient/membership" },
        { ScType::EdgeAccessVarPosTemp, "pair/var/pos/temp/orient/membership" },

        { ScType::EdgeDCommon, "pair/-/-/-/orient" },
        { ScType::EdgeUCommon, "pair/-/-/-/noorient" },

        { ScType::NodeConst, "node/const/perm/general" },
        { ScType::NodeConstMaterial, "node/const/perm/general" },
        { ScType::NodeConstAbstract, "node/const/perm/terminal" },
        { ScType::NodeConstStruct, "node/const/perm/struct" },
        { ScType::NodeConstTuple, "node/const/perm/tuple" },
        { ScType::NodeConstRole, "node/const/perm/role" },
        { ScType::NodeConstNoRole, "node/const/perm/relation" },
        { ScType::NodeConstClass, "node/const/perm/group" },

        { ScType::NodeVarMaterial, "node/var/perm/general" },
        { ScType::NodeVarAbstract, "node/var/perm/terminal" },
        { ScType::NodeVarStruct, "node/var/perm/struct" },
        { ScType::NodeVarTuple, "node/var/perm/tuple" },
        { ScType::NodeVarRole, "node/var/perm/role" },
        { ScType::NodeVarNoRole, "node/var/perm/relation" },
        { ScType::NodeVarClass, "node/var/perm/group" },
    };
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
    typedef QMap<QString, QString> GWFType2TypeAliasMap;


    //! hold all read object info
    TypeToObjectsMap mObjectsInfo;
    QTextStream scsStream;
    QTextStream scgStream;
    SCgEditorHelper helper;
    scs::Parser parser;
    QMap<scs::ElementHandle, scs::ElementHandle> parent;
    QMap<scs::ElementHandle, QString> alias;
    QMap<int, scs::ElementHandle> contours;

    /**
     * \defgroup parseF Parse Functions
     * @{
     */
    bool parseObject(const QDomElement& element, SCgObjectInfo* info);

    /**@}*/

    /*! Gets string value of attribute
      @param element Element to get attribute value from.
      @param attribute Attribute name.
      @param result Reference to result receiver.

      @return If value got normally, then return true, else - false
      */
    bool getAttributeString(const QDomElement &element, QString attribute, QString &result);

    /*! Gets boolean value of attribute
      @param element Element to get attribute value from.
      @param attribute Attribute name.
      @param result Reference to result receiver.

      @return If value got normally, then return true, else - false
      */
    bool getAttributeBool(const QDomElement &element, QString attribute, bool &result);

    /*! Gets float value of attribute
      @param element Element to get attribute value from.
      @param attribute Attribute name.
      @param result Reference to result receiver.

      @return If value got normally, then return true, else - false
      */
    bool getAttributeDouble(const QDomElement &element, QString attribute, double &result);

    /*! Gets int value of attribute
      @param element Element to get attribute value from.
      @param attribute Attribute name.
      @param result Reference to result receiver.

      @return If value got normally, then return true, else - false
      */
    bool getAttributeInt(const QDomElement &element, QString attribute, int &result);

    /*! Gets point for a line object
      @param element Element to get points from.
      @param result Reference for a point vector to write results.

      @return If points got normally, then return true, else - false.
      */
    bool getElementPoints(const QDomElement &element, QVector<QPointF> &result);

    /*! Generates last error message for non existing attribute error.
      @param element Element tag name.
      @param attribute Attribute name.
      */
    void errorHaventAttribute(QString element, QString attribute);

    /*! Generates last error message for error in float value parsing
      @param element Element tag name.
      @param attribute Attribute name.
      */
    void errorFloatParse(QString element, QString attribute);

    /*! Generates last error message for error in boolean value parsing
      @param element Element tag name.
      @param attribute Attribute name.
      */
    void errorBoolParse(QString element, QString attribute);

    /*! Generates last error message for node without content tag
      @param element Element tag name
      */
    void errorHaventContent(QString element);

    /*! Generates last error message for unknown element type error.
      @param element Element tag name.
      @param type Type value.
      */
    void errorUnknownElementType(QString element, QString type);

    //! Deletes all read info.
    void del();

    //! Holds true if this object takes ownership of created info structures.
    bool mIsOwner;

    QString mLastError;

    QPair<qint32, qint32> mVersion;
};
