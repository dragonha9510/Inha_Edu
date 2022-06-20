#pragma once 
 
#ifndef __STOPWATCH_H__
#define __STOPWATCH_H__
 
class CStopWatch
{
public:
	explicit CStopWatch();
	~CStopWatch();

public:	// get
	time_t getStart(time_t* out = nullptr) const { if (out)*out = tStartTime; return tStartTime; }
	time_t getEnd(time_t* out = nullptr) const { if (out)*out = tEndTime; return tEndTime; }
	time_t getElapsedTime(time_t* out = nullptr) const { if (out)*out = tElapsedTime; return tElapsedTime; }

public: // set
	time_t Start();
	time_t Stop();

private:
	time_t tStartTime = 0;
	time_t tEndTime = 0;
	time_t tElapsedTime = 0;
};

#endif // !__STOPWATCH_H__