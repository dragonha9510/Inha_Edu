#include <iostream>

using std::cout;

#include "strngbad.h"

void callme1(CStringBad&);
void callme2(CStringBad);

int main()
{
	using std::endl;
	{
		cout << "내부 블록 시작" << endl;
		CStringBad headline1("Celery Stalks at Midnight");
		CStringBad headline2("Lettuce Prey");

		CStringBad sports("Spinach Leaves Bowl for Dollars");

		cout << "headline1: " << headline1 << endl;
		cout << "headline2: " << headline2 << endl;
		cout << "sports: " << sports << endl;

		callme1(headline1);
		cout << "headline1: " << headline1 << endl;
		callme2(headline2);
		cout << "headline2: " << headline2 << endl;

		cout << "하나의 객체를 다른 객체로 초기화: \n";
		CStringBad sailor = sports;
		cout << "sailor: " << sailor << endl;
		cout << "하나의 객체를 다른 객체에 대입: \n";
		CStringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "내부 블록 끝" << endl;
	}

	cout << "메인의 끝" << endl;

	return 0;
}

void callme1(CStringBad& rsb)
{
	cout << "참조 전달 CStringBad:\n";
	cout << "	\"" << rsb << "\"\n";
}

void callme2(CStringBad sb)
{
	cout << "값 전달 CStringBad:\n";
	cout << "	\"" << sb << "\"\n";
}