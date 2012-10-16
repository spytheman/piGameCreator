#ifndef IMAGEPREVIEWER_H
#define IMAGEPREVIEWER_H

#include <QPixmap>
#include <QDialog>
#include <QListWidgetItem>
#include <QGraphicsScene>

namespace Ui {
class ImagePreviewer;
}

class ImagePreviewer : public QDialog
{
    Q_OBJECT
    
public:
    explicit ImagePreviewer(QWidget *parent = 0);
    ~ImagePreviewer();
    QString sourceFile;
    void loadImages(QStringList files);
    void setMultiMode();
    void setSingleMode();
    QList<int> selectedImageIndexes;
    int imagesCount;
    QPixmap getImage(int index);
    bool cancelled;
    
    Ui::ImagePreviewer *ui;
private slots:
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

    void on_statusCancelButton_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

private:
    bool multiMode;
    QGraphicsScene* imagePreview;
};

#endif // IMAGEPREVIEWER_H
