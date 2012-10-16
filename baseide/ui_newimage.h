/********************************************************************************
** Form generated from reading UI file 'newimage.ui'
**
** Created: Thu 11. Oct 18:31:02 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWIMAGE_H
#define UI_NEWIMAGE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QStackedWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_newImage
{
public:
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QFrame *line;
    QVBoxLayout *buttonsLayout;
    QSpacerItem *verticalSpacer;
    QCommandLinkButton *commandLinkButton;
    QFrame *line_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *newImage)
    {
        if (newImage->objectName().isEmpty())
            newImage->setObjectName(QString::fromUtf8("newImage"));
        newImage->resize(339, 257);
        newImage->setStyleSheet(QString::fromUtf8("QScrollArea\n"
"{\n"
"border: 1px inset #aaa;\n"
"}\n"
"\n"
"QScrollArea #bcontainer\n"
"{\n"
"background: #fff;\n"
"}"));
        verticalLayout = new QVBoxLayout(newImage);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        stackedWidget = new QStackedWidget(newImage);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label = new QLabel(page);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout_2->addWidget(label);

        line = new QFrame(page);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line);

        buttonsLayout = new QVBoxLayout();
        buttonsLayout->setSpacing(0);
        buttonsLayout->setObjectName(QString::fromUtf8("buttonsLayout"));

        verticalLayout_2->addLayout(buttonsLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        commandLinkButton = new QCommandLinkButton(page);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        commandLinkButton->setIcon(icon);

        verticalLayout_2->addWidget(commandLinkButton);

        line_2 = new QFrame(page);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_2->addWidget(line_2);

        buttonBox = new QDialogButtonBox(page);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel);

        verticalLayout_2->addWidget(buttonBox);

        stackedWidget->addWidget(page);

        verticalLayout->addWidget(stackedWidget);


        retranslateUi(newImage);
        QObject::connect(buttonBox, SIGNAL(rejected()), newImage, SLOT(reject()));

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(newImage);
    } // setupUi

    void retranslateUi(QDialog *newImage)
    {
        newImage->setWindowTitle(QApplication::translate("newImage", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("newImage", "Create image...", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("newImage", "Import image", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setDescription(QApplication::translate("newImage", "Imports previously saved image resource", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class newImage: public Ui_newImage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWIMAGE_H
