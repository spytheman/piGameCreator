#include "gamecreator.h"
#include <QFileInfo>
#include <QMessageBox>
#include <QCommandLinkButton>
#include <QFileDialog>
#include "saveornot.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resourceeditor.h"
#include "progressdialog.h"
#include <QTextStream>
#include <QThread>
#include <QDesktopServices>
#include <QtXml/qdom.h>
//#include <QtXmlPatterns/QXmlQuery>
#include <QUrl>

gameproject::gameproject()
{
    file = "";
    name = "New game";
    modified = true;
    failreason="";
    //default data
    gcprint("New project created");
}
gameproject::gameproject(QString s)
{

    //This will LOAD the file as well.
    file = QFileInfo(s).absoluteFilePath();
    name = QFileInfo(s).fileName();
    relativeFolder = QFileInfo(s).baseName();
    absoluteFolder = QFileInfo(s).absolutePath()+"/"+relativeFolder;
    modified = false;
    failreason="";
    //check if already open?
    foreach(gameproject* i,projects.projects)
    {
        if(i->file == file)
        {
            failreason=QObject::tr("This project is already opened");
            gcprint("Project open FAIL: "+failreason);
            QMessageBox::information(0,QObject::tr("Error"),failreason);
        }
    }
    selectedTarget=0;
}

gameproject::~gameproject()
{
    //kill it
    //foreach(gcimage* i,images)delete i;
}

void gameproject::rec_addentry(QDomElement e, QModelIndex target)
{
    if(e.tagName()=="folder")
    {
        //a folder:
        //gcmessage("adding folder " + treeroot->text());
        if(target==QModelIndex())target = gcFolder(this,e.attribute("type"))->index();

        QStandardItem* f = new QStandardItem;
        QFont ff;ff.setBold(true);
        f->setFont(ff);
        f->setText(e.attribute("name"));
        f->setIcon(QApplication::style()->standardIcon(QStyle::SP_DirClosedIcon));
        f->setEditable(true);
        f->setData(qVariantFromValue((void*)this),TIPROJECT);
        f->setData(false,TIFILE);
        f->setData("folder",TITYPE);
        f->setData(e.attribute("type"),TIDATA);
        projects.itemFromIndex(target)->appendRow(f);

        for(int i=0;i<e.childNodes().count();i++)
        {
            rec_addentry(e.childNodes().at(i).toElement(),f->index());
        }
    }
    else
    {
        //just a resource
        if(e.hasAttribute("name"))
        projects.addResource(this,e.tagName(),e.attribute("name"),e.attribute("icon"),target);
    }
}

bool gameproject::load()
{
    //load the file
    gcprint("opening project: "+file);
    bool valid=true;
    if(QFile::exists(file))
    {
        QString errmsg; int errline,errcol;
        QDomDocument xml;
        QFile f(file);
        if (!f.open(QIODevice::ReadOnly | QIODevice::Text))valid=false;
        if (!xml.setContent(&f,&errmsg,&errline,&errcol))
        {
            gcmessage("SetContent failed: "+errmsg+"\nLine: "+QString::number(errline)+", Col: "+QString::number(errcol));
            f.close();
            valid=false;
        }
        f.close();
        if(valid)
        {
            //Load resources from the XML
            QDomNode res = xml.documentElement().firstChild();
            if(res.toElement().tagName()=="resources")
            {
                res=res.firstChild();
                while(!res.isNull())
                {
                    QDomElement e = res.toElement();
                    gcprint("RESOURCE: "+e.tagName());

                    //add the resource
                    rec_addentry(e);

                    res=res.nextSibling();
                }
            }
            else {return false;} //Resources MUST be first defined!

            //load targets
            QDomElement targets = xml.documentElement().firstChildElement().nextSiblingElement();
            if(targets.tagName()=="targets")
            {
                for(int i=0;i<targets.childNodes().count();i++)
                    if(targets.childNodes().at(i).isElement())
                    {
                        QDomElement target = targets.childNodes().at(i).toElement();
                        if(target.tagName()=="target")
                        {
                            buildtarget* T = new buildtarget;
                            T->name=target.elementsByTagName("name").at(0).toElement().text();
                            T->description=target.elementsByTagName("description").at(0).toElement().text();
                            T->codename=target.attribute("name"); //is the name valid? - assuming YES
                            T->exporter=0;  //invalid exporter!
                            QString expname = target.attribute("exporter");
                            bool valid=false;
                            foreach(dllforexport* d,exporters)
                            {
                               // gcmessage(d->exporterName()+" vs. "+expname);
                                if(d->exporterName()==expname)
                                {
                                    T->exporter = d;
                                    T->exportername = expname;
                                    valid=true;
                                    break;
                                }
                            }
                            if(valid==false)T->exportername = expname;
                            //gcmessage(T->name+"\n\n"+T->description+(valid?"":"\nEXPORTER IS NOT VALID"));
                            buildTargets.push_back(T); //added!
                        }
                    }
            }
            thewindow->RebuildTargetsCB(this);
            //end loading
        }
    }
    else
    {
        failreason=QObject::tr("Cannot open project %1: Not found").arg(file);
        gcprint("Project open FAIL: "+failreason);
        QMessageBox::warning(0,QObject::tr("Error"),failreason);
    }

    // DONE!

}

