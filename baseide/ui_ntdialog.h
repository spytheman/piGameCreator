/********************************************************************************
** Form generated from reading UI file 'ntdialog.ui'
**
** Created: Fri 20. Jul 17:13:29 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NTDIALOG_H
#define UI_NTDIALOG_H

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
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_NTdialog
{
public:
    QFormLayout *formLayout;
    QLabel *label_20;
    QComboBox *TypeComboBox;
    QLabel *label_19;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_7;
    QPushButton *OKbutton;
    QPushButton *CancelButton;
    QLabel *label;
    QLineEdit *valueEdit;
    QLabel *label_2;
    QPlainTextEdit *descEdit;

    void setupUi(QDialog *NTdialog)
    {
        if (NTdialog->objectName().isEmpty())
            NTdialog->setObjectName(QString::fromUtf8("NTdialog"));
        NTdialog->resize(252, 222);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/sum.png"), QSize(), QIcon::Normal, QIcon::Off);
        NTdialog->setWindowIcon(icon);
        formLayout = new QFormLayout(NTdialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_20 = new QLabel(NTdialog);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_20);

        TypeComboBox = new QComboBox(NTdialog);
        TypeComboBox->setObjectName(QString::fromUtf8("TypeComboBox"));
        TypeComboBox->setEditable(true);
        TypeComboBox->setMaxVisibleItems(20);

        formLayout->setWidget(0, QFormLayout::FieldRole, TypeComboBox);

        label_19 = new QLabel(NTdialog);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_19);

        lineEdit = new QLineEdit(NTdialog);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_7 = new QSpacerItem(60, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_7);

        OKbutton = new QPushButton(NTdialog);
        OKbutton->setObjectName(QString::fromUtf8("OKbutton"));
        OKbutton->setDefault(true);

        horizontalLayout->addWidget(OKbutton);

        CancelButton = new QPushButton(NTdialog);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout->addWidget(CancelButton);


        formLayout->setLayout(5, QFormLayout::SpanningRole, horizontalLayout);

        label = new QLabel(NTdialog);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label);

        valueEdit = new QLineEdit(NTdialog);
        valueEdit->setObjectName(QString::fromUtf8("valueEdit"));

        formLayout->setWidget(2, QFormLayout::FieldRole, valueEdit);

        label_2 = new QLabel(NTdialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(3, QFormLayout::SpanningRole, label_2);

        descEdit = new QPlainTextEdit(NTdialog);
        descEdit->setObjectName(QString::fromUtf8("descEdit"));

        formLayout->setWidget(4, QFormLayout::SpanningRole, descEdit);

#ifndef QT_NO_SHORTCUT
        label_20->setBuddy(TypeComboBox);
        label_19->setBuddy(lineEdit);
        label->setBuddy(valueEdit);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(TypeComboBox, lineEdit);
        QWidget::setTabOrder(lineEdit, valueEdit);
        QWidget::setTabOrder(valueEdit, OKbutton);
        QWidget::setTabOrder(OKbutton, CancelButton);

        retranslateUi(NTdialog);
        QObject::connect(CancelButton, SIGNAL(clicked()), NTdialog, SLOT(reject()));

        TypeComboBox->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(NTdialog);
    } // setupUi

    void retranslateUi(QDialog *NTdialog)
    {
        NTdialog->setWindowTitle(QApplication::translate("NTdialog", "Argument", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("NTdialog", "Type", 0, QApplication::UnicodeUTF8));
        TypeComboBox->clear();
        TypeComboBox->insertItems(0, QStringList()
         << QApplication::translate("NTdialog", "int", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NTdialog", "real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NTdialog", "bool", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("NTdialog", "string", 0, QApplication::UnicodeUTF8)
        );
        label_19->setText(QApplication::translate("NTdialog", "Name", 0, QApplication::UnicodeUTF8));
        OKbutton->setText(QApplication::translate("NTdialog", "OK", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("NTdialog", "Cancel", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NTdialog", "Value", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NTdialog", "Description", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NTdialog: public Ui_NTdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NTDIALOG_H
