/********************************************************************************
** Form generated from reading UI file 'config.ui'
**
** Created: Fri 20. Jul 17:22:10 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIG_H
#define UI_CONFIG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Config
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *cppgbRealPrecision;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QFrame *line;
    QLabel *label_2;
    QGroupBox *cppgbGameModding;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *checkBox_2;
    QFrame *modFrame;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_8;
    QCheckBox *checkBox_7;
    QCheckBox *checkBox_4;
    QLabel *label_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *cppgbCompilerOptions;
    QVBoxLayout *verticalLayout_3;
    QFormLayout *formLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit;
    QToolButton *toolButton;
    QGroupBox *cppgbWin32;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_3;
    QComboBox *exetype;
    QLabel *exeDesc;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget;
    QVBoxLayout *verticalLayout_5;
    QFrame *line_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *Config)
    {
        if (Config->objectName().isEmpty())
            Config->setObjectName(QString::fromUtf8("Config"));
        Config->resize(458, 355);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Config->sizePolicy().hasHeightForWidth());
        Config->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(Config);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(4, 4, 4, 4);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Config);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        widget_3 = new QWidget(Config);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        horizontalLayout_3 = new QHBoxLayout(widget_3);
#ifndef Q_OS_MAC
        horizontalLayout_3->setSpacing(6);
#endif
        horizontalLayout_3->setContentsMargins(3, 3, 3, 3);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        cppgbRealPrecision = new QGroupBox(widget_3);
        cppgbRealPrecision->setObjectName(QString::fromUtf8("cppgbRealPrecision"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(cppgbRealPrecision->sizePolicy().hasHeightForWidth());
        cppgbRealPrecision->setSizePolicy(sizePolicy2);
        verticalLayout_2 = new QVBoxLayout(cppgbRealPrecision);
        verticalLayout_2->setSpacing(3);
        verticalLayout_2->setContentsMargins(6, 6, 6, 6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton = new QRadioButton(cppgbRealPrecision);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));

        verticalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(cppgbRealPrecision);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(cppgbRealPrecision);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        verticalLayout_2->addWidget(radioButton_3);

        line = new QFrame(cppgbRealPrecision);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        label_2 = new QLabel(cppgbRealPrecision);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy3);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Tahoma"));
        font1.setPointSize(7);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        label_2->setWordWrap(true);

        verticalLayout_2->addWidget(label_2);


        horizontalLayout_3->addWidget(cppgbRealPrecision);

        cppgbGameModding = new QGroupBox(widget_3);
        cppgbGameModding->setObjectName(QString::fromUtf8("cppgbGameModding"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(cppgbGameModding->sizePolicy().hasHeightForWidth());
        cppgbGameModding->setSizePolicy(sizePolicy4);
        verticalLayout_4 = new QVBoxLayout(cppgbGameModding);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setContentsMargins(3, 3, 3, 3);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        checkBox_2 = new QCheckBox(cppgbGameModding);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        verticalLayout_4->addWidget(checkBox_2);

        modFrame = new QFrame(cppgbGameModding);
        modFrame->setObjectName(QString::fromUtf8("modFrame"));
        modFrame->setEnabled(false);
        modFrame->setFrameShape(QFrame::StyledPanel);
        modFrame->setFrameShadow(QFrame::Plain);
        modFrame->setLineWidth(1);
        verticalLayout_6 = new QVBoxLayout(modFrame);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(2, 2, 2, 2);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        checkBox_6 = new QCheckBox(modFrame);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));

        verticalLayout_6->addWidget(checkBox_6);

        checkBox_8 = new QCheckBox(modFrame);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));

        verticalLayout_6->addWidget(checkBox_8);

        checkBox_7 = new QCheckBox(modFrame);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));

        verticalLayout_6->addWidget(checkBox_7);

        checkBox_4 = new QCheckBox(modFrame);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        verticalLayout_6->addWidget(checkBox_4);


        verticalLayout_4->addWidget(modFrame);

        label_4 = new QLabel(cppgbGameModding);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QSizePolicy sizePolicy5(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy5);
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignJustify|Qt::AlignTop);
        label_4->setWordWrap(true);

        verticalLayout_4->addWidget(label_4);


        horizontalLayout_3->addWidget(cppgbGameModding);


        verticalLayout->addWidget(widget_3);

        widget_2 = new QWidget(Config);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
#ifndef Q_OS_MAC
        horizontalLayout->setSpacing(6);
#endif
        horizontalLayout->setContentsMargins(3, 3, 3, 3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        cppgbCompilerOptions = new QGroupBox(widget_2);
        cppgbCompilerOptions->setObjectName(QString::fromUtf8("cppgbCompilerOptions"));
        QSizePolicy sizePolicy6(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(cppgbCompilerOptions->sizePolicy().hasHeightForWidth());
        cppgbCompilerOptions->setSizePolicy(sizePolicy6);
        verticalLayout_3 = new QVBoxLayout(cppgbCompilerOptions);
        verticalLayout_3->setSpacing(3);
        verticalLayout_3->setContentsMargins(6, 6, 6, 6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_5 = new QLabel(cppgbCompilerOptions);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lineEdit = new QLineEdit(cppgbCompilerOptions);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy5.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy5);

        horizontalLayout_2->addWidget(lineEdit);

        toolButton = new QToolButton(cppgbCompilerOptions);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy7);

        horizontalLayout_2->addWidget(toolButton);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_2);


        verticalLayout_3->addLayout(formLayout);


        horizontalLayout->addWidget(cppgbCompilerOptions);

        cppgbWin32 = new QGroupBox(widget_2);
        cppgbWin32->setObjectName(QString::fromUtf8("cppgbWin32"));
        sizePolicy4.setHeightForWidth(cppgbWin32->sizePolicy().hasHeightForWidth());
        cppgbWin32->setSizePolicy(sizePolicy4);
        verticalLayout_7 = new QVBoxLayout(cppgbWin32);
        verticalLayout_7->setSpacing(3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(-1, 6, 6, 6);
        label_3 = new QLabel(cppgbWin32);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_7->addWidget(label_3);

        exetype = new QComboBox(cppgbWin32);
        exetype->setObjectName(QString::fromUtf8("exetype"));

        verticalLayout_7->addWidget(exetype);

        exeDesc = new QLabel(cppgbWin32);
        exeDesc->setObjectName(QString::fromUtf8("exeDesc"));
        QSizePolicy sizePolicy8(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy8.setHorizontalStretch(0);
        sizePolicy8.setVerticalStretch(0);
        sizePolicy8.setHeightForWidth(exeDesc->sizePolicy().hasHeightForWidth());
        exeDesc->setSizePolicy(sizePolicy8);
        exeDesc->setFont(font1);
        exeDesc->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_7->addWidget(exeDesc);


        horizontalLayout->addWidget(cppgbWin32);


        verticalLayout->addWidget(widget_2);

        verticalSpacer_2 = new QSpacerItem(450, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget = new QWidget(Config);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_5 = new QVBoxLayout(widget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(3, 0, 3, 3);
        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShadow(QFrame::Sunken);
        line_2->setFrameShape(QFrame::HLine);

        verticalLayout_5->addWidget(line_2);

        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_5->addWidget(buttonBox);


        verticalLayout->addWidget(widget);


        retranslateUi(Config);
        QObject::connect(buttonBox, SIGNAL(accepted()), Config, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Config, SLOT(reject()));
        QObject::connect(checkBox_2, SIGNAL(clicked(bool)), modFrame, SLOT(setEnabled(bool)));

        QMetaObject::connectSlotsByName(Config);
    } // setupUi

    void retranslateUi(QDialog *Config)
    {
        Config->setWindowTitle(QApplication::translate("Config", "C++ settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Config", "C++ / Mingw options", 0, QApplication::UnicodeUTF8));
        cppgbRealPrecision->setTitle(QApplication::translate("Config", "GameScript REAL precision", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("Config", "Low precision - float", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("Config", "Medium precision - double *", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("Config", "Quad precision - long double", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Config", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Tahoma'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#aa0000;\">NOTE:</span><span style=\" color:#aa0000;\"> Long</span><span style=\" font-weight:600; font-style:italic; color:#aa0000;\"> </span><span style=\" color:#aa0000;\">double type differs on most computers and may be slow. Float type is not so precise and is not recommended if you need acuracy. </span><span style=\" text-decoration: underline; color:#aa0000;\">If you don't know what these means, choose </span><span style=\" font-weight:600; text-decoration: underline; color:#aa0000;\">medium</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        cppgbGameModding->setTitle(QApplication::translate("Config", "Game modding", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("Config", "Support modding", 0, QApplication::UnicodeUTF8));
        checkBox_6->setText(QApplication::translate("Config", "Make classes shared libraries", 0, QApplication::UnicodeUTF8));
        checkBox_8->setText(QApplication::translate("Config", "Make worlds external", 0, QApplication::UnicodeUTF8));
        checkBox_7->setText(QApplication::translate("Config", "Make scenes external", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("Config", "Include piGameCreator Mod IDE", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Config", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Tahoma'; font-size:7pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-weight:600; color:#aa0000;\">NOTE:</span><span style=\" color:#aa0000;\"> With exception of classes, you can also</span><span style=\" font-weight:600; color:#aa0000;\"> implement modding by yourself</span><span style=\" color:#aa0000;\"> (which we recommend). Also, nothing can stop experienced hackers to mod your game anyway.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        cppgbCompilerOptions->setTitle(QApplication::translate("Config", "Compiler options", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Config", "MinGW path:", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QString());
        cppgbWin32->setTitle(QApplication::translate("Config", "Microsoft Windows", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Config", "Executable type:", 0, QApplication::UnicodeUTF8));
        exeDesc->setText(QApplication::translate("Config", "DESC", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Config: public Ui_Config {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIG_H
