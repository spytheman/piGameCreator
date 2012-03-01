#include "skintestwindow.h"
#include "ui_skintestwindow.h"
#include "gamecreator.h"
#include <QDir>
#include <QDateTime>

SkinTestWindow::SkinTestWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SkinTestWindow)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
    Menu = new QMenu;
    ui->TSCBD->setCheckState(Qt::PartiallyChecked);
    ui->TSCBE->setCheckState(Qt::PartiallyChecked);

    Menu->addAction("Option 1");
    Menu->addAction("Option 2");
    Menu->addSeparator();
    Menu->addAction("Option 3");
    QAction* a = new QAction(Menu);a->setText("Option 4");a->setEnabled(false);
    Menu->addAction(a);
    QAction* b = new QAction(Menu);b->setText("Option 5");b->setIcon(ffficon("bullet_error"));
    Menu->addAction(b);

    ui->ButtonWithMenu->setMenu(Menu);
    FileChecker.setSingleShot(false);
    FileChecker.setInterval(1000);
    FileChecker.start();

    connect(&FileChecker,SIGNAL(timeout()),this,SLOT(CheckFileDates()));
    ReloadSkins(true);
}

void SkinTestWindow::CheckFileDates()
{
    QMapIterator<QString,QDateTime> i(times);
    while(i.hasNext())
    {
        i.next();
        QDateTime fdt = QFileInfo(i.key()).lastModified();
        if(i.value() < fdt)
        {
            //File was modified!
            if(ui->SkinsList->currentItem())
            {
                QFile f(ui->SkinsList->currentItem()->data(TIDATA).toString());
                if(f.open(QIODevice::ReadOnly))
                {
                    QString s = f.readAll();
                    qApp->setStyleSheet(s);
                    times[i.key()] = fdt;
                }
            }
        }
    }
    ReloadSkins();
}

void SkinTestWindow::ReloadSkins(bool init)
{
    int ROW= ui->SkinsList->currentRow();
    if(init)times.clear();
    ui->SkinsList->clear();

    QDir d("themes");
    QStringList sl = d.entryList(QDir::Dirs | QDir::NoDotAndDotDot);
    sl.sort();
    foreach(QString theme,sl)
    {

        //determine the SKIN NAME? Subskins?
        QDir dd("themes/"+theme);
        QStringList themefiles = dd.entryList(QStringList("*.css"));
        foreach(QString tf,themefiles)
        {
            QListWidgetItem* a = new QListWidgetItem;

            QString name;
            QFile f(QDir::currentPath()+ "/themes/"+theme+"/"+tf);
            if(f.open(QIODevice::ReadOnly))
            {
                a->setText(theme+"/"+tf);
                a->setData(TIDATA,QDir::currentPath()+ "/themes/"+theme+"/"+tf); //file
                ui->SkinsList->addItem(a);
                QString fn = a->data(TIDATA).toString();
                QFileInfo fi(fn);
                times[fn]=fi.lastModified();
            }
            else gcprint("Unable to read file: "+QDir::currentPath()+ "/themes/"+theme+"/"+tf);
        }
    }
    ui->SkinsList->setCurrentRow(ROW);
}

SkinTestWindow::~SkinTestWindow()
{
    delete ui;
}

void SkinTestWindow::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void SkinTestWindow::on_pushButton_4_clicked()
{
    close();
}

void SkinTestWindow::on_SkinsList_itemClicked(QListWidgetItem *item)
{
    QFile f(item->data(TIDATA).toString());
    if(f.open(QIODevice::ReadOnly))
    {
        QString s = f.readAll();
        qApp->setStyleSheet(s);
    }
}

void SkinTestWindow::on_toolButton_3_clicked()
{
    ReloadSkins();
}
