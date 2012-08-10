/********************************************************************************
** Form generated from reading UI file 'scripttestwindow.ui'
**
** Created: Thu 26. Jul 23:32:03 2012
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
#include <QtGui/QComboBox>
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
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_scripttestwindow
{
public:
    QAction *actionSettings;
    QAction *actionParse;
    QAction *actionExpression;
    QAction *actionCreator_IDE;
    QAction *actionPreprocess;
    QAction *actionC;
    QAction *actionJAVA;
    QAction *actionJS;
    QAction *actionCSharp;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *target;
    QLabel *label_2;
    QLineEdit *exporter;
    QLabel *label_3;
    QLineEdit *defines;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit;
    QWebView *debug;
    QToolBar *toolBar;
    QToolBar *toolBar_2;
    QToolBar *toolBar_3;
    QToolBar *toolBar_4;

    void setupUi(QMainWindow *scripttestwindow)
    {
        if (scripttestwindow->objectName().isEmpty())
            scripttestwindow->setObjectName(QString::fromUtf8("scripttestwindow"));
        scripttestwindow->resize(870, 579);
        actionSettings = new QAction(scripttestwindow);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/cog.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSettings->setIcon(icon);
        actionParse = new QAction(scripttestwindow);
        actionParse->setObjectName(QString::fromUtf8("actionParse"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/tango/actions/media-playback-start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionParse->setIcon(icon1);
        actionExpression = new QAction(scripttestwindow);
        actionExpression->setObjectName(QString::fromUtf8("actionExpression"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/sum.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExpression->setIcon(icon2);
        actionCreator_IDE = new QAction(scripttestwindow);
        actionCreator_IDE->setObjectName(QString::fromUtf8("actionCreator_IDE"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/pi16x16.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCreator_IDE->setIcon(icon3);
        actionPreprocess = new QAction(scripttestwindow);
        actionPreprocess->setObjectName(QString::fromUtf8("actionPreprocess"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/asterisk_yellow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPreprocess->setIcon(icon4);
        actionC = new QAction(scripttestwindow);
        actionC->setObjectName(QString::fromUtf8("actionC"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_cplusplus.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionC->setIcon(icon5);
        actionJAVA = new QAction(scripttestwindow);
        actionJAVA->setObjectName(QString::fromUtf8("actionJAVA"));
        actionJAVA->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_cup.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionJAVA->setIcon(icon6);
        actionJS = new QAction(scripttestwindow);
        actionJS->setObjectName(QString::fromUtf8("actionJS"));
        actionJS->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_world.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionJS->setIcon(icon7);
        actionCSharp = new QAction(scripttestwindow);
        actionCSharp->setObjectName(QString::fromUtf8("actionCSharp"));
        actionCSharp->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_csharp.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCSharp->setIcon(icon8);
        centralwidget = new QWidget(scripttestwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        target = new QComboBox(centralwidget);
        target->setObjectName(QString::fromUtf8("target"));
        target->setMaximumSize(QSize(80, 16777215));
        target->setEditable(true);

        horizontalLayout->addWidget(target);

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
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        frame = new QFrame(splitter);
        frame->setObjectName(QString::fromUtf8("frame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy);
        frame->setFrameShape(QFrame::NoFrame);
        frame->setFrameShadow(QFrame::Plain);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        splitter->addWidget(frame);
        plainTextEdit = new QPlainTextEdit(splitter);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy1);
        splitter->addWidget(plainTextEdit);
        splitter_2->addWidget(splitter);
        debug = new QWebView(splitter_2);
        debug->setObjectName(QString::fromUtf8("debug"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(debug->sizePolicy().hasHeightForWidth());
        debug->setSizePolicy(sizePolicy2);
        debug->setMaximumSize(QSize(16777215, 200));
        debug->setUrl(QUrl(QString::fromUtf8("about:blank")));
        splitter_2->addWidget(debug);

        verticalLayout->addWidget(splitter_2);

        scripttestwindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(scripttestwindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        scripttestwindow->addToolBar(Qt::TopToolBarArea, toolBar);
        toolBar_2 = new QToolBar(scripttestwindow);
        toolBar_2->setObjectName(QString::fromUtf8("toolBar_2"));
        toolBar_2->setIconSize(QSize(16, 16));
        toolBar_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        scripttestwindow->addToolBar(Qt::TopToolBarArea, toolBar_2);
        toolBar_3 = new QToolBar(scripttestwindow);
        toolBar_3->setObjectName(QString::fromUtf8("toolBar_3"));
        toolBar_3->setIconSize(QSize(16, 16));
        scripttestwindow->addToolBar(Qt::TopToolBarArea, toolBar_3);
        toolBar_4 = new QToolBar(scripttestwindow);
        toolBar_4->setObjectName(QString::fromUtf8("toolBar_4"));
        toolBar_4->setIconSize(QSize(16, 16));
        toolBar_4->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        scripttestwindow->addToolBar(Qt::TopToolBarArea, toolBar_4);

        toolBar->addAction(actionSettings);
        toolBar_2->addAction(actionPreprocess);
        toolBar_2->addAction(actionParse);
        toolBar_2->addAction(actionExpression);
        toolBar_3->addAction(actionC);
        toolBar_3->addAction(actionJAVA);
        toolBar_3->addAction(actionJS);
        toolBar_3->addAction(actionCSharp);
        toolBar_4->addAction(actionCreator_IDE);

        retranslateUi(scripttestwindow);

        QMetaObject::connectSlotsByName(scripttestwindow);
    } // setupUi

    void retranslateUi(QMainWindow *scripttestwindow)
    {
        scripttestwindow->setWindowTitle(QApplication::translate("scripttestwindow", "gamescript parser test mode", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("scripttestwindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionSettings->setShortcut(QApplication::translate("scripttestwindow", "F1", 0, QApplication::UnicodeUTF8));
        actionParse->setText(QApplication::translate("scripttestwindow", "Parse", 0, QApplication::UnicodeUTF8));
        actionParse->setShortcut(QApplication::translate("scripttestwindow", "F6", 0, QApplication::UnicodeUTF8));
        actionExpression->setText(QApplication::translate("scripttestwindow", "Expression", 0, QApplication::UnicodeUTF8));
        actionExpression->setShortcut(QApplication::translate("scripttestwindow", "F7", 0, QApplication::UnicodeUTF8));
        actionCreator_IDE->setText(QApplication::translate("scripttestwindow", "Creator IDE", 0, QApplication::UnicodeUTF8));
        actionPreprocess->setText(QApplication::translate("scripttestwindow", "Preprocess", 0, QApplication::UnicodeUTF8));
        actionPreprocess->setShortcut(QApplication::translate("scripttestwindow", "F5", 0, QApplication::UnicodeUTF8));
        actionC->setText(QApplication::translate("scripttestwindow", "C++", 0, QApplication::UnicodeUTF8));
        actionC->setShortcut(QApplication::translate("scripttestwindow", "F9", 0, QApplication::UnicodeUTF8));
        actionJAVA->setText(QApplication::translate("scripttestwindow", "JAVA", 0, QApplication::UnicodeUTF8));
        actionJAVA->setShortcut(QApplication::translate("scripttestwindow", "F10", 0, QApplication::UnicodeUTF8));
        actionJS->setText(QApplication::translate("scripttestwindow", "JavaScript", 0, QApplication::UnicodeUTF8));
        actionJS->setShortcut(QApplication::translate("scripttestwindow", "F11", 0, QApplication::UnicodeUTF8));
        actionCSharp->setText(QApplication::translate("scripttestwindow", "C#", 0, QApplication::UnicodeUTF8));
        actionCSharp->setShortcut(QApplication::translate("scripttestwindow", "F12", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("scripttestwindow", "Target:", 0, QApplication::UnicodeUTF8));
        target->clear();
        target->insertItems(0, QStringList()
         << QApplication::translate("scripttestwindow", "full", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("scripttestwindow", "demo", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("scripttestwindow", "Windows", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("scripttestwindow", "Android", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("scripttestwindow", "Exporter:", 0, QApplication::UnicodeUTF8));
        exporter->setText(QApplication::translate("scripttestwindow", "cpp", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("scripttestwindow", "Defines:", 0, QApplication::UnicodeUTF8));
        defines->setText(QApplication::translate("scripttestwindow", "def1 message", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("scripttestwindow", "toolBar", 0, QApplication::UnicodeUTF8));
        toolBar_2->setWindowTitle(QApplication::translate("scripttestwindow", "toolBar_2", 0, QApplication::UnicodeUTF8));
        toolBar_3->setWindowTitle(QApplication::translate("scripttestwindow", "toolBar_3", 0, QApplication::UnicodeUTF8));
        toolBar_4->setWindowTitle(QApplication::translate("scripttestwindow", "toolBar_4", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class scripttestwindow: public Ui_scripttestwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTTESTWINDOW_H
