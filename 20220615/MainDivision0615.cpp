#include "stdafx0615.h"

int GaroduengSolution(int l, vector<int> v)
{
	int iResult = l / v.size();

	for (size_t i = 0; i < v.size(); ++i)
	{
		for (size_t j = i; j < v.size(); ++j)
		{
			if (v[i] > v[j])
			{
				int temp = v[i];
				v[i] = v[j];
				v[j] = temp;
			}
		}
	}

	for (size_t i = 0; i < v.size(); ++i)
	{
		int iTemp = 0;
		int iBack = 0;

		if (i == 0)
		{
			iBack = (0 - abs(0 - v[i]) - 1);

			if (i + 1 == v.size())
				iBack = abs(iBack) < (l + abs(l - v[i]) + 1) ? (l + abs(l - v[i]) + 1) : iBack;
			else
				iBack = (iBack < v[i + 1]) ? v[i + 1] : iBack;

		}
		else if (i + 1 == v.size())
			iBack = l + abs(l - v[i]) + 1;
		else
			iBack = v[i + 1];

		iTemp = (abs(v[i] - iBack) / 2);
		iTemp += ((abs(v[i] - iBack) % 2)) ? 1 : 0;

		if (iResult < iTemp)
			iResult = iTemp;
	}

	return iResult;
}

void Garodueng()
{
	cout << GaroduengSolution(15, vector<int>({ 15, 5, 3, 7, 9, 14, 0 })); // 3
	cout << GaroduengSolution(25, vector<int>({ 15, 5, 3, 7, 9, 14, 0 })); // 11
	//cout << GaroduengSolution(5, vector<int>({ 2, 5 })); // 2
	//cout << GaroduengSolution(1, vector<int>({ 0 })); // 2
	//cout << GaroduengSolution(5, vector<int>({ 5 })); // 6
	//cout << GaroduengSolution(5, vector<int>({ 0 })); // 6
	cout << GaroduengSolution(1, vector<int>({ 0, 1 })); // 6
}

double hmean(double a, double b) throw(CBad_hmean);
double gmean(double a, double b) throw(CBad_gmean);

int error4()
{
	double x, y, z;

	cout << "두 수 입력 : ";
	while (cin >> x >> y)
	{
		try {
			z = hmean(x, y);
			cout << x << ", " << y << "의 조화 평균은 " << z << "입니다. \n";
			cout << x << ", " << y << "의 기하 평균은 " << gmean(x, y) << "입니다. \n";
			cout << "다른 두 수를 입력하십시오 (끝내려면 q) : ";
		}

		catch (CBad_hmean& bg) {
			bg.mesg();
			cout << "다시 하십시오.\n";
			continue;
		}
		
		catch (CBad_gmean& hg) {
			cout << hg.mesg();
			cout << "Values used : " << hg.v1 << ", " << hg.v2 << endl;
			cout << "죄송합니다. 더 이상 진행할 수 없습니다.\n";
			break;
		}
	}

	cout << "프로그램 종료" << endl;

	return 0;
}

double hmean(double a, double b) throw(CBad_hmean)
{
	if (a == -b)
		throw CBad_hmean(a, b);

	return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) throw(CBad_gmean)
{
	if (a < 0 || b < 0)
		throw CBad_gmean(a, b);

	return sqrt(a * b);
}