#ifndef GCIDE_H
#define GCIDE_H

#include <QSettings>
#include <QStandardItemModel>
#include "../sharedcode/frameworkdata.h"
#include "../sharedcode/rsclass.h"
#include "../sharedcode/globals.h"
#include "../sharedcode/resourcetree.h"

class WorkspaceWidget;
class ResourceEditor;
class gameproject;
class MainWindow;
class SplashScreen;
class OpenedProject;
class gcresource;
class dllForExport;
class dllForResourceEditor;

class gcide: public QObject
{
    Q_OBJECT

public:
    gcide();
    bool init();
    int run();

    //pointer to the Main window
    MainWindow* mainWindow;

    //Pointer to the splash screen. Unset after initialization!
    SplashScreen* splashScreen;

    //piGameCreator's settings. Ready to use after init()
    QSettings* settings;

    //Images, models ans sound formats support
    QString gc2DformatsRead;
    QString gc2DformatsWrite;
    QString gc3DformatsRead;
    QString gc3DformatsWrite;
    QString gcSolidSoundFormats;
    QString gcTrackedSoundFormats;

    //Exporters
    QList<dllForExport*> exporterLibs;
    dllForExport* getExporter(QString name);

    //Resource editors
    QList<dllForResourceEditor*> resourceEditorLibs;

    //All currently opened projects.
    QList<OpenedProject*> projects;
    OpenedProject* currentProject;  //which project is treated as current?
    gcresource* currentResource;

    //creates a new project - opens the wizard and returns true if project was created, NULL if canceled
    //Created oroject will then be opened directly into the IDE
    bool newProject();

    //Loads a project - saves it into the projects[] and to the tree. Returns false if load fails
    bool openProject(QString filename);
    bool openProject(); //asks to select filename then opens the project

    //saves a project - in its file and location
    bool saveProject(OpenedProject* project, bool onlyTree = false);
    bool saveProjectAs(OpenedProject* project);   //asks for new file, saves it and clones project folder there
    bool saveProjectAs(OpenedProject* project, QString newFileName);  //saves to this file and clones project folder

    //closes a project - from index or from gameproject pointer
    bool closeProject(int index);
    bool closeProject(gameproject* project);
    bool closeProject(OpenedProject* project);

    //All opened workspace widgets
    QList<WorkspaceWidget*> openedWidgets;

    //Returns a list with currently opened resource editors
    QList<ResourceEditor*> resourceEditors();

    //creates and opens a workspace window / widget
    bool openWorkspaceWidget(WorkspaceWidget* w);
    void renameWorkspaceWidget(WorkspaceWidget* w, QString newname);

    //closes based on a widget pointer or a index
    bool closeWorkspaceWidget(WorkspaceWidget* w);
    bool closeWorkspaceWidget(int index);

    //Models
    QStandardItemModel* projectModel;

    //Resource editing
    //creates a new resource and adds it to the project ad the views
    bool newResource(OpenedProject* gp, QString kind);

    //Adds the resource to the project VIEWS
    bool addResource(OpenedProject* gp, gcresource* resource, bool=false);

    //Resource misc
    QIcon iconFromKind(QString kind);
    QIcon addIconFromKind(QString kind);
    QIcon delIconFromKind(QString kind);

    QString folderNameFromKind(QString kind);
    gcresource* resourceFromKind(QString kind);

    //Code Editor settings - part of the IDE, not the class editor
    void loadSettings();
    //fontsetting codeFormats[CODE_FORMATS_TOTAL_COUNT];

    void emitConfigChanged();

signals:
    void IDEConfigChanged();

};
extern gcide* creatorIDE;
#endif // GCIDE_H
