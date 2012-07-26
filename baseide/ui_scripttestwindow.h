/********************************************************************************
** Form generated from reading UI file 'scripttestwindow.ui'
**
** Created: Fri 20. Jul 22:46:56 2012
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
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
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
    QAction *actionTEST;
    QAction *actionExpression;
    QAction *actionCreator_IDE;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QSplitter *splitter;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QWebView *debug;
    QToolBar *toolBar;

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
        actionTEST = new QAction(scripttestwindow);
        actionTEST->setObjectName(QString::fromUtf8("actionTEST"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/tango/actions/media-playback-start.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionTEST->setIcon(icon1);
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
        centralwidget = new QWidget(scripttestwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
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
        debug = new QWebView(splitter);
        debug->setObjectName(QString::fromUtf8("debug"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(debug->sizePolicy().hasHeightForWidth());
        debug->setSizePolicy(sizePolicy1);
        debug->setMaximumSize(QSize(16777215, 150));
        debug->setUrl(QUrl(QString::fromUtf8("about:blank")));
        splitter->addWidget(debug);

        verticalLayout->addWidget(splitter);

        scripttestwindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(scripttestwindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        scripttestwindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionSettings);
        toolBar->addAction(actionCreator_IDE);
        toolBar->addSeparator();
        toolBar->addAction(actionTEST);
        toolBar->addAction(actionExpression);

        retranslateUi(scripttestwindow);

        QMetaObject::connectSlotsByName(scripttestwindow);
    } // setupUi

    void retranslateUi(QMainWindow *scripttestwindow)
    {
        scripttestwindow->setWindowTitle(QApplication::translate("scripttestwindow", "gamescript parser test mode", 0, QApplication::UnicodeUTF8));
        actionSettings->setText(QApplication::translate("scripttestwindow", "Settings", 0, QApplication::UnicodeUTF8));
        actionSettings->setShortcut(QApplication::translate("scripttestwindow", "F1", 0, QApplication::UnicodeUTF8));
        actionTEST->setText(QApplication::translate("scripttestwindow", "Code test", 0, QApplication::UnicodeUTF8));
        actionTEST->setShortcut(QApplication::translate("scripttestwindow", "F5", 0, QApplication::UnicodeUTF8));
        actionExpression->setText(QApplication::translate("scripttestwindow", "Expression test", 0, QApplication::UnicodeUTF8));
        actionExpression->setShortcut(QApplication::translate("scripttestwindow", "F6", 0, QApplication::UnicodeUTF8));
        actionCreator_IDE->setText(QApplication::translate("scripttestwindow", "Creator IDE", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("scripttestwindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class scripttestwindow: public Ui_scripttestwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTTESTWINDOW_H
