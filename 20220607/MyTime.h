#pragma once

#ifndef __MYTIME_H__
#define __MYTIME_H__

class CTime
{
private:
	int hours = 0;
	int minutes = 0;

public:
	CTime();
	CTime(int h, int m = 0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h = 0, int m = 0);
	CTime Sum(const CTime& t)const;
	void Show() const;

public:
	CTime operator +(const CTime& t) const
	{
		return Sum(t);
	}
};

#endif // !__MYTIME_H__