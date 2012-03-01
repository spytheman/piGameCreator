#include "gamecreator.h"
#include "imgwframesmodel.h"
#include "imagewindow.h"
#include "ui_imagewindow.h"

imgwFramesModel::imgwFramesModel(QObject *parent) :
    QStandardItemModel(parent)
{
}

Qt::ItemFlags imgwFramesModel::flags(const QModelIndex &index) const
{
    if(index.isValid())
    {
        return Qt::ItemIsSelectable | Qt::ItemIsEnabled | Qt::ItemIsDragEnabled;
    }
    else
        return Qt::ItemIsEnabled | Qt::ItemIsDropEnabled;
}

bool imgwFramesModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    if(row==-1)row=window->frames.count();
    int after = row;
    int source = data->data("application/x-qabstractitemmodeldatalist").toInt();

    //gcmessage(QString("Source: %1, After %2").arg(source).arg(after));
    if(source>after)after+=1;
    window->frames.move(source,after-1);
    window->icons.move(source,after-1);
    window->updateFrameList();
    window->ui->listWidget->setCurrentIndex(index(after-1,0));
    window->makeModified();
    return true;
}

QMimeData* imgwFramesModel::mimeData(const QModelIndexList &indexes) const{
    QMimeData* md = new QMimeData();
    if(indexes.at(0).isValid())
    md->setData("application/x-qabstractitemmodeldatalist",indexes.at(0).data(Qt::DisplayRole).toByteArray());
    return md;
}
