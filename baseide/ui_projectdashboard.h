/********************************************************************************
** Form generated from reading UI file 'projectdashboard.ui'
**
** Created: Fri 2. Nov 07:45:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTDASHBOARD_H
#define UI_PROJECTDASHBOARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectDashboard
{
public:
    QAction *actionEdit_this_module;
    QAction *actionRemove_as_Main_Module;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *DashboardSW;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QFormLayout *formLayout;
    QToolButton *toolButton;
    QHBoxLayout *horizontalLayout;
    QLabel *prolectIconLabel;
    QLabel *projectTitleLabel;
    QToolButton *wallpaperOptions;
    QToolButton *toolButton_2;
    QLabel *projectDescLabel;
    QStackedWidget *BottomPartSW;
    QWidget *bpNone;
    QWidget *bpCalendar;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QCalendarWidget *calendarWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *dateNotes;
    QWidget *bpBasicInfo;
    QVBoxLayout *verticalLayout_6;
    QSpacerItem *verticalSpacer_2;
    QFrame *basicInfoContainer;
    QVBoxLayout *verticalLayout_8;
    QFormLayout *formLayout_2;
    QLabel *label_5;
    QLabel *label_6;
    QPlainTextEdit *projectDescription;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *projectIcon;
    QLineEdit *projectTitle;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_7;
    QLineEdit *projectAuthor;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_3;
    QLineEdit *projectAppVersion;
    QPushButton *buildTargetsBtn;
    QWidget *bpModules;
    QVBoxLayout *verticalLayout_9;
    QFrame *modulesContainerFrame;
    QGridLayout *gridLayout;
    QSpacerItem *verticalSpacer_3;
    QFrame *modulesContainer;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QFrame *modulesFrame;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *addModule;
    QFrame *line;
    QHBoxLayout *modulesLayout;
    QSpacerItem *horizontalSpacer_3;
    QWidget *buttonsBar;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pbCalendar;
    QPushButton *pbBasicInfo;
    QPushButton *pbModules;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbHelp;
    QWidget *UIPages;
    QWidget *addModuleWindow;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QLabel *label_13;
    QLineEdit *searchClass;
    QToolButton *toolButton_6;
    QListWidget *availableClassesWidget;
    QDialogButtonBox *addModuleButtonBox;
    QFrame *wallpaperWidgetFrame;
    QGridLayout *gridLayout_3;
    QToolButton *toolButton_10;
    QToolButton *toolButton_8;
    QToolButton *toolButton_9;
    QToolButton *toolButton_11;
    QMenuBar *menuBar;
    QMenu *menuModule;

    void setupUi(QMainWindow *ProjectDashboard)
    {
        if (ProjectDashboard->objectName().isEmpty())
            ProjectDashboard->setObjectName(QString::fromUtf8("ProjectDashboard"));
        ProjectDashboard->resize(709, 449);
        ProjectDashboard->setStyleSheet(QString::fromUtf8("#DashboardSW\n"
"{\n"
"	background-image: url('D:/projects/zzzzz/wallpaper.jpg');\n"
"}\n"
"\n"
"#projectTitleLabel,\n"
"#projectDescLabel\n"
" {color:#999}\n"
"\n"
""));
        actionEdit_this_module = new QAction(ProjectDashboard);
        actionEdit_this_module->setObjectName(QString::fromUtf8("actionEdit_this_module"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/brick.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_this_module->setIcon(icon);
        actionRemove_as_Main_Module = new QAction(ProjectDashboard);
        actionRemove_as_Main_Module->setObjectName(QString::fromUtf8("actionRemove_as_Main_Module"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove_as_Main_Module->setIcon(icon1);
        centralwidget = new QWidget(ProjectDashboard);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        DashboardSW = new QStackedWidget(centralwidget);
        DashboardSW->setObjectName(QString::fromUtf8("DashboardSW"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setHorizontalSpacing(6);
        formLayout->setVerticalSpacing(6);
        formLayout->setContentsMargins(9, 9, 9, 0);
        toolButton = new QToolButton(page);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));

        formLayout->setWidget(0, QFormLayout::LabelRole, toolButton);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        prolectIconLabel = new QLabel(page);
        prolectIconLabel->setObjectName(QString::fromUtf8("prolectIconLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(prolectIconLabel->sizePolicy().hasHeightForWidth());
        prolectIconLabel->setSizePolicy(sizePolicy);
        prolectIconLabel->setPixmap(QPixmap(QString::fromUtf8(":/resources/RES/ffficons/page_white.png")));

        horizontalLayout->addWidget(prolectIconLabel);

        projectTitleLabel = new QLabel(page);
        projectTitleLabel->setObjectName(QString::fromUtf8("projectTitleLabel"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        projectTitleLabel->setFont(font);

        horizontalLayout->addWidget(projectTitleLabel);

        wallpaperOptions = new QToolButton(page);
        wallpaperOptions->setObjectName(QString::fromUtf8("wallpaperOptions"));
        wallpaperOptions->setPopupMode(QToolButton::InstantPopup);

        horizontalLayout->addWidget(wallpaperOptions);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout);

        toolButton_2 = new QToolButton(page);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, toolButton_2);

        projectDescLabel = new QLabel(page);
        projectDescLabel->setObjectName(QString::fromUtf8("projectDescLabel"));
        QFont font1;
        font1.setPointSize(11);
        projectDescLabel->setFont(font1);
        projectDescLabel->setAlignment(Qt::AlignJustify|Qt::AlignVCenter);
        projectDescLabel->setWordWrap(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, projectDescLabel);


        verticalLayout_2->addLayout(formLayout);

        BottomPartSW = new QStackedWidget(page);
        BottomPartSW->setObjectName(QString::fromUtf8("BottomPartSW"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(BottomPartSW->sizePolicy().hasHeightForWidth());
        BottomPartSW->setSizePolicy(sizePolicy1);
        bpNone = new QWidget();
        bpNone->setObjectName(QString::fromUtf8("bpNone"));
        BottomPartSW->addWidget(bpNone);
        bpCalendar = new QWidget();
        bpCalendar->setObjectName(QString::fromUtf8("bpCalendar"));
        verticalLayout_5 = new QVBoxLayout(bpCalendar);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer);

        widget_2 = new QWidget(bpCalendar);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout_2 = new QHBoxLayout(widget_2);
#ifndef Q_OS_MAC
        horizontalLayout_2->setSpacing(6);
#endif
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_2 = new QFrame(widget_2);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        calendarWidget = new QCalendarWidget(frame_2);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(calendarWidget->sizePolicy().hasHeightForWidth());
        calendarWidget->setSizePolicy(sizePolicy2);
        calendarWidget->setFirstDayOfWeek(Qt::Monday);
        calendarWidget->setGridVisible(false);
        calendarWidget->setSelectionMode(QCalendarWidget::SingleSelection);
        calendarWidget->setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);
        calendarWidget->setVerticalHeaderFormat(QCalendarWidget::ISOWeekNumbers);
        calendarWidget->setNavigationBarVisible(true);
        calendarWidget->setDateEditEnabled(true);

        verticalLayout_4->addWidget(calendarWidget);


        horizontalLayout_2->addWidget(frame_2);

        widget = new QWidget(widget_2);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        dateNotes = new QTextEdit(widget);
        dateNotes->setObjectName(QString::fromUtf8("dateNotes"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dateNotes->sizePolicy().hasHeightForWidth());
        dateNotes->setSizePolicy(sizePolicy3);
        dateNotes->setReadOnly(true);

        verticalLayout_3->addWidget(dateNotes);


        horizontalLayout_2->addWidget(widget);


        verticalLayout_5->addWidget(widget_2);

        BottomPartSW->addWidget(bpCalendar);
        bpBasicInfo = new QWidget();
        bpBasicInfo->setObjectName(QString::fromUtf8("bpBasicInfo"));
        verticalLayout_6 = new QVBoxLayout(bpBasicInfo);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_2);

        basicInfoContainer = new QFrame(bpBasicInfo);
        basicInfoContainer->setObjectName(QString::fromUtf8("basicInfoContainer"));
        basicInfoContainer->setFrameShadow(QFrame::Raised);
        verticalLayout_8 = new QVBoxLayout(basicInfoContainer);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QString::fromUtf8("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_5 = new QLabel(basicInfoContainer);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font2;
        font2.setPointSize(10);
        font2.setBold(true);
        font2.setWeight(75);
        label_5->setFont(font2);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_5);

        label_6 = new QLabel(basicInfoContainer);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font2);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_6);

        projectDescription = new QPlainTextEdit(basicInfoContainer);
        projectDescription->setObjectName(QString::fromUtf8("projectDescription"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(projectDescription->sizePolicy().hasHeightForWidth());
        projectDescription->setSizePolicy(sizePolicy4);
        projectDescription->setMaximumSize(QSize(16777215, 50));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, projectDescription);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        projectIcon = new QToolButton(basicInfoContainer);
        projectIcon->setObjectName(QString::fromUtf8("projectIcon"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        projectIcon->setIcon(icon2);
        projectIcon->setAutoRaise(true);

        horizontalLayout_4->addWidget(projectIcon);

        projectTitle = new QLineEdit(basicInfoContainer);
        projectTitle->setObjectName(QString::fromUtf8("projectTitle"));

        horizontalLayout_4->addWidget(projectTitle);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_7 = new QLabel(basicInfoContainer);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QFont font3;
        font3.setBold(true);
        font3.setWeight(75);
        label_7->setFont(font3);

        horizontalLayout_5->addWidget(label_7);

        projectAuthor = new QLineEdit(basicInfoContainer);
        projectAuthor->setObjectName(QString::fromUtf8("projectAuthor"));
        projectAuthor->setMaximumSize(QSize(120, 16777215));

        horizontalLayout_5->addWidget(projectAuthor);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        label_3 = new QLabel(basicInfoContainer);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        projectAppVersion = new QLineEdit(basicInfoContainer);
        projectAppVersion->setObjectName(QString::fromUtf8("projectAppVersion"));
        projectAppVersion->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_5->addWidget(projectAppVersion);

        buildTargetsBtn = new QPushButton(basicInfoContainer);
        buildTargetsBtn->setObjectName(QString::fromUtf8("buildTargetsBtn"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/computer.png"), QSize(), QIcon::Normal, QIcon::Off);
        buildTargetsBtn->setIcon(icon3);

        horizontalLayout_5->addWidget(buildTargetsBtn);


        formLayout_2->setLayout(2, QFormLayout::SpanningRole, horizontalLayout_5);


        verticalLayout_8->addLayout(formLayout_2);


        verticalLayout_6->addWidget(basicInfoContainer);

        BottomPartSW->addWidget(bpBasicInfo);
        bpModules = new QWidget();
        bpModules->setObjectName(QString::fromUtf8("bpModules"));
        verticalLayout_9 = new QVBoxLayout(bpModules);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        verticalLayout_9->setContentsMargins(0, -1, 0, 0);
        modulesContainerFrame = new QFrame(bpModules);
        modulesContainerFrame->setObjectName(QString::fromUtf8("modulesContainerFrame"));
        modulesContainerFrame->setFrameShape(QFrame::StyledPanel);
        modulesContainerFrame->setFrameShadow(QFrame::Raised);
        gridLayout = new QGridLayout(modulesContainerFrame);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalSpacer_3 = new QSpacerItem(704, 396, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 0, 0, 1, 2);

        modulesContainer = new QFrame(modulesContainerFrame);
        modulesContainer->setObjectName(QString::fromUtf8("modulesContainer"));
        horizontalLayout_7 = new QHBoxLayout(modulesContainer);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(6, 9, 6, 6);
        label_8 = new QLabel(modulesContainer);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QFont font4;
        font4.setPointSize(11);
        font4.setBold(true);
        font4.setWeight(75);
        label_8->setFont(font4);

        horizontalLayout_7->addWidget(label_8);

        modulesFrame = new QFrame(modulesContainer);
        modulesFrame->setObjectName(QString::fromUtf8("modulesFrame"));
        sizePolicy4.setHeightForWidth(modulesFrame->sizePolicy().hasHeightForWidth());
        modulesFrame->setSizePolicy(sizePolicy4);
        modulesFrame->setFrameShape(QFrame::WinPanel);
        modulesFrame->setFrameShadow(QFrame::Sunken);
        horizontalLayout_8 = new QHBoxLayout(modulesFrame);
        horizontalLayout_8->setSpacing(3);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        addModule = new QToolButton(modulesFrame);
        addModule->setObjectName(QString::fromUtf8("addModule"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/application_cascade.png"), QSize(), QIcon::Normal, QIcon::Off);
        addModule->setIcon(icon4);
        addModule->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_8->addWidget(addModule);

        line = new QFrame(modulesFrame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);

        horizontalLayout_8->addWidget(line);

        modulesLayout = new QHBoxLayout();
        modulesLayout->setSpacing(1);
        modulesLayout->setObjectName(QString::fromUtf8("modulesLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        modulesLayout->addItem(horizontalSpacer_3);


        horizontalLayout_8->addLayout(modulesLayout);


        horizontalLayout_7->addWidget(modulesFrame);


        gridLayout->addWidget(modulesContainer, 1, 0, 1, 1);


        verticalLayout_9->addWidget(modulesContainerFrame);

        BottomPartSW->addWidget(bpModules);

        verticalLayout_2->addWidget(BottomPartSW);

        buttonsBar = new QWidget(page);
        buttonsBar->setObjectName(QString::fromUtf8("buttonsBar"));
        horizontalLayout_3 = new QHBoxLayout(buttonsBar);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pbCalendar = new QPushButton(buttonsBar);
        pbCalendar->setObjectName(QString::fromUtf8("pbCalendar"));
        pbCalendar->setCheckable(true);
        pbCalendar->setChecked(true);
        pbCalendar->setProperty("group1", QVariant(true));

        horizontalLayout_3->addWidget(pbCalendar);

        pbBasicInfo = new QPushButton(buttonsBar);
        pbBasicInfo->setObjectName(QString::fromUtf8("pbBasicInfo"));
        pbBasicInfo->setCheckable(true);
        pbBasicInfo->setProperty("group1", QVariant(true));

        horizontalLayout_3->addWidget(pbBasicInfo);

        pbModules = new QPushButton(buttonsBar);
        pbModules->setObjectName(QString::fromUtf8("pbModules"));
        pbModules->setCheckable(true);
        pbModules->setProperty("group1", QVariant(true));

        horizontalLayout_3->addWidget(pbModules);

        horizontalSpacer = new QSpacerItem(406, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        pbHelp = new QPushButton(buttonsBar);
        pbHelp->setObjectName(QString::fromUtf8("pbHelp"));

        horizontalLayout_3->addWidget(pbHelp);


        verticalLayout_2->addWidget(buttonsBar);

        DashboardSW->addWidget(page);
        UIPages = new QWidget();
        UIPages->setObjectName(QString::fromUtf8("UIPages"));
        addModuleWindow = new QWidget(UIPages);
        addModuleWindow->setObjectName(QString::fromUtf8("addModuleWindow"));
        addModuleWindow->setGeometry(QRect(32, 96, 274, 258));
        verticalLayout_10 = new QVBoxLayout(addModuleWindow);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        label_9 = new QLabel(addModuleWindow);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font3);

        verticalLayout_10->addWidget(label_9);

        label_10 = new QLabel(addModuleWindow);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        verticalLayout_10->addWidget(label_10);

        label_11 = new QLabel(addModuleWindow);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        QFont font5;
        font5.setFamily(QString::fromUtf8("Courier New"));
        label_11->setFont(font5);

        verticalLayout_10->addWidget(label_11);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_12 = new QLabel(addModuleWindow);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setPixmap(QPixmap(QString::fromUtf8(":/resources/RES/ffficons/zoom.png")));

        horizontalLayout_6->addWidget(label_12);

        label_13 = new QLabel(addModuleWindow);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_6->addWidget(label_13);

        searchClass = new QLineEdit(addModuleWindow);
        searchClass->setObjectName(QString::fromUtf8("searchClass"));

        horizontalLayout_6->addWidget(searchClass);

        toolButton_6 = new QToolButton(addModuleWindow);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/clear_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon5);
        toolButton_6->setAutoRaise(true);

        horizontalLayout_6->addWidget(toolButton_6);


        verticalLayout_10->addLayout(horizontalLayout_6);

        availableClassesWidget = new QListWidget(addModuleWindow);
        availableClassesWidget->setObjectName(QString::fromUtf8("availableClassesWidget"));

        verticalLayout_10->addWidget(availableClassesWidget);

        addModuleButtonBox = new QDialogButtonBox(addModuleWindow);
        addModuleButtonBox->setObjectName(QString::fromUtf8("addModuleButtonBox"));
        addModuleButtonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_10->addWidget(addModuleButtonBox);

        wallpaperWidgetFrame = new QFrame(UIPages);
        wallpaperWidgetFrame->setObjectName(QString::fromUtf8("wallpaperWidgetFrame"));
        wallpaperWidgetFrame->setGeometry(QRect(376, 88, 182, 53));
        gridLayout_3 = new QGridLayout(wallpaperWidgetFrame);
        gridLayout_3->setSpacing(3);
        gridLayout_3->setContentsMargins(3, 3, 3, 3);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        toolButton_10 = new QToolButton(wallpaperWidgetFrame);
        toolButton_10->setObjectName(QString::fromUtf8("toolButton_10"));
        QSizePolicy sizePolicy5(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(toolButton_10->sizePolicy().hasHeightForWidth());
        toolButton_10->setSizePolicy(sizePolicy5);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_10->setIcon(icon6);
        toolButton_10->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_3->addWidget(toolButton_10, 0, 0, 1, 1);

        toolButton_8 = new QToolButton(wallpaperWidgetFrame);
        toolButton_8->setObjectName(QString::fromUtf8("toolButton_8"));
        sizePolicy5.setHeightForWidth(toolButton_8->sizePolicy().hasHeightForWidth());
        toolButton_8->setSizePolicy(sizePolicy5);
        toolButton_8->setIcon(icon1);
        toolButton_8->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_3->addWidget(toolButton_8, 0, 1, 1, 1);

        toolButton_9 = new QToolButton(wallpaperWidgetFrame);
        toolButton_9->setObjectName(QString::fromUtf8("toolButton_9"));
        sizePolicy5.setHeightForWidth(toolButton_9->sizePolicy().hasHeightForWidth());
        toolButton_9->setSizePolicy(sizePolicy5);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/color_wheel.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_9->setIcon(icon7);
        toolButton_9->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_3->addWidget(toolButton_9, 1, 0, 1, 1);

        toolButton_11 = new QToolButton(wallpaperWidgetFrame);
        toolButton_11->setObjectName(QString::fromUtf8("toolButton_11"));
        sizePolicy5.setHeightForWidth(toolButton_11->sizePolicy().hasHeightForWidth());
        toolButton_11->setSizePolicy(sizePolicy5);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/RES/ffficons/arrow_refresh_small.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_11->setIcon(icon8);
        toolButton_11->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        gridLayout_3->addWidget(toolButton_11, 1, 1, 1, 1);

        DashboardSW->addWidget(UIPages);

        verticalLayout->addWidget(DashboardSW);

        ProjectDashboard->setCentralWidget(centralwidget);
        menuBar = new QMenuBar(ProjectDashboard);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 709, 19));
        menuModule = new QMenu(menuBar);
        menuModule->setObjectName(QString::fromUtf8("menuModule"));
        ProjectDashboard->setMenuBar(menuBar);

        menuBar->addAction(menuModule->menuAction());
        menuModule->addAction(actionEdit_this_module);
        menuModule->addAction(actionRemove_as_Main_Module);

        retranslateUi(ProjectDashboard);

        DashboardSW->setCurrentIndex(0);
        BottomPartSW->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(ProjectDashboard);
    } // setupUi

    void retranslateUi(QMainWindow *ProjectDashboard)
    {
        ProjectDashboard->setWindowTitle(QApplication::translate("ProjectDashboard", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionEdit_this_module->setText(QApplication::translate("ProjectDashboard", "Open in class editor", 0, QApplication::UnicodeUTF8));
        actionRemove_as_Main_Module->setText(QApplication::translate("ProjectDashboard", "Remove as main module", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("ProjectDashboard", "Edit", 0, QApplication::UnicodeUTF8));
        prolectIconLabel->setText(QString());
        projectTitleLabel->setText(QApplication::translate("ProjectDashboard", "Project Title", 0, QApplication::UnicodeUTF8));
        wallpaperOptions->setText(QApplication::translate("ProjectDashboard", "Wallpaper   ", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("ProjectDashboard", "Edit", 0, QApplication::UnicodeUTF8));
        projectDescLabel->setText(QApplication::translate("ProjectDashboard", "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean est neque, sodales interdum venenatis vel, hendrerit in nisi. Nulla quis tortor sed felis consequat fermentum. Nullam auctor ligula erat. Donec commodo dui a sapien viverra vel placerat nisi facilisis. Cras consequat hendrerit gravida. Aenean non blandit quam. Nunc nec enim sem. Nam mauris nisl, molestie id scelerisque quis, gravida nec lectus.", 0, QApplication::UnicodeUTF8));
        dateNotes->setHtml(QApplication::translate("ProjectDashboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">This feature is still not implemented.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("ProjectDashboard", "Title:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("ProjectDashboard", "Description:", 0, QApplication::UnicodeUTF8));
        projectIcon->setText(QString());
        label_7->setText(QApplication::translate("ProjectDashboard", "Company/Team:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ProjectDashboard", "App version:", 0, QApplication::UnicodeUTF8));
        buildTargetsBtn->setText(QApplication::translate("ProjectDashboard", "Build targets", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("ProjectDashboard", "Main modules", 0, QApplication::UnicodeUTF8));
        addModule->setText(QApplication::translate("ProjectDashboard", "Edit", 0, QApplication::UnicodeUTF8));
        pbCalendar->setText(QApplication::translate("ProjectDashboard", "Calendar", 0, QApplication::UnicodeUTF8));
        pbBasicInfo->setText(QApplication::translate("ProjectDashboard", "Basic info", 0, QApplication::UnicodeUTF8));
        pbModules->setText(QApplication::translate("ProjectDashboard", "Modules", 0, QApplication::UnicodeUTF8));
        pbHelp->setText(QApplication::translate("ProjectDashboard", "Help", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("ProjectDashboard", "Select a class to add as main module.", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("ProjectDashboard", "The class must contain:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("ProjectDashboard", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Courier New'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; font-weight:600;\">public</span><span style=\" font-size:8pt;\"> </span><span style=\" font-size:8pt; font-weight:600;\">function</span><span style=\" font-size:8pt;\"> main()</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_12->setText(QString());
        label_13->setText(QString());
        toolButton_6->setText(QApplication::translate("ProjectDashboard", "...", 0, QApplication::UnicodeUTF8));
        toolButton_10->setText(QApplication::translate("ProjectDashboard", "Wallpaper image", 0, QApplication::UnicodeUTF8));
        toolButton_8->setText(QApplication::translate("ProjectDashboard", "None", 0, QApplication::UnicodeUTF8));
        toolButton_9->setText(QApplication::translate("ProjectDashboard", "Text color", 0, QApplication::UnicodeUTF8));
        toolButton_11->setText(QApplication::translate("ProjectDashboard", "Reset", 0, QApplication::UnicodeUTF8));
        menuModule->setTitle(QApplication::translate("ProjectDashboard", "Module", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ProjectDashboard: public Ui_ProjectDashboard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTDASHBOARD_H
