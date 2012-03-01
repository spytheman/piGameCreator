#include "projectmodel.h"
#include "gamecreator.h"
#include "resourceeditor.h"
#include <QStyle>
#include <QDir>
#include <QMenu>
#include <QtGui/QApplication>
#include <mainwindow.h>
#include "saveornot.h"
#include <QInputDialog>
#include <QMessageBox>
#include <ui_mainwindow.h>

ProjectModel::ProjectModel(QObject *parent) :
    QStandardItemModel(parent)
{
    //project model constructor
    gcprint("Creating the project model...");
}

bool ProjectModel::open(QString s)
{
    gcprint("PROJECT MODEL: Opening "+s);

    gameproject* gp = new gameproject(s);
    if(gp->failreason!=""){return false;}
    projects.push_back(gp);

    //add the project entry
    QStandardItem* i = new QStandardItem(gp->name);
    gp->treeroot = i;
    i->setData("project",TITYPE);
    i->setData( qVariantFromValue((void*)gp),TIPROJECT);

    QFont f(i->font());f.setBold(true);
    i->setFont(f);
    i->setIcon(QApplication::style()->standardIcon(QStyle::SP_DirClosedIcon));
    i->setEditable(false);

    //Create the oroject folders
    QStandardItem*  folder;
    //note: NOT all possible folders will be visible in the beginning!

    folder = new QStandardItem(tr("Images"));
    folder->setFont(f);
    folder->setEditable(false);
    folder->setData("imagefolder",TITYPE);  //the images folder!
    folder->setData( qVariantFromValue((void*)gp) ,TIPROJECT);
    folder->setData(false,TIFILE);
    folder->setIcon(QApplication::style()->standardIcon(QStyle::SP_DirClosedIcon));

    i->appendRow(folder);

    i->setBackground(QColor(0,0,0,20));
    appendRow(i);

    //now load the XML
    gcBeginWait();
    gp->load();
    gcEndWait();

    treeview->expand(i->index());
    treeview->setCurrentIndex(i->index());
    //if(projects.count()==1)treeview->setRootIsDecorated(false);
    //else treeview->setRootIsDecorated(true);
    return true;
}

void ProjectModel::updateProjectRoot(gameproject *gp)
{
    //treeroot it not initialized in projectmodel's constructor!
    gp->treeroot->setText(gp->name + (gp->modified?" *":""));
}

bool ProjectModel::close(gameproject* gp)
{
    bool res=true;
    for(int i=0;i<projects.count();i++)
    {
        //gcprint("ITERATION: "+QString::number((int)projects[i]) +": " + projects[i]->name);
        if(projects[i]==gp)
        {
            //close it
            res = gp->close();
            if(!res)return res;

            //Close all project opened stuff:
            for(int k=0;k<workspace->count();k++)
            {
                QWidget* w = workspace->widget(k);
                if(w->property("editor").value<bool>())
                {
                    resourceeditor* r = dynamic_cast<resourceeditor*>(w);
                    if(r->project==gp)
                    {
                        if(r->modified)
                        {
                            int a = saveornot::resource(r->name);
                            if(a==1){gcBeginWait();r->save();w->close();gcEndWait();}
                            if(a==0)return false;
                            if(a==-1){w->close();}
                        }
                        else w->close();
                    }
                }
            }

            //delete project object and remove its item
            delete gp;
            projects.removeAt(i);

            for(int j=0;j<rowCount();j++)
            {
               if(  item(j)->data(TIPROJECT).value<void*>() == (void*)gp  )
               removeRow(j);
            }/**/

            return res;
        }
    }
    return res;
}

bool ProjectModel::dropMimeData(const QMimeData *data, Qt::DropAction action,
                                int row, int column,
                                const QModelIndex &parent)
{

    QStandardItem* w = new QStandardItem;
    w->setText("New item");
    w->setIcon(QApplication::style()->standardIcon(QStyle::SP_ArrowRight));

    //inserting:
    //Root: cannot insert:
    if(parent==QModelIndex())
    {
        gcprint("Can't drop here");
    }
    return true;
}

