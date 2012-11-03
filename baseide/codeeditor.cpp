#include "codeeditor.h"
#include "../sharedcode/idesettings.h"
#include <QApplication>
#include <QLayout>
#include <QDir>
#include <QWebFrame>
#include <QMessageBox>
#include <QClipboard>

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

    setContextMenuPolicy(Qt::NoContextMenu);
}

CodeEditor::~CodeEditor()
{

}

bool CodeEditor::fInitCompleted()
{
    return initCompleted;
}

QVariant CodeEditor::evalJS(QString source)
{
    if(!isLoaded)
    {
        gcprint("WARNING: Ace is not initialized!");
        while(!isLoaded)QApplication::processEvents();
    }
    return webview.page()->mainFrame()->evaluateJavaScript(source);
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

    //add make this accessible through Javascript:
    webview.page()->mainFrame()->addToJavaScriptWindowObject("creatorIDE", this);

    foreach(QString s, callStack)
        webview.page()->mainFrame()->evaluateJavaScript(s);

    emit jsLoaded();
}

void CodeEditor::setText(QString s)
{
    QString text = s;
    text = text.replace("\\","\\\\");
    callJS("setEditorText", QStringList() << text);
}

QString CodeEditor::getText()
{
    return webview.page()->mainFrame()->evaluateJavaScript("getEditorText()").toString();
}

void CodeEditor::setBackgroundColor(QColor c){}
void CodeEditor::clearSelection()
{
}
void CodeEditor::copySelection()
{
}
void CodeEditor::cutSelection()
{
    qApp->clipboard()->setText( webview.page()->mainFrame()->evaluateJavaScript("editor.session.getTextRange(editor.getSelectionRange());").toString() );
    webview.page()->mainFrame()->evaluateJavaScript("editor.session.remove(editor.getSelectionRange());");
}
void CodeEditor::paste()
{
    callJS("editor.insert", qApp->clipboard()->text());
}
void CodeEditor::insertTextAtCursor(const QString& text)
{
    callJS("editor.insert", text);
}
void CodeEditor::newLineAtCursor(){}
void CodeEditor::undo(){}
void CodeEditor::redo(){}
void CodeEditor::clearUndoStates(){}
void CodeEditor::selectAll(){}

void CodeEditor::setFocusOnAce()
{
    webview.setFocus();
}
