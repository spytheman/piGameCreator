/********************************************************************************
** Form generated from reading UI file 'getclassresource.ui'
**
** Created: Fri 2. Nov 07:48:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETCLASSRESOURCE_H
#define UI_GETCLASSRESOURCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_getClassResource
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *TitleLabel;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *Filter;
    QToolButton *toolButton;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *ClearButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *OKbutton;
    QPushButton *CancelButton;

    void setupUi(QDialog *getClassResource)
    {
        if (getClassResource->objectName().isEmpty())
            getClassResource->setObjectName(QString::fromUtf8("getClassResource"));
        getClassResource->resize(268, 441);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/brick.png"), QSize(), QIcon::Normal, QIcon::Off);
        getClassResource->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(getClassResource);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        TitleLabel = new QLabel(getClassResource);
        TitleLabel->setObjectName(QString::fromUtf8("TitleLabel"));

        verticalLayout->addWidget(TitleLabel);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(getClassResource);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        Filter = new QLineEdit(getClassResource);
        Filter->setObjectName(QString::fromUtf8("Filter"));

        horizontalLayout_2->addWidget(Filter);

        toolButton = new QToolButton(getClassResource);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setEnabled(true);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/clear_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon1);
        toolButton->setAutoRaise(true);

        horizontalLayout_2->addWidget(toolButton);


        verticalLayout->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(getClassResource);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/app.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/defbg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon3);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon1);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setIcon(icon2);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setIconSize(QSize(16, 16));
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setMovement(QListView::Static);
        listWidget->setFlow(QListView::TopToBottom);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setWordWrap(true);

        verticalLayout->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 3, 2, -1);
        ClearButton = new QPushButton(getClassResource);
        ClearButton->setObjectName(QString::fromUtf8("ClearButton"));

        horizontalLayout->addWidget(ClearButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OKbutton = new QPushButton(getClassResource);
        OKbutton->setObjectName(QString::fromUtf8("OKbutton"));
        OKbutton->setDefault(true);

        horizontalLayout->addWidget(OKbutton);

        CancelButton = new QPushButton(getClassResource);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout->addWidget(CancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(getClassResource);
        QObject::connect(toolButton, SIGNAL(clicked()), Filter, SLOT(clear()));

        QMetaObject::connectSlotsByName(getClassResource);
    } // setupUi

    void retranslateUi(QDialog *getClassResource)
    {
        getClassResource->setWindowTitle(QApplication::translate("getClassResource", "Select class...", 0, QApplication::UnicodeUTF8));
        TitleLabel->setText(QApplication::translate("getClassResource", "Select a class", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("getClassResource", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/magnifier.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("getClassResource", "Clear", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("getClassResource", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("getClassResource", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("getClassResource", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("getClassResource", "New Item", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        ClearButton->setText(QApplication::translate("getClassResource", "Clear", 0, QApplication::UnicodeUTF8));
        OKbutton->setText(QApplication::translate("getClassResource", "OK", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("getClassResource", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class getClassResource: public Ui_getClassResource {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETCLASSRESOURCE_H
