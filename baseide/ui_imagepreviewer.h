/********************************************************************************
** Form generated from reading UI file 'imagepreviewer.ui'
**
** Created: Fri 2. Nov 07:45:38 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPREVIEWER_H
#define UI_IMAGEPREVIEWER_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QListWidget>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QToolButton>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ImagePreviewer
{
public:
    QVBoxLayout *verticalLayout_3;
    QWidget *widget;
    QHBoxLayout *horizontalLayout_3;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout_6;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QToolButton *toolButton_2;
    QToolButton *toolButton;
    QListWidget *listWidget;
    QSpacerItem *verticalSpacer_2;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QWidget *AddRemove;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_4;
    QToolButton *toolButton_5;
    QSpinBox *spinBox;
    QToolButton *toolButton_6;
    QSpacerItem *horizontalSpacer_2;
    QToolButton *toolButton_4;
    QToolButton *toolButton_7;
    QGraphicsView *graphicsView;
    QFrame *line;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QFrame *frame;
    QFrame *LoaderFrame;
    QHBoxLayout *horizontalLayout;
    QLabel *loaderLabel;
    QLabel *statusLabel;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QPushButton *statusCancelButton;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *ImagePreviewer)
    {
        if (ImagePreviewer->objectName().isEmpty())
            ImagePreviewer->setObjectName(QString::fromUtf8("ImagePreviewer"));
        ImagePreviewer->resize(640, 480);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/resources/RES/ffficons/image.png"), QSize(), QIcon::Normal, QIcon::Off);
        ImagePreviewer->setWindowIcon(icon);
        ImagePreviewer->setWindowOpacity(1);
        ImagePreviewer->setSizeGripEnabled(true);
        verticalLayout_3 = new QVBoxLayout(ImagePreviewer);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        widget = new QWidget(ImagePreviewer);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout_3 = new QHBoxLayout(widget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        widget_2 = new QWidget(widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        frame_4 = new QFrame(widget_2);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        verticalLayout_6 = new QVBoxLayout(frame_4);
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        widget_3 = new QWidget(frame_4);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(6, 0, 6, 6);
        label = new QLabel(widget_3);
        label->setObjectName(QString::fromUtf8("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);

        horizontalLayout_5->addWidget(label);

        toolButton_2 = new QToolButton(widget_3);
        toolButton_2->setObjectName(QString::fromUtf8("toolButton_2"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(toolButton_2->sizePolicy().hasHeightForWidth());
        toolButton_2->setSizePolicy(sizePolicy2);
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/resources/RES/ffficons/tick.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_2->setIcon(icon1);
        toolButton_2->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton_2->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton_2);

        toolButton = new QToolButton(widget_3);
        toolButton->setObjectName(QString::fromUtf8("toolButton"));
        sizePolicy2.setHeightForWidth(toolButton->sizePolicy().hasHeightForWidth());
        toolButton->setSizePolicy(sizePolicy2);
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/resources/RES/ffficons/cross.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton->setIcon(icon2);
        toolButton->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        toolButton->setAutoRaise(true);

        horizontalLayout_5->addWidget(toolButton);


        verticalLayout_6->addWidget(widget_3);

        listWidget = new QListWidget(frame_4);
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/IDE/RES/splash.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon3);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(listWidget->sizePolicy().hasHeightForWidth());
        listWidget->setSizePolicy(sizePolicy3);
        listWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        listWidget->setIconSize(QSize(130, 16777215));
        listWidget->setFlow(QListView::TopToBottom);
        listWidget->setUniformItemSizes(false);
        listWidget->setSelectionRectVisible(true);

        verticalLayout_6->addWidget(listWidget);

        verticalSpacer_2 = new QSpacerItem(164, 0, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_6->addItem(verticalSpacer_2);


        verticalLayout_2->addWidget(frame_4);


        horizontalLayout_3->addWidget(widget_2);

        frame_3 = new QFrame(widget);
        frame_3->setObjectName(QString::fromUtf8("frame_3"));
        frame_3->setFrameShape(QFrame::NoFrame);
        frame_3->setFrameShadow(QFrame::Plain);
        verticalLayout_5 = new QVBoxLayout(frame_3);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        AddRemove = new QWidget(frame_3);
        AddRemove->setObjectName(QString::fromUtf8("AddRemove"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(AddRemove->sizePolicy().hasHeightForWidth());
        AddRemove->setSizePolicy(sizePolicy4);
        verticalLayout_7 = new QVBoxLayout(AddRemove);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(1);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(6, -1, -1, 6);
        toolButton_5 = new QToolButton(AddRemove);
        toolButton_5->setObjectName(QString::fromUtf8("toolButton_5"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/resources/RES/ffficons/zoom_out.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_5->setIcon(icon4);
        toolButton_5->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_5);

        spinBox = new QSpinBox(AddRemove);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setMinimum(10);
        spinBox->setMaximum(500);
        spinBox->setValue(100);

        horizontalLayout_4->addWidget(spinBox);

        toolButton_6 = new QToolButton(AddRemove);
        toolButton_6->setObjectName(QString::fromUtf8("toolButton_6"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/resources/RES/ffficons/zoom_in.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_6->setIcon(icon5);
        toolButton_6->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_6);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        toolButton_4 = new QToolButton(AddRemove);
        toolButton_4->setObjectName(QString::fromUtf8("toolButton_4"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/resources/RES/ffficons/disk.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_4->setIcon(icon6);
        toolButton_4->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_4);

        toolButton_7 = new QToolButton(AddRemove);
        toolButton_7->setObjectName(QString::fromUtf8("toolButton_7"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/resources/RES/ffficons/disk_multiple.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButton_7->setIcon(icon7);
        toolButton_7->setAutoRaise(true);

        horizontalLayout_4->addWidget(toolButton_7);


        verticalLayout_7->addLayout(horizontalLayout_4);


        verticalLayout_4->addWidget(AddRemove);

        graphicsView = new QGraphicsView(frame_3);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));

        verticalLayout_4->addWidget(graphicsView);


        verticalLayout_5->addLayout(verticalLayout_4);


        horizontalLayout_3->addWidget(frame_3);


        verticalLayout_3->addWidget(widget);

        line = new QFrame(ImagePreviewer);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        horizontalLayout_2 = new QHBoxLayout();
#ifndef Q_OS_MAC
        horizontalLayout_2->setSpacing(6);
#endif
#ifndef Q_OS_MAC
        horizontalLayout_2->setContentsMargins(9, 9, 9, 9);
#endif
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(ImagePreviewer);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        sizePolicy1.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy1);

        horizontalLayout_2->addWidget(label_3);

        frame = new QFrame(ImagePreviewer);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        LoaderFrame = new QFrame(frame);
        LoaderFrame->setObjectName(QString::fromUtf8("LoaderFrame"));
        LoaderFrame->setGeometry(QRect(8, 0, 369, 73));
        LoaderFrame->setFrameShape(QFrame::Panel);
        LoaderFrame->setFrameShadow(QFrame::Raised);
        LoaderFrame->setLineWidth(1);
        horizontalLayout = new QHBoxLayout(LoaderFrame);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(16, 9, 9, 9);
        loaderLabel = new QLabel(LoaderFrame);
        loaderLabel->setObjectName(QString::fromUtf8("loaderLabel"));

        horizontalLayout->addWidget(loaderLabel);

        statusLabel = new QLabel(LoaderFrame);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        font.setWeight(75);
        statusLabel->setFont(font);

        horizontalLayout->addWidget(statusLabel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        statusCancelButton = new QPushButton(LoaderFrame);
        statusCancelButton->setObjectName(QString::fromUtf8("statusCancelButton"));

        verticalLayout->addWidget(statusCancelButton);


        horizontalLayout->addLayout(verticalLayout);


        horizontalLayout_2->addWidget(frame);

        buttonBox = new QDialogButtonBox(ImagePreviewer);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        QSizePolicy sizePolicy5(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy5);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        horizontalLayout_2->addWidget(buttonBox);


        verticalLayout_3->addLayout(horizontalLayout_2);


        retranslateUi(ImagePreviewer);
        QObject::connect(buttonBox, SIGNAL(accepted()), ImagePreviewer, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ImagePreviewer, SLOT(reject()));

        QMetaObject::connectSlotsByName(ImagePreviewer);
    } // setupUi

    void retranslateUi(QDialog *ImagePreviewer)
    {
        ImagePreviewer->setWindowTitle(QApplication::translate("ImagePreviewer", "Select frame", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ImagePreviewer", "Select:", 0, QApplication::UnicodeUTF8));
        toolButton_2->setText(QApplication::translate("ImagePreviewer", "All", 0, QApplication::UnicodeUTF8));
        toolButton->setText(QApplication::translate("ImagePreviewer", "None", 0, QApplication::UnicodeUTF8));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        listWidget->setSortingEnabled(__sortingEnabled);

        toolButton_5->setText(QApplication::translate("ImagePreviewer", "Delete", 0, QApplication::UnicodeUTF8));
        spinBox->setSuffix(QApplication::translate("ImagePreviewer", " %", 0, QApplication::UnicodeUTF8));
        spinBox->setPrefix(QApplication::translate("ImagePreviewer", "Zoom: ", 0, QApplication::UnicodeUTF8));
        toolButton_6->setText(QApplication::translate("ImagePreviewer", "Delete", 0, QApplication::UnicodeUTF8));
        toolButton_4->setText(QApplication::translate("ImagePreviewer", "Save", 0, QApplication::UnicodeUTF8));
        toolButton_7->setText(QApplication::translate("ImagePreviewer", "Save All", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("ImagePreviewer", "A comment", 0, QApplication::UnicodeUTF8));
        loaderLabel->setText(QApplication::translate("ImagePreviewer", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><img src=\":/resources/RES/loader.gif\" /></p></body></html>", 0, QApplication::UnicodeUTF8));
        statusLabel->setText(QApplication::translate("ImagePreviewer", "Querying image data...", 0, QApplication::UnicodeUTF8));
        statusCancelButton->setText(QApplication::translate("ImagePreviewer", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ImagePreviewer: public Ui_ImagePreviewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPREVIEWER_H
