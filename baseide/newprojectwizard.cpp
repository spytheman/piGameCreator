#include "newprojectwizard.h"
#include "ui_buildtargets.h"
#include "ui_newprojectwizard.h"
#include "buildtargets.h"
#include "openedproject.h"
#include "gcide.h"
#include "../sharedcode/selecticon.h"
#include "../sharedcode/idesettings.h"
#include "../sharedcode/qtwin.h"
#include "../sharedcode/globals.h"
#include <QFileDialog>
#include <QDesktopServices>
#include <QDebug>

newProjectWizard::newProjectWizard(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::newProjectWizard)
{
    ui->setupUi(this);
    ui->browseButton->setProperty("dir","");
    ui->projectdirname->setProperty("edited",false);
    openedProject = NULL;
    gameProject = NULL;
    buildTargetsWidget = NULL;
    connect(this,SIGNAL(currentIdChanged(int)), this, SLOT(newProjectWizard_currentIdChanged(int)));

#ifdef WIN32
    ui->dirSeparatorLabel->setText("\\");
#else
    ui->dirSeparatorLabel->setText("/");
#endif

    //the DIR
    QString newdir = ideSettings::getString(S_CREATORIDE_PROJECTDIR,"");
    if(newdir!="")
    {
        ui->browseButton->setProperty("dir",newdir);
        ui->browseButton->setText(newdir);
    }

    //Load project templates from the folders
    ui->treeWidget->clear();
    QDomDocument* projects = gcReadXml("data/newprojects/newProjects.xml");
    QDomElement projectroot = projects->documentElement();
    QDomElement group = projectroot.firstChild().toElement();
    while(!group.isNull())
    {
        QTreeWidgetItem* groupTreeItem = new QTreeWidgetItem;
        groupTreeItem->setText(0, group.attribute("name"));
        QIcon icon = QIcon(group.attribute("icon"));
        if(icon.isNull())icon=ffficon("page_white");
        groupTreeItem->setIcon(0, icon);
        QFont f; f.setBold(true);
        groupTreeItem->setFont(0, f);
        groupTreeItem->setData(0, TIDATA, NULL);
        //Parse the projects:
        QString src = group.attribute("src");
        if(!src.startsWith("@"))
        {
            //real dir:
            QDir groupSourceQDir(src);
            //get all subdirs:
            QStringList projectDirs = groupSourceQDir.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
            foreach(QString possibleProjectDir, projectDirs)
            {
                //A dir. Does it contain a .gcpx file?
                QDir gcpxCheckQDir(src + "/" + possibleProjectDir);
                QStringList gcpxFiles = gcpxCheckQDir.entryList(QStringList()<<"*.gcpx");
                qDebug() << gcpxFiles;
                foreach(QString gcpxFile, gcpxFiles)
                {
                    // A gcpx file found into the folder.
                    gameprojectinformation* pi = gameproject::getProjectInformation(src+"/"+possibleProjectDir+"/"+gcpxFile);
                    if(pi)
                    {
                        // valid project - add it
                        QTreeWidgetItem* projectItem = new QTreeWidgetItem;
                        mmGPInfos.append(pi);
                        projectItem->setText(0, pi->title);
                        projectItem->setWhatsThis(0, pi->description);
                        projectItem->setIcon(0, pi->icon);
                        projectItem->setData(0,TIDATA, qVariantFromValue( (void*)pi ));
                        groupTreeItem->addChild(projectItem);
                    }
                    else gcprint("Invalid project!");
                }
            }
        }
        ui->treeWidget->addTopLevelItem(groupTreeItem);
        group=group.nextSibling().toElement();
    }

    //The title AND icon?
    setWindowTitle("Create or open a project");
    setWindowIcon( ffficon("page_white") );

    //Damn AeroStyle workaround
    QApplication::processEvents();
    resize( size().width(), size().height()-1 );
}

newProjectWizard::~newProjectWizard()
{
    qDeleteAll(mmGPInfos);
    delete ui;
}

