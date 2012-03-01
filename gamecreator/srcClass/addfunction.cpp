#include "addfunction.h"
#include "ui_addfunction.h"
#include "pgsparser.h"
#include "srcClass/getclassresource.h"

AddFunction::AddFunction(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddFunction)
{
    ui->setupUi(this);
    ui->selectClass->hide();
    argumentmode=false;
}

AddFunction::~AddFunction()
{
    delete ui;
}

void AddFunction::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void AddFunction::argumentMode()
{
    ui->fnL->setText(tr("Argument name:"));
    ui->returnL->setText(tr("Argument type"));
    ui->advancedButton->hide();
    ui->argumentsAddRemove->hide();
    ui->ArgumentList->hide();
    setWindowTitle(tr("Add argument..."));
    adjustSize();
    ui->varType->removeItem(5);
    argumentmode=true;
    ui->varType->setCurrentIndex(0);
}


void AddFunction::on_AddButton_clicked()
{
    AddFunction w(this);
    w.argumentMode();
    w.project = project;
    if(w.exec()==QDialog::Accepted)
    {
        QStringList L;
        for(int i=0;i<ui->ArgumentList->topLevelItemCount();i++)
        {
            L << ui->ArgumentList->topLevelItem(i)->text(0);
        }
        QString name = fixName(L,w.name);
        QTreeWidgetItem* l = new QTreeWidgetItem();
        l->setText(0,name);
        l->setText(1,w.type);
        ui->ArgumentList->addTopLevelItem(l);
    }
}

void AddFunction::on_varType_currentIndexChanged(int index)
{
    if(index==4)ui->selectClass->show();
    else ui->selectClass->hide();
}


void AddFunction::on_okbutton_clicked()
{
    pgsParser p;
    if(!argumentmode)p.setProject(project); //else we don't need a project
    tokenList l = p.tokenize(ui->lineEdit->text());
    bool valid=false;
    //to do: validation!
    //for now, only the name to be valid
    if(l.count()==1)
        if(l.at(0).kind==pgsParser::nameId)valid=true;

    if(!valid)
    {
        gcerror(tr("The function name is invalid or conflicts with something"));
        return;
    }

    //it's ok now
    name = l.at(0).text;
    switch(ui->varType->currentIndex())
    {
        case 0: type="int";break;
        case 1: type="real";break;
        case 2: type="string";break;
        case 3: type="bool";break;
        case 4: type=theclass;break;
        case 5: type="void";break;
    }

    //store the arguments as well:
    if(!argumentmode)
    {
        vObject o;
        for(int i=0;i<ui->ArgumentList->topLevelItemCount();i++)
        {
            o[ui->ArgumentList->topLevelItem(i)->text(0)] = ui->ArgumentList->topLevelItem(i)->text(1);
        }
        args = o;
    }
    accept();
}

void AddFunction::on_selectClass_clicked()
{
    getClassResource w(project,this);
    if(w.exec()==QDialog::Accepted)
    {
        ui->selectClass->setText(w.resname);
        theclass = w.resname;
    }
}

void AddFunction::on_removeButton_clicked()
{
    QList<QTreeWidgetItem*> l = ui->ArgumentList->selectedItems();
    foreach(QTreeWidgetItem* i,l)delete i;
}
