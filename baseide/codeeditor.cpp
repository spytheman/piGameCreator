#include "codeeditor.h"
#include "../sharedcode/idesettings.h"
#include <QApplication>
#include <QLayout>
#include <QDir>
#include <QWebFrame>
#include <QMessageBox>

//codeEditor
CodeEditor::CodeEditor(QWidget* parent)
{
    setProperty("haxeEditor","true");
    QVBoxLayout* L = new QVBoxLayout;
    L->setContentsMargins(0,0,0,0);
    setLayout(L);
    L->addWidget(&webview);
    isLoaded = false;
    webview.setUrl( QUrl::fromLocalFile(QDir::currentPath()+"/data/ace/ace.html") );
    connect(&webview, SIGNAL(loadFinished(bool)), this, SLOT(loadCompleted(bool)));
}

CodeEditor::~CodeEditor()
{

}

void CodeEditor::callJS(QString function, QString argument)
{
    callJS(function, QStringList()<<argument);
}

void CodeEditor::callJS(QString function, QStringList arguments)
{
    QString jscode = function;
    jscode.append("(");
    for(int i=0;i<arguments.count();i++)
    {
        QString argument = arguments.at(i);
        argument.replace("\"","\\\"");
        argument.replace("\r","");
        argument.replace("\n","\\n");
        argument.replace("\t","\\t");
        jscode.append("\""+argument+"\"");
        if(i<arguments.length()-1)
            jscode.append(",");
    }
    jscode.append(")");

    if(isLoaded)
    {
        gcprint(" EXECUTING "+jscode.mid(0,50)+"...");
        webview.page()->mainFrame()->evaluateJavaScript(jscode);
    }
    else
    {
        //gcprint(" APPENDING to Call Stack "+jscode.mid(0,50)+"...");
        callStack.append(jscode);
    }
}

void CodeEditor::loadCompleted(bool b)
{
    isLoaded = true;
    foreach(QString s, callStack)
        webview.page()->mainFrame()->evaluateJavaScript(s);
}

void CodeEditor::setText(QString s)
{
    callJS("setEditorText", QStringList() << s);
}

void CodeEditor::setBackgroundColor(QColor c){}
void CodeEditor::clearSelection(){}
void CodeEditor::copySelection(){}
void CodeEditor::cutSelection(){}
void CodeEditor::paste(){}
void CodeEditor::insertTextAtCursor(const QString& text){}
void CodeEditor::newLineAtCursor(){}
void CodeEditor::undo(){}
void CodeEditor::redo(){}
void CodeEditor::clearUndoStates(){}
void CodeEditor::selectAll(){}
