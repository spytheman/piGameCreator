#include "gcide.h"
#include "splashscreen.h"
#include "mainwindow.h"
#include "workspacewidget.h"
#include "openedproject.h"
#include "newimage.h"
#include "dllforresourceeditor.h"
#include "scripttestwindow.h"
#include "../sharedcode/gameproject.h"
#include "../sharedcode/resource.h"
#include "../sharedcode/rsclass.h"
#include "../sharedcode/rsimage.h"
#include "../sharedcode/rsmodel.h"
#include "../sharedcode/rsscene.h"
#include "../sharedcode/rssound.h"
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
    QCoreApplication::setOrganizationName("Pi-Dev");
    QCoreApplication::setOrganizationDomain("http://pi-dev.com");
    QCoreApplication::setApplicationName("piGameCreator");
    QSettings::setDefaultFormat(QSettings::IniFormat);
    settings = new QSettings();

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

bool gcide::openProject()
{
    //No arguments passed? Ask user to select files then

    QStringList selectedfiles = QFileDialog::getOpenFileNames(creatorIDE->mainWindow,"Select projects to open",
            "", "piGameCreator project files (*.gcpx);;piGameCreator project archives (*.gcpz);;XML files (*.xml);;All files (*)");
    foreach(QString s,selectedfiles) creatorIDE->openProject(s);
}

bool gcide::openProject(QString filename)
{
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
         creatorIDE->mainWindow->addProjectEntry(op);
    }
    else gcprint("Unable to open the project");
}

