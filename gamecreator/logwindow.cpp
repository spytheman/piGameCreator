#include "logwindow.h"
#include "ui_logwindow.h"
#include "gamecreator.h"
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
logwindow::logwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::logwindow)
{
    ui->setupUi(this);
}

void logwindow::closeEvent(QCloseEvent* e)
{
    gclog=0;
    delete this;
}

logwindow::~logwindow()
{
    delete ui;
}

void logwindow::on_actionActionClear_triggered()
{
    ui->plainTextEdit->clear();
}

void logwindow::print(QString what)
{
    ui->plainTextEdit->appendPlainText(what);
}

void logwindow::on_actionEntire_log_triggered()
{
    ui->plainTextEdit->setPlainText(Applog);
}

void logwindow::on_actionSave_triggered()
{
    QString filename = QFileDialog::getSaveFileName(0,"Save log as...",".","Log files (*.log);;Text files (*.txt);;All files (*)",0,0);
    std::ofstream f(filename.toLocal8Bit().data());
    f<<ui->plainTextEdit->toPlainText().toLocal8Bit().data();
    f.close();
}
