/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created: Fri 2. Nov 07:45:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFontComboBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsWindow
{
public:
    QGridLayout *gridLayout_2;
    QListWidget *leftListWidget;
    QStackedWidget *stackedWidget;
    QWidget *cfgGeneral;
    QVBoxLayout *verticalLayout;
    QLabel *titleLabel;
    QSpacerItem *verticalSpacer;
    QWidget *cfgClassEditor;
    QVBoxLayout *verticalLayout_4;
    QLabel *titleLabel_4;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_12;
    QCheckBox *EnableCodeCompletion;
    QCheckBox *WarnForSyntaxErrorsOnSave;
    QCheckBox *AskToDeclareUnknownVars;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *AutoIndentCode;
    QLabel *label_2;
    QSpinBox *TabSize;
    QLabel *label_3;
    QCheckBox *BackSpaceFollowsIndentation;
    QCheckBox *AllowCursorEveryWhere;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label;
    QCheckBox *brackets;
    QCheckBox *squarebrackets;
    QCheckBox *curlybrackets;
    QCheckBox *quotes;
    QCheckBox *comments;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_13;
    QLabel *label_4;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_12;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_17;
    QRadioButton *libAskArgs;
    QRadioButton *libWriteSig;
    QSpacerItem *verticalSpacer_5;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_18;
    QRadioButton *ccAsk;
    QRadioButton *ccWriteSig;
    QRadioButton *ccShowSig;
    QGroupBox *groupBox_6;
    QVBoxLayout *verticalLayout_20;
    QRadioButton *cmWriteSig;
    QRadioButton *cmShowSig;
    QSpacerItem *verticalSpacer_8;
    QSpacerItem *verticalSpacer_4;
    QWidget *cfgCodeFormatting;
    QGridLayout *gridLayout;
    QLabel *titleLabel_5;
    QHBoxLayout *horizontalLayout_3;
    QComboBox *themeComboBox;
    QSpacerItem *horizontalSpacer;
    QFontComboBox *editorFontComboBox;
    QSpinBox *fontSize;
    QFrame *codeEditorWidget;
    QVBoxLayout *verticalLayout_10;
    QWidget *cfgContentServers;
    QVBoxLayout *verticalLayout_6;
    QLabel *titleLabel_6;
    QSpacerItem *verticalSpacer_6;
    QWidget *cfgCollaboration;
    QVBoxLayout *verticalLayout_7;
    QLabel *titleLabel_7;
    QSpacerItem *verticalSpacer_7;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SettingsWindow)
    {
        if (SettingsWindow->objectName().isEmpty())
            SettingsWindow->setObjectName(QString::fromUtf8("SettingsWindow"));
        SettingsWindow->resize(667, 440);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/cog_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        SettingsWindow->setWindowIcon(icon);
        gridLayout_2 = new QGridLayout(SettingsWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        leftListWidget = new QListWidget(SettingsWindow);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/application_form.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(leftListWidget);
        __qlistwidgetitem->setIcon(icon1);
        __qlistwidgetitem->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/brick.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(leftListWidget);
        __qlistwidgetitem1->setIcon(icon2);
        __qlistwidgetitem1->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/paintcan.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(leftListWidget);
        __qlistwidgetitem2->setIcon(icon3);
        __qlistwidgetitem2->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/server_connect.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(leftListWidget);
        __qlistwidgetitem3->setIcon(icon4);
        __qlistwidgetitem3->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/group.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem4 = new QListWidgetItem(leftListWidget);
        __qlistwidgetitem4->setIcon(icon5);
        __qlistwidgetitem4->setFlags(Qt::ItemIsSelectable|Qt::ItemIsUserCheckable|Qt::ItemIsEnabled);
        leftListWidget->setObjectName(QString::fromUtf8("leftListWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(leftListWidget->sizePolicy().hasHeightForWidth());
        leftListWidget->setSizePolicy(sizePolicy);
        leftListWidget->setMaximumSize(QSize(140, 16777215));
        leftListWidget->setIconSize(QSize(16, 16));

        gridLayout_2->addWidget(leftListWidget, 0, 0, 1, 1);

        stackedWidget = new QStackedWidget(SettingsWindow);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        cfgGeneral = new QWidget();
        cfgGeneral->setObjectName(QString::fromUtf8("cfgGeneral"));
        verticalLayout = new QVBoxLayout(cfgGeneral);
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        titleLabel = new QLabel(cfgGeneral);
        titleLabel->setObjectName(QString::fromUtf8("titleLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titleLabel->sizePolicy().hasHeightForWidth());
        titleLabel->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        titleLabel->setFont(font);

        verticalLayout->addWidget(titleLabel);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        stackedWidget->addWidget(cfgGeneral);
        cfgClassEditor = new QWidget();
        cfgClassEditor->setObjectName(QString::fromUtf8("cfgClassEditor"));
        verticalLayout_4 = new QVBoxLayout(cfgClassEditor);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        titleLabel_4 = new QLabel(cfgClassEditor);
        titleLabel_4->setObjectName(QString::fromUtf8("titleLabel_4"));
        sizePolicy1.setHeightForWidth(titleLabel_4->sizePolicy().hasHeightForWidth());
        titleLabel_4->setSizePolicy(sizePolicy1);
        titleLabel_4->setFont(font);

        verticalLayout_4->addWidget(titleLabel_4);

        groupBox_2 = new QGroupBox(cfgClassEditor);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setFlat(true);
        verticalLayout_12 = new QVBoxLayout(groupBox_2);
        verticalLayout_12->setSpacing(3);
        verticalLayout_12->setContentsMargins(3, 3, 3, 3);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        EnableCodeCompletion = new QCheckBox(groupBox_2);
        EnableCodeCompletion->setObjectName(QString::fromUtf8("EnableCodeCompletion"));
        EnableCodeCompletion->setChecked(true);

        verticalLayout_12->addWidget(EnableCodeCompletion);

        WarnForSyntaxErrorsOnSave = new QCheckBox(groupBox_2);
        WarnForSyntaxErrorsOnSave->setObjectName(QString::fromUtf8("WarnForSyntaxErrorsOnSave"));
        WarnForSyntaxErrorsOnSave->setChecked(true);

        verticalLayout_12->addWidget(WarnForSyntaxErrorsOnSave);

        AskToDeclareUnknownVars = new QCheckBox(groupBox_2);
        AskToDeclareUnknownVars->setObjectName(QString::fromUtf8("AskToDeclareUnknownVars"));
        AskToDeclareUnknownVars->setChecked(true);

        verticalLayout_12->addWidget(AskToDeclareUnknownVars);


        verticalLayout_4->addWidget(groupBox_2);

        groupBox = new QGroupBox(cfgClassEditor);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setFlat(true);
        verticalLayout_14 = new QVBoxLayout(groupBox);
        verticalLayout_14->setSpacing(3);
        verticalLayout_14->setContentsMargins(3, 3, 3, 3);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(3);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        AutoIndentCode = new QCheckBox(groupBox);
        AutoIndentCode->setObjectName(QString::fromUtf8("AutoIndentCode"));
        sizePolicy1.setHeightForWidth(AutoIndentCode->sizePolicy().hasHeightForWidth());
        AutoIndentCode->setSizePolicy(sizePolicy1);
        AutoIndentCode->setChecked(true);

        horizontalLayout_9->addWidget(AutoIndentCode);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(label_2);

        TabSize = new QSpinBox(groupBox);
        TabSize->setObjectName(QString::fromUtf8("TabSize"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(TabSize->sizePolicy().hasHeightForWidth());
        TabSize->setSizePolicy(sizePolicy3);
        TabSize->setValue(4);

        horizontalLayout_9->addWidget(TabSize);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy2.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy2);

        horizontalLayout_9->addWidget(label_3);


        verticalLayout_14->addLayout(horizontalLayout_9);

        BackSpaceFollowsIndentation = new QCheckBox(groupBox);
        BackSpaceFollowsIndentation->setObjectName(QString::fromUtf8("BackSpaceFollowsIndentation"));
        BackSpaceFollowsIndentation->setChecked(true);

        verticalLayout_14->addWidget(BackSpaceFollowsIndentation);

        AllowCursorEveryWhere = new QCheckBox(groupBox);
        AllowCursorEveryWhere->setObjectName(QString::fromUtf8("AllowCursorEveryWhere"));

        verticalLayout_14->addWidget(AllowCursorEveryWhere);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));
        sizePolicy2.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy2);

        horizontalLayout_7->addWidget(label);

        brackets = new QCheckBox(groupBox);
        brackets->setObjectName(QString::fromUtf8("brackets"));
        sizePolicy3.setHeightForWidth(brackets->sizePolicy().hasHeightForWidth());
        brackets->setSizePolicy(sizePolicy3);
        brackets->setChecked(true);

        horizontalLayout_7->addWidget(brackets);

        squarebrackets = new QCheckBox(groupBox);
        squarebrackets->setObjectName(QString::fromUtf8("squarebrackets"));
        sizePolicy3.setHeightForWidth(squarebrackets->sizePolicy().hasHeightForWidth());
        squarebrackets->setSizePolicy(sizePolicy3);
        squarebrackets->setChecked(true);

        horizontalLayout_7->addWidget(squarebrackets);

        curlybrackets = new QCheckBox(groupBox);
        curlybrackets->setObjectName(QString::fromUtf8("curlybrackets"));
        sizePolicy3.setHeightForWidth(curlybrackets->sizePolicy().hasHeightForWidth());
        curlybrackets->setSizePolicy(sizePolicy3);
        curlybrackets->setChecked(true);

        horizontalLayout_7->addWidget(curlybrackets);

        quotes = new QCheckBox(groupBox);
        quotes->setObjectName(QString::fromUtf8("quotes"));
        sizePolicy3.setHeightForWidth(quotes->sizePolicy().hasHeightForWidth());
        quotes->setSizePolicy(sizePolicy3);
        quotes->setChecked(true);

        horizontalLayout_7->addWidget(quotes);

        comments = new QCheckBox(groupBox);
        comments->setObjectName(QString::fromUtf8("comments"));
        sizePolicy1.setHeightForWidth(comments->sizePolicy().hasHeightForWidth());
        comments->setSizePolicy(sizePolicy1);
        comments->setChecked(true);

        horizontalLayout_7->addWidget(comments);


        verticalLayout_14->addLayout(horizontalLayout_7);


        verticalLayout_4->addWidget(groupBox);

        groupBox_3 = new QGroupBox(cfgClassEditor);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setFlat(true);
        verticalLayout_13 = new QVBoxLayout(groupBox_3);
#ifndef Q_OS_MAC
        verticalLayout_13->setSpacing(6);
#endif
        verticalLayout_13->setContentsMargins(3, 3, 3, 3);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_13->addWidget(label_4);

        frame = new QFrame(groupBox_3);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy4);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_12 = new QHBoxLayout(frame);
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        groupBox_4 = new QGroupBox(frame);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_17 = new QVBoxLayout(groupBox_4);
        verticalLayout_17->setSpacing(3);
        verticalLayout_17->setContentsMargins(3, 3, 3, 3);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        verticalLayout_17->setSizeConstraint(QLayout::SetDefaultConstraint);
        libAskArgs = new QRadioButton(groupBox_4);
        libAskArgs->setObjectName(QString::fromUtf8("libAskArgs"));
        libAskArgs->setChecked(true);

        verticalLayout_17->addWidget(libAskArgs);

        libWriteSig = new QRadioButton(groupBox_4);
        libWriteSig->setObjectName(QString::fromUtf8("libWriteSig"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(libWriteSig->sizePolicy().hasHeightForWidth());
        libWriteSig->setSizePolicy(sizePolicy5);

        verticalLayout_17->addWidget(libWriteSig);

        verticalSpacer_5 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_17->addItem(verticalSpacer_5);


        horizontalLayout_12->addWidget(groupBox_4);

        groupBox_5 = new QGroupBox(frame);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        verticalLayout_18 = new QVBoxLayout(groupBox_5);
        verticalLayout_18->setSpacing(3);
        verticalLayout_18->setContentsMargins(3, 3, 3, 3);
        verticalLayout_18->setObjectName(QString::fromUtf8("verticalLayout_18"));
        ccAsk = new QRadioButton(groupBox_5);
        ccAsk->setObjectName(QString::fromUtf8("ccAsk"));

        verticalLayout_18->addWidget(ccAsk);

        ccWriteSig = new QRadioButton(groupBox_5);
        ccWriteSig->setObjectName(QString::fromUtf8("ccWriteSig"));
        ccWriteSig->setChecked(false);

        verticalLayout_18->addWidget(ccWriteSig);

        ccShowSig = new QRadioButton(groupBox_5);
        ccShowSig->setObjectName(QString::fromUtf8("ccShowSig"));
        ccShowSig->setChecked(true);

        verticalLayout_18->addWidget(ccShowSig);


        horizontalLayout_12->addWidget(groupBox_5);

        groupBox_6 = new QGroupBox(frame);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        verticalLayout_20 = new QVBoxLayout(groupBox_6);
        verticalLayout_20->setSpacing(3);
        verticalLayout_20->setContentsMargins(3, 3, 3, 3);
        verticalLayout_20->setObjectName(QString::fromUtf8("verticalLayout_20"));
        cmWriteSig = new QRadioButton(groupBox_6);
        cmWriteSig->setObjectName(QString::fromUtf8("cmWriteSig"));

        verticalLayout_20->addWidget(cmWriteSig);

        cmShowSig = new QRadioButton(groupBox_6);
        cmShowSig->setObjectName(QString::fromUtf8("cmShowSig"));
        cmShowSig->setChecked(true);

        verticalLayout_20->addWidget(cmShowSig);

        verticalSpacer_8 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_20->addItem(verticalSpacer_8);


        horizontalLayout_12->addWidget(groupBox_6);


        verticalLayout_13->addWidget(frame);

        verticalSpacer_4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_13->addItem(verticalSpacer_4);


        verticalLayout_4->addWidget(groupBox_3);

        stackedWidget->addWidget(cfgClassEditor);
        cfgCodeFormatting = new QWidget();
        cfgCodeFormatting->setObjectName(QString::fromUtf8("cfgCodeFormatting"));
        gridLayout = new QGridLayout(cfgCodeFormatting);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        titleLabel_5 = new QLabel(cfgCodeFormatting);
        titleLabel_5->setObjectName(QString::fromUtf8("titleLabel_5"));
        sizePolicy1.setHeightForWidth(titleLabel_5->sizePolicy().hasHeightForWidth());
        titleLabel_5->setSizePolicy(sizePolicy1);
        titleLabel_5->setFont(font);
        titleLabel_5->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(titleLabel_5, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        themeComboBox = new QComboBox(cfgCodeFormatting);
        themeComboBox->setObjectName(QString::fromUtf8("themeComboBox"));

        horizontalLayout_3->addWidget(themeComboBox);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        editorFontComboBox = new QFontComboBox(cfgCodeFormatting);
        editorFontComboBox->setObjectName(QString::fromUtf8("editorFontComboBox"));
        sizePolicy3.setHeightForWidth(editorFontComboBox->sizePolicy().hasHeightForWidth());
        editorFontComboBox->setSizePolicy(sizePolicy3);
        editorFontComboBox->setFontFilters(QFontComboBox::MonospacedFonts);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Courier New"));
        font1.setPointSize(10);
        editorFontComboBox->setCurrentFont(font1);

        horizontalLayout_3->addWidget(editorFontComboBox);

        fontSize = new QSpinBox(cfgCodeFormatting);
        fontSize->setObjectName(QString::fromUtf8("fontSize"));
        sizePolicy3.setHeightForWidth(fontSize->sizePolicy().hasHeightForWidth());
        fontSize->setSizePolicy(sizePolicy3);
        fontSize->setMinimum(4);
        fontSize->setMaximum(100);
        fontSize->setValue(10);

        horizontalLayout_3->addWidget(fontSize);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        codeEditorWidget = new QFrame(cfgCodeFormatting);
        codeEditorWidget->setObjectName(QString::fromUtf8("codeEditorWidget"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(codeEditorWidget->sizePolicy().hasHeightForWidth());
        codeEditorWidget->setSizePolicy(sizePolicy6);
        codeEditorWidget->setFrameShape(QFrame::StyledPanel);
        codeEditorWidget->setFrameShadow(QFrame::Sunken);
        verticalLayout_10 = new QVBoxLayout(codeEditorWidget);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));

        gridLayout->addWidget(codeEditorWidget, 2, 0, 1, 2);

        stackedWidget->addWidget(cfgCodeFormatting);
        cfgContentServers = new QWidget();
        cfgContentServers->setObjectName(QString::fromUtf8("cfgContentServers"));
        verticalLayout_6 = new QVBoxLayout(cfgContentServers);
        verticalLayout_6->setContentsMargins(1, 1, 1, 1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        titleLabel_6 = new QLabel(cfgContentServers);
        titleLabel_6->setObjectName(QString::fromUtf8("titleLabel_6"));
        sizePolicy1.setHeightForWidth(titleLabel_6->sizePolicy().hasHeightForWidth());
        titleLabel_6->setSizePolicy(sizePolicy1);
        titleLabel_6->setFont(font);

        verticalLayout_6->addWidget(titleLabel_6);

        verticalSpacer_6 = new QSpacerItem(20, 281, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer_6);

        stackedWidget->addWidget(cfgContentServers);
        cfgCollaboration = new QWidget();
        cfgCollaboration->setObjectName(QString::fromUtf8("cfgCollaboration"));
        verticalLayout_7 = new QVBoxLayout(cfgCollaboration);
        verticalLayout_7->setContentsMargins(1, 1, 1, 1);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        titleLabel_7 = new QLabel(cfgCollaboration);
        titleLabel_7->setObjectName(QString::fromUtf8("titleLabel_7"));
        sizePolicy1.setHeightForWidth(titleLabel_7->sizePolicy().hasHeightForWidth());
        titleLabel_7->setSizePolicy(sizePolicy1);
        titleLabel_7->setFont(font);

        verticalLayout_7->addWidget(titleLabel_7);

        verticalSpacer_7 = new QSpacerItem(20, 281, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_7->addItem(verticalSpacer_7);

        stackedWidget->addWidget(cfgCollaboration);

        gridLayout_2->addWidget(stackedWidget, 0, 1, 1, 1);

        buttonBox = new QDialogButtonBox(SettingsWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        gridLayout_2->addWidget(buttonBox, 1, 0, 1, 2);


        retranslateUi(SettingsWindow);
        QObject::connect(buttonBox, SIGNAL(accepted()), SettingsWindow, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SettingsWindow, SLOT(reject()));

        leftListWidget->setCurrentRow(-1);
        stackedWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(SettingsWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingsWindow)
    {
        SettingsWindow->setWindowTitle(QApplication::translate("SettingsWindow", "piGameCreator settings", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = leftListWidget->isSortingEnabled();
        leftListWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = leftListWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("SettingsWindow", "General", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = leftListWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("SettingsWindow", "Class editor", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = leftListWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("SettingsWindow", "Code formatting", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = leftListWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("SettingsWindow", "Content servers", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem4 = leftListWidget->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("SettingsWindow", "Collaboration", 0, QApplication::UnicodeUTF8));
        leftListWidget->setSortingEnabled(__sortingEnabled);

        titleLabel->setText(QApplication::translate("SettingsWindow", "General settings", 0, QApplication::UnicodeUTF8));
        titleLabel_4->setText(QApplication::translate("SettingsWindow", "Class editor settings", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("SettingsWindow", "Behavior", 0, QApplication::UnicodeUTF8));
        EnableCodeCompletion->setText(QApplication::translate("SettingsWindow", "Enable Code completion", 0, QApplication::UnicodeUTF8));
        WarnForSyntaxErrorsOnSave->setText(QApplication::translate("SettingsWindow", "Warn for syntax errors on save", 0, QApplication::UnicodeUTF8));
        AskToDeclareUnknownVars->setText(QApplication::translate("SettingsWindow", "Ask to declare unknown variables on save", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("SettingsWindow", "Code editor", 0, QApplication::UnicodeUTF8));
        AutoIndentCode->setText(QApplication::translate("SettingsWindow", "Auto indent code", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SettingsWindow", "Tab size:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SettingsWindow", "chars", 0, QApplication::UnicodeUTF8));
        BackSpaceFollowsIndentation->setText(QApplication::translate("SettingsWindow", "Backspace follows indentation", 0, QApplication::UnicodeUTF8));
        AllowCursorEveryWhere->setText(QApplication::translate("SettingsWindow", "Allow cursor positioning everywhere", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SettingsWindow", "Auto close:", 0, QApplication::UnicodeUTF8));
        brackets->setText(QApplication::translate("SettingsWindow", "( )", 0, QApplication::UnicodeUTF8));
        squarebrackets->setText(QApplication::translate("SettingsWindow", "[ ]", 0, QApplication::UnicodeUTF8));
        curlybrackets->setText(QApplication::translate("SettingsWindow", "{ }", 0, QApplication::UnicodeUTF8));
        quotes->setText(QApplication::translate("SettingsWindow", "\" and '", 0, QApplication::UnicodeUTF8));
        comments->setText(QApplication::translate("SettingsWindow", "/* */", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("SettingsWindow", "Function library", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SettingsWindow", "When functon is used from:", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("SettingsWindow", "The Library", 0, QApplication::UnicodeUTF8));
        libAskArgs->setText(QApplication::translate("SettingsWindow", "Ask for agruments", 0, QApplication::UnicodeUTF8));
        libWriteSig->setText(QApplication::translate("SettingsWindow", "Write signature", 0, QApplication::UnicodeUTF8));
        groupBox_5->setTitle(QApplication::translate("SettingsWindow", "The Code Completer", 0, QApplication::UnicodeUTF8));
        ccAsk->setText(QApplication::translate("SettingsWindow", "Ask for agruments", 0, QApplication::UnicodeUTF8));
        ccWriteSig->setText(QApplication::translate("SettingsWindow", "Write signature", 0, QApplication::UnicodeUTF8));
        ccShowSig->setText(QApplication::translate("SettingsWindow", "Show signature", 0, QApplication::UnicodeUTF8));
        groupBox_6->setTitle(QApplication::translate("SettingsWindow", "Completed manually", 0, QApplication::UnicodeUTF8));
        cmWriteSig->setText(QApplication::translate("SettingsWindow", "Write signature", 0, QApplication::UnicodeUTF8));
        cmShowSig->setText(QApplication::translate("SettingsWindow", "Show signature", 0, QApplication::UnicodeUTF8));
        titleLabel_5->setText(QApplication::translate("SettingsWindow", "Code editor settings", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        editorFontComboBox->setToolTip(QApplication::translate("SettingsWindow", "Font face", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        fontSize->setToolTip(QApplication::translate("SettingsWindow", "Font size", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        fontSize->setSuffix(QApplication::translate("SettingsWindow", " pt", 0, QApplication::UnicodeUTF8));
        fontSize->setPrefix(QApplication::translate("SettingsWindow", "Size: ", 0, QApplication::UnicodeUTF8));
        titleLabel_6->setText(QApplication::translate("SettingsWindow", "Content servers", 0, QApplication::UnicodeUTF8));
        titleLabel_7->setText(QApplication::translate("SettingsWindow", "Collaboration options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SettingsWindow: public Ui_SettingsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
