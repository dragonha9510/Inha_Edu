#include "stdafx.h"

int main()
{
	CVector3 v1(1, 0, 0);
	CVector3 v2(0, 1, 0);
	CVector3 v3 = CVector3::cross(v1, v2);

	cout << v1 << endl;
	cout << v2 << endl;
	cout << CVector3::angle(v1, v2) << endl;
	cout << v3 << endl;
	return 0;
}