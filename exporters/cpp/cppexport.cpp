#include "config.h"
#include "cppexport.h"
#include "../sharedcode/gameproject.h"
#include "../sharedcode/progressdialog.h"
#include <QApplication>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QProcess>
#include <QApplication>
#include <QDir>
#include <QFileInfo>
#include <QTimer>

/*
    All these functions are required for a plugin DLL to work.
*/

extern "C" QString getName()
{
    return "Windows C++";
}

extern "C" QString getDescription()
{
    return "Builds portable C++ projects compiled with hxcpp, \n"
           "based on Boehm GC, OpenGL, Bullet Physics, AssImp and OpenAL\n"
           "The projects can run on every platform that supports these libraries\n"
           "About licensing, read the ZLIB and BSD licenses.";
}

// some global data:
QList<compileerror> Errors;

extern "C" QList<compileerror> getCompileErrors()
{
    return Errors;
}

extern "C" void clearCompileErrors()
{
    Errors.clear();
}

extern "C" bool build(QString projectfile, QString target, bool final)
{
    qDebug() << "BUILDING APPLICATION: \n"+projectfile;
    return true;
}

gameproject* loadProject(QString filename)
{
    if(!QFile::exists(filename))return 0;
    gameproject* p = new gameproject;
    p->setFilename(filename);
    p->load();
    return p;
}

buildtarget* getTargetByCodeName(gameproject* project, QString target)
{
    foreach(buildtarget* t, project->buildTargets())
        if(t->codename==target) return t;
    return 0;
}

QString genMakefile(gameproject* project, buildtarget* target, QStringList flags = QStringList())
{
    QString data = "# Haxe target file for "+target->codename+" target\n"
            "\n";
    int i=1;
    foreach(QString mainClass, target->modules)
    {
        data+="-cp classes\n"
              "-main "+mainClass+"\n";
        foreach(QString flag, flags) data+= "-D"+flag+"\n";
        data+= "-cpp "+target->codename+"\n";
        if(i != target->modules.count()) data+= "\n--next\n";
        i++;
    }
    return data;
}

