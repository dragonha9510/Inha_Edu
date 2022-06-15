#pragma once 
 
#ifndef __2D_OBJECT_H__
#define __2D_OBJECT_H__
 
class C2D_Object
{
public:
	virtual ~C2D_Object();

protected:
	double x;
	double y;
};

#endif // !__2D_OBJECT_H__