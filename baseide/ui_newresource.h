/********************************************************************************
** Form generated from reading UI file 'newresource.ui'
**
** Created: Thu 11. Oct 18:31:03 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWRESOURCE_H
#define UI_NEWRESOURCE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtGui/QWizard>
#include <QtGui/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_newResource
{
public:
    QWizardPage *wpResourceSource;
    QVBoxLayout *verticalLayout;
    QTabWidget *twResourceSource;
    QWidget *newResourceTab;
    QVBoxLayout *newResourceLayout;
    QLabel *noEditorExistsLabel;
    QSpacerItem *newResourceVerticalSpacer;
    QWizardPage *wpResourceName;
    QVBoxLayout *verticalLayout_2;
    QLabel *enterName;
    QHBoxLayout *horizontalLayout;
    QLabel *resName;
    QLineEdit *resourceNameLineEdit;
    QLabel *label;
    QLabel *errorMessage;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWizard *newResource)
    {
        if (newResource->objectName().isEmpty())
            newResource->setObjectName(QString::fromUtf8("newResource"));
        newResource->resize(512, 419);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        newResource->setWindowIcon(icon);
        newResource->setSizeGripEnabled(true);
        wpResourceSource = new QWizardPage();
        wpResourceSource->setObjectName(QString::fromUtf8("wpResourceSource"));
        verticalLayout = new QVBoxLayout(wpResourceSource);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        twResourceSource = new QTabWidget(wpResourceSource);
        twResourceSource->setObjectName(QString::fromUtf8("twResourceSource"));
        newResourceTab = new QWidget();
        newResourceTab->setObjectName(QString::fromUtf8("newResourceTab"));
        newResourceLayout = new QVBoxLayout(newResourceTab);
        newResourceLayout->setObjectName(QString::fromUtf8("newResourceLayout"));
        noEditorExistsLabel = new QLabel(newResourceTab);
        noEditorExistsLabel->setObjectName(QString::fromUtf8("noEditorExistsLabel"));

        newResourceLayout->addWidget(noEditorExistsLabel);

        newResourceVerticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        newResourceLayout->addItem(newResourceVerticalSpacer);

        twResourceSource->addTab(newResourceTab, QString());

        verticalLayout->addWidget(twResourceSource);

        newResource->addPage(wpResourceSource);
        wpResourceName = new QWizardPage();
        wpResourceName->setObjectName(QString::fromUtf8("wpResourceName"));
        verticalLayout_2 = new QVBoxLayout(wpResourceName);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        enterName = new QLabel(wpResourceName);
        enterName->setObjectName(QString::fromUtf8("enterName"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        enterName->setFont(font);

        verticalLayout_2->addWidget(enterName);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        resName = new QLabel(wpResourceName);
        resName->setObjectName(QString::fromUtf8("resName"));

        horizontalLayout->addWidget(resName);

        resourceNameLineEdit = new QLineEdit(wpResourceName);
        resourceNameLineEdit->setObjectName(QString::fromUtf8("resourceNameLineEdit"));

        horizontalLayout->addWidget(resourceNameLineEdit);


        verticalLayout_2->addLayout(horizontalLayout);

        label = new QLabel(wpResourceName);
        label->setObjectName(QString::fromUtf8("label"));

        verticalLayout_2->addWidget(label);

        errorMessage = new QLabel(wpResourceName);
        errorMessage->setObjectName(QString::fromUtf8("errorMessage"));
        QPalette palette;
        QBrush brush(QColor(255, 0, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        errorMessage->setPalette(palette);
        QFont font1;
        font1.setBold(true);
        font1.setWeight(75);
        errorMessage->setFont(font1);

        verticalLayout_2->addWidget(errorMessage);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        newResource->addPage(wpResourceName);

        retranslateUi(newResource);

        twResourceSource->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(newResource);
    } // setupUi

    void retranslateUi(QWizard *newResource)
    {
        newResource->setWindowTitle(QApplication::translate("newResource", "Create resource wizard", 0, QApplication::UnicodeUTF8));
        wpResourceSource->setTitle(QApplication::translate("newResource", "New RESOURCE", 0, QApplication::UnicodeUTF8));
        wpResourceSource->setSubTitle(QApplication::translate("newResource", "What type of RESOURCE to create", 0, QApplication::UnicodeUTF8));
        noEditorExistsLabel->setText(QApplication::translate("newResource", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt; font-weight:600;\">No editor exists for creating a new instance of this resource.</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt; color:#ff0000;\">Probably, your </span><span style=\" font-size:8pt; font-weight:600; color:#ff0000;\">pi|engine</span><span style=\" font-size:8pt; color:#ff0000;\"> installation is corrupted! Please </span><span style=\" font-size:8pt; font-weight:600; color:#ff0000;\">re-instal"
                        "l pi|engine</span><span style=\" font-size:8pt; color:#ff0000;\">.</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        twResourceSource->setTabText(twResourceSource->indexOf(newResourceTab), QApplication::translate("newResource", "New RESOURCE", 0, QApplication::UnicodeUTF8));
        wpResourceName->setTitle(QApplication::translate("newResource", "RESOURCE name", 0, QApplication::UnicodeUTF8));
        wpResourceName->setSubTitle(QApplication::translate("newResource", "Enter the name for this resource.", 0, QApplication::UnicodeUTF8));
        enterName->setText(QApplication::translate("newResource", "Enter the name for this resource.", 0, QApplication::UnicodeUTF8));
        resName->setText(QApplication::translate("newResource", "Resource name:", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("newResource", "The resource name must start with letter and can contain only letters, digits and underscores.\n"
"It must alse be at least 4 characters long.", 0, QApplication::UnicodeUTF8));
        errorMessage->setText(QApplication::translate("newResource", "Error message", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class newResource: public Ui_newResource {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWRESOURCE_H
