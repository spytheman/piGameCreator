#include "globals.h"
#include <QMessageBox>
#include <QApplication>
#include <QDir>
#include <cmath>
#include <QtXml/QDomDocument>
#include <QTextStream>
#include <QFileInfo>
#ifdef WIN32
#include "windows.h"
#endif

void gcprint(QString a)
{
    qDebug(a.toLocal8Bit().data());
}
void gcprint(int i)
{
    QString a = QString::number(i);
    qDebug(a.toLocal8Bit().data());
}
void gcprint(void* i)
{
    int x = *((int *)i); 
    QString a = QString::number(x);
    qDebug(a.toLocal8Bit().data());
}
void gcmessage(QString message)
{
    QMessageBox mb;mb.setText(message);mb.exec();
}
void gcerror(QString message)
{
    QMessageBox mb;
    mb.setIcon(QMessageBox::Critical);
    mb.setText(message);
    mb.exec();
}
void gcerror(QIcon icon, QString title, QString message)
{
    QMessageBox mb;
    mb.setIcon(QMessageBox::Critical);
    mb.setWindowIcon(icon);
    mb.setText(message);
    mb.setWindowTitle(title);
    mb.exec();
}

QIcon ffficon(QString filename)
{
    return QIcon(":/resources/RES/ffficons/"+filename+".png");
}
void gcBeginWait()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
}
void gcEndWait()
{
    QApplication::restoreOverrideCursor();
}
void gccrash(QString message)
{
    gccrash(message,"UNDEFINED",0);
}
void gccrash(QString message, QString file, int line)
{
    gcprint(message);
    gcmessage("Application crash requested with message: <br>"
              "<font size='20'>"+message+"</font><br>"
              "in <b>"+file+"</b> on line <b>"+QString::number(line)+"</b>");
#ifdef WIN32
    RaiseException(0x0BADC0DE, 0x0BADC0DE, 0x0BADC0DE, NULL);
#else
    ((void(*)())NULL) ();
#endif

}

//MATH
double point_distance(double x1, double y1, double x2, double y2)
{
    return sqrt( (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) );
}
void scale_to_fit(int w, int h, int tw, int th, int *resw, int *resh)
{
    double ratio = (double)w/(double)h, width=0.0, height=0.0;

    //uncommenting will disable image enlargement.
    //Preview is considered to be anyres, but low quality (it will be better ingame anyway :))

    //if( ((double)w>(double)tw)||((double)h>(double)th) )
    //{
        width = (double)tw;
        height = (double)th;
        if((double)tw/(double)th > (double)ratio)
        {
            width = (double)th*(double)ratio;
        }
        else
        {
            height = (double)tw/(double)ratio;
        }
    //}
    /*
    else
    {
        width = (double)w;
        height = (double)h;
    }/**/
    (*resw) = (int)width;
    (*resh) = (int)height;
}
double nfmod(double a, double n)
{
    return a - n * floor(a / n);
}
bool point_in_rectangle(double tx, double ty, double x1, double y1, double x2, double y2)
{
    return tx>x1 && tx<x2 && ty>y1 && ty<y2;
}
bool rectangles_overlap(double r1x1,double r1y1,double r1x2,double r1y2,double r2x1,double r2y1,double r2x2,double r2y2)
{
    return !(r1x1 >= r2x2 || r2x1 >= r1x2 || r1y1 >= r2y2 || r2y1 >= r1y2);
}

//FILE IO

bool gcRemoveFolder(QString dirName)
{
    bool result = true;
       QDir dir(dirName);

       if (dir.exists(dirName)) {
           Q_FOREACH(QFileInfo info, dir.entryInfoList(QDir::NoDotAndDotDot | QDir::System | QDir::Hidden  | QDir::AllDirs | QDir::Files, QDir::DirsFirst)) {
               if (info.isDir()) {
                   result = gcRemoveFolder(info.absoluteFilePath());
               }
               else {
                   result = QFile::remove(info.absoluteFilePath());
               }
               if (!result) {
                   return result;
               }
           }
           result = dir.rmdir(dirName);
       }
       return result;
}
bool gcRemoveFiles(QString dir, QString mask)
{
    QDir d(dir);
    QFileInfoList files = d.entryInfoList(QStringList()<<mask);
    foreach(QFileInfo i, files)
    {
        QFile file;
        file.setFileName(i.absoluteFilePath());
        file.remove();
    }
}

fontsetting::fontsetting()
{
    //defaults to a normal text;
    color = QColor(Qt::black);
    bold = false;
    italic = false;
    underline = false;
}
QDomDocument* gcReadXml(QString file)
{
    QString failreason;
    bool valid=true;
    if(QFile::exists(file))
    {
        QString errmsg; int errline,errcol;
        QDomDocument* xml = new QDomDocument();
        QFile f(file);
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text))valid=false;
        if (!xml->setContent(&f,&errmsg,&errline,&errcol))
        {
            gcmessage("SetContent failed: "+errmsg+"\nLine: "+QString::number(errline)+", Col: "+QString::number(errcol));
            f.close();
            valid=false;
        }
        f.close();
        if(valid)
        {
           return xml;
        }
        else return 0;
    }
    else
    {
        failreason=QObject::tr("File %1: Not found").arg(file);
        gcprint("Project open FAIL: "+failreason);
        return 0;
    }

}
bool gcSaveXml(QString file, QDomDocument *xml)
{
    QFile f(file);
    if(f.open(QIODevice::WriteOnly))
    {
        QTextStream TextStream(&f);
        TextStream << xml->toString(4);
        f.close();
        return true;
    }
    else return false;
}
QTreeWidgetItem* gcTreeWidgetItem(QString icon, QString text)
{
    QTreeWidgetItem* i = new QTreeWidgetItem;
    if(icon!="")i->setIcon(0,ffficon(icon));
    i->setText(0,text);
    return i;
}
QString HTMLBodyContents(QString s)
{
    //QTextEdit's HTML is dirty! Let's minify it somehow
    QRegExp r("\\<body.*\\>(.*)\\<\\/body\\>");
    if(r.indexIn(s)>=0)s=r.cap(1);
    return s.trimmed();
}
QIcon gcResIcon(QString kind, QString iconfile)
{
    if(iconfile=="")
    {
        //return the default icon for TYPE
        if(kind=="image")return ffficon("image");
        else if(kind=="class")return ffficon("brick");
        else if(kind=="scene")return ffficon("application");
        else return ffficon("page_white");
    }
    else
    {
        if(QFile::exists(iconfile))
        return QIcon(iconfile);
        else return gcResIcon(kind,"");
    }
}

QString fixName(QStringList R,QString name)
{
    int N=2;QString s=name;
    while(R.contains(s))
    {
        s=name+"_"+QString::number(N);
        N++;
    }
    return s;
}


QStringList findFilesRecursively ( QStringList paths, QStringList fileTypes )
{
    if(fileTypes.isEmpty()) fileTypes << "*";
    QStringList result, more;
    QStringList::Iterator it;
    for ( uint i = 0 ; i < paths.size() ; i++ )
    {
        QDir dir( paths[i] );
        more = dir.entryList( fileTypes, QDir::Files );
        for ( it = more.begin() ; it != more.end() ; ++it )
            result.append( paths[i] + "/" + *it );
        more = dir.entryList( QDir::Dirs | QDir::NoDotAndDotDot );
        for ( it = more.begin() ; it != more.end() ; ++it )
            *it = paths[i] + "/" + *it;
        more = findFilesRecursively( more, fileTypes );
        for ( it = more.begin() ; it != more.end() ; ++it )
            result.append( *it );
    }
    return result; // yields absolute paths
}
