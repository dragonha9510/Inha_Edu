#include "stdafx0608.h"
#include "Circle2D.h" 

CCircle2D::CCircle2D()
{
	x = 0;
	y = 0;
	radius = 1;

	Calculate(&area, &round);
}

CCircle2D::CCircle2D(double X, double Y, double Radius)
{
	x = X;
	y = Y;
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

bool CCircle2D::Contains(const CCircle2D& circle)const
{
	return 	(Distance(circle.getX(), circle.getY()) + circle.getRadius() <= radius);
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
