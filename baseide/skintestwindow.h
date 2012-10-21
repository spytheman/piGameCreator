#ifndef SKINTESTWINDOW_H
#define SKINTESTWINDOW_H

#include <QDialog>
#include <QMenu>
#include <QTimer>
#include <QListWidgetItem>

namespace Ui {
    class SkinTestWindow;
}

class SkinTestWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SkinTestWindow(QWidget *parent = 0);
    ~SkinTestWindow();
    void ReloadSkins(bool init=false);
    QTimer FileChecker;
    QMap<QString,QDateTime> times;

protected:
    void changeEvent(QEvent *e);


private slots:
    void on_pushButton_4_clicked();
    void CheckFileDates();

    void on_SkinsList_itemClicked(QListWidgetItem *item);

    void on_toolButton_3_clicked();

private:
    Ui::SkinTestWindow *ui;
    QMenu* Menu;
};

#endif // SKINTESTWINDOW_H
