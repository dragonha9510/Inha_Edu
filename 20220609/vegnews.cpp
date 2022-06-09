#include <iostream>

using std::cout;

#include "strngbad.h"

void callme1(CStringBad&);
void callme2(CStringBad);

int main()
{
	using std::endl;
	{
		cout << "���� ��� ����" << endl;
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

		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� �ʱ�ȭ: \n";
		CStringBad sailor = sports;
		cout << "sailor: " << sailor << endl;
		cout << "�ϳ��� ��ü�� �ٸ� ��ü�� ����: \n";
		CStringBad knot;
		knot = headline1;
		cout << "knot: " << knot << endl;
		cout << "���� ��� ��" << endl;
	}

	cout << "������ ��" << endl;

	return 0;
}

void callme1(CStringBad& rsb)
{
	cout << "���� ���� CStringBad:\n";
	cout << "	\"" << rsb << "\"\n";
}

void callme2(CStringBad sb)
{
	cout << "�� ���� CStringBad:\n";
	cout << "	\"" << sb << "\"\n";
}