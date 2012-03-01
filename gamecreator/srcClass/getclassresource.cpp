#include "getclassresource.h"
#include "ui_getclassresource.h"
#include "gamecreator.h"
#include <QFile>

getClassResource::getClassResource(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getClassResource)
{
    ui->setupUi(this);
}

getClassResource::getClassResource(gameproject *gp, QWidget *p):
    QDialog(p),
    ui(new Ui::getClassResource)
{
    setParent(thewindow);
    setWindowFlags(Qt::Window);
    project=gp;
    ui->setupUi(this);

    QStringList l = gp->getResourcesFromType("class");
    ui->listWidget->clear();

    foreach(QString s, l)
    {
        QListWidgetItem* li = new QListWidgetItem(s);
        QString ipath = project->absoluteFolder + "/Classes/" + s + "/icon.png";
        if(!QFile::exists(ipath))ipath="";
        li->setIcon(gcResIcon("class",ipath));
        ui->listWidget->addItem(li);
    }
}

getClassResource::~getClassResource()
{
    delete ui;
}

void getClassResource::changeEvent(QEvent *e)
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

void getClassResource::on_OKbutton_clicked()
{
    resname = ui->listWidget->currentItem()->text();
    accept();
}

void getClassResource::on_CancelButton_clicked()
{
    reject();
}

void getClassResource::on_ClearButton_clicked()
{
    resname="";
    accept();
}

void getClassResource::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    on_OKbutton_clicked();
}

void getClassResource::on_Filter_textChanged(QString s)
{
    if(s=="")
    {
        for(int i=0;i<ui->listWidget->count();i++)
            ui->listWidget->item(i)->setHidden(false);
    }
    else for(int i=0;i<ui->listWidget->count();i++)
    {
        if(!ui->listWidget->item(i)->text().contains(s))
            ui->listWidget->item(i)->setHidden(true);
        else ui->listWidget->item(i)->setHidden(false);
    }
}
