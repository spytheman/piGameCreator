/********************************************************************************
** Form generated from reading UI file 'getmouseevent.ui'
**
** Created: Thu 11. Oct 18:33:26 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETMOUSEEVENT_H
#define UI_GETMOUSEEVENT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFormLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GetMouseEvent
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QFormLayout *formLayout;
    QLabel *label_2;
    QComboBox *EventType;
    QLabel *BtnLabel;
    QComboBox *ButtonMenu;
    QSpacerItem *verticalSpacer;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GetMouseEvent)
    {
        if (GetMouseEvent->objectName().isEmpty())
            GetMouseEvent->setObjectName(QString::fromUtf8("GetMouseEvent"));
        GetMouseEvent->resize(221, 127);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/mouse.png"), QSize(), QIcon::Normal, QIcon::Off);
        GetMouseEvent->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(GetMouseEvent);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(GetMouseEvent);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_2 = new QLabel(GetMouseEvent);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_2);

        EventType = new QComboBox(GetMouseEvent);
        EventType->setObjectName(QString::fromUtf8("EventType"));

        formLayout->setWidget(0, QFormLayout::FieldRole, EventType);

        BtnLabel = new QLabel(GetMouseEvent);
        BtnLabel->setObjectName(QString::fromUtf8("BtnLabel"));

        formLayout->setWidget(1, QFormLayout::LabelRole, BtnLabel);

        ButtonMenu = new QComboBox(GetMouseEvent);
        ButtonMenu->setObjectName(QString::fromUtf8("ButtonMenu"));

        formLayout->setWidget(1, QFormLayout::FieldRole, ButtonMenu);


        verticalLayout->addLayout(formLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonBox = new QDialogButtonBox(GetMouseEvent);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GetMouseEvent);
        QObject::connect(buttonBox, SIGNAL(accepted()), GetMouseEvent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), GetMouseEvent, SLOT(reject()));

        QMetaObject::connectSlotsByName(GetMouseEvent);
    } // setupUi

    void retranslateUi(QDialog *GetMouseEvent)
    {
        GetMouseEvent->setWindowTitle(QApplication::translate("GetMouseEvent", "Add mouse event", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("GetMouseEvent", "Select mouse event:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("GetMouseEvent", "Event type:", 0, QApplication::UnicodeUTF8));
        EventType->clear();
        EventType->insertItems(0, QStringList()
         << QApplication::translate("GetMouseEvent", "Clicked on this object", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GetMouseEvent", "Released on this object", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GetMouseEvent", "Button pressed", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GetMouseEvent", "Button released", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GetMouseEvent", "Button is down", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GetMouseEvent", "Wheel up", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GetMouseEvent", "Wheel down", 0, QApplication::UnicodeUTF8)
        );
        BtnLabel->setText(QApplication::translate("GetMouseEvent", "Button:", 0, QApplication::UnicodeUTF8));
        ButtonMenu->clear();
        ButtonMenu->insertItems(0, QStringList()
         << QApplication::translate("GetMouseEvent", "Left", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GetMouseEvent", "Right", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("GetMouseEvent", "Middle", 0, QApplication::UnicodeUTF8)
        );
    } // retranslateUi

};

namespace Ui {
    class GetMouseEvent: public Ui_GetMouseEvent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETMOUSEEVENT_H