bool gameproject::close()
{
    bool m = modified;
    save(file,true);    //Save the XML;
    modified = m;
    //this must destroy the project stuff and free its memory!
    if(modified==true)
    {
        saveornot* w = new saveornot(this);
        int res = w->exec();
        if(res==1)
        {
            //TODO save and close
            save();
            return true;
        }
        else if(res==0)
        {
            //cancel!
            return false;
        }
        else if(res==-1)
        {
            //reject
            return true;
        }
    }
    else return true;
    return false;

    //if true, delete will be called, the destructor will free the objects
}

QString gameproject::toString()
{
    return "Game project";
}

bool gameproject::save() //saves to current file, if not saved, asks where (Ctrl+S)
{
    return save(file);
}

bool gameproject::saveAs()
{
    QString sf;
    QString newf = QFileDialog::getSaveFileName(0,
            QObject::tr("Save project as..."),
            file,
            "piGameCreator project (*.gcpx)",&sf
            );
    if(newf.isEmpty())return false;
    bool res = save(newf);

        //file=newf;name=QFileInfo(newf).fileName();

    MainWindow::projectModel()->updateProjectRoot(this);

    return res;
}

// These classes and functions here are for Save/Save AS threading
// Each class represents a single thread, So i don't think is nessesary to place these in headers
// as they are only used HERE
class DirListThread:public QThread{
public:
    QString path;
    DirListThread(QString dir): path(dir) {}
    QFileInfoList AllFiles;
    QFileInfoList AllDirs;
    void getfolder(QString dir)
    {
        gcprint("getting folder "+dir);
        QDir d(dir);
        QFileInfoList dirs = d.entryInfoList(QDir::Dirs | QDir::NoDotAndDotDot);
        QFileInfoList files = d.entryInfoList(QDir::Files | QDir::NoDotAndDotDot);
        AllFiles<<files;
        AllDirs<<dirs;
        for(int i=0;i<dirs.count();i++)getfolder(dirs.at(i).absoluteFilePath());
    }
    void run(){getfolder(path);}
};
class CopyFileThread:public QThread{
public:
    QString s,d;
    CopyFileThread(QString src,QString dest):s(src),d(dest){}
    void run()
    {
        QDir().mkpath(QFileInfo(d).absolutePath());
        gcprint("Copying "+s +" -> "+d);
        QFile::copy(s,d);
    }
};

void rec_res(QStandardItem* i,QDomDocument* xml, QDomElement target)
{
    if(i->hasChildren()==0)
    {
        //save it
        if(i->data(TIFILE).value<bool>())
        {
            QDomElement e = xml->createElement(i->data(TITYPE).toString());
            e.setAttribute("name",i->text());
            QString s=i->data(TIICON).toString();
            if(s!="")e.setAttribute("icon",s);
            target.appendChild(e);
        }
    }
    else
    {
        // if folder needed, do it and set t2 to it

        //iterate all children
        for(int k=0;k<i->rowCount();k++)
        {
            if(i->child(k)->data(TITYPE).toString()=="folder")
            {
                QDomElement f = xml->createElement("folder");
                f.setAttribute("type",i->child(k)->data(TIDATA).toString());
                f.setAttribute("name",i->child(k)->text());
                target.appendChild(f);
                rec_res(i->child(k),xml,f);
            }
            else   rec_res(i->child(k),xml,target);
        }
    }
}

