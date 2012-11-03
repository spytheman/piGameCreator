/********************************************************************************
** Form generated from reading UI file 'scripttestwindow.ui'
**
** Created: Fri 2. Nov 07:45:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTTESTWINDOW_H
#define UI_SCRIPTTESTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSplitter>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scripttestwindow
{
public:
    QAction *actionParse;
    QAction *actionC;
    QAction *actionJAVA;
    QAction *actionJS;
    QAction *actionCSharp;
    QAction *actionExporter_settings;
    QAction *actionEdit_pi_engine;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLineEdit *exporter;
    QLabel *label_3;
    QLineEdit *defines;
    QSplitter *splitter_2;
    QFrame *frame;
    QPlainTextEdit *plainTextEdit;
    QToolBar *toolBar_2;

    void setupUi(QMainWindow *scripttestwindow)
    {
        if (scripttestwindow->objectName().isEmpty())
            scripttestwindow->setObjectName(QString::fromUtf8("scripttestwindow"));
        scripttestwindow->resize(870, 579);
        actionParse = new QAction(scripttestwindow);
        actionParse->setObjectName(QString::fromUtf8("actionParse"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/tango/actions/media-playback-start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionParse->setIcon(icon);
        actionC = new QAction(scripttestwindow);
        actionC->setObjectName(QString::fromUtf8("actionC"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_cplusplus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionC->setIcon(icon1);
        actionJAVA = new QAction(scripttestwindow);
        actionJAVA->setObjectName(QString::fromUtf8("actionJAVA"));
        actionJAVA->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_cup.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionJAVA->setIcon(icon2);
        actionJS = new QAction(scripttestwindow);
        actionJS->setObjectName(QString::fromUtf8("actionJS"));
        actionJS->setEnabled(false);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_world.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionJS->setIcon(icon3);
        actionCSharp = new QAction(scripttestwindow);
        actionCSharp->setObjectName(QString::fromUtf8("actionCSharp"));
        actionCSharp->setEnabled(false);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_csharp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCSharp->setIcon(icon4);
        actionExporter_settings = new QAction(scripttestwindow);
        actionExporter_settings->setObjectName(QString::fromUtf8("actionExporter_settings"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/checks.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExporter_settings->setIcon(icon5);
        actionEdit_pi_engine = new QAction(scripttestwindow);
        actionEdit_pi_engine->setObjectName(QString::fromUtf8("actionEdit_pi_engine"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/enginelogo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_pi_engine->setIcon(icon6);
        centralwidget = new QWidget(scripttestwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout->addWidget(label_2);

        exporter = new QLineEdit(centralwidget);
        exporter->setObjectName(QString::fromUtf8("exporter"));
        exporter->setMaximumSize(QSize(60, 16777215));

        horizontalLayout->addWidget(exporter);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout->addWidget(label_3);

        defines = new QLineEdit(centralwidget);
        defines->setObjectName(QString::fromUtf8("defines"));

        horizontalLayout->addWidget(defines);


        verticalLayout->addLayout(horizontalLayout);

        splitter_2 = new QSplitter(centralwidget);
        splitter_2->setObjectName(QString::fromUtf8("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        frame = new QFrame(splitter_2);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        splitter_2->addWidget(frame);
        plainTextEdit = new QPlainTextEdit(splitter_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("Fixedsys"));
        font.setPointSize(9);
        plainTextEdit->setFont(font);
        splitter_2->addWidget(plainTextEdit);

        verticalLayout->addWidget(splitter_2);

        scripttestwindow->setCentralWidget(centralwidget);
        toolBar_2 = new QToolBar(scripttestwindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        toolBar_2->setIconSize(QSize(16, 16));
        toolBar_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        scripttestwindow->addToolBar(Qt::TopToolBarArea, toolBar_2);

        toolBar_2->addAction(actionParse);
        toolBar_2->addAction(actionExporter_settings);

        retranslateUi(scripttestwindow);

        QMetaObject::connectSlotsByName(scripttestwindow);
    } // setupUi

    void retranslateUi(QMainWindow *scripttestwindow)
    {
        scripttestwindow->setWindowTitle(QApplication::translate("scripttestwindow", "gamescript parser test mode", 0, QApplication::UnicodeUTF8));
        actionParse->setText(QApplication::translate("scripttestwindow", "Run", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionParse->setToolTip(QApplication::translate("scripttestwindow", "Run", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        actionParse->setShortcut(QApplication::translate("scripttestwindow", "F6", 0, QApplication::UnicodeUTF8));
        actionC->setText(QApplication::translate("scripttestwindow", "C++", 0, QApplication::UnicodeUTF8));
        actionC->setShortcut(QApplication::translate("scripttestwindow", "F9", 0, QApplication::UnicodeUTF8));
        actionJAVA->setText(QApplication::translate("scripttestwindow", "JAVA", 0, QApplication::UnicodeUTF8));
        actionJAVA->setShortcut(QApplication::translate("scripttestwindow", "F10", 0, QApplication::UnicodeUTF8));
        actionJS->setText(QApplication::translate("scripttestwindow", "JavaScript", 0, QApplication::UnicodeUTF8));
        actionJS->setShortcut(QApplication::translate("scripttestwindow", "F11", 0, QApplication::UnicodeUTF8));
        actionCSharp->setText(QApplication::translate("scripttestwindow", "C#", 0, QApplication::UnicodeUTF8));
        actionCSharp->setShortcut(QApplication::translate("scripttestwindow", "F12", 0, QApplication::UnicodeUTF8));
        actionExporter_settings->setText(QApplication::translate("scripttestwindow", "Exporter settings", 0, QApplication::UnicodeUTF8));
        actionEdit_pi_engine->setText(QApplication::translate("scripttestwindow", "Edit pi|engine", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("scripttestwindow", "Exporter:", 0, QApplication::UnicodeUTF8));
        exporter->setText(QApplication::translate("scripttestwindow", "cpp", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("scripttestwindow", "Defines:", 0, QApplication::UnicodeUTF8));
        defines->setText(QApplication::translate("scripttestwindow", "def1 message", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QApplication::translate("scripttestwindow", "Compiler output", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("scripttestwindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class scripttestwindow: public Ui_scripttestwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTTESTWINDOW_H
