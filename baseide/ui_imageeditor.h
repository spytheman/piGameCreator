/********************************************************************************
** Form generated from reading UI file 'imageeditor.ui'
**
** Created: Tue 1. May 04:36:21 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEEDITOR_H
#define UI_IMAGEEDITOR_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImageEditor
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;

    void setupUi(QMainWindow *ImageEditor)
    {
        if (ImageEditor->objectName().isEmpty())
            ImageEditor->setObjectName(QString::fromUtf8("ImageEditor"));
        ImageEditor->resize(614, 475);
        centralwidget = new QWidget(ImageEditor);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        ImageEditor->setCentralWidget(centralwidget);

        retranslateUi(ImageEditor);

        QMetaObject::connectSlotsByName(ImageEditor);
    } // setupUi

    void retranslateUi(QMainWindow *ImageEditor)
    {
        ImageEditor->setWindowTitle(QApplication::translate("ImageEditor", "MainWindow", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ImageEditor", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/app.png\" /></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:16pt;\">Image Editor Main Widget</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt;\">currently only testing the system</span></p></body></html>", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImageEditor: public Ui_ImageEditor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEEDITOR_H