bool newProjectWizard::validateCurrentPage()
{
    if(currentPage() == ui->wpProjectTemplate)
    {
        //Only the FOLDER is required!
        if( ! (ui->browseButton->property("dir").toString()!="" && ui->projectdirname->text()!="") )
        {
            gcmessage("Please select the folder to save the project");
            return false;
        }
        else
        {
            // Valid data may only mean some initialization
            // LOAD the template project!
            QTreeWidgetItem* item = ui->treeWidget->currentItem();
            if(!item)
            {
                gcerror("Please select a project type to create.");
                return false;
            }
            gameprojectinformation* gpi = (gameprojectinformation*) item->data(0,TIDATA).value<void*>();
            if(!gpi)
            {
                gcerror("Please select a project type to create. Not a folder.");
                return false;
            }
            QString fn = gpi->filename;
            gameproject* gp = new gameproject(fn);
            gp->load();
            gameProject = gp;
            openedProject = new OpenedProject;   //This will be set AFTER the user advances and completes the wizard ;]
            openedProject->project = gp;

            // We must patch this project a bit:

            gp->description = ui->projectDescTextEdit->toPlainText();
            gp->title = ui->projectTitleLineEdit->text();
            //the ICON is specified as icon.png into the project folder. We should place it there.
            return true;
        }
    }
    else if(currentPage() == ui->wpProjectTargets)
    {

        //DO NOT set the filename! CALL SAVE with this!
        QString newfn =
                QFileInfo( ui->browseButton->property("dir").toString() + ui->dirSeparatorLabel->text() + ui->projectdirname->text() )
                .absoluteFilePath() + "/" + ui->projectdirname->text() + ".gcpx";
        buildTargetsWidget->on_OKbutton_clicked();
        bool b = buildTargetsWidget->result();  //either 1 or 0
        if(b)
        {
            gameProject->save(newfn);
            creatorIDE->openProject(gameProject->filename());
            delete gameProject;
        }
        return b;
    }
}

void newProjectWizard::initializePage(int id)
{
    if(id==1)
    {
        delete buildTargetsWidget;  //Deleting NULL is allowed!
        buildTargetsWidget = new BuildTargets(openedProject, this);
        buildTargetsWidget->setWizardMode();
        QLayoutItem* item;
        ui->wpProjectTargets->layout()->setContentsMargins(0,0,0,0);
        while ( ( item = ui->wpProjectTargets->layout()->takeAt(0) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        ui->wpProjectTargets->layout()->addWidget(buildTargetsWidget->ui->InnerWidget);
    }
}

void newProjectWizard::on_treeWidget_currentItemChanged(QTreeWidgetItem *current, QTreeWidgetItem *previous)
{
    ui->projectType->setText(current->text(0));
    ui->projectDescription->setText(current->whatsThis(0));
}


void newProjectWizard::on_browseButton_clicked()
{
    QString newdir =
    QFileDialog::getExistingDirectory(this,"Select project folder",
                                      QDesktopServices::storageLocation(
                                          QDesktopServices::DocumentsLocation
                                          ), QFileDialog::ShowDirsOnly );
    if(newdir!="") ui->browseButton->setText(newdir);
    else ui->browseButton->setText("Browse");
    ui->browseButton->setProperty("dir",newdir);
    ideSettings::setString(S_CREATORIDE_PROJECTDIR, newdir);

}

void newProjectWizard::on_projectTitleLineEdit_textChanged(const QString &text)
{
    QRegExp r("[^a-zA-Z0-9_]+");
    QString s = text.toLower();
    s.replace(r,"-");
    if(ui->projectdirname->property("edited").toBool()==false)
    {
        ui->projectdirname->blockSignals(true);
        ui->projectdirname->setText(s);
        ui->projectdirname->blockSignals(false);
    }
}

void newProjectWizard::on_projectdirname_textChanged(const QString &text)
{
    ui->projectdirname->setProperty("edited",true);
    if(text.isEmpty())
    ui->projectdirname->setProperty("edited",false);
}

void newProjectWizard::newProjectWizard_currentIdChanged(int id)
{

}

void newProjectWizard::on_toolButton_clicked()
{
    selectIcon w(this);
    w.setWindowTitle("Select icon for this project");
    w.setSelectedIcon(ui->toolButton->icon());
    w.exec();
    if(!w.selectedIcon.isNull())
    ui->toolButton->setIcon(w.selectedIcon);
}
