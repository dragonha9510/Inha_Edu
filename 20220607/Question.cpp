#include "stdafx.h"
#include "Question.h"

//				1
//			1	2	1
//		1	2	4	2	1
//	1	2	4	8	4	2	1

int POW(int a, int b)
{
	int res = 1;

	for (int i = 0; i < b; ++i)
		res *= a;

	return res;
}

int ABS(int t)
{
	return t < 0 ? t * -1 : t;
}

double SQRT(double num)
{
	double a = 0, b = 0;

	a = num / 2.0;

	while (a != b)
	{
		b = a;
		a = ((num / b) + b) / 2.0;
	}

	return a;
}

void Question1()
{
	int iInput = 0;

	cin >> iInput;

	for (int i = 0; i < iInput + 1; ++i)
	{
		for (int j = 0; j < (iInput * 2) + 1; ++j)
		{
			if ((iInput - i) <= j && (iInput + i) >= j)
				cout << POW(2, i - ABS(j - iInput)) << "\t";
			else
				cout << "\t";
		}
		cout << endl;
	}
}