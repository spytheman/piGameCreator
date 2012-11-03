/********************************************************************************
** Form generated from reading UI file 'getkeyevent.ui'
**
** Created: Fri 2. Nov 07:48:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETKEYEVENT_H
#define UI_GETKEYEVENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QFormLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_getKeyEvent
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *EventTypeL;
    QComboBox *EventTypeCB;
    QLabel *keyL;
    QLabel *keyLabel;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *variableButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *OKbutton;
    QPushButton *cancelButton;

    void setupUi(QDialog *getKeyEvent)
    {
        if (getKeyEvent->objectName().isEmpty())
            getKeyEvent->setObjectName(QString::fromUtf8("getKeyEvent"));
        getKeyEvent->resize(271, 123);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/keyboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        getKeyEvent->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(getKeyEvent);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        EventTypeL = new QLabel(getKeyEvent);
        EventTypeL->setObjectName(QString::fromUtf8("EventTypeL"));

        formLayout->setWidget(0, QFormLayout::LabelRole, EventTypeL);

        EventTypeCB = new QComboBox(getKeyEvent);
        EventTypeCB->setObjectName(QString::fromUtf8("EventTypeCB"));

        formLayout->setWidget(0, QFormLayout::FieldRole, EventTypeCB);

        keyL = new QLabel(getKeyEvent);
        keyL->setObjectName(QString::fromUtf8("keyL"));

        formLayout->setWidget(1, QFormLayout::LabelRole, keyL);

        keyLabel = new QLabel(getKeyEvent);
        keyLabel->setObjectName(QString::fromUtf8("keyLabel"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        keyLabel->setFont(font);

        formLayout->setWidget(1, QFormLayout::FieldRole, keyLabel);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        variableButton = new QPushButton(getKeyEvent);
        variableButton->setObjectName(QString::fromUtf8("variableButton"));

        horizontalLayout->addWidget(variableButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        OKbutton = new QPushButton(getKeyEvent);
        OKbutton->setObjectName(QString::fromUtf8("OKbutton"));
        OKbutton->setEnabled(false);

        horizontalLayout->addWidget(OKbutton);

        cancelButton = new QPushButton(getKeyEvent);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(getKeyEvent);
        QObject::connect(OKbutton, SIGNAL(clicked()), getKeyEvent, SLOT(accept()));
        QObject::connect(cancelButton, SIGNAL(clicked()), getKeyEvent, SLOT(reject()));

        QMetaObject::connectSlotsByName(getKeyEvent);
    } // setupUi

    void retranslateUi(QDialog *getKeyEvent)
    {
        getKeyEvent->setWindowTitle(QApplication::translate("getKeyEvent", "Add keyboard event...", 0, QApplication::UnicodeUTF8));
        EventTypeL->setText(QApplication::translate("getKeyEvent", "Event type:", 0, QApplication::UnicodeUTF8));
        EventTypeCB->clear();
        EventTypeCB->insertItems(0, QStringList()
         << QApplication::translate("getKeyEvent", "Key is down", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("getKeyEvent", "Key being pressed", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("getKeyEvent", "Key being released", 0, QApplication::UnicodeUTF8)
        );
        keyL->setText(QApplication::translate("getKeyEvent", "Key:", 0, QApplication::UnicodeUTF8));
        keyLabel->setText(QApplication::translate("getKeyEvent", "(press a key...)", 0, QApplication::UnicodeUTF8));
        variableButton->setText(QApplication::translate("getKeyEvent", "Variable...", 0, QApplication::UnicodeUTF8));
        OKbutton->setText(QApplication::translate("getKeyEvent", "OK", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("getKeyEvent", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class getKeyEvent: public Ui_getKeyEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETKEYEVENT_H
