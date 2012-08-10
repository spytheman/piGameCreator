/********************************************************************************
** Form generated from reading UI file 'gameframeworkclassdef.ui'
**
** Created: Fri 10. Aug 01:00:05 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEFRAMEWORKCLASSDEF_H
#define UI_GAMEFRAMEWORKCLASSDEF_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSplitter>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameFrameworkClassDef
{
public:
    QVBoxLayout *verticalLayout_8;
    QSplitter *splitter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout_7;
    QTreeWidget *treeWidget;
    QSpacerItem *horizontalSpacer_8;
    QStackedWidget *stackedWidget;
    QWidget *pgNone;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QWidget *pgClassFile;
    QVBoxLayout *verticalLayout_3;
    QLabel *ClassFile;
    QLabel *label_18;
    QSpacerItem *verticalSpacer_2;
    QWidget *pgClassSettings;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *className;
    QLabel *label_3;
    QLineEdit *classDisplayName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton_5;
    QToolButton *toolButton_3;
    QToolButton *toolButton;
    QToolButton *toolButton_2;
    QToolButton *toolButton_4;
    QTextEdit *classDescEdit;
    QCheckBox *classHidden;
    QWidget *pgSelectType;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QRadioButton *addvarRB;
    QRadioButton *addvarRB_2;
    QRadioButton *addFunction;
    QLabel *label_16;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QSpacerItem *verticalSpacer;
    QWidget *pgTasks;
    QVBoxLayout *verticalLayout_4;
    QLabel *HeaderLabel;
    QRadioButton *genDoc;
    QRadioButton *genCpp;
    QRadioButton *genJs;
    QLabel *HeaderLabel_2;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *TaskCurrentClass;
    QPushButton *TaskAllClasses;
    QPushButton *TaskAllFiles;
    QSpacerItem *horizontalSpacer_9;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *pushButton_6;
    QWidget *pgClassTasks;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_20;
    QLabel *label_19;
    QSpacerItem *verticalSpacer_4;
    QWidget *pgVariable;
    QFormLayout *formLayout_3;
    QLabel *label_7;
    QLineEdit *varName;
    QLabel *label_8;
    QComboBox *varType;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *toolButton_13;
    QToolButton *toolButton_14;
    QToolButton *toolButton_15;
    QToolButton *toolButton_16;
    QToolButton *toolButton_17;
    QTextEdit *varDesc;
    QCheckBox *staticVariable;
    QWidget *pgFunction;
    QFormLayout *formLayout_5;
    QLabel *label_13;
    QLineEdit *fnName;
    QLabel *label_14;
    QComboBox *fnType;
    QCheckBox *staticFunction;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_17;
    QSpacerItem *horizontalSpacer_6;
    QToolButton *toolButton_23;
    QToolButton *toolButton_24;
    QToolButton *toolButton_25;
    QToolButton *toolButton_26;
    QToolButton *toolButton_27;
    QTextEdit *fnDesc;
    QWidget *argumentsAddRemove;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *removeButton_2;
    QToolButton *removeButton;
    QToolButton *AddButton;
    QTreeWidget *fnArgumentList;
    QWidget *pgProperty;
    QFormLayout *formLayout_4;
    QLabel *label_12;
    QLineEdit *propName;
    QLabel *label_11;
    QComboBox *propType;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_10;
    QSpacerItem *horizontalSpacer_4;
    QToolButton *toolButton_18;
    QToolButton *toolButton_19;
    QToolButton *toolButton_20;
    QToolButton *toolButton_21;
    QToolButton *toolButton_22;
    QTextEdit *propDesc;
    QLabel *label_5;
    QCheckBox *staticProperty;
    QFrame *line;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_3;
    QPushButton *btnTasks;
    QPushButton *btnEdit;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *OKbutton;
    QPushButton *cancelButton;

    void setupUi(QDialog *GameFrameworkClassDef)
    {
        if (GameFrameworkClassDef->objectName().isEmpty())
            GameFrameworkClassDef->setObjectName(QString::fromUtf8("GameFrameworkClassDef"));
        GameFrameworkClassDef->resize(800, 600);
        verticalLayout_8 = new QVBoxLayout(GameFrameworkClassDef);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        splitter = new QSplitter(GameFrameworkClassDef);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        verticalLayoutWidget = new QWidget(splitter);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayout_7 = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(verticalLayoutWidget);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);
        treeWidget->setContextMenuPolicy(Qt::CustomContextMenu);
        treeWidget->setIndentation(8);
        treeWidget->setRootIsDecorated(false);
        treeWidget->setSortingEnabled(true);
        treeWidget->header()->setVisible(false);

        verticalLayout_7->addWidget(treeWidget);

        horizontalSpacer_8 = new QSpacerItem(120, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout_7->addItem(horizontalSpacer_8);

        splitter->addWidget(verticalLayoutWidget);
        stackedWidget = new QStackedWidget(splitter);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pgNone = new QWidget();
        pgNone->setObjectName(QString::fromUtf8("pgNone"));
        verticalLayout_2 = new QVBoxLayout(pgNone);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_2 = new QLabel(pgNone);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout_2->addWidget(label_2);

        stackedWidget->addWidget(pgNone);
        pgClassFile = new QWidget();
        pgClassFile->setObjectName(QString::fromUtf8("pgClassFile"));
        verticalLayout_3 = new QVBoxLayout(pgClassFile);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        ClassFile = new QLabel(pgClassFile);
        ClassFile->setObjectName(QString::fromUtf8("ClassFile"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        ClassFile->setFont(font);

        verticalLayout_3->addWidget(ClassFile);

        label_18 = new QLabel(pgClassFile);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_18->sizePolicy().hasHeightForWidth());
        label_18->setSizePolicy(sizePolicy1);

        verticalLayout_3->addWidget(label_18);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget->addWidget(pgClassFile);
        pgClassSettings = new QWidget();
        pgClassSettings->setObjectName(QString::fromUtf8("pgClassSettings"));
        formLayout = new QFormLayout(pgClassSettings);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(pgClassSettings);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        className = new QLineEdit(pgClassSettings);
        className->setObjectName(QString::fromUtf8("className"));

        formLayout->setWidget(0, QFormLayout::FieldRole, className);

        label_3 = new QLabel(pgClassSettings);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        classDisplayName = new QLineEdit(pgClassSettings);
        classDisplayName->setObjectName(QString::fromUtf8("classDisplayName"));

        formLayout->setWidget(1, QFormLayout::FieldRole, classDisplayName);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(pgClassSettings);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        toolButton_5 = new QToolButton(pgClassSettings);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/text_allcaps.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon);
        toolButton_5->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_5);

        toolButton_3 = new QToolButton(pgClassSettings);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/text_bold.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon1);
        toolButton_3->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_3);

        toolButton = new QToolButton(pgClassSettings);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/text_italic.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon2);
        toolButton->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton);

        toolButton_2 = new QToolButton(pgClassSettings);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/text_underline.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon3);
        toolButton_2->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_2);

        toolButton_4 = new QToolButton(pgClassSettings);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/text_strikethrough.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon4);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton_4);


        formLayout->setLayout(2, QFormLayout::SpanningRole, horizontalLayout_2);

        classDescEdit = new QTextEdit(pgClassSettings);
        classDescEdit->setObjectName(QString::fromUtf8("classDescEdit"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, classDescEdit);

        classHidden = new QCheckBox(pgClassSettings);
        classHidden->setObjectName(QString::fromUtf8("classHidden"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, classHidden);

        stackedWidget->addWidget(pgClassSettings);
        pgSelectType = new QWidget();
        pgSelectType->setObjectName(QString::fromUtf8("pgSelectType"));
        verticalLayout = new QVBoxLayout(pgSelectType);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(pgSelectType);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setFont(font);

        verticalLayout->addWidget(label_6);

        addvarRB = new QRadioButton(pgSelectType);
        addvarRB->setObjectName(QString::fromUtf8("addvarRB"));
        addvarRB->setCheckable(false);
        addvarRB->setAutoExclusive(false);

        verticalLayout->addWidget(addvarRB);

        addvarRB_2 = new QRadioButton(pgSelectType);
        addvarRB_2->setObjectName(QString::fromUtf8("addvarRB_2"));
        addvarRB_2->setCheckable(false);
        addvarRB_2->setAutoExclusive(false);

        verticalLayout->addWidget(addvarRB_2);

        addFunction = new QRadioButton(pgSelectType);
        addFunction->setObjectName(QString::fromUtf8("addFunction"));
        addFunction->setCheckable(false);
        addFunction->setAutoExclusive(false);

        verticalLayout->addWidget(addFunction);

        label_16 = new QLabel(pgSelectType);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setFont(font);

        verticalLayout->addWidget(label_16);

        radioButton = new QRadioButton(pgSelectType);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setCheckable(false);
        radioButton->setAutoExclusive(false);

        verticalLayout->addWidget(radioButton);

        radioButton_2 = new QRadioButton(pgSelectType);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));
        radioButton_2->setCheckable(false);
        radioButton_2->setAutoExclusive(false);

        verticalLayout->addWidget(radioButton_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        stackedWidget->addWidget(pgSelectType);
        pgTasks = new QWidget();
        pgTasks->setObjectName(QString::fromUtf8("pgTasks"));
        verticalLayout_4 = new QVBoxLayout(pgTasks);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        HeaderLabel = new QLabel(pgTasks);
        HeaderLabel->setObjectName(QString::fromUtf8("HeaderLabel"));
        HeaderLabel->setFont(font);

        verticalLayout_4->addWidget(HeaderLabel);

        genDoc = new QRadioButton(pgTasks);
        genDoc->setObjectName(QString::fromUtf8("genDoc"));

        verticalLayout_4->addWidget(genDoc);

        genCpp = new QRadioButton(pgTasks);
        genCpp->setObjectName(QString::fromUtf8("genCpp"));
        genCpp->setCheckable(true);
        genCpp->setChecked(true);

        verticalLayout_4->addWidget(genCpp);

        genJs = new QRadioButton(pgTasks);
        genJs->setObjectName(QString::fromUtf8("genJs"));

        verticalLayout_4->addWidget(genJs);

        HeaderLabel_2 = new QLabel(pgTasks);
        HeaderLabel_2->setObjectName(QString::fromUtf8("HeaderLabel_2"));
        HeaderLabel_2->setFont(font);

        verticalLayout_4->addWidget(HeaderLabel_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        TaskCurrentClass = new QPushButton(pgTasks);
        TaskCurrentClass->setObjectName(QString::fromUtf8("TaskCurrentClass"));

        horizontalLayout_7->addWidget(TaskCurrentClass);

        TaskAllClasses = new QPushButton(pgTasks);
        TaskAllClasses->setObjectName(QString::fromUtf8("TaskAllClasses"));

        horizontalLayout_7->addWidget(TaskAllClasses);

        TaskAllFiles = new QPushButton(pgTasks);
        TaskAllFiles->setObjectName(QString::fromUtf8("TaskAllFiles"));

        horizontalLayout_7->addWidget(TaskAllFiles);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_9);


        verticalLayout_4->addLayout(horizontalLayout_7);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_3);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_7);

        pushButton_6 = new QPushButton(pgTasks);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_8->addWidget(pushButton_6);


        verticalLayout_4->addLayout(horizontalLayout_8);

        stackedWidget->addWidget(pgTasks);
        pgClassTasks = new QWidget();
        pgClassTasks->setObjectName(QString::fromUtf8("pgClassTasks"));
        verticalLayout_5 = new QVBoxLayout(pgClassTasks);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_20 = new QLabel(pgClassTasks);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setFont(font);

        verticalLayout_5->addWidget(label_20);

        label_19 = new QLabel(pgClassTasks);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        verticalLayout_5->addWidget(label_19);

        verticalSpacer_4 = new QSpacerItem(20, 309, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        stackedWidget->addWidget(pgClassTasks);
        pgVariable = new QWidget();
        pgVariable->setObjectName(QString::fromUtf8("pgVariable"));
        formLayout_3 = new QFormLayout(pgVariable);
        formLayout_3->setObjectName(QString::fromUtf8("formLayout_3"));
        label_7 = new QLabel(pgVariable);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_7);

        varName = new QLineEdit(pgVariable);
        varName->setObjectName(QString::fromUtf8("varName"));

        formLayout_3->setWidget(0, QFormLayout::FieldRole, varName);

        label_8 = new QLabel(pgVariable);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_8);

        varType = new QComboBox(pgVariable);
        varType->setObjectName(QString::fromUtf8("varType"));
        varType->setEditable(true);
        varType->setMaxVisibleItems(20);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, varType);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_9 = new QLabel(pgVariable);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        horizontalSpacer_3 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        toolButton_13 = new QToolButton(pgVariable);
        toolButton_13->setObjectName(QString::fromUtf8("toolButton_13"));
        toolButton_13->setIcon(icon);
        toolButton_13->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_13);

        toolButton_14 = new QToolButton(pgVariable);
        toolButton_14->setObjectName(QString::fromUtf8("toolButton_14"));
        toolButton_14->setIcon(icon1);
        toolButton_14->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_14);

        toolButton_15 = new QToolButton(pgVariable);
        toolButton_15->setObjectName(QString::fromUtf8("toolButton_15"));
        toolButton_15->setIcon(icon2);
        toolButton_15->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_15);

        toolButton_16 = new QToolButton(pgVariable);
        toolButton_16->setObjectName(QString::fromUtf8("toolButton_16"));
        toolButton_16->setIcon(icon3);
        toolButton_16->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_16);

        toolButton_17 = new QToolButton(pgVariable);
        toolButton_17->setObjectName(QString::fromUtf8("toolButton_17"));
        toolButton_17->setIcon(icon4);
        toolButton_17->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_17);


        formLayout_3->setLayout(3, QFormLayout::SpanningRole, horizontalLayout_4);

        varDesc = new QTextEdit(pgVariable);
        varDesc->setObjectName(QString::fromUtf8("varDesc"));

        formLayout_3->setWidget(4, QFormLayout::SpanningRole, varDesc);

        staticVariable = new QCheckBox(pgVariable);
        staticVariable->setObjectName(QString::fromUtf8("staticVariable"));

        formLayout_3->setWidget(2, QFormLayout::LabelRole, staticVariable);

        stackedWidget->addWidget(pgVariable);
        pgFunction = new QWidget();
        pgFunction->setObjectName(QString::fromUtf8("pgFunction"));
        formLayout_5 = new QFormLayout(pgFunction);
        formLayout_5->setObjectName(QString::fromUtf8("formLayout_5"));
        formLayout_5->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_13 = new QLabel(pgFunction);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        formLayout_5->setWidget(0, QFormLayout::LabelRole, label_13);

        fnName = new QLineEdit(pgFunction);
        fnName->setObjectName(QString::fromUtf8("fnName"));

        formLayout_5->setWidget(0, QFormLayout::FieldRole, fnName);

        label_14 = new QLabel(pgFunction);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        formLayout_5->setWidget(1, QFormLayout::LabelRole, label_14);

        fnType = new QComboBox(pgFunction);
        fnType->setObjectName(QString::fromUtf8("fnType"));
        fnType->setEditable(true);
        fnType->setMaxVisibleItems(20);

        formLayout_5->setWidget(1, QFormLayout::FieldRole, fnType);

        staticFunction = new QCheckBox(pgFunction);
        staticFunction->setObjectName(QString::fromUtf8("staticFunction"));

        formLayout_5->setWidget(2, QFormLayout::SpanningRole, staticFunction);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_17 = new QLabel(pgFunction);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_6->addWidget(label_17);

        horizontalSpacer_6 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        toolButton_23 = new QToolButton(pgFunction);
        toolButton_23->setObjectName(QString::fromUtf8("toolButton_23"));
        toolButton_23->setIcon(icon);
        toolButton_23->setAutoRaise(true);

        horizontalLayout_6->addWidget(toolButton_23);

        toolButton_24 = new QToolButton(pgFunction);
        toolButton_24->setObjectName(QString::fromUtf8("toolButton_24"));
        toolButton_24->setIcon(icon1);
        toolButton_24->setAutoRaise(true);

        horizontalLayout_6->addWidget(toolButton_24);

        toolButton_25 = new QToolButton(pgFunction);
        toolButton_25->setObjectName(QString::fromUtf8("toolButton_25"));
        toolButton_25->setIcon(icon2);
        toolButton_25->setAutoRaise(true);

        horizontalLayout_6->addWidget(toolButton_25);

        toolButton_26 = new QToolButton(pgFunction);
        toolButton_26->setObjectName(QString::fromUtf8("toolButton_26"));
        toolButton_26->setIcon(icon3);
        toolButton_26->setAutoRaise(true);

        horizontalLayout_6->addWidget(toolButton_26);

        toolButton_27 = new QToolButton(pgFunction);
        toolButton_27->setObjectName(QString::fromUtf8("toolButton_27"));
        toolButton_27->setIcon(icon4);
        toolButton_27->setAutoRaise(true);

        horizontalLayout_6->addWidget(toolButton_27);


        formLayout_5->setLayout(3, QFormLayout::SpanningRole, horizontalLayout_6);

        fnDesc = new QTextEdit(pgFunction);
        fnDesc->setObjectName(QString::fromUtf8("fnDesc"));

        formLayout_5->setWidget(4, QFormLayout::SpanningRole, fnDesc);

        argumentsAddRemove = new QWidget(pgFunction);
        argumentsAddRemove->setObjectName(QString::fromUtf8("argumentsAddRemove"));
        horizontalLayout_3 = new QHBoxLayout(argumentsAddRemove);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_15 = new QLabel(argumentsAddRemove);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        horizontalLayout_3->addWidget(label_15);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        removeButton_2 = new QToolButton(argumentsAddRemove);
        removeButton_2->setObjectName(QString::fromUtf8("removeButton_2"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeButton_2->setIcon(icon5);
        removeButton_2->setAutoRaise(true);

        horizontalLayout_3->addWidget(removeButton_2);

        removeButton = new QToolButton(argumentsAddRemove);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeButton->setIcon(icon6);
        removeButton->setAutoRaise(true);

        horizontalLayout_3->addWidget(removeButton);

        AddButton = new QToolButton(argumentsAddRemove);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon7);
        AddButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(AddButton);


        formLayout_5->setWidget(5, QFormLayout::SpanningRole, argumentsAddRemove);

        fnArgumentList = new QTreeWidget(pgFunction);
        fnArgumentList->setObjectName(QString::fromUtf8("fnArgumentList"));
        fnArgumentList->setEditTriggers(QAbstractItemView::AllEditTriggers);
        fnArgumentList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        fnArgumentList->setIndentation(0);

        formLayout_5->setWidget(6, QFormLayout::SpanningRole, fnArgumentList);

        stackedWidget->addWidget(pgFunction);
        pgProperty = new QWidget();
        pgProperty->setObjectName(QString::fromUtf8("pgProperty"));
        formLayout_4 = new QFormLayout(pgProperty);
        formLayout_4->setObjectName(QString::fromUtf8("formLayout_4"));
        label_12 = new QLabel(pgProperty);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_12);

        propName = new QLineEdit(pgProperty);
        propName->setObjectName(QString::fromUtf8("propName"));

        formLayout_4->setWidget(0, QFormLayout::FieldRole, propName);

        label_11 = new QLabel(pgProperty);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_11);

        propType = new QComboBox(pgProperty);
        propType->setObjectName(QString::fromUtf8("propType"));
        propType->setEditable(true);
        propType->setMaxVisibleItems(20);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, propType);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_10 = new QLabel(pgProperty);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_5->addWidget(label_10);

        horizontalSpacer_4 = new QSpacerItem(40, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        toolButton_18 = new QToolButton(pgProperty);
        toolButton_18->setObjectName(QString::fromUtf8("toolButton_18"));
        toolButton_18->setIcon(icon);
        toolButton_18->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton_18);

        toolButton_19 = new QToolButton(pgProperty);
        toolButton_19->setObjectName(QString::fromUtf8("toolButton_19"));
        toolButton_19->setIcon(icon1);
        toolButton_19->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton_19);

        toolButton_20 = new QToolButton(pgProperty);
        toolButton_20->setObjectName(QString::fromUtf8("toolButton_20"));
        toolButton_20->setIcon(icon2);
        toolButton_20->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton_20);

        toolButton_21 = new QToolButton(pgProperty);
        toolButton_21->setObjectName(QString::fromUtf8("toolButton_21"));
        toolButton_21->setIcon(icon3);
        toolButton_21->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton_21);

        toolButton_22 = new QToolButton(pgProperty);
        toolButton_22->setObjectName(QString::fromUtf8("toolButton_22"));
        toolButton_22->setIcon(icon4);
        toolButton_22->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton_22);


        formLayout_4->setLayout(3, QFormLayout::SpanningRole, horizontalLayout_5);

        propDesc = new QTextEdit(pgProperty);
        propDesc->setObjectName(QString::fromUtf8("propDesc"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(propDesc->sizePolicy().hasHeightForWidth());
        propDesc->setSizePolicy(sizePolicy2);

        formLayout_4->setWidget(4, QFormLayout::SpanningRole, propDesc);

        label_5 = new QLabel(pgProperty);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout_4->setWidget(5, QFormLayout::SpanningRole, label_5);

        staticProperty = new QCheckBox(pgProperty);
        staticProperty->setObjectName(QString::fromUtf8("staticProperty"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, staticProperty);

        stackedWidget->addWidget(pgProperty);
        splitter->addWidget(stackedWidget);

        verticalLayout_8->addWidget(splitter);

        line = new QFrame(GameFrameworkClassDef);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_8->addWidget(line);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton_3 = new QPushButton(GameFrameworkClassDef);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setIcon(icon7);
        pushButton_3->setAutoDefault(false);

        horizontalLayout->addWidget(pushButton_3);

        btnTasks = new QPushButton(GameFrameworkClassDef);
        btnTasks->setObjectName(QString::fromUtf8("btnTasks"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/RES/ffficons/application_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnTasks->setIcon(icon8);
        btnTasks->setChecked(false);

        horizontalLayout->addWidget(btnTasks);

        btnEdit = new QPushButton(GameFrameworkClassDef);
        btnEdit->setObjectName(QString::fromUtf8("btnEdit"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resources/RES/ffficons/application_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnEdit->setIcon(icon9);

        horizontalLayout->addWidget(btnEdit);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        OKbutton = new QPushButton(GameFrameworkClassDef);
        OKbutton->setObjectName(QString::fromUtf8("OKbutton"));
        OKbutton->setDefault(true);

        horizontalLayout->addWidget(OKbutton);

        cancelButton = new QPushButton(GameFrameworkClassDef);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setAutoDefault(true);

        horizontalLayout->addWidget(cancelButton);


        verticalLayout_8->addLayout(horizontalLayout);

#ifndef QT_NO_SHORTCUT
        label_13->setBuddy(fnName);
        label_14->setBuddy(fnType);
        label_17->setBuddy(fnDesc);
        label_15->setBuddy(AddButton);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(fnName, fnType);
        QWidget::setTabOrder(fnType, staticFunction);
        QWidget::setTabOrder(staticFunction, toolButton_23);
        QWidget::setTabOrder(toolButton_23, toolButton_24);
        QWidget::setTabOrder(toolButton_24, toolButton_25);
        QWidget::setTabOrder(toolButton_25, toolButton_26);
        QWidget::setTabOrder(toolButton_26, toolButton_27);
        QWidget::setTabOrder(toolButton_27, fnDesc);
        QWidget::setTabOrder(fnDesc, removeButton_2);
        QWidget::setTabOrder(removeButton_2, removeButton);
        QWidget::setTabOrder(removeButton, AddButton);
        QWidget::setTabOrder(AddButton, fnArgumentList);
        QWidget::setTabOrder(fnArgumentList, propName);
        QWidget::setTabOrder(propName, propType);
        QWidget::setTabOrder(propType, toolButton_18);
        QWidget::setTabOrder(toolButton_18, toolButton_19);
        QWidget::setTabOrder(toolButton_19, toolButton_20);
        QWidget::setTabOrder(toolButton_20, toolButton_21);
        QWidget::setTabOrder(toolButton_21, toolButton_22);
        QWidget::setTabOrder(toolButton_22, propDesc);
        QWidget::setTabOrder(propDesc, className);
        QWidget::setTabOrder(className, classDisplayName);
        QWidget::setTabOrder(classDisplayName, toolButton_5);
        QWidget::setTabOrder(toolButton_5, toolButton_3);
        QWidget::setTabOrder(toolButton_3, toolButton);
        QWidget::setTabOrder(toolButton, toolButton_2);
        QWidget::setTabOrder(toolButton_2, toolButton_4);
        QWidget::setTabOrder(toolButton_4, classDescEdit);
        QWidget::setTabOrder(classDescEdit, classHidden);
        QWidget::setTabOrder(classHidden, addvarRB);
        QWidget::setTabOrder(addvarRB, addvarRB_2);
        QWidget::setTabOrder(addvarRB_2, addFunction);
        QWidget::setTabOrder(addFunction, radioButton);
        QWidget::setTabOrder(radioButton, radioButton_2);
        QWidget::setTabOrder(radioButton_2, genDoc);
        QWidget::setTabOrder(genDoc, genCpp);
        QWidget::setTabOrder(genCpp, genJs);
        QWidget::setTabOrder(genJs, TaskCurrentClass);
        QWidget::setTabOrder(TaskCurrentClass, TaskAllClasses);
        QWidget::setTabOrder(TaskAllClasses, TaskAllFiles);
        QWidget::setTabOrder(TaskAllFiles, pushButton_6);
        QWidget::setTabOrder(pushButton_6, varName);
        QWidget::setTabOrder(varName, varType);
        QWidget::setTabOrder(varType, toolButton_13);
        QWidget::setTabOrder(toolButton_13, toolButton_14);
        QWidget::setTabOrder(toolButton_14, toolButton_15);
        QWidget::setTabOrder(toolButton_15, toolButton_16);
        QWidget::setTabOrder(toolButton_16, toolButton_17);
        QWidget::setTabOrder(toolButton_17, varDesc);
        QWidget::setTabOrder(varDesc, pushButton_3);
        QWidget::setTabOrder(pushButton_3, btnTasks);
        QWidget::setTabOrder(btnTasks, btnEdit);
        QWidget::setTabOrder(btnEdit, OKbutton);
        QWidget::setTabOrder(OKbutton, cancelButton);

        retranslateUi(GameFrameworkClassDef);
        QObject::connect(cancelButton, SIGNAL(clicked()), GameFrameworkClassDef, SLOT(reject()));

        stackedWidget->setCurrentIndex(8);
        varType->setCurrentIndex(-1);
        propType->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(GameFrameworkClassDef);
    } // setupUi

    void retranslateUi(QDialog *GameFrameworkClassDef)
    {
        GameFrameworkClassDef->setWindowTitle(QApplication::translate("GameFrameworkClassDef", "DEVTOOL: Class editor", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("GameFrameworkClassDef", "Entities", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GameFrameworkClassDef", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Select item from the menu on the left</p></body></html>", 0, QApplication::UnicodeUTF8));
        ClassFile->setText(QApplication::translate("GameFrameworkClassDef", "*.gsd", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("GameFrameworkClassDef", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">Select a class or class member, or click <span style=\" font-weight:600;\">Insert</span> to add new.</p></body></html>", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GameFrameworkClassDef", "Class name:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("GameFrameworkClassDef", "Display name:", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("GameFrameworkClassDef", "Description:", 0, QApplication::UnicodeUTF8));
        toolButton_5->setText(QString());
        toolButton_3->setText(QString());
        toolButton->setText(QString());
        toolButton_2->setText(QString());
        toolButton_4->setText(QString());
        classHidden->setText(QApplication::translate("GameFrameworkClassDef", "Hidden class (don't show in the Code Completer)", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("GameFrameworkClassDef", "Insert to current class:", 0, QApplication::UnicodeUTF8));
        addvarRB->setText(QApplication::translate("GameFrameworkClassDef", "Variable", 0, QApplication::UnicodeUTF8));
        addvarRB_2->setText(QApplication::translate("GameFrameworkClassDef", "Property", 0, QApplication::UnicodeUTF8));
        addFunction->setText(QApplication::translate("GameFrameworkClassDef", "Function", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("GameFrameworkClassDef", "Or insert global object:", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("GameFrameworkClassDef", "New class", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("GameFrameworkClassDef", "New file", 0, QApplication::UnicodeUTF8));
        HeaderLabel->setText(QApplication::translate("GameFrameworkClassDef", "Tasks:", 0, QApplication::UnicodeUTF8));
        genDoc->setText(QApplication::translate("GameFrameworkClassDef", "Generate Documentation", 0, QApplication::UnicodeUTF8));
        genCpp->setText(QApplication::translate("GameFrameworkClassDef", "Generate C++", 0, QApplication::UnicodeUTF8));
        genJs->setText(QApplication::translate("GameFrameworkClassDef", "Generate JavaScript", 0, QApplication::UnicodeUTF8));
        HeaderLabel_2->setText(QApplication::translate("GameFrameworkClassDef", "Run task for:", 0, QApplication::UnicodeUTF8));
        TaskCurrentClass->setText(QApplication::translate("GameFrameworkClassDef", "Current class", 0, QApplication::UnicodeUTF8));
        TaskAllClasses->setText(QApplication::translate("GameFrameworkClassDef", "All classes", 0, QApplication::UnicodeUTF8));
        TaskAllFiles->setText(QApplication::translate("GameFrameworkClassDef", "All files", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("GameFrameworkClassDef", "Close tasks", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("GameFrameworkClassDef", "Unused page", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("GameFrameworkClassDef", "Maybe someday there will be something :]", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("GameFrameworkClassDef", "Variable name:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("GameFrameworkClassDef", "Variable type:", 0, QApplication::UnicodeUTF8));
        varType->clear();
        varType->insertItems(0, QStringList()
         << QApplication::translate("GameFrameworkClassDef", "int", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "bool", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "string", 0, QApplication::UnicodeUTF8)
        );
        label_9->setText(QApplication::translate("GameFrameworkClassDef", "Description:", 0, QApplication::UnicodeUTF8));
        toolButton_13->setText(QString());
        toolButton_14->setText(QString());
        toolButton_15->setText(QString());
        toolButton_16->setText(QString());
        toolButton_17->setText(QString());
        staticVariable->setText(QApplication::translate("GameFrameworkClassDef", "Static variable", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("GameFrameworkClassDef", "Function name:", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("GameFrameworkClassDef", "Return type:", 0, QApplication::UnicodeUTF8));
        fnType->clear();
        fnType->insertItems(0, QStringList()
         << QApplication::translate("GameFrameworkClassDef", "void", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "int", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "bool", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "string", 0, QApplication::UnicodeUTF8)
        );
        staticFunction->setText(QApplication::translate("GameFrameworkClassDef", "Static function", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("GameFrameworkClassDef", "Description:", 0, QApplication::UnicodeUTF8));
        toolButton_23->setText(QString());
        toolButton_24->setText(QString());
        toolButton_25->setText(QString());
        toolButton_26->setText(QString());
        toolButton_27->setText(QString());
        label_15->setText(QApplication::translate("GameFrameworkClassDef", "Arguments:", 0, QApplication::UnicodeUTF8));
        removeButton_2->setText(QApplication::translate("GameFrameworkClassDef", "Delete", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("GameFrameworkClassDef", "Delete", 0, QApplication::UnicodeUTF8));
        AddButton->setText(QApplication::translate("GameFrameworkClassDef", "Add", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem1 = fnArgumentList->headerItem();
        ___qtreewidgetitem1->setText(3, QApplication::translate("GameFrameworkClassDef", "Description", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(2, QApplication::translate("GameFrameworkClassDef", "Default value", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(1, QApplication::translate("GameFrameworkClassDef", "Argument type", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("GameFrameworkClassDef", "Argument name", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("GameFrameworkClassDef", "Property name:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("GameFrameworkClassDef", "Property type:", 0, QApplication::UnicodeUTF8));
        propType->clear();
        propType->insertItems(0, QStringList()
         << QApplication::translate("GameFrameworkClassDef", "int", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "bool", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GameFrameworkClassDef", "string", 0, QApplication::UnicodeUTF8)
        );
        label_10->setText(QApplication::translate("GameFrameworkClassDef", "Description:", 0, QApplication::UnicodeUTF8));
        toolButton_18->setText(QString());
        toolButton_19->setText(QString());
        toolButton_20->setText(QString());
        toolButton_21->setText(QString());
        toolButton_22->setText(QString());
        label_5->setText(QApplication::translate("GameFrameworkClassDef", "This will generate corresponding set/get functions", 0, QApplication::UnicodeUTF8));
        staticProperty->setText(QApplication::translate("GameFrameworkClassDef", "Static property", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("GameFrameworkClassDef", "Insert...", 0, QApplication::UnicodeUTF8));
        btnTasks->setText(QApplication::translate("GameFrameworkClassDef", "Tasks", 0, QApplication::UnicodeUTF8));
        btnEdit->setText(QApplication::translate("GameFrameworkClassDef", "Edit", 0, QApplication::UnicodeUTF8));
        OKbutton->setText(QApplication::translate("GameFrameworkClassDef", "Save", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("GameFrameworkClassDef", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GameFrameworkClassDef: public Ui_GameFrameworkClassDef {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEFRAMEWORKCLASSDEF_H
