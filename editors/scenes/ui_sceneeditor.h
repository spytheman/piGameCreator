/********************************************************************************
** Form generated from reading UI file 'sceneeditor.ui'
**
** Created: Sun 12. Aug 04:54:15 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEEDITOR_H
#define UI_SCENEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDockWidget>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <qwidgetwithclosesignal.h>
#include <sceneview.h>

QT_BEGIN_NAMESPACE

class Ui_SceneEditor
{
public:
    QAction *actionLayers;
    QAction *actionZoomIn;
    QAction *actionZoomOut;
    QAction *action100percent;
    QAction *actionGrid_settings;
    QAction *actionDraw_objects;
    QAction *actionSelect_objects;
    QAction *actionRectangle_tool;
    QAction *actionPolygon_path_tool;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionGet_object_tool;
    QAction *actionToolOptions;
    QAction *actionViews;
    QAction *actionGraph_tool;
    QAction *actionTerrain_tool;
    QAction *actionX_Y;
    QAction *actionX_Z;
    QAction *actionY_Z_side;
    QAction *actionPick_plane;
    QAction *actionX_Y_Top_down;
    QAction *actionX_Z_Side;
    QAction *actionY_Z_side_2;
    QAction *actionPick_plane_2;
    QAction *actionPerspective;
    QAction *actionParallel;
    QAction *actionQuad_view;
    QAction *actionSave_view;
    QAction *actionImport_views;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    sceneview *TheScene;
    QWidgetWithCloseSignal *GridSettingsWidget;
    QVBoxLayout *verticalLayout_13;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QSpacerItem *verticalSpacer_2;
    QFrame *line_3;
    QStackedWidget *GridStackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_21;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QSpinBox *GridWSB;
    QLabel *label_7;
    QSpinBox *GridHSB;
    QSpacerItem *horizontalSpacer_8;
    QHBoxLayout *horizontalLayout_12;
    QToolButton *toolButton_7;
    QToolButton *toolButton_6;
    QLabel *label_8;
    QSpinBox *GridXSB;
    QLabel *label_9;
    QSpinBox *GridYSB;
    QPushButton *colorButton;
    QSlider *GridAlphaSlider;
    QWidget *page_2;
    QWidget *Matrix;
    QGridLayout *gridLayout_5;
    QDoubleSpinBox *m11;
    QDoubleSpinBox *m12;
    QDoubleSpinBox *m13;
    QDoubleSpinBox *m14;
    QDoubleSpinBox *m21;
    QDoubleSpinBox *m31;
    QDoubleSpinBox *m41;
    QDoubleSpinBox *m22;
    QDoubleSpinBox *m23;
    QDoubleSpinBox *m24;
    QDoubleSpinBox *m32;
    QDoubleSpinBox *m33;
    QDoubleSpinBox *m34;
    QDoubleSpinBox *m42;
    QDoubleSpinBox *m43;
    QDoubleSpinBox *m44;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *DefaultMatrix;
    QWidget *GridWidget;
    QHBoxLayout *horizontalLayout_11;
    QToolButton *TBgridToolButton;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QWidget *TBViewToolbar;
    QHBoxLayout *horizontalLayout_18;
    QToolButton *TBView2d;
    QToolButton *TBView25d;
    QToolButton *TBView3d;
    QToolButton *TBView3d_2;
    QWidget *TBZoomWidget;
    QHBoxLayout *horizontalLayout_3;
    QSlider *horizontalSlider;
    QToolBar *toolBar;
    QDockWidget *LayersDockWidget;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *LayersTW;
    QFrame *line;
    QFrame *ButtonsFrame;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_4;
    QToolButton *toolButton_5;
    QToolButton *toolButton;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_3;
    QToolButton *toolButton_2;
    QDockWidget *ToolOptionsDockWidget;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_8;
    QStackedWidget *ToolOptionsSW;
    QWidget *pgObjectInspector;
    QVBoxLayout *verticalLayout_17;
    QFrame *panelSelectToolOptions;
    QVBoxLayout *verticalLayout_9;
    QTreeWidget *PropertiesTW;
    QLabel *LBNoObjectSelected;
    QWidget *pgDrawObjects;
    QVBoxLayout *verticalLayout_18;
    QFrame *panelPencilOptions;
    QVBoxLayout *verticalLayout_10;
    QCheckBox *FreeDrawing;
    QCheckBox *DelUnderlying;
    QSpacerItem *verticalSpacer_3;
    QWidget *pgRectangleOptions;
    QVBoxLayout *verticalLayout_19;
    QFrame *panelRectangleOptions;
    QVBoxLayout *verticalLayout_12;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_10;
    QCheckBox *rectSnapToGrid;
    QPushButton *pushButton_3;
    QSpacerItem *verticalSpacer_4;
    QWidget *pgPathOptions;
    QVBoxLayout *verticalLayout_20;
    QFrame *panelPathOptions;
    QVBoxLayout *verticalLayout_11;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *checkBox;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_10;
    QToolButton *toolButton_11;
    QToolButton *toolButton_12;
    QSpacerItem *horizontalSpacer_5;
    QFrame *line_5;
    QTreeWidget *pathsTW;
    QFrame *line_4;
    QFrame *ButtonsFrame_2;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *path_new;
    QToolButton *path_delete;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *path_save;
    QToolButton *path_load;
    QWidget *pgGraphOptions;
    QVBoxLayout *verticalLayout_22;
    QFrame *GraphFrame;
    QVBoxLayout *verticalLayout_25;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_3;
    QHBoxLayout *horizontalLayout_14;
    QSpacerItem *horizontalSpacer_10;
    QToolButton *toolButton_13;
    QToolButton *toolButton_24;
    QSpacerItem *horizontalSpacer_12;
    QFrame *frame_6;
    QVBoxLayout *verticalLayout_23;
    QFrame *line_7;
    QTreeWidget *GraphsTW;
    QFrame *line_6;
    QFrame *ButtonsFrame_5;
    QHBoxLayout *horizontalLayout_13;
    QToolButton *graph_new;
    QToolButton *graph_delete;
    QSpacerItem *horizontalSpacer_11;
    QToolButton *graph_save;
    QToolButton *graph_load;
    QWidget *pgTerrainOptions;
    QVBoxLayout *verticalLayout_7;
    QFormLayout *formLayout;
    QLabel *label_3;
    QComboBox *comboBox;
    QStackedWidget *terrainOptionsSW;
    QWidget *pgTerrainOptionsNotSelected;
    QVBoxLayout *verticalLayout_15;
    QLabel *label_10;
    QLabel *label_11;
    QCheckBox *checkBox_2;
    QFrame *line_9;
    QLabel *label_12;
    QCommandLinkButton *commandLinkButton;
    QSpacerItem *verticalSpacer_5;
    QWidget *pgTHeightmap;
    QVBoxLayout *verticalLayout_14;
    QGridLayout *gridLayout_4;
    QToolButton *toolButton_16;
    QToolButton *toolButton_17;
    QToolButton *toolButton_18;
    QToolButton *toolButton_19;
    QToolButton *toolButton_21;
    QToolButton *toolButton_20;
    QFrame *line_10;
    QStackedWidget *HeightMapTerrainTools;
    QWidget *pgHmTHeight;
    QVBoxLayout *verticalLayout_24;
    QGridLayout *gridLayout_6;
    QLabel *label_13;
    QSlider *HMTBrushSizeSlider;
    QDoubleSpinBox *doubleSpinBox;
    QLabel *label_14;
    QLabel *label_15;
    QSlider *HMTsoftnessSlider;
    QDoubleSpinBox *doubleSpinBox_2;
    QLabel *label_16;
    QHBoxLayout *horizontalLayout_16;
    QLabel *label_17;
    QSlider *horizontalSlider_2;
    QLabel *label_18;
    QSpacerItem *verticalSpacer_6;
    QWidget *pgHmTSmooth;
    QVBoxLayout *verticalLayout_26;
    QGridLayout *gridLayout_7;
    QLabel *label_19;
    QSlider *HMTBrushSizeSlider_2;
    QDoubleSpinBox *doubleSpinBox_3;
    QLabel *label_20;
    QSpacerItem *verticalSpacer_7;
    QWidget *pgHmTFlatten;
    QVBoxLayout *verticalLayout_27;
    QGridLayout *gridLayout_8;
    QLabel *label_21;
    QSlider *HMTBrushSizeSlider_3;
    QDoubleSpinBox *doubleSpinBox_4;
    QLabel *label_22;
    QToolButton *view_new_3;
    QHBoxLayout *horizontalLayout_19;
    QLabel *label_28;
    QSlider *horizontalSlider_3;
    QSpinBox *spinBox;
    QLabel *label_29;
    QSpacerItem *verticalSpacer_8;
    QWidget *pgHmTPaint;
    QVBoxLayout *verticalLayout_28;
    QGridLayout *gridLayout_9;
    QLabel *label_23;
    QSlider *HMTBrushSizeSlider_4;
    QDoubleSpinBox *doubleSpinBox_5;
    QLabel *label_24;
    QLabel *label_25;
    QSlider *HMTsoftnessSlider_2;
    QDoubleSpinBox *doubleSpinBox_6;
    QLabel *label_26;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_29;
    QTreeWidget *ViewsTW_2;
    QFrame *line_11;
    QFrame *ButtonsFrame_4;
    QHBoxLayout *horizontalLayout_17;
    QToolButton *view_new_2;
    QToolButton *view_delete_3;
    QToolButton *view_delete_2;
    QSpacerItem *horizontalSpacer_13;
    QToolButton *toolButton_22;
    QToolButton *toolButton_23;
    QWidget *pgHmTOther;
    QWidget *pgHmTOptions;
    QVBoxLayout *verticalLayout_31;
    QGridLayout *gridLayout_15;
    QPushButton *pushButton_4;
    QPushButton *pushButton_8;
    QLabel *label_45;
    QLabel *label_44;
    QFrame *line_8;
    QFormLayout *formLayout_2;
    QLabel *label_4;
    QLabel *label_6;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QSpacerItem *verticalSpacer_10;
    QWidget *pgTVoxel;
    QVBoxLayout *verticalLayout_30;
    QLabel *label_27;
    QSpacerItem *verticalSpacer_9;
    QWidget *pgCSGOptions;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer;
    QWidget *page_5;
    QDockWidget *ViewsDockWidget;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_16;
    QTreeWidget *ViewsTW;
    QFrame *line_2;
    QFrame *ButtonsFrame_3;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *view_new;
    QToolButton *view_delete;
    QSpacerItem *horizontalSpacer_7;
    QToolButton *toolButton_14;
    QToolButton *toolButton_15;
    QMenuBar *menuBar;
    QMenu *menu2D;
    QMenu *menu25D;
    QMenu *menu3D;
    QMenu *menuViews;

    void setupUi(QMainWindow *SceneEditor)
    {
        if (SceneEditor->objectName().isEmpty())
            SceneEditor->setObjectName(QString::fromUtf8("SceneEditor"));
        SceneEditor->resize(770, 615);
        actionLayers = new QAction(SceneEditor);
        actionLayers->setObjectName(QString::fromUtf8("actionLayers"));
        actionLayers->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/application_double.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLayers->setIcon(icon);
        actionZoomIn = new QAction(SceneEditor);
        actionZoomIn->setObjectName(QString::fromUtf8("actionZoomIn"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/magnifier_zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomIn->setIcon(icon1);
        actionZoomOut = new QAction(SceneEditor);
        actionZoomOut->setObjectName(QString::fromUtf8("actionZoomOut"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/magifier_zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionZoomOut->setIcon(icon2);
        action100percent = new QAction(SceneEditor);
        action100percent->setObjectName(QString::fromUtf8("action100percent"));
        actionGrid_settings = new QAction(SceneEditor);
        actionGrid_settings->setObjectName(QString::fromUtf8("actionGrid_settings"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/cog.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGrid_settings->setIcon(icon3);
        actionDraw_objects = new QAction(SceneEditor);
        actionDraw_objects->setObjectName(QString::fromUtf8("actionDraw_objects"));
        actionDraw_objects->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDraw_objects->setIcon(icon4);
        actionSelect_objects = new QAction(SceneEditor);
        actionSelect_objects->setObjectName(QString::fromUtf8("actionSelect_objects"));
        actionSelect_objects->setCheckable(true);
        actionSelect_objects->setChecked(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/cursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelect_objects->setIcon(icon5);
        actionRectangle_tool = new QAction(SceneEditor);
        actionRectangle_tool->setObjectName(QString::fromUtf8("actionRectangle_tool"));
        actionRectangle_tool->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/shape_handles.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle_tool->setIcon(icon6);
        actionPolygon_path_tool = new QAction(SceneEditor);
        actionPolygon_path_tool->setObjectName(QString::fromUtf8("actionPolygon_path_tool"));
        actionPolygon_path_tool->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/vector.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPolygon_path_tool->setIcon(icon7);
        actionCopy = new QAction(SceneEditor);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon8);
        actionPaste = new QAction(SceneEditor);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon9);
        actionCut = new QAction(SceneEditor);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/resources/RES/ffficons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon10);
        actionGet_object_tool = new QAction(SceneEditor);
        actionGet_object_tool->setObjectName(QString::fromUtf8("actionGet_object_tool"));
        actionGet_object_tool->setCheckable(true);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/resources/RES/pipetka.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGet_object_tool->setIcon(icon11);
        actionToolOptions = new QAction(SceneEditor);
        actionToolOptions->setObjectName(QString::fromUtf8("actionToolOptions"));
        actionToolOptions->setCheckable(true);
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/resources/RES/checks.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionToolOptions->setIcon(icon12);
        actionViews = new QAction(SceneEditor);
        actionViews->setObjectName(QString::fromUtf8("actionViews"));
        actionViews->setCheckable(true);
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/resources/RES/ffficons/webcam.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionViews->setIcon(icon13);
        actionGraph_tool = new QAction(SceneEditor);
        actionGraph_tool->setObjectName(QString::fromUtf8("actionGraph_tool"));
        actionGraph_tool->setCheckable(true);
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/resources/RES/ffficons/chart_organisation.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGraph_tool->setIcon(icon14);
        actionTerrain_tool = new QAction(SceneEditor);
        actionTerrain_tool->setObjectName(QString::fromUtf8("actionTerrain_tool"));
        actionTerrain_tool->setCheckable(true);
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/resources/RES/terrain.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTerrain_tool->setIcon(icon15);
        actionX_Y = new QAction(SceneEditor);
        actionX_Y->setObjectName(QString::fromUtf8("actionX_Y"));
        actionX_Z = new QAction(SceneEditor);
        actionX_Z->setObjectName(QString::fromUtf8("actionX_Z"));
        actionY_Z_side = new QAction(SceneEditor);
        actionY_Z_side->setObjectName(QString::fromUtf8("actionY_Z_side"));
        actionPick_plane = new QAction(SceneEditor);
        actionPick_plane->setObjectName(QString::fromUtf8("actionPick_plane"));
        actionX_Y_Top_down = new QAction(SceneEditor);
        actionX_Y_Top_down->setObjectName(QString::fromUtf8("actionX_Y_Top_down"));
        actionX_Z_Side = new QAction(SceneEditor);
        actionX_Z_Side->setObjectName(QString::fromUtf8("actionX_Z_Side"));
        actionY_Z_side_2 = new QAction(SceneEditor);
        actionY_Z_side_2->setObjectName(QString::fromUtf8("actionY_Z_side_2"));
        actionPick_plane_2 = new QAction(SceneEditor);
        actionPick_plane_2->setObjectName(QString::fromUtf8("actionPick_plane_2"));
        actionPerspective = new QAction(SceneEditor);
        actionPerspective->setObjectName(QString::fromUtf8("actionPerspective"));
        actionParallel = new QAction(SceneEditor);
        actionParallel->setObjectName(QString::fromUtf8("actionParallel"));
        actionQuad_view = new QAction(SceneEditor);
        actionQuad_view->setObjectName(QString::fromUtf8("actionQuad_view"));
        actionSave_view = new QAction(SceneEditor);
        actionSave_view->setObjectName(QString::fromUtf8("actionSave_view"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/resources/RES/ffficons/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave_view->setIcon(icon16);
        actionImport_views = new QAction(SceneEditor);
        actionImport_views->setObjectName(QString::fromUtf8("actionImport_views"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImport_views->setIcon(icon17);
        centralwidget = new QWidget(SceneEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Sunken);
        verticalLayout = new QVBoxLayout(frame_2);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
#ifndef Q_OS_MAC
        gridLayout->setContentsMargins(0, 0, 0, 0);
#endif
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        TheScene = new sceneview(frame_2);
        TheScene->setObjectName(QString::fromUtf8("TheScene"));
        GridSettingsWidget = new QWidgetWithCloseSignal(TheScene);
        GridSettingsWidget->setObjectName(QString::fromUtf8("GridSettingsWidget"));
        GridSettingsWidget->setGeometry(QRect(18, 18, 211, 127));
        verticalLayout_13 = new QVBoxLayout(GridSettingsWidget);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setContentsMargins(6, 6, 6, 6);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        radioButton = new QRadioButton(GridSettingsWidget);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout_13->addWidget(radioButton);

        radioButton_2 = new QRadioButton(GridSettingsWidget);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setEnabled(false);

        verticalLayout_13->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(GridSettingsWidget);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        radioButton_3->setEnabled(false);

        verticalLayout_13->addWidget(radioButton_3);

        verticalSpacer_2 = new QSpacerItem(20, 3, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_13->addItem(verticalSpacer_2);

        line_3 = new QFrame(GridSettingsWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_13->addWidget(line_3);

        GridStackedWidget = new QStackedWidget(GridSettingsWidget);
        GridStackedWidget->setObjectName(QString::fromUtf8("GridStackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_21 = new QVBoxLayout(page);
        verticalLayout_21->setSpacing(0);
        verticalLayout_21->setContentsMargins(0, 0, 0, 0);
        verticalLayout_21->setObjectName(QString::fromUtf8("verticalLayout_21"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setHorizontalSpacing(2);
        gridLayout_2->setVerticalSpacing(4);
        gridLayout_2->setContentsMargins(-1, 6, -1, 4);
        label_5 = new QLabel(page);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_5, 0, 0, 1, 1);

        GridWSB = new QSpinBox(page);
        GridWSB->setObjectName(QString::fromUtf8("GridWSB"));
        GridWSB->setMaximum(999);
        GridWSB->setValue(16);

        gridLayout_2->addWidget(GridWSB, 0, 1, 1, 1);

        label_7 = new QLabel(page);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_7, 0, 2, 1, 1);

        GridHSB = new QSpinBox(page);
        GridHSB->setObjectName(QString::fromUtf8("GridHSB"));
        GridHSB->setMaximum(999);
        GridHSB->setValue(16);

        gridLayout_2->addWidget(GridHSB, 0, 3, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_8, 0, 4, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        toolButton_7 = new QToolButton(page);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        toolButton_7->setIcon(icon16);
        toolButton_7->setAutoRaise(true);

        horizontalLayout_12->addWidget(toolButton_7);

        toolButton_6 = new QToolButton(page);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        toolButton_6->setIcon(icon17);
        toolButton_6->setAutoRaise(true);

        horizontalLayout_12->addWidget(toolButton_6);


        gridLayout_2->addLayout(horizontalLayout_12, 0, 5, 1, 1);

        label_8 = new QLabel(page);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_8, 1, 0, 1, 1);

        GridXSB = new QSpinBox(page);
        GridXSB->setObjectName(QString::fromUtf8("GridXSB"));
        GridXSB->setMaximum(999);

        gridLayout_2->addWidget(GridXSB, 1, 1, 1, 1);

        label_9 = new QLabel(page);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        sizePolicy.setHeightForWidth(label_9->sizePolicy().hasHeightForWidth());
        label_9->setSizePolicy(sizePolicy);

        gridLayout_2->addWidget(label_9, 1, 2, 1, 1);

        GridYSB = new QSpinBox(page);
        GridYSB->setObjectName(QString::fromUtf8("GridYSB"));
        GridYSB->setMaximum(999);

        gridLayout_2->addWidget(GridYSB, 1, 3, 1, 1);

        colorButton = new QPushButton(page);
        colorButton->setObjectName(QString::fromUtf8("colorButton"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(colorButton->sizePolicy().hasHeightForWidth());
        colorButton->setSizePolicy(sizePolicy1);

        gridLayout_2->addWidget(colorButton, 1, 4, 1, 1);

        GridAlphaSlider = new QSlider(page);
        GridAlphaSlider->setObjectName(QString::fromUtf8("GridAlphaSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(GridAlphaSlider->sizePolicy().hasHeightForWidth());
        GridAlphaSlider->setSizePolicy(sizePolicy2);
        GridAlphaSlider->setMaximum(255);
        GridAlphaSlider->setSingleStep(10);
        GridAlphaSlider->setPageStep(20);
        GridAlphaSlider->setValue(60);
        GridAlphaSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(GridAlphaSlider, 1, 5, 1, 1);


        verticalLayout_21->addLayout(gridLayout_2);

        GridStackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        GridStackedWidget->addWidget(page_2);

        verticalLayout_13->addWidget(GridStackedWidget);

        Matrix = new QWidget(TheScene);
        Matrix->setObjectName(QString::fromUtf8("Matrix"));
        Matrix->setGeometry(QRect(18, 150, 242, 111));
        gridLayout_5 = new QGridLayout(Matrix);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setContentsMargins(3, 3, 3, 3);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        m11 = new QDoubleSpinBox(Matrix);
        m11->setObjectName(QString::fromUtf8("m11"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(m11->sizePolicy().hasHeightForWidth());
        m11->setSizePolicy(sizePolicy3);
        m11->setMaximumSize(QSize(60, 16777215));
        m11->setDecimals(4);
        m11->setMinimum(-1e+06);
        m11->setMaximum(1e+06);
        m11->setSingleStep(0.5);
        m11->setValue(1);

        gridLayout_5->addWidget(m11, 0, 0, 1, 1);

        m12 = new QDoubleSpinBox(Matrix);
        m12->setObjectName(QString::fromUtf8("m12"));
        sizePolicy3.setHeightForWidth(m12->sizePolicy().hasHeightForWidth());
        m12->setSizePolicy(sizePolicy3);
        m12->setMaximumSize(QSize(60, 16777215));
        m12->setDecimals(4);
        m12->setMinimum(-1e+06);
        m12->setMaximum(1e+06);
        m12->setSingleStep(0.5);

        gridLayout_5->addWidget(m12, 0, 1, 1, 1);

        m13 = new QDoubleSpinBox(Matrix);
        m13->setObjectName(QString::fromUtf8("m13"));
        sizePolicy3.setHeightForWidth(m13->sizePolicy().hasHeightForWidth());
        m13->setSizePolicy(sizePolicy3);
        m13->setMaximumSize(QSize(60, 16777215));
        m13->setDecimals(4);
        m13->setMinimum(-1e+06);
        m13->setMaximum(1e+06);
        m13->setSingleStep(0.5);

        gridLayout_5->addWidget(m13, 0, 2, 1, 1);

        m14 = new QDoubleSpinBox(Matrix);
        m14->setObjectName(QString::fromUtf8("m14"));
        sizePolicy3.setHeightForWidth(m14->sizePolicy().hasHeightForWidth());
        m14->setSizePolicy(sizePolicy3);
        m14->setMaximumSize(QSize(60, 16777215));
        m14->setDecimals(4);
        m14->setMinimum(-1e+06);
        m14->setMaximum(1e+06);
        m14->setSingleStep(0.5);

        gridLayout_5->addWidget(m14, 0, 3, 1, 1);

        m21 = new QDoubleSpinBox(Matrix);
        m21->setObjectName(QString::fromUtf8("m21"));
        sizePolicy3.setHeightForWidth(m21->sizePolicy().hasHeightForWidth());
        m21->setSizePolicy(sizePolicy3);
        m21->setMaximumSize(QSize(60, 16777215));
        m21->setDecimals(4);
        m21->setMinimum(-1e+06);
        m21->setMaximum(1e+06);
        m21->setSingleStep(0.5);

        gridLayout_5->addWidget(m21, 1, 0, 1, 1);

        m31 = new QDoubleSpinBox(Matrix);
        m31->setObjectName(QString::fromUtf8("m31"));
        sizePolicy3.setHeightForWidth(m31->sizePolicy().hasHeightForWidth());
        m31->setSizePolicy(sizePolicy3);
        m31->setMaximumSize(QSize(60, 16777215));
        m31->setDecimals(4);
        m31->setMinimum(-1e+06);
        m31->setMaximum(1e+06);
        m31->setSingleStep(0.5);

        gridLayout_5->addWidget(m31, 2, 0, 1, 1);

        m41 = new QDoubleSpinBox(Matrix);
        m41->setObjectName(QString::fromUtf8("m41"));
        sizePolicy3.setHeightForWidth(m41->sizePolicy().hasHeightForWidth());
        m41->setSizePolicy(sizePolicy3);
        m41->setMaximumSize(QSize(60, 16777215));
        m41->setDecimals(4);
        m41->setMinimum(-1e+06);
        m41->setMaximum(1e+06);
        m41->setSingleStep(0.5);

        gridLayout_5->addWidget(m41, 3, 0, 1, 1);

        m22 = new QDoubleSpinBox(Matrix);
        m22->setObjectName(QString::fromUtf8("m22"));
        sizePolicy3.setHeightForWidth(m22->sizePolicy().hasHeightForWidth());
        m22->setSizePolicy(sizePolicy3);
        m22->setMaximumSize(QSize(60, 16777215));
        m22->setDecimals(4);
        m22->setMinimum(-1e+06);
        m22->setMaximum(1e+06);
        m22->setSingleStep(0.5);
        m22->setValue(1);

        gridLayout_5->addWidget(m22, 1, 1, 1, 1);

        m23 = new QDoubleSpinBox(Matrix);
        m23->setObjectName(QString::fromUtf8("m23"));
        sizePolicy3.setHeightForWidth(m23->sizePolicy().hasHeightForWidth());
        m23->setSizePolicy(sizePolicy3);
        m23->setMaximumSize(QSize(60, 16777215));
        m23->setDecimals(4);
        m23->setMinimum(-1e+06);
        m23->setMaximum(1e+06);
        m23->setSingleStep(0.5);

        gridLayout_5->addWidget(m23, 1, 2, 1, 1);

        m24 = new QDoubleSpinBox(Matrix);
        m24->setObjectName(QString::fromUtf8("m24"));
        sizePolicy3.setHeightForWidth(m24->sizePolicy().hasHeightForWidth());
        m24->setSizePolicy(sizePolicy3);
        m24->setMaximumSize(QSize(60, 16777215));
        m24->setDecimals(4);
        m24->setMinimum(-1e+06);
        m24->setMaximum(1e+06);
        m24->setSingleStep(0.5);

        gridLayout_5->addWidget(m24, 1, 3, 1, 1);

        m32 = new QDoubleSpinBox(Matrix);
        m32->setObjectName(QString::fromUtf8("m32"));
        sizePolicy3.setHeightForWidth(m32->sizePolicy().hasHeightForWidth());
        m32->setSizePolicy(sizePolicy3);
        m32->setMaximumSize(QSize(60, 16777215));
        m32->setDecimals(4);
        m32->setMinimum(-1e+06);
        m32->setMaximum(1e+06);
        m32->setSingleStep(0.5);

        gridLayout_5->addWidget(m32, 2, 1, 1, 1);

        m33 = new QDoubleSpinBox(Matrix);
        m33->setObjectName(QString::fromUtf8("m33"));
        sizePolicy3.setHeightForWidth(m33->sizePolicy().hasHeightForWidth());
        m33->setSizePolicy(sizePolicy3);
        m33->setMaximumSize(QSize(60, 16777215));
        m33->setDecimals(4);
        m33->setMinimum(-1e+06);
        m33->setMaximum(1e+06);
        m33->setSingleStep(0.5);
        m33->setValue(1);

        gridLayout_5->addWidget(m33, 2, 2, 1, 1);

        m34 = new QDoubleSpinBox(Matrix);
        m34->setObjectName(QString::fromUtf8("m34"));
        sizePolicy3.setHeightForWidth(m34->sizePolicy().hasHeightForWidth());
        m34->setSizePolicy(sizePolicy3);
        m34->setMaximumSize(QSize(60, 16777215));
        m34->setDecimals(4);
        m34->setMinimum(-1e+06);
        m34->setMaximum(1e+06);
        m34->setSingleStep(0.5);

        gridLayout_5->addWidget(m34, 2, 3, 1, 1);

        m42 = new QDoubleSpinBox(Matrix);
        m42->setObjectName(QString::fromUtf8("m42"));
        sizePolicy3.setHeightForWidth(m42->sizePolicy().hasHeightForWidth());
        m42->setSizePolicy(sizePolicy3);
        m42->setMaximumSize(QSize(60, 16777215));
        m42->setDecimals(4);
        m42->setMinimum(-1e+06);
        m42->setMaximum(1e+06);
        m42->setSingleStep(0.5);

        gridLayout_5->addWidget(m42, 3, 1, 1, 1);

        m43 = new QDoubleSpinBox(Matrix);
        m43->setObjectName(QString::fromUtf8("m43"));
        sizePolicy3.setHeightForWidth(m43->sizePolicy().hasHeightForWidth());
        m43->setSizePolicy(sizePolicy3);
        m43->setMaximumSize(QSize(60, 16777215));
        m43->setDecimals(4);
        m43->setMinimum(-1e+06);
        m43->setMaximum(1e+06);
        m43->setSingleStep(0.5);

        gridLayout_5->addWidget(m43, 3, 2, 1, 1);

        m44 = new QDoubleSpinBox(Matrix);
        m44->setObjectName(QString::fromUtf8("m44"));
        sizePolicy3.setHeightForWidth(m44->sizePolicy().hasHeightForWidth());
        m44->setSizePolicy(sizePolicy3);
        m44->setMaximumSize(QSize(60, 16777215));
        m44->setDecimals(4);
        m44->setMinimum(-1e+06);
        m44->setMaximum(1e+06);
        m44->setSingleStep(0.5);
        m44->setValue(1);

        gridLayout_5->addWidget(m44, 3, 3, 1, 1);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_9);

        DefaultMatrix = new QPushButton(Matrix);
        DefaultMatrix->setObjectName(QString::fromUtf8("DefaultMatrix"));
        sizePolicy3.setHeightForWidth(DefaultMatrix->sizePolicy().hasHeightForWidth());
        DefaultMatrix->setSizePolicy(sizePolicy3);

        horizontalLayout_9->addWidget(DefaultMatrix);


        gridLayout_5->addLayout(horizontalLayout_9, 4, 0, 1, 4);


        gridLayout->addWidget(TheScene, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        GridWidget = new QWidget(frame_2);
        GridWidget->setObjectName(QString::fromUtf8("GridWidget"));
        sizePolicy3.setHeightForWidth(GridWidget->sizePolicy().hasHeightForWidth());
        GridWidget->setSizePolicy(sizePolicy3);
        horizontalLayout_11 = new QHBoxLayout(GridWidget);
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        TBgridToolButton = new QToolButton(GridWidget);
        TBgridToolButton->setObjectName(QString::fromUtf8("TBgridToolButton"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/resources/RES/grid.png"), QSize(), QIcon::Normal, QIcon::Off);
        TBgridToolButton->setIcon(icon18);
        TBgridToolButton->setCheckable(true);
        TBgridToolButton->setChecked(false);
        TBgridToolButton->setPopupMode(QToolButton::MenuButtonPopup);
        TBgridToolButton->setAutoRaise(true);

        horizontalLayout_11->addWidget(TBgridToolButton);

        toolButton_8 = new QToolButton(GridWidget);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/resources/RES/guide_snap.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_8->setIcon(icon19);
        toolButton_8->setCheckable(true);
        toolButton_8->setAutoRaise(true);

        horizontalLayout_11->addWidget(toolButton_8);

        toolButton_9 = new QToolButton(GridWidget);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        toolButton_9->setIcon(icon3);
        toolButton_9->setCheckable(true);
        toolButton_9->setAutoRaise(true);

        horizontalLayout_11->addWidget(toolButton_9);


        verticalLayout->addWidget(GridWidget);

        TBViewToolbar = new QWidget(frame_2);
        TBViewToolbar->setObjectName(QString::fromUtf8("TBViewToolbar"));
        sizePolicy3.setHeightForWidth(TBViewToolbar->sizePolicy().hasHeightForWidth());
        TBViewToolbar->setSizePolicy(sizePolicy3);
        horizontalLayout_18 = new QHBoxLayout(TBViewToolbar);
        horizontalLayout_18->setSpacing(0);
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        TBView2d = new QToolButton(TBViewToolbar);
        TBView2d->setObjectName(QString::fromUtf8("TBView2d"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/resources/RES/2d.png"), QSize(), QIcon::Normal, QIcon::Off);
        TBView2d->setIcon(icon20);
        TBView2d->setCheckable(true);
        TBView2d->setChecked(false);
        TBView2d->setPopupMode(QToolButton::MenuButtonPopup);
        TBView2d->setAutoRaise(true);

        horizontalLayout_18->addWidget(TBView2d);

        TBView25d = new QToolButton(TBViewToolbar);
        TBView25d->setObjectName(QString::fromUtf8("TBView25d"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/resources/RES/25d.png"), QSize(), QIcon::Normal, QIcon::Off);
        TBView25d->setIcon(icon21);
        TBView25d->setCheckable(true);
        TBView25d->setChecked(false);
        TBView25d->setPopupMode(QToolButton::MenuButtonPopup);
        TBView25d->setAutoRaise(true);

        horizontalLayout_18->addWidget(TBView25d);

        TBView3d = new QToolButton(TBViewToolbar);
        TBView3d->setObjectName(QString::fromUtf8("TBView3d"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/resources/RES/3d.png"), QSize(), QIcon::Normal, QIcon::Off);
        TBView3d->setIcon(icon22);
        TBView3d->setCheckable(true);
        TBView3d->setChecked(false);
        TBView3d->setPopupMode(QToolButton::MenuButtonPopup);
        TBView3d->setAutoRaise(true);

        horizontalLayout_18->addWidget(TBView3d);

        TBView3d_2 = new QToolButton(TBViewToolbar);
        TBView3d_2->setObjectName(QString::fromUtf8("TBView3d_2"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/resources/RES/ffficons/eye.png"), QSize(), QIcon::Normal, QIcon::Off);
        TBView3d_2->setIcon(icon23);
        TBView3d_2->setCheckable(true);
        TBView3d_2->setChecked(false);
        TBView3d_2->setPopupMode(QToolButton::MenuButtonPopup);
        TBView3d_2->setAutoRaise(true);

        horizontalLayout_18->addWidget(TBView3d_2);


        verticalLayout->addWidget(TBViewToolbar);

        TBZoomWidget = new QWidget(frame_2);
        TBZoomWidget->setObjectName(QString::fromUtf8("TBZoomWidget"));
        sizePolicy3.setHeightForWidth(TBZoomWidget->sizePolicy().hasHeightForWidth());
        TBZoomWidget->setSizePolicy(sizePolicy3);
        horizontalLayout_3 = new QHBoxLayout(TBZoomWidget);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSlider = new QSlider(TBZoomWidget);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        horizontalSlider->setMaximumSize(QSize(60, 16777215));
        horizontalSlider->setMinimum(10);
        horizontalSlider->setMaximum(500);
        horizontalSlider->setSingleStep(1);
        horizontalSlider->setValue(100);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout_3->addWidget(horizontalSlider);


        verticalLayout->addWidget(TBZoomWidget);


        horizontalLayout->addWidget(frame_2);

        SceneEditor->setCentralWidget(centralwidget);
        toolBar = new QToolBar(SceneEditor);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(16, 16));
        SceneEditor->addToolBar(Qt::TopToolBarArea, toolBar);
        LayersDockWidget = new QDockWidget(SceneEditor);
        LayersDockWidget->setObjectName(QString::fromUtf8("LayersDockWidget"));
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(dockWidgetContents_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        LayersTW = new QTreeWidget(frame);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setFont(0, font);
        __qtreewidgetitem->setIcon(0, icon23);
        LayersTW->setHeaderItem(__qtreewidgetitem);
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/resources/RES/ffficons/shading.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(LayersTW);
        __qtreewidgetitem1->setCheckState(0, Qt::Unchecked);
        __qtreewidgetitem1->setIcon(0, icon24);
        LayersTW->setObjectName(QString::fromUtf8("LayersTW"));
        LayersTW->setFrameShape(QFrame::NoFrame);
        LayersTW->setIndentation(3);
        LayersTW->header()->setDefaultSectionSize(24);

        verticalLayout_4->addWidget(LayersTW);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_4->addWidget(line);

        ButtonsFrame = new QFrame(frame);
        ButtonsFrame->setObjectName(QString::fromUtf8("ButtonsFrame"));
        horizontalLayout_4 = new QHBoxLayout(ButtonsFrame);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        toolButton_4 = new QToolButton(ButtonsFrame);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon25);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_4);

        toolButton_5 = new QToolButton(ButtonsFrame);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/resources/RES/ffficons/shape_square_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon26);
        toolButton_5->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_5);

        toolButton = new QToolButton(ButtonsFrame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/resources/RES/ffficons/bin.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon27);
        toolButton->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        toolButton_3 = new QToolButton(ButtonsFrame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setIcon(icon16);
        toolButton_3->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_3);

        toolButton_2 = new QToolButton(ButtonsFrame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        toolButton_2->setIcon(icon17);
        toolButton_2->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_2);


        verticalLayout_4->addWidget(ButtonsFrame);


        verticalLayout_2->addWidget(frame);

        LayersDockWidget->setWidget(dockWidgetContents_2);
        SceneEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(2), LayersDockWidget);
        ToolOptionsDockWidget = new QDockWidget(SceneEditor);
        ToolOptionsDockWidget->setObjectName(QString::fromUtf8("ToolOptionsDockWidget"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout_8 = new QVBoxLayout(dockWidgetContents_4);
#ifndef Q_OS_MAC
        verticalLayout_8->setSpacing(6);
#endif
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        ToolOptionsSW = new QStackedWidget(dockWidgetContents_4);
        ToolOptionsSW->setObjectName(QString::fromUtf8("ToolOptionsSW"));
        pgObjectInspector = new QWidget();
        pgObjectInspector->setObjectName(QString::fromUtf8("pgObjectInspector"));
        verticalLayout_17 = new QVBoxLayout(pgObjectInspector);
        verticalLayout_17->setSpacing(0);
        verticalLayout_17->setContentsMargins(0, 0, 0, 0);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        panelSelectToolOptions = new QFrame(pgObjectInspector);
        panelSelectToolOptions->setObjectName(QString::fromUtf8("panelSelectToolOptions"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(panelSelectToolOptions->sizePolicy().hasHeightForWidth());
        panelSelectToolOptions->setSizePolicy(sizePolicy4);
        panelSelectToolOptions->setFrameShape(QFrame::StyledPanel);
        panelSelectToolOptions->setFrameShadow(QFrame::Plain);
        verticalLayout_9 = new QVBoxLayout(panelSelectToolOptions);
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setContentsMargins(0, 0, 0, 0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        PropertiesTW = new QTreeWidget(panelSelectToolOptions);
        PropertiesTW->setObjectName(QString::fromUtf8("PropertiesTW"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(PropertiesTW->sizePolicy().hasHeightForWidth());
        PropertiesTW->setSizePolicy(sizePolicy5);
        PropertiesTW->setFrameShape(QFrame::NoFrame);
        PropertiesTW->setLineWidth(0);
        PropertiesTW->header()->setDefaultSectionSize(80);

        verticalLayout_9->addWidget(PropertiesTW);

        LBNoObjectSelected = new QLabel(panelSelectToolOptions);
        LBNoObjectSelected->setObjectName(QString::fromUtf8("LBNoObjectSelected"));
        LBNoObjectSelected->setEnabled(false);
        QFont font1;
        font1.setItalic(true);
        LBNoObjectSelected->setFont(font1);
        LBNoObjectSelected->setAlignment(Qt::AlignCenter);
        LBNoObjectSelected->setWordWrap(true);

        verticalLayout_9->addWidget(LBNoObjectSelected);


        verticalLayout_17->addWidget(panelSelectToolOptions);

        ToolOptionsSW->addWidget(pgObjectInspector);
        pgDrawObjects = new QWidget();
        pgDrawObjects->setObjectName(QString::fromUtf8("pgDrawObjects"));
        verticalLayout_18 = new QVBoxLayout(pgDrawObjects);
        verticalLayout_18->setSpacing(0);
        verticalLayout_18->setContentsMargins(0, 0, 0, 0);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        panelPencilOptions = new QFrame(pgDrawObjects);
        panelPencilOptions->setObjectName(QString::fromUtf8("panelPencilOptions"));
        sizePolicy4.setHeightForWidth(panelPencilOptions->sizePolicy().hasHeightForWidth());
        panelPencilOptions->setSizePolicy(sizePolicy4);
        panelPencilOptions->setFrameShape(QFrame::StyledPanel);
        panelPencilOptions->setFrameShadow(QFrame::Plain);
        verticalLayout_10 = new QVBoxLayout(panelPencilOptions);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(3, 3, 3, 3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        FreeDrawing = new QCheckBox(panelPencilOptions);
        FreeDrawing->setObjectName(QString::fromUtf8("FreeDrawing"));
        FreeDrawing->setChecked(true);

        verticalLayout_10->addWidget(FreeDrawing);

        DelUnderlying = new QCheckBox(panelPencilOptions);
        DelUnderlying->setObjectName(QString::fromUtf8("DelUnderlying"));
        DelUnderlying->setChecked(true);

        verticalLayout_10->addWidget(DelUnderlying);

        verticalSpacer_3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_3);


        verticalLayout_18->addWidget(panelPencilOptions);

        ToolOptionsSW->addWidget(pgDrawObjects);
        pgRectangleOptions = new QWidget();
        pgRectangleOptions->setObjectName(QString::fromUtf8("pgRectangleOptions"));
        verticalLayout_19 = new QVBoxLayout(pgRectangleOptions);
        verticalLayout_19->setSpacing(0);
        verticalLayout_19->setContentsMargins(0, 0, 0, 0);
        verticalLayout_19->setObjectName(QString::fromUtf8("verticalLayout_19"));
        panelRectangleOptions = new QFrame(pgRectangleOptions);
        panelRectangleOptions->setObjectName(QString::fromUtf8("panelRectangleOptions"));
        sizePolicy4.setHeightForWidth(panelRectangleOptions->sizePolicy().hasHeightForWidth());
        panelRectangleOptions->setSizePolicy(sizePolicy4);
        panelRectangleOptions->setFrameShape(QFrame::StyledPanel);
        panelRectangleOptions->setFrameShadow(QFrame::Plain);
        verticalLayout_12 = new QVBoxLayout(panelRectangleOptions);
        verticalLayout_12->setSpacing(0);
        verticalLayout_12->setContentsMargins(0, 0, 0, 0);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(3, 3, -1, -1);
        pushButton = new QPushButton(panelRectangleOptions);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        sizePolicy3.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy3);
        pushButton->setIcon(icon5);

        gridLayout_3->addWidget(pushButton, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(panelRectangleOptions);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        sizePolicy3.setHeightForWidth(pushButton_2->sizePolicy().hasHeightForWidth());
        pushButton_2->setSizePolicy(sizePolicy3);
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/resources/RES/ffficons/paintcan.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon28);

        gridLayout_3->addWidget(pushButton_2, 1, 2, 1, 1);

        pushButton_6 = new QPushButton(panelRectangleOptions);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        sizePolicy3.setHeightForWidth(pushButton_6->sizePolicy().hasHeightForWidth());
        pushButton_6->setSizePolicy(sizePolicy3);
        pushButton_6->setIcon(icon6);

        gridLayout_3->addWidget(pushButton_6, 2, 1, 1, 1);

        pushButton_7 = new QPushButton(panelRectangleOptions);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));
        sizePolicy3.setHeightForWidth(pushButton_7->sizePolicy().hasHeightForWidth());
        pushButton_7->setSizePolicy(sizePolicy3);
        pushButton_7->setIcon(icon18);

        gridLayout_3->addWidget(pushButton_7, 2, 2, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 1, 0, 4, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_3, 1, 3, 4, 1);

        pushButton_5 = new QPushButton(panelRectangleOptions);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setIcon(icon13);

        gridLayout_3->addWidget(pushButton_5, 3, 1, 1, 1);

        pushButton_10 = new QPushButton(panelRectangleOptions);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));
        pushButton_10->setIcon(icon7);

        gridLayout_3->addWidget(pushButton_10, 3, 2, 1, 1);

        rectSnapToGrid = new QCheckBox(panelRectangleOptions);
        rectSnapToGrid->setObjectName(QString::fromUtf8("rectSnapToGrid"));

        gridLayout_3->addWidget(rectSnapToGrid, 0, 0, 1, 4);

        pushButton_3 = new QPushButton(panelRectangleOptions);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setIcon(icon15);

        gridLayout_3->addWidget(pushButton_3, 4, 1, 1, 1);


        verticalLayout_12->addLayout(gridLayout_3);

        verticalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_12->addItem(verticalSpacer_4);


        verticalLayout_19->addWidget(panelRectangleOptions);

        ToolOptionsSW->addWidget(pgRectangleOptions);
        pgPathOptions = new QWidget();
        pgPathOptions->setObjectName(QString::fromUtf8("pgPathOptions"));
        verticalLayout_20 = new QVBoxLayout(pgPathOptions);
        verticalLayout_20->setSpacing(0);
        verticalLayout_20->setContentsMargins(0, 0, 0, 0);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        panelPathOptions = new QFrame(pgPathOptions);
        panelPathOptions->setObjectName(QString::fromUtf8("panelPathOptions"));
        panelPathOptions->setFrameShape(QFrame::StyledPanel);
        panelPathOptions->setFrameShadow(QFrame::Plain);
        verticalLayout_11 = new QVBoxLayout(panelPathOptions);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        frame_3 = new QFrame(panelPathOptions);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setLineWidth(0);
        verticalLayout_3 = new QVBoxLayout(frame_3);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        horizontalLayout_15->setContentsMargins(3, 3, -1, -1);
        checkBox = new QCheckBox(frame_3);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        horizontalLayout_15->addWidget(checkBox);


        verticalLayout_3->addLayout(horizontalLayout_15);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(3);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(-1, 0, -1, 2);
        horizontalSpacer_4 = new QSpacerItem(13, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        toolButton_10 = new QToolButton(frame_3);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        toolButton_10->setIcon(icon5);
        toolButton_10->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_10->addWidget(toolButton_10);

        toolButton_11 = new QToolButton(frame_3);
        toolButton_11->setObjectName(QString::fromUtf8("toolButton_11"));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/resources/RES/ffficons/vector_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_11->setIcon(icon29);
        toolButton_11->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_10->addWidget(toolButton_11);

        toolButton_12 = new QToolButton(frame_3);
        toolButton_12->setObjectName(QString::fromUtf8("toolButton_12"));
        toolButton_12->setIcon(icon28);
        toolButton_12->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_10->addWidget(toolButton_12);

        horizontalSpacer_5 = new QSpacerItem(13, 26, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_5);


        verticalLayout_3->addLayout(horizontalLayout_10);

        line_5 = new QFrame(frame_3);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_5);

        pathsTW = new QTreeWidget(frame_3);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem();
        __qtreewidgetitem2->setIcon(0, icon23);
        pathsTW->setHeaderItem(__qtreewidgetitem2);
        pathsTW->setObjectName(QString::fromUtf8("pathsTW"));
        pathsTW->setFrameShape(QFrame::NoFrame);

        verticalLayout_3->addWidget(pathsTW);

        line_4 = new QFrame(frame_3);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setFrameShape(QFrame::HLine);
        line_4->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line_4);

        ButtonsFrame_2 = new QFrame(frame_3);
        ButtonsFrame_2->setObjectName(QString::fromUtf8("ButtonsFrame_2"));
        horizontalLayout_7 = new QHBoxLayout(ButtonsFrame_2);
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        path_new = new QToolButton(ButtonsFrame_2);
        path_new->setObjectName(QString::fromUtf8("path_new"));
        path_new->setIcon(icon25);
        path_new->setAutoRaise(true);

        horizontalLayout_7->addWidget(path_new);

        path_delete = new QToolButton(ButtonsFrame_2);
        path_delete->setObjectName(QString::fromUtf8("path_delete"));
        path_delete->setIcon(icon27);
        path_delete->setAutoRaise(true);

        horizontalLayout_7->addWidget(path_delete);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_6);

        path_save = new QToolButton(ButtonsFrame_2);
        path_save->setObjectName(QString::fromUtf8("path_save"));
        path_save->setIcon(icon16);
        path_save->setAutoRaise(true);

        horizontalLayout_7->addWidget(path_save);

        path_load = new QToolButton(ButtonsFrame_2);
        path_load->setObjectName(QString::fromUtf8("path_load"));
        path_load->setIcon(icon17);
        path_load->setAutoRaise(true);

        horizontalLayout_7->addWidget(path_load);


        verticalLayout_3->addWidget(ButtonsFrame_2);


        verticalLayout_11->addWidget(frame_3);


        verticalLayout_20->addWidget(panelPathOptions);

        ToolOptionsSW->addWidget(pgPathOptions);
        pgGraphOptions = new QWidget();
        pgGraphOptions->setObjectName(QString::fromUtf8("pgGraphOptions"));
        verticalLayout_22 = new QVBoxLayout(pgGraphOptions);
        verticalLayout_22->setSpacing(0);
        verticalLayout_22->setContentsMargins(0, 0, 0, 0);
        verticalLayout_22->setObjectName(QString::fromUtf8("verticalLayout_22"));
        GraphFrame = new QFrame(pgGraphOptions);
        GraphFrame->setObjectName(QString::fromUtf8("GraphFrame"));
        GraphFrame->setFrameShape(QFrame::StyledPanel);
        GraphFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_25 = new QVBoxLayout(GraphFrame);
        verticalLayout_25->setSpacing(0);
        verticalLayout_25->setContentsMargins(0, 0, 0, 0);
        verticalLayout_25->setObjectName(QString::fromUtf8("verticalLayout_25"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(3, 3, -1, -1);
        checkBox_3 = new QCheckBox(GraphFrame);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        horizontalLayout_6->addWidget(checkBox_3);


        verticalLayout_25->addLayout(horizontalLayout_6);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(3);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        horizontalLayout_14->setContentsMargins(-1, 3, -1, 5);
        horizontalSpacer_10 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_10);

        toolButton_13 = new QToolButton(GraphFrame);
        toolButton_13->setObjectName(QString::fromUtf8("toolButton_13"));
        toolButton_13->setIcon(icon14);
        toolButton_13->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_14->addWidget(toolButton_13);

        toolButton_24 = new QToolButton(GraphFrame);
        toolButton_24->setObjectName(QString::fromUtf8("toolButton_24"));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/resources/RES/ffficons/brick.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_24->setIcon(icon30);
        toolButton_24->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_14->addWidget(toolButton_24);

        horizontalSpacer_12 = new QSpacerItem(5, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_12);


        verticalLayout_25->addLayout(horizontalLayout_14);

        frame_6 = new QFrame(GraphFrame);
        frame_6->setObjectName(QString::fromUtf8("frame_6"));
        verticalLayout_23 = new QVBoxLayout(frame_6);
        verticalLayout_23->setSpacing(0);
        verticalLayout_23->setContentsMargins(0, 0, 0, 0);
        verticalLayout_23->setObjectName(QString::fromUtf8("verticalLayout_23"));
        line_7 = new QFrame(frame_6);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        verticalLayout_23->addWidget(line_7);

        GraphsTW = new QTreeWidget(frame_6);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem();
        __qtreewidgetitem3->setIcon(0, icon23);
        GraphsTW->setHeaderItem(__qtreewidgetitem3);
        GraphsTW->setObjectName(QString::fromUtf8("GraphsTW"));
        GraphsTW->setFrameShape(QFrame::NoFrame);

        verticalLayout_23->addWidget(GraphsTW);

        line_6 = new QFrame(frame_6);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setFrameShape(QFrame::HLine);
        line_6->setFrameShadow(QFrame::Sunken);

        verticalLayout_23->addWidget(line_6);

        ButtonsFrame_5 = new QFrame(frame_6);
        ButtonsFrame_5->setObjectName(QString::fromUtf8("ButtonsFrame_5"));
        horizontalLayout_13 = new QHBoxLayout(ButtonsFrame_5);
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        graph_new = new QToolButton(ButtonsFrame_5);
        graph_new->setObjectName(QString::fromUtf8("graph_new"));
        graph_new->setIcon(icon25);
        graph_new->setAutoRaise(true);

        horizontalLayout_13->addWidget(graph_new);

        graph_delete = new QToolButton(ButtonsFrame_5);
        graph_delete->setObjectName(QString::fromUtf8("graph_delete"));
        graph_delete->setIcon(icon27);
        graph_delete->setAutoRaise(true);

        horizontalLayout_13->addWidget(graph_delete);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_11);

        graph_save = new QToolButton(ButtonsFrame_5);
        graph_save->setObjectName(QString::fromUtf8("graph_save"));
        graph_save->setIcon(icon16);
        graph_save->setAutoRaise(true);

        horizontalLayout_13->addWidget(graph_save);

        graph_load = new QToolButton(ButtonsFrame_5);
        graph_load->setObjectName(QString::fromUtf8("graph_load"));
        graph_load->setIcon(icon17);
        graph_load->setAutoRaise(true);

        horizontalLayout_13->addWidget(graph_load);


        verticalLayout_23->addWidget(ButtonsFrame_5);


        verticalLayout_25->addWidget(frame_6);


        verticalLayout_22->addWidget(GraphFrame);

        ToolOptionsSW->addWidget(pgGraphOptions);
        pgTerrainOptions = new QWidget();
        pgTerrainOptions->setObjectName(QString::fromUtf8("pgTerrainOptions"));
        verticalLayout_7 = new QVBoxLayout(pgTerrainOptions);
        verticalLayout_7->setSpacing(3);
        verticalLayout_7->setContentsMargins(3, 3, 3, 3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_3 = new QLabel(pgTerrainOptions);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        comboBox = new QComboBox(pgTerrainOptions);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);


        verticalLayout_7->addLayout(formLayout);

        terrainOptionsSW = new QStackedWidget(pgTerrainOptions);
        terrainOptionsSW->setObjectName(QString::fromUtf8("terrainOptionsSW"));
        pgTerrainOptionsNotSelected = new QWidget();
        pgTerrainOptionsNotSelected->setObjectName(QString::fromUtf8("pgTerrainOptionsNotSelected"));
        verticalLayout_15 = new QVBoxLayout(pgTerrainOptionsNotSelected);
        verticalLayout_15->setSpacing(3);
        verticalLayout_15->setContentsMargins(0, 0, 0, 0);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        label_10 = new QLabel(pgTerrainOptionsNotSelected);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font2;
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        label_10->setFont(font2);

        verticalLayout_15->addWidget(label_10);

        label_11 = new QLabel(pgTerrainOptionsNotSelected);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font3;
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        label_11->setFont(font3);

        verticalLayout_15->addWidget(label_11);

        checkBox_2 = new QCheckBox(pgTerrainOptionsNotSelected);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_15->addWidget(checkBox_2);

        line_9 = new QFrame(pgTerrainOptionsNotSelected);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setFrameShape(QFrame::HLine);
        line_9->setFrameShadow(QFrame::Sunken);

        verticalLayout_15->addWidget(line_9);

        label_12 = new QLabel(pgTerrainOptionsNotSelected);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        verticalLayout_15->addWidget(label_12);

        commandLinkButton = new QCommandLinkButton(pgTerrainOptionsNotSelected);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));

        verticalLayout_15->addWidget(commandLinkButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_15->addItem(verticalSpacer_5);

        terrainOptionsSW->addWidget(pgTerrainOptionsNotSelected);
        pgTHeightmap = new QWidget();
        pgTHeightmap->setObjectName(QString::fromUtf8("pgTHeightmap"));
        verticalLayout_14 = new QVBoxLayout(pgTHeightmap);
        verticalLayout_14->setSpacing(3);
        verticalLayout_14->setContentsMargins(0, 0, 0, 0);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        toolButton_16 = new QToolButton(pgTHeightmap);
        toolButton_16->setObjectName(QString::fromUtf8("toolButton_16"));
        sizePolicy2.setHeightForWidth(toolButton_16->sizePolicy().hasHeightForWidth());
        toolButton_16->setSizePolicy(sizePolicy2);
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/resources/RES/ffficons/arrow_join.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_16->setIcon(icon31);
        toolButton_16->setCheckable(true);
        toolButton_16->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_16->setAutoRaise(true);

        gridLayout_4->addWidget(toolButton_16, 0, 0, 1, 1);

        toolButton_17 = new QToolButton(pgTHeightmap);
        toolButton_17->setObjectName(QString::fromUtf8("toolButton_17"));
        sizePolicy2.setHeightForWidth(toolButton_17->sizePolicy().hasHeightForWidth());
        toolButton_17->setSizePolicy(sizePolicy2);
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/resources/RES/ffficons/asterisk_orange.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_17->setIcon(icon32);
        toolButton_17->setCheckable(true);
        toolButton_17->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_17->setAutoRaise(true);

        gridLayout_4->addWidget(toolButton_17, 0, 1, 1, 1);

        toolButton_18 = new QToolButton(pgTHeightmap);
        toolButton_18->setObjectName(QString::fromUtf8("toolButton_18"));
        sizePolicy2.setHeightForWidth(toolButton_18->sizePolicy().hasHeightForWidth());
        toolButton_18->setSizePolicy(sizePolicy2);
        toolButton_18->setIcon(icon24);
        toolButton_18->setCheckable(true);
        toolButton_18->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_18->setAutoRaise(true);

        gridLayout_4->addWidget(toolButton_18, 0, 2, 1, 1);

        toolButton_19 = new QToolButton(pgTHeightmap);
        toolButton_19->setObjectName(QString::fromUtf8("toolButton_19"));
        sizePolicy2.setHeightForWidth(toolButton_19->sizePolicy().hasHeightForWidth());
        toolButton_19->setSizePolicy(sizePolicy2);
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/resources/RES/ffficons/paintbrush.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_19->setIcon(icon33);
        toolButton_19->setCheckable(true);
        toolButton_19->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_19->setAutoRaise(true);

        gridLayout_4->addWidget(toolButton_19, 1, 0, 1, 1);

        toolButton_21 = new QToolButton(pgTHeightmap);
        toolButton_21->setObjectName(QString::fromUtf8("toolButton_21"));
        sizePolicy2.setHeightForWidth(toolButton_21->sizePolicy().hasHeightForWidth());
        toolButton_21->setSizePolicy(sizePolicy2);
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/resources/RES/ffficons/wrench.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_21->setIcon(icon34);
        toolButton_21->setCheckable(true);
        toolButton_21->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_21->setAutoRaise(true);

        gridLayout_4->addWidget(toolButton_21, 1, 2, 1, 1);

        toolButton_20 = new QToolButton(pgTHeightmap);
        toolButton_20->setObjectName(QString::fromUtf8("toolButton_20"));
        sizePolicy2.setHeightForWidth(toolButton_20->sizePolicy().hasHeightForWidth());
        toolButton_20->setSizePolicy(sizePolicy2);
        toolButton_20->setIcon(icon5);
        toolButton_20->setCheckable(true);
        toolButton_20->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_20->setAutoRaise(true);

        gridLayout_4->addWidget(toolButton_20, 1, 1, 1, 1);


        verticalLayout_14->addLayout(gridLayout_4);

        line_10 = new QFrame(pgTHeightmap);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setFrameShape(QFrame::HLine);
        line_10->setFrameShadow(QFrame::Sunken);

        verticalLayout_14->addWidget(line_10);

        HeightMapTerrainTools = new QStackedWidget(pgTHeightmap);
        HeightMapTerrainTools->setObjectName(QString::fromUtf8("HeightMapTerrainTools"));
        pgHmTHeight = new QWidget();
        pgHmTHeight->setObjectName(QString::fromUtf8("pgHmTHeight"));
        verticalLayout_24 = new QVBoxLayout(pgHmTHeight);
        verticalLayout_24->setSpacing(3);
        verticalLayout_24->setContentsMargins(0, 0, 0, 0);
        verticalLayout_24->setObjectName(QString::fromUtf8("verticalLayout_24"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        label_13 = new QLabel(pgHmTHeight);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_6->addWidget(label_13, 0, 0, 1, 1);

        HMTBrushSizeSlider = new QSlider(pgHmTHeight);
        HMTBrushSizeSlider->setObjectName(QString::fromUtf8("HMTBrushSizeSlider"));
        HMTBrushSizeSlider->setMaximum(100);
        HMTBrushSizeSlider->setValue(10);
        HMTBrushSizeSlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(HMTBrushSizeSlider, 0, 1, 1, 1);

        doubleSpinBox = new QDoubleSpinBox(pgHmTHeight);
        doubleSpinBox->setObjectName(QString::fromUtf8("doubleSpinBox"));
        doubleSpinBox->setDecimals(0);
        doubleSpinBox->setMaximum(10000);
        doubleSpinBox->setValue(10);

        gridLayout_6->addWidget(doubleSpinBox, 0, 2, 1, 1);

        label_14 = new QLabel(pgHmTHeight);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        gridLayout_6->addWidget(label_14, 0, 3, 1, 1);

        label_15 = new QLabel(pgHmTHeight);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_6->addWidget(label_15, 1, 0, 1, 1);

        HMTsoftnessSlider = new QSlider(pgHmTHeight);
        HMTsoftnessSlider->setObjectName(QString::fromUtf8("HMTsoftnessSlider"));
        HMTsoftnessSlider->setMaximum(100);
        HMTsoftnessSlider->setValue(50);
        HMTsoftnessSlider->setOrientation(Qt::Horizontal);

        gridLayout_6->addWidget(HMTsoftnessSlider, 1, 1, 1, 1);

        doubleSpinBox_2 = new QDoubleSpinBox(pgHmTHeight);
        doubleSpinBox_2->setObjectName(QString::fromUtf8("doubleSpinBox_2"));
        doubleSpinBox_2->setDecimals(0);
        doubleSpinBox_2->setMaximum(100);
        doubleSpinBox_2->setValue(50);

        gridLayout_6->addWidget(doubleSpinBox_2, 1, 2, 1, 1);

        label_16 = new QLabel(pgHmTHeight);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout_6->addWidget(label_16, 1, 3, 1, 1);

        horizontalLayout_16 = new QHBoxLayout();
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        label_17 = new QLabel(pgHmTHeight);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_16->addWidget(label_17);

        horizontalSlider_2 = new QSlider(pgHmTHeight);
        horizontalSlider_2->setObjectName(QString::fromUtf8("horizontalSlider_2"));
        horizontalSlider_2->setMaximum(100);
        horizontalSlider_2->setValue(10);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        horizontalLayout_16->addWidget(horizontalSlider_2);

        label_18 = new QLabel(pgHmTHeight);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_16->addWidget(label_18);


        gridLayout_6->addLayout(horizontalLayout_16, 2, 0, 1, 4);


        verticalLayout_24->addLayout(gridLayout_6);

        verticalSpacer_6 = new QSpacerItem(20, 41, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_24->addItem(verticalSpacer_6);

        HeightMapTerrainTools->addWidget(pgHmTHeight);
        pgHmTSmooth = new QWidget();
        pgHmTSmooth->setObjectName(QString::fromUtf8("pgHmTSmooth"));
        verticalLayout_26 = new QVBoxLayout(pgHmTSmooth);
        verticalLayout_26->setSpacing(3);
        verticalLayout_26->setContentsMargins(0, 0, 0, 0);
        verticalLayout_26->setObjectName(QString::fromUtf8("verticalLayout_26"));
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_19 = new QLabel(pgHmTSmooth);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout_7->addWidget(label_19, 0, 0, 1, 1);

        HMTBrushSizeSlider_2 = new QSlider(pgHmTSmooth);
        HMTBrushSizeSlider_2->setObjectName(QString::fromUtf8("HMTBrushSizeSlider_2"));
        HMTBrushSizeSlider_2->setMaximum(100);
        HMTBrushSizeSlider_2->setOrientation(Qt::Horizontal);

        gridLayout_7->addWidget(HMTBrushSizeSlider_2, 0, 1, 1, 1);

        doubleSpinBox_3 = new QDoubleSpinBox(pgHmTSmooth);
        doubleSpinBox_3->setObjectName(QString::fromUtf8("doubleSpinBox_3"));
        doubleSpinBox_3->setDecimals(0);
        doubleSpinBox_3->setMaximum(10000);

        gridLayout_7->addWidget(doubleSpinBox_3, 0, 2, 1, 1);

        label_20 = new QLabel(pgHmTSmooth);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout_7->addWidget(label_20, 0, 3, 1, 1);


        verticalLayout_26->addLayout(gridLayout_7);

        verticalSpacer_7 = new QSpacerItem(20, 94, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_26->addItem(verticalSpacer_7);

        HeightMapTerrainTools->addWidget(pgHmTSmooth);
        pgHmTFlatten = new QWidget();
        pgHmTFlatten->setObjectName(QString::fromUtf8("pgHmTFlatten"));
        verticalLayout_27 = new QVBoxLayout(pgHmTFlatten);
        verticalLayout_27->setSpacing(3);
        verticalLayout_27->setContentsMargins(0, 0, 0, 0);
        verticalLayout_27->setObjectName(QString::fromUtf8("verticalLayout_27"));
        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        gridLayout_8->setHorizontalSpacing(1);
        gridLayout_8->setVerticalSpacing(0);
        label_21 = new QLabel(pgHmTFlatten);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_8->addWidget(label_21, 1, 1, 1, 1);

        HMTBrushSizeSlider_3 = new QSlider(pgHmTFlatten);
        HMTBrushSizeSlider_3->setObjectName(QString::fromUtf8("HMTBrushSizeSlider_3"));
        HMTBrushSizeSlider_3->setMaximum(100);
        HMTBrushSizeSlider_3->setOrientation(Qt::Horizontal);

        gridLayout_8->addWidget(HMTBrushSizeSlider_3, 1, 2, 1, 1);

        doubleSpinBox_4 = new QDoubleSpinBox(pgHmTFlatten);
        doubleSpinBox_4->setObjectName(QString::fromUtf8("doubleSpinBox_4"));
        doubleSpinBox_4->setDecimals(0);
        doubleSpinBox_4->setMaximum(100);

        gridLayout_8->addWidget(doubleSpinBox_4, 1, 4, 1, 1);

        label_22 = new QLabel(pgHmTFlatten);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_8->addWidget(label_22, 1, 5, 1, 1);

        view_new_3 = new QToolButton(pgHmTFlatten);
        view_new_3->setObjectName(QString::fromUtf8("view_new_3"));
        view_new_3->setIcon(icon11);
        view_new_3->setAutoRaise(true);

        gridLayout_8->addWidget(view_new_3, 1, 3, 1, 1);

        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        label_28 = new QLabel(pgHmTFlatten);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        horizontalLayout_19->addWidget(label_28);

        horizontalSlider_3 = new QSlider(pgHmTFlatten);
        horizontalSlider_3->setObjectName(QString::fromUtf8("horizontalSlider_3"));
        horizontalSlider_3->setOrientation(Qt::Horizontal);

        horizontalLayout_19->addWidget(horizontalSlider_3);

        spinBox = new QSpinBox(pgHmTFlatten);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_19->addWidget(spinBox);

        label_29 = new QLabel(pgHmTFlatten);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout_19->addWidget(label_29);


        gridLayout_8->addLayout(horizontalLayout_19, 0, 1, 1, 5);


        verticalLayout_27->addLayout(gridLayout_8);

        verticalSpacer_8 = new QSpacerItem(20, 181, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_27->addItem(verticalSpacer_8);

        HeightMapTerrainTools->addWidget(pgHmTFlatten);
        pgHmTPaint = new QWidget();
        pgHmTPaint->setObjectName(QString::fromUtf8("pgHmTPaint"));
        verticalLayout_28 = new QVBoxLayout(pgHmTPaint);
        verticalLayout_28->setSpacing(3);
        verticalLayout_28->setContentsMargins(0, 0, 0, 0);
        verticalLayout_28->setObjectName(QString::fromUtf8("verticalLayout_28"));
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
        label_23 = new QLabel(pgHmTPaint);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_9->addWidget(label_23, 0, 0, 1, 1);

        HMTBrushSizeSlider_4 = new QSlider(pgHmTPaint);
        HMTBrushSizeSlider_4->setObjectName(QString::fromUtf8("HMTBrushSizeSlider_4"));
        HMTBrushSizeSlider_4->setMaximum(100);
        HMTBrushSizeSlider_4->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(HMTBrushSizeSlider_4, 0, 1, 1, 1);

        doubleSpinBox_5 = new QDoubleSpinBox(pgHmTPaint);
        doubleSpinBox_5->setObjectName(QString::fromUtf8("doubleSpinBox_5"));
        doubleSpinBox_5->setDecimals(0);
        doubleSpinBox_5->setMaximum(10000);

        gridLayout_9->addWidget(doubleSpinBox_5, 0, 2, 1, 1);

        label_24 = new QLabel(pgHmTPaint);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_9->addWidget(label_24, 0, 3, 1, 1);

        label_25 = new QLabel(pgHmTPaint);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_9->addWidget(label_25, 1, 0, 1, 1);

        HMTsoftnessSlider_2 = new QSlider(pgHmTPaint);
        HMTsoftnessSlider_2->setObjectName(QString::fromUtf8("HMTsoftnessSlider_2"));
        HMTsoftnessSlider_2->setMaximum(100);
        HMTsoftnessSlider_2->setValue(50);
        HMTsoftnessSlider_2->setOrientation(Qt::Horizontal);

        gridLayout_9->addWidget(HMTsoftnessSlider_2, 1, 1, 1, 1);

        doubleSpinBox_6 = new QDoubleSpinBox(pgHmTPaint);
        doubleSpinBox_6->setObjectName(QString::fromUtf8("doubleSpinBox_6"));
        doubleSpinBox_6->setDecimals(0);
        doubleSpinBox_6->setMaximum(100);

        gridLayout_9->addWidget(doubleSpinBox_6, 1, 2, 1, 1);

        label_26 = new QLabel(pgHmTPaint);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_9->addWidget(label_26, 1, 3, 1, 1);


        verticalLayout_28->addLayout(gridLayout_9);

        frame_5 = new QFrame(pgHmTPaint);
        frame_5->setObjectName(QString::fromUtf8("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Sunken);
        verticalLayout_29 = new QVBoxLayout(frame_5);
        verticalLayout_29->setSpacing(0);
        verticalLayout_29->setContentsMargins(0, 0, 0, 0);
        verticalLayout_29->setObjectName(QString::fromUtf8("verticalLayout_29"));
        ViewsTW_2 = new QTreeWidget(frame_5);
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/resources/RES/ffficons/layers.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem();
        __qtreewidgetitem4->setIcon(0, icon35);
        ViewsTW_2->setHeaderItem(__qtreewidgetitem4);
        ViewsTW_2->setObjectName(QString::fromUtf8("ViewsTW_2"));
        ViewsTW_2->setFrameShape(QFrame::NoFrame);

        verticalLayout_29->addWidget(ViewsTW_2);

        line_11 = new QFrame(frame_5);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);

        verticalLayout_29->addWidget(line_11);

        ButtonsFrame_4 = new QFrame(frame_5);
        ButtonsFrame_4->setObjectName(QString::fromUtf8("ButtonsFrame_4"));
        horizontalLayout_17 = new QHBoxLayout(ButtonsFrame_4);
        horizontalLayout_17->setSpacing(0);
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        view_new_2 = new QToolButton(ButtonsFrame_4);
        view_new_2->setObjectName(QString::fromUtf8("view_new_2"));
        view_new_2->setIcon(icon25);
        view_new_2->setAutoRaise(true);

        horizontalLayout_17->addWidget(view_new_2);

        view_delete_3 = new QToolButton(ButtonsFrame_4);
        view_delete_3->setObjectName(QString::fromUtf8("view_delete_3"));
        view_delete_3->setIcon(icon4);
        view_delete_3->setAutoRaise(true);

        horizontalLayout_17->addWidget(view_delete_3);

        view_delete_2 = new QToolButton(ButtonsFrame_4);
        view_delete_2->setObjectName(QString::fromUtf8("view_delete_2"));
        view_delete_2->setIcon(icon27);
        view_delete_2->setAutoRaise(true);

        horizontalLayout_17->addWidget(view_delete_2);

        horizontalSpacer_13 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_17->addItem(horizontalSpacer_13);

        toolButton_22 = new QToolButton(ButtonsFrame_4);
        toolButton_22->setObjectName(QString::fromUtf8("toolButton_22"));
        toolButton_22->setIcon(icon16);
        toolButton_22->setAutoRaise(true);

        horizontalLayout_17->addWidget(toolButton_22);

        toolButton_23 = new QToolButton(ButtonsFrame_4);
        toolButton_23->setObjectName(QString::fromUtf8("toolButton_23"));
        toolButton_23->setIcon(icon17);
        toolButton_23->setAutoRaise(true);

        horizontalLayout_17->addWidget(toolButton_23);


        verticalLayout_29->addWidget(ButtonsFrame_4);


        verticalLayout_28->addWidget(frame_5);

        HeightMapTerrainTools->addWidget(pgHmTPaint);
        pgHmTOther = new QWidget();
        pgHmTOther->setObjectName(QString::fromUtf8("pgHmTOther"));
        HeightMapTerrainTools->addWidget(pgHmTOther);
        pgHmTOptions = new QWidget();
        pgHmTOptions->setObjectName(QString::fromUtf8("pgHmTOptions"));
        verticalLayout_31 = new QVBoxLayout(pgHmTOptions);
        verticalLayout_31->setSpacing(3);
        verticalLayout_31->setContentsMargins(0, 0, 0, 0);
        verticalLayout_31->setObjectName(QString::fromUtf8("verticalLayout_31"));
        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QString::fromUtf8("gridLayout_15"));
        pushButton_4 = new QPushButton(pgHmTOptions);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setIcon(icon7);

        gridLayout_15->addWidget(pushButton_4, 0, 0, 1, 1);

        pushButton_8 = new QPushButton(pgHmTOptions);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));
        pushButton_8->setIcon(icon6);

        gridLayout_15->addWidget(pushButton_8, 0, 1, 1, 1);

        label_45 = new QLabel(pgHmTOptions);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label_45, 1, 1, 1, 1);

        label_44 = new QLabel(pgHmTOptions);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setAlignment(Qt::AlignCenter);

        gridLayout_15->addWidget(label_44, 1, 0, 1, 1);


        verticalLayout_31->addLayout(gridLayout_15);

        line_8 = new QFrame(pgHmTOptions);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout_31->addWidget(line_8);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        label_4 = new QLabel(pgHmTOptions);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_4);

        label_6 = new QLabel(pgHmTOptions);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        comboBox_2 = new QComboBox(pgHmTOptions);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, comboBox_2);

        comboBox_3 = new QComboBox(pgHmTOptions);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, comboBox_3);


        verticalLayout_31->addLayout(formLayout_2);

        verticalSpacer_10 = new QSpacerItem(20, 135, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_31->addItem(verticalSpacer_10);

        HeightMapTerrainTools->addWidget(pgHmTOptions);

        verticalLayout_14->addWidget(HeightMapTerrainTools);

        terrainOptionsSW->addWidget(pgTHeightmap);
        pgTVoxel = new QWidget();
        pgTVoxel->setObjectName(QString::fromUtf8("pgTVoxel"));
        verticalLayout_30 = new QVBoxLayout(pgTVoxel);
        verticalLayout_30->setObjectName(QString::fromUtf8("verticalLayout_30"));
        label_27 = new QLabel(pgTVoxel);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        verticalLayout_30->addWidget(label_27);

        verticalSpacer_9 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_30->addItem(verticalSpacer_9);

        terrainOptionsSW->addWidget(pgTVoxel);

        verticalLayout_7->addWidget(terrainOptionsSW);

        ToolOptionsSW->addWidget(pgTerrainOptions);
        pgCSGOptions = new QWidget();
        pgCSGOptions->setObjectName(QString::fromUtf8("pgCSGOptions"));
        verticalLayout_6 = new QVBoxLayout(pgCSGOptions);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        ToolOptionsSW->addWidget(pgCSGOptions);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        ToolOptionsSW->addWidget(page_5);

        verticalLayout_8->addWidget(ToolOptionsSW);

        ToolOptionsDockWidget->setWidget(dockWidgetContents_4);
        SceneEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(2), ToolOptionsDockWidget);
        ViewsDockWidget = new QDockWidget(SceneEditor);
        ViewsDockWidget->setObjectName(QString::fromUtf8("ViewsDockWidget"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_5 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        frame_4 = new QFrame(dockWidgetContents);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        verticalLayout_16 = new QVBoxLayout(frame_4);
        verticalLayout_16->setSpacing(0);
        verticalLayout_16->setContentsMargins(0, 0, 0, 0);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        ViewsTW = new QTreeWidget(frame_4);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem();
        __qtreewidgetitem5->setIcon(0, icon23);
        ViewsTW->setHeaderItem(__qtreewidgetitem5);
        ViewsTW->setObjectName(QString::fromUtf8("ViewsTW"));
        ViewsTW->setFrameShape(QFrame::NoFrame);

        verticalLayout_16->addWidget(ViewsTW);

        line_2 = new QFrame(frame_4);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_16->addWidget(line_2);

        ButtonsFrame_3 = new QFrame(frame_4);
        ButtonsFrame_3->setObjectName(QString::fromUtf8("ButtonsFrame_3"));
        horizontalLayout_8 = new QHBoxLayout(ButtonsFrame_3);
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        view_new = new QToolButton(ButtonsFrame_3);
        view_new->setObjectName(QString::fromUtf8("view_new"));
        view_new->setIcon(icon25);
        view_new->setAutoRaise(true);

        horizontalLayout_8->addWidget(view_new);

        view_delete = new QToolButton(ButtonsFrame_3);
        view_delete->setObjectName(QString::fromUtf8("view_delete"));
        view_delete->setIcon(icon27);
        view_delete->setAutoRaise(true);

        horizontalLayout_8->addWidget(view_delete);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        toolButton_14 = new QToolButton(ButtonsFrame_3);
        toolButton_14->setObjectName(QString::fromUtf8("toolButton_14"));
        toolButton_14->setIcon(icon16);
        toolButton_14->setAutoRaise(true);

        horizontalLayout_8->addWidget(toolButton_14);

        toolButton_15 = new QToolButton(ButtonsFrame_3);
        toolButton_15->setObjectName(QString::fromUtf8("toolButton_15"));
        toolButton_15->setIcon(icon17);
        toolButton_15->setAutoRaise(true);

        horizontalLayout_8->addWidget(toolButton_15);


        verticalLayout_16->addWidget(ButtonsFrame_3);


        verticalLayout_5->addWidget(frame_4);

        ViewsDockWidget->setWidget(dockWidgetContents);
        SceneEditor->addDockWidget(static_cast<Qt::DockWidgetArea>(2), ViewsDockWidget);
        menuBar = new QMenuBar(SceneEditor);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 770, 19));
        menu2D = new QMenu(menuBar);
        menu2D->setObjectName(QString::fromUtf8("menu2D"));
        menu25D = new QMenu(menuBar);
        menu25D->setObjectName(QString::fromUtf8("menu25D"));
        menu3D = new QMenu(menuBar);
        menu3D->setObjectName(QString::fromUtf8("menu3D"));
        menuViews = new QMenu(menuBar);
        menuViews->setObjectName(QString::fromUtf8("menuViews"));
        SceneEditor->setMenuBar(menuBar);
#ifndef QT_NO_SHORTCUT
        label_5->setBuddy(GridWSB);
        label_7->setBuddy(GridHSB);
        label_8->setBuddy(GridXSB);
        label_9->setBuddy(GridYSB);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(m11, m12);
        QWidget::setTabOrder(m12, m13);
        QWidget::setTabOrder(m13, m14);
        QWidget::setTabOrder(m14, m21);
        QWidget::setTabOrder(m21, m22);
        QWidget::setTabOrder(m22, m23);
        QWidget::setTabOrder(m23, m24);
        QWidget::setTabOrder(m24, m31);
        QWidget::setTabOrder(m31, m32);
        QWidget::setTabOrder(m32, m33);
        QWidget::setTabOrder(m33, m34);
        QWidget::setTabOrder(m34, m41);
        QWidget::setTabOrder(m41, m42);
        QWidget::setTabOrder(m42, m43);
        QWidget::setTabOrder(m43, m44);
        QWidget::setTabOrder(m44, DefaultMatrix);
        QWidget::setTabOrder(DefaultMatrix, toolButton_3);
        QWidget::setTabOrder(toolButton_3, toolButton_2);
        QWidget::setTabOrder(toolButton_2, PropertiesTW);
        QWidget::setTabOrder(PropertiesTW, FreeDrawing);
        QWidget::setTabOrder(FreeDrawing, DelUnderlying);
        QWidget::setTabOrder(DelUnderlying, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_7);
        QWidget::setTabOrder(pushButton_7, path_new);
        QWidget::setTabOrder(path_new, path_delete);
        QWidget::setTabOrder(path_delete, path_save);
        QWidget::setTabOrder(path_save, path_load);
        QWidget::setTabOrder(path_load, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_10);
        QWidget::setTabOrder(pushButton_10, ViewsTW);
        QWidget::setTabOrder(ViewsTW, view_new);
        QWidget::setTabOrder(view_new, view_delete);
        QWidget::setTabOrder(view_delete, toolButton_14);
        QWidget::setTabOrder(toolButton_14, toolButton_15);
        QWidget::setTabOrder(toolButton_15, radioButton);
        QWidget::setTabOrder(radioButton, radioButton_2);
        QWidget::setTabOrder(radioButton_2, radioButton_3);
        QWidget::setTabOrder(radioButton_3, GridWSB);
        QWidget::setTabOrder(GridWSB, GridHSB);
        QWidget::setTabOrder(GridHSB, toolButton_6);
        QWidget::setTabOrder(toolButton_6, LayersTW);
        QWidget::setTabOrder(LayersTW, GridXSB);
        QWidget::setTabOrder(GridXSB, GridYSB);
        QWidget::setTabOrder(GridYSB, toolButton_7);
        QWidget::setTabOrder(toolButton_7, colorButton);
        QWidget::setTabOrder(colorButton, GridAlphaSlider);
        QWidget::setTabOrder(GridAlphaSlider, horizontalSlider);
        QWidget::setTabOrder(horizontalSlider, toolButton_4);
        QWidget::setTabOrder(toolButton_4, toolButton_5);
        QWidget::setTabOrder(toolButton_5, toolButton);

        toolBar->addAction(actionSelect_objects);
        toolBar->addAction(actionDraw_objects);
        toolBar->addAction(actionRectangle_tool);
        toolBar->addAction(actionPolygon_path_tool);
        toolBar->addAction(actionGraph_tool);
        toolBar->addAction(actionTerrain_tool);
        toolBar->addAction(actionGet_object_tool);
        toolBar->addSeparator();
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionCut);
        toolBar->addSeparator();
        toolBar->addAction(actionZoomOut);
        toolBar->addAction(actionZoomIn);
        toolBar->addAction(action100percent);
        toolBar->addSeparator();
        toolBar->addAction(actionToolOptions);
        toolBar->addAction(actionLayers);
        toolBar->addAction(actionViews);
        toolBar->addSeparator();
        menuBar->addAction(menu2D->menuAction());
        menuBar->addAction(menu25D->menuAction());
        menuBar->addAction(menu3D->menuAction());
        menuBar->addAction(menuViews->menuAction());
        menu2D->addAction(actionX_Y);
        menu2D->addAction(actionX_Z);
        menu2D->addAction(actionY_Z_side);
        menu2D->addSeparator();
        menu2D->addAction(actionPick_plane);
        menu25D->addAction(actionX_Y_Top_down);
        menu25D->addAction(actionX_Z_Side);
        menu25D->addAction(actionY_Z_side_2);
        menu25D->addSeparator();
        menu25D->addAction(actionPick_plane_2);
        menu3D->addAction(actionPerspective);
        menu3D->addAction(actionParallel);
        menu3D->addSeparator();
        menu3D->addAction(actionQuad_view);
        menuViews->addSeparator();
        menuViews->addAction(actionSave_view);
        menuViews->addAction(actionImport_views);

        retranslateUi(SceneEditor);

        GridStackedWidget->setCurrentIndex(0);
        ToolOptionsSW->setCurrentIndex(0);
        terrainOptionsSW->setCurrentIndex(0);
        HeightMapTerrainTools->setCurrentIndex(5);
        comboBox_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SceneEditor);
    } // setupUi

    void retranslateUi(QMainWindow *SceneEditor)
    {
        SceneEditor->setWindowTitle(QApplication::translate("SceneEditor", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionLayers->setText(QApplication::translate("SceneEditor", "Layers", 0, QApplication::UnicodeUTF8));
        actionZoomIn->setText(QApplication::translate("SceneEditor", "Zoom in", 0, QApplication::UnicodeUTF8));
        actionZoomOut->setText(QApplication::translate("SceneEditor", "Zoom out", 0, QApplication::UnicodeUTF8));
        action100percent->setText(QApplication::translate("SceneEditor", "100%", 0, QApplication::UnicodeUTF8));
        actionGrid_settings->setText(QApplication::translate("SceneEditor", "Grid settings...", 0, QApplication::UnicodeUTF8));
        actionDraw_objects->setText(QApplication::translate("SceneEditor", "Draw objects", 0, QApplication::UnicodeUTF8));
        actionSelect_objects->setText(QApplication::translate("SceneEditor", "Select objects", 0, QApplication::UnicodeUTF8));
        actionRectangle_tool->setText(QApplication::translate("SceneEditor", "Rectangle tool", 0, QApplication::UnicodeUTF8));
        actionPolygon_path_tool->setText(QApplication::translate("SceneEditor", "Polygon / path tool", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("SceneEditor", "Copy", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("SceneEditor", "Paste", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("SceneEditor", "Cut", 0, QApplication::UnicodeUTF8));
        actionGet_object_tool->setText(QApplication::translate("SceneEditor", "Eyedropper tool", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionGet_object_tool->setToolTip(QApplication::translate("SceneEditor", "Pick placed object with its settings for placing.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionToolOptions->setText(QApplication::translate("SceneEditor", "Properties", 0, QApplication::UnicodeUTF8));
        actionViews->setText(QApplication::translate("SceneEditor", "Views", 0, QApplication::UnicodeUTF8));
        actionGraph_tool->setText(QApplication::translate("SceneEditor", "Graph tool", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionGraph_tool->setToolTip(QApplication::translate("SceneEditor", "Create graphs that can be used for different purposes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionTerrain_tool->setText(QApplication::translate("SceneEditor", "Terrain tool", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionTerrain_tool->setToolTip(QApplication::translate("SceneEditor", "Allows you to create and edit voxel or heightmap based terrains", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionX_Y->setText(QApplication::translate("SceneEditor", "X/Y - top down", 0, QApplication::UnicodeUTF8));
        actionX_Z->setText(QApplication::translate("SceneEditor", "X/Z - side", 0, QApplication::UnicodeUTF8));
        actionY_Z_side->setText(QApplication::translate("SceneEditor", "Y/Z - side", 0, QApplication::UnicodeUTF8));
        actionPick_plane->setText(QApplication::translate("SceneEditor", "Pick plane...", 0, QApplication::UnicodeUTF8));
        actionX_Y_Top_down->setText(QApplication::translate("SceneEditor", "X/Y - top down", 0, QApplication::UnicodeUTF8));
        actionX_Z_Side->setText(QApplication::translate("SceneEditor", "X/Z - side", 0, QApplication::UnicodeUTF8));
        actionY_Z_side_2->setText(QApplication::translate("SceneEditor", "Y/Z - side", 0, QApplication::UnicodeUTF8));
        actionPick_plane_2->setText(QApplication::translate("SceneEditor", "Pick plane...", 0, QApplication::UnicodeUTF8));
        actionPerspective->setText(QApplication::translate("SceneEditor", "Perspective", 0, QApplication::UnicodeUTF8));
        actionParallel->setText(QApplication::translate("SceneEditor", "Parallel", 0, QApplication::UnicodeUTF8));
        actionQuad_view->setText(QApplication::translate("SceneEditor", "Quad view", 0, QApplication::UnicodeUTF8));
        actionSave_view->setText(QApplication::translate("SceneEditor", "Save view...", 0, QApplication::UnicodeUTF8));
        actionImport_views->setText(QApplication::translate("SceneEditor", "Import views...", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("SceneEditor", "Rectangle grid", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("SceneEditor", "Isometric grid", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("SceneEditor", "Custom grid...", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("SceneEditor", "W:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("SceneEditor", "H:", 0, QApplication::UnicodeUTF8));
        toolButton_7->setText(QApplication::translate("SceneEditor", "Save", 0, QApplication::UnicodeUTF8));
        toolButton_6->setText(QApplication::translate("SceneEditor", "Load", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("SceneEditor", "X:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("SceneEditor", "Y:", 0, QApplication::UnicodeUTF8));
        colorButton->setText(QString());
        DefaultMatrix->setText(QApplication::translate("SceneEditor", "Clear matrix", 0, QApplication::UnicodeUTF8));
        TBgridToolButton->setText(QApplication::translate("SceneEditor", "Show grid", 0, QApplication::UnicodeUTF8));
        toolButton_8->setText(QApplication::translate("SceneEditor", "Snap to grid", 0, QApplication::UnicodeUTF8));
        toolButton_9->setText(QApplication::translate("SceneEditor", "Grid settings", 0, QApplication::UnicodeUTF8));
        TBView2d->setText(QApplication::translate("SceneEditor", "2D", 0, QApplication::UnicodeUTF8));
        TBView25d->setText(QApplication::translate("SceneEditor", "2,5D", 0, QApplication::UnicodeUTF8));
        TBView3d->setText(QApplication::translate("SceneEditor", "3D", 0, QApplication::UnicodeUTF8));
        TBView3d_2->setText(QApplication::translate("SceneEditor", "Camera", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("SceneEditor", "toolBar", 0, QApplication::UnicodeUTF8));
        LayersDockWidget->setWindowTitle(QApplication::translate("SceneEditor", "Layers", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = LayersTW->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("SceneEditor", " Layer name", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = LayersTW->isSortingEnabled();
        LayersTW->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = LayersTW->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("SceneEditor", "Default", 0, QApplication::UnicodeUTF8));
        LayersTW->setSortingEnabled(__sortingEnabled);

        toolButton_4->setText(QApplication::translate("SceneEditor", "New layer", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QApplication::translate("SceneEditor", "Rename layer", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("SceneEditor", "Delete layer", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("SceneEditor", "Save layer", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("SceneEditor", "Load layer", 0, QApplication::UnicodeUTF8));
        ToolOptionsDockWidget->setWindowTitle(QApplication::translate("SceneEditor", "Tool options", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = PropertiesTW->headerItem();
        ___qtreewidgetitem2->setText(1, QApplication::translate("SceneEditor", "Value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("SceneEditor", "Property", 0, QApplication::UnicodeUTF8));
        LBNoObjectSelected->setText(QApplication::translate("SceneEditor", "No object selected.\n"
"Select an object to edit its properties.", 0, QApplication::UnicodeUTF8));
        FreeDrawing->setText(QApplication::translate("SceneEditor", "Free drawing", 0, QApplication::UnicodeUTF8));
        DelUnderlying->setText(QApplication::translate("SceneEditor", "Delete underlying", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SceneEditor", "Select", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("SceneEditor", "Fill", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("SceneEditor", "Add layer", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("SceneEditor", "Grid layer", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("SceneEditor", "Add view", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("SceneEditor", "Add path", 0, QApplication::UnicodeUTF8));
        rectSnapToGrid->setText(QApplication::translate("SceneEditor", "Snap rectangle to the grid", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("SceneEditor", "Terrain", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("SceneEditor", "Snap points to the grid", 0, QApplication::UnicodeUTF8));
        toolButton_10->setText(QApplication::translate("SceneEditor", "Select", 0, QApplication::UnicodeUTF8));
        toolButton_11->setText(QApplication::translate("SceneEditor", "Add path", 0, QApplication::UnicodeUTF8));
        toolButton_12->setText(QApplication::translate("SceneEditor", "Fill", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = pathsTW->headerItem();
        ___qtreewidgetitem3->setText(0, QApplication::translate("SceneEditor", " Paths", 0, QApplication::UnicodeUTF8));
        path_new->setText(QApplication::translate("SceneEditor", "New", 0, QApplication::UnicodeUTF8));
        path_delete->setText(QApplication::translate("SceneEditor", "Delete", 0, QApplication::UnicodeUTF8));
        path_save->setText(QApplication::translate("SceneEditor", "Save", 0, QApplication::UnicodeUTF8));
        path_load->setText(QApplication::translate("SceneEditor", "Load", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("SceneEditor", "Snap vertices to the grid", 0, QApplication::UnicodeUTF8));
        toolButton_13->setText(QApplication::translate("SceneEditor", "Add graph", 0, QApplication::UnicodeUTF8));
        toolButton_24->setText(QApplication::translate("SceneEditor", "Place objects", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = GraphsTW->headerItem();
        ___qtreewidgetitem4->setText(0, QApplication::translate("SceneEditor", " Graphs", 0, QApplication::UnicodeUTF8));
        graph_new->setText(QApplication::translate("SceneEditor", "New", 0, QApplication::UnicodeUTF8));
        graph_delete->setText(QApplication::translate("SceneEditor", "Delete", 0, QApplication::UnicodeUTF8));
        graph_save->setText(QApplication::translate("SceneEditor", "Save", 0, QApplication::UnicodeUTF8));
        graph_load->setText(QApplication::translate("SceneEditor", "Load", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SceneEditor", "Terrain type:", 0, QApplication::UnicodeUTF8));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("SceneEditor", "Heightmap", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SceneEditor", "Voxel", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("SceneEditor", "Draw a rectangle", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("SceneEditor", "to define the terrain area.", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("SceneEditor", "Snap rectangle to the grid", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("SceneEditor", "Or click existing terrain to edit it.", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("SceneEditor", "Show all terrains", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setDescription(QApplication::translate("SceneEditor", "in selected layers", 0, QApplication::UnicodeUTF8));
        toolButton_16->setText(QApplication::translate("SceneEditor", "Height", 0, QApplication::UnicodeUTF8));
        toolButton_17->setText(QApplication::translate("SceneEditor", "Smooth", 0, QApplication::UnicodeUTF8));
        toolButton_18->setText(QApplication::translate("SceneEditor", "Flatten", 0, QApplication::UnicodeUTF8));
        toolButton_19->setText(QApplication::translate("SceneEditor", "Paint", 0, QApplication::UnicodeUTF8));
        toolButton_21->setText(QApplication::translate("SceneEditor", "Options", 0, QApplication::UnicodeUTF8));
        toolButton_20->setText(QApplication::translate("SceneEditor", "Other", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_in.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_out.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/soft.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_2->setSuffix(QApplication::translate("SceneEditor", "%", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/hard.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">weak</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">strong</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_in.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_out.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_21->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_down.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_4->setSuffix(QApplication::translate("SceneEditor", "%", 0, QApplication::UnicodeUTF8));
        label_22->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_up.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        view_new_3->setText(QApplication::translate("SceneEditor", "Pick", 0, QApplication::UnicodeUTF8));
        label_28->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_in.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_29->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_out.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_23->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_in.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_24->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/arrow_out.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_25->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/soft.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        doubleSpinBox_6->setSuffix(QApplication::translate("SceneEditor", "%", 0, QApplication::UnicodeUTF8));
        label_26->setText(QApplication::translate("SceneEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/hard.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = ViewsTW_2->headerItem();
        ___qtreewidgetitem5->setText(0, QApplication::translate("SceneEditor", " Biomes", 0, QApplication::UnicodeUTF8));
        view_new_2->setText(QApplication::translate("SceneEditor", "New", 0, QApplication::UnicodeUTF8));
        view_delete_3->setText(QApplication::translate("SceneEditor", "Edit", 0, QApplication::UnicodeUTF8));
        view_delete_2->setText(QApplication::translate("SceneEditor", "Delete", 0, QApplication::UnicodeUTF8));
        toolButton_22->setText(QApplication::translate("SceneEditor", "Save", 0, QApplication::UnicodeUTF8));
        toolButton_23->setText(QApplication::translate("SceneEditor", "Load", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("SceneEditor", "Vertex shader", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("SceneEditor", "Geometry shader", 0, QApplication::UnicodeUTF8));
        label_45->setText(QApplication::translate("SceneEditor", "Default", 0, QApplication::UnicodeUTF8));
        label_44->setText(QApplication::translate("SceneEditor", "Default", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SceneEditor", "Runtime:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("SceneEditor", "Fallback:", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SceneEditor", "Mesh without terrain data", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SceneEditor", "Static with terrain data", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SceneEditor", "Dynamic - shader based", 0, QApplication::UnicodeUTF8)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("SceneEditor", "Convert to mesh", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SceneEditor", "Ignore terrain", 0, QApplication::UnicodeUTF8)
        );
        label_27->setText(QApplication::translate("SceneEditor", "Voxel terrain options here", 0, QApplication::UnicodeUTF8));
        ViewsDockWidget->setWindowTitle(QApplication::translate("SceneEditor", "Views", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = ViewsTW->headerItem();
        ___qtreewidgetitem6->setText(0, QApplication::translate("SceneEditor", " Views", 0, QApplication::UnicodeUTF8));
        view_new->setText(QApplication::translate("SceneEditor", "New", 0, QApplication::UnicodeUTF8));
        view_delete->setText(QApplication::translate("SceneEditor", "Delete", 0, QApplication::UnicodeUTF8));
        toolButton_14->setText(QApplication::translate("SceneEditor", "Save", 0, QApplication::UnicodeUTF8));
        toolButton_15->setText(QApplication::translate("SceneEditor", "Load", 0, QApplication::UnicodeUTF8));
        menu2D->setTitle(QApplication::translate("SceneEditor", "2D", 0, QApplication::UnicodeUTF8));
        menu25D->setTitle(QApplication::translate("SceneEditor", "2,5D", 0, QApplication::UnicodeUTF8));
        menu3D->setTitle(QApplication::translate("SceneEditor", "3D", 0, QApplication::UnicodeUTF8));
        menuViews->setTitle(QApplication::translate("SceneEditor", "Camera", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SceneEditor: public Ui_SceneEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEEDITOR_H
