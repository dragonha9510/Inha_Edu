#pragma once 
 
#ifndef __2D_OBJECT_H__
#define __2D_OBJECT_H__

class C2D_Object
{
public:
	enum OBJ_TYPE {CIRCLE, RECT, POINT, TYPE_END};
public:
	C2D_Object() {}
	C2D_Object(double X, double Y, OBJ_TYPE t) : x(X), y(Y), type(t) {}
	virtual ~C2D_Object();

public:
	double getX(double* out = nullptr)const { NOTNULLRETURN(out, x) }
	double getY(double* out = nullptr)const { NOTNULLRETURN(out, y) }
	OBJ_TYPE getType() const { return type; }

public:
	virtual bool Contains(C2D_Object& obj) = 0;

protected:
	double x;
	double y;
	OBJ_TYPE type;
};

#endif // !__2D_OBJECT_H__