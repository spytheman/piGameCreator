#ifndef SCRIPTTESTWINDOW_H
#define SCRIPTTESTWINDOW_H

#include <QMainWindow>

class scriptwindow;
namespace Ui {
    class scripttestwindow;
}

class scripttestwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit scripttestwindow(QWidget *parent = 0);
    ~scripttestwindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::scripttestwindow *ui;
    scriptwindow* source;

private slots:
    void on_actionSettings_triggered();
    void codeChanged();
    void on_actionExpression_triggered();
    void on_actionCreator_IDE_triggered();
    void on_actionPreprocess_triggered();
    void on_actionParse_triggered();
};

#endif // SCRIPTTESTWINDOW_H
