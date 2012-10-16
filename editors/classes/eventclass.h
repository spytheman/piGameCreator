#ifndef EVENTCLASS_H
#define EVENTCLASS_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include "variable.h"
#include "classwindoweventfilters.h"
#include "../../baseide/codeeditor.h"
#include "../../baseide/resourceeditor.h"


namespace Ui {
    class eventClass;
}
class classpreview;

class eventClass : public QMainWindow, public ResourceEditor
{
    friend class dropEventHandler;
    Q_OBJECT

public:
    explicit eventClass(QWidget *parent = 0);
    ~eventClass();
    QList<variable> vars, properties;

    bool save();
    bool load();
    bool init();

    void checkVars();
protected:
    void changeEvent(QEvent *e);

private:
    Ui::eventClass *ui;

private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
};

class classpreview: public QWidget
{
    Q_OBJECT
public:
    explicit classpreview(QWidget* parent = 0);
    ~classpreview();
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);
    classwindow* window;
    QPixmap icon;
    QString resname;
};



#endif // EVENTCLASS_H
