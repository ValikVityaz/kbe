#pragma once

#include "scgeditorhelper.h"

#include <QTextStream>
#include <QVector>
#include <QHash>
#include <memory>

class SCgObject;
class SCgContour;

class StreamWriter;
class QTextStream;

class SCgStreamWriter
{
public:
    typedef QVector<QPair<QString, QString>> RelationValueVector;
    SCgStreamWriter();
    void startWriting(QIODevice *device, QIODevice *layoutDevice);
    void writeObject(SCgObject *object);
    void finishWriting();
    void writeObjectWithDeps(SCgObject *obj);
    void processObject(SCgObject *object);
private:
    class StreamWriter {
    public:
        QString indent;
        StreamWriter();
        StreamWriter(QIODevice *device);
        void write(QString s);
        void setDevice(QIODevice *device);
        ~StreamWriter(){}
    private:
        QTextStream stream;
    };

    static const QString END_LINE;
    static const QString END_PART_SENT;
    static const QString END_SENT;
    static const QString TAB;

    QHash<int, QVector<SCgObject *> > children;
    QHash<SCgObject *, QVector<SCgObject *>> deps;
    QHash<SCgObject *, short> status;

    SCgEditorHelper helper;

    StreamWriter scg;
    StreamWriter scs;
    QString scgBuffer;

    QVector<SCgObject *> waitlist;

    void writeBuffer();

    void writeNode(SCgObject *obj);
    void writePair(SCgObject *obj);
    void writeBus(SCgObject *obj);
    void writeContour(SCgObject *obj);
    void writeSCgProperties(QString const & idtf, const RelationValueVector & properties);
    void writePoints(const QString &idtf, const QVector<QPointF> &points, bool cyclic);

    QString linkWrap(const QString &idtf);
    QString linkWrap(int number);
    QString linkWrap(double number);

    static QString convertType(QString const & type);
};
