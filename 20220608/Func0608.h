#pragma once

#define NOTNULLRETURN(t, n) if(t)*t=n;return n;
#define ABS(t) ((t) < 0 ? (t*-1):t)

double SQRT(double num);