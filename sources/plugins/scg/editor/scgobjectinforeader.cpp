/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#include "scgobjectinforeader.h"

#include <QRegularExpression>
#include <QTextStream>
#include <memory>
#include <QDebug>

#include "scgobjectsinfo.h"
#include "scgnode.h"
#include "scgbus.h"
#include "scgcontour.h"
#include "scgpair.h"

#include <editor/scs/scs_parser.hpp>

SCgObjectInfoReader::SCgObjectInfoReader(bool isOwner) :
    mIsOwner(isOwner),
    mVersion(qMakePair(0, 0))
{
    helper = SCgEditorHelper();
}

SCgObjectInfoReader::SCgObjectInfoReader(QIODevice *dev, QIODevice *layoutdev, bool isOwner):
                                                        mIsOwner(isOwner)
{
    helper = SCgEditorHelper();
    read(dev, layoutdev);
}

SCgObjectInfoReader::~SCgObjectInfoReader()
{
    if (mIsOwner)
        del();
}

void SCgObjectInfoReader::del()
{
    TypeToObjectsMap::iterator it = mObjectsInfo.begin();
    ObjectInfoList::iterator itList;

    for(;it != mObjectsInfo.end(); ++it)
    {
        for(itList = it.value().begin(); itList != it.value().end(); ++itList)
            delete *itList;
        it.value().clear();
    }
    mObjectsInfo.clear();
}

double convertCoor(QString str) {
    if (str.startsWith("neg_")) {
        str = "-" + str.remove(0, 4);
    }
    return str.toDouble();
}

