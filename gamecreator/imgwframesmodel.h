#ifndef IMGWFRAMESMODEL_H
#define IMGWFRAMESMODEL_H

#include <QStandardItemModel>
#include <QMimeData>

class imagewindow;
class imgwFramesModel : public QStandardItemModel
{
    friend class imagewindow;
    Q_OBJECT
public:
    explicit imgwFramesModel(QObject *parent = 0);

    Qt::ItemFlags flags(const QModelIndex &index) const;

    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    QMimeData* mimeData(const QModelIndexList &indexes) const;

private:
    imagewindow* window;

};

#endif // IMGWFRAMESMODEL_H
