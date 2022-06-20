#pragma once 
 
#ifndef __BAD_HMEAN_H__
#define __BAD_HMEAN_H__
 
class CBad_hmean
{
public:
	CBad_hmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	~CBad_hmean();

public:
	void mesg()
	{
		cout << "hmean(" << v1 << ", " << v2 << ") : " << "�߸��� �Ű����� : a = -b\n";
	}

private:
	double v1;
	double v2;
};

class CBad_gmean
{
public:
	CBad_gmean(double a = 0, double b = 0) : v1(a), v2(b) {}
	const char* mesg()
	{
		return "gmean() �Ű��������� >= 0 �̾�� �մϴ�.\n";
	}
public:
	double v1;
	double v2;
};

#endif // !__BAD_HMEAN_H__