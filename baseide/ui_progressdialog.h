/********************************************************************************
** Form generated from reading UI file 'progressdialog.ui'
**
** Created: Fri 2. Nov 07:45:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSDIALOG_H
#define UI_PROGRESSDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_progressdialog
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QProgressBar *progressBar;
    QPushButton *pushButton;
    QLabel *labelHeader;

    void setupUi(QWidget *progressdialog)
    {
        if (progressdialog->objectName().isEmpty())
            progressdialog->setObjectName(QString::fromUtf8("progressdialog"));
        progressdialog->resize(402, 117);
        gridLayout = new QGridLayout(progressdialog);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(progressdialog);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        gridLayout->addWidget(label, 1, 0, 1, 2);

        progressBar = new QProgressBar(progressdialog);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setMaximum(0);
        progressBar->setValue(-1);
        progressBar->setTextVisible(false);

        gridLayout->addWidget(progressBar, 2, 0, 1, 2);

        pushButton = new QPushButton(progressdialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy1);

        gridLayout->addWidget(pushButton, 3, 1, 1, 1);

        labelHeader = new QLabel(progressdialog);
        labelHeader->setObjectName(QString::fromUtf8("labelHeader"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        labelHeader->setFont(font);

        gridLayout->addWidget(labelHeader, 0, 0, 1, 1);


        retranslateUi(progressdialog);

        QMetaObject::connectSlotsByName(progressdialog);
    } // setupUi

    void retranslateUi(QWidget *progressdialog)
    {
        progressdialog->setWindowTitle(QApplication::translate("progressdialog", "Form", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("progressdialog", "Progress...", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("progressdialog", "Cancel", 0, QApplication::UnicodeUTF8));
        labelHeader->setText(QApplication::translate("progressdialog", "Header...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class progressdialog: public Ui_progressdialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSDIALOG_H
