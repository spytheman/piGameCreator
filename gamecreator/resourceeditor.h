#ifndef RESOURCEEDITOR_H
#define RESOURCEEDITOR_H

#include "gameproject.h"
class resourceeditor
{
public:

    virtual void save();    //saves the resource
    virtual void load();    //initializes it after creation, editor must load its data

    //resource state
    void makeModified();

    //tab options
    void updateTitle();
    void setName(QString); //will be called if treeitem is renamed

    gameproject* project;
    QString name, type;
    QIcon icon;
    QStandardItem* treeitem;

    bool initialized;
    bool modified;
};

#endif // RESOURCEEDITOR_H
