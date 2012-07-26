#ifndef PROJECTTREEMODEL_H
#define PROJECTTREEMODEL_H

#include <QStandardItemModel>

class gcresource;
class gameproject;

class ProjectTreeModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit ProjectTreeModel(QObject *parent = 0);
    gcresource* selectedResource;
    int projectCount();
    void updateTree();

    QStringList mimeTypes() const;
    QMimeData* mimeData(const QModelIndexList &indexes) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    Qt::DropActions supportedDropActions() const;


    //Model:

private:
    bool mNoClear;
};

#endif // PROJECTTREEMODEL_H
