#include "stdafx0608.h"
#include "Stonewt.h" 

CStonewt::CStonewt()
{
	stone = 0;
	pounds = 0;
	pds_left = 0;
}

CStonewt::~CStonewt()
{
}

CStonewt::CStonewt(double lbs)
{
	stone = int(lbs) / Lbs_per_stn;
	pds_left = int(lbs) % Lbs_per_stn + lbs - int(lbs);
	pounds = lbs;
}

CStonewt::CStonewt(int stn, double lbs)
{
	stone = stn;
	pds_left = lbs;
	pounds = stn * Lbs_per_stn + lbs;
}

void CStonewt::show_lbs() const
{
	cout << pounds << "파운드" << endl;
}

void CStonewt::show_stn() const
{
	cout << stone << "스톤, " << pds_left << "파운드" << endl;
}

CStonewt::operator int() const
{
	return int(pounds + 0.5);
}

CStonewt::operator double() const
{
	return pounds;
}

