/********************************************************************************
** Form generated from reading UI file 'newprojectwizard.ui'
**
** Created: Sun 21. Oct 17:32:03 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTWIZARD_H
#define UI_NEWPROJECTWIZARD_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QSpacerItem>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>
#include <QtGui/QWizard>
#include <QtGui/QWizardPage>

QT_BEGIN_NAMESPACE

class Ui_newProjectWizard
{
public:
    QWizardPage *wpProjectTemplate;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QSpacerItem *HORIZONTAL_HINT;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QLabel *projectType;
    QLabel *projectDescription;
    QFrame *line;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_6;
    QFrame *line_3;
    QLabel *label_4;
    QPlainTextEdit *projectDescTextEdit;
    QLabel *label_7;
    QFrame *line_2;
    QLabel *label_8;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QToolButton *browseButton;
    QLabel *dirSeparatorLabel;
    QLineEdit *projectdirname;
    QHBoxLayout *horizontalLayout_3;
    QToolButton *toolButton;
    QLineEdit *projectTitleLineEdit;
    QLabel *label_5;
    QLabel *label_9;
    QLineEdit *mainClassName;
    QWizardPage *wpProjectTargets;
    QGridLayout *gridLayout;

    void setupUi(QWizard *newProjectWizard)
    {
        if (newProjectWizard->objectName().isEmpty())
            newProjectWizard->setObjectName(QString::fromUtf8("newProjectWizard"));
        newProjectWizard->resize(561, 451);
        newProjectWizard->setWizardStyle(QWizard::AeroStyle);
        wpProjectTemplate = new QWizardPage();
        wpProjectTemplate->setObjectName(QString::fromUtf8("wpProjectTemplate"));
        horizontalLayout = new QHBoxLayout(wpProjectTemplate);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        treeWidget = new QTreeWidget(wpProjectTemplate);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder_page_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/2d.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/3d.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/25d.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/group.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder_lightbulb.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder_user.png"), QSize(), QIcon::Normal, QIcon::Off);
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder_table.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem->setFont(0, font);
        __qtreewidgetitem->setIcon(0, icon);
        QTreeWidgetItem *__qtreewidgetitem1 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem1->setIcon(0, icon1);
        QTreeWidgetItem *__qtreewidgetitem2 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem2->setIcon(0, icon2);
        QTreeWidgetItem *__qtreewidgetitem3 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem3->setIcon(0, icon3);
        QTreeWidgetItem *__qtreewidgetitem4 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem4->setIcon(0, icon4);
        QTreeWidgetItem *__qtreewidgetitem5 = new QTreeWidgetItem(__qtreewidgetitem);
        __qtreewidgetitem5->setIcon(0, icon5);
        QTreeWidgetItem *__qtreewidgetitem6 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem6->setFont(0, font);
        __qtreewidgetitem6->setIcon(0, icon6);
        QTreeWidgetItem *__qtreewidgetitem7 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem7->setFont(0, font);
        __qtreewidgetitem7->setIcon(0, icon7);
        QTreeWidgetItem *__qtreewidgetitem8 = new QTreeWidgetItem(treeWidget);
        __qtreewidgetitem8->setFont(0, font);
        __qtreewidgetitem8->setIcon(0, icon8);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(treeWidget);

        HORIZONTAL_HINT = new QSpacerItem(160, 0, QSizePolicy::Minimum, QSizePolicy::Ignored);

        verticalLayout_2->addItem(HORIZONTAL_HINT);


        horizontalLayout->addLayout(verticalLayout_2);

        widget = new QWidget(wpProjectTemplate);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        projectType = new QLabel(widget);
        projectType->setObjectName(QString::fromUtf8("projectType"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(projectType->sizePolicy().hasHeightForWidth());
        projectType->setSizePolicy(sizePolicy2);
        QFont font1;
        font1.setPointSize(11);
        font1.setBold(true);
        font1.setWeight(75);
        projectType->setFont(font1);

        verticalLayout_3->addWidget(projectType);

        projectDescription = new QLabel(widget);
        projectDescription->setObjectName(QString::fromUtf8("projectDescription"));
        sizePolicy2.setHeightForWidth(projectDescription->sizePolicy().hasHeightForWidth());
        projectDescription->setSizePolicy(sizePolicy2);
        projectDescription->setWordWrap(true);

        verticalLayout_3->addWidget(projectDescription);

        line = new QFrame(widget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_3 = new QLabel(widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_3);

        label_6 = new QLabel(widget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        QFont font2;
        font2.setItalic(true);
        label_6->setFont(font2);
        label_6->setWordWrap(true);

        formLayout->setWidget(1, QFormLayout::SpanningRole, label_6);

        line_3 = new QFrame(widget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(4, QFormLayout::SpanningRole, line_3);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setFont(font);

        formLayout->setWidget(5, QFormLayout::SpanningRole, label_4);

        projectDescTextEdit = new QPlainTextEdit(widget);
        projectDescTextEdit->setObjectName(QString::fromUtf8("projectDescTextEdit"));

        formLayout->setWidget(6, QFormLayout::SpanningRole, projectDescTextEdit);

        label_7 = new QLabel(widget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setFont(font2);
        label_7->setWordWrap(true);

        formLayout->setWidget(7, QFormLayout::SpanningRole, label_7);

        line_2 = new QFrame(widget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        formLayout->setWidget(8, QFormLayout::SpanningRole, line_2);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        formLayout->setWidget(9, QFormLayout::LabelRole, label_8);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font2);

        formLayout->setWidget(9, QFormLayout::FieldRole, label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        browseButton = new QToolButton(widget);
        browseButton->setObjectName(QString::fromUtf8("browseButton"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        browseButton->setIcon(icon9);
        browseButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        browseButton->setAutoRaise(false);

        horizontalLayout_2->addWidget(browseButton);

        dirSeparatorLabel = new QLabel(widget);
        dirSeparatorLabel->setObjectName(QString::fromUtf8("dirSeparatorLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dirSeparatorLabel->sizePolicy().hasHeightForWidth());
        dirSeparatorLabel->setSizePolicy(sizePolicy3);

        horizontalLayout_2->addWidget(dirSeparatorLabel);

        projectdirname = new QLineEdit(widget);
        projectdirname->setObjectName(QString::fromUtf8("projectdirname"));

        horizontalLayout_2->addWidget(projectdirname);


        formLayout->setLayout(10, QFormLayout::SpanningRole, horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        toolButton = new QToolButton(widget);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        toolButton->setIcon(icon1);
        toolButton->setAutoRaise(true);

        horizontalLayout_3->addWidget(toolButton);

        projectTitleLineEdit = new QLineEdit(widget);
        projectTitleLineEdit->setObjectName(QString::fromUtf8("projectTitleLineEdit"));

        horizontalLayout_3->addWidget(projectTitleLineEdit);


        formLayout->setLayout(0, QFormLayout::FieldRole, horizontalLayout_3);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_5);

        label_9 = new QLabel(widget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setFont(font2);
        label_9->setWordWrap(true);

        formLayout->setWidget(3, QFormLayout::SpanningRole, label_9);

        mainClassName = new QLineEdit(widget);
        mainClassName->setObjectName(QString::fromUtf8("mainClassName"));

        formLayout->setWidget(2, QFormLayout::FieldRole, mainClassName);


        verticalLayout_3->addLayout(formLayout);


        horizontalLayout->addWidget(widget);

        newProjectWizard->addPage(wpProjectTemplate);
        wpProjectTargets = new QWizardPage();
        wpProjectTargets->setObjectName(QString::fromUtf8("wpProjectTargets"));
        gridLayout = new QGridLayout(wpProjectTargets);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        newProjectWizard->addPage(wpProjectTargets);

        retranslateUi(newProjectWizard);

        QMetaObject::connectSlotsByName(newProjectWizard);
    } // setupUi

    void retranslateUi(QWizard *newProjectWizard)
    {
        newProjectWizard->setWindowTitle(QApplication::translate("newProjectWizard", "Wizard", 0, QApplication::UnicodeUTF8));
        wpProjectTemplate->setTitle(QApplication::translate("newProjectWizard", "New project", 0, QApplication::UnicodeUTF8));
        wpProjectTemplate->setSubTitle(QApplication::translate("newProjectWizard", "Select the type of the project to create", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("newProjectWizard", "Project template", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(0, QApplication::translate("newProjectWizard", "New projects", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = ___qtreewidgetitem1->child(0);
        ___qtreewidgetitem2->setText(0, QApplication::translate("newProjectWizard", "Empty project", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ___qtreewidgetitem2->setWhatsThis(0, QApplication::translate("newProjectWizard", "A totally empty project with no classes.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem1->child(1);
        ___qtreewidgetitem3->setText(0, QApplication::translate("newProjectWizard", "2D game", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ___qtreewidgetitem3->setWhatsThis(0, QApplication::translate("newProjectWizard", "A project pre-set for two-dimensional games and most platforms.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        QTreeWidgetItem *___qtreewidgetitem4 = ___qtreewidgetitem1->child(2);
        ___qtreewidgetitem4->setText(0, QApplication::translate("newProjectWizard", "3D game", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ___qtreewidgetitem4->setWhatsThis(0, QApplication::translate("newProjectWizard", "A project pre-set for three-dimensional games, only supports native desktop applications.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        QTreeWidgetItem *___qtreewidgetitem5 = ___qtreewidgetitem1->child(3);
        ___qtreewidgetitem5->setText(0, QApplication::translate("newProjectWizard", "2,5D game", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ___qtreewidgetitem5->setWhatsThis(0, QApplication::translate("newProjectWizard", "A project pre-set for games with two-dimensional gameplay and optional 3D graphics.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        QTreeWidgetItem *___qtreewidgetitem6 = ___qtreewidgetitem1->child(4);
        ___qtreewidgetitem6->setText(0, QApplication::translate("newProjectWizard", "Social game", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_WHATSTHIS
        ___qtreewidgetitem6->setWhatsThis(0, QApplication::translate("newProjectWizard", "A project pre-set for making social games for Facebook and Google Plus. This project utilizes the Web Server Foundation API for providing online services.", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_WHATSTHIS
        QTreeWidgetItem *___qtreewidgetitem7 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem7->setText(0, QApplication::translate("newProjectWizard", "Sample projects", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem8 = treeWidget->topLevelItem(2);
        ___qtreewidgetitem8->setText(0, QApplication::translate("newProjectWizard", "User templates", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem9 = treeWidget->topLevelItem(3);
        ___qtreewidgetitem9->setText(0, QApplication::translate("newProjectWizard", "Recent projects", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled);

        projectType->setText(QApplication::translate("newProjectWizard", "Project Type", 0, QApplication::UnicodeUTF8));
        projectDescription->setText(QApplication::translate("newProjectWizard", "Project description", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("newProjectWizard", "Project title:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("newProjectWizard", "The title of the project, e.g. the name of your game. It can be easily changed afterwards.", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("newProjectWizard", "Project description", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("newProjectWizard", "Can be filled later, of course", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("newProjectWizard", "Create in:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("newProjectWizard", "Select base folder and type project's own folder name", 0, QApplication::UnicodeUTF8));
        browseButton->setText(QApplication::translate("newProjectWizard", "Browse", 0, QApplication::UnicodeUTF8));
        dirSeparatorLabel->setText(QApplication::translate("newProjectWizard", "DIR_SEP", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("newProjectWizard", "Icon", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("newProjectWizard", "Main class:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("newProjectWizard", "Type the name of the main class. Typing more than one name here will create more than one classes.", 0, QApplication::UnicodeUTF8));
        mainClassName->setText(QApplication::translate("newProjectWizard", "Main", 0, QApplication::UnicodeUTF8));
        wpProjectTargets->setTitle(QApplication::translate("newProjectWizard", "Targets and platforms", 0, QApplication::UnicodeUTF8));
        wpProjectTargets->setSubTitle(QApplication::translate("newProjectWizard", "Define the targets and platforms for this project.", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class newProjectWizard: public Ui_newProjectWizard {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTWIZARD_H
