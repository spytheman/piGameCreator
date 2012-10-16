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
#include "scripttestwindow.h"
#include "settingswindow.h"
#include "buildtargets.h"
#include "newresource.h"
#include "../sharedcode/qtwin.h"
#include "../sharedcode/gameproject.h"
#include "../sharedcode/globals.h"
#include "../sharedcode/resource.h"
#include "../sharedcode/rsimage.h"
#include "../sharedcode/rsmodel.h"
#include "../sharedcode/rssound.h"
#include "../sharedcode/rsclass.h"
#include "../sharedcode/rsscene.h"
#include <QMessageBox>
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

    setWindowTitle("pi|engine CREATOR");
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
    UpdateTargetsCB(0);
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

    connect(ui->projectTree->selectionModel(),SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            this,SLOT(projectTreeSelection(QItemSelection,QItemSelection)));

    connect(creatorIDE->projectModel, SIGNAL(itemChanged(QStandardItem*)), this, SLOT(ProjectItemChanged(QStandardItem*)));

    // QGLWidget Crash Workaround & GCC Linker bug workaround
    QGLWidget initializeOpenGL;
    initializeOpenGL.makeCurrent();
    char* renderer = (char*)glGetString(GL_RENDERER);
    QString s = QString::fromLocal8Bit(renderer);    
}

