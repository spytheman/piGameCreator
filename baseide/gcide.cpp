#include "gcide.h"
#include "splashscreen.h"
#include "mainwindow.h"
#include "workspacewidget.h"
#include "openedproject.h"
#include "newimage.h"
#include "dllforresourceeditor.h"
#include "scripttestwindow.h"
#include "wwmainpage.h"
#include "newprojectwizard.h"
#include "projectdashboard.h"
#include "../sharedcode/gameproject.h"
#include "../sharedcode/resource.h"
#include "../sharedcode/rsclass.h"
#include "../sharedcode/rsimage.h"
#include "../sharedcode/rsmodel.h"
#include "../sharedcode/rsscene.h"
#include "../sharedcode/rssound.h"
#include "../../sharedcode/idesettings.h"
#include <QApplication>
#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <new>


gcide* creatorIDE;

gcide::gcide()
{
    creatorIDE = this;
    currentProject = 0;
    currentResource = 0;
}

bool gcide::init()
{
    //Prepare application configuration
    settings = ideSettings::settings();

    //Add plugin paths
    QString SS = QDir::currentPath()+"/data";
    QCoreApplication::addLibraryPath(SS);

    gcprint("Starting piGameCreator...");

    //Check if the EXE is started in the proper folder
    gcprint(QDir::currentPath());
    gcprint("QApplication dir: "+QApplication::applicationDirPath());
    if(!QFile::exists("data"))
    {
        QString s = QObject::tr("piGameCreator installation is corrupted!\n"
                                "The data folder is missing.\n\n"
                                "Try reinstalling piGameCreator, or check\n"
                                "if you are running it in proper working directory!");
        QMessageBox err;
        err.setText(s);
        err.setWindowTitle("piGameCreator Error");
        err.setIcon(QMessageBox::Critical);
        err.setWindowIcon(ffficon("cancel"));
        err.exec();
        return false;
    }

    //Load the skin.... Damn threads...
    QString skinfile = settings->value("creatorIDE/Skin","themes/default/default.css").toString();
    QFile f(skinfile);
    if(f.open(QIODevice::ReadOnly))
    {
        qApp->setStyleSheet(f.readAll());
    }/**/

    //Show the splash screen - it WAITS intil it completes..... :|
    SplashScreen* ss = new SplashScreen;
    ss->exec();
    ss->setMessage("Enjoy!");
    ss->ShowForAWhile();

    //The splash screen starts the initialization thread
    return true;
}

void no_memory()
{
    gcerror("Unable to allocate memory for this operation.\n"
            "The application will now terminate.\n\n"
            "If you work with large resources, like huge classes, \n"
            "or huge scenes, try keeping as few tabs as possible! \n"
            "32-bit versions of Windows have 2 GB memory limit per process! \n"
            "You can also try to run the Windows Kernel in 3 GB mode");
}

int gcide::run()
{
    try
    {
        MainWindow* w = new MainWindow;
        if(qApp->arguments().contains("--gsdebug"))
        {
            scripttestwindow* stw = new scripttestwindow;
            stw->showMaximized();
            return qApp->exec();
        }
        else
        {
            w->showMaximized();
            return qApp->exec();
        }
    }
    catch(std::bad_alloc)
    {
        no_memory();
    }
}

void gcide::emitConfigChanged()
{
    emit IDEConfigChanged();
}

bool gcide::openWorkspaceWidget(WorkspaceWidget* w)
{
    mainWindow->openWorkspaceWidget(w);
    return true;
}

void gcide::renameWorkspaceWidget(WorkspaceWidget *w, QString newname)
{
    mainWindow->renameWorkspaceWidget(w,newname);
}

bool gcide::openProject()
{
    //No arguments passed? Ask user to select files then

    QStringList selectedfiles = QFileDialog::getOpenFileNames(creatorIDE->mainWindow,"Select projects to open",
            "", "piGameCreator project files (*.gcpx);;piGameCreator project archives (*.gcpz);;XML files (*.xml);;All files (*)");
    foreach(QString s,selectedfiles) creatorIDE->openProject(s);
}

