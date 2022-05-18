#include <iostream>

using namespace std;

//Q1. Ű�� ������ cm ������ ���� �� ���� m, cm ������ ��ȯ�ϴ� ������ ���α׷�
/*/
int main()
{
	int iHeightCM = 0;

	cout << "Ű�� �Է��ϼ��� (cm) : ";
	cin >> iHeightCM;

	cout << iHeightCM / 100 << "m " << iHeightCM % 100 << "cm" << endl;

	return 0;
}
//*/

//Q2. ������ ����, �а�, �ʰ� ������ ��û, 10���� �������� ����ϴ� ���α׷� �ۼ�
//	1�а��� 60�ʰ� 1������ 60�а�
/*/
#define UNIT 60.0f

int main()
{
	float fDegree	= 0.f;
	float fMinutes  = 0.f;
	float fSeconds  = 0.f;
	float fResult	= 0.f;

	cout << "������ ��, ��, �� ������ �Է��Ͻÿ� :\n";
	cout << "����, ������ �Է��Ͻÿ� : ";
	cin >> fDegree;
	cout << "������, �а��� �Է��Ͻÿ� : ";
	cin >> fMinutes;
	cout << "������, �ʰ��� �Է��Ͻÿ� : ";
	cin >> fSeconds;

	fResult = fDegree + ((fMinutes / UNIT) + ((fSeconds / UNIT) / UNIT));

	cout << fDegree << "��, " << fMinutes << "��," << fSeconds << "�� = " << fResult << "��";

	return 0;
}
//*/

//Q3. 
/*/
int main()
{
	long long llWorld = 0;
	long long llAmerica = 0;

	cout << "���� �α����� �Է��Ͻÿ� : ";
	cin >> llWorld;

	cout << "�̱��� �α����� �Է��Ͻÿ� : ";
	cin >> llAmerica;

	float fPopulation = ((float)llAmerica / (float)llWorld) * 100.f;

	cout << "���� �α����� �̱��� �����ϴ� ������ " << fPopulation << "% �̴�." << endl;

	return 0;
}
//*/

//Q4.
/*/
#define EUTOAMERICA(t) 62.14f / (t / 3.875f)

int main()
{
	float fLitter = 0;
	cin >> fLitter;

	cout << (int)(EUTOAMERICA(fLitter));

	return 0;
}

//*/

// Q5.
//*/
int Max4(int a, int b, int c, int d)
{
	int iArr[3] = { b,c,d };
	int iMax = a;

	for (int i = 0; i < 3; ++i)
	{
		if (iMax < iArr[i])
			iMax = iArr[i];
	}

	return iMax;
}

int med3(int a, int b, int c)
{
	int	iRes = a < b ? (c < a ? a : (b < c ? b : c)) : (c < b ? b : (a < c ? a : c));

	return iRes;
}

int main()
{
	int iA, iB, iC;

	cin >> iA >> iB >> iC;

	cout << med3(iA, iB, iC);

	return 0;
}
//*/