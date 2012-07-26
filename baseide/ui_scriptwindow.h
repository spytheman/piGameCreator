/********************************************************************************
** Form generated from reading UI file 'scriptwindow.ui'
**
** Created: Fri 20. Jul 17:13:29 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCRIPTWINDOW_H
#define UI_SCRIPTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_scriptwindow
{
public:
    QAction *actionSearch_Replace;
    QAction *actionInsert_function;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionInsert_object;
    QAction *actionLanguage_help;
    QAction *actionPrint;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *Sourcezone;
    QHBoxLayout *horizontalLayout_2;
    QToolBar *toolBar;

    void setupUi(QMainWindow *scriptwindow)
    {
        if (scriptwindow->objectName().isEmpty())
            scriptwindow->setObjectName(QString::fromUtf8("scriptwindow"));
        scriptwindow->resize(529, 411);
        actionSearch_Replace = new QAction(scriptwindow);
        actionSearch_Replace->setObjectName(QString::fromUtf8("actionSearch_Replace"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/magnifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSearch_Replace->setIcon(icon);
        actionInsert_function = new QAction(scriptwindow);
        actionInsert_function->setObjectName(QString::fromUtf8("actionInsert_function"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/sum.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsert_function->setIcon(icon1);
        actionCopy = new QAction(scriptwindow);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon2);
        actionPaste = new QAction(scriptwindow);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon3);
        actionCut = new QAction(scriptwindow);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon4);
        actionInsert_object = new QAction(scriptwindow);
        actionInsert_object->setObjectName(QString::fromUtf8("actionInsert_object"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/brick.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionInsert_object->setIcon(icon5);
        actionLanguage_help = new QAction(scriptwindow);
        actionLanguage_help->setObjectName(QString::fromUtf8("actionLanguage_help"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionLanguage_help->setIcon(icon6);
        actionPrint = new QAction(scriptwindow);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon7);
        centralwidget = new QWidget(scriptwindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        Sourcezone = new QWidget(centralwidget);
        Sourcezone->setObjectName(QString::fromUtf8("Sourcezone"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Sourcezone->sizePolicy().hasHeightForWidth());
        Sourcezone->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(Sourcezone);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));

        verticalLayout->addWidget(Sourcezone);

        scriptwindow->setCentralWidget(centralwidget);
        toolBar = new QToolBar(scriptwindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setFloatable(false);
        scriptwindow->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionSearch_Replace);
        toolBar->addAction(actionInsert_object);
        toolBar->addAction(actionInsert_function);
        toolBar->addSeparator();
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionCut);
        toolBar->addSeparator();
        toolBar->addAction(actionPrint);
        toolBar->addAction(actionLanguage_help);

        retranslateUi(scriptwindow);

        QMetaObject::connectSlotsByName(scriptwindow);
    } // setupUi

    void retranslateUi(QMainWindow *scriptwindow)
    {
        scriptwindow->setWindowTitle(QApplication::translate("scriptwindow", "GameScript code editor", 0, QApplication::UnicodeUTF8));
        actionSearch_Replace->setText(QApplication::translate("scriptwindow", "Search/replace", 0, QApplication::UnicodeUTF8));
        actionInsert_function->setText(QApplication::translate("scriptwindow", "Insert function", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("scriptwindow", "Copy", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("scriptwindow", "Paste", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("scriptwindow", "Cut", 0, QApplication::UnicodeUTF8));
        actionInsert_object->setText(QApplication::translate("scriptwindow", "Insert object", 0, QApplication::UnicodeUTF8));
        actionLanguage_help->setText(QApplication::translate("scriptwindow", "GameScript help", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("scriptwindow", "Print", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("scriptwindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class scriptwindow: public Ui_scriptwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCRIPTWINDOW_H
