#ifndef IMAGEWINDOW_H
#define IMAGEWINDOW_H

#include <QMainWindow>
#include "imgwframesmodel.h"
#include "imgwpreview.h"
#include "resourceeditor.h"

namespace Ui {
    class imagewindow;
}

class imagewindow : public QMainWindow, public resourceeditor
{
    friend class imgwFramesModel;
    friend class imgwpreview;
    Q_OBJECT

public:
    explicit imagewindow(QWidget *parent = 0);
    ~imagewindow();
    Ui::imagewindow *ui;

    //resource editor required
    void load();
    void save();

    void setName(QString name);

    //imagewindow specific
    void updateFrameList(bool updatetree=true);
    void nextFrame();

    //image vars:
    int masktype,
     width, height,
     offsetx, offsety,
     bboxleft,bboxright,bboxtop,bboxbottom,
     circleradius,
     scalingmode, previewmode;
    double unitsize;
    bool bitmapcolisionperframe;
    QList<QPixmap> frames, icons;

    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);

protected:
    void changeEvent(QEvent *e);
    void on_cmAsFrame_clicked();
    void on_cmBitmap_clicked();
    void on_cmCircle_clicked();
    void on_cmBox_clicked();

private:
    imgwFramesModel framelist;
    imgwpreview preview;

private slots:
    void on_pmUnits_valueChanged(double );
    void on_comboBox_scaling_activated(int index);
    void on_comboBox_activated(int index);
    void on_toolButton_clicked();
    void on_toolButton_4_clicked();
    void on_actionDelete_selected_triggered();
    void on_offsetY_valueChanged(int );
    void on_offsetX_valueChanged(int );
    void on_imgHeight_valueChanged(int );
    void on_imgWidth_valueChanged(int );
    void on_listWidget_clicked(QModelIndex index);
    void on_toolButton_3_clicked();
    void on_actionLoad_images_triggered();
    void on_actionPaste_triggered();
};

#endif // IMAGEWINDOW_H
