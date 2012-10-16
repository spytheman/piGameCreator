#ifndef IMAGEIO_H
#define IMAGEIO_H

#include <QPixmap>

struct imageFormat
{
    QString format, description;
    bool read,write,multi,nativeblob;
    bool warnForHugeData;
    QStringList additionalArgs;
};

class imageio
{
public:
     static void init();

     static QPixmap loadImage(QString filename);
     static QList<QPixmap> loadAllImages(QString filename);
     static QList<QPixmap> loadSomeImages(QString filename);
     static bool savePixmap(QPixmap pixmap, QString filename);
     static bool savePixmaps(QList<QPixmap> frames, QString filename);

     //multi means that format can save/load more than 1 frame - like GIF
     static QString getOpenFilename(QString path, bool multi=true);
     static QStringList getOpenFilenames(QString path, bool multi=true);
     static QString getSaveFilename(QString path, bool multi=false);

     //and some lists to keep the format specs:
     static QList<imageFormat*> formats;
     static imageFormat* getFormat(QString format);
     static bool isInitialized;
     static QList<imageFormat*> getFormats(bool read, bool write, bool multi);
     static QString getQFileDialogFilterString(bool read, bool write, bool multi);

};

#endif // IMAGEIO_H
