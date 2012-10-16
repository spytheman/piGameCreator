#include "imagepreviewer.h"
#include "ui_imagepreviewer.h"
#include "qtwin.h"
#include "globals.h"
#include "idesettings.h"
#include <QMovie>
#include <QGraphicsDropShadowEffect>
#include <QDesktopServices>
#include <QListWidgetItem>
#include <QProcess>
#include <QFile>

ImagePreviewer::ImagePreviewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ImagePreviewer)
{
    cancelled = false;
    imagesCount = 0;
    multiMode = false;
    ui->setupUi(this);

    setWindowFlags(Qt::Window
                   | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint
                   | Qt::WindowMaximizeButtonHint
                   | Qt::WindowSystemMenuHint | Qt::WindowTitleHint);

    QtWin::extendFrameIntoClientArea(this);

    QGraphicsDropShadowEffect* ds = new QGraphicsDropShadowEffect;
    ds->setColor(Qt::white);
    ds->setOffset(0,0);
    ds->setBlurRadius(4);
    ui->loaderLabel->setGraphicsEffect(ds);
    ui->statusLabel->setGraphicsEffect(ds);
    QMovie* m = new QMovie(":/resources/RES/loader.gif");
    ui->loaderLabel->setMovie(m);
    m->setCacheMode(QMovie::CacheAll);
    m->start();
    imagePreview = new QGraphicsScene;
    ui->graphicsView->setScene(imagePreview);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/resources/RES/alpha.png"));
    restoreGeometry(ideSettings::getByteArray(S_IMAGEPREVIEW_GEOMETRY));
}

ImagePreviewer::~ImagePreviewer()
{
    delete imagePreview;
    delete ui;
}

void ImagePreviewer::loadImages(QStringList files)
{
    imagesCount = 0;
    ui->listWidget->clear();
    for(int i=0;i<files.count();++i)
    {
        QPixmap p(files.at(i));
        QListWidgetItem* item = new QListWidgetItem();
        item->setIcon( QIcon(p) );
        item->setData(TIDATA, files.at(i));
        item->setData(TICODE, i);   //the index
        ui->listWidget->addItem(item);
        imagesCount++;
    }
    if(files.count()==0)
    {
        gcmessage("This file does not contain images,"
                  "cannot be loaded, "
                  "the system library for its format is not installed,"
                  "or the file format is not supported. "
                  "\n\n"
                  "Note that PDF and EPS require Ghostscript to be installed, MOV requires Apple QuickTime and MPG/MPEG/MP4/AVI mar require ffmpeg and/or appropriate codecs.");
        selectedImageIndexes.clear();
        accept();
        return;
    }
    if(files.count()==1)
    {
        //only one frame, directly accept:
        //set selected image indexes:
        selectedImageIndexes.clear();
        selectedImageIndexes.append(0);
        accept();
        close();
    }
    on_listWidget_currentItemChanged(ui->listWidget->item(0),NULL);
}

void ImagePreviewer::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    QString filename = current->data(TIDATA).toString();
    QRegExp r("([0-9]+)");
    QString number;
    if(r.indexIn(filename))number=r.cap(0);
    int i = number.toInt();
    QString temppath = QDesktopServices::storageLocation(QDesktopServices::TempLocation)+"/imagick";
    QString tempfilename = temppath+"/fullsize-"+number+".png";
    if(!QFile::exists(tempfilename))
    {
        ui->statusLabel->setText("Loading image data...");
        ui->LoaderFrame->show();
        gcBeginWait();
        QProcess im;
        im.start("imagick/convert", QStringList()<< sourceFile + "["+ QString::number(i) +"]" << tempfilename );
        im.waitForStarted();
        while(im.state()!=QProcess::NotRunning)
        {
            QApplication::processEvents();
        }
        gcEndWait();
        ui->LoaderFrame->hide();
    }
    //tempfilename now must exist!
    QPixmap p(tempfilename);
    imagePreview->clear();
    imagePreview->addPixmap(p);
    ui->graphicsView->setSceneRect(imagePreview->itemsBoundingRect());
}

QPixmap ImagePreviewer::getImage(int index)
{
    //Which listitem have this number?
    for(int i=0;i<ui->listWidget->count();++i)
    {
        QListWidgetItem* item = ui->listWidget->item(i);
        QString filename = item->data(TIDATA).toString();
        QRegExp r("([0-9]+)");
        QString number;
        if(r.indexIn(filename))number=r.cap(0);
        int idx = number.toInt();
        if(idx == index)
        {
            QString temppath = QDesktopServices::storageLocation(QDesktopServices::TempLocation)+"/imagick";
            QString tempfilename = temppath+"/fullsize-"+number+".png";
            if(!QFile::exists(tempfilename))
            {
                ui->statusLabel->setText("Loading image data...");
                ui->LoaderFrame->show();
                gcBeginWait();
                QProcess im;
                im.start("imagick/convert", QStringList()<< sourceFile + "["+ QString::number(i) +"]" << tempfilename );
                im.waitForStarted();
                while(im.state()!=QProcess::NotRunning)
                {
                    QApplication::processEvents();
                }
                gcEndWait();
                ui->LoaderFrame->hide();
            }
            //tempfilename now must exist! what if not? @BUG
            return QPixmap(tempfilename);
        }
    }
    return QPixmap();
}

void ImagePreviewer::on_buttonBox_accepted()
{
    selectedImageIndexes.clear();
    ideSettings::setByteArray(S_IMAGEPREVIEW_GEOMETRY, saveGeometry());
    QList<QListWidgetItem*> items = ui->listWidget->selectedItems();
    foreach(QListWidgetItem* i, items)
    {
        selectedImageIndexes.append( i->data(TICODE).toInt() );
    }
}

void ImagePreviewer::on_buttonBox_rejected()
{
    ideSettings::setByteArray(S_IMAGEPREVIEW_GEOMETRY, saveGeometry());
}

void ImagePreviewer::on_statusCancelButton_clicked()
{
    cancelled = true;
}

void ImagePreviewer::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    if(!multiMode)
    {
        on_buttonBox_accepted();
        accept();
    }
}
