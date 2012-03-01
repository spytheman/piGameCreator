#include "gamecreator.h"
#include "imagewindow.h"
#include "ui_imagewindow.h"
#include <QGraphicsBlurEffect>
#include <QFileDialog>
#include <QImageReader>
#include <QImageWriter>
#include <QPaintEvent>
#include <QPainter>
#include <QUrl>
#include <QClipboard>

imagewindow::imagewindow(QWidget *parent) : //should not be called.
    QMainWindow(parent),
    ui(new Ui::imagewindow)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    fixback(this);
    setProperty("editor",true);
    setAcceptDrops(true);
    width=64;
    height=64;
    unitsize=1.0;
    scalingmode=0;
    previewmode=0;
    offsetx=0;
    offsety=0;
    masktype=0;
}

void imagewindow::load()
{
    initialized=0;
    //loads the resource
    QDomDocument* xml = gcReadXml(project->absoluteFolder + "/images/"+name+".xml");
    if(xml!=0)
    {
        QDomElement e = xml->documentElement();
        //read it
        masktype = e.attribute("masktype").toInt();
        width = e.attribute("width").toInt();
        height = e.attribute("height").toInt();
        offsetx = e.attribute("offsetX").toInt();
        offsety = e.attribute("offsetY").toInt();
        unitsize = e.attribute("unitsize").toDouble();
        bboxleft = e.attribute("boxleft").toInt();
        bboxright = e.attribute("boxright").toInt();
        bboxtop = e.attribute("boxtop").toInt();
        bboxbottom = e.attribute("boxbottom").toInt();
        circleradius = e.attribute("circleradius").toInt();
        previewmode = e.attribute("previewmode").toInt();
        scalingmode = e.attribute("scalingmode").toInt();
        bitmapcolisionperframe = e.attribute("bitmapcolisionperframe").toInt();

        QDomNode i = e.firstChild();
        while(!i.isNull())
        {
            QDomElement E = i.toElement();
            if(E.tagName()=="img")
                if(E.hasAttribute("src"))
                {
                    //Load and add the frame
                    QImageReader I(project->absoluteFolder+"/images/"+name+"/"+E.attribute("src"));
                    for(int ii=0;ii<I.imageCount();ii++) //for all frames
                    {
                        QImage f = I.read();
                        if(f.isNull())break;
                        QPixmap pr;
                        if(!pr.convertFromImage(f))gcprint("QPixmap::ConvertFromImage: FAILED!");
                        frames.push_back(pr);
                        icons.push_back(pr.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
                        gcprint("pushing image...");
                    }
                }

            i = i.nextSibling();
        }

        delete xml;
    }
    //update UI
    ui->imgName->setText(name);
    ui->imgWidth->setValue(width);
    ui->imgHeight->setValue(height);
    ui->offsetX->setValue(offsetx);
    ui->offsetY->setValue(offsety);
    ui->comboBox->setCurrentIndex(masktype);
    on_comboBox_activated(masktype);
    ui->comboBox_scaling->setCurrentIndex(scalingmode);
    on_comboBox_scaling_activated(scalingmode);

    //some other UI stuff
    ui->listWidget->setModel(&framelist);

    preview.window = this;
    framelist.window = this;

    QHBoxLayout* L = new QHBoxLayout; L->setMargin(0);
    ui->previewFrame->setLayout(L);
    ui->previewFrame->layout()->addWidget(&preview);

    updateFrameList();
    ui->listWidget->setCurrentIndex(framelist.index(0,0));
    preview.repaint();
    initialized=1;

}
void imagewindow::save()
{
    //save the resource
    QDomDocument xml;
    QDomProcessingInstruction pi = xml.createProcessingInstruction("xml","version=\"1.0\"");
    xml.appendChild(pi);
    QDomElement image = xml.createElement("image");
    xml.appendChild(image);
    //width, height, xoffset, yoffset
    image.setAttribute("width",width);
    image.setAttribute("height",height);
    image.setAttribute("offsetX",offsetx);
    image.setAttribute("offsetY",offsety);
    image.setAttribute("scalingmode",scalingmode);
    image.setAttribute("unitsize",unitsize);
    image.setAttribute("masktype",masktype);
    switch(masktype)
    {
    case 0:
        image.setAttribute("boxleft",bboxleft);
        image.setAttribute("boxright",bboxright);
        image.setAttribute("boxtop",bboxtop);
        image.setAttribute("boxbottom",bboxbottom);
        break;
    case 1:
        image.setAttribute("circleradius",circleradius);
        break;
    case 2:
        image.setAttribute("bitmapcolisionperframe",bitmapcolisionperframe);
        break;
    case 3:
        //nothing
        break;
    }

    image.setAttribute("previewmode",previewmode);

    //now the frames
    int c=0;
    QDir().mkpath(project->absoluteFolder+"/images/"+name);
    QDir d;d.setPath(project->absoluteFolder);d.cd("images");d.cd(name);
    QStringList F = d.entryList(QStringList("*.png"),QDir::Files);
    foreach(QString s,F)d.remove(s);
    for(int i=0;i<frames.count();i++)
    {
        c++;
        QString fn = "frame"+QString::number(c)+".png";
        QString afn = project->absoluteFolder+"/images/"+name+"/"+fn;
        frames.at(i).save(afn,"PNG");
        QDomElement img = xml.createElement("img");
        img.setAttribute("src",fn);
        image.appendChild(img);
    }
    if(icons.count()>0)
    {
        icons.at(0).save(project->absoluteFolder+"/images/"+name+"/icon.png","PNG");
    }
    gcSaveXml(project->absoluteFolder+"/images/"+name+".xml", &xml);
    modified=false;
    updateTitle();
}

void imagewindow::setName(QString name)
{
    ui->imgName->setText(name);
}

imagewindow::~imagewindow()
{
    frames.clear();
    icons.clear();
    delete ui;
}
void imagewindow::changeEvent(QEvent *e)
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

void imagewindow::dragEnterEvent(QDragEnterEvent * e)
{
  if(e->mimeData()->hasUrls() or e->mimeData()->hasImage())
  e->accept();
}
void imagewindow::dropEvent(QDropEvent * e)
{

    //if(e->mimeData()->hasUrls() or e->mimeData()->hasImage())e->accept();
    if(e->mimeData()->hasUrls())
    {

        QList<QUrl> urls = e->mimeData()->urls();
        //for each file try to fetch it as image
        for(int u=0;u<urls.count();u++)
        {
           // gcmessage(urls.at(u).toString());
            QString lf = urls.at(u).toLocalFile();
            QImageReader i(lf);
            for(int ii=0;ii<i.imageCount();ii++) //for all frames
            {
                QImage f = i.read();
                if(f.isNull())break;
                QPixmap pr;
                if(!pr.convertFromImage(f))gcprint("QPixmap::ConvertFromImage: FAILED!");
                frames.push_back(pr);
                icons.push_back(pr.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
            }
        }
        updateFrameList(false);
        if(ui->listWidget->currentIndex().row()==-1)
            ui->listWidget->setCurrentIndex(framelist.index(0,0));
        preview.repaint();
        //damn crash
        if(icons.count()>0)treeitem->setIcon(icons.at(0));
    }
    else if(e->mimeData()->hasImage())
    {

    }
    e->accept();
}

void imagewindow::on_actionLoad_images_triggered()
{
    QStringList files = QFileDialog::getOpenFileNames(this,"Add frames...","",gc2DformatsRead);
    QString it; int n=0;QString ffn, fn;
    //this is okay even if already there :D:
    makeModified();
    //for each selected file
    foreach(QString s,files)
    {
        gcprint("Importing file: " + s);
        //load all selected files
        QImageReader i(s);
        for(int ii=0;ii<i.imageCount();ii++) //for all frames
        {

            QImage f = i.read();
            if(f.isNull())break;

            //add it to frames

            //add it to the preview
            QPixmap pr;
            if(!pr.convertFromImage(f))gcprint("QPixmap::ConvertFromImage: FAILED!");
            frames.push_back(pr);
            icons.push_back(pr.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));
        }
    }
    updateFrameList();
    if(ui->listWidget->currentIndex().row()==-1)
        ui->listWidget->setCurrentIndex(framelist.index(0,0));
    if(frames.count()==1) on_toolButton_clicked();
    preview.repaint();
}

void imagewindow::updateFrameList(bool updatetree)
{
    framelist.clear();
    int i=0;
    for(int i=0;i<icons.count();i++)
    {
        QStandardItem* j = new QStandardItem;
        j->setText(QString::number(i));
        j->setIcon(icons.at(i));
        framelist.appendRow(j);
    }
    if(updatetree and icons.count()>0)treeitem->setIcon(icons.at(0));  //does THIS one crash the SetIcon?
}

//0 - box, 1 - circle, 2 - pixmap, 3 - as frame (per pixel)
void imagewindow::on_cmBox_clicked()
{
    masktype=0;
    ui->gbBoxCollision->show();
    ui->gbCircleCollision->hide();
    ui->gbBitmapCollision->hide();
}

void imagewindow::on_cmCircle_clicked()
{
    masktype=1;
    ui->gbBoxCollision->hide();
    ui->gbCircleCollision->show();
    ui->gbBitmapCollision->hide();
}

void imagewindow::on_cmBitmap_clicked()
{
    masktype=2;
    ui->gbBoxCollision->hide();
    ui->gbCircleCollision->hide();
    ui->gbBitmapCollision->show();
}

void imagewindow::on_cmAsFrame_clicked()
{
    masktype=3;
    ui->gbBoxCollision->hide();
    ui->gbCircleCollision->hide();
    ui->gbBitmapCollision->hide();
}

void imagewindow::on_toolButton_3_clicked()
{
    makeModified();
    offsetx = 0;
    offsety = 0;
    ui->offsetX->setValue(offsetx);
    ui->offsetY->setValue(offsety);
    preview.repaint();
}

void imagewindow::on_listWidget_clicked(QModelIndex index)
{
    preview.repaint();
}

void imagewindow::on_imgWidth_valueChanged(int i)
{
    makeModified();
    width = i;
    preview.repaint();
}

void imagewindow::on_imgHeight_valueChanged(int i)
{
    makeModified();
    height = i;
    preview.repaint();
}

void imagewindow::on_offsetX_valueChanged(int i)
{
    makeModified();
    offsetx = i;
    preview.repaint();
}

void imagewindow::on_offsetY_valueChanged(int i)
{
    makeModified();
    offsety = i;
    preview.repaint();
}

void imagewindow::on_actionDelete_selected_triggered()
{
    makeModified();
    if(frames.isEmpty())return;
    int row = ui->listWidget->currentIndex().row();
    if(! ui->listWidget->currentIndex().isValid())return;

    frames.removeAt(row);
    icons.removeAt(row);

    updateFrameList();

    if(frames.count()>0)
        ui->listWidget->setCurrentIndex(framelist.index(row,0));

    preview.repaint();

}

void imagewindow::on_toolButton_4_clicked()
{
    makeModified();
    offsetx = width/2;
    offsety = height/2;
    ui->offsetX->setValue(offsetx);
    ui->offsetY->setValue(offsety);
    preview.repaint();
}

void imagewindow::on_toolButton_clicked()
{
    makeModified();
    if(frames.isEmpty())return;
    if(ui->listWidget->currentIndex().isValid()==false)return;
    int row = ui->listWidget->currentIndex().row();
    width = frames.at(row).width();
    height = frames.at(row).height();
    ui->imgWidth->setValue(width);
    ui->imgHeight->setValue(height);
    preview.repaint();
}

void imagewindow::on_comboBox_activated(int index)
{
    //makeModified();
    previewmode = index;
    switch(index)
    {
    case 0: on_cmBox_clicked();break;
    case 1: on_cmCircle_clicked();break;
    case 2: on_cmBitmap_clicked();break;
    case 3: on_cmAsFrame_clicked();break;
    }
    preview.repaint();
}

void imagewindow::on_comboBox_scaling_activated(int index)
{
    makeModified();
    scalingmode=index;
    preview.repaint();
}

void imagewindow::on_pmUnits_valueChanged(double i)
{
    makeModified();
    unitsize = i;
    preview.repaint();
}

void imagewindow::on_actionPaste_triggered()
{
    const QClipboard *clipboard = QApplication::clipboard();
    const QMimeData *mimeData = clipboard->mimeData();
    QPixmap pr;
    if (mimeData->hasImage())
    {
        pr = qvariant_cast<QPixmap>(mimeData->imageData());
    }
    if(!pr.isNull())
    {
        frames.push_back(pr);
        icons.push_back(pr.scaled(64,64,Qt::KeepAspectRatio,Qt::SmoothTransformation));/**/
    }
    updateFrameList();
}