void MainWindow::ProjectItemChanged(QStandardItem *item)
{
    QString newtext = item->text();
    if(newtext=="")newtext = "Folder";
    ResourceTreeNode* node = (ResourceTreeNode*)item->data(TIDATA).value<void*>();
    if(!node)gcerror("NULL ResourceTreeNode* ?");
    node->name = newtext;
    ui->projectTree->blockSignals(true);
    item->setText(newtext);
    ui->projectTree->blockSignals(false);
    creatorIDE->currentProject->project->save();
    // These lead to crashes
    //updateProjectExplorer();
    //focusProjectExplorer();
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

void MainWindow::UpdateTargetsCB(OpenedProject* p)
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
        else UpdateTargetsCB(0);
    }
    else
    {
        targetsCB->setEnabled(false);
        targetsCB->addItem(tr("No project opened"));
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
/*
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
*/
void MainWindow::updateProjectExplorer()
{
    //updates currently selected view
    updateProjectTrees();
}
void MainWindow::focusProjectExplorer()
{
    //focuses currently opened project's active widget - project tree, image library, class library and so on...
    ui->projectTree->setFocus();
}

void MainWindow::rec_addResourceEntry(ResourceTreeNode* node, QStandardItem* target, int level, OpenedProject* project)
{
    if(node->folder)
    {
        QStandardItem* folderNode = new QStandardItem(node->name);
        folderNode->setEditable(true);
        if(level==0)
        {
            QFont f;f.setBold(true);
            folderNode->setFont(f);
            folderNode->setEditable(false);
        }
        folderNode->setDropEnabled(true);
        folderNode->setIcon( ffficon("folder") );
        folderNode->setData( qVariantFromValue((void*)project), TIPROJECT);
        folderNode->setData( qVariantFromValue((void*)node), TIDATA );
        folderNode->setData( "folder", TIKIND);
        //if(creatorIDE->currentProject == project)
        if(project->selectedResource == node)
        {
            selectedWhileTreeRefresh = folderNode;
        }
        foreach(ResourceTreeNode* R, node->childs)
            rec_addResourceEntry(R,folderNode,++level,project);

        //For now all folders them!
        target->appendRow(folderNode);

        /*
        if(level>1 || folderNode->rowCount()>0)
            target->appendRow(folderNode);
        else delete folderNode; */

        if(project->expandedResources.contains(node))
            creatorIDE->mainWindow->ui->projectTree->expand( creatorIDE->projectModel->indexFromItem(folderNode) );
    }
    else
    {
        QStandardItem* res = new QStandardItem(node->name);
        res->setIcon(node->resource->icon);
        res->setEditable(false);
        res->setDropEnabled(false);
        res->setData( qVariantFromValue((void*)project), TIPROJECT);
        res->setData( qVariantFromValue((void*)node ), TIDATA );
        res->setData( node->resource->kind(), TIKIND);
        target->appendRow(res);

        //if(creatorIDE->currentProject == project)
        if(project->selectedResource == node)
        {
            selectedWhileTreeRefresh = res;
        }
    }
}

void MainWindow::updateProjectTrees()
{
    if(creatorIDE->currentProject == NULL)
    {
        creatorIDE->projectModel->clear();
        targetsCB->blockSignals(true);
        targetsCB->clear();
        targetsCB->setEnabled(false);
        targetsCB->addItem("No project opened");
        targetsCB->blockSignals(false);
        return;
    }

    //Updates the project tree
    ui->projectComboBox->blockSignals(true);
    creatorIDE->projectModel->clear();
    ui->projectComboBox->clear();
    selectedWhileTreeRefresh = NULL;

    int I = 0;
    foreach(OpenedProject* p, creatorIDE->projects)
    {
        // Add the project to the project combobox as well:
        ui->projectComboBox->addItem( ffficon("human-joystick") ,p->project->title,
                                     qVariantFromValue( (void*)p ));

        if(ui->projectComboBox->count()>1)ui->projectComboBox->setVisible(true);
        else ui->projectComboBox->setVisible(false);
        if(p == creatorIDE->currentProject)ui->projectComboBox->setCurrentIndex(I);
        ++I;
    }
    ui->projectComboBox->blockSignals(false);
    OpenedProject* p = creatorIDE->currentProject;
    {
        QStandardItem* projectNode = new QStandardItem(p->project->title);
        QFont f; f.setBold(true);
        if(p=creatorIDE->currentProject)selectedWhileTreeRefresh = projectNode;
        projectNode->setEditable(false);
        projectNode->setFont(f);
        projectNode->setBackground( QColor(0,0,0,15) );
        projectNode->setIcon( ffficon("human-joystick") );
        projectNode->setDropEnabled(1);

        // "project" node: Project AND data are OpenedProject* pointers
        projectNode->setData( qVariantFromValue((void*)p), TIPROJECT);
        projectNode->setData( qVariantFromValue((void*)p), TIDATA);
        projectNode->setData( "project",TIKIND);

        creatorIDE->projectModel->appendRow(projectNode);

        ui->projectTree->blockSignals(true);
        ui->projectTree->expand(creatorIDE->projectModel->indexFromItem(projectNode));
        ui->projectTree->blockSignals(false);



        // update targets combo box:
        UpdateTargetsCB(p);

        // Create the project resource tree
        ResourceTreeNode root = p->project->getRootNode();
        foreach(ResourceTreeNode* R, root.childs)
            rec_addResourceEntry(R, projectNode, 0, p);

        //Add some fixed features:
        QStandardItem* dashboard = new QStandardItem("Dashboard");
        dashboard->setIcon(ffficon("application_form"));
        dashboard->setData("dashboard", TIKIND);
        dashboard->setData( qVariantFromValue( (void*)p ),TIPROJECT );
        dashboard->setDropEnabled(false);
        dashboard->setEditable(false);
        QFont bf; bf.setBold(1); dashboard->setFont(bf);
        projectNode->insertRow(0,dashboard);
        if(p->isDashboardSelected)
        {
            ui->projectTree->setCurrentIndex( creatorIDE->projectModel->indexFromItem(dashboard) );
            return;
        }
    }

    //For more than 1 projects, proper project must be specified!
    if(selectedWhileTreeRefresh != NULL)
    {
        ui->projectTree->setCurrentIndex( creatorIDE->projectModel->indexFromItem(selectedWhileTreeRefresh));
    }
    selectedWhileTreeRefresh = NULL;
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
        • And creatorIDE's DEFAULT resource editor for that type will be used
          (because ALL default editors implement the type * as well as default type, OR maybe...)
        • If for some reason, there is NOT a DLL that supports this kind with * TYPE,
        ERROR will occur! [for example invalid resource kind was specified in the project XML]
     */
    QStandardItem* item = creatorIDE->projectModel->itemFromIndex(index);

    //FOLDERS:
    ResourceTreeNode* node = (ResourceTreeNode*)item->data(TIDATA).value<void*>();
    if(!node && item->data(TIKIND).toString() == "dashboard")
    {
        //This will open the project sadhboard
        gcerror("Dashboard is not implemented!");
        return;
    }
    gcresource* resource = node->resource;
    if(!node)return;
    if(node->folder)return;

    //projects:
    if(item->data(TIKIND).toString()=="project")return;

    //else it is resource
    res = node->resource;
    kind = res->kind();
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
            gcerror("pi|engine CREATOR is unable to edit this type of resource!\n Maybe it is created by newer version of pi|engine CREATOR or some of the files are missing.\n\nTry reinstalling pi|engine");
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
        editor->project = res->project;
        editor->init();
        openWorkspaceWidget(editor);
    }
    else gcerror("Unable to initialize GUI for editor "+selectedEditor->binaryFile() );
}

