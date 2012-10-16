#include "getrepresentation.h"
#include "ui_getrepresentation.h"
#include "../../sharedcode/globals.h"
#include "../../sharedcode/gameproject.h"
#include <QFile>

getRepresentation::getRepresentation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getRepresentation)
{
    gcerror("Error! No project set");
    ui->setupUi(this);
}

getRepresentation::getRepresentation(gameproject *gp, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::getRepresentation)
{
    setWindowFlags(Qt::Window);
}

void getRepresentation::setProject(gameproject* gp)
{
    project = gp;
}

getRepresentation::~getRepresentation()
{
    delete ui;
}

void getRepresentation::changeEvent(QEvent *e)
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

void getRepresentation::on_pushButton_2_clicked()
{
    selectedName = "";
    selectedIcon = QIcon();
    accept();
}

void getRepresentation::on_listWidget_itemDoubleClicked(QListWidgetItem* item)
{
    selectedName = item->text();
    selectedIcon = item->icon();
    accept();
}

void getRepresentation::on_listWidget_itemClicked(QListWidgetItem* item)
{
    selectedName = item->text();
    selectedIcon = item->icon();
}

void getRepresentation::on_radioButton_4_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgNone);
}

void getRepresentation::on_radioButton_5_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgImage);
}

void getRepresentation::on_radioButton_6_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgModel);
}

void getRepresentation::on_radioButton_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgRectangle);
}

void getRepresentation::on_radioButton_2_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgVectorPath);
}

void getRepresentation::on_radioButton_3_clicked()
{
    ui->stackedWidget->setCurrentWidget(ui->pgText);
}