bool gameproject::save(QString fn, bool SaveOnlyXML)
{
    gcBeginWait();
    //gcmessage("SAVE");
    if(QFileInfo(fn).absoluteFilePath() != file  )
    {
        //SAVE AS:
        //1. Copy current project in new location
        //2. set as current
        //3. save resource editors now (in the new location) :)

        QString newdir = QFileInfo(fn).absolutePath();
        QString newname = QFileInfo(fn).fileName();
        QString newabsdir = newdir + "/" + QFileInfo(newname).baseName();
        //fn is the new file

        progressdialog p;
        p.setParent(thewindow);
        p.setWindowFlags(Qt::Window);
        p.setWindowTitle(QObject::tr("Saving project %1 as %2...").arg(name).arg(newname));
        p.setText(QObject::tr("Preparing to copy..."));
        p.setCancel(false);
        p.setMax(-1);
        p.show();
        DirListThread d(QFileInfo(file).absolutePath()+"/"+QFileInfo(file).baseName());
        d.start();

        thewindow->setEnabled(false);
        p.setEnabled(true);
        forever
        {
            if(d.isFinished())break;
            QApplication::processEvents();
        }
        QStringList src,dest;
        gcprint("\nSOURCE FILES to COPY");
        for(int i=0;i<d.AllFiles.count();i++)
        {
            src << d.AllFiles.at(i).absoluteFilePath();
            gcprint(d.AllFiles.at(i).absoluteFilePath());
        }
        gcprint("\nDESTINATION FILES");
        for(int i=0;i<d.AllFiles.count();i++)
        {
            QString o = d.AllFiles.at(i).absoluteFilePath();
            o.replace(absoluteFolder,newabsdir);
            gcprint(o);
            dest<<o;
        }
        gcprint("\nDIRS to MAKE");
        for(int i=0;i<d.AllDirs.count();i++)
        {
            QString o = d.AllDirs.at(i).absoluteFilePath();
            o.replace(absoluteFolder,newabsdir);
            gcprint(o);
            QDir().mkpath(o);
        }
        //src and dest are OK, do the real COPY

        p.setMax(src.count());
        for(int i=0;i<src.count();i++)
        {
            p.setValue(i);
            p.setText(QObject::tr("Copying %1").arg(QFileInfo(src.at(i)).fileName()));
            CopyFileThread c(src.at(i),dest.at(i));
            c.start();
            while(!c.isFinished())QApplication::processEvents();
        }
        thewindow->setEnabled(true);

        //commit changes to project
        file = fn; //the project is updated. save() must work but it fails...
        relativeFolder = QFileInfo(fn).baseName();
        absoluteFolder = QFileInfo(fn).absolutePath()+"/"+relativeFolder;
        //end saveas
    }

    //first save all the resources
    if(SaveOnlyXML==false)
    for(int i=0;i<thewindow->ui->WorkSpaceTabWidget->count();i++)
    {
        //for each tab
        if(thewindow->ui->WorkSpaceTabWidget->widget(i)->property("editor").value<bool>()==true)
        {
            //this tab is editor!
            resourceeditor* e = dynamic_cast<resourceeditor*>(thewindow->ui->WorkSpaceTabWidget->widget(i));
            if(e->modified)e->save(); //save the resource
        }
    }
    //All resources are OKAY now.

    //Update the project file
    //if(modified) //no, it's not so much work to save it all the time
    {
        //QDir(absoluteFolder).mkpath("icons"); //not needed anymore
        gcprint("Project tree modified, saving...");
        QDomDocument xml;
        QDomProcessingInstruction pi = xml.createProcessingInstruction("xml","version=\"1.0\"");
        xml.appendChild(pi);
        QDomElement project = xml.createElement("project");
        xml.appendChild(project);
        project.setAttribute("folder",relativeFolder);
        project.setAttribute("name",name);
        QDomElement resources = xml.createElement("resources");
        project.appendChild(resources);
        //for each resource in the project, add it to the resource tag
        rec_res(treeroot,&xml,resources);


        //Build targets
        QDomElement ts = xml.createElement("targets");
        project.appendChild(ts);
        foreach(buildtarget* t,buildTargets)
        {
            QDomElement tel=xml.createElement("target");
            tel.setAttribute("name",t->codename);
            tel.setAttribute("exporter",t->exportername);
            QDomElement name=xml.createElement("name");
            QDomText tname = xml.createTextNode(t->name);
            name.appendChild(tname);
            QDomElement desc=xml.createElement("description");
            QDomText tdesc = xml.createTextNode(t->description);
            desc.appendChild(tdesc);
            tel.appendChild(name);
            tel.appendChild(desc);
            ts.appendChild(tel);
            //TODO add settings here
        }

        //save it
        gcSaveXml(file,&xml);
        modified=0;
    }
    //end updating

    modified=false;
    MainWindow::projectModel()->updateProjectRoot(this);
    //QDesktopServices::openUrl(QUrl(fn));
    gcEndWait();
    return true;
}

bool gameproject::saveTree()
{
    return save(file,true);
}


void rec_getres(QStandardItem* i, QMap<QString,QStringList>* l, QStringList* sl)
{
    if(i->hasChildren()==0)
    {
        //add it
        if(i->data(TIFILE).value<bool>())
        {
            if(sl->at(0)=="*")
            {
                (*l)["*"] << i->text();
            }
            else
            {
                QString type = i->data(TITYPE).toString();
                if(sl->contains(type)) l->operator[](type)  << i->text();
            }
        }
    }
    else
    {
        //iterate all children
        for(int k=0;k<i->rowCount();k++)
        {
            rec_getres(i->child(k),l,sl);
        }
    }
}

QMap<QString,QStringList> gameproject::getResourcesFromTypes(QStringList types)
{
    QMap<QString,QStringList> l;
    rec_getres(treeroot,&l,&types);
    return l;
}

QStringList gameproject::getResourcesFromType(QString type)
{
    QStringList T; T << type;
    QMap<QString,QStringList> l = getResourcesFromTypes(T);
    return l.value(type);
}

QStringList gameproject::getAllResourceNames()
{
    QStringList T; T<<"*";
    QMap<QString,QStringList> l = getResourcesFromTypes(T);
    return l.value("*");
}

buildtarget* gameproject::getTarget(QString name)
{
    foreach(buildtarget* t,buildTargets)
    {
        if(t->name == name)return t;
    }
    return 0;
}
