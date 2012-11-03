#ifndef GLOBALS_H
#define GLOBALS_H

#include <QIcon>
#include <QHash>
#include <QtXml/QDomDocument>
#include <QTreeWidgetItem>

class dllForExport;
typedef QHash<QString,QVariant> vObject;
typedef QHash<QString,QVariant>::const_iterator vObjectIterator;

/* common functionality */
void gcprint(QString text);
void gcprint(int number);
void gcprint(void*);

void gcmessage(QString message);
void gcerror(QString message);
void gcerror(QIcon icon, QString title, QString message);
void gccrash(QString message);
void gccrash(QString message,QString file,int line);

QIcon ffficon(QString);
QIcon gcResIcon(QString kind, QString iconfile);
QTreeWidgetItem* gcTreeWidgetItem(QString icon, QString text);
QString HTMLBodyContents(QString s);
QString fixName(QStringList L,QString name);

void gcBeginWait();
void gcEndWait();

//Common math
double point_distance(double x1, double y1, double x2, double y2);
void scale_to_fit(int w, int h, int tw, int th, int* resw, int* resh);
double nfmod(double a,double n);
bool point_in_rectangle(double tx,double ty, double x1, double y1, double x2, double y2);
bool rectangles_overlap(double r1x1, double r1y1,double r1x2,double r1y2,double r2x1,double r2y1,double r2x2,double r2y2);

// FILE IO
bool gcRemoveFolder(QString dir);
bool gcRemoveFiles(QString dir, QString mask);
QStringList findFilesRecursively ( QStringList paths, QStringList fileTypes );
QDomDocument* gcReadXml(QString file);
bool gcSaveXml(QString file, QDomDocument *xml);

//DEFINES:
//GUI  TreeView ITEMS data roles
#define TIKIND Qt::UserRole+1       // Resurce kind as QString
#define TIPROJECT Qt::UserRole+2    // gameproject* as void*
#define TIFILE Qt::UserRole+3       // True - resource is file? / else is folder
#define TIDATA Qt::UserRole+4       // Resource name as QString / Folder type if folder
#define TIICON Qt::UserRole+5       // Resource icon file as string (must be gen'd by restype editor)
#define TICODE Qt::UserRole+6       // PGS Code for Class editor items
#define TITYPE_NEW Qt::UserRole+7   // Resurce type as QString

// Code formatting - the Code Editor itself is part from the IDE but may get used
// in plugins as well.
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
    dllForExport* exporter;
    QStringList defines;
    QStringList modules;
    vObject settings;
};
struct compileerror
{
    QString message,file;
    int line,begin,end;
};
Q_DECLARE_METATYPE(compileerror)

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

#define __MessageEvent 2012
#define MessageEvent ((QEvent::Type)__MessageEvent)

#endif // GLOBALS_H
