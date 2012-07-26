#include "projecttreemodel.h"
#include "gcide.h"
#include "openedproject.h"
#include "../sharedcode/gameproject.h"
#include "../sharedcode/globals.h"
#include "../sharedcode/resource.h"
#include "../sharedcode/rsimage.h"
#include "../sharedcode/rsmodel.h"
#include "../sharedcode/rssound.h"
#include "../sharedcode/rsclass.h"
#include "../sharedcode/rsscene.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPointer>
#include <QMimeData>
#include <QUrl>

ProjectTreeModel::ProjectTreeModel(QObject *parent) :
    QStandardItemModel(parent)
{
    //updateTree();
}

void ProjectTreeModel::updateTree()
{
    //This API is deprecated
    gcprint("DEPRECATED UNPLANNED FUCTION ProjectTreeModel::updateTree() CALLED");
    clear();
    foreach(OpenedProject* opr, creatorIDE->projects)
    {
        gameproject* p = opr->project;
        QStandardItem* projectNode = new QStandardItem(p->title());
        QFont f; f.setBold(true);
        projectNode->setEditable(false);
        projectNode->setFont(f);
        projectNode->setBackground( QColor(0,0,0,15) );
        projectNode->setIcon( ffficon("human-joystick") );
        projectNode->setDropEnabled(1);

        // "project" node: Project AND data are OpenedProject* pointers
        //projectNode->setData( qVariantFromValue((void*)opr), TIPROJECT);
        //projectNode->setData( qVariantFromValue((void*)opr), TIDATA);
        projectNode->setData( "project",TIKIND);

        // Now for each resource, add it to the tree:

        //images:
        QStandardItem* imagesFolder = new QStandardItem("Images");
        imagesFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
        imagesFolder->setEditable(false);
        imagesFolder->setData("image",TIKIND);
        imagesFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
        imagesFolder->setData(NULL,TIDATA);
        imagesFolder->setFont(f);
        foreach(gcresource* r,p->images())
        {
            QStandardItem* rn = new QStandardItem();
            rn->setIcon(r->icon);
            rn->setText(r->name);
            rn->setData("image",TIKIND);
            rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
            rn->setData(qVariantFromValue((void*)r), TIDATA);
            rn->setDropEnabled(0);
            imagesFolder->appendRow(rn);
        }
        projectNode->appendRow(imagesFolder);


        //sounds:
        QStandardItem* soundsFolder = new QStandardItem("Sounds");
        soundsFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
        soundsFolder->setEditable(false);
        soundsFolder->setData("sound",TIKIND);
        soundsFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
        soundsFolder->setData(NULL,TIDATA);
        soundsFolder->setFont(f);
        foreach(gcresource* r,p->sounds())
        {
            QStandardItem* rn = new QStandardItem();
            rn->setIcon(r->icon);
            rn->setText(r->name);
            rn->setData("sound",TIKIND);
            rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
            rn->setData(qVariantFromValue((void*)r), TIDATA);
            rn->setDropEnabled(0);
            soundsFolder->appendRow(rn);
        }
        projectNode->appendRow(soundsFolder);


        //models:
        QStandardItem* modelsFolder = new QStandardItem("Models");
        modelsFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
        modelsFolder->setEditable(false);
        modelsFolder->setData("model",TIKIND);
        modelsFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
        modelsFolder->setData(NULL,TIDATA);
        modelsFolder->setFont(f);
        foreach(gcresource* r,p->models())
        {
            QStandardItem* rn = new QStandardItem();
            rn->setIcon(r->icon);
            rn->setText(r->name);
            rn->setData("model",TIKIND);
            rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
            rn->setData(qVariantFromValue((void*)r), TIDATA);
            rn->setDropEnabled(0);
            modelsFolder->appendRow(rn);
        }
        projectNode->appendRow(modelsFolder);

        //classes:
        QStandardItem* classesFolder = new QStandardItem("Classes");
        classesFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
        classesFolder->setEditable(false);
        classesFolder->setData("model",TIKIND);
        classesFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
        classesFolder->setData(NULL,TIDATA);
        classesFolder->setFont(f);
        foreach(gcresource* r,p->classes())
        {
            QStandardItem* rn = new QStandardItem();
            rn->setIcon(r->icon);
            rn->setText(r->name);
            rn->setData("class",TIKIND);
            rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
            rn->setData(qVariantFromValue((void*)r), TIDATA);
            rn->setDropEnabled(0);
            classesFolder->appendRow(rn);
        }
        projectNode->appendRow(classesFolder);

        //scenes:
        QStandardItem* scenesFolder = new QStandardItem("Scenes");
        scenesFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
        scenesFolder->setEditable(false);
        scenesFolder->setData("scene",TIKIND);
        scenesFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
        scenesFolder->setData(NULL,TIDATA);
        scenesFolder->setFont(f);
        foreach(gcresource* r,p->scenes())
        {
            QStandardItem* rn = new QStandardItem();
            rn->setIcon(r->icon);
            rn->setText(r->name);
            rn->setData("scene",TIKIND);
            rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
            rn->setData(qVariantFromValue((void*)r), TIDATA);
            rn->setDropEnabled(0);
            scenesFolder->appendRow(rn);
        }
        projectNode->appendRow(scenesFolder);


        //Add the rest here!

        this->appendRow(projectNode);
        creatorIDE->mainWindow->ui->projectTree->expand(indexFromItem(projectNode));
        creatorIDE->currentProject = opr;
    }

}

inline int ProjectTreeModel::projectCount()
{
    return creatorIDE->projects.count();
}

QMimeData* ProjectTreeModel::mimeData(const QModelIndexList &indexes) const
{
    QMimeData* d = new QMimeData();
    foreach(QModelIndex i,indexes)
        if(i.isValid())
        {
            d->setText(itemFromIndex(i)->text());
        }
    return d;
}

bool ProjectTreeModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    if(data->hasText())gcmessage(data->text());
    if(data->hasUrls())
    {
        QStringList L;
        foreach(QUrl u,data->urls())L.append(u.toString());
    }
    return true;
}

Qt::DropActions ProjectTreeModel::supportedDropActions() const
{
    return Qt::ActionMask | Qt::IgnoreAction | Qt::MoveAction | Qt::CopyAction;
}

QStringList ProjectTreeModel::mimeTypes() const
{
    QStringList L; L
            << "text/uri-list"
            << "text/plain"
            << "text/html"
            << "gamecreator/resource"
            << "application/x-qt-image"
            << "application/x-qt-windows-mime;value=\"PNG\""
    ;
    return L;
}
