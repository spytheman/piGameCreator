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
    "background: #eee; font-size: 12px;" \
    "display: inline-block;" \
    "border-radius:3px;margin:1px;padding: 1px;" \
    "color: #333;'><b>"+t.text+"</b><br>"+p.tokenkindToString(t.kind)+" "+t.typeName+"&nbsp;</div>");

#define ERROR(MESSAGE) s.append("<div style='border: 1px solid #f00;" \
    "background: #fee; font-size: 13px;" \
    "border-radius:3px;margin:2px;padding: 1px;" \
    "color: #400;'><b>ERROR: </b>"+MESSAGE.message+" in class "+MESSAGE.className+" at line "+QString::number(MESSAGE.line)+"</div>");

void scripttestwindow::on_actionExpression_triggered()
{
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

void scripttestwindow::on_actionPreprocess_triggered()
{
    QString s;
    //must do something
    pgsParser p;
    pgsParser::tokenlist l = p.tokenize(source->codeEditor->getText());

    pgsParser::tokenlist defs = p.tokenize( ui->defines->text() );
    QStringList deflist;
    bool invdef = false;
    foreach(pgsParser::token def, defs)
    {
        if(p.isTextToken(def.kind)) deflist += def.text;
        else invdef = true;
    }

    l = p.preProcess(&l,ui->target->currentText(), ui->exporter->text(), deflist);

    foreach(pgsParser::parseError err, p.parseErrors)
    {
        ERROR(err)
    }

    if(invdef)
    {
        s = "Invalid defines!";
    }
    else
    foreach(pgsParser::token t, l)
    {
        OUTIT
    }
    ui->debug->setHtml(s); /**/
}

void scripttestwindow::on_actionParse_triggered()
{
    //parse
    QString s;
    //must do something
    pgsParser p;
    pgsParser::tokenlist l = p.tokenize(source->codeEditor->getText());

    pgsParser::tokenlist defs = p.tokenize( ui->defines->text() );
    QStringList deflist;
    bool invdef = false;
    foreach(pgsParser::token def, defs)
    {
        if(p.isTextToken(def.kind)) deflist += def.text;
        else invdef = true;
    }

    l = p.preProcess(&l,ui->target->currentText(), ui->exporter->text(), deflist);
    if(!invdef)
    {
        p.parse(&l);
    }
    else s="Invalid defines";
    //else
    ui->debug->setHtml(s); /**/
}

#undef OUTIT
#undef ERROR
