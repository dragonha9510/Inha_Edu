#pragma once 

#ifndef __CIRCLE2D_H__
#define __CIRCLE2D_H__

class C2D_Object;

class CCircle2D : public C2D_Object
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
	bool Overlaps(const CCircle2D& circle) const;

private: // private method
	void Calculate(double* areaout = nullptr, double* roundout = nullptr);
	double Distance(double X, double Y) const;

public: // virtual
	virtual bool Contains(C2D_Object& obj) override;

private:
	double radius;
	double area;
	double round;
};

#endif // !__CIRCLE2D_H__