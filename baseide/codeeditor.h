#ifndef CODEEDITOR_H
#define CODEEDITOR_H

#include <QAbstractScrollArea>
#include <QLinkedList>
#include "../sharedcode/pgsparser.h"
#include <QWebView>

class CodeEditor : public QAbstractScrollArea
{
    friend struct gswWrapper;
        Q_OBJECT
        Q_PROPERTY(bool initCompleted READ fInitCompleted)

    public:
        CodeEditor(QWidget *parent = 0);
        ~CodeEditor();


        //Text editing routines
        void clearSelection();
        void copySelection();
        void cutSelection();
        void paste();
        void insertTextAtCursor(const QString& text);
        void newLineAtCursor();
        void undo();
        void redo();
        void clearUndoStates();
        void selectAll();
        void setFocusOnAce();
        void callJS(QString function, QString argument);
        void callJS(QString function, QStringList arguments = QStringList());
        QVariant evalJS(QString source);

        //set and get the text
        void setText(QString s);
        QString getSelectedText();
        QString getText();

        //other
        void setBackgroundColor(QColor c);

    signals:
        void textModified();
        void completerRequested(int,QString);
        void jsLoaded();

    private slots:
        void loadCompleted(bool b);

    private:
        QWebView webview;
        QString textToSet;
        bool isLoaded;
        bool initCompleted;
        bool fInitCompleted();
        QStringList callStack;
};

#endif // CODEEDITOR_H
