#include "gamecreator.h"
#include "gameproject.h"
#include <QFile>
#include <QMessageBox>
#include <QApplication>
#include <QDir>
#include <QTextStream>
#include <QLibrary>
#include <QImageReader>
#include <QImageWriter>
#include <QMutexLocker>
#include <QInputDialog>
#include <QtXmlPatterns/QXmlQuery>
#include <QXmlResultItems>
#include <QDebug>
#include <cmath>

QString Applog;
QStringList RecentFiles;
QMutex gcmutex;
logwindow* gclog=0;
ProjectModel projects;
MainWindow* thewindow=0;
QList<dllforexport*> exporters;
QMap<QString,fontsetting> CodeColors;
fontsetting CodeFormats[12];
QString codeFontFace;
int codeFontSize;
QColor codeBackground;
QString gc2DformatsRead;
QString gc2DformatsWrite;
QString gc3DformatsRead;
QString gc3DformatsWrite;
QString gcsoundformats;
QStringList gcClassDefFiles;
vObject gcGameScriptData;

//settings
int nrOfRecentFiles=8;

void gcprint(QString a)
{
    QMutexLocker l(&gcmutex);
    Applog += a+"\n";
    if(gclog!=0)
    {
        gclog->print(a);
    }
    qDebug(a.toLocal8Bit().data());
}
void gcprint(int i)
{
    QMutexLocker l(&gcmutex);
    QString a = QString::number(i);
    Applog += a+"\n";
    if(gclog!=0)
    {
        gclog->print(a);
    }
    qDebug(a.toLocal8Bit().data());
}
void gcprint(void* i)
{
    QMutexLocker l(&gcmutex);
    QString a = QString::number((int)i);
    Applog += a+"\n";
    if(gclog!=0)
    {
        gclog->print(a);
    }
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

void gcloadrecentfiles()
{
    RecentFiles.clear();
    //load recent files
    QFile rf("recent.lst");
    if(rf.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        //load elements
        while(!rf.atEnd())
        {
            QString fn = rf.readLine().trimmed();
            RecentFiles.append(fn);
            gcprint("Recent File: "+fn);
        }
        rf.close();
    }
}
void gcinittargets()
{
    gcprint("Searching for platform targets...");
    QDir t("targets");
    QStringList folders = t.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    foreach(QString s,folders)
    {
        dllforexport* dll = new dllforexport(s);
        if(dll->isValid())exporters.push_back(dll);
        else delete dll;
    }
}

dllforexport* getExporter(QString name)
{
    foreach(dllforexport* e,exporters)
        if(e->exporterName() == name)return e;
    return 0; //if invalid exporter!
}

//INIT
void gcinit2Dimageformats()
{
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
    gc2DformatsRead=QObject::tr("All supported image types (%1);;%2").arg(allf).arg(fmts);
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

    gc2DformatsWrite=QObject::tr("All supported image types (%1);;%2").arg(allf).arg(fmts);
    gcprint("2D Image formats WRITE:");
    gcprint(allf);
}
void gcloadsettings()
{
    gcprint("loading settings");
    QXmlQuery q;

    //Code formatting
    q.setQuery("doc('config.xml')/settings/codeformat/*");
    QString s;
    q.evaluateTo(&s);
    s = "<codeformat>\n"+s+"</codeformat>";
   // gcprint(s);
    if(s.isEmpty())gcprint("Config file error: cannot find <settings>/<codeformat> in config.xml");
    QDomDocument t;
    t.setContent(s);

    for(int i=0;i<t.documentElement().childNodes().count();i++)
    {
        QDomElement e = t.documentElement().childNodes().at(i).toElement();
      //  gcprint(e.tagName());
        if(e.tagName()!="font")
        {
            //performance may get slow here
            CodeColors[e.tagName()].color.setNamedColor(e.attribute("color","#000000"));
            CodeColors[e.tagName()].bold = e.attribute("bold",false).toInt();
            CodeColors[e.tagName()].italic = e.attribute("italic",false).toInt();
            CodeColors[e.tagName()].underline = e.attribute("underline",false).toInt();
        }
        else
        {
            //the editor's font
            codeFontFace = e.attribute("face","Courier New");
            codeFontSize = e.attribute("size","10").toInt();
            codeBackground.setNamedColor( e.attribute("color","#FFF") );
            if(!codeBackground.isValid())codeBackground.setNamedColor("#FFF");
        }

    }
    //init CodeFormats - to speed up things, int-based indexes
    CodeFormats[CFkeyword] = CodeColors.value("keyword");
    CodeFormats[CFfunction] = CodeColors.value("function");
    CodeFormats[CFvariable] = CodeColors.value("variable");
    CodeFormats[CFresource] = CodeColors.value("resource");
    CodeFormats[CFclass] = CodeColors.value("class");
    CodeFormats[CFnumber] = CodeColors.value("number");
    CodeFormats[CFstring] = CodeColors.value("string");
    CodeFormats[CFoperator] = CodeColors.value("operator");
    CodeFormats[CFcomment] = CodeColors.value("comment");
    CodeFormats[CFpreproc] = CodeColors.value("preprocessor");
    CodeFormats[CFnormaltext] = CodeColors.value("normaltext");
    CodeFormats[CFerror] = CodeColors.value("error");
}

//GameScript
QList<vObject> gcClasses()
{
    QList<vObject> L;    
    vObjectIterator FI;
    for(FI=gcGameScriptData.begin();FI!=gcGameScriptData.end();++FI)
    {
        vObject File = FI.value().toHash();
        vObjectIterator Class;
        for(Class=File.begin();Class!=File.end();++Class)
            L << Class.value().toHash();
    }
    return L;
}

vObject gcClass(QString name)
{
    vObjectIterator FI;
    for(FI=gcGameScriptData.begin();FI!=gcGameScriptData.end();++FI)
    {
        vObject File = FI.value().toHash();
        vObjectIterator Class;
        for(Class=File.begin();Class!=File.end();++Class)
            if(Class.value().toHash().value("gcName").toString()==name)
                return Class.value().toHash();
    }
    return vObject();
}

void gcInitClasses()
{

    //clear ALL
    gcClassDefFiles.clear();
    gcGameScriptData.clear();
    //current project class data must get reloaded OR saved in gameproject*;

    //get ALL files
    QDir d("data");
    QStringList files = d.entryList(QStringList("*.gsd"));
    foreach(QString fn,files)
    {
        vObject oFile;
        QDomDocument* xml = gcReadXml("data/"+fn);
        if(xml==0){gcerror("Something wrong happened with Game Script Definition file\ndata/"+fn);}
        QDomElement defs = xml->documentElement();
        if(defs.tagName()=="gamescriptdata")
        {
            for(int i=0;i<defs.childNodes().count();i++)
            {
                QDomNode defN = defs.childNodes().at(i);
                if(defN.isElement())
                {
                    vObject oClass;
                    QDomElement def = defN.toElement();
                    oClass["gcHidden"] = def.attribute("hidden");
                    oClass["gcDesc"] = def.attribute("desc");
                    oClass["gcDisplayName"] = def.attribute("doc");
                    oClass["gcName"] = def.attribute("name");
                    //def can only be CLASS or GLOBAL
                    QString className="";
                    if(def.tagName()=="global" or def.tagName()=="class")
                    {
                        //class name is empty string for GLOBAL scope!
                        if(def.tagName()=="class")className=def.attribute("name");

                        //class name is OK! now let's load its internal things
                        QDomElement e = def.firstChildElement();
                        while(!e.isNull())
                        {
                            //description
                            QString description;
                            QTextStream T(&description);
                            for(int i=0;i<e.childNodes().count();i++)e.childNodes().at(i).save(T,0);
                            description = description.trimmed();

                            //type: variable, property or function
                            if(e.tagName()=="var" or e.tagName()=="prop")
                            {
                                //variable and property
                                QString name = e.attribute("name");
                                if(name==""){gcerror(fn+"::"+className+": Unnamed variable!");}
                                //gcGameScriptData[fn][className][name]
                                vObject o;
                                o["kind"]=e.tagName(); //var or prop
                                o["type"]=e.attribute("type","int");
                                o["desc"]=description;
                                oClass[name]=o;
                            }
                            else if(e.tagName()=="func")
                            {
                                //function
                                QString name = e.attribute("name");
                                if(name==""){gcerror(fn+"::"+className+": Unnamed function!");}
                                vObject o;
                                o["kind"]=e.tagName(); //var or prop
                                o["type"]=e.attribute("type","int");
                                o["static"]= (e.attribute("static")=="true");
                                o["desc"]=description;

                                //Arguments!
                                int n=1;
                                QString ns = "arg"+QString::number(n);
                                while(e.hasAttribute(ns))
                                {
                                    QStringList nl = e.attribute(ns).split(" ");
                                    vObject arg;
                                    arg["kind"]="arg";
                                    arg["type"]=nl.at(0);
                                    arg["name"]=nl.at(1);
                                    arg["val"] =e.attribute(ns+"value");
                                    arg["desc"] =e.attribute(ns+"desc");
                                    o[ns]=arg;
                                    n++;
                                    ns = "arg"+QString::number(n);
                                }
                                oClass[name]=o;
                            }
                            e = e.nextSiblingElement();
                        }
                    }
                    oFile[className]=oClass;
                    oFile["gcFileName"]=fn;
                }
            }
        }
        else gcprint(fn + " is not a valid Game Script Definition file.");
        gcGameScriptData[fn] = oFile;
    }
    //qDebug()<<gcGameScriptData;
    //Data is loaded but badly processed!
}

//GUI
void fixback(QWidget* w)
{
    /*
    QString s = w->objectName();
    QColor c = QApplication::palette().color(QPalette::Background);
    QString r,g,b;    r.setNum(c.red());    g.setNum(c.green());    b.setNum(c.blue());
    w->setStyleSheet(s+" {background-color: rgb("+r+", "+g+","+b+")}");
    /**/
}
QIcon ffficon(QString filename)
{
    return QIcon(":/resources/RES/ffficons/"+filename+".png");
}
QTreeWidgetItem* gcTreeWidgetItem(QString icon, QString text)
{
    QTreeWidgetItem* i = new QTreeWidgetItem;
    if(icon!="")i->setIcon(0,ffficon(icon));
    i->setText(0,text);
    return i;
}

void gcBeginWait()
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
}
void gcEndWait()
{
    QApplication::restoreOverrideCursor();
}

