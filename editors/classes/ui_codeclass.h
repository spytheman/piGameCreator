/********************************************************************************
** Form generated from reading UI file 'codeclass.ui'
**
** Created: Fri 2. Nov 07:48:41 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODECLASS_H
#define UI_CODECLASS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDockWidget>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QSplitter>
#include <QtGui/QToolBar>
#include <QtGui/QToolBox>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_codeClass
{
public:
    QAction *actionFind;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionCut;
    QAction *actionClass_members;
    QAction *actionFunction_library;
    QAction *actionPrint;
    QAction *actionHelp;
    QAction *actionShow_hidden_symbols;
    QAction *actionShow_tab_lines;
    QAction *actionGo_to_line_number;
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_5;
    QSplitter *splitter;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QFrame *CodeEditorFrame;
    QVBoxLayout *verticalLayout_4;
    QFrame *goToLineBox;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpinBox *sbLineNumber;
    QToolButton *tbGoToLineNumber;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *tbCloseLineNumber;
    QFrame *searchBox;
    QGridLayout *gridLayout_2;
    QLineEdit *searchText;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *tbFindPrev;
    QToolButton *tbFindNext;
    QSpacerItem *horizontalSpacer_3;
    QToolButton *tbCloseSearch;
    QLabel *label_3;
    QLineEdit *replaceText;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btReplace;
    QPushButton *btReplaceAll;
    QHBoxLayout *horizontalLayout_2;
    QCheckBox *cbWholeWord;
    QCheckBox *cbCaseSensitive;
    QCheckBox *cbRegexp;
    QSpacerItem *horizontalSpacer_4;
    QLabel *label_2;
    QDockWidget *classMembersDW;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QHBoxLayout *horizontalLayout;
    QToolButton *toolButton_2;
    QSpacerItem *horizontalSpacer;
    QToolButton *toolButton;
    QToolButton *toolButton_3;
    QToolButton *toolButton_4;
    QTreeWidget *treeWidget;
    QPushButton *pushButton_3;
    QDockWidget *functionLibraryDW;
    QWidget *dockWidgetContents_2;
    QVBoxLayout *verticalLayout_3;
    QToolBox *toolBox;
    QWidget *fnLibrary;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_5;
    QSpacerItem *verticalSpacer;
    QToolBar *toolBar;

    void setupUi(QMainWindow *codeClass)
    {
        if (codeClass->objectName().isEmpty())
            codeClass->setObjectName(QString::fromUtf8("codeClass"));
        codeClass->resize(780, 466);
        actionFind = new QAction(codeClass);
        actionFind->setObjectName(QString::fromUtf8("actionFind"));
        actionFind->setCheckable(true);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/magnifier.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFind->setIcon(icon);
        actionCopy = new QAction(codeClass);
        actionCopy->setObjectName(QString::fromUtf8("actionCopy"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_copy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon1);
        actionPaste = new QAction(codeClass);
        actionPaste->setObjectName(QString::fromUtf8("actionPaste"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_paste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon2);
        actionCut = new QAction(codeClass);
        actionCut->setObjectName(QString::fromUtf8("actionCut"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/cut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon3);
        actionClass_members = new QAction(codeClass);
        actionClass_members->setObjectName(QString::fromUtf8("actionClass_members"));
        actionClass_members->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/bricks.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClass_members->setIcon(icon4);
        actionFunction_library = new QAction(codeClass);
        actionFunction_library->setObjectName(QString::fromUtf8("actionFunction_library"));
        actionFunction_library->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/book_open.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionFunction_library->setIcon(icon5);
        actionPrint = new QAction(codeClass);
        actionPrint->setObjectName(QString::fromUtf8("actionPrint"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/printer.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPrint->setIcon(icon6);
        actionHelp = new QAction(codeClass);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/help.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionHelp->setIcon(icon7);
        actionShow_hidden_symbols = new QAction(codeClass);
        actionShow_hidden_symbols->setObjectName(QString::fromUtf8("actionShow_hidden_symbols"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/resources/RES/ffficons/pilcrow.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_hidden_symbols->setIcon(icon8);
        actionShow_tab_lines = new QAction(codeClass);
        actionShow_tab_lines->setObjectName(QString::fromUtf8("actionShow_tab_lines"));
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/resources/RES/ffficons/text_padding_left.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionShow_tab_lines->setIcon(icon9);
        actionGo_to_line_number = new QAction(codeClass);
        actionGo_to_line_number->setObjectName(QString::fromUtf8("actionGo_to_line_number"));
        actionGo_to_line_number->setCheckable(true);
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_white_go.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionGo_to_line_number->setIcon(icon10);
        centralwidget = new QWidget(codeClass);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout_5 = new QVBoxLayout(centralwidget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        splitter = new QSplitter(centralwidget);
        splitter->setObjectName(QString::fromUtf8("splitter"));
        splitter->setOrientation(Qt::Vertical);
        widget = new QWidget(splitter);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        CodeEditorFrame = new QFrame(widget);
        CodeEditorFrame->setObjectName(QString::fromUtf8("CodeEditorFrame"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(CodeEditorFrame->sizePolicy().hasHeightForWidth());
        CodeEditorFrame->setSizePolicy(sizePolicy);
        CodeEditorFrame->setFrameShape(QFrame::StyledPanel);
        CodeEditorFrame->setFrameShadow(QFrame::Plain);
        verticalLayout_4 = new QVBoxLayout(CodeEditorFrame);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));

        verticalLayout->addWidget(CodeEditorFrame);

        goToLineBox = new QFrame(widget);
        goToLineBox->setObjectName(QString::fromUtf8("goToLineBox"));
        goToLineBox->setFrameShape(QFrame::Panel);
        goToLineBox->setFrameShadow(QFrame::Raised);
        goToLineBox->setProperty("Toolbar", QVariant(true));
        horizontalLayout_5 = new QHBoxLayout(goToLineBox);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(3, 0, 3, 0);
        label = new QLabel(goToLineBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_5->addWidget(label);

        sbLineNumber = new QSpinBox(goToLineBox);
        sbLineNumber->setObjectName(QString::fromUtf8("sbLineNumber"));

        horizontalLayout_5->addWidget(sbLineNumber);

        tbGoToLineNumber = new QToolButton(goToLineBox);
        tbGoToLineNumber->setObjectName(QString::fromUtf8("tbGoToLineNumber"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/resources/RES/ffficons/control_play_blue.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbGoToLineNumber->setIcon(icon11);
        tbGoToLineNumber->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tbGoToLineNumber->setAutoRaise(true);

        horizontalLayout_5->addWidget(tbGoToLineNumber);

        horizontalSpacer_2 = new QSpacerItem(403, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_2);

        tbCloseLineNumber = new QToolButton(goToLineBox);
        tbCloseLineNumber->setObjectName(QString::fromUtf8("tbCloseLineNumber"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/resources/RES/ffficons/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbCloseLineNumber->setIcon(icon12);
        tbCloseLineNumber->setAutoRaise(true);

        horizontalLayout_5->addWidget(tbCloseLineNumber);


        verticalLayout->addWidget(goToLineBox);

        searchBox = new QFrame(widget);
        searchBox->setObjectName(QString::fromUtf8("searchBox"));
        searchBox->setFrameShape(QFrame::Panel);
        searchBox->setFrameShadow(QFrame::Raised);
        searchBox->setProperty("Toolbar", QVariant(true));
        gridLayout_2 = new QGridLayout(searchBox);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setContentsMargins(3, 3, 3, 3);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        searchText = new QLineEdit(searchBox);
        searchText->setObjectName(QString::fromUtf8("searchText"));

        gridLayout_2->addWidget(searchText, 0, 1, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        tbFindPrev = new QToolButton(searchBox);
        tbFindPrev->setObjectName(QString::fromUtf8("tbFindPrev"));
        QIcon icon13;
        icon13.addFile(QString::fromUtf8(":/resources/RES/ffficons/resultset_previous.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbFindPrev->setIcon(icon13);
        tbFindPrev->setAutoRaise(true);

        horizontalLayout_4->addWidget(tbFindPrev);

        tbFindNext = new QToolButton(searchBox);
        tbFindNext->setObjectName(QString::fromUtf8("tbFindNext"));
        QIcon icon14;
        icon14.addFile(QString::fromUtf8(":/resources/RES/ffficons/resultset_next.png"), QSize(), QIcon::Normal, QIcon::Off);
        tbFindNext->setIcon(icon14);
        tbFindNext->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        tbFindNext->setAutoRaise(true);

        horizontalLayout_4->addWidget(tbFindNext);

        horizontalSpacer_3 = new QSpacerItem(40, 5, QSizePolicy::Ignored, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        tbCloseSearch = new QToolButton(searchBox);
        tbCloseSearch->setObjectName(QString::fromUtf8("tbCloseSearch"));
        tbCloseSearch->setIcon(icon12);
        tbCloseSearch->setAutoRaise(true);

        horizontalLayout_4->addWidget(tbCloseSearch);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 2, 1, 1);

        label_3 = new QLabel(searchBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_2->addWidget(label_3, 1, 0, 1, 1);

        replaceText = new QLineEdit(searchBox);
        replaceText->setObjectName(QString::fromUtf8("replaceText"));

        gridLayout_2->addWidget(replaceText, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        btReplace = new QPushButton(searchBox);
        btReplace->setObjectName(QString::fromUtf8("btReplace"));

        horizontalLayout_3->addWidget(btReplace);

        btReplaceAll = new QPushButton(searchBox);
        btReplaceAll->setObjectName(QString::fromUtf8("btReplaceAll"));

        horizontalLayout_3->addWidget(btReplaceAll);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 2, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        cbWholeWord = new QCheckBox(searchBox);
        cbWholeWord->setObjectName(QString::fromUtf8("cbWholeWord"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(cbWholeWord->sizePolicy().hasHeightForWidth());
        cbWholeWord->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(cbWholeWord);

        cbCaseSensitive = new QCheckBox(searchBox);
        cbCaseSensitive->setObjectName(QString::fromUtf8("cbCaseSensitive"));
        sizePolicy1.setHeightForWidth(cbCaseSensitive->sizePolicy().hasHeightForWidth());
        cbCaseSensitive->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(cbCaseSensitive);

        cbRegexp = new QCheckBox(searchBox);
        cbRegexp->setObjectName(QString::fromUtf8("cbRegexp"));
        sizePolicy1.setHeightForWidth(cbRegexp->sizePolicy().hasHeightForWidth());
        cbRegexp->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(cbRegexp);

        horizontalSpacer_4 = new QSpacerItem(40, 5, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_4);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 3);

        label_2 = new QLabel(searchBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 0, 1, 1);


        verticalLayout->addWidget(searchBox);

        splitter->addWidget(widget);

        verticalLayout_5->addWidget(splitter);

        codeClass->setCentralWidget(centralwidget);
        classMembersDW = new QDockWidget(codeClass);
        classMembersDW->setObjectName(QString::fromUtf8("classMembersDW"));
        classMembersDW->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents);
        verticalLayout_2->setSpacing(1);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame = new QFrame(dockWidgetContents);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::Panel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        toolButton_2 = new QToolButton(frame);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon15;
        icon15.addFile(QString::fromUtf8(":/resources/RES/ffficons/monitor.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon15);
        toolButton_2->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_2);

        horizontalSpacer = new QSpacerItem(39, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        toolButton = new QToolButton(frame);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon16;
        icon16.addFile(QString::fromUtf8(":/resources/RES/ffficons/clock.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon16);
        toolButton->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton);

        toolButton_3 = new QToolButton(frame);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon17;
        icon17.addFile(QString::fromUtf8(":/resources/RES/ffficons/sum.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon17);
        toolButton_3->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_3);

        toolButton_4 = new QToolButton(frame);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QIcon icon18;
        icon18.addFile(QString::fromUtf8(":/resources/RES/ffficons/tag_yellow.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon18);
        toolButton_4->setAutoRaise(true);

        horizontalLayout->addWidget(toolButton_4);


        verticalLayout_2->addWidget(frame);

        treeWidget = new QTreeWidget(dockWidgetContents);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(treeWidget->sizePolicy().hasHeightForWidth());
        treeWidget->setSizePolicy(sizePolicy2);

        verticalLayout_2->addWidget(treeWidget);

        pushButton_3 = new QPushButton(dockWidgetContents);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        QIcon icon19;
        icon19.addFile(QString::fromUtf8(":/resources/RES/ffficons/information.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon19);

        verticalLayout_2->addWidget(pushButton_3);

        classMembersDW->setWidget(dockWidgetContents);
        codeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), classMembersDW);
        functionLibraryDW = new QDockWidget(codeClass);
        functionLibraryDW->setObjectName(QString::fromUtf8("functionLibraryDW"));
        functionLibraryDW->setFeatures(QDockWidget::AllDockWidgetFeatures);
        dockWidgetContents_2 = new QWidget();
        dockWidgetContents_2->setObjectName(QString::fromUtf8("dockWidgetContents_2"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        toolBox = new QToolBox(dockWidgetContents_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        fnLibrary = new QWidget();
        fnLibrary->setObjectName(QString::fromUtf8("fnLibrary"));
        fnLibrary->setGeometry(QRect(0, 0, 87, 397));
        verticalLayout_6 = new QVBoxLayout(fnLibrary);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_5 = new QLabel(fnLibrary);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setText(QString::fromUtf8("To Do:\n"
"Functions library"));
        label_5->setScaledContents(false);
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        verticalLayout_6->addWidget(label_5);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_6->addItem(verticalSpacer);

        toolBox->addItem(fnLibrary, QString::fromUtf8("Functions library"));

        verticalLayout_3->addWidget(toolBox);

        functionLibraryDW->setWidget(dockWidgetContents_2);
        codeClass->addDockWidget(static_cast<Qt::DockWidgetArea>(2), functionLibraryDW);
        toolBar = new QToolBar(codeClass);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(16, 16));
        codeClass->addToolBar(Qt::TopToolBarArea, toolBar);

        toolBar->addAction(actionFind);
        toolBar->addAction(actionGo_to_line_number);
        toolBar->addSeparator();
        toolBar->addAction(actionCopy);
        toolBar->addAction(actionPaste);
        toolBar->addAction(actionCut);
        toolBar->addSeparator();
        toolBar->addAction(actionClass_members);
        toolBar->addAction(actionFunction_library);
        toolBar->addSeparator();
        toolBar->addAction(actionShow_hidden_symbols);
        toolBar->addAction(actionShow_tab_lines);
        toolBar->addSeparator();
        toolBar->addAction(actionPrint);
        toolBar->addAction(actionHelp);

        retranslateUi(codeClass);

        toolBox->setCurrentIndex(0);
        toolBox->layout()->setSpacing(0);


        QMetaObject::connectSlotsByName(codeClass);
    } // setupUi

    void retranslateUi(QMainWindow *codeClass)
    {
        codeClass->setWindowTitle(QApplication::translate("codeClass", "MainWindow", 0, QApplication::UnicodeUTF8));
        actionFind->setText(QApplication::translate("codeClass", "Find", 0, QApplication::UnicodeUTF8));
        actionCopy->setText(QApplication::translate("codeClass", "Copy", 0, QApplication::UnicodeUTF8));
        actionPaste->setText(QApplication::translate("codeClass", "Paste", 0, QApplication::UnicodeUTF8));
        actionCut->setText(QApplication::translate("codeClass", "Cut", 0, QApplication::UnicodeUTF8));
        actionClass_members->setText(QApplication::translate("codeClass", "Class members", 0, QApplication::UnicodeUTF8));
        actionFunction_library->setText(QApplication::translate("codeClass", "Function library", 0, QApplication::UnicodeUTF8));
        actionPrint->setText(QApplication::translate("codeClass", "print", 0, QApplication::UnicodeUTF8));
        actionHelp->setText(QApplication::translate("codeClass", "help", 0, QApplication::UnicodeUTF8));
        actionShow_hidden_symbols->setText(QApplication::translate("codeClass", "Show hidden symbols", 0, QApplication::UnicodeUTF8));
        actionShow_tab_lines->setText(QApplication::translate("codeClass", "Show tab lines", 0, QApplication::UnicodeUTF8));
        actionGo_to_line_number->setText(QApplication::translate("codeClass", "Go to line number", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("codeClass", "Line # ", 0, QApplication::UnicodeUTF8));
        tbGoToLineNumber->setText(QApplication::translate("codeClass", "Go", 0, QApplication::UnicodeUTF8));
        tbCloseLineNumber->setText(QApplication::translate("codeClass", "Close", 0, QApplication::UnicodeUTF8));
        tbFindPrev->setText(QApplication::translate("codeClass", "Find Previous", 0, QApplication::UnicodeUTF8));
        tbFindNext->setText(QApplication::translate("codeClass", "Find next", 0, QApplication::UnicodeUTF8));
        tbCloseSearch->setText(QApplication::translate("codeClass", "Close", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("codeClass", "Replace:", 0, QApplication::UnicodeUTF8));
        btReplace->setText(QApplication::translate("codeClass", "Replace", 0, QApplication::UnicodeUTF8));
        btReplaceAll->setText(QApplication::translate("codeClass", "Replace All", 0, QApplication::UnicodeUTF8));
        cbWholeWord->setText(QApplication::translate("codeClass", "Whole word only", 0, QApplication::UnicodeUTF8));
        cbCaseSensitive->setText(QApplication::translate("codeClass", "Case sensitive", 0, QApplication::UnicodeUTF8));
        cbRegexp->setText(QApplication::translate("codeClass", "Use RegExps", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("codeClass", "Search:", 0, QApplication::UnicodeUTF8));
        classMembersDW->setWindowTitle(QApplication::translate("codeClass", "Class members", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("codeClass", "Representation", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("codeClass", "Add event", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("codeClass", "Add function", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("codeClass", "Add variable", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("codeClass", "Class members", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("codeClass", "Information", 0, QApplication::UnicodeUTF8));
        functionLibraryDW->setWindowTitle(QApplication::translate("codeClass", "Function library", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(fnLibrary), QApplication::translate("codeClass", "Functions library", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("codeClass", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class codeClass: public Ui_codeClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODECLASS_H
