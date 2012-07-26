#ifndef IMAGEEDITOR_H
#define IMAGEEDITOR_H

#include <QMainWindow>
#include "../../baseide/resourceeditor.h"

namespace Ui {
class ImageEditor;
}

class ImageEditor : public QMainWindow, public ResourceEditor
{
    Q_OBJECT
    
public:
    explicit ImageEditor(QWidget *parent = 0);
    ~ImageEditor();
    bool init();
    bool save();
    bool saveAs(QString newname);
    bool load();
    bool exportResource(QString filename);
    
private:
    Ui::ImageEditor *ui;
};

#endif // IMAGEEDITOR_H
