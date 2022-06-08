#pragma once 

#ifndef __CIRCLE2D_H__
#define __CIRCLE2D_H__

class CCircle2D
{
public:
	CCircle2D();
	CCircle2D(double X = 0, double Y = 0, double Radius = 1);
	~CCircle2D();

public: // get
	double getX(double* out = nullptr)const { NOTNULLRETURN(out, x) }
	double getY(double* out = nullptr)const { NOTNULLRETURN(out, y) }
	double getArea(double* out = nullptr)const { NOTNULLRETURN(out, area) }
	double getRadius(double* out = nullptr)const { NOTNULLRETURN(out, radius) }
	double getPerimeter(double* out = nullptr)const { NOTNULLRETURN(out,round) }

public: // cal
	bool Contains(double X, double Y) const;
	bool Contains(const CCircle2D& circle) const;
	bool Overlaps(const CCircle2D& circle) const;

private:
	void Calculate(double* areaout = nullptr, double* roundout = nullptr);
	double Distance(double X, double Y) const;

private:
	double x;
	double y;
	double radius;
	double area;
	double round;
};

#endif // !__CIRCLE2D_H__