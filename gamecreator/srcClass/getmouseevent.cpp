#include "getmouseevent.h"
#include "ui_getmouseevent.h"

GetMouseEvent::GetMouseEvent(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GetMouseEvent)
{
    ui->setupUi(this);
}

GetMouseEvent::~GetMouseEvent()
{
    delete ui;
}

void GetMouseEvent::changeEvent(QEvent *e)
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

void GetMouseEvent::on_EventType_currentIndexChanged(int index)
{
    if(index>=5)
    {
        ui->BtnLabel->setEnabled(0);
        ui->ButtonMenu->setEnabled(0);
    }
    else
    {
        ui->BtnLabel->setEnabled(1);
        ui->ButtonMenu->setEnabled(1);
    }
}

void GetMouseEvent::on_buttonBox_accepted()
{
    etype = ui->EventType->currentIndex();
    button=ui->ButtonMenu->currentIndex();
}
