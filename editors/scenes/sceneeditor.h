#ifndef SCENEEDITOR_H
#define SCENEEDITOR_H

#include <QTimer>
#include <QMainWindow>
#include "../../baseide/resourceeditor.h"
class sceneview;

namespace Ui {
class SceneEditor;
}

class SceneEditor : public QMainWindow, public ResourceEditor
{
    Q_OBJECT
    
public:
    explicit SceneEditor(QWidget *parent = 0);
    ~SceneEditor();

    bool init();
    bool save();
    bool saveAs(QString newname);
    bool load();
    bool exportResource(QString filename);
    void unselectTools();
    void setGridColor(QColor c);
    void setGridAlpha(float a); //0...1

    //SceneEditor specific
    bool initialized;
    void showEvent(QShowEvent *);
    void hideEvent(QHideEvent *);

    //Converts the layer data for rendering and editing
    bool loadScene();

public slots:
    void on_actionGraph_tool_triggered();
    void on_actionPolygon_path_tool_triggered();
    void on_actionRectangle_tool_triggered();
    void on_actionDraw_objects_triggered();
    void on_actionSelect_objects_triggered();
    void on_HeightSB_valueChanged(int);
    void on_WidthSB_valueChanged(int);
    void on_actionLayers_triggered(bool checked);
    void on_actionToolOptions_triggered(bool checked);
    void on_actionViews_triggered(bool checked);
    void updateViewport();

private slots:
    void on_action100percent_triggered();
    void on_actionTerrain_tool_triggered();


private:
    Ui::SceneEditor *ui;
    QTimer updateTimer;
};

#endif // SCENEEDITOR_H
