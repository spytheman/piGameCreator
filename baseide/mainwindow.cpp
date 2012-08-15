#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "gcide.h"
#include "QApplication"
#include "workspacewidget.h"
#include "wwmainpage.h"
#include "model/projecttreemodel.h"
#include "dllforresourceeditor.h"
#include "openedproject.h"
#include "inputresourcename.h"
#include "gameframeworkclassdef.h"
#include "scripttestwindow.h"
#include "settingswindow.h"
#include "buildtargets.h"
#include "../sharedcode/gameproject.h"
#include "../sharedcode/globals.h"
#include "../sharedcode/resource.h"
#include "../sharedcode/rsimage.h"
#include "../sharedcode/rsmodel.h"
#include "../sharedcode/rssound.h"
#include "../sharedcode/rsclass.h"
#include "../sharedcode/rsscene.h"
#include <QPushButton>
#include <QStandardItem>
#include <QDir>
#include <QTimer>
#include <QAction>
#include <QDialog>
#include <QGLWidget>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
   // int argc = QApplication::instance()->argc();
   // glutInit(&argc,QApplication::instance()->argv());

    ui->setupUi(this);
    creatorIDE->mainWindow=this;
    ui->centralWidget->layout()->setContentsMargins(0,0,0,0);
    ui->WorkSpaceMDIContainer->hide();


    //remove ALL the DEVELOPER stuff
    if(!QApplication::arguments().contains("-dev"))
    {
        ui->menuDeveloper->setVisible(false);
    }
    ui->projectComboBox->hide();

    //Exporter selector
    targetsCB = new QComboBox;
    connect(targetsCB, SIGNAL(currentIndexChanged(int)), this, SLOT(BuildTargetChanged(int)));
    RebuildTargetsCB(0);
    ui->runToolbar->insertWidget(ui->action_Targets,targetsCB);

    //Prepare the skins menu:
    SkinsMenu = new QMenu;
    ui->actionSkins->setMenu(SkinsMenu);
    connect(SkinsMenu,SIGNAL(aboutToShow()),this,SLOT(ShowSkins()));

    connect(&OpenWidgetTimer,SIGNAL(timeout()),this,SLOT(LastWWClosed()));

    //init the project tree to represent the last selected option
    //TODO
    ui->stackedWidget->setCurrentWidget(ui->pgProjectTree);

    //add a mainPage to the widgets
    creatorIDE->openWorkspaceWidget(new wwMainPage);

    QList<QAction*> acts = ui->viewToolbar->actions();
    foreach(QAction* a,acts)
    {
        connect(a,SIGNAL(triggered()),this,SLOT(ResViewChange()));
    }

    //Set appropriate models
    ProjectTreeModel* ptm = new ProjectTreeModel;
    ui->projectTree->setModel(ptm);
    creatorIDE->projectModel = ptm;
    ui->projectTree->setAcceptDrops(true);

    ui->viewToolbar->setFloatable(1);
    ui->viewToolbar->setWindowFlags(Qt::Tool);

    //Load files from cmdline
    QStringList ARGV = QApplication::arguments();
    int i=0;
    foreach(QString a,ARGV)
    {
        if(a.at(0)!='-' and i!=0 and QFile::exists(a))
        {
            creatorIDE->openProject(a);
            i++;
        }
    }

    ui->actionToolbars->setMenu( createPopupMenu() );

    // QGLWidget Crash Workaround & GCC Linker bug workaround
    QGLWidget initializeOpenGL;
    initializeOpenGL.makeCurrent();
    char* renderer = (char*)glGetString(GL_RENDERER);
    QString s = QString::fromLocal8Bit(renderer);    
}

