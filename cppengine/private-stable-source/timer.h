#ifndef TIMER_H
#define TIMER_H
#include "pgframework.h"



class timer
{
public:
	
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
};

#endif //TIMER_H