#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QProgressBar>
#include <QTabBar>
#include <QToolBar>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QTableView>
#include <QCloseEvent>
#include <QComboBox>
#include "logwindow.h"
#include "mainpage.h"
#include "gamecreator.h"
#include "imagewindow.h"
#include "classwindow.h"
#include "sceneeditor.h"
#include "saveornot.h"
#include "qtwin.h"
#include "buildtargets.h"
#include "srcSettings/settingswindow.h"
#include <qgraphicseffect.h>
#include "buildtargets.h"
#include "skintestwindow.h"
#include "gameframeworkclassdef.h"
#include "overlay.h"
#include <cmath>

void dim(QPainter* p, QWidget* t)
{
    //This piece of code is unused and experimental!
    //But is still stable
    p->setRenderHint(QPainter::Antialiasing);
    p->setRenderHint(QPainter::SmoothPixmapTransform);

    MainWindow* w = (MainWindow*)t;
    if(w->rec_drawOverlay==false)return;
    p->setBrush(QColor(0,0,0,0));
    p->drawRect(0,0,w->width(),w->height());

    QPixmap hpass(w->width(),w->height());
    QPixmap vpass(w->width(),w->height());
    QPainter H(&hpass);
    int x,prec=1;
    for(int i=0;i<w->height();i+=prec)
    {
        x = sin((i+w->frame)/10.0)*4.0;
        H.drawPixmap(x,i,w->width(),prec,*w->LastIdeFrame,0,i,w->width(),prec);
    }

    QPainter V(&vpass);
    int y;
    for(int i=0;i<w->width();i+=prec)
    {
        y = sin((i+w->frame*3.0)/30.0)*5.0;
        V.drawPixmap(i,y,prec,w->height(),hpass,i,0,prec,w->height());
    }/**/

    p->drawPixmap(0,0,w->width(),w->height(),vpass);
}

void MainWindow::updateOverlay()
{
    if(mustUpdate)update();
    Overlay->repaint();
    frame+=3;
}

//static vars
ProjectModel* MainWindow::pmodel;

MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*
    LastIdeFrame = new QPixmap();
    rec_drawOverlay=true;
    overlayTimer.setInterval(1000/60);
    overlayTimer.setSingleShot(0);
    connect(&overlayTimer,SIGNAL(timeout()),this,SLOT(updateOverlay()));
    overlayTimer.start();
    Overlay = new overlay(this,(OverlayPainterFP)dim);
    /**/
    thewindow = this;
    if(!QApplication::arguments().contains("-dev"))
    {
        //remove ALL the DEVELOPER stuff
        ui->menuDeveloper->setVisible(false);
    }
    gcprint("Interface setup completed.");
    ui->WorkSpaceTabWidget->addTab(new MainPage," "+tr("Main page"));
    setAttribute(Qt::WA_QuitOnClose);
    tutorials=0;
    SkinsMenu = new QMenu;
    ui->actionSkins->setMenu(SkinsMenu);
    connect(SkinsMenu,SIGNAL(aboutToShow()),this,SLOT(ShowSkins()));

    //Exporter selector
    targetsCB = new QComboBox;
    connect(targetsCB, SIGNAL(currentIndexChanged(int)), this, SLOT(BuildTargetChanged(int)));
    RebuildTargetsCB(0);

    ui->runToolbar->insertWidget(ui->action_Targets,targetsCB);


    //Recent files list
    if(RecentFiles.count()>0)
    {
        //add elements
        for(int i=0;(i<RecentFiles.count()) and (i<nrOfRecentFiles);i++)
        {
            QAction* m = new QAction(this);
            m->setText("&"+QString::number(i+1)+". "+QFileInfo(RecentFiles.at(i)).fileName());
            m->setData( RecentFiles.at(i) );
            connect(m,SIGNAL(triggered()),this,SLOT(openRecentFile()));
            ui->menu_File->insertAction(ui->actionExit,m);
        }
        ui->menu_File->insertSeparator(ui->actionExit);
    }
    else
    {
        //no elements
    }

    // project model init:
    ui->treeView->setModel(&projects);
    projects.treeview = ui->treeView;
    projects.workspace = ui->WorkSpaceTabWidget;
    connect(ui->treeView,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(TreeContextMenu()));
    connect(ui->treeView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(ItemClicked(QModelIndex)));
    pmodel = &projects;

    //Load files from cmdline
    QStringList ARGV = QApplication::arguments();
    int i=0;
    foreach(QString a,ARGV)
    {
        if(a.at(0)!='-' and i!=0 and QFile::exists(a))
        {
            gcOpenProject(a);
            i++;
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
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
                connect(a,SIGNAL(triggered()),this,SLOT(settheme()));
                SkinsMenu->addAction(a);
            }
            else gcprint("Unable to read file: "+QDir::currentPath()+ "/themes/"+theme+"/"+tf);
        }
    }
}
void MainWindow::settheme()
{
    QAction* a = (QAction*)sender();
    QFile f(a->data().toString());
    if(f.open(QIODevice::ReadOnly))
    {
        QString s = f.readAll();
        qApp->setStyleSheet(s);
    }
}

