#include <iostream>
#include <string>
#include <math.h>
#include <windows.h>
#include <vector>

using namespace std;

/*/

typedef struct point
{
	double x;
	double y;
}POINT;

double POW(double d)
{
	return d * d;
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

#define GETDISTANCE_POINT(t, q) SQRT(POW(t.x - q.x) + POW(t.y - q.y))

int main()
{
	POINT a, b, c;

	cout << "ù��° ��ǥ : ";
	cin >> a.x >> a.y;

	cout << "�ι�° ��ǥ : ";
	cin >> b.x >> b.y;

	cout << "����° ��ǥ : ";
	cin >> c.x >> c.y;

	double dDistance[3];	// �ﰢ�� ������ ����

	dDistance[0] = GETDISTANCE_POINT(a, b);
	dDistance[1] = GETDISTANCE_POINT(b, c);
	dDistance[2] = GETDISTANCE_POINT(c, a);

	double dSum = 0;
	for (int i = 0; i < 3; ++i)
		dSum += dDistance[i];

	double dS = dSum * 0.5;

	double dRes = SQRT(dS * (dS - dDistance[0]) * (dS - dDistance[1]) * (dS - dDistance[2]));

	cout << dRes;

	return 0;
}

//*/

//	 ���ӿ��� ��й�ȣ�� � ��Ģ�� �䱸�ϴ� ��찡�ִ�.
//	������ ���� ��й�ȣ�� ������ �Ѵٰ� ����.
//	1. ��й�ȣ�� �ּ� 8���� ����
//	2. ��й�ȣ�� ���ڿ� ���ڸ����� ����
//	3. ��й�ȣ�� ��� �ΰ��� ���ڰ� ����

//	���� �� valid password
//	���� �� Invalid password
/*/
#define LESSCHARS 2
#define LESSDIGITS 2
#define LESSLENGTH 8

#define ISDIGIT(t) t >= '0' && t <= '9'
#define ISALPHA(t) (t >= 'a' && t <= 'z') || (t >= 'A' && t <= 'Z')

bool CheckPassword(string pass)
{
	size_t iLength = pass.length();
	
	if (iLength < LESSLENGTH)
		return false;

	int iChars	= 0;
	int iDigits = 0;
	int iOthers = 0;

	for (size_t i = 0; i < iLength; ++i)
	{
		if (ISALPHA(pass[i]))
			++iChars;
		else if (ISDIGIT(pass[i]))
			++iDigits;
		else
			++iOthers;
	}

	if (iOthers)
		return false;
	else if (iChars < LESSCHARS)
		return false;
	else if (iDigits < LESSDIGITS)
		return false;

	return true;
}

int main()
{
	string password;

	while (1)
	{
		cin >> password;

		if (CheckPassword(password))
		{
			cout << "Valid Password" << endl;
			return 0;
		}
		else
			cout << "Invalid Password" << endl;

		system("pause");
		system("cls");
	}

	return 0;
}
//*/


//	�� (x, y) �� �Է¹޾� �� ���� (x0, y0)�� �߽����� �ϰ� ������ r �� �� ���ο� �����ϴ��� �˻��ϴ� ���α׷�
/*/

typedef struct point
{
	float x;
	float y;
}POINT;

string PrintPoint(POINT* pt)
{
	string strPoint = "( ";
	strPoint += to_string(pt->x);
	strPoint += ", ";
	strPoint += to_string(pt->y);
	strPoint += " )";

	return strPoint;
}

float POW(float d);
float SQRT(float num);
bool CheckInCircle(POINT* sour, POINT* center, float radius);

int main()
{
	float fRadius = 0;
	POINT poCenter = {};
	POINT poInput = {};

	int iSel = 0;

	while (true)
	{
		cout << "���� �Է�" << endl;
		cout << "��� : 1 ���� : 0" << endl;
		cin >> iSel;

		if (!iSel)
			break;

		cout << "���� �Է� (x, y����) : ";
		cin >> poCenter.x >> poCenter.y;
		cout << "������ �Է� : ";
		cin >> fRadius;

		while (true)
		{
			cout << "���� ��ġ : ����" << PrintPoint(&poCenter) << " : ������ : " << fRadius << endl;
			cout << "��� : 1 �����޴� : 0" << endl;
			cin >> iSel;

			if (!iSel)
				break;

			cout << "Ȯ���� ��ġ �Է� : ";
			cin >> poInput.x >> poInput.y;


			string strRes =
				CheckInCircle(&poInput, &poCenter, fRadius) ? "�� �ȿ� �ֽ��ϴ�." : "�� �ȿ� �����ϴ�.";

			cout << "result => �� " << PrintPoint(&poInput) << " �� ������ "
				<< PrintPoint(&poCenter) << " �̰� �������� " << fRadius << " �� " << strRes << endl;

			system("pause");
			system("cls");
		}
	}
	return 0;
}

float POW(float d)
{
	return d * d;
}

float SQRT(float num)
{
	float a = 0, b = 0;

	a = num / 2.0f;

	while (a != b)
	{
		b = a;
		a = ((num / b) + b) / 2.0f;
	}

	return a;
}

bool CheckInCircle(POINT* sour, POINT* center, float radius)
{
	float fDistance = SQRT(POW(sour->x - center->x) + POW(sour->y - center->y));

	return fDistance <= radius ? true : false;
}


//*/


