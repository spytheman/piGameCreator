#include "initthread.h"
#include "splashscreen.h"
#include <QApplication>
#include <QFile>
#include <QImageReader>
#include <QImageWriter>
#include <QDir>
#include "../sharedcode/globals.h"
#include "gcide.h"
#include "dllforexport.h"
#include "dllforresourceeditor.h"

void initThread::run()
{

    //Load and initialize ALL stuff needed for piGameCreator.
    emit messageChanged("Initializing pi|game CREATOR...");
    QThread::yieldCurrentThread();
    QApplication::processEvents();
    //load settings
    emit messageChanged("Loading language exporters...");
    QThread::yieldCurrentThread();
    QApplication::processEvents();
    //load them
    {
        QDir t("targets");
        QStringList folders = t.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
        foreach(QString s,folders)
        {
            dllForExport* dll = new dllForExport(s);
            if(dll->isValid())creatorIDE->exporterLibs.push_back(dll);
            else delete dll;
        }
    }
    emit messageChanged("Loading resource editors...");
    QThread::yieldCurrentThread();
    QApplication::processEvents();
    //load them
    {
        QDir t("editors");
        QStringList libs = t.entryList();
        foreach(QString s,libs)
        {
            dllForResourceEditor* dll = new dllForResourceEditor(s);
            if(dll->isValid())creatorIDE->resourceEditorLibs.push_back(dll);
            else delete dll;
        }
    }
    //if firsttime:
    //  ask to import settings OR:
    //1. Ask for skin
    //2. Ask for default projects folder
    //2. setup pi-dev Developer account

    //Update check.

    //2D image formats
    emit messageChanged("Querying 2D image formats...");
    QThread::yieldCurrentThread();
    QApplication::processEvents();
    QString allf, fmts;
    QList<QByteArray> FMT = QImageReader::supportedImageFormats();
    for(int i=0;i<FMT.count();i++)
    {
        allf += "*."+FMT.at(i);
        fmts += QObject::tr("%1 image (*.%2)").arg(QString(FMT.at(i).toUpper())).arg(QString(FMT.at(i)));
        if(i<FMT.count()-1)
        {
            fmts+=";;";
            allf += " ";
        }
    }
    gcprint("2D Image formats READ:");
    gcprint(allf);
    creatorIDE->gc2DformatsRead=QObject::tr("All supported image types (%1);;%2").arg(allf).arg(fmts);
    allf="";fmts="";
    QList<QByteArray> FMTW = QImageWriter::supportedImageFormats();
    for(int i=0;i<FMTW.count();i++)
    {
        allf += "*."+FMTW.at(i);
        fmts += QObject::tr("%1 image (*.%2)").arg(QString(FMTW.at(i).toUpper())).arg(QString(FMTW.at(i)));
        if(i<FMTW.count()-1)
        {
            fmts+=";;";
            allf += " ";
        }
    }
    creatorIDE->gc2DformatsWrite=QObject::tr("All supported image types (%1);;%2").arg(allf).arg(fmts);
    gcprint("2D Image formats WRITE:");
    gcprint(allf);

    emit messageChanged("Loading IDE settings...");
    QThread::yieldCurrentThread();
    QApplication::processEvents();
    creatorIDE->loadSettings();

    FrameworkData::loadFrameworkData();
}