void MainWindow::on_projectTree_clicked(const QModelIndex &index)
{
    //Update the project that is selected in the Project Selector
    ui->projectComboBox->blockSignals(true);
    void* opr =  creatorIDE->projectModel->itemFromIndex(index)->data(TIPROJECT).value<void*>();
    for(int i=0;i<ui->projectComboBox->count();i++)
        if(ui->projectComboBox->itemData(i).value<void*>() == opr)
        {
            ui->projectComboBox->setCurrentIndex(i);
            //update the CURRENT PROJECT
            creatorIDE->currentProject = (OpenedProject*)opr;
        }
    //update the TARGETS
    ui->projectComboBox->blockSignals(false);
    UpdateTargetsCB(creatorIDE->currentProject);
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
        QAction closeproject(tr("&Close project")+" "+gp->title,0); closeproject.setIcon(ffficon("cross"));
        m.addAction(&save);m.addAction(&saveas);
        m.addSeparator();
        m.addAction(&closeproject);
        QAction* res = m.exec(QCursor::pos());
        //Close project
        if(res==&closeproject) creatorIDE->closeProject(op);
        return;
    }

    //FOLDERS:
    ResourceTreeNode* node = (ResourceTreeNode*)item->data(TIDATA).value<void*>();
    if(!node && item->data(TIKIND).toString()=="dashboard")
    {
        gcprint("Dashboard right click");
        return;
    }
    if(node->folder)
    {
        OpenedProject* op = ((OpenedProject*)(item->data(TIPROJECT).value<void*>()));
        gameproject* gp = op->project;
        kind = node->kind;
        QMenu m;
        QAction add("Add "+kind+"...",0);
        add.setIcon(creatorIDE->addIconFromKind(kind));

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
            newResource* w = new newResource(this);
            w->setKind( node->kind );
            if(w->exec())
            {
                gcresource* r = w->resource;
                if(!r->project)gcerror("Your ResourceEditor MUST fill the PROJECT field of the gcResource, returned by its CreateResource(gameproject*, QString, QString, QString) function");
                //it must fill its project.
                ResourceTreeNode* nn = new ResourceTreeNode;
                nn->kind = r->kind();
                nn->name = r->name;
                nn->folder = false;
                nn->resource = r;
                nn->root = false;
                node->childs.append(nn);
                creatorIDE->currentProject->selectedResource = nn;
                nn->resource->project->save();
                updateProjectExplorer();
                on_projectTree_doubleClicked(ui->projectTree->currentIndex());
            }

        }
        else if (res==&folder)
        {
            ResourceTreeNode* f = new ResourceTreeNode;
            f->name = "Folder";
            f->folder = true;
            f->root = false;
            f->kind = node->kind;
            node->childs.append(f);
            creatorIDE->currentProject->selectedResource = f;
            creatorIDE->currentProject->project->save();
            updateProjectExplorer();
            ui->projectTree->edit(ui->projectTree->currentIndex());
        }
        else if (res==&rename)
        {
            ui->projectTree->edit( creatorIDE->projectModel->indexFromItem(item) );
        }
        else if(res==&delete_item)
        {
            if( QMessageBox::question(this,"Delete "+node->name,
                                      "Do you want to permanently delete this folder?",
                                      QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes )
            {
                gcprint("DELETE ITEM called");
                QList<gcresource*> resources = gp->getResourcesUnderNode(node);
                gp->removeTreeNode(node);
                delete node;
                foreach(gcresource* r, resources)
                {
                    //must delete EVERYTHING from the resource folder!
                    QString folderpath = r->project->absoluteFolder() + "/" + r->relativeFolder();
                    gcRemoveFolder(folderpath);
                    QDir d(folderpath); d.cdUp();
                    gcRemoveFiles( d.absolutePath(), r->name +".*");
                    gcprint("REMOVING RESOURCE: "+r->name);

                    //Close resource if opened
                    foreach(WorkspaceWidget* ww, creatorIDE->openedWidgets)
                        if(ww->isResourceEditor())
                            if( ((ResourceEditor*)ww)->resource == r )
                            {
                                ww->widget->close();
                                creatorIDE->openedWidgets.removeAll(ww);
                            }
                    delete r;
                }
                //This saves only the tree
                gp->save();
                updateProjectExplorer();
                focusProjectExplorer();
            }
        }
        return;
    }

    //RESOURCES:
    kind = item->data(TIKIND).toString();
    ResourceTreeNode* rtn = (ResourceTreeNode*)(item->data(TIDATA).value<void*>());
    res = rtn->resource;
    type = res->type;
    name = res->name;

    //Default resource menu:
    QMenu menu;
    QIcon deleteIcon = ffficon("cancel");
    QAction clone(ffficon("page_white_copy"),"Duplicate "+kind, &menu);
    QAction exportResource(ffficon("package_go"),"Export this "+kind, &menu);
    QAction del(deleteIcon, "Delete "+kind, &menu);
    menu.addAction(&clone);
    menu.addAction(&exportResource);
    menu.addAction(&del);

    //query ALL resource editors for additional menu items:
    foreach(dllForResourceEditor* re, creatorIDE->resourceEditorLibs)
    {
        QList<QAction*> items = re->contextMenuItems(kind,type,false,res);
        if(items.count()>0)
        {
            menu.addSeparator();
            foreach(QAction* a,items)
            {
                connect(a,SIGNAL(triggered()),this, SLOT(routeRightMenuClickToItsDLL()));
                a->setProperty("DLLINSTANCE", qVariantFromValue( (void*)re ) );
            }
            menu.addActions(items);
        }
    }
    menu.addSeparator();
    QAction* lastAction = menu.actions().at(menu.actions().count()-1);
    if(lastAction->isSeparator())delete lastAction;
    //menu.addSeparator();
    QAction* r = menu.exec(QCursor::pos());

    //now let's do the job with selected option:
    if(r==&del)
    {
        //we must DELETE anything related to this resource!
        if( QMessageBox::question(this,"Delete "+res->name,
                                  "Do you want to permanently delete this resource?",
                                  QMessageBox::Yes, QMessageBox::No) == QMessageBox::Yes )
        {
            //must delete EVERYTHING from the resource folder!
            QString folderpath = res->project->absoluteFolder() + "/" + res->relativeFolder();
            gcRemoveFolder(folderpath);
            QDir d(folderpath); d.cdUp();
            gcRemoveFiles( d.absolutePath(), res->name +".*");
            res->project->removeResource(res);

            //Close resource if opened
            foreach(WorkspaceWidget* ww, creatorIDE->openedWidgets)
                if(ww->isResourceEditor())
                    if( ((ResourceEditor*)ww)->resource == res )
                    {
                        ww->widget->close();
                        creatorIDE->openedWidgets.removeAll(ww);
                    }
            res->project->save();   //only the tree
            delete res;
            updateProjectExplorer();
            focusProjectExplorer();
        }
    }
}

