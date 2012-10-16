#include "imageio.h"
#include "imagepreviewer.h"
#include "globals.h"
#include "qtwin.h"
#include "ui_imagepreviewer.h";
#include <QFileInfo>
#include <QDesktopWidget>
#include <QDesktopServices>
#include <QFileDialog>
#include <QApplication>
#include <QProcess>
#include <QDebug>

bool imageio::isInitialized = false;
QList<imageFormat*> imageio::formats;


void imageio::init()
{
    if(isInitialized)return;
    QProcess im;
    im.start("identify", QStringList() << "-list" << "format");
    im.waitForFinished();
    formats.clear();

    while(!im.atEnd())
    {
        QString line = im.readLine().trimmed();
        //      3FR  r--   Hasselblad CFV/H3D39II
        line.replace("   "," ");
        line.replace("  " ," ");
        //3FR r-- Hasselblad CFV/H3D39II
        QString word1 = line.mid(0, line.indexOf(" "));
        QString word2 = line.mid(word1.length()+1, 3);
        QString desc = line.mid(word1.length()+word2.length()+2);
        bool nbs = word1.contains("*");
        word1.replace("*","");

        // At this stage we can check is this a valid file format description.
        // Word2 must only be in form of [r-][w-][+-].
        bool valid = true, write, read, multi;
        if(word2[0]=='r')read=true;
        else if(word2[0]=='-')read=false;
        else valid=false;
        if(word2[1]=='w')write=true;
        else if(word2[0]=='-')write=false;
        else valid=false;
        if(word2[2]=='+')multi=true;
        else if(word2[2]=='-')multi=false;
        else valid=false;

        if(valid)
        {
            imageFormat* f = new imageFormat;
            f->description = desc;
            f->format = word1;
            f->read = read;
            f->write = write;
            f->multi = multi;
            f->nativeblob = nbs;
            if(desc.toLower().contains("video")) f->warnForHugeData = true;

            //Settings:
            if(f->format=="PDF")f->additionalArgs << "-density" << "1000";

            //Exclusions: TXT files won't be added to the list at all!
            if(f->format!="TXT")
            formats << f;

            QString fDesc = f->format.rightJustified(10,' ',true)+ " "+(f->read?"R":"-") + (f->write?"W":"-") + (f->multi?" M":" -")
                    +" "+f->description;
            qDebug(fDesc.toLocal8Bit());
        }
    }
    isInitialized = true;
}

imageFormat* imageio::getFormat(QString format)
{
    foreach(imageFormat* f, formats)
        if(f->format.toLower()==format.toLower())
            return f;
    return NULL;
}

QList<imageFormat*> imageio::getFormats(bool read, bool write, bool multi)
{
    QList<imageFormat*> res;
    QStringList common;
    common << "PNG" << "BMP" << "TGA" << "JPG" << "PSD" << "XCF" << "ICO" << "GIF" << "MNG";

    foreach(QString s, common)
    {
        imageFormat* f = getFormat(s);
        if(f!=NULL)
        {
            if( (write && f->write) || (read && f->read) ) res << f;
        }
    }
    QHash<QString,imageFormat*>::iterator i;

    foreach(imageFormat* f, formats)
        if(!res.contains(f))
        {
            if( (write && f->write) || (read && f->read) ) res << f;
        }
    return res;
}

QString imageio::getQFileDialogFilterString(bool read, bool write, bool multi)
{
    QString buf;
    QList<imageFormat*> formats = imageio::getFormats(read,write,multi);
    QStringList allformats;
    foreach(imageFormat* f, formats)
    {
        buf.append(f->description + " (*." +f->format + ");;");
        allformats << "*."+f->format;
    }
    buf.append("All files (*)");
    buf.prepend("All supported formats ("+ allformats.join(" ") +");;");
    return buf;
}

QString imageio::getOpenFilename(QString path, bool multi)
{
    QString filter = imageio::getQFileDialogFilterString(true, false, true);
    return QFileDialog::getOpenFileName( qApp->activeWindow(), "Select image file","", filter,0 );
}

QPixmap imageio::loadImage(QString filename)
{
    if(filename=="")return QPixmap();
    ImagePreviewer w( qApp->activeWindow() );
    QWidget* loaderWidget = w.ui->LoaderFrame;
    QRect R = loaderWidget->geometry();
    loaderWidget->setParent( (QWidget*)w.parent());
    loaderWidget->setWindowFlags(Qt::Window | Qt::CustomizeWindowHint );
    loaderWidget->setGeometry(
                QStyle::alignedRect(
                    Qt::LeftToRight,
                    Qt::AlignCenter,
                    R.size(),
                    qApp->desktop()->availableGeometry()
                ));
    loaderWidget->setWindowModality(Qt::ApplicationModal);
    loaderWidget->show();
    QApplication::processEvents();
    //it is now shown

    QString temppath = QDesktopServices::storageLocation(QDesktopServices::TempLocation)+"/imagick";
    QDir d; d.setPath(temppath);
    d.mkpath(d.path());
    if(!d.exists(d.path()))
    {
        //can't create it?
        gcerror("Unable to write to the TEMP directory");
    }

    QString format = "png";
    gcRemoveFiles(d.path(), "frame-*");
    gcRemoveFiles(d.path(), "fullsize-*");

    QString imgp = d.path()+"/frame-%05d."+format;
    QProcess im;
    imageFormat* formatdata = getFormat(format);
    if(!formatdata)gcmessage("Format "+format+ " is not supported but is supported?? Bug?");
    QStringList args;
    im.start("imagick/convert", QStringList() << filename << "-resize" << ">130x10000" << args << imgp);
    im.waitForStarted();
    while(im.state()!=QProcess::NotRunning)
    {
        if(w.cancelled)
        {
            im.kill();
            w.close();
            delete loaderWidget;
            return QPixmap();
        }
        //it is now running:
        QApplication::processEvents();
    }
    QString output = im.readAll();
    qDebug()<<output;
    //It must now be completed
    loaderWidget->hide();
    QFileInfoList files = d.entryInfoList(QStringList()<<"frame-*.*");
    QStringList files2;
    foreach(QFileInfo f,files)files2<<f.absoluteFilePath();
    w.sourceFile = filename;
    w.loadImages(files2);
    // if more than 1 frame, exec it
    if(w.imagesCount>1) w.exec();

    // w.selectedImageIndexes must be exactly one
    if(w.selectedImageIndexes.count() > 1)
    {
        gcerror("Too many selected indexes? Error ... Bug!");
    }
    else if(w.selectedImageIndexes.count()==1)
    {
        return w.getImage(w.selectedImageIndexes.at(0));
        //must load and return this image from previewer's cache!
    }
    else return QPixmap();
}
