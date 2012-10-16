/********************************************************************************
** Form generated from reading UI file 'addfunction.ui'
**
** Created: Thu 11. Oct 18:33:26 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDFUNCTION_H
#define UI_ADDFUNCTION_H

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
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddFunction
{
public:
    QVBoxLayout *verticalLayout;
    QFormLayout *formLayout;
    QLabel *fnL;
    QLineEdit *lineEdit;
    QLabel *returnL;
    QHBoxLayout *horizontalLayout;
    QComboBox *varType;
    QPushButton *selectClass;
    QWidget *argumentsAddRemove;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QToolButton *removeButton;
    QToolButton *AddButton;
    QTreeWidget *ArgumentList;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *advancedButton;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *okbutton;
    QPushButton *cancelbutton;

    void setupUi(QDialog *AddFunction)
    {
        if (AddFunction->objectName().isEmpty())
            AddFunction->setObjectName(QString::fromUtf8("AddFunction"));
        AddFunction->resize(318, 247);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/sum.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddFunction->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(AddFunction);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        fnL = new QLabel(AddFunction);
        fnL->setObjectName(QString::fromUtf8("fnL"));

        formLayout->setWidget(0, QFormLayout::LabelRole, fnL);

        lineEdit = new QLineEdit(AddFunction);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        returnL = new QLabel(AddFunction);
        returnL->setObjectName(QString::fromUtf8("returnL"));

        formLayout->setWidget(1, QFormLayout::LabelRole, returnL);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        varType = new QComboBox(AddFunction);
        varType->setObjectName(QString::fromUtf8("varType"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(varType->sizePolicy().hasHeightForWidth());
        varType->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(varType);

        selectClass = new QPushButton(AddFunction);
        selectClass->setObjectName(QString::fromUtf8("selectClass"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(selectClass->sizePolicy().hasHeightForWidth());
        selectClass->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(selectClass);


        formLayout->setLayout(1, QFormLayout::FieldRole, horizontalLayout);


        verticalLayout->addLayout(formLayout);

        argumentsAddRemove = new QWidget(AddFunction);
        argumentsAddRemove->setObjectName(QString::fromUtf8("argumentsAddRemove"));
        horizontalLayout_3 = new QHBoxLayout(argumentsAddRemove);
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(argumentsAddRemove);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        removeButton = new QToolButton(argumentsAddRemove);
        removeButton->setObjectName(QString::fromUtf8("removeButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        removeButton->setIcon(icon1);
        removeButton->setAutoRaise(true);

        horizontalLayout_3->addWidget(removeButton);

        AddButton = new QToolButton(argumentsAddRemove);
        AddButton->setObjectName(QString::fromUtf8("AddButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddButton->setIcon(icon2);
        AddButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_3->addWidget(AddButton);


        verticalLayout->addWidget(argumentsAddRemove);

        ArgumentList = new QTreeWidget(AddFunction);
        ArgumentList->setObjectName(QString::fromUtf8("ArgumentList"));
        ArgumentList->setSelectionMode(QAbstractItemView::ExtendedSelection);
        ArgumentList->setIndentation(0);

        verticalLayout->addWidget(ArgumentList);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        advancedButton = new QPushButton(AddFunction);
        advancedButton->setObjectName(QString::fromUtf8("advancedButton"));

        horizontalLayout_2->addWidget(advancedButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        okbutton = new QPushButton(AddFunction);
        okbutton->setObjectName(QString::fromUtf8("okbutton"));
        okbutton->setDefault(true);

        horizontalLayout_2->addWidget(okbutton);

        cancelbutton = new QPushButton(AddFunction);
        cancelbutton->setObjectName(QString::fromUtf8("cancelbutton"));

        horizontalLayout_2->addWidget(cancelbutton);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(AddFunction);
        QObject::connect(cancelbutton, SIGNAL(clicked()), AddFunction, SLOT(reject()));

        varType->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(AddFunction);
    } // setupUi

    void retranslateUi(QDialog *AddFunction)
    {
        AddFunction->setWindowTitle(QApplication::translate("AddFunction", "Add member function...", 0, QApplication::UnicodeUTF8));
        fnL->setText(QApplication::translate("AddFunction", "Function name:", 0, QApplication::UnicodeUTF8));
        returnL->setText(QApplication::translate("AddFunction", "Return type:", 0, QApplication::UnicodeUTF8));
        varType->clear();
        varType->insertItems(0, QStringList()
         << QApplication::translate("AddFunction", "Integer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddFunction", "Real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddFunction", "String", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddFunction", "Boolean", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddFunction", "Class", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("AddFunction", "No return type", 0, QApplication::UnicodeUTF8)
        );
        selectClass->setText(QApplication::translate("AddFunction", "Select class...", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("AddFunction", "Arguments:", 0, QApplication::UnicodeUTF8));
        removeButton->setText(QApplication::translate("AddFunction", "Delete", 0, QApplication::UnicodeUTF8));
        AddButton->setText(QApplication::translate("AddFunction", "Add", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = ArgumentList->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("AddFunction", "Argument type", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("AddFunction", "Argument name", 0, QApplication::UnicodeUTF8));
        advancedButton->setText(QApplication::translate("AddFunction", "Advanced...", 0, QApplication::UnicodeUTF8));
        okbutton->setText(QApplication::translate("AddFunction", "OK", 0, QApplication::UnicodeUTF8));
        cancelbutton->setText(QApplication::translate("AddFunction", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AddFunction: public Ui_AddFunction {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDFUNCTION_H
