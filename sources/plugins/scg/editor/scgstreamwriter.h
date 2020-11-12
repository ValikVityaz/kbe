#pragma once

#include "scgeditorhelper.h"

#include <QBuffer>
#include <QTextStream>
#include <QVector>
#include <QStack>
#include <QHash>
#include <algorithm>
#include <memory>
#include <bits/shared_ptr.h>
#include <bits/unique_ptr.h>
#include <sstream>

class SCgObject;
class SCgContour;

class StreamWriter;
class QTextStream;

class SCgStreamWriter
{
public:
    SCgStreamWriter();
    void startWriting(QIODevice * device, QIODevice *layoutDevice);
    void writeObject(SCgObject *object);
    void finishWriting();
    void processObject(SCgObject *object);
private:
    SCgEditorHelper helper;
    QHash<int, QVector<SCgObject *> > contourChildren;

    std::unique_ptr<StreamWriter> scsWriter;
    std::unique_ptr<StreamWriter> scgWriter;
    QString scgBuffer;

    QVector<SCgContour *> contourWaitlist;

    void writeBuffer();
    void writeWaitlist();

    void write(QString ...);

    void writeNode(SCgObject *obj);
    void writePair(SCgObject *obj);
    void writeBus(SCgObject *obj);
    void writeContour(SCgObject *obj);

    void writeCoordinates(QString scgNodeName, QPointF pos);
    void writePoints(QVector<QPoint> &vector);
    QString convertType(QString type);
};

class StreamWriter {
public:
    StreamWriter(QIODevice *device) {
        stream = std::make_shared<QTextStream>(device);
        indentLvl = 0;
    }
    StreamWriter(QString *str) {
        stream = std::make_shared<QTextStream>(str);
        indentLvl = 0;
    }
    ~StreamWriter(){}

    QStack<QString> st;

    void startBlock(QString br) {
        int len = br.length();
        assert(len % 2 == 0);
        this->operator<<(br.mid(0, len / 2)) << '\n';
        st.push(br.mid(len / 2, len / 2));
        ++indentLvl;
    }

    void endBlock() {
        --indentLvl;
        this->operator<<(st.pop()) << '\n';
    }
    QTextStream &operator<<(QChar arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    }
    QTextStream &operator<<(char arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    }
    QTextStream &operator<<(signed short arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    }
    QTextStream &operator<<(unsigned short arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(signed int arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(unsigned int arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(signed long arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(unsigned long arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(qlonglong arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(qulonglong arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(float arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(double arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(const QString &arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(QStringView arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(QLatin1String arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(const QStringRef &arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(const QByteArray &arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(const char *arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };
    QTextStream &operator<<(const void *arg) {
        int i = indentLvl + 1;
        while (--i) *stream << '\t';
        *stream << arg;
        return *stream;
    };

    void write(QString string) {
        QTextStream strStream(&string);

        while(!strStream.atEnd()) {
            this->operator<<(strStream.readLine()) << "\n";
        }
    }
public:
    int indentLvl;
private:
    std::shared_ptr<QTextStream> stream;
};
