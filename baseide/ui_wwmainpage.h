/********************************************************************************
** Form generated from reading UI file 'wwmainpage.ui'
**
** Created: Fri 2. Nov 07:45:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WWMAINPAGE_H
#define UI_WWMAINPAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QWidget>
#include <QtWebKit/QWebView>

QT_BEGIN_NAMESPACE

class Ui_wwMainPage
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QWebView *webView;

    void setupUi(QMainWindow *wwMainPage)
    {
        if (wwMainPage->objectName().isEmpty())
            wwMainPage->setObjectName(QString::fromUtf8("wwMainPage"));
        wwMainPage->resize(780, 550);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(wwMainPage->sizePolicy().hasHeightForWidth());
        wwMainPage->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(wwMainPage);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setSpacing(0);
        gridLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        webView = new QWebView(centralwidget);
        webView->setObjectName(QString::fromUtf8("webView"));
        webView->setMaximumSize(QSize(642, 482));
        webView->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        webView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        gridLayout->addWidget(webView, 0, 0, 1, 1);

        wwMainPage->setCentralWidget(centralwidget);

        retranslateUi(wwMainPage);

        QMetaObject::connectSlotsByName(wwMainPage);
    } // setupUi

    void retranslateUi(QMainWindow *wwMainPage)
    {
        wwMainPage->setWindowTitle(QApplication::translate("wwMainPage", "Main page", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class wwMainPage: public Ui_wwMainPage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WWMAINPAGE_H
