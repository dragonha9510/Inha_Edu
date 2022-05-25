#include <iostream>
#include <array>
#include <string>

using namespace std;

/*/
const int Seasons = 4;
const array<string, Seasons> sname = { "spring", "summer", "fall", "winter" };

void fill(array<double, Seasons>* pa);
void show(array<double, Seasons> da);

int main()
{
	array<double, Seasons> expenses;

	fill(&expenses);
	show(expenses);

	return 0;
}

void fill(array<double, Seasons>* pa)
{
	for (int i = 0; i < Seasons; ++i)
	{
		cout << sname[i] << "에 소용되는 비용 : ";
		cin >> (*pa)[i];
	}
}

void show(array<double, Seasons> da)
{
	double total = 0.0;

	cout << "\n계절별 비용\n";
	for (int i = 0; i < Seasons; ++i)
	{
		cout << sname[i] << " : $ " << da[i] << endl;
		total += da[i];
	}

	cout << "총 비용 : $ " << total << endl;
}

//*/


//*/

const double* f1(const double ar[], int n);
const double* f2(const double[], int);
const double* f3(const double*, int);

int main()
{
	double av[3] = { 1112.3, 1542.6, 2227.9 };

	const double* (*p1)(const double*, int) = f1;
	auto p2 = f2;
	
	cout << "함수 포인터 \t" << (*p1)(av, 3) << " : " << *(*p1)(av, 3) << endl;
	cout << "\t\t" << p2(av, 3) << " : " << *p2(av, 3) << endl;

	const double* (*pa[3])(const double*, int) = { f1, f2, f3 };

	auto pb = pa;

	cout << "\n 함수 포인터를 원소로 가지는 배열 : \n";
	for (int i = 0; i < 3; ++i)
		cout << "\t\t" << pa[i](av, 3) << " : " << *pa[i](av, 3) << endl;

	cout << "\n 함수 포인터를 가리키는 포인터 : \n";
	for (int i = 0; i < 3; ++i)
		cout << "\t\t" << pb[i](av, 3) << " : " << *pb[i](av, 3) << endl;

	auto pc = &pa;

	cout << (*pc)[0](av, 3) << " : " << *(*pc)[0](av, 3) << endl;
	
	const double* (*(*pd)[3])(const double*, int) = &pa;

	const double* pdb = (*pd)[1](av, 3);
	cout << pdb << " : " << *pdb << endl;

	cout << (*(*pd)[2])(av, 3) << " : " << *(*(*pd)[2])(av, 3) << endl;

	return 0;
}

const double* f1(const double* ar, int n) 
{
	return ar;
}
const double* f2(const double ar[], int n)
{
	return ar + 1;
}
const double* f3(const double ar[], int n)
{
	return ar + 2;
}

//*/