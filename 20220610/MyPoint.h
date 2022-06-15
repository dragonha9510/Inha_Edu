#pragma once 
 
#ifndef __MYPOINT_H__
#define __MYPOINT_H__

class C2D_Object;
class CCircle2D;
class CRectangle2D;

class CMyPoint : public C2D_Object
{
public:
	CMyPoint();
	CMyPoint(double X, double Y);
	~CMyPoint();

public:	//	get
	double getDistance(const CMyPoint& pt);

public:	//	set
	double setX(double X) { x = X; return x; }
	double setY(double Y) { x = Y; return y; }

public: // virtual
	virtual bool Contains(C2D_Object& obj) override;
};

#endif // !__MYPOINT_H__