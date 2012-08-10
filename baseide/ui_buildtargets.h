/********************************************************************************
** Form generated from reading UI file 'buildtargets.ui'
**
** Created: Thu 26. Jul 04:24:13 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BUILDTARGETS_H
#define UI_BUILDTARGETS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_BuildTargets
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *AddTarget;
    QSpacerItem *horizontalSpacer;
    QToolButton *DelTarget;
    QFrame *line;
    QListWidget *TargetsLV;
    QWidget *SettingsPart;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *DisplayName;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *codeName;
    QToolButton *toolButton_3;
    QLabel *label_4;
    QPlainTextEdit *DescText;
    QLabel *label_3;
    QStackedWidget *stackedWidget;
    QWidget *pgExporterSelect;
    QHBoxLayout *horizontalLayout;
    QComboBox *ExporterComboBox;
    QToolButton *toolButton_2;
    QPushButton *OptionsButton;
    QWidget *pgExporterInvalid;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *exporterLineEdit;
    QToolButton *toolButton;
    QPushButton *OptionsButton_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout_4;
    QLabel *exporterDescription;
    QLabel *label_6;
    QLineEdit *defines;
    QVBoxLayout *verticalLayout_2;
    QPushButton *OKbutton;
    QPushButton *cancelbutton;
    QSpacerItem *verticalSpacer;
    QPushButton *helpbutton;
    QLabel *label_2;

    void setupUi(QDialog *BuildTargets)
    {
        if (BuildTargets->objectName().isEmpty())
            BuildTargets->setObjectName(QString::fromUtf8("BuildTargets"));
        BuildTargets->resize(573, 415);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/computer.png"), QSize(), QIcon::Normal, QIcon::Off);
        BuildTargets->setWindowIcon(icon);
        BuildTargets->setModal(true);
        gridLayout = new QGridLayout(BuildTargets);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        frame_2 = new QFrame(BuildTargets);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame_2->sizePolicy().hasHeightForWidth());
        frame_2->setSizePolicy(sizePolicy);
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Plain);
        verticalLayout_5 = new QVBoxLayout(frame_2);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
#ifndef Q_OS_MAC
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
#endif
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        AddTarget = new QToolButton(frame_2);
        AddTarget->setObjectName(QString::fromUtf8("AddTarget"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddTarget->setIcon(icon1);
        AddTarget->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        AddTarget->setAutoRaise(true);

        horizontalLayout_3->addWidget(AddTarget);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        DelTarget = new QToolButton(frame_2);
        DelTarget->setObjectName(QString::fromUtf8("DelTarget"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DelTarget->setIcon(icon2);
        DelTarget->setToolButtonStyle(Qt::ToolButtonIconOnly);
        DelTarget->setAutoRaise(true);

        horizontalLayout_3->addWidget(DelTarget);


        verticalLayout_3->addLayout(horizontalLayout_3);

        line = new QFrame(frame_2);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShadow(QFrame::Raised);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_3->addWidget(line);

        TargetsLV = new QListWidget(frame_2);
        TargetsLV->setObjectName(QString::fromUtf8("TargetsLV"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(TargetsLV->sizePolicy().hasHeightForWidth());
        TargetsLV->setSizePolicy(sizePolicy1);
        TargetsLV->setMinimumSize(QSize(150, 0));
        TargetsLV->setMaximumSize(QSize(150, 16777215));
        TargetsLV->setFrameShape(QFrame::NoFrame);

        verticalLayout_3->addWidget(TargetsLV);


        verticalLayout_5->addLayout(verticalLayout_3);


        horizontalLayout_2->addWidget(frame_2);

        SettingsPart = new QWidget(BuildTargets);
        SettingsPart->setObjectName(QString::fromUtf8("SettingsPart"));
        formLayout = new QFormLayout(SettingsPart);
        formLayout->setContentsMargins(0, 0, 0, 0);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(SettingsPart);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        DisplayName = new QLineEdit(SettingsPart);
        DisplayName->setObjectName(QString::fromUtf8("DisplayName"));

        formLayout->setWidget(0, QFormLayout::FieldRole, DisplayName);

        label_5 = new QLabel(SettingsPart);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        codeName = new QLineEdit(SettingsPart);
        codeName->setObjectName(QString::fromUtf8("codeName"));

        horizontalLayout_5->addWidget(codeName);

        toolButton_3 = new QToolButton(SettingsPart);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/arrow_refresh_small.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon3);
        toolButton_3->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton_3);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout_5);

        label_4 = new QLabel(SettingsPart);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        DescText = new QPlainTextEdit(SettingsPart);
        DescText->setObjectName(QString::fromUtf8("DescText"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(DescText->sizePolicy().hasHeightForWidth());
        DescText->setSizePolicy(sizePolicy2);
        DescText->setMaximumSize(QSize(16777215, 60));

        formLayout->setWidget(3, QFormLayout::FieldRole, DescText);

        label_3 = new QLabel(SettingsPart);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        stackedWidget = new QStackedWidget(SettingsPart);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pgExporterSelect = new QWidget();
        pgExporterSelect->setObjectName(QString::fromUtf8("pgExporterSelect"));
        horizontalLayout = new QHBoxLayout(pgExporterSelect);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        ExporterComboBox = new QComboBox(pgExporterSelect);
        ExporterComboBox->setObjectName(QString::fromUtf8("ExporterComboBox"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ExporterComboBox->sizePolicy().hasHeightForWidth());
        ExporterComboBox->setSizePolicy(sizePolicy3);

        horizontalLayout->addWidget(ExporterComboBox);

        toolButton_2 = new QToolButton(pgExporterSelect);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/textfield_rename.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon4);

        horizontalLayout->addWidget(toolButton_2);

        OptionsButton = new QPushButton(pgExporterSelect);
        OptionsButton->setObjectName(QString::fromUtf8("OptionsButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/checks.png"), QSize(), QIcon::Normal, QIcon::Off);
        OptionsButton->setIcon(icon5);

        horizontalLayout->addWidget(OptionsButton);

        stackedWidget->addWidget(pgExporterSelect);
        pgExporterInvalid = new QWidget();
        pgExporterInvalid->setObjectName(QString::fromUtf8("pgExporterInvalid"));
        horizontalLayout_4 = new QHBoxLayout(pgExporterInvalid);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        exporterLineEdit = new QLineEdit(pgExporterInvalid);
        exporterLineEdit->setObjectName(QString::fromUtf8("exporterLineEdit"));

        horizontalLayout_4->addWidget(exporterLineEdit);

        toolButton = new QToolButton(pgExporterInvalid);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/cursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon6);

        horizontalLayout_4->addWidget(toolButton);

        OptionsButton_2 = new QPushButton(pgExporterInvalid);
        OptionsButton_2->setObjectName(QString::fromUtf8("OptionsButton_2"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        OptionsButton_2->setIcon(icon7);

        horizontalLayout_4->addWidget(OptionsButton_2);

        stackedWidget->addWidget(pgExporterInvalid);

        formLayout->setWidget(4, QFormLayout::FieldRole, stackedWidget);

        frame = new QFrame(SettingsPart);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout_4 = new QVBoxLayout(frame);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        exporterDescription = new QLabel(frame);
        exporterDescription->setObjectName(QString::fromUtf8("exporterDescription"));
        QSizePolicy sizePolicy4(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(exporterDescription->sizePolicy().hasHeightForWidth());
        exporterDescription->setSizePolicy(sizePolicy4);
        exporterDescription->setWordWrap(true);

        verticalLayout_4->addWidget(exporterDescription);


        formLayout->setWidget(5, QFormLayout::SpanningRole, frame);

        label_6 = new QLabel(SettingsPart);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        defines = new QLineEdit(SettingsPart);
        defines->setObjectName(QString::fromUtf8("defines"));

        formLayout->setWidget(2, QFormLayout::FieldRole, defines);


        horizontalLayout_2->addWidget(SettingsPart);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        OKbutton = new QPushButton(BuildTargets);
        OKbutton->setObjectName(QString::fromUtf8("OKbutton"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(OKbutton->sizePolicy().hasHeightForWidth());
        OKbutton->setSizePolicy(sizePolicy5);
        OKbutton->setDefault(true);

        verticalLayout_2->addWidget(OKbutton);

        cancelbutton = new QPushButton(BuildTargets);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));
        sizePolicy5.setHeightForWidth(cancelbutton->sizePolicy().hasHeightForWidth());
        cancelbutton->setSizePolicy(sizePolicy5);

        verticalLayout_2->addWidget(cancelbutton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        helpbutton = new QPushButton(BuildTargets);
        helpbutton->setObjectName(QString::fromUtf8("helpbutton"));
        sizePolicy5.setHeightForWidth(helpbutton->sizePolicy().hasHeightForWidth());
        helpbutton->setSizePolicy(sizePolicy5);

        verticalLayout_2->addWidget(helpbutton);


        gridLayout->addLayout(verticalLayout_2, 0, 1, 2, 1);

        label_2 = new QLabel(BuildTargets);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy6);
        label_2->setWordWrap(true);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        retranslateUi(BuildTargets);
        QObject::connect(cancelbutton, SIGNAL(clicked()), BuildTargets, SLOT(reject()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(BuildTargets);
    } // setupUi

    void retranslateUi(QDialog *BuildTargets)
    {
        BuildTargets->setWindowTitle(QApplication::translate("BuildTargets", "Project Build Targets", 0, QApplication::UnicodeUTF8));
        AddTarget->setText(QApplication::translate("BuildTargets", "Add target", 0, QApplication::UnicodeUTF8));
        DelTarget->setText(QApplication::translate("BuildTargets", "Delete", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("BuildTargets", "Display name:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("BuildTargets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Courier New,courier';\">#target</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("BuildTargets", "revert", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("BuildTargets", "Description:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("BuildTargets", "Exporter:", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("BuildTargets", "Edit", 0, QApplication::UnicodeUTF8));
        OptionsButton->setText(QApplication::translate("BuildTargets", "Options", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("BuildTargets", "Select", 0, QApplication::UnicodeUTF8));
        OptionsButton_2->setText(QApplication::translate("BuildTargets", "Options", 0, QApplication::UnicodeUTF8));
        exporterDescription->setText(QApplication::translate("BuildTargets", "Description", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("BuildTargets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">Defines:</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        OKbutton->setText(QApplication::translate("BuildTargets", "OK", 0, QApplication::UnicodeUTF8));
        cancelbutton->setText(QApplication::translate("BuildTargets", "Cancel", 0, QApplication::UnicodeUTF8));
        helpbutton->setText(QApplication::translate("BuildTargets", "Help", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("BuildTargets", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">To make conditional code for a target, use the </span><span style=\" font-family:'Courier New,courier'; font-size:8pt;\">#target</span><span style=\" font-size:8pt;\"> GameScript directive.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">The </span><span style=\" font-size:8pt; font-style:italic;\">defines</span><span style=\" font-size:8pt;\"> field must contain space separated names. Use </span><span st"
                        "yle=\" font-family:'Courier New,courier'; font-size:8pt;\">#ifdef</span><span style=\" font-size:8pt;\"> or </span><span style=\" font-family:'Courier New,courier'; font-size:8pt;\">#ifndef</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class BuildTargets: public Ui_BuildTargets {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BUILDTARGETS_H