void MainWindow::routeRightMenuClickToItsDLL()
{
    QAction* a = (QAction*) sender();
    dllForResourceEditor* re = (dllForResourceEditor*) a->property("DLLINSTANCE").value<void*>();
    re->contextMenuItemClicked(a);
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
    UpdateTargetsCB(creatorIDE->currentProject);
}

void MainWindow::on_action_Run_triggered()
{
    if(creatorIDE->currentProject==0)return;
    OpenedProject* op = creatorIDE->currentProject;

    //must not go out of bounds...
    buildtarget* bt = op->project->buildTargets().at(op->selectedTarget);
    if(bt->exporter->isValid())
        bt->exporter->run(op->project->filename());
    else on_action_Targets_triggered();
}

void MainWindow::on_action_Debug_triggered()
{
    if(creatorIDE->currentProject==0)return;
    OpenedProject* op = creatorIDE->currentProject;

    //must not go out of bounds...
    buildtarget* bt = op->project->buildTargets().at(op->selectedTarget);
    if(bt->exporter->isValid())
        bt->exporter->debug(op->project->filename());
    else on_action_Targets_triggered();
}

void MainWindow::on_actionBuild_triggered()
{
    if(creatorIDE->currentProject==0)return;
    OpenedProject* op = creatorIDE->currentProject;

    //must not go out of bounds...
    buildtarget* bt = op->project->buildTargets().at(op->selectedTarget);
    if(bt->exporter->isValid())
        bt->exporter->build(op->project->filename(),false);
    else on_action_Targets_triggered();
}