bool gcide::openProject(QString filename)
{
    // Does this file exists??
    if(!QFile::exists(filename))
    {
        gcerror("The file you tried to open no longer exists.\nIt will be removed from this listing.");
        QStringList recentFiles = ideSettings::get("creatorIDE/RecentFiles").toStringList();
        recentFiles.removeAll(filename);
        ideSettings::set("creatorIDE/RecentFiles", recentFiles);
        foreach(WorkspaceWidget* ww,creatorIDE->openedWidgets)
            if(ww->widget->property("mainpage").toBool()==true)
            {
                wwMainPage* page = (wwMainPage*)ww->widget;
                page->refresh();
            }
        return false;
    }

    //check if this project is already loaded
    foreach(OpenedProject* p, creatorIDE->projects)
    {
        QString rfn = QFileInfo(filename).absoluteFilePath();
        if(p->project->filename()==rfn)
        {
            // The project is already opened.
            // Just set it as current and re-show the project summary page / or preselect it
            gcprint("The project "+filename+" is already opened");

            return false;
        }
    }

    //Loads a project and adds it to the project tree
    gameproject* gp = new gameproject(filename);
    if(gp->load())
    {
        //validate and update the exporters
        foreach(buildtarget* t, gp->buildTargets())
        {
            QString expname = t->exportername;
            foreach(dllForExport* d, creatorIDE->exporterLibs)
                if(d->exporterName()==expname)
                {
                    t->exporter = d;
                    t->valid = true;
                    break;
                }
        }

        //add the project to the opened projects
        OpenedProject* op = new OpenedProject;
        op->project = gp;
        creatorIDE->projects.append(op);

        //Must add to the project tree and all other widgets of this type

        //add to recent files as well
        creatorIDE->settings->sync();
        QStringList Recent = creatorIDE->settings->value("creatorIDE/RecentFiles",QStringList()).toStringList();
        Recent.append(filename);
        Recent.removeDuplicates();
        creatorIDE->settings->setValue("creatorIDE/RecentFiles",Recent);
        creatorIDE->settings->sync();
        creatorIDE->currentProject = op;

        // This API is not needed! Views will be updated manually by each op
        creatorIDE->mainWindow->updateProjectExplorer();

        // Open its dashboard:
        ProjectDashboard* pd = new ProjectDashboard;
        pd->setProject(op);
        pd->init();
        openWorkspaceWidget(pd);
    }
    else gcprint("Unable to open the project");
}

// @RESOURCES
QIcon gcide::iconFromKind(QString kind)
{
    if(kind=="image") return ffficon("image");
    if(kind=="class") return ffficon("brick");
    if(kind=="model") return ffficon("car");
    if(kind=="sound") return ffficon("sound");
    if(kind=="world") return ffficon("world");
    if(kind=="scene") return ffficon("application");
    if(kind=="font")  return ffficon("font");
    if(kind=="filter")return ffficon("contrast");
    if(kind=="effect")return ffficon("rainbow");
}
QIcon gcide::addIconFromKind(QString kind)
{
    if(kind=="image") return ffficon("image_add");
    if(kind=="class") return ffficon("brick_add");
    if(kind=="model") return ffficon("car_add");
    if(kind=="sound") return ffficon("sound_add");
    if(kind=="world") return ffficon("world_add");
    if(kind=="scene") return ffficon("application_add");
    if(kind=="font")  return ffficon("font_add");
    if(kind=="filter")return ffficon("add");
    if(kind=="effect")return ffficon("add");
}
QIcon gcide::delIconFromKind(QString kind)
{
    if(kind=="image")return ffficon("image_delete");
    if(kind=="class")return ffficon("brick_delete");
    if(kind=="model")return ffficon("car_delete");
    if(kind=="sound")return ffficon("sound_delete");
    if(kind=="world")return ffficon("world_delete");
    if(kind=="scene")return ffficon("application_delete");
    if(kind=="font")  return ffficon("font_delete");
    if(kind=="filter")return ffficon("bin");
    if(kind=="effect")return ffficon("bin");
}
// @RESOURCES
QString gcide::folderNameFromKind(QString kind)
{
    gcerror("Deprecated");
    if(kind=="image")return "Images";
    if(kind=="class")return "Classes";
    if(kind=="model")return "Models";
    if(kind=="sound")return "Sounds";
    if(kind=="world")return "Worlds";
    if(kind=="scene")return "Scenes";
}

