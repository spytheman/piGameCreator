#ifndef SELECTICON_H
#define SELECTICON_H

#include <QDialog>
#include <QIcon>
#include <QListWidgetItem>

namespace Ui {
class selectIcon;
}

class selectIcon : public QDialog
{
    Q_OBJECT
    
public:
    explicit selectIcon(QWidget *parent = 0);
    ~selectIcon();

    QIcon selectedIcon;
    void setSelectedIcon(QIcon selectedIcon);
    void accept();
    
private slots:
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_searchTextBox_textChanged(const QString &text);

    void on_clearButton_clicked();

    void on_toolButton_clicked();

private:
    Ui::selectIcon *ui;
};

#endif // SELECTICON_H