// @RESOURCES
QIcon gcide::iconFromKind(QString kind)
{
    if(kind=="image")return ffficon("image");
    if(kind=="class")return ffficon("brick");
    if(kind=="model")return ffficon("car");
    if(kind=="sound")return ffficon("sound");
    if(kind=="world")return ffficon("world");
    if(kind=="scene")return ffficon("application");
}
QIcon gcide::addIconFromKind(QString kind)
{
    if(kind=="image")return ffficon("image_add");
    if(kind=="class")return ffficon("brick_add");
    if(kind=="model")return ffficon("car_add");
    if(kind=="sound")return ffficon("sound_add");
    if(kind=="world")return ffficon("world_add");
    if(kind=="scene")return ffficon("application_add");
}
// @RESOURCES
QString gcide::folderNameFromKind(QString kind)
{
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

QDialog* gcide::getNewDialogForKind(QString kind)
{
    //NEW dialogs @RESOURCES
    if(kind=="image")return new newImage;
}

bool gcide::addResource(OpenedProject *gp, gcresource *resource, bool open)
{
    creatorIDE->mainWindow->addResourceEntry(gp,resource,open);
    return true;
}

void gcide::loadSettings()
{

    //Code formats:
    creatorIDE->codeFormats[CFkeyword].bold = creatorIDE->settings->value("CodeEditor/format_keyword_bold").toBool();
    creatorIDE->codeFormats[CFfunction].bold = creatorIDE->settings->value("CodeEditor/format_function_bold").toBool();
    creatorIDE->codeFormats[CFvariable].bold = creatorIDE->settings->value("CodeEditor/format_variable_bold").toBool();
    creatorIDE->codeFormats[CFresource].bold = creatorIDE->settings->value("CodeEditor/format_resource_bold").toBool();
    creatorIDE->codeFormats[CFclass].bold = creatorIDE->settings->value("CodeEditor/format_class_bold").toBool();
    creatorIDE->codeFormats[CFnumber].bold = creatorIDE->settings->value("CodeEditor/format_number_bold").toBool();
    creatorIDE->codeFormats[CFstring].bold = creatorIDE->settings->value("CodeEditor/format_string_bold").toBool();
    creatorIDE->codeFormats[CFoperator].bold = creatorIDE->settings->value("CodeEditor/format_operator_bold").toBool();
    creatorIDE->codeFormats[CFcomment].bold = creatorIDE->settings->value("CodeEditor/format_comment_bold").toBool();
    creatorIDE->codeFormats[CFpreproc].bold = creatorIDE->settings->value("CodeEditor/format_preproc_bold").toBool();
    creatorIDE->codeFormats[CFnormaltext].bold = creatorIDE->settings->value("CodeEditor/format_normaltext_bold").toBool();
    creatorIDE->codeFormats[CFerror].bold = creatorIDE->settings->value("CodeEditor/format_error_bold").toBool();

    creatorIDE->codeFormats[CFkeyword].italic = creatorIDE->settings->value("CodeEditor/format_keyword_italic").toBool();
    creatorIDE->codeFormats[CFfunction].italic = creatorIDE->settings->value("CodeEditor/format_function_italic").toBool();
    creatorIDE->codeFormats[CFvariable].italic = creatorIDE->settings->value("CodeEditor/format_variable_italic").toBool();
    creatorIDE->codeFormats[CFresource].italic = creatorIDE->settings->value("CodeEditor/format_resource_italic").toBool();
    creatorIDE->codeFormats[CFclass].italic = creatorIDE->settings->value("CodeEditor/format_class_italic").toBool();
    creatorIDE->codeFormats[CFnumber].italic = creatorIDE->settings->value("CodeEditor/format_number_italic").toBool();
    creatorIDE->codeFormats[CFstring].italic = creatorIDE->settings->value("CodeEditor/format_string_italic").toBool();
    creatorIDE->codeFormats[CFoperator].italic = creatorIDE->settings->value("CodeEditor/format_operator_italic").toBool();
    creatorIDE->codeFormats[CFcomment].italic = creatorIDE->settings->value("CodeEditor/format_comment_italic").toBool();
    creatorIDE->codeFormats[CFpreproc].italic = creatorIDE->settings->value("CodeEditor/format_preproc_italic").toBool();
    creatorIDE->codeFormats[CFnormaltext].italic = creatorIDE->settings->value("CodeEditor/format_normaltext_italic").toBool();
    creatorIDE->codeFormats[CFerror].italic = creatorIDE->settings->value("CodeEditor/format_error_italic").toBool();

    creatorIDE->codeFormats[CFkeyword].underline = creatorIDE->settings->value("CodeEditor/format_keyword_underline").toBool();
    creatorIDE->codeFormats[CFfunction].underline = creatorIDE->settings->value("CodeEditor/format_function_underline").toBool();
    creatorIDE->codeFormats[CFvariable].underline = creatorIDE->settings->value("CodeEditor/format_variable_underline").toBool();
    creatorIDE->codeFormats[CFresource].underline = creatorIDE->settings->value("CodeEditor/format_resource_underline").toBool();
    creatorIDE->codeFormats[CFclass].underline = creatorIDE->settings->value("CodeEditor/format_class_underline").toBool();
    creatorIDE->codeFormats[CFnumber].underline = creatorIDE->settings->value("CodeEditor/format_number_underline").toBool();
    creatorIDE->codeFormats[CFstring].underline = creatorIDE->settings->value("CodeEditor/format_string_underline").toBool();
    creatorIDE->codeFormats[CFoperator].underline = creatorIDE->settings->value("CodeEditor/format_operator_underline").toBool();
    creatorIDE->codeFormats[CFcomment].underline = creatorIDE->settings->value("CodeEditor/format_comment_underline").toBool();
    creatorIDE->codeFormats[CFpreproc].underline = creatorIDE->settings->value("CodeEditor/format_preproc_underline").toBool();
    creatorIDE->codeFormats[CFnormaltext].underline = creatorIDE->settings->value("CodeEditor/format_normaltext_underline").toBool();
    creatorIDE->codeFormats[CFerror].underline = creatorIDE->settings->value("CodeEditor/format_error_underline").toBool();

    creatorIDE->codeFormats[CFkeyword].color = creatorIDE->settings->value("CodeEditor/format_keyword_color").value<QColor>();
    creatorIDE->codeFormats[CFfunction].color = creatorIDE->settings->value("CodeEditor/format_function_color").value<QColor>();
    creatorIDE->codeFormats[CFvariable].color = creatorIDE->settings->value("CodeEditor/format_variable_color").value<QColor>();
    creatorIDE->codeFormats[CFresource].color = creatorIDE->settings->value("CodeEditor/format_resource_color").value<QColor>();
    creatorIDE->codeFormats[CFclass].color = creatorIDE->settings->value("CodeEditor/format_class_color").value<QColor>();
    creatorIDE->codeFormats[CFnumber].color = creatorIDE->settings->value("CodeEditor/format_number_color").value<QColor>();
    creatorIDE->codeFormats[CFstring].color = creatorIDE->settings->value("CodeEditor/format_string_color").value<QColor>();
    creatorIDE->codeFormats[CFoperator].color = creatorIDE->settings->value("CodeEditor/format_operator_color").value<QColor>();
    creatorIDE->codeFormats[CFcomment].color = creatorIDE->settings->value("CodeEditor/format_comment_color").value<QColor>();
    creatorIDE->codeFormats[CFpreproc].color = creatorIDE->settings->value("CodeEditor/format_preproc_color").value<QColor>();
    creatorIDE->codeFormats[CFnormaltext].color = creatorIDE->settings->value("CodeEditor/format_normaltext_color").value<QColor>();
    creatorIDE->codeFormats[CFerror].color = creatorIDE->settings->value("CodeEditor/format_error_color").value<QColor>();

}