bool SCgObjectInfoReader::read(QIODevice *dev, QIODevice *layoutDev)
{
    if (mIsOwner)
        del();
    mLastError.clear();
    scgStream.setDevice(layoutDev);
    scsStream.setDevice(dev);

    /*QString line = stream.readLine();
    if (line != SCgEditorHelper::SCG_COMMENT)
    {
        mLastError = QString("Given document has unsupported format.");
        return false;
    }*/
    scs::Parser parser;
    parser.Parse(scsStream.readAll().toStdString().append(scgStream.readAll().toStdString()));
    scs::Parser::AliasHandles aliases = parser.GetAliases();
    for (auto const & it : aliases) {
        qDebug() << "-----";
        qDebug() << QString::fromStdString(it.first) << " " << (*it.second) << " " << parser.GetParsedElement(it.second).GetType();
        alias.insert(it.second, QString::fromStdString(it.first));
    }

    scs::Parser::TripleVector triples = parser.GetParsedTriples();
    for (auto const & t : triples) {

        auto const & src = parser.GetParsedElement(t.m_source);
        auto const & edge = parser.GetParsedElement(t.m_edge);
        auto const & trg = parser.GetParsedElement(t.m_target);
        qDebug() << "-----";
        qDebug() << QString::fromStdString(src.GetIdtf()) << " " << QString::number(*(t.m_source));
        qDebug() << QString::fromStdString(edge.GetIdtf()) << " " << QString::number(*(t.m_edge)) << " " << QString::number(edge.GetType());
        qDebug() << QString::fromStdString(trg.GetIdtf()) << " " << QString::number(*(t.m_target));

        if (src.GetIdtf() == "concept_scg_contour") contours.insert(*t.m_target, t.m_target);

        helper.addEdge(t.m_edge, t.m_source, t.m_target);
    }
    for (auto const & contour : contours.keys()) {
        auto set = helper.findRelByIdtf(contours[contour], "nrel_including", parser);
        for (auto member : helper.getOut(set)) {
            parent[member.second] = contours[contour];
        }
    }
    for (auto const & t : triples) {
        qDebug() << "???";
        auto const & src = parser.GetParsedElement(t.m_source);
        auto const & trg = parser.GetParsedElement(t.m_target);
        if (src.GetIdtf() == "nrel_scg_editor_representation") {
            auto pair = helper.getEdge(t.m_target);
            scs::ParsedElement f = parser.GetParsedElement(pair.first);
            scs::ParsedElement s = parser.GetParsedElement(pair.second);
            if (f.GetType().IsNode()) {
                std::unique_ptr<SCgNodeInfo> nodeInfo(new SCgNodeInfo());
                QMap<QString, QString> values;

                for (auto outPair : helper.getOut(pair.second)) {
                    auto inVec = helper.getIn(outPair.first);
                    if (inVec.size() == 1) {
                        auto rel = inVec[0].second;
                        auto val = outPair.second;
                        values.insert(QString::fromStdString(parser.GetParsedElement(rel).GetIdtf()),
                                      QString::fromStdString(parser.GetParsedElement(val).GetIdtf()));
                    }
                }
                nodeInfo->posRef() = QPointF(convertCoor(values["nrel_x"]), convertCoor(values["nrel_y"]));
                nodeInfo->idtfPosRef() = values["nrel_idtf_pos"].toDouble();
                if (f.GetIdtf()[0] == '.') {
                    nodeInfo->idtfValueRef() = "";
                } else {
                    nodeInfo->idtfValueRef() = QString::fromStdString(f.GetIdtf());
                }
                nodeInfo->idRef() = helper.getId(QString::fromStdString(s.GetIdtf()));
                
                if (parent.find(pair.second) != parent.end()) {
                    QString idtf = QString::fromStdString(parser.GetParsedElement(parent[pair.second]).GetIdtf());
                    nodeInfo->parentIdRef() = helper.getId(idtf);
                } else {
                    nodeInfo->parentIdRef() = "0";
                }

                nodeInfo->typeAliasRef() = types[f.GetType()];
                nodeInfo->contentTypeRef() = 0;
                nodeInfo->contentMimeTypeRef() = "";
                nodeInfo->contentVisibleRef() = false;
                nodeInfo->contentDataRef() = QVariant("");
                mObjectsInfo[SCgNode::Type].append(nodeInfo.release());
            } else if (f.GetType().IsEdge()) {
                std::unique_ptr<SCgPairInfo> pairInfo(new SCgPairInfo());
                QMap<QString, scs::ElementHandle> values;

                for (auto outPair : helper.getOut(pair.second)) {
                    auto inVec = helper.getIn(outPair.first);
                    if (inVec.size() == 1) {
                        auto rel = inVec[0].second;
                        auto val = outPair.second;
                        values.insert(QString::fromStdString(parser.GetParsedElement(rel).GetIdtf()), val);
                    }
                }

                pairInfo->idtfValueRef() = "";
                pairInfo->idRef() = helper.getId(QString::fromStdString(s.GetIdtf()));
                pairInfo->beginDotRef() = (QString::fromStdString(parser.GetParsedElement(values["nrel_start_ratio"]).GetIdtf()).toDouble());
                pairInfo->endDotRef() = (QString::fromStdString(parser.GetParsedElement(values["nrel_end_ratio"]).GetIdtf()).toDouble());

                auto p = helper.getEdge(pair.second);
                QString startIdtf = QString::fromStdString(parser.GetParsedElement(p.first).GetIdtf());
                QString endIdtf = QString::fromStdString(parser.GetParsedElement(p.second).GetIdtf());
                pairInfo->beginObjectIdRef() = helper.getId(startIdtf);
                pairInfo->endObjectIdRef() = helper.getId(endIdtf);

                pairInfo->typeAliasRef() = types[f.GetType()];
                pairInfo->parentIdRef() = "0";

                auto set = values["nrel_decomposition"];
                scs::ElementHandle cur;
                pairInfo->pointsRef().push_back(QPointF());
                for (auto memberPair : helper.getOut(set)) {
                    scs::ElementHandle prev = helper.findRelByIdtf(memberPair.second, "nrel_basic_sequence", parser);
                    if (!prev.IsValid()) {
                        cur = memberPair.second;
                        break;
                    }
                }
                while (true) {
                    cur = helper.findRelByIdtf(cur, "nrel_basic_sequence", parser, false);
                    if (!cur.IsValid()) break;
                    auto next = helper.findRelByIdtf(cur, "nrel_basic_sequence", parser, false);
                    if (!next.IsValid()) break;

                    auto x = parser.GetParsedElement(helper.findRelByIdtf(cur, "nrel_x", parser)).GetIdtf();
                    auto y = parser.GetParsedElement(helper.findRelByIdtf(cur, "nrel_y", parser)).GetIdtf();
                    pairInfo->pointsRef().push_back(QPointF(convertCoor(QString::fromStdString(x)),
                                                            convertCoor(QString::fromStdString(y))));
                }
                pairInfo->pointsRef().push_back(QPointF());

                mObjectsInfo[SCgPair::Type].append(pairInfo.release());
            }
        } else if (src.GetIdtf() == "concept_scg_bus") {
            std::unique_ptr<SCgBusInfo> busInfo(new SCgBusInfo());
            QMap<QString, scs::ElementHandle> values;
            QString idtf = QString::fromStdString(trg.GetIdtf());

            for (auto outPair : helper.getOut(t.m_target)) {
                auto inVec = helper.getIn(outPair.first);
                if (inVec.size() == 1) {
                    auto rel = inVec[0].second;
                    auto val = outPair.second;
                    values.insert(QString::fromStdString(parser.GetParsedElement(rel).GetIdtf()), val);
                }
            }

            busInfo->idtfValueRef() = "";
            busInfo->typeAliasRef() = "bus";
            busInfo->idRef() = helper.getId(idtf);
            auto ownerIdtf = parser.GetParsedElement(helper.findRelByIdtf(t.m_target, "nrel_adjacent", parser)).GetIdtf();
            busInfo->ownerIdRef() = helper.getId(QString::fromStdString(ownerIdtf));

            if (parent.find(t.m_target) != parent.end()) {
                QString idtf = QString::fromStdString(parser.GetParsedElement(parent[t.m_target]).GetIdtf());
                busInfo->parentIdRef() = helper.getId(idtf);
            } else {
                busInfo->parentIdRef() = "0";
            }

            auto set = values["nrel_decomposition"];
            scs::ElementHandle cur;
            busInfo->pointsRef().push_back(QPointF());
            for (auto memberPair : helper.getOut(set)) {
                scs::ElementHandle prev = helper.findRelByIdtf(memberPair.second, "nrel_basic_sequence", parser);
                if (!prev.IsValid()) {
                    cur = memberPair.second;
                    break;
                }
            }
            while (true) {
                cur = helper.findRelByIdtf(cur, "nrel_basic_sequence", parser, false);
                if (!cur.IsValid()) break;

                auto x = parser.GetParsedElement(helper.findRelByIdtf(cur, "nrel_x", parser)).GetIdtf();
                auto y = parser.GetParsedElement(helper.findRelByIdtf(cur, "nrel_y", parser)).GetIdtf();
                busInfo->pointsRef().push_back(QPointF(convertCoor(QString::fromStdString(x)),
                                                        convertCoor(QString::fromStdString(y))));
            }

            mObjectsInfo[SCgBus::Type].append(busInfo.release());
        } else if (src.GetIdtf() == "concept_scg_contour") {
            std::unique_ptr<SCgContourInfo> contourInfo(new SCgContourInfo());
            QMap<QString, scs::ElementHandle> values;
            QString idtf = QString::fromStdString(trg.GetIdtf());

            contourInfo->idRef() = helper.getId(idtf);
            contourInfo->idtfValueRef() = "";

            if (parent.find(t.m_target) != parent.end()) {
                QString idtf = QString::fromStdString(parser.GetParsedElement(parent[t.m_target]).GetIdtf());
                contourInfo->parentIdRef() = helper.getId(idtf);
            } else {
                contourInfo->parentIdRef() = "0";
            }

            for (auto outPair : helper.getOut(t.m_target)) {
                auto inVec = helper.getIn(outPair.first);
                if (inVec.size() == 1) {
                    auto rel = inVec[0].second;
                    auto val = outPair.second;
                    values.insert(QString::fromStdString(parser.GetParsedElement(rel).GetIdtf()), val);
                }
            }

            auto set = values["nrel_decomposition"];
            scs::ElementHandle start = helper.getOut(set)[0].second;
            scs::ElementHandle cur = start;
            auto x = parser.GetParsedElement(helper.findRelByIdtf(cur, "nrel_x", parser)).GetIdtf();
            auto y = parser.GetParsedElement(helper.findRelByIdtf(cur, "nrel_y", parser)).GetIdtf();
            contourInfo->pointsRef().push_back(QPointF(convertCoor(QString::fromStdString(x)),
                                                    convertCoor(QString::fromStdString(y))));
            while (true) {
                cur = helper.findRelByIdtf(cur, "nrel_basic_sequence", parser, false);
                if (cur == start) break;

                auto x = parser.GetParsedElement(helper.findRelByIdtf(cur, "nrel_x", parser)).GetIdtf();
                auto y = parser.GetParsedElement(helper.findRelByIdtf(cur, "nrel_y", parser)).GetIdtf();
                contourInfo->pointsRef().push_back(QPointF(convertCoor(QString::fromStdString(x)),
                                                        convertCoor(QString::fromStdString(y))));
            }

            mObjectsInfo[SCgContour::Type].append(contourInfo.release());
        }
    }
    QString line;


    return true;
}

