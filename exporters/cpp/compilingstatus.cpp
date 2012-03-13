#include "compilingstatus.h"
#include "ui_compilingstatus.h"
#include "QDebug"
#include "QThread"
#include "cppexport.h"

//Get access to some gameCreator tools.
#include "gamecreator.h"

class ExportThread:public QThread{
public:
    QString gcpx;
    CompilingStatus* w;
    //sets the dialog message
    void messsage(QString m)
    {
        w->ui->message->setText(m);
        w->ui->complog->appendPlainText(m);
    }
    void progress(int i){w->ui->progress->setValue(i);}
    void run()
    {
        //this thread will compile each resource
        cppExporter e;
        e.loadProject(gcpx);
        foreach(QString s,e.resourceFiles)
        {
            e.exportResource(s);
            QThread::msleep(500);
        }
    }
};


CompilingStatus::CompilingStatus(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CompilingStatus)
{
    ui->setupUi(this);
    ui->complog->hide();
    ui->details->setCheckable(1);
    adjustSize();
    setWindowIcon( QIcon(":/resources/RES/compile.png"));
    et = new ExportThread;
    et->gcpx = project;
    et->w = this;
    et->run();
}


CompilingStatus::~CompilingStatus()
{
    delete ui;
}

void CompilingStatus::on_details_toggled(bool checked)
{
    ui->complog->setVisible(checked);
    adjustSize();
}
void CompilingStatus::run(){ui->header->setText("Preparing to run "+project);}
void CompilingStatus::debug(){ui->header->setText("Preparing to debug "+project);}
void CompilingStatus::build(){ui->header->setText("Building "+project);}
void CompilingStatus::deploy(){ui->header->setText("Deploying "+project);}
