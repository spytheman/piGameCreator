#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QDialog>
#include <QTimer>


namespace Ui {
class SplashScreen;
}
class initThread;
class QGraphicsBlurEffect;
class SplashScreen : public QDialog
{
    friend class initThread;
    Q_OBJECT
    
public:
    explicit SplashScreen(QWidget *parent = 0);
    ~SplashScreen();
    void closeEvent(QCloseEvent *);
    void reject();
    QString message();

public slots:
    void setMessage(QString);
    void initcomplete();
    void ShowForAWhile();
    void completed();
    void fadeoutStep();

private:
    Ui::SplashScreen *ui;
    initThread* ssInitThread;
    bool canClose;
    QTimer timer, fadetimer;
    QGraphicsBlurEffect* blur;
};

#endif // SPLASHSCREEN_H
