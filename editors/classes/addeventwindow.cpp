#include "addeventwindow.h"
#include "ui_addeventwindow.h"
#include "../../sharedcode/globals.h"

AddEventWindow::AddEventWindow(QWidget *parent):
    QDialog(parent),
    ui(new Ui::AddEventWindow)
{
    ui->setupUi(this);
    //init here
    OKclicked=false;
    ui->treeWidget->setCurrentItem(ui->treeWidget->topLevelItem(0));
}

AddEventWindow::~AddEventWindow()
{
    delete ui;
}

void AddEventWindow::changeEvent(QEvent *e)
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

void AddEventWindow::on_buttonBox_accepted()
{
    if(ui->treeWidget->currentIndex().isValid())
    {
        selectedEvent = ui->treeWidget->currentItem();
        OKclicked=true;
        accept();
    }
    else gcmessage(tr("Please select event!"));
}

void AddEventWindow::on_buttonBox_rejected()
{
    reject();
}

void AddEventWindow::on_treeWidget_itemDoubleClicked(QTreeWidgetItem* item, int column)
{
    on_buttonBox_accepted();
}
