#include <QtGui/QApplication>
#include <QCoreApplication>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QMessageBox>
#include <QtTest/QTest>

#include "GL/freeglut.h"

#include "mainwindow.h"
#include "mainpage.h"
#include "gamecreator.h"
#include "scripttestwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setApplicationName("piGameCreator [INTERNAL TEST]");
    a.setOrganizationName("Pi-Dev");
    a.setOrganizationDomain("http://pi-dev.com");
    QString SS = QDir::currentPath()+"/data";
    QCoreApplication::addLibraryPath(SS);


    QFile f("themes/default/default.css");
    if(f.open(QIODevice::ReadOnly))
    {
        qApp->setStyleSheet(f.readAll());
    }/**/

    gcprint("Starting piGameCreator...");
    gcprint(QDir::currentPath());
    gcprint("QApplication dir: "+QApplication::applicationDirPath());
    if(!QFile::exists("data"))
    {
        QString s = QObject::tr("piGameCreator installation is corrupted!\n"
                                "The data folder is missing.\n\n"
                                "Try reinstalling piGameCreator, or check\n"
                                "if you are running it in proper working directory!");
        QMessageBox err;
        err.setText(s);
        err.setWindowTitle("piGameCreator Error");
        err.setIcon(QMessageBox::Critical);
        err.setWindowIcon(ffficon("cancel"));
        err.exec();
        return EXIT_FAILURE;
    }
    gcloadrecentfiles();
    gcinittargets();
    gcinit2Dimageformats();
    gcloadsettings();
    gcInitClasses();
    glutInit(&argc,argv);

    //debug mode: testing the gamescript window
    QStringList ARGV = QApplication::arguments();
    MainWindow w;
    w.showMaximized();
    return a.exec();
}
