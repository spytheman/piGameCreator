#ifndef WWMAINPAGE_H
#define WWMAINPAGE_H

#include <QMainWindow>
#include "resourceeditor.h"
#include <QUrl>

namespace Ui {
class wwMainPage;
}

class wwMainPage : public QMainWindow, public WorkspaceWidget
{
    Q_OBJECT
    
public:
    explicit wwMainPage(QWidget *parent = 0);
    ~wwMainPage();
    void changeEvent(QEvent *);
    void refresh();
    
private slots:
    void on_webView_linkClicked(QUrl u);
    void on_webView_loadFinished(bool);

private:
    Ui::wwMainPage *ui;
};

#endif // WWMAINPAGE_H
