#include "ntdialog.h"
#include "ui_ntdialog.h"
#include <QShowEvent>

NTdialog::NTdialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NTdialog)
{
    ui->setupUi(this);
}

NTdialog::~NTdialog()
{
    delete ui;
}

void NTdialog::changeEvent(QEvent *e)
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

void NTdialog::on_OKbutton_clicked()
{
    name=ui->lineEdit->text();
    type=ui->TypeComboBox->currentText();
    value=ui->valueEdit->text();
    desc=ui->descEdit->toPlainText();
    accept();
}

int NTdialog::exec()
{
    ui->lineEdit->setText(name);
    ui->TypeComboBox->setEditText(type);
    ui->valueEdit->setText(value);
    ui->descEdit->setPlainText(desc);
    return QDialog::exec();
}
