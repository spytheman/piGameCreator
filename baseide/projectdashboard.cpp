#include "gcide.h"
#include "openedproject.h"
#include "../sharedcode/gameproject.h"
#include "../sharedcode/imageio.h"
#include "../sharedcode/selecticon.h"
#include "projectdashboard.h"
#include "ui_projectdashboard.h"
#include "mainwindow.h"
#include <QColorDialog>
#include <QMenu>
#include <QWidgetAction>

ProjectDashboard::ProjectDashboard(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ProjectDashboard)
{
    widget = this;
    setBackgroundRole(QPalette::Window);
    setProperty("dashboard", true);
    ui->setupUi(this);

    ui->menuBar->hide();

    ui->DashboardSW->setCurrentIndex(0);
    setAttribute(Qt::WA_DeleteOnClose,true);
    timer.setSingleShot(true);
    timer.setInterval(1000);
    refresher.setInterval(1);
    refresher.setSingleShot(true);
    connect(&timer, SIGNAL(timeout()),this,SLOT(saveProjectAndUpdateExplorer()));
    connect(&refresher, SIGNAL(timeout()), this, SLOT(refreshModules()));

    //hide unimplemented stuff:
    ui->pbCalendar->hide();

    //force default page:
    ui->BottomPartSW->setCurrentWidget(ui->bpNone);

    QMenu* m = new QMenu;
    QWidgetAction* a = new QWidgetAction(this);
    a->setDefaultWidget(ui->wallpaperWidgetFrame);
    m->addAction(a);
    ui->wallpaperOptions->setMenu(m);


}

ProjectDashboard::~ProjectDashboard()
{
    delete ui;
}

void ProjectDashboard::setProject(OpenedProject *project)
{
    this->project = project;
}

void ProjectDashboard::updateWallpaper()
{
    QString wall = project->project->absoluteFolder()+"/wallpaper.jpg";
    QString color = project->project->dbcolor;
    QColor c; c.setNamedColor(color);
    if(!c.isValid())color="#000";
    QString qss = "#DashboardSW{background: url('"+wall+"') center center;}"
            "#projectTitleLabel,#projectDescLabel{color:"+color+"}"  ;
    setStyleSheet(qss);
}

void ProjectDashboard::init()
{
    updateWallpaper();
    refreshModules();

    setTitle(project->project->title);
    // project's icon.png and wallpaper.jpg must be into the project's folder;
    QString ic;
    ic=project->project->absoluteFolder()+"/icon.png";
    QIcon icon;
    if(QFile::exists(ic))icon=QIcon(ic);
    else icon=ffficon("page_white");
    ui->projectIcon->setIcon(icon);
    ui->prolectIconLabel->setPixmap(icon.pixmap(16,16));

    ui->projectAppVersion->setText(project->project->version);
    ui->projectAuthor->setText(project->project->author);
    ui->projectDescription->setPlainText(project->project->description);
    ui->projectTitle->setText(project->project->title);
}

void ProjectDashboard::on_projectDescription_textChanged()
{
    QString desc = ui->projectDescription->toPlainText();
    ui->projectDescLabel->setText(desc);
    project->project->description = desc;
    timer.start();
}

void ProjectDashboard::on_projectTitle_textChanged(const QString &arg1)
{
    emit titleChanged(arg1);
    QString title = arg1; if(title.isEmpty())title="Untitled project";
    setTitle(title);
    ui->projectTitleLabel->setText(arg1);
    project->project->title = arg1;
    timer.start();
}

void ProjectDashboard::clearBottomStates()
{
    ui->pbBasicInfo->blockSignals(true);
    ui->pbBasicInfo->setChecked(false);
    ui->pbBasicInfo->blockSignals(false);
    ui->pbModules->blockSignals(true);
    ui->pbModules->setChecked(false);
    ui->pbModules->blockSignals(false);
    ui->pbCalendar->blockSignals(true);
    ui->pbCalendar->setChecked(false);
    ui->pbCalendar->blockSignals(false);
}

void ProjectDashboard::saveProjectAndUpdateExplorer()
{
    project->project->save();
    creatorIDE->mainWindow->updateProjectExplorer();
}

void ProjectDashboard::on_projectAuthor_textChanged(const QString &arg1)
{
    project->project->author = arg1;
    timer.start();
}

void ProjectDashboard::on_projectAppVersion_textChanged(const QString &arg1)
{
    project->project->version = arg1;
    timer.start();
}

void ProjectDashboard::on_buildTargetsBtn_clicked()
{
    project->project->save();
    creatorIDE->currentProject = project;
    creatorIDE->mainWindow->updateProjectExplorer();
    creatorIDE->mainWindow->on_action_Targets_triggered();
}

void ProjectDashboard::on_pbBasicInfo_clicked()
{
    if(!ui->pbBasicInfo->isChecked())
    {
        clearBottomStates();
        ui->BottomPartSW->setCurrentWidget(ui->bpNone);
    }
    else
    {
        clearBottomStates();
        ui->pbBasicInfo->setChecked(true);
        ui->BottomPartSW->setCurrentWidget(ui->bpBasicInfo);
    }
}

void ProjectDashboard::on_pbModules_clicked()
{
    if(!ui->pbModules->isChecked())
    {
        clearBottomStates();
        ui->BottomPartSW->setCurrentWidget(ui->bpNone);
    }
    else
    {
        clearBottomStates();
        ui->pbModules->setChecked(true);
        ui->BottomPartSW->setCurrentWidget(ui->bpModules);
    }
}

