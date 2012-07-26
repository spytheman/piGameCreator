#ifndef TIMER_H_DEF 
#define TIMER_H_DEF 
 
#ifdef WIN32   // Windows system specific 
#include <windows.h> 
#else          // Unix based system specific 
#include <sys/time.h> 
#endif 
 
 
class highPerformanceTimer
{ 
public: 
    highPerformanceTimer();                                    // default constructor
    ~highPerformanceTimer();                                   // default destructor
 
    void   start();                             // start timer 
    void   stop();                              // stop the timer 
    double getElapsedTime();                    // get elapsed time in second 
    double getElapsedTimeInSec();               // get elapsed time in second (same as getElapsedTime) 
    double getElapsedTimeInMilliSec();          // get elapsed time in milli-second 
    double getElapsedTimeInMicroSec();          // get elapsed time in micro-second 
 
 
protected: 
 
 
private: 
    double startTimeInMicroSec;                 // starting time in micro-second 
    double endTimeInMicroSec;                   // ending time in micro-second 
    int    stopped;                             // stop flag  
#ifdef WIN32 
    LARGE_INTEGER frequency;                    // ticks per second 
    LARGE_INTEGER startCount;                   // 
    LARGE_INTEGER endCount;                     // 
#else 
    timeval startCount;                         // 
    timeval endCount;                           // 
#endif 
}; 
 
#endif // TIMER_H_DEF 
