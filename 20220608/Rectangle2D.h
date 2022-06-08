#pragma once 
 
#ifndef __RECTANGLE2D_H__
#define __RECTANGLE2D_H__

class CRectangle2D
{
public:
	CRectangle2D();
	CRectangle2D(double X = 0, double Y = 0, double Width = 1, double Height = 1);
	~CRectangle2D();

public: // get
	double getX(double* out = nullptr)const { NOTNULLRETURN(out, x) }
	double getY(double* out = nullptr)const { NOTNULLRETURN(out, y) }
	double getArea(double* out = nullptr)const { NOTNULLRETURN(out, area) }
	double getWidth(double* out = nullptr)const { NOTNULLRETURN(out, width) }
	double getHeight(double* out = nullptr)const { NOTNULLRETURN(out, height) }
	double getPerimeter(double* out = nullptr)const { NOTNULLRETURN(out, round) }

public: // cal
	bool Contains(double X, double Y) const;
	bool Contains(const CRectangle2D& rect) const;
	bool Overlaps(const CRectangle2D& rect) const;

private:
	void Calculate();

private:
	double x;
	double y;
	double area;
	double round;
	double width;
	double height;
};

#endif // !__RECTANGLE2D_H__