ProjectModel* MainWindow::projectModel()
{
    return MainWindow::pmodel;
}

int MainWindow::gcOpenProject(QString s)
{
    projects.open(s);
    return 0;
}

void MainWindow::openRecentFile()
{
    QAction* a = (QAction*)sender();
    gcprint(a->data().toString());
}

void MainWindow::closeEvent(QCloseEvent* e)
{
    bool mustexit=true;


    while(projects.rowCount(QModelIndex()) != 0 )
    {
       void* d= projects.itemFromIndex(projects.index(0,0))->data(TIPROJECT).value<void*>();
       gameproject* dd = (gameproject*)d;
       if(projects.close(dd)==0){mustexit=false;break;}
    }/**/

    if(!mustexit)e->ignore();

}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionShowLog_triggered()
{
   if(gclog==0)gclog = new logwindow;
   gclog->setParent(this);
   gclog->move(400,200);
   gclog->setWindowFlags(Qt::Window);
   gclog->show();
}

void MainWindow::TutorialsVisible(bool a)
{
    ui->actionTutorials->setChecked(tutorials->isVisible());
}

void MainWindow::on_actionTutorials_triggered(bool checked)
{

    if(tutorials==0)
    {
        gcprint("Initializing tutorials pane...");
        tutorials = new QDockWidget(tr("Tutorials"),this);
        tutorials->setAllowedAreas
                (Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

        tutorials->setWidget(new logwindow); // this for now :D
        connect(tutorials,SIGNAL(visibilityChanged(bool)),this,SLOT(TutorialsVisible(bool)));

        addDockWidget(Qt::RightDockWidgetArea,tutorials);
        ui->actionTutorials->setChecked(true);
    }
    else
    if(tutorials->isVisible())
    {
        gcprint("Hiding tutorials pane");
        tutorials->setVisible(false);
        ui->actionTutorials->setChecked(false);
    }
    else
    {
        gcprint("Showing tutorials pane");
        tutorials->setVisible(true);
        ui->actionTutorials->setChecked(true);
    }
}

void MainWindow::on_actionTEST_triggered()
{

}

void MainWindow::on_WorkSpaceTabWidget_tabCloseRequested(int i)
{
    if(i<0)return;
    QWidget* w = ui->WorkSpaceTabWidget->widget(i);
    if(w->property("editor").toBool())
    {
        resourceeditor* re = dynamic_cast<resourceeditor*>(w);
        if(re->modified)
        {
            int a = saveornot::resource(re->name);
            if(a==1){gcBeginWait(); re->save(); w->close(); gcEndWait();}
            if(a==-1){w->close();}
        }
        else w->close();
    }
    else w->close();
    if(ui->WorkSpaceTabWidget->count()==1)on_actionShow_Main_page_triggered();
}

void MainWindow::on_actionClose_active_tab_triggered()
{
   on_WorkSpaceTabWidget_tabCloseRequested(ui->WorkSpaceTabWidget->currentIndex());
}

void MainWindow::on_actionShow_Main_page_triggered()
{
    int t = ui->WorkSpaceTabWidget->addTab(new MainPage," "+tr("Main page"));
    ui->WorkSpaceTabWidget->setCurrentIndex(t);
}

void MainWindow::on_actionOpen_project_triggered()
{
    QString s = QFileDialog::getOpenFileName(this,tr("Open project"),"","piGameCreator project (*.gcpx)");
    if(s!="")
    {
        gcOpenProject(s);
        RebuildTargetsCB(0);
    }
}

void MainWindow::TreeContextMenu()
{
    if(projects.treeview->currentIndex().isValid()==false)return;
    QStandardItem* a = projects.itemFromIndex(projects.treeview->currentIndex());
    QString type = a->data(TITYPE).toString();
    QString data = a->data(TIDATA).toString();
    //bool folder = !a->data(TIFILE).toBool();
    //gcmessage(  QString("Type: %1\nData: %2\nFolder: %3").arg(type).arg(data).arg(folder?"true":"false")  );
    gameproject* gp = (gameproject*) a->data(TIPROJECT).value<void*>();
    if(type=="imagefolder" or (data=="image" and type=="folder")) //image folder
    {
        QMenu m;
        QAction add(tr("Create &new image..."),0);add.setIcon(ffficon("image_add")); m.addAction(&add);
        QAction import(tr("&Import from file..."),0); import.setIcon(ffficon("folder_go")); m.addAction(&import);
        QAction folder(tr("Create &folder..."),0);folder.setIcon(ffficon("folder_add")); m.addAction(&folder);
        QAction delete_item(tr("Delete this folder"),0);delete_item.setIcon(ffficon("cancel"));
        QAction rename(tr("Rename folder"),0);rename.setIcon(ffficon("textfield_rename"));
        if(type=="folder"){m.addAction(&rename);m.addAction(&delete_item);}
        m.addSeparator();
        QAction exportall(tr("&Export all..."),0); exportall.setIcon(ffficon("disk_multiple"));  m.addAction(&exportall);
        QAction* r = m.exec(QCursor::pos());
        if(r==&add)
        {
            //Add the image
            newimage(gp,a->index());
        }
        else if(r==&folder)newfolder(gp,"image",a->index(),true);
        else if(r==&rename)projects.treeview->edit(a->index());
        else if(r==&delete_item)projects.delresource(a->index());

    }
    else if(type=="classfolder" or (data=="class" and type=="folder")) //class folder
    {
        QMenu m;
        QAction add(tr("Create &new class..."),0);add.setIcon(ffficon("brick_add")); m.addAction(&add);
        QAction import(tr("&Import from file..."),0); import.setIcon(ffficon("folder_go")); m.addAction(&import);
        QAction folder(tr("Create &folder..."),0);folder.setIcon(ffficon("folder_add")); m.addAction(&folder);
        QAction delete_item(tr("Delete this folder"),0);delete_item.setIcon(ffficon("cancel"));
        QAction rename(tr("Rename folder"),0);rename.setIcon(ffficon("textfield_rename"));
        if(type=="folder"){m.addAction(&rename);m.addAction(&delete_item);}
        m.addSeparator();
        QAction exportall(tr("&Export all..."),0); exportall.setIcon(ffficon("disk_multiple"));  m.addAction(&exportall);
        QAction* r = m.exec(QCursor::pos());
        if(r==&add)
        {
            //Add the image
            newclass(gp,a->index());
        }
        else if(r==&folder)newfolder(gp,"class",a->index(),true);
        else if(r==&rename)projects.treeview->edit(a->index());
        else if(r==&delete_item)projects.delresource(a->index());
    }
    else if(type=="scenefolder" or (data=="scene" and type=="folder")) //scene folder
    {
        QMenu m;
        QAction add(tr("Create &new scene..."),0);add.setIcon(ffficon("application_add")); m.addAction(&add);
        QAction import(tr("&Import from file..."),0); import.setIcon(ffficon("folder_go")); m.addAction(&import);
        QAction folder(tr("Create &folder..."),0);folder.setIcon(ffficon("folder_add")); m.addAction(&folder);
        QAction delete_item(tr("Delete this folder"),0);delete_item.setIcon(ffficon("cancel"));
        QAction rename(tr("Rename folder"),0);rename.setIcon(ffficon("textfield_rename"));
        if(type=="folder"){m.addAction(&rename);m.addAction(&delete_item);}
        m.addSeparator();
        QAction exportall(tr("&Export all..."),0); exportall.setIcon(ffficon("disk_multiple"));  m.addAction(&exportall);
        QAction* r = m.exec(QCursor::pos());
        if(r==&add)
        {
            //Add the image
            newclass(gp,a->index());
        }
        else if(r==&folder)newfolder(gp,"class",a->index(),true);
        else if(r==&rename)projects.treeview->edit(a->index());
        else if(r==&delete_item)projects.delresource(a->index());
    }

    else if(type=="project")
    {
        QMenu m;
        QAction save(tr("&Save project"),0); save.setIcon(ffficon("disk"));
        QAction saveas(tr("Save &as..."),0);
        QAction closeproject(tr("&Close project")+" "+gp->name,0); closeproject.setIcon(ffficon("cross"));
        m.addAction(&save);m.addAction(&saveas);m.addAction(&closeproject);
        QAction* res = m.exec(QCursor::pos());

        //Project closing
        if(res==&closeproject)
        {
            projects.close(gp);
            RebuildTargetsCB(0);
        }

        //saving project...
        if(res==&save)gp->save();
        if(res==&saveas)gp->saveAs();
    }

    else if(type=="image")
    {
        QMenu m;
        QAction open(tr("&Edit image"),0); open.setIcon(ffficon("application_edit")); m.addAction(&open);
        QAction clone(tr("&Clone image..."),0); clone.setIcon(ffficon("page_white_copy")); m.addAction(&clone);
        QAction rename(tr("&Rename image"),0); rename.setIcon(ffficon("textfield_rename")); m.addAction(&rename);
        QAction EXPORT(tr("E&xport image..."),0); EXPORT.setIcon(ffficon("application_go")); m.addAction(&EXPORT);
        QAction delete_item(tr("Delete image"),0); delete_item.setIcon(ffficon("cancel")); m.addAction(&delete_item);
        QFont f;f.setBold(true);open.setFont(f);
        QAction* r = m.exec(QCursor::pos());
        if(r==&open)ItemClicked(a->index());
        else if(r==&delete_item)projects.delresource(a->index());
        else if(r==&rename)projects.treeview->edit(a->index());
        else if(r==&clone) projects.cloneresource(a->index());
        else if(r==&EXPORT)projects.exportresource(a->index());
    }
    else if(type=="class")
    {
        QMenu m;
        QAction open(tr("&Edit class"),0); open.setIcon(ffficon("application_edit")); m.addAction(&open);
        QAction clone(tr("&Clone class..."),0); clone.setIcon(ffficon("page_white_copy")); m.addAction(&clone);
        QAction rename(tr("&Rename class"),0); rename.setIcon(ffficon("textfield_rename")); m.addAction(&rename);
        QAction EXPORT(tr("E&xport class..."),0); EXPORT.setIcon(ffficon("application_go")); m.addAction(&EXPORT);
        QAction delete_item(tr("Delete class"),0); delete_item.setIcon(ffficon("cancel")); m.addAction(&delete_item);
        QFont f;f.setBold(true);open.setFont(f);
        QAction* r = m.exec(QCursor::pos());
        if(r==&open)ItemClicked(a->index());
        else if(r==&delete_item)projects.delresource(a->index());
        else if(r==&rename)projects.treeview->edit(a->index());
        else if(r==&clone) projects.cloneresource(a->index());
        else if(r==&EXPORT)projects.exportresource(a->index());
    }
    else if(type=="scene")
    {
        QMenu m;
        QAction open(tr("&Edit scene"),0); open.setIcon(ffficon("application_edit")); m.addAction(&open);
        QAction clone(tr("&Clone scene..."),0); clone.setIcon(ffficon("page_white_copy")); m.addAction(&clone);
        QAction rename(tr("&Rename scene"),0); rename.setIcon(ffficon("textfield_rename")); m.addAction(&rename);
        QAction EXPORT(tr("E&xport scene..."),0); EXPORT.setIcon(ffficon("application_go")); m.addAction(&EXPORT);
        QAction delete_item(tr("Delete scene"),0); delete_item.setIcon(ffficon("cancel")); m.addAction(&delete_item);
        QFont f;f.setBold(true);open.setFont(f);
        QAction* r = m.exec(QCursor::pos());
        if(r==&open)ItemClicked(a->index());
        else if(r==&delete_item)projects.delresource(a->index());
        else if(r==&rename)projects.treeview->edit(a->index());
        else if(r==&clone) projects.cloneresource(a->index());
        else if(r==&EXPORT)projects.exportresource(a->index());
    }
}

void MainWindow::ItemClicked(QModelIndex index)
{
    gcBeginWait();
    bool file = projects.itemFromIndex(index)->data(TIFILE).value<bool>();
    QString type = projects.itemFromIndex(index)->data(TITYPE).toString();
    QString name = projects.itemFromIndex(index)->text();
    gameproject* gp = (gameproject*) projects.itemFromIndex(index)->data(TIPROJECT).value<void*>();

    //1st: check if this is already opened!
    for(int i=0;i<ui->WorkSpaceTabWidget->count();i++)
    {
        QWidget* w = ui->WorkSpaceTabWidget->widget(i);
        if(w->property("editor").value<bool>())
        {
            //it is editor
            resourceeditor* RE = dynamic_cast<resourceeditor*>(w);
            if(RE->treeitem == projects.itemFromIndex(index))
            {
                //activate it
                ui->WorkSpaceTabWidget->setCurrentIndex(i);
                gcEndWait();
                return;
            }
        }
    }

    //open the appropriate editor for given res type
    if(file)
    {
        if(type=="image")
        {
            //load the image editor
            imagewindow* w = new imagewindow;
            w->project = gp;
            w->name = name;
            w->type = type;

            //sometimes managed pointers screw tabs...
            //so I prefer keeping basic QObject data
            w->setProperty("name",name);
            w->setProperty("type",type);

            w->treeitem = projects.itemFromIndex(index);
            int tab = ui->WorkSpaceTabWidget->addTab(w," "+name);
            w->load();
            ui->WorkSpaceTabWidget->setCurrentIndex(tab);
        }
        else if(type=="class")
        {
            //load the class editor
            classwindow* w = new classwindow;
            w->project = gp;
            w->name = name;
            w->type = type;
            //sometimes managed pointers screw tabs...
            //so I prefer keeping basic QObject data
            w->setProperty("name",name);
            w->setProperty("type",type);
            w->treeitem = projects.itemFromIndex(index);
            int tab = ui->WorkSpaceTabWidget->addTab(w," "+name);
            w->load();
            ui->WorkSpaceTabWidget->setCurrentIndex(tab);
        }
        else if(type=="scene")
        {
            //load the class editor
            SceneEditor* w = new SceneEditor;
            w->project = gp;
            w->name = name;
            w->type = type;
            //sometimes managed pointers screw tabs...
            //so I prefer keeping basic QObject data
            w->setProperty("name",name);
            w->setProperty("type",type);
            w->treeitem = projects.itemFromIndex(index);
            int tab = ui->WorkSpaceTabWidget->addTab(w," "+name);
            w->load();
            ui->WorkSpaceTabWidget->setCurrentIndex(tab);
        }

        //ADD other resources UP here ^   ;]
        else
        {
            gcEndWait();
            gcmessage(tr("piGameCreator cannot edit this type of resource."));
            gcBeginWait();
        }
    }
    gcEndWait();
}
void MainWindow::on_action_Save_triggered()
{
    if(ui->treeView->currentIndex()==QModelIndex())return;
    gameproject* cp = (gameproject*) projects.itemFromIndex(projects.treeview->currentIndex())->data(TIPROJECT).value<void*>();
    cp->save();

}

void MainWindow::on_actionSave_as_triggered()
{
    if(ui->treeView->currentIndex()==QModelIndex())return;
    gameproject* cp = (gameproject*) projects.itemFromIndex(projects.treeview->currentIndex())->data(TIPROJECT).value<void*>();
    cp->saveAs();
}

void MainWindow::on_actionCreate_image_triggered()
{
    if(!ui->treeView->currentIndex().isValid())return;
    newimage( (gameproject*) projects.itemFromIndex(ui->treeView->currentIndex())->data(TIPROJECT).value<void*>()  );
}

void MainWindow::on_action_Preferences_triggered()
{
    //open settings
    SettingsWindow s(this);
    s.exec();
}

void MainWindow::on_actionAdd_class_triggered()
{
    if(!ui->treeView->currentIndex().isValid())return;
    newclass( (gameproject*) projects.itemFromIndex(ui->treeView->currentIndex())->data(TIPROJECT).value<void*>()  );
}

void MainWindow::on_actionCreate_2D_scene_triggered()
{
    if(!ui->treeView->currentIndex().isValid())return;
    newscene( (gameproject*) projects.itemFromIndex(ui->treeView->currentIndex())->data(TIPROJECT).value<void*>()  );
}


void MainWindow::on_action_Run_triggered()
{
    if(ui->treeView->currentIndex()==QModelIndex()){gcEndWait();return;}
    gameproject* cp = (gameproject*) projects.itemFromIndex(projects.treeview->currentIndex())->data(TIPROJECT).value<void*>();
    cp->save();
    if(cp->buildTargets.count()>0)
    {
        buildtarget* target=(buildtarget*) targetsCB->itemData(targetsCB->currentIndex()).value<void*>();
        target->exporter->run(cp->file);
    }
    else on_action_Targets_triggered();
}

void MainWindow::on_action_Debug_triggered()
{
    if(ui->treeView->currentIndex()==QModelIndex()){gcEndWait();return;}
    gameproject* cp = (gameproject*) projects.itemFromIndex(projects.treeview->currentIndex())->data(TIPROJECT).value<void*>();
    cp->save();
    if(cp->buildTargets.count()>0)
    {
        buildtarget* target=(buildtarget*) targetsCB->itemData(targetsCB->currentIndex()).value<void*>();
        target->exporter->debug(cp->file);
    }
    else on_action_Targets_triggered();
}

void MainWindow::on_actionBuild_triggered()
{
    if(ui->treeView->currentIndex()==QModelIndex()){gcEndWait();return;}
    gameproject* cp = (gameproject*) projects.itemFromIndex(projects.treeview->currentIndex())->data(TIPROJECT).value<void*>();
    cp->save();
    if(cp->buildTargets.count()>0)
    {
        buildtarget* target=(buildtarget*) targetsCB->itemData(targetsCB->currentIndex()).value<void*>();
        target->exporter->build(cp->file,true);
    }
    else on_action_Targets_triggered();
}

void MainWindow::on_treeView_clicked(const QModelIndex &index)
{
    gameproject* gp = (gameproject*) index.data(TIPROJECT).value<void*>();
    RebuildTargetsCB(gp);
}

void MainWindow::RebuildTargetsCB(gameproject* gp)
{
    targetsCB->blockSignals(true);
    targetsCB->clear();
    if(gp!=0)
    {
        if(gp->buildTargets.count()>0)
        {
            targetsCB->setEnabled(true);
            foreach(buildtarget* T,gp->buildTargets)
                targetsCB->addItem(QIcon(),T->name,qVariantFromValue((void*)T));
            targetsCB->setCurrentIndex(gp->selectedTarget);
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

void MainWindow::on_action_Targets_triggered()
{
    if(ui->treeView->currentIndex()==QModelIndex())return;
    gameproject* cp = (gameproject*) projects.itemFromIndex(projects.treeview->currentIndex())->data(TIPROJECT).value<void*>();
    BuildTargets w(cp);
    w.exec();
}

void MainWindow::BuildTargetChanged(int row)
{
    //gcmessage(QString::number(row));
    if(ui->treeView->currentIndex()==QModelIndex())return;
    gameproject* cp = (gameproject*) projects.itemFromIndex(projects.treeview->currentIndex())->data(TIPROJECT).value<void*>();
    cp->selectedTarget=row;
}

void MainWindow::on_actionSkin_editor_triggered()
{
    SkinTestWindow* w = new SkinTestWindow;
    w->show();
}

void MainWindow::on_actionClass_editor_triggered()
{
    GameFrameworkClassDef w(this);
    w.setWindowFlags(Qt::Window);
    w.exec();
}

void MainWindow::paintEvent(QPaintEvent *e)
{
    mustUpdate=true;
    e->accept();
}

void MainWindow::update()
{
    mustUpdate=false;
    delete LastIdeFrame;
    LastIdeFrame = new QPixmap(width(),height());
    QPainter p(LastIdeFrame);
    rec_drawOverlay=false;
    render(&p);
    rec_drawOverlay=true;
    gcprint("Updating...");
}
