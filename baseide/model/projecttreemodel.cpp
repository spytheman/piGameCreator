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
    gcerror("DEPRECATED FUCTION ProjectTreeModel::updateTree() CALLED");
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
