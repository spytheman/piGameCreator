#ifndef SCRIPTWINDOW_H
#define SCRIPTWINDOW_H

#include <QMainWindow>
#include <QPlainTextEdit>
#include <QSyntaxHighlighter>
#include "pgsparser.h"

namespace Ui {
    class scriptwindow;
}

//ALL classes used for the text editor... I won't separate them now.
    class scriptwindow;
    class CodeEditor;
    class LineNumberArea : public QWidget
    {
    public:
        LineNumberArea(CodeEditor *editor);
        QSize sizeHint() const ;

    protected:
        void paintEvent(QPaintEvent *event);

    private:
        CodeEditor *codeEditor;
    };
    class CodeEditor : public QPlainTextEdit
    {
        Q_OBJECT

    public:
        CodeEditor(QWidget *parent = 0);
        scriptwindow* SW;
        void lineNumberAreaPaintEvent(QPaintEvent *event);
        int lineNumberAreaWidth();
        void focusInEvent(QFocusEvent *e);

    protected:
        void resizeEvent(QResizeEvent *event);

    public slots:
        void updateLineNumberAreaWidth(int newBlockCount);
        void highlightCurrentLine();
        void updateLineNumberArea(const QRect &, int);

    private:
        QWidget *lineNumberArea;
    };
    class pgsHighlighter : public QSyntaxHighlighter
    {
        Q_OBJECT
    public:
        pgsHighlighter(QTextDocument* parent = 0);
    protected:
        void highlightBlock(const QString &text);
    };

class scriptwindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit scriptwindow(QWidget *parent = 0);
    ~scriptwindow();
    bool debug;
    void tokenize();
    void setText(QString s);
    void setReadOnly(bool readonly);
    QString Text();
    bool ReadOnly();
    QString DebugString;
    QList<pgsParser::token> tokens;
    CodeEditor* source;
    void recolorize();
    void setBackgroundColor(QColor);

signals:
    void codeChanged();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::scriptwindow *ui;
    pgsHighlighter* HL;

private slots:
    void colorize_slot(int position,int added,int deleted);
};

#endif // SCRIPTWINDOW_H
