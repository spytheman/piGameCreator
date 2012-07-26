/********************************************************************************
** Form generated from reading UI file 'compilingstatus.ui'
**
** Created: Fri 20. Jul 17:22:10 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPILINGSTATUS_H
#define UI_COMPILINGSTATUS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_CompilingStatus
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *header;
    QLabel *message;
    QProgressBar *progress;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *details;
    QDialogButtonBox *cancel;
    QPlainTextEdit *complog;

    void setupUi(QDialog *CompilingStatus)
    {
        if (CompilingStatus->objectName().isEmpty())
            CompilingStatus->setObjectName(QString::fromUtf8("CompilingStatus"));
        CompilingStatus->resize(407, 319);
        verticalLayout = new QVBoxLayout(CompilingStatus);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        header = new QLabel(CompilingStatus);
        header->setObjectName(QString::fromUtf8("header"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(header->sizePolicy().hasHeightForWidth());
        header->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        header->setFont(font);

        verticalLayout->addWidget(header);

        message = new QLabel(CompilingStatus);
        message->setObjectName(QString::fromUtf8("message"));
        sizePolicy.setHeightForWidth(message->sizePolicy().hasHeightForWidth());
        message->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(message);

        progress = new QProgressBar(CompilingStatus);
        progress->setObjectName(QString::fromUtf8("progress"));
        progress->setValue(24);
        progress->setTextVisible(false);

        verticalLayout->addWidget(progress);

        horizontalSpacer = new QSpacerItem(400, 6, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        details = new QPushButton(CompilingStatus);
        details->setObjectName(QString::fromUtf8("details"));
        details->setFlat(true);

        horizontalLayout->addWidget(details);

        cancel = new QDialogButtonBox(CompilingStatus);
        cancel->setObjectName(QString::fromUtf8("cancel"));
        cancel->setStandardButtons(QDialogButtonBox::Cancel);

        horizontalLayout->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout);

        complog = new QPlainTextEdit(CompilingStatus);
        complog->setObjectName(QString::fromUtf8("complog"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(complog->sizePolicy().hasHeightForWidth());
        complog->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(complog);


        retranslateUi(CompilingStatus);
        QObject::connect(cancel, SIGNAL(rejected()), CompilingStatus, SLOT(reject()));

        QMetaObject::connectSlotsByName(CompilingStatus);
    } // setupUi

    void retranslateUi(QDialog *CompilingStatus)
    {
        CompilingStatus->setWindowTitle(QApplication::translate("CompilingStatus", "Compiling...", 0, QApplication::UnicodeUTF8));
        header->setText(QApplication::translate("CompilingStatus", "Compiling...", 0, QApplication::UnicodeUTF8));
        message->setText(QApplication::translate("CompilingStatus", "Preparing...", 0, QApplication::UnicodeUTF8));
        details->setText(QApplication::translate("CompilingStatus", "Show details...", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class CompilingStatus: public Ui_CompilingStatus {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPILINGSTATUS_H
