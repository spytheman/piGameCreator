#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include <QMainWindow>
#include <QListWidgetItem>
#include <QTreeWidgetItem>
#include "resourceeditor.h"
#include "srcScene/sceneview.h"

namespace Ui {
    class SceneEditor;
}

class SceneEditor : public QMainWindow, public resourceeditor
{
    friend class SceneView;
    Q_OBJECT

public:
    explicit SceneEditor(QWidget *parent = 0);
    ~SceneEditor();

    void save();
    void savelayer(layer* l,QDomElement container ); //saves a layer FROM the scene / Recursive
    void load();
    void loadScene();

    void showEvent(QShowEvent *e);
    void hideEvent(QHideEvent *e);
    void closeEvent(QCloseEvent *e);
    QByteArray test;
    void loadClasses();

protected:
    void changeEvent(QEvent *e);

private:
    QColor gridcolor;
    Ui::SceneEditor *ui;
    void unselectTools();
    void setGridColor(QColor c);
    void setGridAlpha(float a); //0...1
private slots:
    void on_actionViews_triggered(bool checked);
    void on_gridDrawCheckBox_clicked(bool checked);
    void on_GridSnapCheckbox_clicked(bool checked);
    void on_GridAlphaSlider_valueChanged(int value);
    void on_colorButton_clicked();
    void on_TBgridToolButton_clicked(bool checked);
    void on_GridYSB_valueChanged(int );
    void on_GridXSB_valueChanged(int );
    void on_GridHSB_valueChanged(int );
    void on_GridWSB_valueChanged(int );
    void on_actionPaths_triggered(bool checked);
    void on_actionShowGrid_triggered();
    void on_actionHideGrid_triggered();
    void on_actionGrid_settings_triggered();
    void on_verticalScrollBar_valueChanged(int value);
    void on_horizontalScrollBar_valueChanged(int value);
    void on_AllClassesLW_itemClicked(QListWidgetItem* item);
    void on_AllClassesLE_textChanged(QString s);
    void on_actionPolygon_path_tool_triggered();
    void on_actionRectangle_tool_triggered();
    void on_actionDraw_objects_triggered();
    void on_actionSelect_objects_triggered();
    void on_actionLayers_triggered(bool checked);
    void on_actionToolOptions_triggered(bool checked);
    void on_actionClasses_triggered(bool checked);
    void on_HeightSB_valueChanged(int );
    void on_WidthSB_valueChanged(int );
    void on_horizontalSlider_valueChanged(int value);
    void on_action100percent_triggered();
    void on_actionZoomIn_triggered();
    void on_actionZoomOut_triggered();
    void on_LayersTW_itemClicked(QTreeWidgetItem *item, int column);
    void on_DefaultMatrix_clicked();
    void on_toolButton_8_clicked(bool checked);
    void on_toolButton_9_clicked();
    void on_actionGraph_tool_triggered();
    void gridclosed(QWidget* w);
    void gridmenu();
};

#endif // SCENEEDITOR_H