void MainWindow::on_projectTree_expanded(const QModelIndex &index)
{
    ResourceTreeNode* r = (ResourceTreeNode*)index.data(TIDATA).value<void*>();
    OpenedProject* p = (OpenedProject*)index.data(TIPROJECT).value<void*>();
    // if p and r are same this is a project node so ignore it
    if( (void*)p == (void*)r ) return;
    p->expandedResources.append(r);
    gcprint("Expanding "+r->name);
}

void MainWindow::on_projectTree_collapsed(const QModelIndex &index)
{
    if(index.data(TIKIND).toString()=="project")return;
    ResourceTreeNode* r = (ResourceTreeNode*)index.data(TIDATA).value<void*>();
    if(!r)return;
    OpenedProject* p = (OpenedProject*)index.data(TIPROJECT).value<void*>();
    p->expandedResources.removeAll(r);
    gcprint("Collapsing "+r->name);
}

void MainWindow::on_toolButton_clicked()
{
    updateProjectExplorer();
}

void MainWindow::on_toolButton_2_clicked()
{
    updateProjectExplorer();
}

void MainWindow::projectTreeSelection(QItemSelection current, QItemSelection previous)
{
    QModelIndexList l = current.indexes();
    if(l.count()!=1)return;
    QModelIndex index = l.at(0);
    ResourceTreeNode* node = (ResourceTreeNode*)index.data(TIDATA).value<void*>();
    QStandardItem* i = creatorIDE->projectModel->itemFromIndex(index);
    OpenedProject* op = (OpenedProject*)i->data(TIPROJECT).value<void*>();
    op->isDashboardSelected = false;
    if(!node && i->data(TIKIND).toString() == "dashboard")
    {
        op->isDashboardSelected = true;
    }
    if(!node) return;
    op->selectedResource = node;

    //This must also update the targets combobox
    creatorIDE->currentProject = op;
    creatorIDE->mainWindow->UpdateTargetsCB(op);
}

void MainWindow::on_projectComboBox_currentIndexChanged(int index)
{
    OpenedProject* op = (OpenedProject*) ui->projectComboBox->itemData(index).value<void*>();
    if(!op)return;
    creatorIDE->currentProject = op;
    gcprint("Setting project " +op->project->title + " as current" );
    updateProjectExplorer();
}

void MainWindow::on_pushButton_clicked()
{
    QStringList names = creatorIDE->currentProject->project->getAllResourceNames();
    QListWidget* ww = new QListWidget;
    ww->addItems(names);
    ww->setAttribute(Qt::WA_DeleteOnClose);
    ww->show();
}

void MainWindow::on_action_Save_triggered()
{
    //Just to test that
    creatorIDE->currentProject->project->save();
}

void MainWindow::on_actionOpen_project_triggered()
{
    creatorIDE->openProject();
}

void MainWindow::on_actionCreate_project_triggered()
{
    creatorIDE->newProject();
}
