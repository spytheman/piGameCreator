#include "wwmainpage.h"
#include "ui_wwmainpage.h"
#include "gcide.h"
#include "../sharedcode/globals.h"
#include <QDir>
#include <QGraphicsDropShadowEffect>
#include <QFileDialog>
#include <QtWebKit/QWebHistory>
#include <QtWebKit/QWebElement>
#include <QDesktopServices>
#include <QPushButton>
#include <QtWebKit/QWebFrame>

wwMainPage::wwMainPage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::wwMainPage)
{
    ui->setupUi(this);
    widget = this;
    setTitle("Welcome");
    QWebSettings::setObjectCacheCapacities(0,0,0);
    setAttribute(Qt::WA_DeleteOnClose,true);
    ui->setupUi(this);

    connect(ui->webView,SIGNAL(loadFinished(bool)),this,SLOT(on_webView_loadFinished(bool)));
    connect(ui->webView,SIGNAL(linkClicked(QUrl)),this,SLOT(on_webView_linkClicked(QUrl)));

    ui->webView->page()->setLinkDelegationPolicy(QWebPage::DelegateAllLinks);
    ui->webView->setContextMenuPolicy(Qt::NoContextMenu);
    ui->webView->setUrl( QUrl::fromLocalFile(QDir::currentPath()+"/data/mainpage.html"));

    QGraphicsDropShadowEffect* ds = new QGraphicsDropShadowEffect;
    ds->setBlurRadius(10);
    ds->setYOffset(3);
    ds->setXOffset(0);
    ds->setColor(QColor(0,0,0,210));
    ui->webView->setGraphicsEffect(ds);
}

void wwMainPage::changeEvent(QEvent *e)
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

wwMainPage::~wwMainPage()
{
    delete ui;
}

void wwMainPage::on_webView_linkClicked(QUrl u)
{
    gcprint("Main page: Link click: "+u.toString());
    gcprint("Protocol: "+u.scheme());
    gcprint("Path: "+u.path());
    ui->webView->history()->clear();

    if(u.scheme()=="http")QDesktopServices::openUrl(u);
    if(u.scheme()=="recent")
    {
        //projects.open(u.toString().mid(8));
        creatorIDE->openProject(u.toString().mid(8));
    }
    if(u.path()=="newproject" and u.scheme()=="ui")
    {
        gcprint("Creating new project");
        gcmessage("Creating a new project... TODO: Implement it!");
    }
    if(u.path()=="openproject" and u.scheme()=="ui")
    {
        QString s = QFileDialog::getOpenFileName(this,tr("Open project"),"","piGameCreator project (*.gcpx)");
        if(s!="")creatorIDE->openProject(s);
    }/**/
}

void wwMainPage::on_webView_loadFinished(bool b)
{
    gcprint("wwMainPage: Load finished");
    ui->webView->history()->clear();
    if(b==true)
    {
        QWebFrame* wf = ui->webView->page()->mainFrame();
        QWebElement rf = wf->findFirstElement("div.recentfiles");
        if(rf.isNull()){gcprint("ERROR data/mainpage.html: Missing div.recentfiles");return;}
        else
        {
            QString TheHTML;
            foreach(QString i, creatorIDE->settings->value("creatorIDE/RecentFiles",QStringList()).toStringList() )
            {
                QUrl link = QUrl::fromLocalFile(i);
                link.setScheme("recent");
                TheHTML.append("<a class='rfile' href='"+link.toString()+"'><img src='file.png'> "+QFileInfo(i).fileName()+"</a>\n");
            }
            rf.removeAllChildren();
            rf.appendInside(TheHTML);
        }
    }/**/
}
