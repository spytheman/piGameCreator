#ifndef SCRIPTWINDOW_H
#define SCRIPTWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QSyntaxHighlighter>
#include "../sharedcode/pgsparser.h"

class CodeEditor;

namespace Ui {
    class scriptwindow;
}

class scriptwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit scriptwindow(QWidget *parent = 0);
    ~scriptwindow();
    CodeEditor* codeEditor;
    void setText(QString s);
    void setBackgroundColor(QColor c);
    QString Text();
    void recolorize();

signals:

protected:
    void changeEvent(QEvent *e);

private:
    Ui::scriptwindow *ui;

};

#endif // SCRIPTWINDOW_H