extern "C" bool run(QString projectfile, QString target)
{
    clearCompileErrors();
    qDebug() << "Preparing to run "+projectfile;
    gameproject* gp = loadProject(projectfile);
    if(!gp)return false;
    buildtarget* bt = getTargetByCodeName(gp,target);
    if(!bt)return false;
    if(bt->modules.count()==0)
    {
        gcerror("This target does not have main modules.\nPlease define one into the Target settings.");
        return false;
    }
    progressdialog* w = new progressdialog(qApp->activeWindow());
    w->setWindowFlags(Qt::Window);
    w->setWindowTitle("Preparing to run "+gp->title+" - "+target);
    w->setText("Preparing to run "+gp->title);

    // First: Generate the Target config
    QString hxmlfn = gp->absoluteFolder()+"/"+target+".hxml";
    QString data = genMakefile(gp,bt);
    QFile f(hxmlfn);
    f.open(QIODevice::WriteOnly);
    f.write(data.toUtf8());
    f.close();
    w->setWindowModality(Qt::ApplicationModal);
    w->show();

    //Launch haXe compiler with this file:
    QProcess haxe;
    QStringList haxeOutput;
    haxe.setWorkingDirectory(gp->absoluteFolder());
    haxe.setReadChannelMode(QProcess::MergedChannels);

    // For each MODULE:
    foreach(QString mainClass, bt->modules)
    {
        w->setWindowTitle("Preparing to run "+gp->title);
        w->setHeader("Creating module "+mainClass+"...");


        // Run the compiler. Verbose mode is ON here so we can estimate the progress.
        haxe.start("haxe", QStringList()<< gp->absoluteFolder()+"/"+target+".hxml" << "-v" << "-D" << "WIN32" << "-cp" << FrameworkData::classPath());
        haxe.waitForStarted();

        QProcess::ProcessError e = haxe.error();
        if(e==QProcess::FailedToStart)gcmessage("Unable to invoke the haXe compiler");

        w->setText("Generating and updating the C++ code...");
        int numFiles = 0;
        bool compilingStarted = false;
        while(haxe.state()!=QProcess::NotRunning)
        {
            //here we are waiting for the output.
            QApplication::processEvents();
            if(haxe.canReadLine())
            {
                QString line = haxe.readLine();
                haxeOutput << line;
                gcprint(line);
                // The progress bar is still undefined here.

                // Parsed + haxe module - good way to at least try estimating some progress.
                if(line.startsWith("Parsed")) numFiles++;
                //if(line.startsWith("Typing")) numFiles++;


                // Then the cl.exe output comes. We will ignore it as hxcpp outputs just a line with cpp filename
                // We'll go for it!
                if(!line.contains(" ") && line.contains(".cpp"))
                {
                    if(!compilingStarted)
                    {
                        qDebug() << numFiles;
                        w->setMax(numFiles);
                        w->setValue(0);
                        w->setText("Creating precompiled header...");
                        numFiles = 0;   //from now on, use this var as loop control
                        compilingStarted = true;
                    }
                    QString ln = line.replace("\n","");
                    w->setText("Compiling "+ln+"...");
                    w->setValue(++numFiles);
                }

                // And when compilation is complete, a linker will run.
                // Microsoft linker, link.exe is easy
                if(line.startsWith("link.exe"))
                {
                    w->setText("Linking Windows EXE...");
                    //Fill ot on 100 %
                    w->setMax(1);
                    w->setValue(1);
                }

                // Then it quits!
            }
        }
    }

    w->close();

    int haxeResult = haxe.exitCode();
    // 0 => Success.
    // 1 => Error.
    QString AllOutput = haxeOutput.join("\n") + haxe.readAllStandardOutput();
    //if(haxeResult!=0) gcmessage(AllOutput);

    /* Thread unsync occurs between STDERR and STDOUT. Either Qt bug or bad sync!

      The following line was returned by the compiler - a mix between STDOUT and STDERR!

Typing haxe.iclasses/Main.hx:9: characters 14-24 : Cannot access to private field count
classes/Main.hx:11: characters 14-24 : Cannot access to private field count
o.Output.writeInt31

To workaround this, we will re-call the compiler in STDERR mode and in NON-Verbose mode!
      */
    if(haxeResult!=0)
    {
        w->close();
        haxe.start("haxe", QStringList()<< gp->absoluteFolder()+"/"+target+".hxml" << "-D" << "WIN32" << "-cp" << FrameworkData::classPath());
        haxe.waitForStarted();
        haxe.waitForFinished();
        AllOutput = haxe.readAllStandardOutput();
        QStringList lines = AllOutput.split("\n");
        foreach(QString l, lines)
        {
            QRegExp rx( "(.*):(\\d+): characters (\\d+)-(\\d+) : (.*)"  );
            int pos = rx.indexIn(l);
            if(pos!=-1)
            {
                //we got match!
                compileerror error;
                error.file=rx.cap(1);
                error.line=rx.cap(2).toInt();
                error.begin=rx.cap(3).toInt();
                error.end=rx.cap(4).toInt();
                error.message=rx.cap(5);
                Errors.append(error);
                // Throw an error to the IDE? Exporter cannot ACCESS the IDE ...
                // THE IDE Must ask for compiling errors itself here! IF I return FALSE!

                //They must be handled by the IDE in better way. For example, Errors panel in the Mainwindow!.
            }
        }
        delete w;
        return false;   // Run failed!
    }



    //gcprint("------------------ BEGIN! ------------------\n");
    //gcprint(AllOutput);
    //gcprint("------------------  END!  ------------------\n");

    // What about a target with many Main classes? Which one to run? Ask?
    if(haxeResult==0)
    foreach(QString mainClass, gp->modules)
    {
        // Well, now, the EXEs are there. Or? Some antivirus killed the linker?
        QFile exe (gp->absoluteFolder()+"/"+target+"/"+mainClass+".exe");
        if(!exe.exists())
        {
            gcmessage("Unable to find the generated module EXE.\nIs your project in writable folder?\n"
                      "Or, did your antivirus blocked the linker?");
            return false;
        }

        //AFTER link: Copy Pi|Engine DLL and haXe DLLs onto the EXE folder

        //Else it exists. We must copy the std.dll and other binaries to the EXE folder prior running:
        QString hxcppPath = QFileInfo("haxe/lib/hxcpp").absoluteFilePath();
        QFile f( hxcppPath+"/.current" );

        if(!f.open(QIODevice::ReadOnly)) gcerror("BUG: cppexport.cpp: Unable to query hxCpp's version.\\nLIMITATION: Place Haxe in Creator IDE's folder and run haxelib install hxcpp!\n\nTODO: Auto installer!");
        QString version = f.readAll();
        version = version.replace(".",",");
        hxcppPath.append("/"+version+"/bin/Windows");
        QFileInfoList dlls = QDir(hxcppPath).entryInfoList( QStringList()<<"*.dll" );
        QFileInfo piDll;
        piDll.setFile("data/pi-engine/Engine_CPP/pi-engine.dll");
        dlls.append(piDll);
        foreach(QFileInfo f, dlls)QFile(f.absoluteFilePath()).copy( gp->absoluteFolder()+"/"+target+"/"+f.fileName() );
        w->hide();
        QApplication::processEvents();
        QTimer t;
        t.setInterval(100);
        t.setSingleShot(true);
        t.start();
        while(t.isActive()) QApplication::processEvents();
        QProcess::startDetached(exe.fileName());
    }
    delete w;
    return true;
}

extern "C" bool debug(QString projectfile, QString target)
{
    return true;
}

extern "C" bool clean(QString projectfile, QString target)
{
    return true;
}

extern "C" QString configure(QString)
{
    Config c;
    c.exec();
    return QString();
}

extern "C" QString parameters(QString)
{

}

bool cppExporter::exportResource(QString name)
{
    qDebug() << "Exporting " + name;
}
