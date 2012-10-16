#include "newresource.h"
#include "ui_newresource.h"
#include "gcide.h"
#include "openedproject.h"
#include "dllforresourceeditor.h"
#include "../sharedcode/gameproject.h"
#include <QCommandLinkButton>
#include <QMessageBox>

newResource::newResource(QWidget *parent) :
    QWizard(parent),
    ui(new Ui::newResource)
{
    isContentProvider = false;
    resource = NULL;
    selectedProject = NULL;
    selectedResourceEditor = NULL;

    ui->setupUi(this);

    selectedProject = creatorIDE->currentProject;

    //Empty the error message:
    ui->errorMessage->setText("");
}

newResource::~newResource()
{
    delete ui;
}

void newResource::setKind(QString kind)
{
    setWindowTitle("New "+kind+" wizard");
    QString newstr = "New "+kind;
    QString caped = kind;
    selectedKind = kind;
    caped[0] = caped[0].toUpper();
    ui->wpResourceSource->setTitle(newstr);
    ui->wpResourceSource->setSubTitle("Choose what type of "+kind+" to create");
    ui->twResourceSource->setTabText(0,newstr);
    ui->enterName->setText("Enter the name for this "+kind+":");
    ui->resName->setText(caped + " name:");

    //Now, for each kind, query for the Resource Editors
    cmlButtons.clear();
    foreach(dllForResourceEditor* re, creatorIDE->resourceEditorLibs)
    {
        QList<vObject> list = re->newResources();
        foreach(vObject o,list)
            if(o.value("kind")==kind)
            {
                QCommandLinkButton* button = new QCommandLinkButton(o.value("title").toString(),o.value("description").toString());
                button->setIcon(o.value("icon").value<QIcon>());

                //add plugin instance pointer
                o["pluginlibpointer"]=qVariantFromValue( (void*)re );

                button->setProperty("data",o);
                button->setCheckable(true);
                connect(button,SIGNAL(clicked()),this,SLOT(setUsedEditor()));
                ui->noEditorExistsLabel->hide();
                ui->newResourceLayout->insertWidget(0, button);
                cmlButtons.append(button);
            }
    }
    QRegExpValidator* varNameValidator = new QRegExpValidator;
    varNameValidator->setRegExp(QRegExp("[a-zA-Z_][a-zA-Z0-9_]{3,}"));
    ui->resourceNameLineEdit->setValidator(varNameValidator);
}

void newResource::setUsedEditor()
{
    QCommandLinkButton* cb = qobject_cast<QCommandLinkButton*>(sender());


    foreach(QCommandLinkButton* cb, cmlButtons)
        cb->setChecked(false);
    cb->setChecked(true);

    //set as qDialog's property
    vObject o = cb->property("data").toHash();
    bool wasItClicked = (selectedType==o.value("type").toString());
    selectedResourceEditor = (dllForResourceEditor*) o.value("pluginlibpointer").value<void*>();
    selectedType = o.value("type").toString();
    selectedKind = o.value("kind").toString();
    selectedOption = cb->text();
    selectedOptionDesc = cb->description();
    if(wasItClicked)this->next();
}

bool newResource::validateCurrentPage()
{
    if(currentPage() == ui->wpResourceSource)
    {
        //something must be selected
        if(selectedResourceEditor==NULL)
        {
            gcerror(ffficon("cancel"), "Select type of "+selectedKind, "Please, select what type of "+selectedKind+" you want to create!");
            return false;
        }
        else return true;
    }
    else if(currentPage() == ui->wpResourceName)
    {
        if(ui->resourceNameLineEdit->hasAcceptableInput())
        {
            QString name = ui->resourceNameLineEdit->text();
            QStringList allnames = selectedProject->project->getAllResourceNames();
            if(allnames.contains(name))
            {
                ui->errorMessage->setText("Resource with same name already exists in this project!");
                return false;
            }
            //here: Create the actual resource
            resource = selectedResourceEditor->createResource(creatorIDE->currentProject->project, selectedKind, selectedType, name);
            if(resource) return true;
            else gcerror("The resource editor FAILED to create this resource for some reason");
        }
        else
        {
            ui->errorMessage->setText("The resource name is invalid!");
            return false;
        }
    }
    return false;
}

void newResource::initializePage(int id)
{
    if(id == 1)
    {
        ui->wpResourceName->setTitle(selectedOption);
        ui->wpResourceName->setSubTitle(selectedOptionDesc);
    }
}
