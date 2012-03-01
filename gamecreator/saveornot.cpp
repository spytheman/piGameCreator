#include "gamecreator.h"
#include "saveornot.h"
#include "ui_saveornot.h"
#include "qtwin.h"
saveornot::saveornot(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::saveornot)
{
    gcprint("can't create this");
    // force crash
    ((QWidget*)0)->show();
}
saveornot::saveornot(gameproject *gp):
    QDialog(0),
    ui(new Ui::saveornot)
{
    ui->setupUi(this);
    if(QtWin::isCompositionEnabled())
    {
        QtWin::extendFrameIntoClientArea(this);
        QtWin::enableBlurBehindWindow(this,true);
    }
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(size());
    ui->label_2->setText(gp->name);
}

saveornot::saveornot(QString what):
    QDialog(0),
    ui(new Ui::saveornot)
{
    ui->setupUi(this);
    if(QtWin::isCompositionEnabled())
    {
        QtWin::extendFrameIntoClientArea(this);
        QtWin::enableBlurBehindWindow(this,true);
    }
    setAttribute(Qt::WA_DeleteOnClose);
    setFixedSize(size());
    ui->label->setText(tr("Following resource has changed:"));
    ui->label_2->setText(what);
}

saveornot::~saveornot()
{
    delete ui;
}

void saveornot::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type())
    {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void saveornot::on_commandLinkButton_3_clicked()
{
    done(-1);
}

int saveornot::resource(QString what)
{
    saveornot* q = new saveornot(what);
    return q->exec();
}

int saveornot::project(QString what)
{
    saveornot* q = new saveornot(what);
    return q->exec();
}

