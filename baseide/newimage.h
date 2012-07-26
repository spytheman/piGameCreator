#ifndef NEWIMAGE_H
#define NEWIMAGE_H

#include <QDialog>

namespace Ui {
class newImage;
}

class newImage : public QDialog
{
    Q_OBJECT
    
public:
    explicit newImage(QWidget *parent = 0);
    ~newImage();
    
private:
    Ui::newImage *ui;
private slots:
    void setDialogData();
};

#endif // NEWIMAGE_H
