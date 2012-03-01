#include "gamecreator.h"
#include "scripttestwindow.h"
#include "ui_scripttestwindow.h"
#include "srcSettings/settingswindow.h"

#include <QFile>

scripttestwindow::scripttestwindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::scripttestwindow)
{
    ui->setupUi(this);
    source = new scriptwindow;
    ui->frame->layout()->addWidget(source);
    QFile f("test.pgs"); QString S;
    if(f.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        S=f.readAll();
    }
    source->setText(S);
    source->source->setFocus();
    connect(source, SIGNAL(codeChanged()), this, SLOT(codeChanged()));
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
    source->setBackgroundColor(codeBackground);
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
