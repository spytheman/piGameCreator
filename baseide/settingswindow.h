#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include "../sharedcode/globals.h"
#include "gcide.h"
#include "codeeditor.h"
#include <QDialog>
#include <QListWidgetItem>

namespace Ui {
    class SettingsWindow;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = 0);
    ~SettingsWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::SettingsWindow *ui;

    //Settings
    CodeEditor* source;

signals:
    void codeColoringChanged();

private slots:
    void on_editorFontComboBox_currentFontChanged(QFont f);
    void SettingsWindow_rejected();
    void SettingsWindow_accepted();
    void listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);
    void on_fontSize_valueChanged(int newsize);
    void on_themeComboBox_currentIndexChanged(const QString &arg1);
};

#endif // SETTINGSWINDOW_H