// @RESOURCES
gcresource* gcide::resourceFromKind(QString kind)
{
    if(kind=="image")return new rsImage;
    if(kind=="class")return new rsClass;
    if(kind=="model")return new rsModel;
    if(kind=="sound")return new rsSound;
    if(kind=="scene")return new rsScene;
}

bool gcide::newResource(OpenedProject* op, QString kind)
{
    gameproject* gp = op->project;

    //show the "New..." wizard for this resource KIND
    foreach(dllForResourceEditor* re,creatorIDE->resourceEditorLibs)
    {

    }

    //create the required resource:
    //gcresource* res = piGameCreator->resourceFromKind(kind);
    //res->name
    //gp->addResource( piGameCreator->resourceFromKind(kind) );

    //add it to the views as well
}

bool gcide::addResource(OpenedProject *gp, gcresource *resource, bool open)
{
    gcerror("What does this do?");
    //ResourceTreeNode* target = gp->project->getKindFolder(resource->kind());
    //target->childs.append();
    //creatorIDE->mainWindow->addResourceEntry(gp,resource,open);
    //return true;
}

void gcide::loadSettings()
{
    ideSettings::initSettings();
}

dllForExport* gcide::getExporter(QString name)
{
    foreach(dllForExport* d, exporterLibs)
        if(d->exporterName()==name)
            return d;
    return 0;
}

bool gcide::saveProject(OpenedProject *project, bool onlyTree)
{
    project->project->save(project->project->filename());
}

bool gcide::saveProjectAs(OpenedProject *project)
{
    //@TODO: Copy from old codebase
    return false;
}

bool gcide::saveProjectAs(OpenedProject *project, QString newFileName)
{
    return false;
}

bool gcide::closeProject(OpenedProject *project)
{
    QList<int> removeIndexes;
    for(int i=0;i<projects.count();i++)
    {
        if( projects.at(i) == project)
        {
            //close all editors coresponding to this project:
            for(int wwindex=0; wwindex<openedWidgets.count();wwindex++)
                if(openedWidgets.at(wwindex)->isResourceEditor())
                {
                    ResourceEditor* re = dynamic_cast<ResourceEditor*>(openedWidgets.at(wwindex));
                    if(re->project == project->project)
                    {
                        // Ask to save
                        if(re->modified)
                            if(QMessageBox::question(
                                        mainWindow,
                                        "Save "+re->resource->name,
                                        "Do you want to save changes you made to " + re->resource->kind() +": "
                                        +re->resource->name,
                                        QMessageBox::Yes, QMessageBox::No
                                        ))
                                re->save();

                        //remove from the list
                        delete openedWidgets.at(wwindex);  //possible double deallocation
                        removeIndexes.append(wwindex);
                    }
                }
                else if(openedWidgets.at(wwindex)->widget->property("dashboard").toBool())
                {
                    //a dashboard
                    ProjectDashboard* pd = dynamic_cast<ProjectDashboard*>(openedWidgets.at(wwindex));
                    if(!pd)gcerror("Bad cast?");
                    else
                    {
                        if(pd->project == project)
                        {
                            delete openedWidgets.at(wwindex);  //possible double deallocation
                            removeIndexes.append(wwindex);
                        }
                    }
                }

            //remove the project from the opened projects list
            projects.removeAt(i);
            delete project;
        }
    }

    //remove all the opened widgets
    for(int i=openedWidgets.count()-1;i>=0;i--)
        if(removeIndexes.contains(i))
        {
            openedWidgets.at(i)->widget->close();
            openedWidgets.removeAt(i);
        }

    // Avoid crashes, invalidate the current project!
    if(projects.count()>0)currentProject = projects.at(projects.count()-1);
    else currentProject = NULL;

    mainWindow->updateProjectExplorer();
}

bool gcide::newProject()
{
    newProjectWizard w(creatorIDE->mainWindow);
    w.exec();   //This will open the project.
    //Again safe workaround
    QApplication::processEvents();
}
