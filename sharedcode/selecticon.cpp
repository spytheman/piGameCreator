#include "selecticon.h"
#include "ui_selecticon.h"
#include "../sharedcode/globals.h"
#include "../sharedcode/qtwin.h"
#include "../sharedcode/imageio.h"
#include <QFileDialog>

selectIcon::selectIcon(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::selectIcon)
{
    setWindowFlags(Qt::Window | Qt::CustomizeWindowHint
                   | Qt::MSWindowsFixedSizeDialogHint
                   | Qt::WindowTitleHint | Qt::WindowSystemMenuHint
                   | Qt::WindowCloseButtonHint
                   );
    QtWin::extendFrameIntoClientArea(this);

    gcBeginWait();
    ui->setupUi(this);

    //init all icons:
    ui->listWidget->clear();
    QStringList pngs = findFilesRecursively( QStringList()<<":/", QStringList()<<"*.png" );

    foreach(QString file, pngs)
    {
        QListWidgetItem* i = new QListWidgetItem;
        i->setIcon(QIcon(file));
        i->setWhatsThis(file);
        ui->listWidget->addItem(i);
    }

    gcEndWait();
}

selectIcon::~selectIcon()
{
    delete ui;
}

void selectIcon::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    ui->selectedIconTB->setIcon(current->icon());
}

void selectIcon::setSelectedIcon(QIcon selectedIcon)
{
    ui->selectedIconTB->setIcon(selectedIcon);
    ui->listWidget->blockSignals(true);
    bool mustadd = true;
    for(int i=0; i<ui->listWidget->count();++i)
    {
        QListWidgetItem* item = ui->listWidget->item(i);
        if( item->icon().pixmap(16,16).toImage() ==  selectedIcon.pixmap(16,16).toImage())
        {
            ui->listWidget->setCurrentItem(item);
            mustadd = false;
        }
    }
    if(mustadd)
    {
        QListWidgetItem* current = new QListWidgetItem;
        current->setIcon(selectedIcon);
        current->setWhatsThis("Current selected icon");
        ui->listWidget->insertItem(0,current);
    }
    ui->listWidget->blockSignals(false);
}

void selectIcon::accept()
{
    selectedIcon = ui->selectedIconTB->icon();
    close();
}

void selectIcon::on_searchTextBox_textChanged(const QString &text)
{
    if(text!="")
    {
        for(int i=0;i<ui->listWidget->count();i++)
        {
            QListWidgetItem* item = ui->listWidget->item(i);
            if(item->whatsThis().contains(text))item->setHidden(false);
            else item->setHidden(true);
        }
    }
    else
    {
        for(int i=0;i<ui->listWidget->count();i++)
        {
            QListWidgetItem* item = ui->listWidget->item(i);
            item->setHidden(false);
        }
    }
}

void selectIcon::on_clearButton_clicked()
{
    ui->searchTextBox->setText("");
}

void selectIcon::on_toolButton_clicked()
{
    QString s = imageio::getOpenFilename("",true);
    QPixmap p = imageio::loadImage(s);
    if(!p.isNull())
    {
        QIcon icon( p.scaled(16,16,Qt::KeepAspectRatio,Qt::SmoothTransformation) );
        setSelectedIcon(icon);
    }
}
