/********************************************************************************
** Form generated from reading UI file 'eventclass.ui'
**
** Created: Fri 2. Nov 07:48:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENTCLASS_H
#define UI_EVENTCLASS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolBox>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_eventClass
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QFrame *previewFrame;
    QVBoxLayout *verticalLayout_6;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QToolButton *addEvent;
    QListWidget *EventsListWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QToolButton *addFunction;
    QListWidget *FunctionsListWidget;
    QPushButton *pushButton_3;
    QStackedWidget *stackedWidget;
    QWidget *PropertiesPage;
    QVBoxLayout *verticalLayout_2;
    QSplitter *splitter;
    QFrame *frame;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *lbClassVars;
    QToolButton *DelVars;
    QToolButton *addVariable;
    QTreeWidget *VarsList;
    QVBoxLayout *verticalLayout_9;
    QLabel *lbDefaultSettingsForInstances;
    QGridLayout *gridLayout;
    QCheckBox *cbGlobal;
    QCheckBox *cbPersistent;
    QHBoxLayout *horizontalLayout_7;
    QCheckBox *cbPhysical;
    QToolButton *tbPhysical;
    QSpacerItem *horizontalSpacer_3;
    QSpacerItem *horizontalSpacer_4;
    QSpacerItem *horizontalSpacer_5;
    QCheckBox *checkBox;
    QFrame *line;
    QHBoxLayout *horizontalLayout_5;
    QLabel *lbColisionMode;
    QRadioButton *rb2d;
    QRadioButton *rb3d;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lbBaseClass;
    QSpacerItem *horizontalSpacer;
    QPushButton *baseClassButton;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *lbDTProperties;
    QToolButton *DelProperties;
    QToolButton *addProperty;
    QTreeWidget *PropList;
    QVBoxLayout *verticalLayout_10;
    QHBoxLayout *horizontalLayout_10;
    QLabel *lbDTHelpers;
    QSpacerItem *horizontalSpacer_8;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QGridLayout *gridLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *horizontalSpacer_7;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *cbResizing;
    QToolButton *tbResizing;
    QSpacerItem *horizontalSpacer_10;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *cbRotation;
    QToolButton *tbRotation;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *cbRepresentation;
    QToolButton *tbRepresentation;
    QSpacerItem *horizontalSpacer_11;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *cbRepresentation_2;
    QToolButton *tbRepresentation_2;
    QSpacerItem *horizontalSpacer_12;
    QWidget *CodeEditPage;
    QHBoxLayout *horizontalLayout_4;
    QFrame *CodeEditorFrame;
    QVBoxLayout *verticalLayout_5;
    QToolBox *FunctionBox;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QWidget *FunctionEditPage;
    QVBoxLayout *verticalLayout_8;
    QLabel *label_3;
    QFrame *frame_3;

    void setupUi(QMainWindow *eventClass)
    {
        if (eventClass->objectName().isEmpty())
            eventClass->setObjectName(QString::fromUtf8("eventClass"));
        eventClass->resize(780, 466);
        centralwidget = new QWidget(eventClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        previewFrame = new QFrame(centralwidget);
        previewFrame->setObjectName(QString::fromUtf8("previewFrame"));
        previewFrame->setMinimumSize(QSize(120, 120));
        previewFrame->setMaximumSize(QSize(120, 120));
        previewFrame->setFrameShape(QFrame::Panel);
        previewFrame->setFrameShadow(QFrame::Sunken);
        previewFrame->setProperty("alphaChannel", QVariant(true));
        verticalLayout_6 = new QVBoxLayout(previewFrame);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));

        verticalLayout->addWidget(previewFrame);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/database.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setCheckable(true);
        pushButton->setChecked(true);

        verticalLayout->addWidget(pushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(3, -1, -1, -1);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        addEvent = new QToolButton(centralwidget);
        addEvent->setObjectName(QString::fromUtf8("addEvent"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        addEvent->setIcon(icon1);
        addEvent->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        addEvent->setAutoRaise(false);

        horizontalLayout_2->addWidget(addEvent);


        verticalLayout->addLayout(horizontalLayout_2);

        EventsListWidget = new QListWidget(centralwidget);
        EventsListWidget->setObjectName(QString::fromUtf8("EventsListWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(EventsListWidget->sizePolicy().hasHeightForWidth());
        EventsListWidget->setSizePolicy(sizePolicy);
        EventsListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        EventsListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        EventsListWidget->setSortingEnabled(true);

        verticalLayout->addWidget(EventsListWidget);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(3, -1, -1, -1);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2);

        addFunction = new QToolButton(centralwidget);
        addFunction->setObjectName(QString::fromUtf8("addFunction"));
        addFunction->setIcon(icon1);
        addFunction->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        addFunction->setAutoRaise(false);

        horizontalLayout_3->addWidget(addFunction);


        verticalLayout->addLayout(horizontalLayout_3);

        FunctionsListWidget = new QListWidget(centralwidget);
        FunctionsListWidget->setObjectName(QString::fromUtf8("FunctionsListWidget"));
        sizePolicy.setHeightForWidth(FunctionsListWidget->sizePolicy().hasHeightForWidth());
        FunctionsListWidget->setSizePolicy(sizePolicy);
        FunctionsListWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        FunctionsListWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        FunctionsListWidget->setSortingEnabled(true);

        verticalLayout->addWidget(FunctionsListWidget);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon2);

        verticalLayout->addWidget(pushButton_3);


        horizontalLayout->addLayout(verticalLayout);

        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        PropertiesPage = new QWidget();
        PropertiesPage->setObjectName(QString::fromUtf8("PropertiesPage"));
        verticalLayout_2 = new QVBoxLayout(PropertiesPage);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter = new QSplitter(PropertiesPage);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        splitter->setHandleWidth(4);
        splitter->setChildrenCollapsible(false);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Sunken);
        verticalLayout_3 = new QVBoxLayout(frame);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(6, -1, -1, -1);
        lbClassVars = new QLabel(frame);
        lbClassVars->setObjectName(QString::fromUtf8("lbClassVars"));
        lbClassVars->setFont(font);

        horizontalLayout_9->addWidget(lbClassVars);

        DelVars = new QToolButton(frame);
        DelVars->setObjectName(QString::fromUtf8("DelVars"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DelVars->setIcon(icon3);
        DelVars->setAutoRaise(true);

        horizontalLayout_9->addWidget(DelVars);

        addVariable = new QToolButton(frame);
        addVariable->setObjectName(QString::fromUtf8("addVariable"));
        addVariable->setIcon(icon1);
        addVariable->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        addVariable->setAutoRaise(false);

        horizontalLayout_9->addWidget(addVariable);


        verticalLayout_3->addLayout(horizontalLayout_9);

        VarsList = new QTreeWidget(frame);
        VarsList->setObjectName(QString::fromUtf8("VarsList"));
        VarsList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        VarsList->setDragEnabled(true);
        VarsList->setDragDropMode(QAbstractItemView::DragDrop);
        VarsList->setDefaultDropAction(Qt::MoveAction);
        VarsList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        VarsList->setIconSize(QSize(16, 16));
        VarsList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        VarsList->setIndentation(0);
        VarsList->setItemsExpandable(true);
        VarsList->header()->setDefaultSectionSize(80);

        verticalLayout_3->addWidget(VarsList);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(3);
        verticalLayout_9->setContentsMargins(3, 3, 3, 3);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        lbDefaultSettingsForInstances = new QLabel(frame);
        lbDefaultSettingsForInstances->setObjectName(QString::fromUtf8("lbDefaultSettingsForInstances"));
        lbDefaultSettingsForInstances->setFont(font);

        verticalLayout_9->addWidget(lbDefaultSettingsForInstances);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(3);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetNoConstraint);
        cbGlobal = new QCheckBox(frame);
        cbGlobal->setObjectName(QString::fromUtf8("cbGlobal"));

        gridLayout->addWidget(cbGlobal, 1, 0, 1, 1);

        cbPersistent = new QCheckBox(frame);
        cbPersistent->setObjectName(QString::fromUtf8("cbPersistent"));

        gridLayout->addWidget(cbPersistent, 1, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        cbPhysical = new QCheckBox(frame);
        cbPhysical->setObjectName(QString::fromUtf8("cbPhysical"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cbPhysical->sizePolicy().hasHeightForWidth());
        cbPhysical->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(cbPhysical);

        tbPhysical = new QToolButton(frame);
        tbPhysical->setObjectName(QString::fromUtf8("tbPhysical"));
        sizePolicy2.setHeightForWidth(tbPhysical->sizePolicy().hasHeightForWidth());
        tbPhysical->setSizePolicy(sizePolicy2);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/wrench.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbPhysical->setIcon(icon4);
        tbPhysical->setAutoRaise(true);

        horizontalLayout_7->addWidget(tbPhysical);

        horizontalSpacer_3 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalSpacer_4 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_4, 0, 0, 1, 1);

        horizontalSpacer_5 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_5, 0, 1, 1, 1);

        checkBox = new QCheckBox(frame);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));

        gridLayout->addWidget(checkBox, 2, 1, 1, 1);


        verticalLayout_9->addLayout(gridLayout);

        line = new QFrame(frame);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_9->addWidget(line);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        lbColisionMode = new QLabel(frame);
        lbColisionMode->setObjectName(QString::fromUtf8("lbColisionMode"));
        lbColisionMode->setFont(font);

        horizontalLayout_5->addWidget(lbColisionMode);

        rb2d = new QRadioButton(frame);
        rb2d->setObjectName(QString::fromUtf8("rb2d"));
        rb2d->setChecked(true);

        horizontalLayout_5->addWidget(rb2d);

        rb3d = new QRadioButton(frame);
        rb3d->setObjectName(QString::fromUtf8("rb3d"));
        rb3d->setEnabled(false);

        horizontalLayout_5->addWidget(rb3d);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);


        verticalLayout_9->addLayout(horizontalLayout_5);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        lbBaseClass = new QLabel(frame);
        lbBaseClass->setObjectName(QString::fromUtf8("lbBaseClass"));
        sizePolicy2.setHeightForWidth(lbBaseClass->sizePolicy().hasHeightForWidth());
        lbBaseClass->setSizePolicy(sizePolicy2);
        lbBaseClass->setFont(font);

        horizontalLayout_8->addWidget(lbBaseClass);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        baseClassButton = new QPushButton(frame);
        baseClassButton->setObjectName(QString::fromUtf8("baseClassButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/brick.png"), QSize(), QIcon::Normal, QIcon::Off);
        baseClassButton->setIcon(icon5);

        horizontalLayout_8->addWidget(baseClassButton);


        verticalLayout_9->addLayout(horizontalLayout_8);


        verticalLayout_3->addLayout(verticalLayout_9);

        splitter->addWidget(frame);
        frame_2 = new QFrame(splitter);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        sizePolicy1.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy1);
        frame_2->setFrameShape(QFrame::Panel);
        frame_2->setFrameShadow(QFrame::Sunken);
        verticalLayout_4 = new QVBoxLayout(frame_2);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(6, -1, -1, -1);
        lbDTProperties = new QLabel(frame_2);
        lbDTProperties->setObjectName(QString::fromUtf8("lbDTProperties"));
        lbDTProperties->setFont(font);

        horizontalLayout_6->addWidget(lbDTProperties);

        DelProperties = new QToolButton(frame_2);
        DelProperties->setObjectName(QString::fromUtf8("DelProperties"));
        DelProperties->setIcon(icon3);
        DelProperties->setAutoRaise(true);

        horizontalLayout_6->addWidget(DelProperties);

        addProperty = new QToolButton(frame_2);
        addProperty->setObjectName(QString::fromUtf8("addProperty"));
        addProperty->setIcon(icon1);
        addProperty->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        addProperty->setAutoRaise(false);

        horizontalLayout_6->addWidget(addProperty);


        verticalLayout_4->addLayout(horizontalLayout_6);

        PropList = new QTreeWidget(frame_2);
        PropList->setObjectName(QString::fromUtf8("PropList"));
        PropList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        PropList->setDragEnabled(true);
        PropList->setDragDropMode(QAbstractItemView::DragDrop);
        PropList->setDefaultDropAction(Qt::MoveAction);
        PropList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        PropList->setIconSize(QSize(16, 16));
        PropList->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        PropList->setIndentation(0);
        PropList->setItemsExpandable(true);
        PropList->header()->setDefaultSectionSize(80);

        verticalLayout_4->addWidget(PropList);

        verticalLayout_10 = new QVBoxLayout();
        verticalLayout_10->setSpacing(5);
        verticalLayout_10->setContentsMargins(3, 3, 3, 3);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        lbDTHelpers = new QLabel(frame_2);
        lbDTHelpers->setObjectName(QString::fromUtf8("lbDTHelpers"));
        lbDTHelpers->setFont(font);

        horizontalLayout_10->addWidget(lbDTHelpers);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_8);

        toolButton_2 = new QToolButton(frame_2);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon6);
        toolButton_2->setAutoRaise(true);

        horizontalLayout_10->addWidget(toolButton_2);

        toolButton = new QToolButton(frame_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/tick.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon7);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_10->addWidget(toolButton);


        verticalLayout_10->addLayout(horizontalLayout_10);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_6, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_7, 0, 1, 1, 1);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        cbResizing = new QCheckBox(frame_2);
        cbResizing->setObjectName(QString::fromUtf8("cbResizing"));

        horizontalLayout_12->addWidget(cbResizing);

        tbResizing = new QToolButton(frame_2);
        tbResizing->setObjectName(QString::fromUtf8("tbResizing"));
        sizePolicy2.setHeightForWidth(tbResizing->sizePolicy().hasHeightForWidth());
        tbResizing->setSizePolicy(sizePolicy2);
        tbResizing->setIcon(icon4);
        tbResizing->setAutoRaise(true);

        horizontalLayout_12->addWidget(tbResizing);

        horizontalSpacer_10 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_10);


        gridLayout_2->addLayout(horizontalLayout_12, 1, 0, 1, 1);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(0);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        cbRotation = new QCheckBox(frame_2);
        cbRotation->setObjectName(QString::fromUtf8("cbRotation"));

        horizontalLayout_13->addWidget(cbRotation);

        tbRotation = new QToolButton(frame_2);
        tbRotation->setObjectName(QString::fromUtf8("tbRotation"));
        sizePolicy2.setHeightForWidth(tbRotation->sizePolicy().hasHeightForWidth());
        tbRotation->setSizePolicy(sizePolicy2);
        tbRotation->setIcon(icon4);
        tbRotation->setAutoRaise(true);

        horizontalLayout_13->addWidget(tbRotation);

        horizontalSpacer_9 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_9);


        gridLayout_2->addLayout(horizontalLayout_13, 1, 1, 1, 1);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        cbRepresentation = new QCheckBox(frame_2);
        cbRepresentation->setObjectName(QString::fromUtf8("cbRepresentation"));

        horizontalLayout_11->addWidget(cbRepresentation);

        tbRepresentation = new QToolButton(frame_2);
        tbRepresentation->setObjectName(QString::fromUtf8("tbRepresentation"));
        sizePolicy2.setHeightForWidth(tbRepresentation->sizePolicy().hasHeightForWidth());
        tbRepresentation->setSizePolicy(sizePolicy2);
        tbRepresentation->setIcon(icon4);
        tbRepresentation->setAutoRaise(true);

        horizontalLayout_11->addWidget(tbRepresentation);

        horizontalSpacer_11 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_11);


        gridLayout_2->addLayout(horizontalLayout_11, 2, 0, 1, 1);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(0);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        cbRepresentation_2 = new QCheckBox(frame_2);
        cbRepresentation_2->setObjectName(QString::fromUtf8("cbRepresentation_2"));

        horizontalLayout_14->addWidget(cbRepresentation_2);

        tbRepresentation_2 = new QToolButton(frame_2);
        tbRepresentation_2->setObjectName(QString::fromUtf8("tbRepresentation_2"));
        sizePolicy2.setHeightForWidth(tbRepresentation_2->sizePolicy().hasHeightForWidth());
        tbRepresentation_2->setSizePolicy(sizePolicy2);
        tbRepresentation_2->setIcon(icon4);
        tbRepresentation_2->setAutoRaise(true);

        horizontalLayout_14->addWidget(tbRepresentation_2);

        horizontalSpacer_12 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_14->addItem(horizontalSpacer_12);


        gridLayout_2->addLayout(horizontalLayout_14, 2, 1, 1, 1);


        verticalLayout_10->addLayout(gridLayout_2);


        verticalLayout_4->addLayout(verticalLayout_10);

        splitter->addWidget(frame_2);

        verticalLayout_2->addWidget(splitter);

        stackedWidget->addWidget(PropertiesPage);
        CodeEditPage = new QWidget();
        CodeEditPage->setObjectName(QString::fromUtf8("CodeEditPage"));
        horizontalLayout_4 = new QHBoxLayout(CodeEditPage);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        CodeEditorFrame = new QFrame(CodeEditPage);
        CodeEditorFrame->setObjectName(QString::fromUtf8("CodeEditorFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(CodeEditorFrame->sizePolicy().hasHeightForWidth());
        CodeEditorFrame->setSizePolicy(sizePolicy3);
        CodeEditorFrame->setFrameShape(QFrame::StyledPanel);
        CodeEditorFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_5 = new QVBoxLayout(CodeEditorFrame);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));

        horizontalLayout_4->addWidget(CodeEditorFrame);

        FunctionBox = new QToolBox(CodeEditPage);
        FunctionBox->setObjectName(QString::fromUtf8("FunctionBox"));
        QSizePolicy sizePolicy4(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(FunctionBox->sizePolicy().hasHeightForWidth());
        FunctionBox->setSizePolicy(sizePolicy4);
        FunctionBox->setMinimumSize(QSize(100, 0));
        FunctionBox->setMaximumSize(QSize(100, 16777215));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 100, 445));
        verticalLayout_7 = new QVBoxLayout(page_2);
        verticalLayout_7->setSpacing(3);
        verticalLayout_7->setContentsMargins(3, 3, 3, 3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_5 = new QLabel(page_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setText(QString::fromUtf8("To Do:\n"
"Functions library"));
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        verticalLayout_7->addWidget(label_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer);

        FunctionBox->addItem(page_2, QString::fromUtf8("Functions library"));

        horizontalLayout_4->addWidget(FunctionBox);

        stackedWidget->addWidget(CodeEditPage);
        FunctionEditPage = new QWidget();
        FunctionEditPage->setObjectName(QString::fromUtf8("FunctionEditPage"));
        verticalLayout_8 = new QVBoxLayout(FunctionEditPage);
        verticalLayout_8->setContentsMargins(0, 0, 0, 0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        label_3 = new QLabel(FunctionEditPage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_8->addWidget(label_3);

        frame_3 = new QFrame(FunctionEditPage);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        sizePolicy1.setHeightForWidth(frame_3->sizePolicy().hasHeightForWidth());
        frame_3->setSizePolicy(sizePolicy1);
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);

        verticalLayout_8->addWidget(frame_3);

        stackedWidget->addWidget(FunctionEditPage);

        horizontalLayout->addWidget(stackedWidget);

        eventClass->setCentralWidget(centralwidget);

        retranslateUi(eventClass);

        stackedWidget->setCurrentIndex(2);
        FunctionBox->setCurrentIndex(0);
        FunctionBox->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(eventClass);
    } // setupUi

    void retranslateUi(QMainWindow *eventClass)
    {
        eventClass->setWindowTitle(QApplication::translate("eventClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("eventClass", "Class settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("eventClass", "Events", 0, QApplication::UnicodeUTF8));
        addEvent->setText(QApplication::translate("eventClass", "Add", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("eventClass", "Functions", 0, QApplication::UnicodeUTF8));
        addFunction->setText(QApplication::translate("eventClass", "Add", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("eventClass", "Information", 0, QApplication::UnicodeUTF8));
        lbClassVars->setText(QApplication::translate("eventClass", "Class variables", 0, QApplication::UnicodeUTF8));
        DelVars->setText(QApplication::translate("eventClass", "Delete", 0, QApplication::UnicodeUTF8));
        addVariable->setText(QApplication::translate("eventClass", "Add", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = VarsList->headerItem();
        ___qtreewidgetitem->setText(2, QApplication::translate("eventClass", "Default value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(1, QApplication::translate("eventClass", "Variable type", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("eventClass", "Variable name", 0, QApplication::UnicodeUTF8));
        lbDefaultSettingsForInstances->setText(QApplication::translate("eventClass", "Default settings for instances", 0, QApplication::UnicodeUTF8));
        cbGlobal->setText(QApplication::translate("eventClass", "Global object", 0, QApplication::UnicodeUTF8));
        cbPersistent->setText(QApplication::translate("eventClass", "Persistent object", 0, QApplication::UnicodeUTF8));
        cbPhysical->setText(QApplication::translate("eventClass", "Physical", 0, QApplication::UnicodeUTF8));
        tbPhysical->setText(QApplication::translate("eventClass", "settings", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QApplication::translate("eventClass", "Lighting", 0, QApplication::UnicodeUTF8));
        lbColisionMode->setText(QApplication::translate("eventClass", "Colision mode:", 0, QApplication::UnicodeUTF8));
        rb2d->setText(QApplication::translate("eventClass", "2D", 0, QApplication::UnicodeUTF8));
        rb3d->setText(QApplication::translate("eventClass", "3D", 0, QApplication::UnicodeUTF8));
        lbBaseClass->setText(QApplication::translate("eventClass", "Base class:", 0, QApplication::UnicodeUTF8));
        baseClassButton->setText(QApplication::translate("eventClass", "(none)", 0, QApplication::UnicodeUTF8));
        lbDTProperties->setText(QApplication::translate("eventClass", "Design-time properties", 0, QApplication::UnicodeUTF8));
        DelProperties->setText(QApplication::translate("eventClass", "Delete", 0, QApplication::UnicodeUTF8));
        addProperty->setText(QApplication::translate("eventClass", "Add", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = PropList->headerItem();
        ___qtreewidgetitem1->setText(2, QApplication::translate("eventClass", "Default value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("eventClass", "Variable type", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("eventClass", "Variable name", 0, QApplication::UnicodeUTF8));
        lbDTHelpers->setText(QApplication::translate("eventClass", "Design-time helpers", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("eventClass", "None", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("eventClass", "All", 0, QApplication::UnicodeUTF8));
        cbResizing->setText(QApplication::translate("eventClass", "Resizing", 0, QApplication::UnicodeUTF8));
        tbResizing->setText(QApplication::translate("eventClass", "settings", 0, QApplication::UnicodeUTF8));
        cbRotation->setText(QApplication::translate("eventClass", "Rotation", 0, QApplication::UnicodeUTF8));
        tbRotation->setText(QApplication::translate("eventClass", "settings", 0, QApplication::UnicodeUTF8));
        cbRepresentation->setText(QApplication::translate("eventClass", "Representation", 0, QApplication::UnicodeUTF8));
        tbRepresentation->setText(QApplication::translate("eventClass", "settings", 0, QApplication::UnicodeUTF8));
        cbRepresentation_2->setText(QApplication::translate("eventClass", "Graphics Effects", 0, QApplication::UnicodeUTF8));
        tbRepresentation_2->setText(QApplication::translate("eventClass", "settings", 0, QApplication::UnicodeUTF8));
        FunctionBox->setItemText(FunctionBox->indexOf(page_2), QApplication::translate("eventClass", "Functions library", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("eventClass", "These widgets are used as top level windows.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class eventClass: public Ui_eventClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENTCLASS_H