bool SCgObjectInfoReader::getAttributeString(const QDomElement &element, QString attribute, QString &result)
{
    if (element.hasAttribute(attribute))
    {
        result = element.attribute(attribute);
        return true;
    }

    errorHaventAttribute(element.tagName(), attribute);
    return false;
}

bool SCgObjectInfoReader::getAttributeBool(const QDomElement &element, QString attribute, bool &result)
{
    QString strResult;
    if (!getAttributeString(element, attribute, strResult))
        return false;
    else
        if (strResult == "false")
            result = false;
        else if (strResult == "true")
            result = true;
        else
        {
            errorBoolParse(element.tagName(), attribute);
            return false;
        }
    return true;
}

bool SCgObjectInfoReader::getAttributeDouble(const QDomElement &element, QString attribute, double &result)
{
    if (element.hasAttribute(attribute))
    {
        bool res;
        result = element.attribute(attribute).toDouble(&res);

        if (!res) return false;

        return true;
    }

    errorHaventAttribute(element.tagName(), attribute);
    return false;
}

bool SCgObjectInfoReader::getAttributeInt(const QDomElement &element, QString attribute, int &result)
{
    if (element.hasAttribute(attribute))
    {
        bool res;
        result = element.attribute(attribute).toInt(&res);

        if (!res) return false;

        return true;
    }
    errorHaventAttribute(element.tagName(), attribute);
    return false;
}

