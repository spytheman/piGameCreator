#ifndef MAINPAGE_H
#define MAINPAGE_H

#include <QMainWindow>
#include <QUrl>

namespace Ui {
    class MainPage;
}

class MainPage : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainPage(QWidget *parent = 0);
    ~MainPage();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainPage *ui;

private slots:
    void on_webView_loadFinished(bool);
    void on_webView_linkClicked(QUrl u);
};

#endif // MAINPAGE_H
