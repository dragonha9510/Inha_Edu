#include "stdafx.h"
#include "MyTime.h"

CTime::CTime()
{
	hours = minutes = 0;
}

CTime::CTime(int h, int m)
{
	hours = h;
	minutes = m;

	if (minutes >= 60)
	{
		hours += minutes / 60;
		minutes %= 60;
	}
}

void CTime::AddMin(int m)
{
	minutes += m;
	hours += minutes / 60;
	minutes %= 60;
}

void CTime::AddHr(int h)
{
	hours += h;
}

void CTime::Reset(int h, int m)
{
	hours = h;
	minutes = m;
}

CTime CTime::Sum(const CTime& t) const
{
	CTime sum;
	sum.minutes = minutes + t.minutes;
	sum.hours = hours + t.hours + (sum.minutes / 60);
	sum.minutes %= 60;

	return sum;
}

void CTime::Show() const
{
	cout << hours << "½Ã°£, " << minutes << "ºĞ";
}
