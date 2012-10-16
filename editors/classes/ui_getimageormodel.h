/********************************************************************************
** Form generated from reading UI file 'getimageormodel.ui'
**
** Created: Sun 23. Sep 18:30:50 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETIMAGEORMODEL_H
#define UI_GETIMAGEORMODEL_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_getRepresentation
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_4;
    QRadioButton *rpNone;
    QRadioButton *rpImage;
    QRadioButton *rpModel;
    QRadioButton *rpRectangle;
    QRadioButton *rpPath;
    QRadioButton *rpGraph;
    QRadioButton *rpText;
    QSpacerItem *verticalSpacer_2;
    QStackedWidget *stackedWidget;
    QWidget *pgNone;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QWidget *pgImage;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QListWidget *listWidget;
    QWidget *pgModel;
    QWidget *pgRectangle;
    QWidget *pgVectorPath;
    QWidget *pgText;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *getRepresentation)
    {
        if (getRepresentation->objectName().isEmpty())
            getRepresentation->setObjectName(QString::fromUtf8("getRepresentation"));
        getRepresentation->resize(586, 355);
        verticalLayout = new QVBoxLayout(getRepresentation);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox = new QGroupBox(getRepresentation);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        verticalLayout_4 = new QVBoxLayout(groupBox);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setContentsMargins(6, 6, 6, 6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        rpNone = new QRadioButton(groupBox);
        rpNone->setObjectName(QString::fromUtf8("rpNone"));
        rpNone->setChecked(true);

        verticalLayout_4->addWidget(rpNone);

        rpImage = new QRadioButton(groupBox);
        rpImage->setObjectName(QString::fromUtf8("rpImage"));

        verticalLayout_4->addWidget(rpImage);

        rpModel = new QRadioButton(groupBox);
        rpModel->setObjectName(QString::fromUtf8("rpModel"));

        verticalLayout_4->addWidget(rpModel);

        rpRectangle = new QRadioButton(groupBox);
        rpRectangle->setObjectName(QString::fromUtf8("rpRectangle"));

        verticalLayout_4->addWidget(rpRectangle);

        rpPath = new QRadioButton(groupBox);
        rpPath->setObjectName(QString::fromUtf8("rpPath"));

        verticalLayout_4->addWidget(rpPath);

        rpGraph = new QRadioButton(groupBox);
        rpGraph->setObjectName(QString::fromUtf8("rpGraph"));

        verticalLayout_4->addWidget(rpGraph);

        rpText = new QRadioButton(groupBox);
        rpText->setObjectName(QString::fromUtf8("rpText"));

        verticalLayout_4->addWidget(rpText);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);


        horizontalLayout_3->addWidget(groupBox);

        stackedWidget = new QStackedWidget(getRepresentation);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        pgNone = new QWidget();
        pgNone->setObjectName(QString::fromUtf8("pgNone"));
        gridLayout = new QGridLayout(pgNone);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(pgNone);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        stackedWidget->addWidget(pgNone);
        pgImage = new QWidget();
        pgImage->setObjectName(QString::fromUtf8("pgImage"));
        verticalLayout_5 = new QVBoxLayout(pgImage);
        verticalLayout_5->setSpacing(3);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(pgImage);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        listWidget = new QListWidget(pgImage);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/app.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/defbg.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon1);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/clear_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon2);
        QListWidgetItem *__qlistwidgetitem3 = new QListWidgetItem(listWidget);
        __qlistwidgetitem3->setIcon(icon);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setIconSize(QSize(64, 64));
        listWidget->setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
        listWidget->setMovement(QListView::Static);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setSpacing(10);
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setWordWrap(true);

        verticalLayout_5->addWidget(listWidget);

        stackedWidget->addWidget(pgImage);
        pgModel = new QWidget();
        pgModel->setObjectName(QString::fromUtf8("pgModel"));
        stackedWidget->addWidget(pgModel);
        pgRectangle = new QWidget();
        pgRectangle->setObjectName(QString::fromUtf8("pgRectangle"));
        stackedWidget->addWidget(pgRectangle);
        pgVectorPath = new QWidget();
        pgVectorPath->setObjectName(QString::fromUtf8("pgVectorPath"));
        stackedWidget->addWidget(pgVectorPath);
        pgText = new QWidget();
        pgText->setObjectName(QString::fromUtf8("pgText"));
        stackedWidget->addWidget(pgText);

        horizontalLayout_3->addWidget(stackedWidget);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, 3, 2, -1);
        pushButton_2 = new QPushButton(getRepresentation);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(getRepresentation);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setDefault(true);

        horizontalLayout->addWidget(pushButton);

        pushButton_3 = new QPushButton(getRepresentation);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(getRepresentation);
        QObject::connect(pushButton, SIGNAL(clicked()), getRepresentation, SLOT(accept()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), getRepresentation, SLOT(reject()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(getRepresentation);
    } // setupUi

    void retranslateUi(QDialog *getRepresentation)
    {
        getRepresentation->setWindowTitle(QApplication::translate("getRepresentation", "Select resource...", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("getRepresentation", "Representation", 0, QApplication::UnicodeUTF8));
        rpNone->setText(QApplication::translate("getRepresentation", "None", 0, QApplication::UnicodeUTF8));
        rpImage->setText(QApplication::translate("getRepresentation", "Image", 0, QApplication::UnicodeUTF8));
        rpModel->setText(QApplication::translate("getRepresentation", "Model", 0, QApplication::UnicodeUTF8));
        rpRectangle->setText(QApplication::translate("getRepresentation", "Rectangle", 0, QApplication::UnicodeUTF8));
        rpPath->setText(QApplication::translate("getRepresentation", "Vector path", 0, QApplication::UnicodeUTF8));
        rpGraph->setText(QApplication::translate("getRepresentation", "Graph", 0, QApplication::UnicodeUTF8));
        rpText->setText(QApplication::translate("getRepresentation", "Text", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("getRepresentation", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">Select a representation for this object</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:10pt;\">This is only used for the Editors.</span></p>\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:7pt;\">Render events will ignore this setting runtime."
                        "</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("getRepresentation", "Select the image", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("getRepresentation", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("getRepresentation", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("getRepresentation", "New Item", 0, QApplication::UnicodeUTF8));
        QListWidgetItem *___qlistwidgetitem3 = listWidget->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("getRepresentation", "New Item", 0, QApplication::UnicodeUTF8));
        listWidget->setSortingEnabled(__sortingEnabled);

        pushButton_2->setText(QApplication::translate("getRepresentation", "Clear", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("getRepresentation", "OK", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("getRepresentation", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class getRepresentation: public Ui_getRepresentation {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETIMAGEORMODEL_H
