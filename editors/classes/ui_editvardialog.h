/********************************************************************************
** Form generated from reading UI file 'editvardialog.ui'
**
** Created: Thu 11. Oct 18:33:26 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDITVARDIALOG_H
#define UI_EDITVARDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QDoubleSpinBox>
#include <QtGui/QFrame>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStackedWidget>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EditVarDialog
{
public:
    QVBoxLayout *verticalLayout_3;
    QGridLayout *gridLayout_2;
    QLabel *varNameLabel;
    QLabel *varTypeLabel;
    QLineEdit *varName;
    QComboBox *varType;
    QGroupBox *PropertyTypeGB;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *menuWithChoices;
    QLabel *InitValLabel;
    QHBoxLayout *horizontalLayout_9;
    QStackedWidget *PageWidget;
    QWidget *IntegerValue;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_10;
    QSpinBox *IntegerSpinBox;
    QWidget *RealValue;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_11;
    QDoubleSpinBox *realSpinBox;
    QWidget *TextBoxPage;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_12;
    QLineEdit *StringBox;
    QWidget *BooleanValue;
    QVBoxLayout *verticalLayout_4;
    QCheckBox *BoolBox;
    QWidget *PointBoxPage;
    QHBoxLayout *horizontalLayout;
    QLabel *label_4;
    QDoubleSpinBox *p2x;
    QLabel *label_5;
    QDoubleSpinBox *p2y;
    QWidget *point3D;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_6;
    QDoubleSpinBox *p3x;
    QLabel *label_7;
    QDoubleSpinBox *p3y;
    QLabel *label_8;
    QDoubleSpinBox *p3z;
    QWidget *Color;
    QHBoxLayout *horizontalLayout_5;
    QToolButton *SetColorToolButton;
    QFrame *ColorFrame;
    QWidget *FunctionPage;
    QHBoxLayout *horizontalLayout_8;
    QLabel *FunctionLabel;
    QToolButton *WriteFunctionButton;
    QToolButton *SelectFunctionButton;
    QWidget *Resource;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ResName_label;
    QToolButton *NullresourceButton;
    QToolButton *SelectResourceButton;
    QToolButton *AddToArrayButton;
    QToolButton *DelFromArray;
    QListWidget *ArrayList;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer;
    QPushButton *OKbutton;
    QPushButton *CancelButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *EditVarDialog)
    {
        if (EditVarDialog->objectName().isEmpty())
            EditVarDialog->setObjectName(QString::fromUtf8("EditVarDialog"));
        EditVarDialog->resize(327, 392);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/add.png"), QSize(), QIcon::Normal, QIcon::Off);
        EditVarDialog->setWindowIcon(icon);
        verticalLayout_3 = new QVBoxLayout(EditVarDialog);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(-1, -1, -1, 9);
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        varNameLabel = new QLabel(EditVarDialog);
        varNameLabel->setObjectName(QString::fromUtf8("varNameLabel"));

        gridLayout_2->addWidget(varNameLabel, 0, 0, 1, 1);

        varTypeLabel = new QLabel(EditVarDialog);
        varTypeLabel->setObjectName(QString::fromUtf8("varTypeLabel"));

        gridLayout_2->addWidget(varTypeLabel, 1, 0, 1, 1);

        varName = new QLineEdit(EditVarDialog);
        varName->setObjectName(QString::fromUtf8("varName"));

        gridLayout_2->addWidget(varName, 0, 1, 1, 1);

        varType = new QComboBox(EditVarDialog);
        varType->setObjectName(QString::fromUtf8("varType"));

        gridLayout_2->addWidget(varType, 1, 1, 1, 1);


        verticalLayout_3->addLayout(gridLayout_2);

        PropertyTypeGB = new QGroupBox(EditVarDialog);
        PropertyTypeGB->setObjectName(QString::fromUtf8("PropertyTypeGB"));
        verticalLayout_2 = new QVBoxLayout(PropertyTypeGB);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButton = new QRadioButton(PropertyTypeGB);
        radioButton->setObjectName(QString::fromUtf8("radioButton"));
        radioButton->setChecked(true);

        verticalLayout_2->addWidget(radioButton);

        radioButton_2 = new QRadioButton(PropertyTypeGB);
        radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

        verticalLayout_2->addWidget(radioButton_2);

        menuWithChoices = new QRadioButton(PropertyTypeGB);
        menuWithChoices->setObjectName(QString::fromUtf8("menuWithChoices"));

        verticalLayout_2->addWidget(menuWithChoices);


        verticalLayout_3->addWidget(PropertyTypeGB);

        InitValLabel = new QLabel(EditVarDialog);
        InitValLabel->setObjectName(QString::fromUtf8("InitValLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(InitValLabel->sizePolicy().hasHeightForWidth());
        InitValLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setBold(true);
        font.setWeight(75);
        InitValLabel->setFont(font);

        verticalLayout_3->addWidget(InitValLabel);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(0);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        PageWidget = new QStackedWidget(EditVarDialog);
        PageWidget->setObjectName(QString::fromUtf8("PageWidget"));
        sizePolicy.setHeightForWidth(PageWidget->sizePolicy().hasHeightForWidth());
        PageWidget->setSizePolicy(sizePolicy);
        IntegerValue = new QWidget();
        IntegerValue->setObjectName(QString::fromUtf8("IntegerValue"));
        horizontalLayout_3 = new QHBoxLayout(IntegerValue);
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_10 = new QLabel(IntegerValue);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_10->sizePolicy().hasHeightForWidth());
        label_10->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(label_10);

        IntegerSpinBox = new QSpinBox(IntegerValue);
        IntegerSpinBox->setObjectName(QString::fromUtf8("IntegerSpinBox"));
        IntegerSpinBox->setMinimum(-999999999);
        IntegerSpinBox->setMaximum(999999999);

        horizontalLayout_3->addWidget(IntegerSpinBox);

        PageWidget->addWidget(IntegerValue);
        RealValue = new QWidget();
        RealValue->setObjectName(QString::fromUtf8("RealValue"));
        horizontalLayout_4 = new QHBoxLayout(RealValue);
        horizontalLayout_4->setSpacing(3);
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_11 = new QLabel(RealValue);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        sizePolicy1.setHeightForWidth(label_11->sizePolicy().hasHeightForWidth());
        label_11->setSizePolicy(sizePolicy1);

        horizontalLayout_4->addWidget(label_11);

        realSpinBox = new QDoubleSpinBox(RealValue);
        realSpinBox->setObjectName(QString::fromUtf8("realSpinBox"));
        realSpinBox->setDecimals(6);
        realSpinBox->setMinimum(-1e+09);
        realSpinBox->setMaximum(1e+09);

        horizontalLayout_4->addWidget(realSpinBox);

        PageWidget->addWidget(RealValue);
        TextBoxPage = new QWidget();
        TextBoxPage->setObjectName(QString::fromUtf8("TextBoxPage"));
        horizontalLayout_7 = new QHBoxLayout(TextBoxPage);
        horizontalLayout_7->setSpacing(3);
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_12 = new QLabel(TextBoxPage);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_7->addWidget(label_12);

        StringBox = new QLineEdit(TextBoxPage);
        StringBox->setObjectName(QString::fromUtf8("StringBox"));

        horizontalLayout_7->addWidget(StringBox);

        PageWidget->addWidget(TextBoxPage);
        BooleanValue = new QWidget();
        BooleanValue->setObjectName(QString::fromUtf8("BooleanValue"));
        verticalLayout_4 = new QVBoxLayout(BooleanValue);
        verticalLayout_4->setSpacing(3);
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        BoolBox = new QCheckBox(BooleanValue);
        BoolBox->setObjectName(QString::fromUtf8("BoolBox"));

        verticalLayout_4->addWidget(BoolBox);

        PageWidget->addWidget(BooleanValue);
        PointBoxPage = new QWidget();
        PointBoxPage->setObjectName(QString::fromUtf8("PointBoxPage"));
        horizontalLayout = new QHBoxLayout(PointBoxPage);
        horizontalLayout->setSpacing(3);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_4 = new QLabel(PointBoxPage);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy1.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_4);

        p2x = new QDoubleSpinBox(PointBoxPage);
        p2x->setObjectName(QString::fromUtf8("p2x"));
        p2x->setMinimum(-1e+09);
        p2x->setMaximum(1e+09);

        horizontalLayout->addWidget(p2x);

        label_5 = new QLabel(PointBoxPage);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        sizePolicy1.setHeightForWidth(label_5->sizePolicy().hasHeightForWidth());
        label_5->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(label_5);

        p2y = new QDoubleSpinBox(PointBoxPage);
        p2y->setObjectName(QString::fromUtf8("p2y"));

        horizontalLayout->addWidget(p2y);

        PageWidget->addWidget(PointBoxPage);
        point3D = new QWidget();
        point3D->setObjectName(QString::fromUtf8("point3D"));
        horizontalLayout_2 = new QHBoxLayout(point3D);
        horizontalLayout_2->setSpacing(3);
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_6 = new QLabel(point3D);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        sizePolicy1.setHeightForWidth(label_6->sizePolicy().hasHeightForWidth());
        label_6->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_6);

        p3x = new QDoubleSpinBox(point3D);
        p3x->setObjectName(QString::fromUtf8("p3x"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(p3x->sizePolicy().hasHeightForWidth());
        p3x->setSizePolicy(sizePolicy2);
        p3x->setMinimum(-1e+09);
        p3x->setMaximum(1e+09);

        horizontalLayout_2->addWidget(p3x);

        label_7 = new QLabel(point3D);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy1.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_7);

        p3y = new QDoubleSpinBox(point3D);
        p3y->setObjectName(QString::fromUtf8("p3y"));
        sizePolicy2.setHeightForWidth(p3y->sizePolicy().hasHeightForWidth());
        p3y->setSizePolicy(sizePolicy2);
        p3y->setMinimum(-1e+09);
        p3y->setMaximum(1e+09);

        horizontalLayout_2->addWidget(p3y);

        label_8 = new QLabel(point3D);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_8);

        p3z = new QDoubleSpinBox(point3D);
        p3z->setObjectName(QString::fromUtf8("p3z"));
        sizePolicy2.setHeightForWidth(p3z->sizePolicy().hasHeightForWidth());
        p3z->setSizePolicy(sizePolicy2);
        p3z->setMinimum(-1e+09);
        p3z->setMaximum(1e+09);

        horizontalLayout_2->addWidget(p3z);

        PageWidget->addWidget(point3D);
        Color = new QWidget();
        Color->setObjectName(QString::fromUtf8("Color"));
        horizontalLayout_5 = new QHBoxLayout(Color);
        horizontalLayout_5->setSpacing(3);
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        SetColorToolButton = new QToolButton(Color);
        SetColorToolButton->setObjectName(QString::fromUtf8("SetColorToolButton"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/palette.png"), QSize(), QIcon::Normal, QIcon::Off);
        SetColorToolButton->setIcon(icon1);
        SetColorToolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_5->addWidget(SetColorToolButton);

        ColorFrame = new QFrame(Color);
        ColorFrame->setObjectName(QString::fromUtf8("ColorFrame"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ColorFrame->sizePolicy().hasHeightForWidth());
        ColorFrame->setSizePolicy(sizePolicy3);
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        palette.setBrush(QPalette::Active, QPalette::Window, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush);
        ColorFrame->setPalette(palette);
        ColorFrame->setAutoFillBackground(true);
        ColorFrame->setFrameShape(QFrame::Panel);
        ColorFrame->setFrameShadow(QFrame::Sunken);

        horizontalLayout_5->addWidget(ColorFrame);

        PageWidget->addWidget(Color);
        FunctionPage = new QWidget();
        FunctionPage->setObjectName(QString::fromUtf8("FunctionPage"));
        horizontalLayout_8 = new QHBoxLayout(FunctionPage);
        horizontalLayout_8->setSpacing(3);
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        FunctionLabel = new QLabel(FunctionPage);
        FunctionLabel->setObjectName(QString::fromUtf8("FunctionLabel"));
        sizePolicy3.setHeightForWidth(FunctionLabel->sizePolicy().hasHeightForWidth());
        FunctionLabel->setSizePolicy(sizePolicy3);

        horizontalLayout_8->addWidget(FunctionLabel);

        WriteFunctionButton = new QToolButton(FunctionPage);
        WriteFunctionButton->setObjectName(QString::fromUtf8("WriteFunctionButton"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/page_edit.png"), QSize(), QIcon::Normal, QIcon::Off);
        WriteFunctionButton->setIcon(icon2);
        WriteFunctionButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_8->addWidget(WriteFunctionButton);

        SelectFunctionButton = new QToolButton(FunctionPage);
        SelectFunctionButton->setObjectName(QString::fromUtf8("SelectFunctionButton"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/resources/RES/ffficons/folder.png"), QSize(), QIcon::Normal, QIcon::Off);
        SelectFunctionButton->setIcon(icon3);
        SelectFunctionButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_8->addWidget(SelectFunctionButton);

        PageWidget->addWidget(FunctionPage);
        Resource = new QWidget();
        Resource->setObjectName(QString::fromUtf8("Resource"));
        horizontalLayout_6 = new QHBoxLayout(Resource);
        horizontalLayout_6->setSpacing(3);
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        ResName_label = new QLabel(Resource);
        ResName_label->setObjectName(QString::fromUtf8("ResName_label"));

        horizontalLayout_6->addWidget(ResName_label);

        NullresourceButton = new QToolButton(Resource);
        NullresourceButton->setObjectName(QString::fromUtf8("NullresourceButton"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        NullresourceButton->setIcon(icon4);
        NullresourceButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_6->addWidget(NullresourceButton);

        SelectResourceButton = new QToolButton(Resource);
        SelectResourceButton->setObjectName(QString::fromUtf8("SelectResourceButton"));
        SelectResourceButton->setIcon(icon3);
        SelectResourceButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);

        horizontalLayout_6->addWidget(SelectResourceButton);

        PageWidget->addWidget(Resource);

        horizontalLayout_9->addWidget(PageWidget);

        AddToArrayButton = new QToolButton(EditVarDialog);
        AddToArrayButton->setObjectName(QString::fromUtf8("AddToArrayButton"));
        AddToArrayButton->setIcon(icon);
        AddToArrayButton->setToolButtonStyle(Qt::ToolButtonIconOnly);
        AddToArrayButton->setAutoRaise(true);

        horizontalLayout_9->addWidget(AddToArrayButton);

        DelFromArray = new QToolButton(EditVarDialog);
        DelFromArray->setObjectName(QString::fromUtf8("DelFromArray"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/delete.png"), QSize(), QIcon::Normal, QIcon::Off);
        DelFromArray->setIcon(icon5);
        DelFromArray->setAutoRaise(true);

        horizontalLayout_9->addWidget(DelFromArray);


        verticalLayout_3->addLayout(horizontalLayout_9);

        ArrayList = new QListWidget(EditVarDialog);
        ArrayList->setObjectName(QString::fromUtf8("ArrayList"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(ArrayList->sizePolicy().hasHeightForWidth());
        ArrayList->setSizePolicy(sizePolicy4);
        ArrayList->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ArrayList->setDragEnabled(true);
        ArrayList->setDragDropMode(QAbstractItemView::DragDrop);
        ArrayList->setDefaultDropAction(Qt::MoveAction);
        ArrayList->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_3->addWidget(ArrayList);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer);

        OKbutton = new QPushButton(EditVarDialog);
        OKbutton->setObjectName(QString::fromUtf8("OKbutton"));
        OKbutton->setDefault(true);

        horizontalLayout_10->addWidget(OKbutton);

        CancelButton = new QPushButton(EditVarDialog);
        CancelButton->setObjectName(QString::fromUtf8("CancelButton"));

        horizontalLayout_10->addWidget(CancelButton);


        verticalLayout_3->addLayout(horizontalLayout_10);

        verticalSpacer = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        retranslateUi(EditVarDialog);
        QObject::connect(CancelButton, SIGNAL(clicked()), EditVarDialog, SLOT(reject()));

        PageWidget->setCurrentIndex(6);


        QMetaObject::connectSlotsByName(EditVarDialog);
    } // setupUi

    void retranslateUi(QDialog *EditVarDialog)
    {
        EditVarDialog->setWindowTitle(QApplication::translate("EditVarDialog", "Add variable", 0, QApplication::UnicodeUTF8));
        varNameLabel->setText(QApplication::translate("EditVarDialog", "Variable name:", 0, QApplication::UnicodeUTF8));
        varTypeLabel->setText(QApplication::translate("EditVarDialog", "Variable type:", 0, QApplication::UnicodeUTF8));
        varType->clear();
        varType->insertItems(0, QStringList()
         << QApplication::translate("EditVarDialog", "Integer", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "Real", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "String", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "Boolean", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "2D point", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "3D point", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "Color", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "Function", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "Image", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "Class", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "Vector path", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("EditVarDialog", "...", 0, QApplication::UnicodeUTF8)
        );
        PropertyTypeGB->setTitle(QApplication::translate("EditVarDialog", "Variable kind", 0, QApplication::UnicodeUTF8));
        radioButton->setText(QApplication::translate("EditVarDialog", "Single variable", 0, QApplication::UnicodeUTF8));
        radioButton_2->setText(QApplication::translate("EditVarDialog", "Array of type", 0, QApplication::UnicodeUTF8));
        menuWithChoices->setText(QApplication::translate("EditVarDialog", "Menu with fixed choices", 0, QApplication::UnicodeUTF8));
        InitValLabel->setText(QApplication::translate("EditVarDialog", "Initital value(s):", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("EditVarDialog", "Integer:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("EditVarDialog", "Real:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("EditVarDialog", "String:", 0, QApplication::UnicodeUTF8));
        BoolBox->setText(QApplication::translate("EditVarDialog", "Check for true, uncheck for false", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("EditVarDialog", "X:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("EditVarDialog", "Y:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("EditVarDialog", "X:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("EditVarDialog", "Y:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("EditVarDialog", "Z:", 0, QApplication::UnicodeUTF8));
        SetColorToolButton->setText(QApplication::translate("EditVarDialog", "Select", 0, QApplication::UnicodeUTF8));
        FunctionLabel->setText(QApplication::translate("EditVarDialog", "Empty function", 0, QApplication::UnicodeUTF8));
        WriteFunctionButton->setText(QApplication::translate("EditVarDialog", "Write", 0, QApplication::UnicodeUTF8));
        SelectFunctionButton->setText(QApplication::translate("EditVarDialog", "Select", 0, QApplication::UnicodeUTF8));
        ResName_label->setText(QApplication::translate("EditVarDialog", "(Not selected)", 0, QApplication::UnicodeUTF8));
        NullresourceButton->setText(QApplication::translate("EditVarDialog", "NULL", 0, QApplication::UnicodeUTF8));
        SelectResourceButton->setText(QApplication::translate("EditVarDialog", "Select", 0, QApplication::UnicodeUTF8));
        AddToArrayButton->setText(QApplication::translate("EditVarDialog", "Add", 0, QApplication::UnicodeUTF8));
        AddToArrayButton->setShortcut(QApplication::translate("EditVarDialog", "Return", 0, QApplication::UnicodeUTF8));
        DelFromArray->setText(QApplication::translate("EditVarDialog", "...", 0, QApplication::UnicodeUTF8));
        DelFromArray->setShortcut(QApplication::translate("EditVarDialog", "Del", 0, QApplication::UnicodeUTF8));
        OKbutton->setText(QApplication::translate("EditVarDialog", "OK", 0, QApplication::UnicodeUTF8));
        CancelButton->setText(QApplication::translate("EditVarDialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class EditVarDialog: public Ui_EditVarDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDITVARDIALOG_H
