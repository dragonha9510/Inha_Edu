#include "stdafx0610.h"
#include "MyPoint.h" 
#include "2D_Object.h"

CMyPoint::CMyPoint()
{
	x = 0;
	y = 0;
}

CMyPoint::CMyPoint(double X, double Y)
	:C2D_Object(X, Y, POINT)
{
}

CMyPoint::~CMyPoint()
{
}

double CMyPoint::getDistance(const CMyPoint& pt)
{
	return SQRT((pt.getX() - x) * (pt.getX() - x) + (pt.getY() - y) * (pt.getY() - y));
}

bool CMyPoint::Contains(C2D_Object& obj)
{
	switch (obj.getType())
	{
	case RECT:
		return dynamic_cast<CRectangle2D*>(&obj)->Contains(x, y);
	case CIRCLE:
		return dynamic_cast<CCircle2D*>(&obj)->Contains(x, y);
	default:
		break;
	}

	return false;
}