void ProjectDashboard::on_toolButton_clicked()
{
    clearBottomStates();
    ui->pbBasicInfo->setChecked(true);
    ui->BottomPartSW->setCurrentWidget(ui->bpBasicInfo);
    ui->projectTitle->setFocus();
}

void ProjectDashboard::on_toolButton_2_clicked()
{
    clearBottomStates();
    ui->pbBasicInfo->setChecked(true);
    ui->BottomPartSW->setCurrentWidget(ui->bpBasicInfo);
    ui->projectDescription->setFocus();
}

void ProjectDashboard::on_toolButton_8_clicked()
{
    //Delete the wallpaper.jpg:
    QFile f(project->project->absoluteFolder() + "/wallpaper.jpg");
    f.remove();
    updateWallpaper();
}

void ProjectDashboard::on_toolButton_10_clicked()
{
    QPixmap p;
    QString fn = imageio::getOpenFilename("", true);
    if(!fn.isEmpty())
    p = imageio::loadImage(fn);
    QString walljpg = project->project->absoluteFolder()+"/wallpaper.jpg";
    if(!p.isNull())p.save(walljpg);
    updateWallpaper();
}

void ProjectDashboard::on_toolButton_11_clicked()
{
    project->project->dbcolor = QColor::fromRgb(0,0,0).name();
    updateWallpaper();
}

void ProjectDashboard::on_toolButton_9_clicked()
{
    QColorDialog col;
    col.setParent(this);
    col.setWindowFlags(Qt::Window | Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint);
    col.setWindowTitle("Select color for the text");  //1440 x 900!

    QColor c;
    c.setNamedColor(project->project->dbcolor);
    col.setCurrentColor(c);
    if(col.exec())
    {
        project->project->dbcolor = col.currentColor().name();
        updateWallpaper();
    }
}

void ProjectDashboard::on_projectIcon_clicked()
{

    selectIcon w(this);
    w.setWindowTitle("Select icon for this project");
    w.setSelectedIcon(project->project->icon);
    w.exec();
    if(!w.selectedIcon.isNull())
    {
        project->project->icon = w.selectedIcon;
        ui->projectIcon->setIcon(w.selectedIcon);
        ui->prolectIconLabel->setPixmap(w.selectedIcon.pixmap(16,16));
        ui->prolectIconLabel->pixmap()->save(project->project->absoluteFolder()+"/icon.png");
    }
}

void ProjectDashboard::refreshModules()
{
    //update the widgets
    QWidgetList l;
    QWidget* w;
    for( int i=0; i < ui->modulesLayout->count(); i++ )
    {
        QLayoutItem* li = ui->modulesLayout->itemAt(i);
        if(!li->isEmpty())
        {
            w = li->widget();
            if(w->property("module").toBool()==true)
                l<<w;
        }
    }
    qDeleteAll(l);

    //Add:
    for(int i= project->project->modules.count()-1; i>=0; i--)
    {
        QString s = project->project->modules.at(i);
        QToolButton* tb = new QToolButton;
        tb->setPopupMode(QToolButton::InstantPopup);
        tb->setText(s);
        tb->setProperty("module",true);
        tb->setMenu(ui->menuModule);
        tb->setIcon(ffficon("application_xp"));
        tb->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tb->installEventFilter(this);
        connect(tb, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(moduleButtonPressed()));
        QBoxLayout* bl = ui->modulesLayout;
        bl->insertWidget(0,tb);
    }
}

bool ProjectDashboard::eventFilter(QObject *o, QEvent *e)
{
    if(e->type()==QEvent::MouseButtonPress)
    {
        QToolButton* tb = (QToolButton*)o;
        moduleButtonClicked = tb->text();
    }
    return false;
}

void ProjectDashboard::moduleButtonPressed()
{
    QToolButton* t = (QToolButton*) sender();
    gcmessage(t->text());
}

void ProjectDashboard::on_addModule_clicked()
{
    addModuleResult = -1;
    ui->addModuleWindow->setWindowFlags(Qt::Dialog);
    ui->addModuleWindow->setWindowTitle("Add main module");
    ui->addModuleWindow->setWindowIcon(ffficon("application_add"));
    QWidget* w = ui->addModuleWindow;
    ui->availableClassesWidget->clear();
    QList<gcresource*> classes = project->project->getResourcesFromKind("class");
    foreach(gcresource* r, classes)
    {
        QListWidgetItem* item = new QListWidgetItem;
        item->setCheckState(   project->project->modules.contains(r->name)?Qt::Checked:Qt::Unchecked   );
        item->setText(r->name);
        ui->availableClassesWidget->addItem(item);
    }
    w->setWindowModality(Qt::ApplicationModal);
    w->show();
    while(addModuleResult==-1)QApplication::processEvents();
    w->hide();
    //now update the checked things
    project->project->modules.clear();

    for(int i=0;i<ui->availableClassesWidget->count();++i)
        if(ui->availableClassesWidget->item(i)->checkState()==Qt::Checked)
            project->project->modules.append( ui->availableClassesWidget->item(i)->text() );

    refreshModules();
}

void ProjectDashboard::on_actionEdit_this_module_triggered()
{
    //TODO: call this on the MainWindow
    gcresource* res = project->project->getResourceByName(moduleButtonClicked);
    if(res)
    {
        creatorIDE->openResource(res);
    }
}

void ProjectDashboard::on_actionRemove_as_Main_Module_triggered()
{
    project->project->modules.removeAll(moduleButtonClicked);
    refresher.start();
}

void ProjectDashboard::on_addModuleButtonBox_accepted()
{
    addModuleResult = 1;
}

void ProjectDashboard::on_addModuleButtonBox_rejected()
{
    addModuleResult = 0;
}
