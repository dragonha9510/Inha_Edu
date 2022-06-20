#include <iostream>
#include <windows.h>

#include "StopWatch.h" 

CStopWatch::CStopWatch()
{
	tStartTime = clock();
}

CStopWatch::~CStopWatch()
{
}

time_t CStopWatch::Start()
{
	return tStartTime = clock();
}

time_t CStopWatch::Stop()
{
	tEndTime = clock();

	tElapsedTime = tEndTime - tStartTime;

	return tElapsedTime;
}

