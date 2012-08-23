#ifndef TIMER_H
#define TIMER_H
#include "pgframework.h"
#include <cstdlib>

#ifdef WIN32   // Windows system specific
#include <windows.h>
#else          // Unix based system specific
#include <sys/time.h>
#endif

class timer
{
public:
    timer();
/*
	Gets elapsed time in seconds.
*/
	real getElapsedTimeInSec();
	
/*
	Gets elapsed time in milli-seconds. 
*/
	real getElapsedTimeInMilliSec();
	
/*
	Stops the timer.
*/
	void stop();
	
/*
	Gets elapsed time in micro-seconds. 
*/
	real getElapsedTimeInMicroSec();
	
/*
	Gets elapsed time in seconds.
*/
	real getElapsedTime();
	
/*
	Starts the timer.
*/
	void start();

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

#endif //TIMER_H
