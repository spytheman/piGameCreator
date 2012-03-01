#ifndef GAMECREATOR_H
#define GAMECREATOR_H

#include <QStandardItemModel>
#include <QString>
#include <QIcon>
#include "logwindow.h"
#include "gameproject.h"
#include "projectmodel.h"
#include "dllforexport.h"
#include "mainwindow.h"
#include <QTreeWidgetItem>
#include <QtXml/qdom.h>
#include <QMutex>

//Common structs and small classes

//Yes, i know that TYPEDEF is right but Qt Creator's
//Code Completion didn't respect vObject as typedef, so:
typedef QHash<QString,QVariant> vObject;
typedef QHash<QString,QVariant>::const_iterator vObjectIterator;

struct fontsetting
{
    QColor color;
    bool bold,italic,underline;
    fontsetting();
};
struct buildtarget
{
    QString name,codename,description,exportername;
    bool valid; //installed or not - it MUST be possible to maintain uninstalled targets [but don't show them in the editor!]
    dllforexport* exporter;
    vObject settings;
};

extern logwindow* gclog;
extern QString Applog;
extern QStringList RecentFiles;
extern QStringList Targets;
extern QString gc2DformatsRead;
extern QString gc2DformatsWrite;
extern QString gc3DformatsRead;
extern QString gc3DformatsWrite;
extern QString gcsoundformats;

//Opened projects
extern ProjectModel projects;
extern MainWindow* thewindow;

//Ide settings
extern int nrOfRecentFiles;
extern QList<dllforexport*> exporters;
extern QMap<QString,fontsetting> CodeColors;
extern fontsetting CodeFormats[12];
extern QString codeFontFace;
extern int codeFontSize;
extern QColor codeBackground;

//logging
void gcprint(QString text); //THREAD SAFE!
void gcprint(int number);   //THREAD SAFE!
void gcprint(void*);        //THREAD SAFE!

void gcmessage(QString message);
void gcerror(QString message);

//Game Creator - formats and other ititialization
void gcloadrecentfiles();
void gcinittargets();
dllforexport* getExporter(QString name);
void gcinit2Dimageformats();
void gcinit3Dmodelformats();
void gcinitsoundformats();
void gcloadsettings();      //must also apply them if already running
void gcinitGLEW();

//Game Script data
extern QStringList gcClassDefFiles;
extern vObject gcGameScriptData;
QList<vObject> gcClasses(); //Returns list of data, from the frameworks AND the current project!
vObject gcClass(QString name);
void gcInitClasses();       //(Re)initializes ALL the classes from Framework and Extension files!

//resource utils
QStandardItem* gcFolder(gameproject* project, QString ResType);
QIcon gcResIcon(QString resource_type, QString absolute_icon_file_name);
QDomDocument* gcReadXml(QString file);
bool gcSaveXml(QString file, QDomDocument* xml);
QString getFolderName(QString);

QString fixName(QStringList list, QString name);
QString fixName(gameproject* project, QString name);

//utils
QString QStringWordWrap(const QString &str, int wrapLength);
QString HTMLBodyContents(QString);

//GUI stuff
void fixback(QWidget* widget); //fixes the tabWidget page widget's background to match the global theme
QIcon ffficon(QString);        //loads and returns a famfamfam icon
QTreeWidgetItem* gcTreeWidgetItem(QString icon, QString text);
void gcBeginWait();
void gcEndWait();


//thread safety
extern QMutex gcmutex;  //this one is used from gcprint

//Common math
double point_distance(double x1, double y1, double x2, double y2);
void scale_to_fit(int w, int h, int tw, int th, int* resw, int* resh);
double nfmod(double a,double n);
bool point_in_rectangle(double tx,double ty, double x1, double y1, double x2, double y2);
bool rectangles_overlap(double r1x1, double r1y1,double r1x2,double r1y2,double r2x1,double r2y1,double r2x2,double r2y2);

//double point_distance(double x1, double y1, double z1, double x2, double y2, double z2);


// NEW resources
QStandardItem* newfolder(gameproject*,QString type, QModelIndex = QModelIndex(), bool = true);
void newimage(gameproject*,QModelIndex = QModelIndex());
void newclass(gameproject*,QModelIndex = QModelIndex());
void newscene(gameproject*,QModelIndex = QModelIndex());

// FILE IO
bool gcRemoveFolder(QString dir);

//DEFINES:
//GUI  TreeView ITEMS data roles
#define TITYPE Qt::UserRole+1       // Item type as QString
#define TIPROJECT Qt::UserRole+2    // gameproject* as void*
#define TIFILE Qt::UserRole+3       // True - resource is file? / else is folder
#define TIDATA Qt::UserRole+4       // Resource name as QString / Folder type if folder
#define TIICON Qt::UserRole+5       // Resource icon file as string (must be gen'd by restype editor)
#define TICODE Qt::UserRole+6       // PGS Code for Class editor items

#define CFkeyword 0
#define CFfunction 1
#define CFvariable 2
#define CFresource 3
#define CFclass 4
#define CFnumber 5
#define CFstring 6
#define CFoperator 7
#define CFcomment 8
#define CFpreproc 9
#define CFnormaltext 10
#define CFerror 11

// for images: Pointer to GCImage stored as void*

#endif // GAMECREATOR_H
