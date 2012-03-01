#include "mainpage.h"
#include "ui_mainpage.h"
#include "gamecreator.h"
#include <QMessageBox>
#include <QUrl>
#include <QFileInfo>
#include <QWebFrame>
#include <QWebElement>
#include <QDesktopServices>
#include <QWebHistory>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>

MainPage::MainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainPage)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    ui->webView->setContextMenuPolicy(Qt::NoContextMenu);
    ui->webView->setUrl(QUrl("data/mainpage.html"));
    QGraphicsDropShadowEffect* ds = new QGraphicsDropShadowEffect;
    ds->setBlurRadius(10);
    ds->setYOffset(3);
    ds->setXOffset(0);
    ds->setColor(QColor(0,0,0,210));
    ui->webView->setGraphicsEffect(ds);
}

MainPage::~MainPage()
{
    delete ui;
}

void MainPage::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void MainPage::on_webView_linkClicked(QUrl u)
{
    gcprint("Main page: Link click: "+u.toString());
    gcprint("Protocol: "+u.scheme());
    gcprint("Path: "+u.path());
    ui->webView->history()->clear();

    if(u.scheme()=="http")QDesktopServices::openUrl(u);
    if(u.scheme()=="recent")
    {
        projects.open(u.toString().mid(8));
    }
    if(u.path()=="newproject" and u.scheme()=="ui")
    {
        gcprint("Creating new project");
        gcmessage("Creating a new project... TODO: Implement it!");
    }
    if(u.path()=="openproject" and u.scheme()=="ui")
    {
        QString s = QFileDialog::getOpenFileName(this,tr("Open project"),"","piGameCreator project (*.gcpx)");
        if(s!="")projects.open(s);
    }
}

void MainPage::on_webView_loadFinished(bool b)
{
    ui->webView->history()->clear();
    if(b==true)
    {
        QWebFrame* wf = ui->webView->page()->mainFrame();
        QWebElement rf = wf->findFirstElement("div.recentfiles");
        if(rf.isNull()){gcprint("ERROR data/mainpage.html: Missing div.recentfiles");return;}
        else
        {
            QString TheHTML;
            foreach(QString i,RecentFiles)
            {
                QUrl link = QUrl::fromLocalFile(i);
                link.setScheme("recent");
                TheHTML.append("<a class='rfile' href='"+link.toString()+"'><img src='file.png'> "+QFileInfo(i).fileName()+"</a>\n");
            }
            rf.removeAllChildren();
            rf.appendInside(TheHTML);
        }
    }
}