void MainWindow::ResViewChange()
{
    QAction* s = qobject_cast<QAction*>(sender());
    if(!s)return;
    if(!s->isChecked())
    {
        ui->projectDockWidget->hide();
        return;
    }
    else ui->projectDockWidget->show();

    QList<QAction*> acts = ui->viewToolbar->actions();
    foreach(QAction* a,acts)
    {
        bool state=false;
        if(sender()==a)state=true;
        a->setChecked(state);
        //connect(a,SIGNAL(triggered()),this,SLOT(ResViewChange()));
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    creatorIDE->settings->setValue("MainWindow/Geometry",saveGeometry());
    creatorIDE->settings->setValue("MainWindow/State",saveState());
}

void MainWindow::showEvent(QShowEvent *)
{
    //Init the mainWindow [and do it only on first show!]
    static bool shown=false;
    if(shown)return;
    gcprint("Showing Mainwindow");
    restoreGeometry(creatorIDE->settings->value("MainWindow/Geometry").toByteArray());
    restoreState(creatorIDE->settings->value("MainWindow/State").toByteArray());
    shown = true;
}
void MainWindow::openWorkspaceWidget(WorkspaceWidget *w)
{
    gcprint("Opening workspace widget: "+w->widget->objectName());
    //by default only tabs will be supported
    ui->WorkSpaceTabWidget->addTab( w->widget ," "+w->title());
    ui->WorkSpaceTabWidget->setCurrentWidget(w->widget);
    creatorIDE->openedWidgets.append(w);

    //Each opened workspace widget must know its pointer
    //as each WorkspaceWidget must know its actual widget
    w->widget->setProperty("WorkspaceWidget",qVariantFromValue(  (void*)w ) );
}

void MainWindow::RebuildTargetsCB(OpenedProject* p)
{
    gameproject* gp;
    if(p==0) gp=0;
    else gp = p->project;

    targetsCB->blockSignals(true);
    targetsCB->clear();
    if(gp!=0)
    {
        if(gp->buildTargets().count()>0)
        {
            targetsCB->setEnabled(true);
            foreach(buildtarget* T,gp->buildTargets())
                targetsCB->addItem(QIcon(),T->name,qVariantFromValue((void*)T));
            targetsCB->setCurrentIndex(p->selectedTarget);
        }
        else RebuildTargetsCB(0);
    }
    else
    {
        targetsCB->setEnabled(false);
        targetsCB->addItem(tr("No targets available"));
    }
    targetsCB->blockSignals(false);
}

void MainWindow::ShowSkins()
{
    //Load the skins:
    SkinsMenu->clear();
    QDir d("themes");
    QStringList sl = d.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    sl.sort();
    foreach(QString theme,sl)
    {

        //determine the SKIN NAME? Subskins?
        QDir dd("themes/"+theme);
        QStringList themefiles = dd.entryList(QStringList("*.css"));
        foreach(QString tf,themefiles)
        {
            QAction* a = new QAction(SkinsMenu);
            //determine the theme name
            QString name;
            QFile f(QDir::currentPath()+ "/themes/"+theme+"/"+tf);
            if(f.open(QIODevice::ReadOnly))
            {
                QString s = f.readAll();
                int i = s.indexOf("THEME: ")+7;
                int end=s.indexOf("\n",i);
                if(end==-1)end=s.indexOf("\r",i);
                if(end==-1)gcerror("Skin name problem!");
                QString name = s.mid(i,end-i);

               // QMessageBox::information(0,"",s);
                a->setText(name);
                a->setData(QDir::currentPath()+ "/themes/"+theme+"/"+tf); //file
                connect(a,SIGNAL(triggered()),this,SLOT(setSkin()));
                SkinsMenu->addAction(a);
            }
            else gcprint("Unable to read file: "+QDir::currentPath()+ "/themes/"+theme+"/"+tf);
        }
    }
}
void MainWindow::setSkin()
{
    QAction* a = (QAction*)sender();
    QFile f(a->data().toString());
    if(f.open(QIODevice::ReadOnly))
    {
        QString s = f.readAll();
        qApp->setStyleSheet(s);
    }
    creatorIDE->settings->setValue("creatorIDE/Skin",a->data().toString());
}

void MainWindow::on_action_Run_triggered()
{

}

void MainWindow::on_WorkSpaceTabWidget_tabCloseRequested(int index)
{
    WorkspaceWidget* w =  (WorkspaceWidget*) ui->WorkSpaceTabWidget->widget(index)->property("WorkspaceWidget").value<void*>();

    //if it is NOT an resource editor:
    if(!w->isResourceEditor())
    {
        if(w->widget->close())  //Qt::WA_DeleteOnClose will delete the widget!
        {
            for(int i=0;i<creatorIDE->openedWidgets.count();i++)
            {
                if(creatorIDE->openedWidgets.at(i) == w)
                    creatorIDE->openedWidgets.removeAt(i);
            }
        }
    }
    else // if it is resource editor
    {
        //ask for save or whatever...
        if(w->widget->close())  //Qt::WA_DeleteOnClose will delete the widget!
        {
            for(int i=0;i<creatorIDE->openedWidgets.count();i++)
            {
                if(creatorIDE->openedWidgets.at(i) == w)
                    creatorIDE->openedWidgets.removeAt(i);
            }
        }
    }

    if(creatorIDE->openedWidgets.count()==0)
    {
        creatorIDE->openWorkspaceWidget(new wwMainPage);
    }
}
void MainWindow::LastWWClosed()
{
    creatorIDE->openWorkspaceWidget(new wwMainPage);
}

bool MainWindow::addResourceEntry(OpenedProject *opr, gcresource *r, bool open)
{
    gcprint(r->kind());
    gcprint(r->type);
    gameproject* p = opr->project;
    QStandardItem* folder=0, *project=0;
    // get the project root for the TREE
    for(int i=0;i<creatorIDE->projectModel->rowCount();i++)
    {
        if(creatorIDE->projectModel->item(i)->data(TIPROJECT).value<void*>() == (void*)opr)
            project = creatorIDE->projectModel->item(i);
    }
    if(project==0)gcerror("Project is NOT opened! Please file a bug report what actually happened!");

    //check does this folder exists?
    QString foldername = creatorIDE->folderNameFromKind(r->kind());
    for(int i=0;i<project->rowCount();i++)
    {
        QString fn = project->child(i)->text();
        if(fn==foldername) folder = project->child(i);
    }

    if(folder==0)
    {
        //no such folder exists! It will be added to the tree!
        QFont f; f.setBold(true);

        // @RESOURCES create folder for given kind
        QStandardItem* itemFolder = new QStandardItem(foldername);
        itemFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
        itemFolder->setEditable(false);
        itemFolder->setData(r->kind(),TIKIND);
        itemFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
        itemFolder->setData(NULL,TIDATA);
        itemFolder->setFont(f);
        project->appendRow(itemFolder);
        folder = itemFolder;
        //gcerror("Missing folder inserted!");
    }

    //Now add the actual resource under that folder ;]

    QStandardItem* rn = new QStandardItem();
    rn->setIcon(r->icon);
    rn->setText(r->name);
    rn->setData(r->kind(),TIKIND);
    rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
    rn->setData(qVariantFromValue((void*)r), TIDATA);
    rn->setDropEnabled(0);
    folder->appendRow(rn);

    gcprint("TODO:  MainWindow::addResourceEntry -> Add to the other views as well!");

    // Open and select the resource if requested
    if(open)
    {
        ui->projectTree->setCurrentIndex(creatorIDE->projectModel->indexFromItem(rn));
        on_projectTree_doubleClicked( creatorIDE->projectModel->indexFromItem(rn) );
    }
}

void MainWindow::addProjectEntry(OpenedProject *opr)
{
    gameproject* p = opr->project;

    //Adds project to the TREE and ALL comboboxes

    QStandardItem* projectNode = new QStandardItem(p->title());
    QFont f; f.setBold(true);
    projectNode->setEditable(false);
    projectNode->setFont(f);
    projectNode->setBackground( QColor(0,0,0,15) );
    projectNode->setIcon( ffficon("human-joystick") );
    projectNode->setDropEnabled(1);

    // "project" node: Project AND data are OpenedProject* pointers
    projectNode->setData( qVariantFromValue((void*)opr), TIPROJECT);
    projectNode->setData( qVariantFromValue((void*)opr), TIDATA);
    projectNode->setData( "project",TIKIND);

    creatorIDE->projectModel->appendRow(projectNode);
    ui->projectTree->expand(creatorIDE->projectModel->indexFromItem(projectNode));

    // Add the project to the project combobox as well:
    ui->projectComboBox->addItem(projectNode->icon(),projectNode->text(), projectNode->data(TIPROJECT));
    if(ui->projectComboBox->count()>1)ui->projectComboBox->setVisible(true);
    else ui->projectComboBox->setVisible(false);
    creatorIDE->currentProject = opr;

    // update targets combo box:
    RebuildTargetsCB(opr);

    // @RESOURCES
    // Now for each resource, add it to the tree:
    foreach(gcresource* r,p->images())  addResourceEntry(opr,r);
    foreach(gcresource* r,p->models())  addResourceEntry(opr,r);
    foreach(gcresource* r,p->sounds())  addResourceEntry(opr,r);
    foreach(gcresource* r,p->classes()) addResourceEntry(opr,r);
    foreach(gcresource* r,p->scenes())  addResourceEntry(opr,r);
    return; //rest code is unused old code

    //images:
    QStandardItem* imagesFolder = new QStandardItem("Images");
    imagesFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
    imagesFolder->setEditable(false);
    imagesFolder->setData("image",TIKIND);
    imagesFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
    imagesFolder->setData(NULL,TIDATA);
    imagesFolder->setFont(f);
    foreach(gcresource* r,p->images())
    {
        QStandardItem* rn = new QStandardItem();
        rn->setIcon(r->icon);
        rn->setText(r->name);
        rn->setData("image",TIKIND);
        rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
        rn->setData(qVariantFromValue((void*)r), TIDATA);
        rn->setDropEnabled(0);
        imagesFolder->appendRow(rn);
    }
    if(p->images().count()>0)projectNode->appendRow(imagesFolder);
    else delete imagesFolder;


    //sounds:
    QStandardItem* soundsFolder = new QStandardItem("Sounds");
    soundsFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
    soundsFolder->setEditable(false);
    soundsFolder->setData("sound",TIKIND);
    soundsFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
    soundsFolder->setData(NULL,TIDATA);
    soundsFolder->setFont(f);
    foreach(gcresource* r,p->sounds())
    {
        QStandardItem* rn = new QStandardItem();
        rn->setIcon(r->icon);
        rn->setText(r->name);
        rn->setData("sound",TIKIND);
        rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
        rn->setData(qVariantFromValue((void*)r), TIDATA);
        rn->setDropEnabled(0);
        soundsFolder->appendRow(rn);
    }
    if(p->sounds().count()>0)projectNode->appendRow(soundsFolder);
    else delete soundsFolder;


    //models:
    QStandardItem* modelsFolder = new QStandardItem("Models");
    modelsFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
    modelsFolder->setEditable(false);
    modelsFolder->setData("model",TIKIND);
    modelsFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
    modelsFolder->setData(NULL,TIDATA);
    modelsFolder->setFont(f);
    foreach(gcresource* r,p->models())
    {
        QStandardItem* rn = new QStandardItem();
        rn->setIcon(r->icon);
        rn->setText(r->name);
        rn->setData("model",TIKIND);
        rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
        rn->setData(qVariantFromValue((void*)r), TIDATA);
        rn->setDropEnabled(0);
        modelsFolder->appendRow(rn);
    }
    if(p->models().count()>0)projectNode->appendRow(modelsFolder);
    else delete modelsFolder;

    //classes:
    QStandardItem* classesFolder = new QStandardItem("Classes");
    classesFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
    classesFolder->setEditable(false);
    classesFolder->setData("model",TIKIND);
    classesFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
    classesFolder->setData(NULL,TIDATA);
    classesFolder->setFont(f);
    foreach(gcresource* r,p->classes())
    {
        QStandardItem* rn = new QStandardItem();
        rn->setIcon(r->icon);
        rn->setText(r->name);
        rn->setData("class",TIKIND);
        rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
        rn->setData(qVariantFromValue((void*)r), TIDATA);
        rn->setDropEnabled(0);
        classesFolder->appendRow(rn);
    }
    if(p->classes().count()>0)projectNode->appendRow(classesFolder);
    else delete classesFolder;

    //scenes:
    QStandardItem* scenesFolder = new QStandardItem("Scenes");
    scenesFolder->setIcon( qApp->style()->standardIcon(QStyle::SP_DirClosedIcon));
    scenesFolder->setEditable(false);
    scenesFolder->setData("scene",TIKIND);
    scenesFolder->setData(qVariantFromValue((void*)opr), TIPROJECT);
    scenesFolder->setData(NULL,TIDATA);
    scenesFolder->setFont(f);
    foreach(gcresource* r,p->scenes())
    {
        QStandardItem* rn = new QStandardItem();
        rn->setIcon(r->icon);
        rn->setText(r->name);
        rn->setData("scene",TIKIND);
        rn->setData(qVariantFromValue((void*)opr), TIPROJECT);
        rn->setData(qVariantFromValue((void*)r), TIDATA);
        rn->setDropEnabled(0);
        scenesFolder->appendRow(rn);
    }
    if(p->scenes().count()>0)projectNode->appendRow(scenesFolder);
    else delete scenesFolder;


    //Add the rest here!

    QStandardItemModel* sim = qobject_cast<QStandardItemModel*>(ui->projectTree->model());
    if(sim) sim->appendRow(projectNode);
    ui->projectTree->expand(sim->indexFromItem(projectNode));

    // Add the project to the project combobox as well:
    ui->projectComboBox->addItem(projectNode->icon(),projectNode->text(), projectNode->data(TIPROJECT));
    creatorIDE->currentProject = opr;
}

void MainWindow::on_projectTree_doubleClicked(const QModelIndex &index)
{
    QString kind,type,name,file;
    gcresource* res;
    /* WHAT is doubleclicked:

      PROJECT and FOLDER:  Does nothing [will expand it]
      RESOURCE:  Open it with default editor

        The DLL instance being used is determined by the following algorithm:
        • It must support the proper resource kind AND type.
        • If NO DLL supports both KIND and TYPE, TYPE will be set to * (asterisk) string
        • And piGameCreator's DEFAULT resource editor for that type will be used
          (because ALL default editors implement the type * as well as default type, OR maybe...)
        • If for some reason, there is NOT a DLL that supports this kind with * TYPE,
        ERROR will occur! [for example invalid resource kind was specified in the project XML]
     */
    QStandardItem* item = creatorIDE->projectModel->itemFromIndex(index);

    //FOLDERS:
    if(item->data(TIDATA)==NULL)return;

    //projects:
    if(item->data(TIKIND).toString()=="project")return;

    //else it is resource
    kind = item->data(TIKIND).toString();
    res = (gcresource*)(item->data(TIDATA).value<void*>());
    type = res->type;
    name = res->name;
    //gcmessage(name + ": " + kind + " " + type);

    //Now check if this resource is already opened:
    foreach(WorkspaceWidget* ww,creatorIDE->openedWidgets)
    {
        if(ww->isResourceEditor())
        {
            ResourceEditor* e = (ResourceEditor*)ww;
            if(e->resource == res)  //pointer comparison?
            {
                ui->WorkSpaceTabWidget->setCurrentWidget(ww->widget);
                return;
            }
        }
    }

    QList<dllForResourceEditor*> possibleEditors;

    // It must support the proper resource kind AND type.
    foreach(dllForResourceEditor* re, creatorIDE->resourceEditorLibs)
    {
        QStringList kinds = re->getResourceKinds(), types = re->getResourceTypes();
        if(kinds.contains(kind) && types.contains(type))
        {
            //This editor is supported!
            possibleEditors.append(re);
        }
    }

    //  If NO DLL supports both KIND and TYPE,
    if(possibleEditors.count()==0)
    {
        //  TYPE will be set to * (asterisk) string
        type = "*";

        //  and we do the check again:
        foreach(dllForResourceEditor* re, creatorIDE->resourceEditorLibs)
        {
            QStringList kinds = re->getResourceKinds(), types = re->getResourceTypes();
            if(kinds.contains(kind) && types.contains(type))
            {
                //This editor is supported!
                possibleEditors.append(re);
            }
        }

        //and if now, again, there is NOTHING, we
        if(possibleEditors.count()==0)
        {
            gcerror("piGameCreator is unable to edit this type of resource!\n Maybe it is created by newer version of piGameCreator or some of the files are missing.\n\nTry reinstalling piGameCreator");
            return;
        }
    }

    dllForResourceEditor* selectedEditor;
    if(possibleEditors.count()==1)
    {
        selectedEditor = possibleEditors.at(0);
    }
    else    // if >1
    {
        gcmessage("Too many possible editors");
        foreach(dllForResourceEditor* dll,possibleEditors)
        {
            gcprint(dll->getName());
        }
        selectedEditor = possibleEditors.at(0);
    }

    //Done. After EDITOR was determined, let's actually open the resource for editing
    ResourceEditor* editor = selectedEditor->getGUI(kind,type,res);
    if(editor!=0)
    {
        //Each resource editor must KNOW the IDE
        editor->creatorIDE = creatorIDE;
        editor->resource = res;
        editor->init();
        openWorkspaceWidget(editor);
    }
    else gcerror("Unable to initialize GUI for editor "+selectedEditor->binaryFile() );
}

void MainWindow::on_projectTree_clicked(const QModelIndex &index)
{
    //Update the project that is selected in the Project Selector
    void* opr =  creatorIDE->projectModel->itemFromIndex(index)->data(TIPROJECT).value<void*>();
    for(int i=0;i<ui->projectComboBox->count();i++)
        if(ui->projectComboBox->itemData(i).value<void*>() == opr)
        {
            ui->projectComboBox->setCurrentIndex(i);
            //update the CURRENT PROJECT
            creatorIDE->currentProject = (OpenedProject*)opr;
        }
    //update the TARGETS
    RebuildTargetsCB(creatorIDE->currentProject);
}

void MainWindow::BuildTargetChanged(int row)
{
    creatorIDE->currentProject->selectedTarget = row;
}

void MainWindow::on_projectTree_customContextMenuRequested(const QPoint &pos)
{
    if(!ui->projectTree->currentIndex().isValid())return;
    QStandardItem* item = creatorIDE->projectModel->itemFromIndex(ui->projectTree->currentIndex());
    QString kind,type,name;
    gcresource* res;

    //PROJECTS:
    if(item->data(TIKIND).toString()=="project")
    {
        OpenedProject* op = ((OpenedProject*)(item->data(TIDATA).value<void*>()));
        gameproject* gp = op->project;
        //project menu is fixed
        QMenu m;
        QAction save(tr("&Save project"),0); save.setIcon(ffficon("disk"));
        QAction saveas(tr("Save &as..."),0);
        QAction closeproject(tr("&Close project")+" "+gp->title(),0); closeproject.setIcon(ffficon("cross"));
        m.addAction(&save);m.addAction(&saveas);
        m.addSeparator();
        m.addAction(&closeproject);
        QAction* res = m.exec(QCursor::pos());
        return;
    }

    //FOLDERS:
    if(item->data(TIDATA)==NULL)
    {
        OpenedProject* op = ((OpenedProject*)(item->data(TIPROJECT).value<void*>()));
        gameproject* gp = op->project;
        kind = item->data(TIKIND).toString();

        QMenu m;
        QAction add("Add "+kind+"...",0); add.setIcon(creatorIDE->addIconFromKind(kind));

        //folder management TODO:
        QAction folder(tr("Add &folder..."),0);folder.setIcon(ffficon("folder_add"));
        QAction delete_item(tr("Delete this folder"),0);delete_item.setIcon(ffficon("cancel"));
        QAction rename(tr("Rename folder"),0);rename.setIcon(ffficon("textfield_rename"));
        m.addAction(&add);
        m.addAction(&folder);

        //add folder/delete/rename
        if(item->parent()->data(TIKIND).toString()!="project")
        {
            m.addSeparator();
            m.addAction(&delete_item); m.addAction(&rename);
        }
        QAction* res = m.exec(QCursor::pos());
        if(res==&add)
        {
            // Add the required resource.
            QDialog* w = creatorIDE->getNewDialogForKind(kind);
            if(w)
            {
                w->exec();  //How should I pass the taken data? IN PROPERTIES
                vObject o = w->property("data").toHash();
                if(!o.isEmpty())
                {
                    InputResourceName irn;
                    irn.exec();
                    if(irn.enteredName!="")
                    {
                        //exec problem???
                        name = irn.enteredName;
                        kind = o.value("kind").toString();
                        type = o.value("type").toString();
                        dllForResourceEditor* re = (dllForResourceEditor*) o.value("pluginlibpointer").value<void*>();

                        //gcmessage(re->getName());
                        gcresource* newres = re->createResource(kind,type,name);
                        if(newres)
                        {
                            //resource was created! Add it to the project AND to the views
                            creatorIDE->addResource(op,newres,true);
                        }
                        //else do nothnig
                        else gcprint("Cannot add NULL resource to the project");
                    }
                }
            }
            else gcerror("Cannot add "+kind+"\nFeature not implemented");
        }
        return;
    }

    //RESOURCES:
    kind = item->data(TIKIND).toString();
    res = (gcresource*)(item->data(TIDATA).value<void*>());
    type = res->type;
    name = res->name;
}

void MainWindow::on_actionFramework_editor_triggered()
{
    GameFrameworkClassDef w(this);
    w.setWindowFlags(Qt::Window);
    w.exec();
}

void MainWindow::on_action_Preferences_triggered()
{
    //open settings
    SettingsWindow s(this);
    s.exec();
}

void MainWindow::on_actionGameScript_tester_triggered()
{
    scripttestwindow* w = new scripttestwindow(this);
    w->setWindowModality(Qt::ApplicationModal);
    w->show();
}

void MainWindow::on_action_Targets_triggered()
{
    if(creatorIDE->currentProject==0)return;
    BuildTargets w(creatorIDE->currentProject);
    w.setParent(this);
    w.setWindowFlags(Qt::Window);
    w.exec();
    RebuildTargetsCB(creatorIDE->currentProject);
}
