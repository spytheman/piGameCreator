#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QWidget>

namespace Ui {
    class progressdialog;
}

class progressdialog : public QWidget
{
    Q_OBJECT

public:
    explicit progressdialog(QWidget *parent = 0);
    ~progressdialog();
    void setText(QString);
    void setMax(int);   //-1 for undetermined / infinity
    void setValue(int);
    void setCancel(bool);
    void closeEvent(QCloseEvent *);

protected:
    void changeEvent(QEvent *e);

private:
    Ui::progressdialog *ui;
};

#endif // PROGRESSDIALOG_H