bool SCgObjectInfoReader::getElementPoints(const QDomElement &element, QVector<QPointF> &result)
{
    QDomElement points = element.firstChildElement("points");
    if (points.isNull())
    {
        mLastError = QObject::tr("There are no points data for element '%1'").arg(element.tagName());
        return false;
    }

    QDomElement point = points.firstChildElement("point");
    while (!point.isNull())
    {
        double x, y;
        if (!getAttributeDouble(point, "x", x) || !getAttributeDouble(point, "y", y))
            return false;
        result.push_back(QPointF(x, y));
        point = point.nextSiblingElement("point");
    }

    return true;
}

void SCgObjectInfoReader::errorHaventAttribute(QString element, QString attribute)
{
    mLastError = QObject::tr("'%1' element haven't '%2' attribute").arg(element).arg(attribute);
}

void SCgObjectInfoReader::errorFloatParse(QString element, QString attribute)
{
    mLastError = QObject::tr("invalid float value in attribute '%1' of element '%2'").arg(attribute).arg(element);
}

void SCgObjectInfoReader::errorBoolParse(QString element, QString attribute)
{
    mLastError = QObject::tr("invalid bollean value in attribute '%1' of element '%2'").arg(attribute).arg(element);
}

void SCgObjectInfoReader::errorHaventContent(QString element)
{
    mLastError = QObject::tr("node element '%1' haven't content tag").arg(element);
}

void SCgObjectInfoReader::errorUnknownElementType(QString element, QString type)
{
    mLastError = QObject::tr("type '%1' is unknown for element '%2'").arg(type).arg(element);
}
