#include "getimageormodel.h"
#include "ui_getimageormodel.h"
#include "gamecreator.h"
#include "gameproject.h"
#include <QFile>

getImageOrModel::getImageOrModel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getImageOrModel)
{
    gcerror("Error! No project set");
    ui->setupUi(this);
}

getImageOrModel::getImageOrModel(gameproject *gp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getImageOrModel)
{
    setParent(thewindow);
    setWindowFlags(Qt::Window);
    setProject(gp);
    ui->setupUi(this);
    QStringList T; T << "image" << "class";
    QMap<QString,QStringList> l = gp->getResourcesFromTypes(T);
    ui->listWidget->clear();

    gcprint("IMAGES");
    foreach(QString s, l.value("image"))
    {
        QListWidgetItem* li = new QListWidgetItem(s);
        QString ipath = project->absoluteFolder + "/images/" + s + "/icon.png";
        if(!QFile::exists(ipath))ipath="";
        li->setIcon(gcResIcon("image",ipath));
        ui->listWidget->addItem(li);
    }
    gcprint("CLASSES");
    foreach(QString s, l.value("class"))
    {

    }
}

void getImageOrModel::setProject(gameproject* gp)
{
    project = gp;
}

getImageOrModel::~getImageOrModel()
{
    delete ui;
}

void getImageOrModel::changeEvent(QEvent *e)
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

void getImageOrModel::on_pushButton_2_clicked()
{
    selectedName = "";
    selectedIcon = QIcon();
    accept();
}

void getImageOrModel::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    selectedName = item->text();
    selectedIcon = item->icon();
    accept();
}

void getImageOrModel::on_listWidget_itemClicked(QListWidgetItem* item)
{
    selectedName = item->text();
    selectedIcon = item->icon();
}

void getImageOrModel::on_radioButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgNone);
}

void getImageOrModel::on_radioButton_5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgImage);
}

void getImageOrModel::on_radioButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgModel);
}

void getImageOrModel::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgRectangle);
}

void getImageOrModel::on_radioButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgVectorPath);
}

void getImageOrModel::on_radioButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgText);
}
