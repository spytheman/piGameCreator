#ifndef RESOURCEEDITOR_H
#define RESOURCEEDITOR_H

#include "workspacewidget.h"
#include <QString>
#include <QAction>
#include <QIcon>
#include <QTimer>

#define RE_SHOW_EVENT updateTimer.start();

#define RE_HIDE_EVENT(STATE_SETTING_NAME)     \
if(initialized) \
{   \
    gcprint("SAVING WINDOW STATE -> " STATE_SETTING_NAME );  \
    ideSettings::setByteArray(STATE_SETTING_NAME, dynamic_cast<QMainWindow*>(widget)->saveState(0));  \
    ideSettings::settings()->sync();   \
    foreach(QObject* o, widget->children()) \
    {   \
        if(QString(o->metaObject()->className()) == "QDockWidget")  \
        {   \
            ((QWidget*)o)->hide();  \
        }   \
    }   \
}

#define RE_WINDOW_STATE_LOAD(STATE_SETTING_NAME) \
{ \
    QApplication::processEvents(); \
    initialized = true; \
    gcprint("LOADING WINDOW STATE <- " STATE_SETTING_NAME); \
    dynamic_cast<QMainWindow*>(widget) ->restoreState( ideSettings::getByteArray(STATE_SETTING_NAME) ); \
}

#define RE_INIT(STATE_SETTING_NAME) {\
    QApplication::processEvents(); \
    connect(&updateTimer, SIGNAL(timeout()),this,SLOT(reloadWindowState())); \
    gcprint("LOADING WINDOW STATE <- " STATE_SETTING_NAME " [INIT]"); \
    restoreState( ideSettings::getByteArray(STATE_SETTING_NAME) ); \
}



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

    // Call this into your editor contructor:
    void initResourceEditor(QWidget* w);
    void postMessage(QString text, QVariant data);

    //Theresource associated with this editor
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

    virtual void reloadWindowState();

    QTimer updateTimer;
    bool initialized;

    //if the resource is modified:
    bool modified;
    virtual void makeModified();
    void updateTitle();
};

#endif // RESOURCEEDITOR_H
