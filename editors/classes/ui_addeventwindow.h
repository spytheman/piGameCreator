/********************************************************************************
** Form generated from reading UI file 'addeventwindow.ui'
**
** Created: Fri 2. Nov 07:48:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDEVENTWINDOW_H
#define UI_ADDEVENTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AddEventWindow
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTreeWidget *treeWidget;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *AddEventWindow)
    {
        if (AddEventWindow->objectName().isEmpty())
            AddEventWindow->setObjectName(QString::fromUtf8("AddEventWindow"));
        AddEventWindow->resize(514, 309);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        AddEventWindow->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(AddEventWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(AddEventWindow);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout->addWidget(label);

        treeWidget = new QTreeWidget(AddEventWindow);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/tick.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/bin.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/tango/actions/media-playback-start.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/pencil.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/shape_move_backwards.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/RES/ffficons/keyboard.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resources/RES/ffficons/mouse.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/resources/RES/ffficons/joystick.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/resources/RES/ffficons/image_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setIcon(0, icon1);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem->setToolTip(0, QString::fromUtf8("create"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem1->setIcon(0, icon2);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem1->setToolTip(0, QString::fromUtf8("init"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem2->setIcon(0, icon3);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem2->setToolTip(0, QString::fromUtf8("delete"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem3->setIcon(0, icon4);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem3->setToolTip(0, QString::fromUtf8("step"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem4->setIcon(0, icon5);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem4->setToolTip(0, QString::fromUtf8("render"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem5->setIcon(0, icon6);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem5->setToolTip(0, QString::fromUtf8("timer"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem6->setIcon(0, icon7);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem6->setToolTip(1, QString::fromUtf8("colision"));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem6->setToolTip(0, QString::fromUtf8("collision"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem7->setIcon(0, icon8);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem7->setToolTip(1, QString::fromUtf8("key"));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem7->setToolTip(0, QString::fromUtf8("key"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem8->setIcon(0, icon9);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem8->setToolTip(1, QString::fromUtf8("mouse"));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem8->setToolTip(0, QString::fromUtf8("mouse"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem9 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem9->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable);
        __qtreewidgetitem9->setIcon(0, icon10);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem9->setToolTip(1, QString::fromUtf8("joystick"));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem9->setToolTip(0, QString::fromUtf8("joystick"));
#endif // QT_NO_TOOLTIP
        QTreeWidgetItem *__qtreewidgetitem10 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem10->setFlags(Qt::ItemIsSelectable|Qt::ItemIsDragEnabled|Qt::ItemIsUserCheckable);
        __qtreewidgetitem10->setIcon(0, icon11);
#ifndef QT_NO_TOOLTIP
        __qtreewidgetitem10->setToolTip(0, QString::fromUtf8("touch"));
#endif // QT_NO_TOOLTIP
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->setIconSize(QSize(16, 16));
        treeWidget->setIndentation(0);
        treeWidget->header()->setDefaultSectionSize(140);

        verticalLayout->addWidget(treeWidget);

        buttonBox = new QDialogButtonBox(AddEventWindow);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(AddEventWindow);

        QMetaObject::connectSlotsByName(AddEventWindow);
    } // setupUi

    void retranslateUi(QDialog *AddEventWindow)
    {
        AddEventWindow->setWindowTitle(QApplication::translate("AddEventWindow", "Add event...", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("AddEventWindow", "Select which event to add to this class:", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("AddEventWindow", "Description", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("AddEventWindow", "Event", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QApplication::translate("AddEventWindow", "Occurs when object is created and placed in the scene.", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("AddEventWindow", "Create", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(1, QApplication::translate("AddEventWindow", "Occurs just after creation, but after current step finishes.", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("AddEventWindow", "Initialize", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem3->setText(1, QApplication::translate("AddEventWindow", "Occurs when object is deleted.", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem3->setText(0, QApplication::translate("AddEventWindow", "Destroy", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem4 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem4->setText(1, QApplication::translate("AddEventWindow", "Occurs every game tick", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem4->setText(0, QApplication::translate("AddEventWindow", "Step(priority)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem5 = treeWidget->topLevelItem(4);
        ___qtreewidgetitem5->setText(1, QApplication::translate("AddEventWindow", "Renders the object.", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem5->setText(0, QApplication::translate("AddEventWindow", "Render(pass)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem6 = treeWidget->topLevelItem(5);
        ___qtreewidgetitem6->setText(1, QApplication::translate("AddEventWindow", "Occurs when the int'th timer timeouts.", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem6->setText(0, QApplication::translate("AddEventWindow", "Timer(int)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget->topLevelItem(6);
        ___qtreewidgetitem7->setText(1, QApplication::translate("AddEventWindow", "Occurs when this object is overlapping other object.", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem7->setText(0, QApplication::translate("AddEventWindow", "Collision(class)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(7);
        ___qtreewidgetitem8->setText(1, QApplication::translate("AddEventWindow", "Occurs when keyboard key is pressed or released.", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem8->setText(0, QApplication::translate("AddEventWindow", "Key(type,key)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(8);
        ___qtreewidgetitem9->setText(1, QApplication::translate("AddEventWindow", "Occurs when mouse is clicked, released, moved or the wheel is rotated.", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem9->setText(0, QApplication::translate("AddEventWindow", "Mouse(type,button)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem10 = treeWidget->topLevelItem(9);
        ___qtreewidgetitem10->setText(1, QApplication::translate("AddEventWindow", "NOT IMPLEMENTED!", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem10->setText(0, QApplication::translate("AddEventWindow", "Joystick(type,button)", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem11 = treeWidget->topLevelItem(10);
        ___qtreewidgetitem11->setText(1, QApplication::translate("AddEventWindow", "NOT IMPLEMENTED!", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem11->setText(0, QApplication::translate("AddEventWindow", "Touch", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class AddEventWindow: public Ui_AddEventWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDEVENTWINDOW_H
