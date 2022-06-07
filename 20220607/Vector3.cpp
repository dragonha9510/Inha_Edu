#include "stdafx.h"
#include "Vector3.h" 

CVector3::CVector3()
	:X(0), Y(0), Z(0)
{
}

CVector3::CVector3(double x, double y, double z)
{
	X = x;
	Y = y;
	Z = z;
}

CVector3::~CVector3()
{
}

bool CVector3::operator==(CVector3& vec)
{
	return (vec.X == X) ? ((vec.Y == Y) ? ((vec.Z == Z) ? true : false) : false) : false;
}

bool CVector3::operator!=(CVector3& vec)
{
	return  (vec.X == X) ? ((vec.Y == Y) ? ((vec.Z == Z) ? false : true) : true) : true;
}

CVector3 CVector3::operator+(CVector3 vec)
{
	return CVector3(X + vec.X, Y + vec.Y, Z + vec.Z);
}

CVector3 CVector3::operator-(CVector3 vec)
{
	return CVector3(X - vec.X, Y - vec.Y, Z - vec.Z);
}

CVector3 CVector3::operator=(CVector3 vec)
{
	X = vec.X;
	Y = vec.Y;
	Z = vec.Z;

	return *this;
}

CVector3 CVector3::operator*(double d)
{
	return CVector3(X * d, Y * d, Z * d);
}

CVector3 CVector3::operator/(double d)
{
	return CVector3(X / d, Y / d, Z / d);
}

double CVector3::dot(CVector3& v1, CVector3& v2)
{
	return (v1.X * v2.X) + (v1.Y * v2.Y) + (v1.Z * v2.Z);
}

double CVector3::angle(CVector3& v1, CVector3& v2)
{
	CVector3 v1Normal = v1.normalize();
	CVector3 v2Normal = v2.normalize();
	
	return acos(dot(v1Normal, v2Normal)) * 180.0 / 3.14159265358979;
}

CVector3 CVector3::cross(CVector3& v1, CVector3& v2)
{
	return CVector3(v1.Y * v2.Z - v1.Z * v2.Y, 
		v1.Z * v2.X - v1.X * v2.Z,
		v1.X * v2.Y - v1.Y * v2.X);
}

CVector3 CVector3::cross(CVector3& v1, CVector3& v2, int type)
{
	if(type)
		return CVector3(v1.Y * v2.Z - v1.Z * v2.Y,
		v1.Z * v2.X - v1.X * v2.Z,
		v1.X * v2.Y - v1.Y * v2.X);
	else
		return CVector3(v2.Y * v1.Z - v2.Z * v1.Y,
			v2.Z * v1.X - v2.X * v1.Z,
			v2.X * v1.Y - v2.Y * v1.X);
}

double CVector3::length()
{
	double a = SQRT((X * X) + (Z * Z));

	return 	SQRT((a * a) + (Y * Y));
}

CVector3 CVector3::normalize()
{
	double dLength = length();

	return CVector3(X / dLength, Y / dLength, Z / dLength);
}

CVector3 CVector3::normal()
{
	return CVector3();
}

ostream& operator<<(ostream& os, CVector3 vec)
{
	os << "x/y/z : " << vec.X << "/" << vec.Y << "/" << vec.Z;
	return os;
}
