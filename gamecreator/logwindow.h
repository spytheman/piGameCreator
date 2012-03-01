#ifndef LOGWINDOW_H
#define LOGWINDOW_H

#include <QMainWindow>

namespace Ui {
    class logwindow;
}

class logwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit logwindow(QWidget *parent = 0);
    ~logwindow();
    void print(QString what);
    void closeEvent(QCloseEvent *);

private:
    Ui::logwindow *ui;

private slots:
    void on_actionSave_triggered();
    void on_actionEntire_log_triggered();
    void on_actionActionClear_triggered();
};

#endif // LOGWINDOW_H
