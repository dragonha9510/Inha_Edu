#pragma once 
 
#ifndef __MYPOINT_H__
#define __MYPOINT_H__

class CCircle2D;
class CRectangle2D;

class CMyPoint
{
public:
	CMyPoint();
	CMyPoint(double X, double Y);
	~CMyPoint();

public:	//	get
	double getX(double* out = nullptr) const { NOTNULLRETURN(out, x) }
	double getY(double* out = nullptr) const { NOTNULLRETURN(out, y) }
	double getDistance(const CMyPoint& pt);

public:	//	set
	double setX(double X) { x = X; return x; }
	double setY(double Y) { x = Y; return y; }

public: //	cal
	friend bool Contains(const CCircle2D& circle, const CMyPoint& pt);
	friend bool Contains(const CRectangle2D& rect, const CMyPoint& pt);

private:	
	double x;
	double y;
};

#endif // !__MYPOINT_H__