// ���� �˻��� �ϱ� ���� �⺻ �������� �̸� �������� ���� ���α׷��� �ۼ��϶�.
// Input : data : 6 5 2 1 8 9 7 4
// Output : search : 9 => �ڷ� �� 9 �� �ֽ��ϴ�.
/*/

bool FindData(int arrdata[], int size, int sour);
bool FindData2(int arrdata[], int size, int sour);

#define ARRMAXINDEX 100000000

int main()
{
	int* arrData = new int[ARRMAXINDEX];
	int iInputData = 0;
	
	int iCnt = 0;

	cout << "����Ÿ �Է� (�Է� ���� -1): ";

	while (true)
	{
		arrData[iCnt] = iCnt + 1;
		++iCnt;

		if (iCnt == ARRMAXINDEX - 1)
			break;
	}

	int iSearch = 0;

	while (true)
	{
		cout << "�˻� ����Ÿ (���� -1): ";
		cin >> iSearch;

		if (iSearch == -1)
			break;

		time_t tTime = clock();

		cout << "�ڷ� �� " << iSearch;

		if (FindData(arrData, iCnt, iSearch))
			cout << " (��)�� �ֽ��ϴ�." << endl;
		else
			cout << " (��)�� �����ϴ�." << endl;
	
		cout << endl;
		cout << clock() - tTime << "ms �ɸ�" << endl;;
		cout << endl;
	
		tTime = clock();

		cout << "�ڷ� �� " << iSearch;

		if (FindData2(arrData, iCnt, iSearch))
			cout << " (��)�� �ֽ��ϴ�." << endl;
		else
			cout << " (��)�� �����ϴ�." << endl;

		cout << endl;
		cout << clock() - tTime << "ms �ɸ�" << endl;
		cout << endl;
	}

	delete[] arrData;
	arrData = nullptr;
}

bool FindData(int arrdata[], int size, int sour)
{
	for (int i = 0; i < size; ++i)
	{
		if (arrdata[i] == sour)
			return true;
	}

	return false;
}

bool FindData2(int arrdata[], int size, int sour)
{
	arrdata[size] = sour;

	int i = 0;
	while (true)
	{
		if (arrdata[i] == sour)
			break;
		++i;
	}

	if (i == size)
		return false;
	else
		return true;
}

//*/

bool FindData(int arrdata[], int size, int sour);
bool FindData2(int arrdata[], int size, int sour);

#define ARRMAXINDEX 19

time_t g_sleeptime = 0;

int main()
{
	int* arrData = new int[ARRMAXINDEX];
	int iCnt = 0;

	while (true)
	{
		arrData[iCnt] = iCnt + 1;
		++iCnt;

		if (iCnt == ARRMAXINDEX - 1)
			break;
	}

	int iSearch = 0;
	bool bChange = true;
	while (true)
	{
		cout << "�˻� ����Ÿ (���� -1): ";
		cin >> iSearch;

		if (iSearch == -1)
			break;

		cout << "0. �Ϲݼ���  1. ���ʹ�����";
		cin >> bChange;

		time_t tTime = clock();
		g_sleeptime = 0;

		if (!bChange)
		{
			FindData(arrData, iCnt, iSearch);

			cout << "���� �˻�!\n";
			cout << "�ɸ� �ð� : ";
			cout << clock() - tTime - g_sleeptime << endl;
		}
		else
		{
			FindData2(arrData, iCnt, iSearch);

			cout << "���ʹ� ����!\n";
			cout << "�ɸ� �ð� : ";
			cout << clock() - tTime - g_sleeptime << endl;
		}
	}

	delete[] arrData;
	arrData = nullptr;
}

bool FindData(int arrdata[], int size, int sour)
{
	system("cls");

	for (int i = 0; i < size; ++i)
	{	
		cout << sour << " Ž��\n";

		for (int j = 0; j < size; ++j)
		{
			if (i == j)
			{
				cout << "*" << endl;
				break;
			}
			else
				cout << '\t';
		}
		for (int j = 0; j < size; ++j)
		{
			cout << arrdata[j] << '\t';
		}
		cout << endl;

		if (arrdata[i] == sour)
		{
			system("cls");
			cout << "ã�Ҵ�!!" << endl;
			return true;
		}

		Sleep(50);
		g_sleeptime += 50;
		system("cls");
	}
	system("cls");
	cout << "�� ã�Ҵ�.." << endl;

	return false;
}

bool FindData2(int arrdata[], int size, int sour)
{
	system("cls");

	arrdata[size] = sour;

	int i = 0;
	while (true)
	{
		cout << sour << " Ž��\n";

		for (int j = 0; j < size + 1; ++j)
		{
			if (i == j)
			{
				cout << "*" << endl;
				break;
			}
			else
				cout << '\t';
		}
		for (int j = 0; j < size + 1; ++j)
		{
			cout << arrdata[j] << '\t';
		}
		cout << endl;

		if (arrdata[i] == sour)
			break;
		++i;

		Sleep(50);
		g_sleeptime += 50;
		system("cls");
	}

	system("cls");

	if (i == size)
	{
		cout << "�� ã�Ҵ�.." << endl;
		return false;
	}

	cout << "ã�Ҵ�!!" << endl;
	return true;
}