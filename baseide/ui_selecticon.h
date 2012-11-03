/********************************************************************************
** Form generated from reading UI file 'selecticon.ui'
**
** Created: Fri 2. Nov 07:45:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTICON_H
#define UI_SELECTICON_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_selectIcon
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QLineEdit *searchTextBox;
    QToolButton *clearButton;
    QListWidget *listWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QToolButton *selectedIconTB;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QFrame *line;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *selectIcon)
    {
        if (selectIcon->objectName().isEmpty())
            selectIcon->setObjectName(QString::fromUtf8("selectIcon"));
        selectIcon->resize(411, 325);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        selectIcon->setWindowIcon(icon);
        selectIcon->setSizeGripEnabled(true);
        verticalLayout = new QVBoxLayout(selectIcon);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(selectIcon);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_3 = new QVBoxLayout(widget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label_2 = new QLabel(widget_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        searchTextBox = new QLineEdit(widget_2);
        searchTextBox->setObjectName(QString::fromUtf8("searchTextBox"));

        horizontalLayout_2->addWidget(searchTextBox);

        clearButton = new QToolButton(widget_2);
        clearButton->setObjectName(QString::fromUtf8("clearButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/clear_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon1);
        clearButton->setAutoRaise(true);

        horizontalLayout_2->addWidget(clearButton);


        verticalLayout_3->addLayout(horizontalLayout_2);

        listWidget = new QListWidget(widget_2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/accept.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon2);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/application_xp_terminal.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon4);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        listWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listWidget->setProperty("showDropIndicator", QVariant(false));
        listWidget->setDragDropMode(QAbstractItemView::DragDrop);
        listWidget->setIconSize(QSize(16, 16));
        listWidget->setMovement(QListView::Snap);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setResizeMode(QListView::Adjust);
        listWidget->setLayoutMode(QListView::SinglePass);
        listWidget->setGridSize(QSize(22, 22));
        listWidget->setViewMode(QListView::IconMode);
        listWidget->setUniformItemSizes(false);

        verticalLayout_3->addWidget(listWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(widget_2);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(label);

        selectedIconTB = new QToolButton(widget_2);
        selectedIconTB->setObjectName(QString::fromUtf8("selectedIconTB"));
        selectedIconTB->setAutoRaise(true);

        horizontalLayout->addWidget(selectedIconTB);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(widget_2);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder_picture.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon5);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout->addWidget(toolButton);


        verticalLayout_3->addLayout(horizontalLayout);


        verticalLayout->addWidget(widget_2);

        line = new QFrame(selectIcon);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        widget = new QWidget(selectIcon);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        buttonBox = new QDialogButtonBox(widget);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout_2->addWidget(buttonBox);


        verticalLayout->addWidget(widget);


        retranslateUi(selectIcon);
        QObject::connect(buttonBox, SIGNAL(rejected()), selectIcon, SLOT(reject()));
        QObject::connect(buttonBox, SIGNAL(accepted()), selectIcon, SLOT(accept()));

        QMetaObject::connectSlotsByName(selectIcon);
    } // setupUi

    void retranslateUi(QDialog *selectIcon)
    {
        selectIcon->setWindowTitle(QApplication::translate("selectIcon", "Select icon", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("selectIcon", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/ffficons/magnifier.png\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("selectIcon", " Search: ", 0, QApplication::UnicodeUTF8));
        clearButton->setText(QApplication::translate("selectIcon", "Search", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        listWidget->setSortingEnabled(__sortingEnabled);

        label->setText(QApplication::translate("selectIcon", "Selected:", 0, QApplication::UnicodeUTF8));
        selectedIconTB->setText(QApplication::translate("selectIcon", "(None)", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("selectIcon", "From file", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class selectIcon: public Ui_selectIcon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTICON_H
