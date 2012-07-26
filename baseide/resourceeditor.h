#ifndef RESOURCEEDITOR_H
#define RESOURCEEDITOR_H

#include "workspacewidget.h"
#include <QString>
#include <QAction>
#include <QIcon>

class gcide;
class gameproject;
class gcresource;
class ResourceEditor: public WorkspaceWidget
{
public:
    ResourceEditor();
    virtual bool isResourceEditor();    //true, do not overload

    //The project this resource belongs to
    gameproject* project;
    gcresource* resource;

    //The resource icon
    QIcon icon;

    //The type of resource being edited - overload it!
    QString type;

    //file name for this resource - Load and save will use this name
    QString filename;

    //gcide* piGameCreator pointer
    gcide* creatorIDE;

    //Initializes the editor
    virtual bool init();

    //Loads the resource data into the editor's GUI
    virtual bool load();

    //Save the resource data to the file
    virtual bool save();

    //clone the resource into a new resource
    virtual bool saveAs(QString newname);
    virtual bool saveAs();  //asks for a name
    virtual bool exportResource(QString filename);
//    virtual QList<QAction*> contextMenuItems(QString kind, QString type, bool folder, gcresource* res);

    virtual QString title();

    //if the resource is modified:
    bool modified;
    virtual void makeModified();
    void updateTitle();
};

#endif // RESOURCEEDITOR_H
