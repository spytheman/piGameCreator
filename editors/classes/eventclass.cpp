#include <QPainter>
#include <QFile>
#include <QTimer>
#include <QInputDialog>
#include <QMenu>
#include "../../sharedcode/globals.h"
#include "eventclass.h"
#include "getrepresentation.h"
#include "ui_eventclass.h"
#include "editvardialog.h"

eventClass::eventClass(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::eventClass)
{
    ui->setupUi(this);
    widget=this;
    setAttribute(Qt::WA_DeleteOnClose);
    setProperty("editor",true);
    ui->stackedWidget->setCurrentIndex(0);
}

eventClass::~eventClass()
{
    delete ui;
}

void eventClass::changeEvent(QEvent *e)
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

bool eventClass::save()
{

}


bool eventClass::load()
{

}

bool eventClass::init()
{
    setTitle(resource->name);
    return true;
}

void eventClass::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void eventClass::on_pushButton_clicked()
{

}

void classpreview::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    if(icon.isNull())
    {
        p.fillRect(0,0,width(),height(),QApplication::palette().background());
        p.drawText(0,0,width(),height(),Qt::AlignCenter,tr("PREVIEW\nClick to select"));

    }
    else
    {
        p.drawPixmap(0,0,icon);
    }
}

void classpreview::mousePressEvent(QMouseEvent *e)
{

}

void classpreview::mouseReleaseEvent(QMouseEvent *e)
{

}

classpreview::classpreview(QWidget *parent) : QWidget(parent)
{

}

classpreview::~classpreview()
{

}

void eventClass::checkVars()
{

}
