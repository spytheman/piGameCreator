#ifndef PROJECTMODEL_H
#define PROJECTMODEL_H

#include <QStandardItemModel>
#include <QStandardItem>
#include <QList>
#include <QTreeView>

//resources
#include "gameproject.h"

class ProjectModel : public QStandardItemModel
{
    Q_OBJECT
    friend gameproject::gameproject(QString s);

public:

    //the project model stuff:
    bool open(QString s);
    bool close(gameproject* gp);
    gameproject* at(int i);

    explicit ProjectModel(QObject *parent = 0);
    QTreeView* treeview;
    QTabWidget* workspace;

    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);
    bool setData(const QModelIndex &index, const QVariant &value, int role);


    //Resource editing
    bool addResource(gameproject*, QString type, QString name, QString icon, QModelIndex where = QModelIndex());
    void delresource(QModelIndex, bool=false);
    void exportresource(QModelIndex);
    void cloneresource(QModelIndex);

    //Tree sync methods
    void updateProjectRoot(gameproject* gp);

signals:

public slots:

private:
    QList<gameproject*> projects;
};

#endif // PROJECTMODEL_H
