#ifndef CODECLASS_H
#define CODECLASS_H

#include <QMainWindow>
#include "../../baseide/resourceeditor.h"
#include "../../sharedcode/pgshighlighter.h"

#define SETTING_CODECLASS_WINDOW_STATE "CodeClass/State"
#define SETTING_CODECLASS_SPLITTER_STATE "CodeClass/SplitterState"

namespace Ui {
    class codeClass;
}

class CodeEditor;
class codeClass : public QMainWindow, public ResourceEditor
{
    Q_OBJECT
public:
    explicit codeClass(QWidget *parent = 0);
    ~codeClass();
    
    bool init();
    bool save();
    bool load();
    void hideEvent(QHideEvent *);
    void showEvent(QShowEvent *);

signals:

public slots:
    void on_actionClass_members_triggered(bool checked);
    void on_actionFunction_library_triggered(bool checked);
    void reloadWindowState();

    void on_tbGoToLineNumber_clicked();

private:
    Ui::codeClass *ui;
    CodeEditor* editor;
    
};

#endif // CODECLASS_H