bool ProjectModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    //Reimplementing stuff that is already implemented in order to fully customize renaming of items!
    if(role==Qt::EditRole)
    {
        if(itemFromIndex(index)->text() == value.toString())return false;
        if(index.data(TIFILE).toBool()==true)
        {
            //renaming an item - only if closed
            bool canrename=true;
            for(int i=0;i< workspace->count();i++)
            {
                QWidget* w = workspace->widget(i);
                if(w->property("editor").toBool())
                {
                    resourceeditor* r = dynamic_cast<resourceeditor*>(w);
                    if(r->treeitem == itemFromIndex(index))
                        canrename = false;
                }
            }/**/

            if(canrename)
            {
                QStandardItem* i = itemFromIndex(index);
                gameproject* gp = (gameproject*)( i->data(TIPROJECT).value<void*>());
                QString
                        oldname = i->text(),
                        newname = value.toString(),
                        projectpath = gp->absoluteFolder,
                        resdir = projectpath + "/" + getFolderName(i->data(TITYPE).toString()); // DAMN

                QDir d(resdir);
                if(d.rename(oldname,newname))
                {
                    d.rename(oldname+".xml", newname+".xml");
                    i->setText(newname);
                    //POSSIBLE BUG: project MUST really exists!
                    gp->save(gp->file,true);
                }
                else gcerror(QObject::tr("Cannot rename this resource!"));

            }
            else gcerror(QObject::tr("Cannot rename opened resource. Please close it first."));
        }
        else itemFromIndex(index)->setText(value.toString());

    }
    return true;
}

void ProjectModel::delresource(QModelIndex r, bool force)
{
    bool shoulddel=0;
    if(force)shoulddel=1;
    if(shoulddel==0)
    shoulddel = QMessageBox::question(thewindow,tr("Delete resource"),
                                      tr("Are you sure you want to delete %1").arg(itemFromIndex(r)->text()),
                                      QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes;
    if(shoulddel)
    {
        gameproject* gp = (gameproject*) r.data(TIPROJECT).value<void*>();
        if(r.data(TIFILE).toBool())
        {
            for(int i=0;i<workspace->count();i++)
            {
                QWidget* w = workspace->widget(i);
                if(w->property("editor").toBool())
                {
                    resourceeditor* r2 = dynamic_cast<resourceeditor*>(w);
                    if(r2->treeitem->index() == r)
                    {
                        workspace->removeTab(i);
                        w->close();
                    }
                }
            }
            QDir d(gp->absoluteFolder);

            d.cd( getFolderName( r.data(TITYPE).toString()) ); // <---- This is the bug!
            // image+s is OK.. class+s is classEs...

            gcRemoveFolder(d.absolutePath() + "/"+itemFromIndex(r)->text());
            d.remove(itemFromIndex(r)->text()+".xml");
            itemFromIndex(r)->parent()->removeRow(itemFromIndex(r)->row());
        }
        else
        {
            //deleting a folder
            int rc = itemFromIndex(r)->rowCount();
            for(int i=0; i<rc;i++)
            {
                delresource(r.child(0,0),true);
            }
            itemFromIndex(r)->parent()->removeRow(itemFromIndex(r)->row());
            //itemFromIndex(r)->setText("DELETED");
        }
    }
}
void ProjectModel::exportresource(QModelIndex r){}
void ProjectModel::cloneresource(QModelIndex r){}

bool ProjectModel::addResource(gameproject* gp, QString type, QString name, QString icon, QModelIndex target)
{
    if(target==QModelIndex())
    for(int R=0;R<rowCount(QModelIndex());R++)
    {
        QStandardItem* i = itemFromIndex(index(R,0));
        if(i->data(TIPROJECT).value<void*>() == (void*)gp)
        {
            target = indexFromItem(gcFolder(gp,type));
        }
    }


    QString ficon;
    if(icon!="")
        ficon = gp->absoluteFolder+"/"+getFolderName(type)+"/"+name+"/"+icon; // test/images/image/icon
    else
    {
        //default icon.png
        ficon = gp->absoluteFolder+"/"+getFolderName(type)+"/"+name+"/icon.png";
        if(!QFile::exists(ficon))ficon="";
    }
    QStandardItem* nr = new QStandardItem();
    nr->setText(name);
    nr->setData(type,TITYPE);
    nr->setData(qVariantFromValue((void*)gp),TIPROJECT);
    nr->setData(true,TIFILE);
    nr->setFlags(Qt::ItemIsEditable | Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsDragEnabled);
    nr->setIcon(gcResIcon(type,ficon));
    nr->setData(icon,TIICON);
    itemFromIndex(target)->appendRow(nr);
    return true;

    //else gcerror("Internal error");

}

// RESOURCE LOADERS








