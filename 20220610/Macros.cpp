#include "stdafx0610.h"

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