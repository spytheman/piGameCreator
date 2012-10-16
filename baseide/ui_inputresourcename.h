/********************************************************************************
** Form generated from reading UI file 'inputresourcename.ui'
**
** Created: Thu 11. Oct 18:31:02 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INPUTRESOURCENAME_H
#define UI_INPUTRESOURCENAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_InputResourceName
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_2;
    QPushButton *pushButton;

    void setupUi(QDialog *InputResourceName)
    {
        if (InputResourceName->objectName().isEmpty())
            InputResourceName->setObjectName(QString::fromUtf8("InputResourceName"));
        InputResourceName->resize(318, 132);
        verticalLayout = new QVBoxLayout(InputResourceName);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(InputResourceName);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);

        verticalLayout->addWidget(label);

        label_2 = new QLabel(InputResourceName);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(InputResourceName);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        verticalSpacer = new QSpacerItem(300, 16, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton_2 = new QPushButton(InputResourceName);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);

        pushButton = new QPushButton(InputResourceName);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(InputResourceName);
        QObject::connect(pushButton, SIGNAL(clicked()), InputResourceName, SLOT(reject()));

        QMetaObject::connectSlotsByName(InputResourceName);
    } // setupUi

    void retranslateUi(QDialog *InputResourceName)
    {
        InputResourceName->setWindowTitle(QApplication::translate("InputResourceName", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("InputResourceName", "Enter the resource name...", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("InputResourceName", "All resource names must be unique.", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("InputResourceName", "OK", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("InputResourceName", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class InputResourceName: public Ui_InputResourceName {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INPUTRESOURCENAME_H
