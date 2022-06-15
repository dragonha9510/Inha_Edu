#include "stdafx0610.h"
#include "Circle2D.h" 
#include "2D_Object.h"

CCircle2D::CCircle2D()
{
	x = 0;
	y = 0;
	radius = 1;

	Calculate(&area, &round);
}

CCircle2D::CCircle2D(double X, double Y, double Radius)
	: C2D_Object(X, Y, CIRCLE)
{
	radius = Radius;

	Calculate(&area, &round);
}

CCircle2D::~CCircle2D()
{
}

bool CCircle2D::Contains(double X, double Y)const
{
	return (Distance(X, Y) <= radius);
}

bool CCircle2D::Contains(C2D_Object& obj)
{
	if (obj.getType() != CIRCLE)
		return false;

	CCircle2D* circle = dynamic_cast<CCircle2D*>(&obj);

	if (circle == nullptr)
		return false;

	return 	(Distance(circle->getX(), circle->getY()) + circle->getRadius() <= radius);
}

bool CCircle2D::Overlaps(const CCircle2D& circle)const
{
	return (Distance(circle.getX(), circle.getY()) <= (circle.getRadius() + radius));
}

void CCircle2D::Calculate(double* areaout, double* roundout)
{
	area = *areaout = radius * radius * PI;
	round = *roundout = 2 * radius * PI;
}

double CCircle2D::Distance(double X, double Y) const
{
	return SQRT((X - x) * (X - x) + (Y - y) * (Y - y));
}
