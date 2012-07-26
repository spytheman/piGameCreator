#ifndef INITTHREAD_H
#define INITTHREAD_H

#include <QThread>
class SplashScreen;

class initThread: public QThread
{
    Q_OBJECT
    //This thread must initialize ALL piGameCreator stuff.
    friend class SplashScreen;
    SplashScreen* splash;
    void run();

signals:
    void messageChanged(QString message);
};


#endif // INITTHREAD_H
