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
#include <stdlib.h>
#include <QProcess>
#include <iostream>
#include "../sharedcode/imageio.h"

void initThread::run()
{

    //Load and initialize ALL stuff needed for piGameCreator.
    emit messageChanged("Initializing pi|game CREATOR...");
    QThread::yieldCurrentThread();


    QString path = getenv("PATH");
    QString cpath = QFileInfo( QDir::currentPath() ).canonicalFilePath();

#ifdef WIN32
    cpath = cpath.replace("/", "\\");
    putenv( QString( "HAXE_LIBRARY_PATH="+
                     cpath+"\\haxe\\std:."
    ).toLocal8Bit());

    putenv( QString( "HAXEPATH="+
                     cpath+"\\haxe"
    ).toLocal8Bit());

    putenv( QString( "NEKOPATH"+
                     cpath+"\\neko"
    ).toLocal8Bit());

    putenv( QString( "PATH="+
                path+";"+
                cpath+"\\imagick;"+
                cpath+"\\haxe;"+
                cpath+"\\neko;"
    ).toLocal8Bit() );
#else
//    gcerror("initthread.cpp: Set the proper environment for your system!");
#endif

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
#ifdef WIN32
        QDir t("editors", "*.dll");
#else
        QDir t("editors", "*.so");       
#endif       
        QStringList libs = t.entryList();
        foreach(QString s,libs)
        {
            gcprint("----------------- Trying to open: '" + s + "' .\n");
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

    //Load the image formats:
    char* c = getenv("PATH");
    gcprint(  QString(c) );
    //system("identify -list format");

    imageio::init();

    gcprint("2D Image formats READ:");

    gcprint("2D Image formats WRITE:");


    emit messageChanged("Loading IDE settings...");
    QThread::yieldCurrentThread();
    QApplication::processEvents();
    creatorIDE->loadSettings();

    FrameworkData::loadFrameworkData();

    creatorIDE->hxStartServer();
}
