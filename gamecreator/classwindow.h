#ifndef CLASSWINDOW_H
#define CLASSWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QListWidgetItem>
#include "srcClass/variable.h"
#include "srcClass/classwindoweventfilters.h"
#include "resourceeditor.h"
#include "scriptwindow.h"

namespace Ui {
    class classwindow;
}
class classpreview;
class classwindow : public QMainWindow, public resourceeditor
{
    friend class dropEventHandler;
    Q_OBJECT

public:
    explicit classwindow(QWidget *parent = 0);
    ~classwindow();
    QList<variable> vars, properties;

    void save();
    void load();


protected:
    void changeEvent(QEvent *e);

private:
    dropEventHandler varsDrop, propsDrop;
    Ui::classwindow *ui;
    scriptwindow* source;
    classpreview* preview;
    variable makeVariable(vObject o,bool property);
    vObject makeVObject(variable v);
    void makeTreeItem(QTreeWidgetItem* w, variable v);
    void keyPressEvent(QKeyEvent *);
    void checkVars();
    QListWidgetItem* CurrentActiveItem;
    void updateCurrentActiveItem(); //for source code syncing;

private slots:
    void on_baseClassButton_clicked();
    void on_FunctionsListWidget_itemClicked(QListWidgetItem* item);
    void on_EventsListWidget_itemClicked(QListWidgetItem* item);
    void on_PropList_itemSelectionChanged();
    void on_PropList_itemDoubleClicked(QTreeWidgetItem* item, int column);
    void on_DelProperties_clicked();
    void on_DelVars_clicked();
    void on_VarsList_itemSelectionChanged();
    void on_VarsList_itemDoubleClicked(QTreeWidgetItem* item, int column);
    void on_addProperty_clicked();
    void on_addVariable_clicked();
    void on_addFunction_clicked();
    void on_addEvent_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void timeout();
    void modify();
    void on_EventsListWidget_customContextMenuRequested(const QPoint &pos);
    void on_FunctionsListWidget_customContextMenuRequested(const QPoint &pos);
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



#endif // CLASSWINDOW_H
