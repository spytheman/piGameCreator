#ifndef NTDIALOG_H
#define NTDIALOG_H

#include <QDialog>

// Name/Type dialog

namespace Ui {
    class NTdialog;
}

class NTdialog : public QDialog
{
    Q_OBJECT

public:
    QString name,type,value,desc;
    explicit NTdialog(QWidget *parent = 0);
    ~NTdialog();
    int exec();

protected:
    void changeEvent(QEvent *e);

private slots:
    void on_OKbutton_clicked();

private:
    Ui::NTdialog *ui;
};

#endif // NTDIALOG_H
