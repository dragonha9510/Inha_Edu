#include "stdafx0608.h"
#include "MyPoint.h" 

CMyPoint::CMyPoint()
{
	x = 0;
	y = 0;
}

CMyPoint::CMyPoint(double X, double Y)
{
	x = X;
	y = Y;
}

CMyPoint::~CMyPoint()
{
}

double CMyPoint::getDistance(const CMyPoint& pt)
{
	return SQRT( (pt.getX() - x) * (pt.getX() - x) + (pt.getY() - y) * (pt.getY() - y));
}

bool Contains(const CCircle2D& circle, const CMyPoint& pt)
{
	return circle.Contains(pt.getX(), pt.getY());;
}

bool Contains(const CRectangle2D& rect, const CMyPoint& pt)
{
	return rect.Contains(pt.getX(), pt.getY());
}
