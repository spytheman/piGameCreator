#include "../sharedcode/globals.h"
#include "scripttestwindow.h"
#include "ui_scripttestwindow.h"
#include "settingswindow.h"
#include <QFile>
#include "../sharedcode/pgsparser.h"
#include "scriptwindow.h"
#include "codeeditor.h"
#include "mainwindow.h"

scripttestwindow::scripttestwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scripttestwindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

    source = new scriptwindow;
    ui->frame->layout()->addWidget(source);
    QFile f("test.pgs"); QString S;
    if(f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        S=f.readAll();
    }
    source->codeEditor->setSyntaxHighlighter(new pgsHighlighter);
    source->setText(S);
    source->codeEditor->setFocus();

    connect(creatorIDE, SIGNAL(IDEConfigChanged()), source->codeEditor, SLOT(onIDESettingsChanged()));

    setContentsMargins(0,0,0,0);
}

scripttestwindow::~scripttestwindow()
{
    delete ui;
}

void scripttestwindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void scripttestwindow::on_actionSettings_triggered()
{
    SettingsWindow w;
    w.exec();
    source->recolorize();
    source->setBackgroundColor(creatorIDE->settings->value("CodeEditor/BackgroundColor").value<QColor>());
}

void scripttestwindow::codeChanged()
{
    /*
    QString s;
    QList<pgsParser::token> l = source->tokens;
    for(int i=0;i<l.count();i++)
    {
        s.append("[" + pgsParser().tokenkindToString(l.at(i).kind) + "]: "+l.at(i).text + "\n");
        ui->debug->setPlainText(s);
    }/**/
}

#define OUTIT s.append("<div style='border: 1px solid #aaa;" \
    "background: #ccc; font-size: 12px;" \
    "display: inline-block;" \
    "border-radius:4px;margin:2px;padding: 2px;" \
    "color: #333;'><b>"+t.text+"</b><br>"+p.tokenkindToString(t.kind)+" "+t.typeName+"&nbsp;</div>");

void scripttestwindow::on_actionTEST_triggered()
{
    ui->debug->setMaximumHeight(16777215);
    QString s;
    //must do something
    pgsParser p;
    pgsParser::tokenlist l = p.tokenize(source->codeEditor->getText());
    p.parse(&l);

    /*
    foreach(pgsParser::token t, l)
    {
        OUTIT
    }
    ui->debug->setHtml(s); /**/
}

void scripttestwindow::on_actionExpression_triggered()
{
    ui->debug->setMaximumHeight(16777215);
    QString s;
    pgsParser p;
    pgsParser::expression e = p.parseExpression(source->codeEditor->getText());
    foreach(pgsParser::token t, e.parts)
    {
        OUTIT
    }
    ui->debug->setHtml(s);
}

void scripttestwindow::on_actionCreator_IDE_triggered()
{
    creatorIDE->mainWindow->show();
    close();
}
