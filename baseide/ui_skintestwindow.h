/********************************************************************************
** Form generated from reading UI file 'skintestwindow.ui'
**
** Created: Fri 2. Nov 07:45:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SKINTESTWINDOW_H
#define UI_SKINTESTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCalendarWidget>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QCommandLinkButton>
#include <QtGui/QDateEdit>
#include <QtGui/QDateTimeEdit>
#include <QtGui/QDial>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QProgressBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QScrollBar>
#include <QtGui/QSlider>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QToolBox>
#include <QtGui/QToolButton>
#include <QtGui/QTreeWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SkinTestWindow
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_11;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QPushButton *ButtonWithMenu;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_2;
    QFrame *line_3;
    QRadioButton *radioButton;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_2;
    QCheckBox *TSCBE;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QCheckBox *TSCBD;
    QHBoxLayout *horizontalLayout_7;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLineEdit *lineEdit;
    QSpinBox *spinBox;
    QHBoxLayout *horizontalLayout_9;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QGridLayout *gridLayout_2;
    QTabWidget *tabWidget_3;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_10;
    QSlider *verticalSlider;
    QVBoxLayout *verticalLayout_5;
    QSlider *horizontalSlider;
    QProgressBar *progressBar;
    QWidget *tab_6;
    QWidget *tab_3;
    QCommandLinkButton *commandLinkButton;
    QPlainTextEdit *plainTextEdit;
    QToolBox *toolBox;
    QWidget *page;
    QWidget *page_2;
    QScrollBar *verticalScrollBar;
    QScrollBar *horizontalScrollBar;
    QWidget *tab_4;
    QGridLayout *gridLayout_3;
    QCalendarWidget *calendarWidget;
    QDateTimeEdit *dateTimeEdit;
    QDateEdit *dateEdit;
    QDial *dial;
    QWidget *tab;
    QVBoxLayout *verticalLayout_2;
    QTreeWidget *treeWidget;
    QWidget *tab_7;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget;
    QSpacerItem *verticalSpacer;
    QLabel *label_4;
    QVBoxLayout *verticalLayout_3;
    QListWidget *SkinsList;
    QHBoxLayout *horizontalLayout_8;
    QToolButton *toolButton_3;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButton_4;

    void setupUi(QDialog *SkinTestWindow)
    {
        if (SkinTestWindow->objectName().isEmpty())
            SkinTestWindow->setObjectName(QString::fromUtf8("SkinTestWindow"));
        SkinTestWindow->resize(518, 532);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        SkinTestWindow->setWindowIcon(icon);
        gridLayout = new QGridLayout(SkinTestWindow);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(SkinTestWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setWordWrap(true);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        line = new QFrame(SkinTestWindow);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(SkinTestWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        label_2 = new QLabel(SkinTestWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(false);

        horizontalLayout_2->addWidget(label_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_2 = new QPushButton(SkinTestWindow);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_3->addWidget(pushButton_2);

        pushButton = new QPushButton(SkinTestWindow);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);

        horizontalLayout_3->addWidget(pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(0);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        toolButton_2 = new QToolButton(SkinTestWindow);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/shield.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setAutoRaise(true);

        horizontalLayout_11->addWidget(toolButton_2);

        toolButton = new QToolButton(SkinTestWindow);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/star.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon2);
        toolButton->setPopupMode(QToolButton::MenuButtonPopup);
        toolButton->setAutoRaise(true);

        horizontalLayout_11->addWidget(toolButton);


        horizontalLayout_3->addLayout(horizontalLayout_11);

        ButtonWithMenu = new QPushButton(SkinTestWindow);
        ButtonWithMenu->setObjectName(QString::fromUtf8("ButtonWithMenu"));

        horizontalLayout_3->addWidget(ButtonWithMenu);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        radioButton_3 = new QRadioButton(SkinTestWindow);
        radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

        horizontalLayout_4->addWidget(radioButton_3);

        radioButton_2 = new QRadioButton(SkinTestWindow);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        horizontalLayout_4->addWidget(radioButton_2);

        line_3 = new QFrame(SkinTestWindow);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setFrameShape(QFrame::VLine);
        line_3->setFrameShadow(QFrame::Sunken);

        horizontalLayout_4->addWidget(line_3);

        radioButton = new QRadioButton(SkinTestWindow);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setEnabled(false);

        horizontalLayout_4->addWidget(radioButton);


        verticalLayout->addLayout(horizontalLayout_4);

        line_2 = new QFrame(SkinTestWindow);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        checkBox_3 = new QCheckBox(SkinTestWindow);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setChecked(true);

        horizontalLayout_5->addWidget(checkBox_3);

        checkBox_2 = new QCheckBox(SkinTestWindow);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));

        horizontalLayout_5->addWidget(checkBox_2);

        TSCBE = new QCheckBox(SkinTestWindow);
        TSCBE->setObjectName(QString::fromUtf8("TSCBE"));
        TSCBE->setCheckable(true);
        TSCBE->setTristate(true);

        horizontalLayout_5->addWidget(TSCBE);


        verticalLayout->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        checkBox_4 = new QCheckBox(SkinTestWindow);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setEnabled(false);
        checkBox_4->setChecked(true);

        horizontalLayout_6->addWidget(checkBox_4);

        checkBox_5 = new QCheckBox(SkinTestWindow);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setEnabled(false);

        horizontalLayout_6->addWidget(checkBox_5);

        TSCBD = new QCheckBox(SkinTestWindow);
        TSCBD->setObjectName(QString::fromUtf8("TSCBD"));
        TSCBD->setEnabled(false);
        TSCBD->setCheckable(true);
        TSCBD->setTristate(true);

        horizontalLayout_6->addWidget(TSCBD);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        comboBox_2 = new QComboBox(SkinTestWindow);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_2->sizePolicy().hasHeightForWidth());
        comboBox_2->setSizePolicy(sizePolicy);
        comboBox_2->setEditable(true);

        horizontalLayout_7->addWidget(comboBox_2);

        comboBox_3 = new QComboBox(SkinTestWindow);
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        sizePolicy.setHeightForWidth(comboBox_3->sizePolicy().hasHeightForWidth());
        comboBox_3->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(comboBox_3);

        lineEdit = new QLineEdit(SkinTestWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);

        horizontalLayout_7->addWidget(lineEdit);

        spinBox = new QSpinBox(SkinTestWindow);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(spinBox->sizePolicy().hasHeightForWidth());
        spinBox->setSizePolicy(sizePolicy1);

        horizontalLayout_7->addWidget(spinBox);


        verticalLayout->addLayout(horizontalLayout_7);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));

        verticalLayout->addLayout(horizontalLayout_9);

        tabWidget = new QTabWidget(SkinTestWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        gridLayout_2 = new QGridLayout(tab_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        tabWidget_3 = new QTabWidget(tab_2);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(tabWidget_3->sizePolicy().hasHeightForWidth());
        tabWidget_3->setSizePolicy(sizePolicy2);
        tabWidget_3->setTabPosition(QTabWidget::South);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_4 = new QVBoxLayout(tab_5);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        verticalSlider = new QSlider(tab_5);
        verticalSlider->setObjectName(QString::fromUtf8("verticalSlider"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(verticalSlider->sizePolicy().hasHeightForWidth());
        verticalSlider->setSizePolicy(sizePolicy3);
        verticalSlider->setMaximumSize(QSize(16777215, 60));
        verticalSlider->setOrientation(Qt::Vertical);

        horizontalLayout_10->addWidget(verticalSlider);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalSlider = new QSlider(tab_5);
        horizontalSlider->setObjectName(QString::fromUtf8("horizontalSlider"));
        QSizePolicy sizePolicy4(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy4);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout_5->addWidget(horizontalSlider);

        progressBar = new QProgressBar(tab_5);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setValue(50);
        progressBar->setTextVisible(false);

        verticalLayout_5->addWidget(progressBar);


        horizontalLayout_10->addLayout(verticalLayout_5);


        verticalLayout_4->addLayout(horizontalLayout_10);

        tabWidget_3->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget_3->addTab(tab_6, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tabWidget_3->addTab(tab_3, QString());

        gridLayout_2->addWidget(tabWidget_3, 0, 0, 1, 1);

        commandLinkButton = new QCommandLinkButton(tab_2);
        commandLinkButton->setObjectName(QString::fromUtf8("commandLinkButton"));
        commandLinkButton->setCheckable(true);

        gridLayout_2->addWidget(commandLinkButton, 1, 0, 1, 1);

        plainTextEdit = new QPlainTextEdit(tab_2);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy5);

        gridLayout_2->addWidget(plainTextEdit, 1, 1, 1, 1);

        toolBox = new QToolBox(tab_2);
        toolBox->setObjectName(QString::fromUtf8("toolBox"));
        QSizePolicy sizePolicy6(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(toolBox->sizePolicy().hasHeightForWidth());
        toolBox->setSizePolicy(sizePolicy6);
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        page->setGeometry(QRect(0, 0, 123, 56));
        toolBox->addItem(page, QString::fromUtf8("Page 1"));
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        page_2->setGeometry(QRect(0, 0, 123, 56));
        toolBox->addItem(page_2, QString::fromUtf8("Page 2"));

        gridLayout_2->addWidget(toolBox, 0, 1, 1, 1);

        verticalScrollBar = new QScrollBar(tab_2);
        verticalScrollBar->setObjectName(QString::fromUtf8("verticalScrollBar"));
        verticalScrollBar->setPageStep(50);
        verticalScrollBar->setOrientation(Qt::Vertical);

        gridLayout_2->addWidget(verticalScrollBar, 0, 2, 2, 1);

        horizontalScrollBar = new QScrollBar(tab_2);
        horizontalScrollBar->setObjectName(QString::fromUtf8("horizontalScrollBar"));
        horizontalScrollBar->setPageStep(50);
        horizontalScrollBar->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalScrollBar, 2, 0, 1, 2);

        tabWidget->addTab(tab_2, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        gridLayout_3 = new QGridLayout(tab_4);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        calendarWidget = new QCalendarWidget(tab_4);
        calendarWidget->setObjectName(QString::fromUtf8("calendarWidget"));

        gridLayout_3->addWidget(calendarWidget, 0, 0, 1, 1);

        dateTimeEdit = new QDateTimeEdit(tab_4);
        dateTimeEdit->setObjectName(QString::fromUtf8("dateTimeEdit"));
        dateTimeEdit->setCalendarPopup(true);

        gridLayout_3->addWidget(dateTimeEdit, 1, 0, 1, 1);

        dateEdit = new QDateEdit(tab_4);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        gridLayout_3->addWidget(dateEdit, 1, 1, 1, 1);

        dial = new QDial(tab_4);
        dial->setObjectName(QString::fromUtf8("dial"));

        gridLayout_3->addWidget(dial, 0, 1, 1, 1);

        tabWidget->addTab(tab_4, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_2 = new QVBoxLayout(tab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        treeWidget = new QTreeWidget(tab);
        new QTreeWidgetItem(treeWidget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem(treeWidget);
        new QTreeWidgetItem(__qtreewidgetitem);
        treeWidget->setObjectName(QString::fromUtf8("treeWidget"));
        treeWidget->header()->setDefaultSectionSize(100);

        verticalLayout_2->addWidget(treeWidget);

        tabWidget->addTab(tab, QString());
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        verticalLayout_6 = new QVBoxLayout(tab_7);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        tableWidget = new QTableWidget(tab_7);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        if (tableWidget->rowCount() < 6)
            tableWidget->setRowCount(6);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem11);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/emoticon_surprised.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        __qtablewidgetitem12->setIcon(icon3);
        tableWidget->setItem(0, 0, __qtablewidgetitem12);
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/cursor.png"), QSize(), QIcon::Normal, QIcon::Off);
        QFont font;
        font.setFamily(QString::fromUtf8("Courier New"));
        font.setBold(true);
        font.setWeight(75);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        __qtablewidgetitem13->setFont(font);
        __qtablewidgetitem13->setIcon(icon4);
        tableWidget->setItem(0, 1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setItem(0, 2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setItem(0, 3, __qtablewidgetitem15);
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/eye.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        __qtablewidgetitem16->setIcon(icon5);
        tableWidget->setItem(1, 0, __qtablewidgetitem16);
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_excel.png"), QSize(), QIcon::Normal, QIcon::Off);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        __qtablewidgetitem17->setIcon(icon6);
        tableWidget->setItem(1, 1, __qtablewidgetitem17);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setAutoScrollMargin(0);
        tableWidget->setIconSize(QSize(16, 16));
        tableWidget->setShowGrid(true);
        tableWidget->setGridStyle(Qt::SolidLine);

        verticalLayout_6->addWidget(tableWidget);

        tabWidget->addTab(tab_7, QString());

        verticalLayout->addWidget(tabWidget);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        label_4 = new QLabel(SkinTestWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout->addWidget(label_4);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        SkinsList = new QListWidget(SkinTestWindow);
        SkinsList->setObjectName(QString::fromUtf8("SkinsList"));
        QSizePolicy sizePolicy7(QSizePolicy::Fixed, QSizePolicy::Expanding);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(SkinsList->sizePolicy().hasHeightForWidth());
        SkinsList->setSizePolicy(sizePolicy7);
        SkinsList->setMaximumSize(QSize(140, 16777215));

        verticalLayout_3->addWidget(SkinsList);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        toolButton_3 = new QToolButton(SkinTestWindow);
        toolButton_3->setObjectName(QString::fromUtf8("toolButton_3"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/arrow_refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_3->setIcon(icon7);
        toolButton_3->setAutoRaise(true);

        horizontalLayout_8->addWidget(toolButton_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);

        pushButton_4 = new QPushButton(SkinTestWindow);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        sizePolicy1.setHeightForWidth(pushButton_4->sizePolicy().hasHeightForWidth());
        pushButton_4->setSizePolicy(sizePolicy1);
        pushButton_4->setDefault(true);

        horizontalLayout_8->addWidget(pushButton_4);


        verticalLayout_3->addLayout(horizontalLayout_8);


        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(SkinTestWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        toolBox->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SkinTestWindow);
    } // setupUi

    void retranslateUi(QDialog *SkinTestWindow)
    {
        SkinTestWindow->setWindowTitle(QApplication::translate("SkinTestWindow", "Theme editor", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SkinTestWindow", "Here you can test all the generic skins. When you edit the skin file and save it, if it is the selected skin, it will be instantly reloaded into the entire IDE!", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("SkinTestWindow", "Enabled Text label", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("SkinTestWindow", "Disabled Text label", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        pushButton_2->setToolTip(QApplication::translate("SkinTestWindow", "QPushButton", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        pushButton_2->setText(QApplication::translate("SkinTestWindow", "Enabled button", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("SkinTestWindow", "Disabled button", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("SkinTestWindow", "...", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("SkinTestWindow", "...", 0, QApplication::UnicodeUTF8));
        ButtonWithMenu->setText(QApplication::translate("SkinTestWindow", "With menu", 0, QApplication::UnicodeUTF8));
        radioButton_3->setText(QApplication::translate("SkinTestWindow", "Radio button", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("SkinTestWindow", "Radio button 2", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("SkinTestWindow", "Disabled", 0, QApplication::UnicodeUTF8));
        checkBox_3->setText(QApplication::translate("SkinTestWindow", "Checked", 0, QApplication::UnicodeUTF8));
        checkBox_2->setText(QApplication::translate("SkinTestWindow", "Unchecked", 0, QApplication::UnicodeUTF8));
        TSCBE->setText(QApplication::translate("SkinTestWindow", "Tristate", 0, QApplication::UnicodeUTF8));
        checkBox_4->setText(QApplication::translate("SkinTestWindow", "Checked", 0, QApplication::UnicodeUTF8));
        checkBox_5->setText(QApplication::translate("SkinTestWindow", "Unchecked", 0, QApplication::UnicodeUTF8));
        TSCBD->setText(QApplication::translate("SkinTestWindow", "Tristate", 0, QApplication::UnicodeUTF8));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("SkinTestWindow", "Editable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SkinTestWindow", "Item 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SkinTestWindow", "Item 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SkinTestWindow", "Item 3", 0, QApplication::UnicodeUTF8)
        );
        comboBox_3->clear();
        comboBox_3->insertItems(0, QStringList()
         << QApplication::translate("SkinTestWindow", "Selectable", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SkinTestWindow", "Item 1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SkinTestWindow", "Item 2", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("SkinTestWindow", "Item 3", 0, QApplication::UnicodeUTF8)
        );
        lineEdit->setText(QApplication::translate("SkinTestWindow", "Text box", 0, QApplication::UnicodeUTF8));
        progressBar->setFormat(QApplication::translate("SkinTestWindow", "%p %", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_5), QApplication::translate("SkinTestWindow", "Tab 1", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_6), QApplication::translate("SkinTestWindow", "Tab 2", 0, QApplication::UnicodeUTF8));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_3), QApplication::translate("SkinTestWindow", "Tab 3", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setText(QApplication::translate("SkinTestWindow", "Command Link", 0, QApplication::UnicodeUTF8));
        commandLinkButton->setDescription(QApplication::translate("SkinTestWindow", "Description of it", 0, QApplication::UnicodeUTF8));
        plainTextEdit->setPlainText(QApplication::translate("SkinTestWindow", "Plain text Edit", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page), QApplication::translate("SkinTestWindow", "Page 1", 0, QApplication::UnicodeUTF8));
        toolBox->setItemText(toolBox->indexOf(page_2), QApplication::translate("SkinTestWindow", "Page 2", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("SkinTestWindow", "Other", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("SkinTestWindow", "Stuff", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(1, QApplication::translate("SkinTestWindow", "Column 2", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem->setText(0, QApplication::translate("SkinTestWindow", "Column 1", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = treeWidget->isSortingEnabled();
        treeWidget->setSortingEnabled(false);
        QTreeWidgetItem *___qtreewidgetitem1 = treeWidget->topLevelItem(0);
        ___qtreewidgetitem1->setText(1, QApplication::translate("SkinTestWindow", "TreeWidget", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem1->setText(0, QApplication::translate("SkinTestWindow", "Item 1", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem2 = treeWidget->topLevelItem(1);
        ___qtreewidgetitem2->setText(1, QApplication::translate("SkinTestWindow", "Description", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem2->setText(0, QApplication::translate("SkinTestWindow", "Item 2", 0, QApplication::UnicodeUTF8));
        QTreeWidgetItem *___qtreewidgetitem3 = ___qtreewidgetitem2->child(0);
        ___qtreewidgetitem3->setText(1, QApplication::translate("SkinTestWindow", "Desc", 0, QApplication::UnicodeUTF8));
        ___qtreewidgetitem3->setText(0, QApplication::translate("SkinTestWindow", "Subitem", 0, QApplication::UnicodeUTF8));
        treeWidget->setSortingEnabled(__sortingEnabled);

        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("SkinTestWindow", "Tree Widget", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("SkinTestWindow", "1", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("SkinTestWindow", "2", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("SkinTestWindow", "3", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("SkinTestWindow", "4", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("SkinTestWindow", "5", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("SkinTestWindow", "6", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem6->setText(QApplication::translate("SkinTestWindow", "A", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem7->setText(QApplication::translate("SkinTestWindow", "B", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem8->setText(QApplication::translate("SkinTestWindow", "C", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem9->setText(QApplication::translate("SkinTestWindow", "D", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem10->setText(QApplication::translate("SkinTestWindow", "E", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem11->setText(QApplication::translate("SkinTestWindow", "F", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled1 = tableWidget->isSortingEnabled();
        tableWidget->setSortingEnabled(false);
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->item(0, 0);
        ___qtablewidgetitem12->setText(QApplication::translate("SkinTestWindow", "Isn't", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->item(0, 1);
        ___qtablewidgetitem13->setText(QApplication::translate("SkinTestWindow", "this", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->item(1, 0);
        ___qtablewidgetitem14->setText(QApplication::translate("SkinTestWindow", "looks", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->item(1, 1);
        ___qtablewidgetitem15->setText(QApplication::translate("SkinTestWindow", "Excelish?", 0, QApplication::UnicodeUTF8));
        tableWidget->setSortingEnabled(__sortingEnabled1);

        tabWidget->setTabText(tabWidget->indexOf(tab_7), QApplication::translate("SkinTestWindow", "Table", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("SkinTestWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\342\200\242 For </span><span style=\" font-size:8pt; font-weight:600;\">TreeView</span><span style=\" font-size:8pt;\"> look at the </span><span style=\" font-size:8pt; font-style:italic;\">Project Tree</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\342\200\242 For </span><span style=\" font-size:8pt; font-weight:600;\">ListWidget</span><span style=\" font-size:8pt;\"> look at </span><span style=\" fon"
                        "t-size:8pt; font-style:italic;\">the right</span><span style=\" font-size:8pt;\"> \342\207\222</span></p>\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:8pt;\">\342\200\242 For </span><span style=\" font-size:8pt; font-weight:600;\">Toolbars</span><span style=\" font-size:8pt;\"> and </span><span style=\" font-size:8pt; font-weight:600;\">Menus</span><span style=\" font-size:8pt;\"> look at the </span><span style=\" font-size:8pt; font-style:italic;\">Main window</span></p></body></html>", 0, QApplication::UnicodeUTF8));
        toolButton_3->setText(QApplication::translate("SkinTestWindow", "...", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("SkinTestWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SkinTestWindow: public Ui_SkinTestWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SKINTESTWINDOW_H
