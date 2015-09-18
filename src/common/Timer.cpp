// High Resolution Timer.
// This timer is able to measure the elapsed time with 1 micro-second accuracy
// in both Windows, Linux and Unix system
//
//  AUTHOR: Song Ho Ahn (song.ahn@gmail.com)
// CREATED: 2003-01-13
// UPDATED: 2006-01-13
//
// Copyright (c) 2003 Song Ho Ahn
//////////////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include "Timer.h"

/**
* @ingroup Common
* Constructor
**/
Timer::Timer()
{
#ifdef WIN32
int core=0; 
	//SetThreadAffinityMask(GetCurrentThread(),(1<<core)-1);
   QueryPerformanceFrequency(&frequency);
   startCount.QuadPart = 0;
   endCount.QuadPart = 0;
#else
   startCount.tv_sec = startCount.tv_usec = 0;
   endCount.tv_sec = endCount.tv_usec = 0;
#endif

   stopped = 0;
   startTimeInMicroSec = 0;
   endTimeInMicroSec = 0;
}

/**
* @ingroup Common
* Destructor
**/
Timer::~Timer()
{
}

/**
* @ingroup Common
* Start timer.
* startCount will be set at this point.
**/
void Timer::start()
{  stopped = 0; // reset stop flag
#ifdef WIN32
   QueryPerformanceCounter(&startCount);
#else
   gettimeofday(&startCount, NULL);
#endif
}

/**
* @ingroup Common
* Stop the timer.
* endCount will be set at this point.
**/

void Timer::stop()
{  stopped = 1; // set timer stopped flag

#ifdef WIN32
   QueryPerformanceCounter(&endCount);
#else
   gettimeofday(&endCount, NULL);
#endif
}



/**
* @ingroup Common
* Compute elapsed time in micro-second resolution.
* other getElapsedTime will call this first, then convert to correspond resolution.
* @return Elapsed time in microseconds
**/
double Timer::getElapsedTimeInMicroSec()
{
#ifdef WIN32
   if(!stopped)
      QueryPerformanceCounter(&endCount);

   startTimeInMicroSec = startCount.QuadPart * (1000000.0 / frequency.QuadPart);
   endTimeInMicroSec = endCount.QuadPart * (1000000.0 / frequency.QuadPart);
#else
   if(!stopped)
      gettimeofday(&endCount, NULL);

   startTimeInMicroSec = (startCount.tv_sec * 1000000.0) + startCount.tv_usec;
   endTimeInMicroSec = (endCount.tv_sec * 1000000.0) + endCount.tv_usec;
#endif

   return endTimeInMicroSec - startTimeInMicroSec;
}


/**
* @ingroup Common
* Compute elapsed time in millisecond resolution.
* other getElapsedTime will call this first, then convert to correspond resolution.
* @return Elapsed time in millisecond
**/
double Timer::getElapsedTimeInMilliSec()
{  return this->getElapsedTimeInMicroSec() * 0.001;
}



/**
* @ingroup Common
* Compute elapsed time in seconds resolution.
* other getElapsedTime will call this first, then convert to correspond resolution.
* @return Elapsed time in seconds
**/
double Timer::getElapsedTimeInSec()
{  return this->getElapsedTimeInMicroSec() * 0.000001;
}



/**
* @ingroup Common
* Same as getElapsedTimeInSec()
* @return Elapsed time in seconds
**/
double Timer::getElapsedTime()
{  return this->getElapsedTimeInSec();
}

/**
* @ingroup Common
* Full the CPU for specified time (in milliSeconds)
* Not very beatiful
**/
void Timer::sleep(unsigned int milliSeconds)
{  this->start();
   while ( this->getElapsedTimeInMilliSec() < milliSeconds );
   this->stop();
}

/**
* @ingroup Common
* Reset the timer count to zero
**/

void Timer::reset()
{
	this->startTimeInMicroSec=this->endTimeInMicroSec=0;
}
