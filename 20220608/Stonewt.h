#pragma once 
 
#ifndef __STONEWT_H__
#define __STONEWT_H__
 
class CStonewt
{
public:
	explicit CStonewt();
	~CStonewt();

public:
	CStonewt(double lbs);
	CStonewt(int stn, double lbs);

public:
	void show_lbs()const;
	void show_stn()const;
	operator int() const;
	operator double() const;

private:
	enum {Lbs_per_stn = 14};
	int stone;
	double pds_left;
	double pounds;
};

#endif // !__STONEWT_H__