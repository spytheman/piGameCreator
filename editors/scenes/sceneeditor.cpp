#include "sceneeditor.h"
#include "ui_sceneeditor.h"
#include "../../sharedcode/resource.h"
#include "../../baseide/gcide.h"
#include "../../sharedcode/idesettings.h"
#include "sceneview.h"

#define UGL if(initialized)ui->TheScene->updateGL();
#define SC ui->TheScene


SceneEditor::SceneEditor(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SceneEditor)
{
    gcprint("Initializing SceneEditor...");
    ui->setupUi(this);

    ui->TheScene->editor=this;

    //Setup the toolbar...and WHY the designer is sooo...
    ui->toolBar->insertWidget(ui->actionZoomOut,ui->GridWidget);
    ui->toolBar->insertSeparator(ui->actionZoomOut);
    ui->toolBar->insertWidget(ui->actionZoomIn,ui->TBZoomWidget);
    ui->toolBar->insertWidget(ui->actionZoomOut,ui->TBViewToolbar);
    ui->toolBar->insertSeparator(ui->actionZoomOut);
    //ui->TheScene->extent=100;

    //hide the matrix view
    ui->Matrix->hide();
    ui->menuBar->hide();

    //setup the rest
    //ui->LBNoObjectSelected->hide();
    ui->GridSettingsWidget->hide();
    ui->PropertiesTW->hide();
    on_actionSelect_objects_triggered();

    //widget = this;
    initResourceEditor(this);
}

void SceneEditor::hideEvent(QHideEvent *)
{
    gcprint(QString("HIDE Init: ")+(initialized?"true":"false"));
    RE_HIDE_EVENT(SCN_EDIT_SETTING_NAME);
    ui->GridSettingsWidget->hide();   
}
void SceneEditor::showEvent(QShowEvent *e)
{
    gcprint(QString("SHOW Init: ")+(initialized?"true":"false"));
    RE_SHOW_EVENT(SCN_EDIT_SETTING_NAME);
    if(ui->toolButton_9->isChecked())ui->GridSettingsWidget->show();
}
void SceneEditor::reloadWindowState()
{
    RE_WINDOW_STATE_LOAD(SCN_EDIT_SETTING_NAME);

    ui->TheScene->resizeGL(ui->TheScene->width(),ui->TheScene->height());
    UGL ;

    ui->actionToolOptions->setChecked(ui->ToolOptionsDockWidget->isVisible());
    ui->actionLayers->setChecked(ui->LayersDockWidget->isVisible());
    ui->actionViews->setChecked(ui->ViewsDockWidget->isVisible());
}

SceneEditor::~SceneEditor()
{
    delete ui;
}

bool SceneEditor::init()
{
    RE_INIT(SCN_EDIT_SETTING_NAME);
    setTitle(resource->name);
    return true;
}

bool SceneEditor::save()
{
    return true;
}

bool SceneEditor::saveAs(QString newname)
{
    return true;
}

bool SceneEditor::load()
{
    return true;
}

bool SceneEditor::exportResource(QString filename)
{
    return true;
}


void SceneEditor::unselectTools()
{
    ui->actionSelect_objects->setChecked(0);
    ui->actionRectangle_tool->setChecked(0);
    ui->actionDraw_objects->setChecked(0);
    ui->actionPolygon_path_tool->setChecked(0);
    ui->actionGraph_tool->setChecked(0);
    ui->actionTerrain_tool->setChecked(0);
}

void SceneEditor::on_actionSelect_objects_triggered()
{
    unselectTools();
    ui->actionSelect_objects->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->pgObjectInspector);
    SC->toolmode=0;
}

void SceneEditor::on_actionDraw_objects_triggered()
{
    unselectTools();
    ui->actionDraw_objects->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->pgDrawObjects);
    SC->toolmode=1;
}

void SceneEditor::on_actionRectangle_tool_triggered()
{
    unselectTools();
    ui->actionRectangle_tool->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->pgRectangleOptions);
    SC->toolmode=2;
}

void SceneEditor::on_actionPolygon_path_tool_triggered()
{
    unselectTools();
    ui->actionPolygon_path_tool->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->pgPathOptions);
    SC->toolmode=3;
}

void SceneEditor::on_actionGraph_tool_triggered()
{
    unselectTools();
    ui->actionGraph_tool->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->pgGraphOptions);
    SC->toolmode=4;
}

void SceneEditor::on_actionTerrain_tool_triggered()
{
    unselectTools();
    ui->actionTerrain_tool->setChecked(1);
    ui->ToolOptionsSW->setCurrentWidget(ui->pgTerrainOptions);
    SC->toolmode=5;
}

void SceneEditor::on_WidthSB_valueChanged(int i)
{
    int x = SC->extent*2 + i*SC->zoom - ui->TheScene->width(); if(x<0)x=0;
    SC->ww=i;UGL
}
void SceneEditor::on_HeightSB_valueChanged(int i)
{
    int y = SC->extent*2 + i*SC->zoom - ui->TheScene->height(); if(y<0)y=0;
    SC->hh=i;UGL
}
bool SceneEditor::loadScene()
{
}


void SceneEditor::on_actionToolOptions_triggered(bool checked)
{
    ui->ToolOptionsDockWidget->setVisible(checked);
}

void SceneEditor::on_actionLayers_triggered(bool checked)
{
    ui->LayersDockWidget->setVisible(checked);
}

void SceneEditor::on_actionViews_triggered(bool checked)
{
    ui->ViewsDockWidget->setVisible(checked);
}


void SceneEditor::on_action100percent_triggered()
{
    restoreState( creatorIDE->settings->value("SceneEditor/State").toByteArray() );
}

