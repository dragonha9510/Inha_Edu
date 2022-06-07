#pragma once 
 
#ifndef __VECTOR3_H__
#define __VECTOR3_H__
 
class CVector3
{
private :
	explicit CVector3();

public: // Init
	CVector3(double x, double y, double z);
	~CVector3();

public:	// Operator
	bool operator==(CVector3& vec);
	bool operator!=(CVector3& vec);
	CVector3 operator+(CVector3 vec);
	CVector3 operator-(CVector3 vec);
	CVector3 operator=(CVector3 vec);
	CVector3 operator*(double d);
	CVector3 operator/(double d);
	friend ostream& operator<<(ostream& os, CVector3 vec);

public:	// Get
	double length();
	CVector3 normalize();
	CVector3 normal();

public: // Static
	static double dot(CVector3& v1, CVector3& v2);
	static double angle(CVector3& v1, CVector3& v2);
	static CVector3 cross(CVector3& v1, CVector3& v2);
	static CVector3 cross(CVector3& v1, CVector3& v2, int type);

private:
	double X, Y, Z;
};

#endif // !__VECTOR3_H__