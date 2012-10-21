/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed 17. Oct 23:27:45 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDockWidget>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLineEdit>
#include <QtGui/QListView>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QToolButton>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExit;
    QAction *actionOpen_project;
    QAction *actionCreate_project;
    QAction *actionPiGameCreator_help;
    QAction *actionYour_first_game;
    QAction *actionTutorials;
    QAction *actionAbout_piGameCreator;
    QAction *actionVisit_piGameCreator_website;
    QAction *actionCheck_for_updates;
    QAction *actionAPI_documentation;
    QAction *actionLicensing;
    QAction *actionShowLog;
    QAction *actionTEST;
    QAction *actionClose_active_tab;
    QAction *actionClose_all_tabs;
    QAction *actionImport_resources_from_project;
    QAction *actionCreate_image;
    QAction *actionCreate_sound;
    QAction *actionCreate_GUI_layer;
    QAction *actionCreate_2D_scene;
    QAction *actionCreate_grid_based_2D_scene;
    QAction *actionClone_resource;
    QAction *actionExport_resource;
    QAction *actionAdd_class;
    QAction *actionAdd_global_function;
    QAction *actionCreate_model;
    QAction *actionExport_some_resources;
    QAction *actionCreate_class_template;
    QAction *actionDefine_grid;
    QAction *actionEdit_application_settings;
    QAction *actionCreate_Font;
    QAction *actionShow_Main_page;
    QAction *action_Save;
    QAction *actionSave_as;
    QAction *actionSave_a_ll;
    QAction *action_Run;
    QAction *action_Debug;
    QAction *action_Parameters;
    QAction *action_Targets;
    QAction *action_Project_options;
    QAction *actionCreate_vector_path;
    QAction *actionBuild;
    QAction *actionCreate_Shader;
    QAction *actionTarget_options;
    QAction *actionToolbars;
    QAction *action_Pack_project;
    QAction *action_Preferences;
    QAction *actionSet_up_collaboration;
    QAction *actionSkins;
    QAction *actionGameScript_tester;
    QAction *actionSkin_editor;
    QAction *actionFramework_editor;
    QAction *actionProject_tree;
    QAction *actionImages;
    QAction *actionSounds;
    QAction *actionScenes;
    QAction *actionClasses;
    QAction *actionModels;
    QAction *actionFonts;
    QAction *actionFilters;
    QAction *actionAdd_Effect;
    QAction *actionGraphics_effects;
    QAction *actionGlobal_functions;
    QAction *actionEdit_Haxe_stdlib;
    QAction *actionExport_project;
    QAction *actionClean;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *WorkSpaceMDIContainer;
    QTabWidget *WorkSpaceTabWidget;
    QMenuBar *menuBar;
    QMenu *menu_File;
    QMenu *menu_Help;
    QMenu *menuWindow;
    QMenu *menuResources;
    QMenu *menu_Project;
    QMenu *menuDeveloper;
    QMenu *menuView;
    QStatusBar *statusBar;
    QToolBar *projectToolbar;
    QDockWidget *projectDockWidget;
    QWidget *dockWidgetContents_6;
    QVBoxLayout *verticalLayout_2;
    QComboBox *projectComboBox;
    QStackedWidget *stackedWidget;
    QWidget *pgProjectTree;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *searchboxLayout_4;
    QToolButton *toolButton;
    QLineEdit *searchbox_4;
    QToolButton *searchboxClear_4;
    QTreeView *projectTree;
    QWidget *pgImages;
    QVBoxLayout *verticalLayout_4;
    QWidget *AddRemove;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *addImage;
    QSpacerItem *horizontalSpacer;
    QToolButton *delImage;
    QHBoxLayout *searchboxLayout;
    QLineEdit *searchbox;
    QToolButton *searchboxClear;
    QListWidget *imageListWidget;
    QWidget *pgTreeView;
    QVBoxLayout *verticalLayout_6;
    QWidget *AddRemove_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *addSomething;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *delSomething;
    QHBoxLayout *searchboxLayout_2;
    QLineEdit *searchbox_2;
    QToolButton *searchboxClear_2;
    QListView *somethingLV;
    QWidget *pgShaders;
    QVBoxLayout *verticalLayout_7;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_8;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_5;
    QWidget *AddRemove_3;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_7;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_4;
    QHBoxLayout *searchboxLayout_3;
    QLineEdit *searchbox_3;
    QToolButton *searchboxClear_3;
    QListWidget *listWidget;
    QWidget *page_3;
    QWidget *page_4;
    QWidget *page_5;
    QToolBar *runToolbar;
    QToolBar *viewToolbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(974, 590);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/pi16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/door_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon1);
        actionOpen_project = new QAction(MainWindow);
        actionOpen_project->setObjectName(QString::fromUtf8("actionOpen_project"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_project->setIcon(icon2);
        actionCreate_project = new QAction(MainWindow);
        actionCreate_project->setObjectName(QString::fromUtf8("actionCreate_project"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_project->setIcon(icon3);
        actionPiGameCreator_help = new QAction(MainWindow);
        actionPiGameCreator_help->setObjectName(QString::fromUtf8("actionPiGameCreator_help"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPiGameCreator_help->setIcon(icon4);
        actionYour_first_game = new QAction(MainWindow);
        actionYour_first_game->setObjectName(QString::fromUtf8("actionYour_first_game"));
        actionTutorials = new QAction(MainWindow);
        actionTutorials->setObjectName(QString::fromUtf8("actionTutorials"));
        actionTutorials->setCheckable(true);
        actionAbout_piGameCreator = new QAction(MainWindow);
        actionAbout_piGameCreator->setObjectName(QString::fromUtf8("actionAbout_piGameCreator"));
        actionVisit_piGameCreator_website = new QAction(MainWindow);
        actionVisit_piGameCreator_website->setObjectName(QString::fromUtf8("actionVisit_piGameCreator_website"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/world_link.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionVisit_piGameCreator_website->setIcon(icon5);
        actionCheck_for_updates = new QAction(MainWindow);
        actionCheck_for_updates->setObjectName(QString::fromUtf8("actionCheck_for_updates"));
        actionAPI_documentation = new QAction(MainWindow);
        actionAPI_documentation->setObjectName(QString::fromUtf8("actionAPI_documentation"));
        actionLicensing = new QAction(MainWindow);
        actionLicensing->setObjectName(QString::fromUtf8("actionLicensing"));
        actionShowLog = new QAction(MainWindow);
        actionShowLog->setObjectName(QString::fromUtf8("actionShowLog"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/log.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShowLog->setIcon(icon6);
        actionTEST = new QAction(MainWindow);
        actionTEST->setObjectName(QString::fromUtf8("actionTEST"));
        actionClose_active_tab = new QAction(MainWindow);
        actionClose_active_tab->setObjectName(QString::fromUtf8("actionClose_active_tab"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose_active_tab->setIcon(icon7);
        actionClose_all_tabs = new QAction(MainWindow);
        actionClose_all_tabs->setObjectName(QString::fromUtf8("actionClose_all_tabs"));
        actionClose_all_tabs->setIcon(icon7);
        actionImport_resources_from_project = new QAction(MainWindow);
        actionImport_resources_from_project->setObjectName(QString::fromUtf8("actionImport_resources_from_project"));
        actionCreate_image = new QAction(MainWindow);
        actionCreate_image->setObjectName(QString::fromUtf8("actionCreate_image"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/RES/ffficons/image_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_image->setIcon(icon8);
        actionCreate_sound = new QAction(MainWindow);
        actionCreate_sound->setObjectName(QString::fromUtf8("actionCreate_sound"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resources/RES/ffficons/sound_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_sound->setIcon(icon9);
        actionCreate_GUI_layer = new QAction(MainWindow);
        actionCreate_GUI_layer->setObjectName(QString::fromUtf8("actionCreate_GUI_layer"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/resources/RES/ffficons/textfield_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_GUI_layer->setIcon(icon10);
        actionCreate_2D_scene = new QAction(MainWindow);
        actionCreate_2D_scene->setObjectName(QString::fromUtf8("actionCreate_2D_scene"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/resources/RES/ffficons/world_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_2D_scene->setIcon(icon11);
        actionCreate_grid_based_2D_scene = new QAction(MainWindow);
        actionCreate_grid_based_2D_scene->setObjectName(QString::fromUtf8("actionCreate_grid_based_2D_scene"));
        actionClone_resource = new QAction(MainWindow);
        actionClone_resource->setObjectName(QString::fromUtf8("actionClone_resource"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClone_resource->setIcon(icon12);
        actionExport_resource = new QAction(MainWindow);
        actionExport_resource->setObjectName(QString::fromUtf8("actionExport_resource"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/resources/RES/ffficons/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_resource->setIcon(icon13);
        actionAdd_class = new QAction(MainWindow);
        actionAdd_class->setObjectName(QString::fromUtf8("actionAdd_class"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/resources/RES/ffficons/brick_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_class->setIcon(icon14);
        actionAdd_global_function = new QAction(MainWindow);
        actionAdd_global_function->setObjectName(QString::fromUtf8("actionAdd_global_function"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/resources/RES/ffficons/script_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_global_function->setIcon(icon15);
        actionCreate_model = new QAction(MainWindow);
        actionCreate_model->setObjectName(QString::fromUtf8("actionCreate_model"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/resources/RES/ffficons/car_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_model->setIcon(icon16);
        actionExport_some_resources = new QAction(MainWindow);
        actionExport_some_resources->setObjectName(QString::fromUtf8("actionExport_some_resources"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/resources/RES/ffficons/disk_multiple.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_some_resources->setIcon(icon17);
        actionCreate_class_template = new QAction(MainWindow);
        actionCreate_class_template->setObjectName(QString::fromUtf8("actionCreate_class_template"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/resources/RES/ffficons/brick_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_class_template->setIcon(icon18);
        actionDefine_grid = new QAction(MainWindow);
        actionDefine_grid->setObjectName(QString::fromUtf8("actionDefine_grid"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/resources/RES/ffficons/color_swatch.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDefine_grid->setIcon(icon19);
        actionEdit_application_settings = new QAction(MainWindow);
        actionEdit_application_settings->setObjectName(QString::fromUtf8("actionEdit_application_settings"));
        QIcon icon20;
        icon20.addFile(QString::fromUtf8(":/resources/RES/ffficons/cog_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_application_settings->setIcon(icon20);
        actionCreate_Font = new QAction(MainWindow);
        actionCreate_Font->setObjectName(QString::fromUtf8("actionCreate_Font"));
        QIcon icon21;
        icon21.addFile(QString::fromUtf8(":/resources/RES/ffficons/font_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_Font->setIcon(icon21);
        actionShow_Main_page = new QAction(MainWindow);
        actionShow_Main_page->setObjectName(QString::fromUtf8("actionShow_Main_page"));
        QIcon icon22;
        icon22.addFile(QString::fromUtf8(":/resources/RES/ffficons/application_home.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_Main_page->setIcon(icon22);
        action_Save = new QAction(MainWindow);
        action_Save->setObjectName(QString::fromUtf8("action_Save"));
        action_Save->setIcon(icon13);
        actionSave_as = new QAction(MainWindow);
        actionSave_as->setObjectName(QString::fromUtf8("actionSave_as"));
        actionSave_a_ll = new QAction(MainWindow);
        actionSave_a_ll->setObjectName(QString::fromUtf8("actionSave_a_ll"));
        actionSave_a_ll->setIcon(icon17);
        action_Run = new QAction(MainWindow);
        action_Run->setObjectName(QString::fromUtf8("action_Run"));
        QIcon icon23;
        icon23.addFile(QString::fromUtf8(":/resources/RES/tango/actions/media-playback-start.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Run->setIcon(icon23);
        action_Debug = new QAction(MainWindow);
        action_Debug->setObjectName(QString::fromUtf8("action_Debug"));
        QIcon icon24;
        icon24.addFile(QString::fromUtf8(":/resources/RES/ffficons/bug_delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Debug->setIcon(icon24);
        action_Parameters = new QAction(MainWindow);
        action_Parameters->setObjectName(QString::fromUtf8("action_Parameters"));
        QIcon icon25;
        icon25.addFile(QString::fromUtf8(":/resources/RES/ffficons/application_osx_terminal.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Parameters->setIcon(icon25);
        action_Targets = new QAction(MainWindow);
        action_Targets->setObjectName(QString::fromUtf8("action_Targets"));
        QIcon icon26;
        icon26.addFile(QString::fromUtf8(":/resources/RES/ffficons/computer.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Targets->setIcon(icon26);
        action_Project_options = new QAction(MainWindow);
        action_Project_options->setObjectName(QString::fromUtf8("action_Project_options"));
        QIcon icon27;
        icon27.addFile(QString::fromUtf8(":/resources/RES/ffficons/cog.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Project_options->setIcon(icon27);
        actionCreate_vector_path = new QAction(MainWindow);
        actionCreate_vector_path->setObjectName(QString::fromUtf8("actionCreate_vector_path"));
        QIcon icon28;
        icon28.addFile(QString::fromUtf8(":/resources/RES/ffficons/chart_line_add.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_vector_path->setIcon(icon28);
        actionBuild = new QAction(MainWindow);
        actionBuild->setObjectName(QString::fromUtf8("actionBuild"));
        QIcon icon29;
        icon29.addFile(QString::fromUtf8(":/resources/RES/compile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBuild->setIcon(icon29);
        actionCreate_Shader = new QAction(MainWindow);
        actionCreate_Shader->setObjectName(QString::fromUtf8("actionCreate_Shader"));
        QIcon icon30;
        icon30.addFile(QString::fromUtf8(":/resources/RES/ffficons/contrast_high.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreate_Shader->setIcon(icon30);
        actionTarget_options = new QAction(MainWindow);
        actionTarget_options->setObjectName(QString::fromUtf8("actionTarget_options"));
        QIcon icon31;
        icon31.addFile(QString::fromUtf8(":/resources/RES/ffficons/computer_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTarget_options->setIcon(icon31);
        actionToolbars = new QAction(MainWindow);
        actionToolbars->setObjectName(QString::fromUtf8("actionToolbars"));
        action_Pack_project = new QAction(MainWindow);
        action_Pack_project->setObjectName(QString::fromUtf8("action_Pack_project"));
        QIcon icon32;
        icon32.addFile(QString::fromUtf8(":/resources/RES/ffficons/package_green.png"), QSize(), QIcon::Normal, QIcon::Off);
        action_Pack_project->setIcon(icon32);
        action_Preferences = new QAction(MainWindow);
        action_Preferences->setObjectName(QString::fromUtf8("action_Preferences"));
        action_Preferences->setIcon(icon27);
        actionSet_up_collaboration = new QAction(MainWindow);
        actionSet_up_collaboration->setObjectName(QString::fromUtf8("actionSet_up_collaboration"));
        QIcon icon33;
        icon33.addFile(QString::fromUtf8(":/resources/RES/ffficons/connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSet_up_collaboration->setIcon(icon33);
        actionSkins = new QAction(MainWindow);
        actionSkins->setObjectName(QString::fromUtf8("actionSkins"));
        QIcon icon34;
        icon34.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder_palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSkins->setIcon(icon34);
        actionGameScript_tester = new QAction(MainWindow);
        actionGameScript_tester->setObjectName(QString::fromUtf8("actionGameScript_tester"));
        actionSkin_editor = new QAction(MainWindow);
        actionSkin_editor->setObjectName(QString::fromUtf8("actionSkin_editor"));
        actionFramework_editor = new QAction(MainWindow);
        actionFramework_editor->setObjectName(QString::fromUtf8("actionFramework_editor"));
        actionProject_tree = new QAction(MainWindow);
        actionProject_tree->setObjectName(QString::fromUtf8("actionProject_tree"));
        actionProject_tree->setCheckable(true);
        actionProject_tree->setChecked(true);
        QIcon icon35;
        icon35.addFile(QString::fromUtf8(":/resources/RES/tree.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionProject_tree->setIcon(icon35);
        actionImages = new QAction(MainWindow);
        actionImages->setObjectName(QString::fromUtf8("actionImages"));
        actionImages->setCheckable(true);
        QIcon icon36;
        icon36.addFile(QString::fromUtf8(":/resources/RES/ffficons/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionImages->setIcon(icon36);
        actionSounds = new QAction(MainWindow);
        actionSounds->setObjectName(QString::fromUtf8("actionSounds"));
        actionSounds->setCheckable(true);
        QIcon icon37;
        icon37.addFile(QString::fromUtf8(":/resources/RES/ffficons/sound.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSounds->setIcon(icon37);
        actionScenes = new QAction(MainWindow);
        actionScenes->setObjectName(QString::fromUtf8("actionScenes"));
        actionScenes->setCheckable(true);
        QIcon icon38;
        icon38.addFile(QString::fromUtf8(":/resources/RES/ffficons/world.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScenes->setIcon(icon38);
        actionClasses = new QAction(MainWindow);
        actionClasses->setObjectName(QString::fromUtf8("actionClasses"));
        actionClasses->setCheckable(true);
        QIcon icon39;
        icon39.addFile(QString::fromUtf8(":/resources/RES/ffficons/brick.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClasses->setIcon(icon39);
        actionModels = new QAction(MainWindow);
        actionModels->setObjectName(QString::fromUtf8("actionModels"));
        actionModels->setCheckable(true);
        QIcon icon40;
        icon40.addFile(QString::fromUtf8(":/resources/RES/ffficons/car.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionModels->setIcon(icon40);
        actionFonts = new QAction(MainWindow);
        actionFonts->setObjectName(QString::fromUtf8("actionFonts"));
        actionFonts->setCheckable(true);
        QIcon icon41;
        icon41.addFile(QString::fromUtf8(":/resources/RES/ffficons/font.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFonts->setIcon(icon41);
        actionFilters = new QAction(MainWindow);
        actionFilters->setObjectName(QString::fromUtf8("actionFilters"));
        actionFilters->setCheckable(true);
        QIcon icon42;
        icon42.addFile(QString::fromUtf8(":/resources/RES/ffficons/contrast.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFilters->setIcon(icon42);
        actionAdd_Effect = new QAction(MainWindow);
        actionAdd_Effect->setObjectName(QString::fromUtf8("actionAdd_Effect"));
        QIcon icon43;
        icon43.addFile(QString::fromUtf8(":/resources/RES/ffficons/rainbow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAdd_Effect->setIcon(icon43);
        actionGraphics_effects = new QAction(MainWindow);
        actionGraphics_effects->setObjectName(QString::fromUtf8("actionGraphics_effects"));
        actionGraphics_effects->setCheckable(true);
        actionGraphics_effects->setIcon(icon43);
        actionGlobal_functions = new QAction(MainWindow);
        actionGlobal_functions->setObjectName(QString::fromUtf8("actionGlobal_functions"));
        actionGlobal_functions->setCheckable(true);
        QIcon icon44;
        icon44.addFile(QString::fromUtf8(":/resources/RES/ffficons/script.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGlobal_functions->setIcon(icon44);
        actionEdit_Haxe_stdlib = new QAction(MainWindow);
        actionEdit_Haxe_stdlib->setObjectName(QString::fromUtf8("actionEdit_Haxe_stdlib"));
        actionExport_project = new QAction(MainWindow);
        actionExport_project->setObjectName(QString::fromUtf8("actionExport_project"));
        QIcon icon45;
        icon45.addFile(QString::fromUtf8(":/resources/RES/ffficons/package_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExport_project->setIcon(icon45);
        actionClean = new QAction(MainWindow);
        actionClean->setObjectName(QString::fromUtf8("actionClean"));
        QIcon icon46;
        icon46.addFile(QString::fromUtf8(":/resources/RES/ffficons/bin.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClean->setIcon(icon46);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        WorkSpaceMDIContainer = new QWidget(centralWidget);
        WorkSpaceMDIContainer->setObjectName(QString::fromUtf8("WorkSpaceMDIContainer"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(WorkSpaceMDIContainer->sizePolicy().hasHeightForWidth());
        WorkSpaceMDIContainer->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(WorkSpaceMDIContainer);

        WorkSpaceTabWidget = new QTabWidget(centralWidget);
        WorkSpaceTabWidget->setObjectName(QString::fromUtf8("WorkSpaceTabWidget"));
        WorkSpaceTabWidget->setTabPosition(QTabWidget::North);
        WorkSpaceTabWidget->setElideMode(Qt::ElideLeft);
        WorkSpaceTabWidget->setUsesScrollButtons(true);
        WorkSpaceTabWidget->setDocumentMode(false);
        WorkSpaceTabWidget->setTabsClosable(true);
        WorkSpaceTabWidget->setMovable(true);

        horizontalLayout->addWidget(WorkSpaceTabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 974, 19));
        menu_File = new QMenu(menuBar);
        menu_File->setObjectName(QString::fromUtf8("menu_File"));
        menu_Help = new QMenu(menuBar);
        menu_Help->setObjectName(QString::fromUtf8("menu_Help"));
        menuWindow = new QMenu(menuBar);
        menuWindow->setObjectName(QString::fromUtf8("menuWindow"));
        menuResources = new QMenu(menuBar);
        menuResources->setObjectName(QString::fromUtf8("menuResources"));
        menu_Project = new QMenu(menuBar);
        menu_Project->setObjectName(QString::fromUtf8("menu_Project"));
        menuDeveloper = new QMenu(menuBar);
        menuDeveloper->setObjectName(QString::fromUtf8("menuDeveloper"));
        menuView = new QMenu(menuBar);
        menuView->setObjectName(QString::fromUtf8("menuView"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        projectToolbar = new QToolBar(MainWindow);
        projectToolbar->setObjectName(QString::fromUtf8("projectToolbar"));
        projectToolbar->setContextMenuPolicy(Qt::PreventContextMenu);
        projectToolbar->setIconSize(QSize(16, 16));
        projectToolbar->setFloatable(true);
        MainWindow->addToolBar(Qt::TopToolBarArea, projectToolbar);
        projectDockWidget = new QDockWidget(MainWindow);
        projectDockWidget->setObjectName(QString::fromUtf8("projectDockWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(projectDockWidget->sizePolicy().hasHeightForWidth());
        projectDockWidget->setSizePolicy(sizePolicy1);
        projectDockWidget->setContextMenuPolicy(Qt::PreventContextMenu);
        projectDockWidget->setFloating(false);
        projectDockWidget->setFeatures(QDockWidget::AllDockWidgetFeatures);
        projectDockWidget->setAllowedAreas(Qt::LeftDockWidgetArea|Qt::RightDockWidgetArea);
        dockWidgetContents_6 = new QWidget();
        dockWidgetContents_6->setObjectName(QString::fromUtf8("dockWidgetContents_6"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_6);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        projectComboBox = new QComboBox(dockWidgetContents_6);
        projectComboBox->setObjectName(QString::fromUtf8("projectComboBox"));
        projectComboBox->setMinimumSize(QSize(0, 21));

        verticalLayout_2->addWidget(projectComboBox);

        stackedWidget = new QStackedWidget(dockWidgetContents_6);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pgProjectTree = new QWidget();
        pgProjectTree->setObjectName(QString::fromUtf8("pgProjectTree"));
        verticalLayout = new QVBoxLayout(pgProjectTree);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        searchboxLayout_4 = new QHBoxLayout();
        searchboxLayout_4->setSpacing(0);
        searchboxLayout_4->setObjectName(QString::fromUtf8("searchboxLayout_4"));
        toolButton = new QToolButton(pgProjectTree);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        searchboxLayout_4->addWidget(toolButton);

        searchbox_4 = new QLineEdit(pgProjectTree);
        searchbox_4->setObjectName(QString::fromUtf8("searchbox_4"));

        searchboxLayout_4->addWidget(searchbox_4);

        searchboxClear_4 = new QToolButton(pgProjectTree);
        searchboxClear_4->setObjectName(QString::fromUtf8("searchboxClear_4"));
        QIcon icon47;
        icon47.addFile(QString::fromUtf8(":/resources/RES/clear_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        searchboxClear_4->setIcon(icon47);
        searchboxClear_4->setAutoRaise(true);

        searchboxLayout_4->addWidget(searchboxClear_4);


        verticalLayout->addLayout(searchboxLayout_4);

        projectTree = new QTreeView(pgProjectTree);
        projectTree->setObjectName(QString::fromUtf8("projectTree"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(projectTree->sizePolicy().hasHeightForWidth());
        projectTree->setSizePolicy(sizePolicy2);
        projectTree->setSizeIncrement(QSize(10, 10));
        projectTree->setBaseSize(QSize(100, 0));
        projectTree->setContextMenuPolicy(Qt::CustomContextMenu);
        projectTree->setEditTriggers(QAbstractItemView::EditKeyPressed|QAbstractItemView::SelectedClicked);
        projectTree->setProperty("showDropIndicator", QVariant(true));
        projectTree->setDragEnabled(true);
        projectTree->setDragDropMode(QAbstractItemView::DragDrop);
        projectTree->setDefaultDropAction(Qt::IgnoreAction);
        projectTree->setIconSize(QSize(16, 16));
        projectTree->setIndentation(16);
        projectTree->setRootIsDecorated(false);
        projectTree->setUniformRowHeights(true);
        projectTree->setHeaderHidden(true);
        projectTree->setExpandsOnDoubleClick(true);

        verticalLayout->addWidget(projectTree);

        stackedWidget->addWidget(pgProjectTree);
        pgImages = new QWidget();
        pgImages->setObjectName(QString::fromUtf8("pgImages"));
        verticalLayout_4 = new QVBoxLayout(pgImages);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        AddRemove = new QWidget(pgImages);
        AddRemove->setObjectName(QString::fromUtf8("AddRemove"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(AddRemove->sizePolicy().hasHeightForWidth());
        AddRemove->setSizePolicy(sizePolicy3);
        verticalLayout_3 = new QVBoxLayout(AddRemove);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(1);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        addImage = new QToolButton(AddRemove);
        addImage->setObjectName(QString::fromUtf8("addImage"));
        QIcon icon48;
        icon48.addFile(QString::fromUtf8(":/resources/RES/ffficons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addImage->setIcon(icon48);
        addImage->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_2->addWidget(addImage);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        delImage = new QToolButton(AddRemove);
        delImage->setObjectName(QString::fromUtf8("delImage"));
        QIcon icon49;
        icon49.addFile(QString::fromUtf8(":/resources/RES/ffficons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        delImage->setIcon(icon49);
        delImage->setAutoRaise(true);

        horizontalLayout_2->addWidget(delImage);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout_4->addWidget(AddRemove);

        searchboxLayout = new QHBoxLayout();
        searchboxLayout->setSpacing(3);
        searchboxLayout->setObjectName(QString::fromUtf8("searchboxLayout"));
        searchbox = new QLineEdit(pgImages);
        searchbox->setObjectName(QString::fromUtf8("searchbox"));

        searchboxLayout->addWidget(searchbox);

        searchboxClear = new QToolButton(pgImages);
        searchboxClear->setObjectName(QString::fromUtf8("searchboxClear"));
        searchboxClear->setIcon(icon47);
        searchboxClear->setAutoRaise(true);

        searchboxLayout->addWidget(searchboxClear);


        verticalLayout_4->addLayout(searchboxLayout);

        imageListWidget = new QListWidget(pgImages);
        imageListWidget->setObjectName(QString::fromUtf8("imageListWidget"));

        verticalLayout_4->addWidget(imageListWidget);

        stackedWidget->addWidget(pgImages);
        pgTreeView = new QWidget();
        pgTreeView->setObjectName(QString::fromUtf8("pgTreeView"));
        verticalLayout_6 = new QVBoxLayout(pgTreeView);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        AddRemove_2 = new QWidget(pgTreeView);
        AddRemove_2->setObjectName(QString::fromUtf8("AddRemove_2"));
        sizePolicy3.setHeightForWidth(AddRemove_2->sizePolicy().hasHeightForWidth());
        AddRemove_2->setSizePolicy(sizePolicy3);
        verticalLayout_5 = new QVBoxLayout(AddRemove_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(1);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        addSomething = new QToolButton(AddRemove_2);
        addSomething->setObjectName(QString::fromUtf8("addSomething"));
        addSomething->setIcon(icon48);
        addSomething->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(addSomething);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        delSomething = new QToolButton(AddRemove_2);
        delSomething->setObjectName(QString::fromUtf8("delSomething"));
        delSomething->setIcon(icon49);
        delSomething->setAutoRaise(true);

        horizontalLayout_3->addWidget(delSomething);


        verticalLayout_5->addLayout(horizontalLayout_3);


        verticalLayout_6->addWidget(AddRemove_2);

        searchboxLayout_2 = new QHBoxLayout();
        searchboxLayout_2->setSpacing(3);
        searchboxLayout_2->setObjectName(QString::fromUtf8("searchboxLayout_2"));
        searchbox_2 = new QLineEdit(pgTreeView);
        searchbox_2->setObjectName(QString::fromUtf8("searchbox_2"));

        searchboxLayout_2->addWidget(searchbox_2);

        searchboxClear_2 = new QToolButton(pgTreeView);
        searchboxClear_2->setObjectName(QString::fromUtf8("searchboxClear_2"));
        searchboxClear_2->setIcon(icon47);
        searchboxClear_2->setAutoRaise(true);

        searchboxLayout_2->addWidget(searchboxClear_2);


        verticalLayout_6->addLayout(searchboxLayout_2);

        somethingLV = new QListView(pgTreeView);
        somethingLV->setObjectName(QString::fromUtf8("somethingLV"));

        verticalLayout_6->addWidget(somethingLV);

        stackedWidget->addWidget(pgTreeView);
        pgShaders = new QWidget();
        pgShaders->setObjectName(QString::fromUtf8("pgShaders"));
        verticalLayout_7 = new QVBoxLayout(pgShaders);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(3, 3, 3, 3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        groupBox = new QGroupBox(pgShaders);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_8 = new QVBoxLayout(groupBox);
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setContentsMargins(3, 3, 3, 3);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        radioButton = new QRadioButton(groupBox);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(radioButton->sizePolicy().hasHeightForWidth());
        radioButton->setSizePolicy(sizePolicy4);

        verticalLayout_8->addWidget(radioButton);

        radioButton_2 = new QRadioButton(groupBox);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        sizePolicy4.setHeightForWidth(radioButton_2->sizePolicy().hasHeightForWidth());
        radioButton_2->setSizePolicy(sizePolicy4);

        verticalLayout_8->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(groupBox);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));
        sizePolicy4.setHeightForWidth(radioButton_3->sizePolicy().hasHeightForWidth());
        radioButton_3->setSizePolicy(sizePolicy4);

        verticalLayout_8->addWidget(radioButton_3);

        radioButton_4 = new QRadioButton(groupBox);
        radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));
        radioButton_4->setEnabled(false);
        sizePolicy4.setHeightForWidth(radioButton_4->sizePolicy().hasHeightForWidth());
        radioButton_4->setSizePolicy(sizePolicy4);

        verticalLayout_8->addWidget(radioButton_4);

        radioButton_5 = new QRadioButton(groupBox);
        radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));
        radioButton_5->setEnabled(false);
        sizePolicy4.setHeightForWidth(radioButton_5->sizePolicy().hasHeightForWidth());
        radioButton_5->setSizePolicy(sizePolicy4);

        verticalLayout_8->addWidget(radioButton_5);

        AddRemove_3 = new QWidget(groupBox);
        AddRemove_3->setObjectName(QString::fromUtf8("AddRemove_3"));
        sizePolicy3.setHeightForWidth(AddRemove_3->sizePolicy().hasHeightForWidth());
        AddRemove_3->setSizePolicy(sizePolicy3);
        verticalLayout_11 = new QVBoxLayout(AddRemove_3);
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setContentsMargins(0, 0, 0, 0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(1);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        toolButton_3 = new QToolButton(AddRemove_3);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        toolButton_3->setIcon(icon48);
        toolButton_3->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_7->addWidget(toolButton_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_4);

        toolButton_4 = new QToolButton(AddRemove_3);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        toolButton_4->setIcon(icon49);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_7->addWidget(toolButton_4);


        verticalLayout_11->addLayout(horizontalLayout_7);


        verticalLayout_8->addWidget(AddRemove_3);


        verticalLayout_9->addWidget(groupBox);


        verticalLayout_7->addLayout(verticalLayout_9);

        searchboxLayout_3 = new QHBoxLayout();
        searchboxLayout_3->setSpacing(3);
        searchboxLayout_3->setObjectName(QString::fromUtf8("searchboxLayout_3"));
        searchbox_3 = new QLineEdit(pgShaders);
        searchbox_3->setObjectName(QString::fromUtf8("searchbox_3"));

        searchboxLayout_3->addWidget(searchbox_3);

        searchboxClear_3 = new QToolButton(pgShaders);
        searchboxClear_3->setObjectName(QString::fromUtf8("searchboxClear_3"));
        searchboxClear_3->setIcon(icon47);
        searchboxClear_3->setAutoRaise(true);

        searchboxLayout_3->addWidget(searchboxClear_3);


        verticalLayout_7->addLayout(searchboxLayout_3);

        listWidget = new QListWidget(pgShaders);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        sizePolicy2.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy2);

        verticalLayout_7->addWidget(listWidget);

        stackedWidget->addWidget(pgShaders);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QString::fromUtf8("page_4"));
        stackedWidget->addWidget(page_4);
        page_5 = new QWidget();
        page_5->setObjectName(QString::fromUtf8("page_5"));
        stackedWidget->addWidget(page_5);

        verticalLayout_2->addWidget(stackedWidget);

        projectDockWidget->setWidget(dockWidgetContents_6);
        MainWindow->addDockWidget(static_cast<Qt::DockWidgetArea>(1), projectDockWidget);
        runToolbar = new QToolBar(MainWindow);
        runToolbar->setObjectName(QString::fromUtf8("runToolbar"));
        runToolbar->setContextMenuPolicy(Qt::PreventContextMenu);
        runToolbar->setIconSize(QSize(16, 16));
        MainWindow->addToolBar(Qt::TopToolBarArea, runToolbar);
        viewToolbar = new QToolBar(MainWindow);
        viewToolbar->setObjectName(QString::fromUtf8("viewToolbar"));
        viewToolbar->setContextMenuPolicy(Qt::PreventContextMenu);
        viewToolbar->setIconSize(QSize(16, 16));
        viewToolbar->setFloatable(true);
        MainWindow->addToolBar(Qt::LeftToolBarArea, viewToolbar);

        menuBar->addAction(menu_File->menuAction());
        menuBar->addAction(menuView->menuAction());
        menuBar->addAction(menuResources->menuAction());
        menuBar->addAction(menu_Project->menuAction());
        menuBar->addAction(menuWindow->menuAction());
        menuBar->addAction(menu_Help->menuAction());
        menuBar->addAction(menuDeveloper->menuAction());
        menu_File->addAction(actionCreate_project);
        menu_File->addAction(actionOpen_project);
        menu_File->addSeparator();
        menu_File->addAction(action_Save);
        menu_File->addAction(actionSave_as);
        menu_File->addAction(actionSave_a_ll);
        menu_File->addSeparator();
        menu_File->addAction(action_Pack_project);
        menu_File->addAction(actionExport_project);
        menu_File->addSeparator();
        menu_File->addAction(actionSet_up_collaboration);
        menu_File->addAction(action_Preferences);
        menu_File->addSeparator();
        menu_File->addAction(actionExit);
        menu_Help->addAction(actionPiGameCreator_help);
        menu_Help->addAction(actionAPI_documentation);
        menu_Help->addSeparator();
        menu_Help->addAction(actionYour_first_game);
        menu_Help->addAction(actionTutorials);
        menu_Help->addSeparator();
        menu_Help->addAction(actionCheck_for_updates);
        menu_Help->addAction(actionLicensing);
        menu_Help->addSeparator();
        menu_Help->addAction(actionVisit_piGameCreator_website);
        menu_Help->addAction(actionAbout_piGameCreator);
        menuWindow->addAction(actionClose_active_tab);
        menuWindow->addAction(actionClose_all_tabs);
        menuWindow->addSeparator();
        menuWindow->addAction(actionShowLog);
        menuWindow->addAction(actionShow_Main_page);
        menuResources->addAction(actionCreate_image);
        menuResources->addAction(actionCreate_sound);
        menuResources->addAction(actionCreate_model);
        menuResources->addSeparator();
        menuResources->addAction(actionAdd_class);
        menuResources->addAction(actionAdd_global_function);
        menuResources->addAction(actionDefine_grid);
        menuResources->addSeparator();
        menuResources->addAction(actionCreate_Font);
        menuResources->addAction(actionCreate_Shader);
        menuResources->addAction(actionAdd_Effect);
        menuResources->addSeparator();
        menuResources->addAction(actionCreate_2D_scene);
        menuResources->addAction(actionImport_resources_from_project);
        menuResources->addAction(actionClone_resource);
        menuResources->addAction(actionExport_resource);
        menuResources->addAction(actionExport_some_resources);
        menuResources->addSeparator();
        menuResources->addAction(actionEdit_application_settings);
        menu_Project->addAction(action_Run);
        menu_Project->addAction(action_Debug);
        menu_Project->addAction(actionBuild);
        menu_Project->addAction(actionClean);
        menu_Project->addAction(action_Parameters);
        menu_Project->addAction(actionTarget_options);
        menu_Project->addSeparator();
        menu_Project->addAction(action_Targets);
        menu_Project->addAction(action_Project_options);
        menu_Project->addSeparator();
        menu_Project->addAction(actionExport_project);
        menuDeveloper->addAction(actionSkin_editor);
        menuDeveloper->addAction(actionFramework_editor);
        menuDeveloper->addAction(actionEdit_Haxe_stdlib);
        menuView->addAction(actionSkins);
        menuView->addAction(actionToolbars);
        menuView->addSeparator();
        menuView->addAction(actionProject_tree);
        menuView->addSeparator();
        menuView->addAction(actionImages);
        menuView->addAction(actionModels);
        menuView->addAction(actionSounds);
        menuView->addSeparator();
        menuView->addAction(actionClasses);
        menuView->addAction(actionGlobal_functions);
        menuView->addSeparator();
        menuView->addAction(actionScenes);
        menuView->addSeparator();
        menuView->addAction(actionFonts);
        menuView->addAction(actionFilters);
        menuView->addAction(actionGraphics_effects);
        projectToolbar->addAction(actionCreate_project);
        projectToolbar->addAction(actionOpen_project);
        projectToolbar->addAction(action_Save);
        runToolbar->addAction(action_Run);
        runToolbar->addAction(action_Debug);
        runToolbar->addSeparator();
        runToolbar->addAction(action_Targets);
        runToolbar->addSeparator();
        runToolbar->addAction(actionBuild);
        viewToolbar->addAction(actionProject_tree);
        viewToolbar->addSeparator();
        viewToolbar->addAction(actionImages);
        viewToolbar->addAction(actionModels);
        viewToolbar->addAction(actionSounds);
        viewToolbar->addSeparator();
        viewToolbar->addAction(actionClasses);
        viewToolbar->addAction(actionGlobal_functions);
        viewToolbar->addSeparator();
        viewToolbar->addAction(actionScenes);
        viewToolbar->addSeparator();
        viewToolbar->addAction(actionFonts);
        viewToolbar->addAction(actionFilters);
        viewToolbar->addAction(actionGraphics_effects);

        retranslateUi(MainWindow);

        WorkSpaceTabWidget->setCurrentIndex(-1);
        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionExit->setToolTip(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionOpen_project->setText(QApplication::translate("MainWindow", "&Open project...", 0, QApplication::UnicodeUTF8));
        actionOpen_project->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", 0, QApplication::UnicodeUTF8));
        actionCreate_project->setText(QApplication::translate("MainWindow", "Create &new project...", 0, QApplication::UnicodeUTF8));
        actionCreate_project->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0, QApplication::UnicodeUTF8));
        actionPiGameCreator_help->setText(QApplication::translate("MainWindow", "Creator IDE help", 0, QApplication::UnicodeUTF8));
        actionPiGameCreator_help->setShortcut(QApplication::translate("MainWindow", "F1", 0, QApplication::UnicodeUTF8));
        actionYour_first_game->setText(QApplication::translate("MainWindow", "Your first game", 0, QApplication::UnicodeUTF8));
        actionTutorials->setText(QApplication::translate("MainWindow", "Tutorials", 0, QApplication::UnicodeUTF8));
        actionTutorials->setShortcut(QApplication::translate("MainWindow", "Ctrl+F1", 0, QApplication::UnicodeUTF8));
        actionAbout_piGameCreator->setText(QApplication::translate("MainWindow", "About piGameCreator", 0, QApplication::UnicodeUTF8));
        actionVisit_piGameCreator_website->setText(QApplication::translate("MainWindow", "Visit <b>pi|engine</b> website", 0, QApplication::UnicodeUTF8));
        actionCheck_for_updates->setText(QApplication::translate("MainWindow", "Check for updates...", 0, QApplication::UnicodeUTF8));
        actionAPI_documentation->setText(QApplication::translate("MainWindow", "Help for developers", 0, QApplication::UnicodeUTF8));
        actionLicensing->setText(QApplication::translate("MainWindow", "Licensing...", 0, QApplication::UnicodeUTF8));
        actionShowLog->setText(QApplication::translate("MainWindow", "Show &Log", 0, QApplication::UnicodeUTF8));
        actionShowLog->setShortcut(QApplication::translate("MainWindow", "Ctrl+L", 0, QApplication::UnicodeUTF8));
        actionTEST->setText(QApplication::translate("MainWindow", "TEST", 0, QApplication::UnicodeUTF8));
        actionClose_active_tab->setText(QApplication::translate("MainWindow", "Close active &tab", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionClose_active_tab->setToolTip(QApplication::translate("MainWindow", "Closes the active tag", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionClose_active_tab->setShortcut(QApplication::translate("MainWindow", "Ctrl+F4", 0, QApplication::UnicodeUTF8));
        actionClose_all_tabs->setText(QApplication::translate("MainWindow", "Close &all tabs", 0, QApplication::UnicodeUTF8));
        actionImport_resources_from_project->setText(QApplication::translate("MainWindow", "Import resources...", 0, QApplication::UnicodeUTF8));
        actionCreate_image->setText(QApplication::translate("MainWindow", "Create Image", 0, QApplication::UnicodeUTF8));
        actionCreate_image->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+I", 0, QApplication::UnicodeUTF8));
        actionCreate_sound->setText(QApplication::translate("MainWindow", "Create Sound", 0, QApplication::UnicodeUTF8));
        actionCreate_sound->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+U", 0, QApplication::UnicodeUTF8));
        actionCreate_GUI_layer->setText(QApplication::translate("MainWindow", "Create GUI layer", 0, QApplication::UnicodeUTF8));
        actionCreate_GUI_layer->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+G", 0, QApplication::UnicodeUTF8));
        actionCreate_2D_scene->setText(QApplication::translate("MainWindow", "Create scene", 0, QApplication::UnicodeUTF8));
        actionCreate_2D_scene->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+S", 0, QApplication::UnicodeUTF8));
        actionCreate_grid_based_2D_scene->setText(QApplication::translate("MainWindow", "Create grid-based 2D scene", 0, QApplication::UnicodeUTF8));
        actionCreate_grid_based_2D_scene->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+2", 0, QApplication::UnicodeUTF8));
        actionClone_resource->setText(QApplication::translate("MainWindow", "Clone resource...", 0, QApplication::UnicodeUTF8));
        actionClone_resource->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+C", 0, QApplication::UnicodeUTF8));
        actionExport_resource->setText(QApplication::translate("MainWindow", "Export resource...", 0, QApplication::UnicodeUTF8));
        actionAdd_class->setText(QApplication::translate("MainWindow", "Create Class", 0, QApplication::UnicodeUTF8));
        actionAdd_class->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+C", 0, QApplication::UnicodeUTF8));
        actionAdd_global_function->setText(QApplication::translate("MainWindow", "Add global script", 0, QApplication::UnicodeUTF8));
        actionAdd_global_function->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+U", 0, QApplication::UnicodeUTF8));
        actionCreate_model->setText(QApplication::translate("MainWindow", "Create Model", 0, QApplication::UnicodeUTF8));
        actionCreate_model->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+M", 0, QApplication::UnicodeUTF8));
        actionExport_some_resources->setText(QApplication::translate("MainWindow", "Export some resources...", 0, QApplication::UnicodeUTF8));
        actionCreate_class_template->setText(QApplication::translate("MainWindow", "Create Class template...", 0, QApplication::UnicodeUTF8));
        actionDefine_grid->setText(QApplication::translate("MainWindow", "Define sprite sheet", 0, QApplication::UnicodeUTF8));
        actionEdit_application_settings->setText(QApplication::translate("MainWindow", "Edit application settings", 0, QApplication::UnicodeUTF8));
        actionCreate_Font->setText(QApplication::translate("MainWindow", "Create Font", 0, QApplication::UnicodeUTF8));
        actionCreate_Font->setShortcut(QApplication::translate("MainWindow", "Ctrl+Alt+F", 0, QApplication::UnicodeUTF8));
        actionShow_Main_page->setText(QApplication::translate("MainWindow", "&Main page", 0, QApplication::UnicodeUTF8));
        actionShow_Main_page->setShortcut(QApplication::translate("MainWindow", "Ctrl+M", 0, QApplication::UnicodeUTF8));
        action_Save->setText(QApplication::translate("MainWindow", "&Save project", 0, QApplication::UnicodeUTF8));
        action_Save->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", 0, QApplication::UnicodeUTF8));
        actionSave_as->setText(QApplication::translate("MainWindow", "Save project &as...", 0, QApplication::UnicodeUTF8));
        actionSave_as->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+S", 0, QApplication::UnicodeUTF8));
        actionSave_a_ll->setText(QApplication::translate("MainWindow", "Save a&ll projects", 0, QApplication::UnicodeUTF8));
        action_Run->setText(QApplication::translate("MainWindow", "&Run", 0, QApplication::UnicodeUTF8));
        action_Run->setShortcut(QApplication::translate("MainWindow", "F5", 0, QApplication::UnicodeUTF8));
        action_Debug->setText(QApplication::translate("MainWindow", "&Debug", 0, QApplication::UnicodeUTF8));
        action_Parameters->setText(QApplication::translate("MainWindow", "&Parameters...", 0, QApplication::UnicodeUTF8));
        action_Targets->setText(QApplication::translate("MainWindow", "&Targets...", 0, QApplication::UnicodeUTF8));
        action_Project_options->setText(QApplication::translate("MainWindow", "&Project options...", 0, QApplication::UnicodeUTF8));
        actionCreate_vector_path->setText(QApplication::translate("MainWindow", "Create &vector path", 0, QApplication::UnicodeUTF8));
        actionBuild->setText(QApplication::translate("MainWindow", "Build", 0, QApplication::UnicodeUTF8));
        actionCreate_Shader->setText(QApplication::translate("MainWindow", "Create Filter", 0, QApplication::UnicodeUTF8));
        actionTarget_options->setText(QApplication::translate("MainWindow", "Target options...", 0, QApplication::UnicodeUTF8));
        actionToolbars->setText(QApplication::translate("MainWindow", "Toolbars", 0, QApplication::UnicodeUTF8));
        action_Pack_project->setText(QApplication::translate("MainWindow", "&Pack project...", 0, QApplication::UnicodeUTF8));
        action_Preferences->setText(QApplication::translate("MainWindow", "&Preferences...", 0, QApplication::UnicodeUTF8));
        action_Preferences->setShortcut(QApplication::translate("MainWindow", "Ctrl+Shift+P", 0, QApplication::UnicodeUTF8));
        actionSet_up_collaboration->setText(QApplication::translate("MainWindow", "Set up &collaboration...", 0, QApplication::UnicodeUTF8));
        actionSkins->setText(QApplication::translate("MainWindow", "Skins", 0, QApplication::UnicodeUTF8));
        actionGameScript_tester->setText(QApplication::translate("MainWindow", "Haxe playground", 0, QApplication::UnicodeUTF8));
        actionSkin_editor->setText(QApplication::translate("MainWindow", "Skin editor", 0, QApplication::UnicodeUTF8));
        actionFramework_editor->setText(QApplication::translate("MainWindow", "Edit pi|engine", 0, QApplication::UnicodeUTF8));
        actionProject_tree->setText(QApplication::translate("MainWindow", "Project tree", 0, QApplication::UnicodeUTF8));
        actionImages->setText(QApplication::translate("MainWindow", "Images", 0, QApplication::UnicodeUTF8));
        actionSounds->setText(QApplication::translate("MainWindow", "Sounds", 0, QApplication::UnicodeUTF8));
        actionScenes->setText(QApplication::translate("MainWindow", "Scenes", 0, QApplication::UnicodeUTF8));
        actionClasses->setText(QApplication::translate("MainWindow", "Classes", 0, QApplication::UnicodeUTF8));
        actionModels->setText(QApplication::translate("MainWindow", "Models", 0, QApplication::UnicodeUTF8));
        actionFonts->setText(QApplication::translate("MainWindow", "Fonts", 0, QApplication::UnicodeUTF8));
        actionFilters->setText(QApplication::translate("MainWindow", "Filters", 0, QApplication::UnicodeUTF8));
        actionAdd_Effect->setText(QApplication::translate("MainWindow", "Create Graphics Effect", 0, QApplication::UnicodeUTF8));
        actionGraphics_effects->setText(QApplication::translate("MainWindow", "Graphics Effects", 0, QApplication::UnicodeUTF8));
        actionGlobal_functions->setText(QApplication::translate("MainWindow", "Global scripts", 0, QApplication::UnicodeUTF8));
        actionEdit_Haxe_stdlib->setText(QApplication::translate("MainWindow", "Edit Haxe stdlib", 0, QApplication::UnicodeUTF8));
        actionExport_project->setText(QApplication::translate("MainWindow", "Export project...", 0, QApplication::UnicodeUTF8));
        actionClean->setText(QApplication::translate("MainWindow", "Clean", 0, QApplication::UnicodeUTF8));
        menu_File->setTitle(QApplication::translate("MainWindow", "&File", 0, QApplication::UnicodeUTF8));
        menu_Help->setTitle(QApplication::translate("MainWindow", "&Help", 0, QApplication::UnicodeUTF8));
        menuWindow->setTitle(QApplication::translate("MainWindow", "&Window", 0, QApplication::UnicodeUTF8));
        menuResources->setTitle(QApplication::translate("MainWindow", "Resources", 0, QApplication::UnicodeUTF8));
        menu_Project->setTitle(QApplication::translate("MainWindow", "&Project", 0, QApplication::UnicodeUTF8));
        menuDeveloper->setTitle(QApplication::translate("MainWindow", "&Developer", 0, QApplication::UnicodeUTF8));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0, QApplication::UnicodeUTF8));
        projectToolbar->setWindowTitle(QApplication::translate("MainWindow", "Standard", 0, QApplication::UnicodeUTF8));
        projectDockWidget->setWindowTitle(QApplication::translate("MainWindow", "Project tree", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("MainWindow", "...", 0, QApplication::UnicodeUTF8));
        searchboxClear_4->setText(QString());
        addImage->setText(QApplication::translate("MainWindow", "Add image", 0, QApplication::UnicodeUTF8));
        delImage->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        searchboxClear->setText(QString());
        addSomething->setText(QApplication::translate("MainWindow", "Add sth", 0, QApplication::UnicodeUTF8));
        delSomething->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        searchboxClear_2->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Shader types:", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("MainWindow", "Fragment / Pixel", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("MainWindow", "Vertex", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("MainWindow", "Geometry", 0, QApplication::UnicodeUTF8));
        radioButton_4->setText(QApplication::translate("MainWindow", "Tessellation Control / Hull", 0, QApplication::UnicodeUTF8));
        radioButton_5->setText(QApplication::translate("MainWindow", "Tessellation Evaluation / Domain", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("MainWindow", "Add", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("MainWindow", "Delete", 0, QApplication::UnicodeUTF8));
        searchboxClear_3->setText(QString());
        runToolbar->setWindowTitle(QApplication::translate("MainWindow", "Debug and Run", 0, QApplication::UnicodeUTF8));
        viewToolbar->setWindowTitle(QApplication::translate("MainWindow", "Resources", 0, QApplication::UnicodeUTF8));
        Q_UNUSED(MainWindow);
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
