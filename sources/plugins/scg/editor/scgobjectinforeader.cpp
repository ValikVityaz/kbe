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
#include <QMap>

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
}

SCgObjectInfoReader::SCgObjectInfoReader(QIODevice *dev, QIODevice *layoutdev, bool isOwner) :
                                                        mIsOwner(isOwner)
{
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

bool SCgObjectInfoReader::read(QIODevice *dev, QIODevice *layoutDev)
{
    if (mIsOwner)
        del();
    mLastError.clear();
    scgStream.setDevice(layoutDev);
    scsStream.setDevice(dev);

    parser.Parse(scsStream.readAll().append(scgStream.readAll()).toStdString());

    for (auto const & it : parser.GetAliases()) {
        qDebug() << "-----";
        qDebug() << QString::fromStdString(it.first) << " " << (*it.second) << " " << parser.GetParsedElement(it.second).GetType();
        aliases.insert(it.second, QString::fromStdString(it.first));
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

        addEdge(t.m_edge, t.m_source, t.m_target);
    }
    for (auto const & contour : contours.keys()) {
        auto set = findRelValByIdtf(contours[contour], "nrel_including");
        for (auto member : getOut(set)) {
            parents[member.second] = contours[contour];
        }
    }
    for (auto const & t : triples) {
        auto const & srcIdtf = parser.GetParsedElement(t.m_source).GetIdtf();
        if (srcIdtf == "nrel_scg_representation") {
            auto pair = getEdge(t.m_target);
            auto type = parser.GetParsedElement(pair.first).GetType();

            if (type.IsNode() || type.IsLink()) {
                parseNode(pair.first, pair.second);
            } else if (type.IsEdge()) {
                parsePair(pair.first, pair.second);
            }
        } else if (srcIdtf == "concept_scg_bus") {
            parseBus(t.m_target);
        } else if (srcIdtf == "concept_scg_contour") {
            parseContour(t.m_target);
        }
    }
    return true;
}

void SCgObjectInfoReader::parseNode(const scs::ElementHandle &node, const scs::ElementHandle &scgNode)
{
    ScType type = parser.GetParsedElement(node).GetType();
    QString idtf = QString::fromStdString(parser.GetParsedElement(node).GetIdtf());
    QString scgIdtf = QString::fromStdString(parser.GetParsedElement(scgNode).GetIdtf());
    auto values = getRelValues(scgNode);

    std::unique_ptr<SCgNodeInfo> nodeInfo(new SCgNodeInfo());

    nodeInfo->posRef() = QPointF(values["nrel_x"].toDouble(), values["nrel_y"].toDouble());
    nodeInfo->idtfPosRef() = values["nrel_idtf_pos"].toDouble();
    if (idtf.startsWith('.')) {
        nodeInfo->idtfValueRef() = "";
    } else {
        nodeInfo->idtfValueRef() = idtf;
    }
    nodeInfo->idRef() = getId(scgIdtf);
    nodeInfo->parentIdRef() = getParentId(scgNode);
    nodeInfo->typeAliasRef() = convertType(type);

    if (type.IsNode()) {
        nodeInfo->contentTypeRef() = 0;
        nodeInfo->contentMimeTypeRef() = "";
        nodeInfo->contentVisibleRef() = false;
        nodeInfo->contentDataRef() = QVariant("");
    } else {
        nodeInfo->contentTypeRef() = values["nrel_content_type"].toInt();
        nodeInfo->contentMimeTypeRef() = values["nrel_content_mime_type"].replace('_','/');
        nodeInfo->contentVisibleRef() = values["nrel_content_visible"].toInt();
        nodeInfo->contentFilenameRef() = values["nrel_content_filename"];
        QString content = QString::fromStdString(parser.GetParsedElement(node).GetValue());
        if (nodeInfo->contentType() == 4) {
            QByteArray arr = QByteArray::fromBase64(content.toLocal8Bit());
            nodeInfo->contentDataRef() = QVariant(arr);
        } else {
            nodeInfo->contentDataRef() = QVariant(content);
        }
    }

    mObjectsInfo[SCgNode::Type].append(nodeInfo.release());
}

void SCgObjectInfoReader::parsePair(const scs::ElementHandle &pair, const scs::ElementHandle &scgPair)
{
    ScType type = parser.GetParsedElement(pair).GetType();
    QString scgIdtf = QString::fromStdString(parser.GetParsedElement(scgPair).GetIdtf());
    auto values = getRelValues(scgPair);

    std::unique_ptr<SCgPairInfo> pairInfo(new SCgPairInfo());

    pairInfo->idtfValueRef() = "";
    pairInfo->idRef() = getId(scgIdtf);
    pairInfo->beginDotRef() = values["nrel_start_ratio"].toDouble();
    pairInfo->endDotRef() = values["nrel_end_ratio"].toDouble();

    auto p = getEdge(scgPair);
    QString startIdtf = QString::fromStdString(parser.GetParsedElement(p.first).GetIdtf());
    QString endIdtf = QString::fromStdString(parser.GetParsedElement(p.second).GetIdtf());
    pairInfo->beginObjectIdRef() = getId(startIdtf);
    pairInfo->endObjectIdRef() = getId(endIdtf);

    pairInfo->typeAliasRef() = convertType(type);
    pairInfo->parentIdRef() = getParentId(scgPair);

    auto set = findRelValByIdtf(scgPair, "nrel_decomposition");
    pairInfo->pointsRef().push_back(QPointF());
    pairInfo->pointsRef().append(getPoints(set));
    pairInfo->pointsRef().push_back(QPointF());

    mObjectsInfo[SCgPair::Type].append(pairInfo.release());
}

void SCgObjectInfoReader::parseBus(const scs::ElementHandle &bus)
{
    std::unique_ptr<SCgBusInfo> busInfo(new SCgBusInfo());
    QString idtf = QString::fromStdString(parser.GetParsedElement(bus).GetIdtf());

    auto values = getRelValues(bus);

    busInfo->idtfValueRef() = "";
    busInfo->typeAliasRef() = "bus";
    busInfo->idRef() = getId(idtf);
    auto ownerIdtf = parser.GetParsedElement(findRelValByIdtf(bus, "nrel_owner")).GetIdtf();
    busInfo->ownerIdRef() = getId(QString::fromStdString(ownerIdtf));
    busInfo->parentIdRef() = getParentId(bus);

    auto set = findRelValByIdtf(bus, "nrel_decomposition");
    busInfo->pointsRef().push_back(QPointF());
    busInfo->pointsRef().append(getPoints(set));

    mObjectsInfo[SCgBus::Type].append(busInfo.release());
}

void SCgObjectInfoReader::parseContour(const scs::ElementHandle &contour)
{
    std::unique_ptr<SCgContourInfo> contourInfo(new SCgContourInfo());
    QString idtf = QString::fromStdString(parser.GetParsedElement(contour).GetIdtf());

    auto values = getRelValues(contour);

    contourInfo->idRef() = getId(idtf);
    contourInfo->idtfValueRef() = "";
    contourInfo->parentIdRef() = getParentId(contour);

    auto set = findRelValByIdtf(contour, "nrel_decomposition");
    contourInfo->pointsRef().append(getPoints(set));

    mObjectsInfo[SCgContour::Type].append(contourInfo.release());
}

QVector<QPointF> SCgObjectInfoReader::getPoints(const scs::ElementHandle &set)
{
    QVector<QPointF> points;
    auto pairs = getOut(set);
    if (pairs.isEmpty()) return points;

    scs::ElementHandle start = getOut(set)[0].second;
    scs::ElementHandle cur = start;
    while (true) {
        if (!cur.IsValid()) break;
        auto x = parser.GetParsedElement(findRelValByIdtf(cur, "nrel_x")).GetValue();
        auto y = parser.GetParsedElement(findRelValByIdtf(cur, "nrel_y")).GetValue();
        points.push_back(QPointF(QString::fromStdString(x).toDouble(),
                                                QString::fromStdString(y).toDouble()));
        cur = findRelValByIdtf(cur, "nrel_basic_sequence", false);
        if (cur == start) return points;
    }
    cur = start;
    while (true) {
        cur = findRelValByIdtf(cur, "nrel_basic_sequence");
        if (!cur.IsValid()) break;
        auto x = parser.GetParsedElement(findRelValByIdtf(cur, "nrel_x")).GetValue();
        auto y = parser.GetParsedElement(findRelValByIdtf(cur, "nrel_y")).GetValue();
        points.push_front(QPointF(QString::fromStdString(x).toDouble(),
                                                QString::fromStdString(y).toDouble()));
    }
    return points;
}

QString SCgObjectInfoReader::convertType(ScType type)
{
    static const QMap<ScType, QString> myTypes = {
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

        { ScType::LinkConst, "node/const/perm/general" },
        { ScType::NodeConst, "node/const/perm/general" },
        { ScType::NodeConstMaterial, "node/const/perm/general" },
        { ScType::NodeConstAbstract, "node/const/perm/terminal" },
        { ScType::NodeConstStruct, "node/const/perm/struct" },
        { ScType::NodeConstTuple, "node/const/perm/tuple" },
        { ScType::NodeConstRole, "node/const/perm/role" },
        { ScType::NodeConstNoRole, "node/const/perm/relation" },
        { ScType::NodeConstClass, "node/const/perm/group" },

        { ScType::LinkVar, "node/var/perm/general" },
        { ScType::NodeVar, "node/var/perm/general" },
        { ScType::NodeVarAbstract, "node/var/perm/terminal" },
        { ScType::NodeVarStruct, "node/var/perm/struct" },
        { ScType::NodeVarTuple, "node/var/perm/tuple" },
        { ScType::NodeVarRole, "node/var/perm/role" },
        { ScType::NodeVarNoRole, "node/var/perm/relation" },
        { ScType::NodeVarClass, "node/var/perm/group" },
    };

    return myTypes[type];
}

void SCgObjectInfoReader::addEdge(const scs::ElementHandle &edge, const scs::ElementHandle &src, const scs::ElementHandle &trg)
{
    edges.insert(edge, qMakePair(src, trg));

    if (outEdges.find(src) == outEdges.end()) {
        outEdges.insert(src, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>());
    }
    outEdges[src].push_back(qMakePair(edge, trg));

    if (inEdges.find(trg) == inEdges.end()) {
        inEdges.insert(trg, QVector<QPair<scs::ElementHandle, scs::ElementHandle>>());
    }
    inEdges[trg].push_back(qMakePair(edge, src));
}

QPair<scs::ElementHandle, scs::ElementHandle> SCgObjectInfoReader::getEdge(const scs::ElementHandle &elHandle)
{
    return edges[elHandle];
}

QVector<QPair<scs::ElementHandle, scs::ElementHandle>> SCgObjectInfoReader::getIn(const scs::ElementHandle &elHandle)
{
    return inEdges[elHandle];
}

QVector<QPair<scs::ElementHandle, scs::ElementHandle>> SCgObjectInfoReader::getOut(const scs::ElementHandle &elHandle)
{
    return outEdges[elHandle];
}

scs::ElementHandle SCgObjectInfoReader::findRelValByIdtf(const scs::ElementHandle &el, QString idtf, bool out)
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

QHash<QString, QString> SCgObjectInfoReader::getRelValues(const scs::ElementHandle &el)
{
    QHash<QString, QString> values;
    for (auto outPair : getOut(el)) {
        auto inVec = getIn(outPair.first);
        for (auto inPair : getIn(outPair.first)) {
            scs::ParsedElement relNode = parser.GetParsedElement(inPair.second);
            scs::ParsedElement relTarget = parser.GetParsedElement(outPair.second);
            /*ScType type = relNode.GetType();
            bool isRelation = ((type & ScType::NodeRole) == type) ||
                    ((type & ScType::NodeNoRole) == type);*/
            if (true) {
                auto value = relTarget.GetType().IsLink() ? relTarget.GetValue() : relTarget.GetIdtf();
                values.insert(QString::fromStdString(relNode.GetIdtf()),
                              QString::fromStdString(value));
            }
        }
    }
    return values;
}

QString SCgObjectInfoReader::getId(QString idtf) {
    static int cnt = 0;
    if (ids.find(idtf) == ids.end()) ids[idtf] = ++cnt;
    return QString::number(ids[idtf]);
}

QString SCgObjectInfoReader::getParentId(scs::ElementHandle const &el) {
    if (parents.find(el) != parents.end()) {
        QString idtf = QString::fromStdString(parser.GetParsedElement(parents[el]).GetIdtf());
        return getId(idtf);
    } else {
        return "0";
    }
}
