#include "progressdialog.h"
#include "ui_progressdialog.h"
#include <QCloseEvent>

progressdialog::progressdialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::progressdialog)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

progressdialog::~progressdialog()
{
    delete ui;
}

void progressdialog::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
void progressdialog::closeEvent(QCloseEvent * e)
{
    if(ui->pushButton->isEnabled()==false)e->ignore();
    else e->accept();
}
void progressdialog::setText(QString s)
{
    ui->label->setText(s);
}
void progressdialog::setHeader(QString s)
{
    ui->labelHeader->setText(s);
}
void progressdialog::setCancel(bool b)
{
    ui->pushButton->setEnabled(b);
}
void progressdialog::setMax(int m)
{
    if(m!=-1)
    {
        ui->progressBar->setMaximum(m);
    }
    else
    {
        ui->progressBar->setMaximum(0);
        ui->progressBar->setMinimum(0);
        ui->progressBar->setValue(-1);
    }
}
void progressdialog::setValue(int m)
{
    if(m!=-1)
    {
        ui->progressBar->setValue(m);
    }
    else
    {
        ui->progressBar->setMaximum(0);
        ui->progressBar->setMinimum(0);
        ui->progressBar->setValue(-1);
    }
}
