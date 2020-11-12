#include "scgfileloader.h"
#include "scgobjectinforeader.h"
#include "scgdefaultobjectbuilder.h"
#include "scgobject.h"
#include "scgscene.h"

#include <QMessageBox>
#include <QApplication>
#include <QDomDocument>
#include <QFile>

#include <QtDebug>

#include "scs/scs_parser.hpp"


SCgFileLoader::SCgFileLoader()
{

}
SCgFileLoader::~SCgFileLoader()
{

}

/*void SCgFileLoader::showLastError()
{
    QMessageBox::information(0, qAppName(), QObject::tr("Error while opening file %1\n").arg(mFileName) + mLastError);
}*/

/*void SCgFileLoader::showGeneralError()
{
    errorParse();
    showLastError();
}*/

bool SCgFileLoader::load(QString file_name, QObject *output)
{
    SCgScene *scene = qobject_cast<SCgScene*>(output);

    // read data from file
    QString errorStr;
    int errorLine;
    int errorColumn;

    mFileName = file_name;

    QFile file(mFileName);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QFile layoutFile(file_name.replace(file_name.size() - 3, 3, "layout.scs"));
    layoutFile.open(QIODevice::ReadOnly | QIODevice::Text);

    /////////////////////////////////////////////
    // Read document
    SCgObjectInfoReader reader;
    reader.read(&file, &layoutFile);
    /*if (!reader.read(document))
    {
        mLastError = reader.lastError();
        showLastError();
        return false;
    }*/
    file.close();
    layoutFile.close();

    /////////////////////////////////////////////
    /////////////////////////////////////////////
    //Place objects to scene
    DefaultSCgObjectBuilder objectBuilder(scene);
    objectBuilder.buildObjects(reader.objectsInfo());
    /*if (objectBuilder.hasErrors())
    {
        mLastError = QObject::tr("Building process has finished with following errors:\n").arg(mFileName);
        foreach(const QString& str, objectBuilder.errorList())
            mLastError += str + '\n';

        showLastError();
    }*/
    /////////////////////////////////////////////

    return true;
}

/*void SCgFileLoader::errorParse()
{
    mLastError = QObject::tr("error to parse file '%1'").arg(mFileName);
}*/
