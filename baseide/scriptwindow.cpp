#include "../sharedcode/globals.h"
#include "../sharedcode/timer.h"
#include "../baseide/gcide.h"
#include "scriptwindow.h"
#include "codeeditor.h"
#include "ui_scriptwindow.h"
#include <QPainter>
#include <QTextBlock>
#include <QTextStream>
#include <QTextCursor>
#include <QFile>
#include <QTextDocumentFragment>
#include <QTextBlockFormat>
#include <QtTest/qbenchmark.h>

scriptwindow::scriptwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scriptwindow)
{
    ui->setupUi(this);
    //codeBackground = creatorIDE->settings->value("CodeEditor/BackgroundColor").value<QColor>();
    //if(!codeBackground.isValid())gcerror("Invalid color!");
    codeEditor = new CodeEditor;
    ui->Sourcezone->layout()->addWidget(codeEditor);

}

scriptwindow::~scriptwindow()
{
    delete codeEditor;
    delete ui;
}

void scriptwindow::changeEvent(QEvent *e)
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

void scriptwindow::setText(QString s)
{
    codeEditor->setText(s);
}

QString scriptwindow::Text()
{
    return codeEditor->getText();
}


void scriptwindow::setBackgroundColor(QColor c)
{
    codeEditor->backgroundColor = c;
    codeEditor->repaint();
}

void scriptwindow::recolorize()
{
    //must reload the color config and then:
    codeEditor->repaint();
}
