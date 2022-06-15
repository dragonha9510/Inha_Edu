#include "stdafx0610.h"
#include "2D_Object.h"
#include "Rectangle2D.h" 

CRectangle2D::CRectangle2D()
{
	x = 0;
	y = 0;
	width = 1;
	height = 1;

	Calculate();
}

CRectangle2D::CRectangle2D(double X, double Y, double Width, double Height)
	:C2D_Object(X, Y, RECT)
{
	width = Width;
	height = Height;

	Calculate();
}

CRectangle2D::~CRectangle2D()
{
}

bool CRectangle2D::Contains(C2D_Object& obj)
{
	if (obj.getType() != RECT)
		return false;

	CRectangle2D* rect = dynamic_cast<CRectangle2D*>(&obj);

	if (rect == nullptr)
		return false;

	double X = rect->getX();
	double Y = rect->getY();
	double halfWidthSour = rect->getWidth() * 0.5;
	double halfHeightSour = rect->getHeight() * 0.5;

	double arrX[4] = { X - halfWidthSour , X + halfWidthSour, X - halfWidthSour, X + halfWidthSour };
	double arrY[4] = { Y - halfHeightSour, Y - halfHeightSour , Y + halfHeightSour, Y + halfHeightSour };

	int iCnt = 0;

	for (int i = 0; i < 4; ++i)
	{
		if (!Contains(arrX[i], arrY[i]))
			return false;
	}

	return true;
}

bool CRectangle2D::Contains(double X, double Y) const
{
	double halfWidth = (width * 0.5);
	double halfHeight = (height * 0.5);
	
	return (((x - halfWidth) <= X && (x + halfWidth) >= X) 
		&& ((y - halfHeight) <= Y && (y + halfHeight) >= Y));
}

bool CRectangle2D::Overlaps(const CRectangle2D& rect) const
{
	double X = rect.getX();
	double Y = rect.getY();
	double halfWidthSour = rect.getWidth() * 0.5;
	double halfHeightSour = rect.getHeight() * 0.5;

	return (X - x <= halfWidthSour + (width * 0.5)) && (Y - y <= halfHeightSour + (height * 0.5));;
}

void CRectangle2D::Calculate()
{
	area = width * height;
	round = width * 2 + height * 2;
}