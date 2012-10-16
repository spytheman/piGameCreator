#ifndef GETIMAGEORMODEL_H
#define GETIMAGEORMODEL_H

#include <QDialog>
#include <QIcon>
#include <QListWidgetItem>
class gameproject;

namespace Ui {
    class getRepresentation;
}

class getRepresentation : public QDialog
{
    Q_OBJECT

public:
    explicit getRepresentation(QWidget *parent = 0);
    getRepresentation(gameproject* gp, QWidget *parent = 0);
    ~getRepresentation();
    QString selectedName;
    QIcon selectedIcon;

    void setProject(gameproject*);

protected:
    void changeEvent(QEvent *e);

private:
    gameproject* project;
    Ui::getRepresentation *ui;

private slots:
    void on_listWidget_itemClicked(QListWidgetItem* item);
    void on_listWidget_itemDoubleClicked(QListWidgetItem* item);
    void on_pushButton_2_clicked();
    void on_radioButton_4_clicked();
    void on_radioButton_5_clicked();
    void on_radioButton_6_clicked();
    void on_radioButton_clicked();
    void on_radioButton_2_clicked();
    void on_radioButton_3_clicked();
};

#endif // GETIMAGEORMODEL_H
