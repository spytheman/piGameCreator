#include "splashscreen.h"
#include "ui_splashscreen.h"
#include "mainwindow.h"
#include <QThread>
#include <QGraphicsDropShadowEffect>
#include <QCloseEvent>
#include "threads/initthread.h"
#include "gcide.h"
#include "../sharedcode/globals.h"
#include "QGraphicsBlurEffect"

SplashScreen::SplashScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SplashScreen)
{
    ui->setupUi(this);
    setWindowTitle("pi|game CREATOR");
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    ssInitThread = new initThread();

    QGraphicsDropShadowEffect* ds = new QGraphicsDropShadowEffect;
    ds->setBlurRadius(4);
    ds->setXOffset(1);
    ds->setYOffset(1);
    ds->setColor(Qt::black);
    ui->splashLabel->setGraphicsEffect(ds);
    canClose = true;

    initThread* t = new initThread;
    t->splash = this;
    connect(t,SIGNAL(finished()), this, SLOT(initcomplete()));
    connect(t,SIGNAL(terminated()), this, SLOT(initcomplete()));
    connect(t,SIGNAL(messageChanged(QString)),this,SLOT(setMessage(QString)));
    t->start();
}

SplashScreen::~SplashScreen()
{
    creatorIDE->splashScreen = 0;
    delete ui;
}
void SplashScreen::reject()
{
    close();
}

void SplashScreen::closeEvent(QCloseEvent *e)
{
    if(canClose)e->accept();
    else e->ignore();
}
QString SplashScreen::message()
{
    return ui->splashLabel->text();
}
void SplashScreen::initcomplete()
{
    canClose=true;
    close();
}
void SplashScreen::setMessage(QString s)
{
    //print to the log
    gcprint(s);
    ui->splashLabel->setText(s);
}

void SplashScreen::ShowForAWhile()
{
    setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint | Qt::SplashScreen);
    show();
    timer.setInterval(1500);
    timer.setSingleShot(1);
    connect(&timer,SIGNAL(timeout()),this,SLOT(completed()));
    timer.start();
}

void SplashScreen::completed()
{
    creatorIDE->mainWindow->activateWindow();

    fadetimer.setInterval(10);
    connect(&fadetimer, SIGNAL(timeout()), this, SLOT(fadeoutStep()));
    blur = new QGraphicsBlurEffect;
    fadetimer.start();
}

void SplashScreen::fadeoutStep()
{
    static int i = 10;
    int steps=30;
    if(i>=steps) {close(); return;}
    setWindowOpacity( (float)(steps-i)/(float)steps );
    i++;
}
