/********************************************************************************
** Form generated from reading UI file 'splashscreen.ui'
**
** Created: Thu 11. Oct 18:31:02 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHSCREEN_H
#define UI_SPLASHSCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>

QT_BEGIN_NAMESPACE

class Ui_SplashScreen
{
public:
    QLabel *label;
    QLabel *splashLabel;

    void setupUi(QDialog *SplashScreen)
    {
        if (SplashScreen->objectName().isEmpty())
            SplashScreen->setObjectName(QString::fromUtf8("SplashScreen"));
        SplashScreen->resize(520, 349);
        label = new QLabel(SplashScreen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 513, 345));
        splashLabel = new QLabel(SplashScreen);
        splashLabel->setObjectName(QString::fromUtf8("splashLabel"));
        splashLabel->setGeometry(QRect(45, 290, 425, 16));
        splashLabel->setStyleSheet(QString::fromUtf8("color: #aaa;"));

        retranslateUi(SplashScreen);

        QMetaObject::connectSlotsByName(SplashScreen);
    } // setupUi

    void retranslateUi(QDialog *SplashScreen)
    {
        SplashScreen->setWindowTitle(QApplication::translate("SplashScreen", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SplashScreen", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/IDE/RES/splash.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        splashLabel->setText(QApplication::translate("SplashScreen", "Initializing pi|game CREATOR...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SplashScreen: public Ui_SplashScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHSCREEN_H
