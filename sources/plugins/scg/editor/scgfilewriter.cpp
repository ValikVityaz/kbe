#include "scgfilewriter.h"
#include "scgscene.h"
#include "scgnode.h"
#include "scgpair.h"
#include "scgbus.h"
#include "scgcontour.h"

#include <QMessageBox>
#include <QFile>
#include <QTextCodec>
#include <QApplication>



SCgFileWriter::SCgFileWriter()
{

}


SCgFileWriter::~SCgFileWriter()
{

}

bool SCgFileWriter::save(QString file_name, QObject *input)
{
    SCgScene *scene = qobject_cast<SCgScene*>(input);

    QFile fileOut(file_name);
    if (!fileOut.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(0, qAppName(),
                              QObject::tr("File saving error.\nCannot write file %1:\n%2.")
                              .arg(file_name)
                              .arg(fileOut.errorString()));
         return false;
    }
    QString layoutName = file_name.replace(file_name.size() - 3, 3, "layout.scs");
    QFile layoutFileOut(layoutName);
    if (!layoutFileOut.open(QFile::WriteOnly | QFile::Text)) {
         QMessageBox::warning(0, qAppName(),
                              QObject::tr("File saving error.\nCannot write file %1:\n%2.")
                              .arg(layoutName)
                              .arg(layoutFileOut.errorString()));
         return false;
    }
    stream.startWriting(&fileOut, &layoutFileOut);

    QList<QGraphicsItem *> items = scene->items();
    QGraphicsItem * item;
    foreach (item, items) {
        if(SCgObject::isSCgObjectType(item->type())) {
            SCgObject *obj = static_cast<SCgObject*>(item);
            stream.processObject(obj);
        }
    }

    stream.finishWriting();

    fileOut.close();
    return true;
}
