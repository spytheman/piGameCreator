#ifndef CODECLASS_H
#define CODECLASS_H

#include <QMainWindow>
#include <QtNetwork/QTcpSocket>
#include "../../baseide/resourceeditor.h"
#include "../../sharedcode/pgshighlighter.h"
#include <QListWidget>

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
    bool event(QEvent* e);

    struct completeOption
    {
        QString name, type, description;
        QIcon icon;
    };

signals:

public slots:
    void on_actionClass_members_triggered(bool checked);
    void on_actionFunction_library_triggered(bool checked);
    void reloadWindowState();
    void codeModified();
    void invokeCompleter(int pos, QString c);
    void on_tbGoToLineNumber_clicked();
    void showError(QString out);

    void InitHaxeCompilerCompleter(QString xml);

    void showCompleter();   //only shows it and updates it!
    void hideCompleter();
    //void showCompleter(QList<completeOption> items);
    void completerItemClicked(QListWidgetItem* item);
    void completerItemSelected(QListWidgetItem* item);
    // It appears that I must hack into the event system here...
    bool eventFilter(QObject *o, QEvent *e);
    void refreshHaxeAPI();
    void refreshHaxeAPIlater();

private:
    bool underDeletion;

    Ui::codeClass *ui;
    CodeEditor* editor;
    int lastTargetIndex;
    int largestOptionWidth;
    QList<completeOption> ccOptions;
    QWidget completerContainer;
    QListWidget completer;
    QString completerSearchString;
    void updateCompleterQuery();
};

#endif // CODECLASS_H