//UTILS

QString QStringWordWrap(const QString &str, int wrapLength)
{
    QString tempStr= str;
    int len = str.length(), pos= (wrapLength>1)?wrapLength -1:1;
    while(pos < len-1)
    {
        int tempPos=pos;
        while(tempStr.at(tempPos)!=' ' && tempPos > 0)
        {
            tempPos--;
        }
        if(tempPos > 0)pos=tempPos;
        tempStr.replace(pos,1,'\n');
        pos+=pos;
    }
    return tempStr;
}

QString HTMLBodyContents(QString s)
{
    //QTextEdit's HTML is dirty! Let's minify it somehow
    QRegExp r("\\<body.*\\>(.*)\\<\\/body\\>");
    if(r.indexIn(s)>=0)s=r.cap(1);
    return s.trimmed();
}

QString getFolderName(QString type)
{
    if(type=="class")return "Classes";
    else
    {
        QString nn = type;nn[0] = nn[0].toUpper();nn+="s";
        return nn;
    }
}

QStandardItem* gcFolder(gameproject *gp, QString n)
{
        int foldercount = gp->treeroot->rowCount();
        for(int i=0;i<foldercount;i++)
        {
            if(gp->treeroot->child(i)->data(TITYPE).toString() == n+"folder")
                return gp->treeroot->child(i);
        }
        QStandardItem* folder;
        QString nn = getFolderName(n);
        folder = new QStandardItem(nn);
        QFont f(folder->font());f.setBold(true);
        folder->setFont(f);
        folder->setEditable(false);
        folder->setData(n+"folder",TITYPE);
        folder->setData( qVariantFromValue((void*)gp) ,TIPROJECT);
        folder->setIcon(QApplication::style()->standardIcon(QStyle::SP_DirClosedIcon));
        gp->treeroot->appendRow(folder);

        return folder;
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
QIcon gcResIcon(QString type, QString icon)
{
    if(icon=="")
    {
        //return the default icon for TYPE
        if(type=="image")return ffficon("image");
        else if(type=="class")return ffficon("brick");
        else if(type=="scene")return ffficon("application");
        else return ffficon("page_white");
    }
    else
    {
        if(QFile::exists(icon))
        return QIcon(icon);
        else return gcResIcon(type,"");
    }
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

//FILE IO, misc...

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

QString fixName(gameproject* g,QString name)
{
    QStringList R = g->getAllResourceNames();
    int N=2;QString s=name;
    while(R.contains(s))
    {
        s=name+"_"+QString::number(N);
        N++;
    }
    return s;
}

QString fixName(QStringList R, QString name)
{
    int N=2;QString s=name;
    while(R.contains(s))
    {
        s=name+"_"+QString::number(N);
        N++;
    }
    return s;
}

//NEW RESOURCES
void newimage(gameproject* g, QModelIndex i)
{
    QString n = QInputDialog::getText(thewindow,QObject::tr("Adding new image..."),QObject::tr("Enter the new image name."));
    n=fixName(g,n);
    QDir d(g->absoluteFolder+"/images");
    d.mkpath(d.path());
    if(d.mkdir(n))
    {
        projects.addResource(g,"image",n,"",i);
        g->save(g->file,true);
    }

}
void newclass(gameproject* g, QModelIndex i)
{
    QString n = QInputDialog::getText(thewindow,QObject::tr("Adding new class..."),QObject::tr("Enter the new class name."));
    n=fixName(g,n);
    QDir d(g->absoluteFolder+"/classes");
    d.mkpath(d.path());
    if(d.mkdir(n))
    {
        projects.addResource(g,"class",n,"",i);
        g->save(g->file,true);
    }
}
void newscene(gameproject* g, QModelIndex i)
{
    QString n = QInputDialog::getText(thewindow,QObject::tr("Adding new class..."),QObject::tr("Enter the new class name."));
    n=fixName(g,n);
    QDir d(g->absoluteFolder+"/scenes");
    d.mkpath(d.path());
    if(d.mkdir(n))
    {
        projects.addResource(g,"scene",n,"",i);
        g->save(g->file,true);
    }
}


QStandardItem* newfolder(gameproject* g, QString type, QModelIndex i, bool inside)
{
    QStandardItem* f = new QStandardItem;
    QFont ff;ff.setBold(true);
    f->setFont(ff);
    f->setText(QObject::tr("Folder"));
    f->setIcon(QApplication::style()->standardIcon(QStyle::SP_DirClosedIcon));
    f->setEditable(true);
    f->setData(qVariantFromValue((void*)g),TIPROJECT);
    f->setData(false,TIFILE);
    f->setData("folder",TITYPE);
    f->setData(type,TIDATA);
    if(inside)
        projects.itemFromIndex(i)->appendRow(f);
    else
        projects.itemFromIndex(i)->parent()->appendRow(f);
    projects.treeview->edit(f->index());
    return f;
}

fontsetting::fontsetting()
{
    color = QColor(Qt::black);
    bold = false;
    italic = false;
    underline = false;
}

