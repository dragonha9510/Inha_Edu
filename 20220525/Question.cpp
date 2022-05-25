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

	cout << "첫번째 좌표 : ";
	cin >> a.x >> a.y;

	cout << "두번째 좌표 : ";
	cin >> b.x >> b.y;

	cout << "세번째 좌표 : ";
	cin >> c.x >> c.y;

	double dDistance[3];	// 삼각형 세변의 길이

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

//	 게임에서 비밀번호에 어떤 법칙을 요구하는 경우가있다.
//	다음과 같이 비밀번호를 만들어야 한다고 하자.
//	1. 비밀번호는 최소 8개의 문자
//	2. 비밀번호는 문자와 숫자만으로 구성
//	3. 비밀번호는 적어도 두개의 숫자가 포함

//	성공 시 valid password
//	실패 시 Invalid password
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


//	점 (x, y) 를 입력받아 그 점이 (x0, y0)을 중심으로 하고 반지름 r 인 원 내부에 존재하는지 검사하는 프로그램
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
		cout << "중점 입력" << endl;
		cout << "계속 : 1 종료 : 0" << endl;
		cin >> iSel;

		if (!iSel)
			break;

		cout << "중점 입력 (x, y순서) : ";
		cin >> poCenter.x >> poCenter.y;
		cout << "반지름 입력 : ";
		cin >> fRadius;

		while (true)
		{
			cout << "비교할 위치 : 중점" << PrintPoint(&poCenter) << " : 반지름 : " << fRadius << endl;
			cout << "계속 : 1 이전메뉴 : 0" << endl;
			cin >> iSel;

			if (!iSel)
				break;

			cout << "확인할 위치 입력 : ";
			cin >> poInput.x >> poInput.y;


			string strRes =
				CheckInCircle(&poInput, &poCenter, fRadius) ? "원 안에 있습니다." : "원 안에 없습니다.";

			cout << "result => 점 " << PrintPoint(&poInput) << " 는 중점이 "
				<< PrintPoint(&poCenter) << " 이고 반지름이 " << fRadius << " 인 " << strRes << endl;

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


// 선형 검색을 하기 위한 기본 순서도와 이를 바탕으로 선형 프로그램을 작성하라.
// Input : data : 6 5 2 1 8 9 7 4
// Output : search : 9 => 자료 중 9 가 있습니다.
/*/

bool FindData(int arrdata[], int size, int sour);
bool FindData2(int arrdata[], int size, int sour);

#define ARRMAXINDEX 100000000

int main()
{
	int* arrData = new int[ARRMAXINDEX];
	int iInputData = 0;
	
	int iCnt = 0;

	cout << "데이타 입력 (입력 종료 -1): ";

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
		cout << "검색 데이타 (종료 -1): ";
		cin >> iSearch;

		if (iSearch == -1)
			break;

		time_t tTime = clock();

		cout << "자료 중 " << iSearch;

		if (FindData(arrData, iCnt, iSearch))
			cout << " (이)가 있습니다." << endl;
		else
			cout << " (이)가 없습니다." << endl;
	
		cout << endl;
		cout << clock() - tTime << "ms 걸림" << endl;;
		cout << endl;
	
		tTime = clock();

		cout << "자료 중 " << iSearch;

		if (FindData2(arrData, iCnt, iSearch))
			cout << " (이)가 있습니다." << endl;
		else
			cout << " (이)가 없습니다." << endl;

		cout << endl;
		cout << clock() - tTime << "ms 걸림" << endl;
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
		cout << "검색 데이타 (종료 -1): ";
		cin >> iSearch;

		if (iSearch == -1)
			break;

		cout << "0. 일반선형  1. 보초법적용";
		cin >> bChange;

		time_t tTime = clock();
		g_sleeptime = 0;

		if (!bChange)
		{
			FindData(arrData, iCnt, iSearch);

			cout << "선형 검색!\n";
			cout << "걸린 시간 : ";
			cout << clock() - tTime - g_sleeptime << endl;
		}
		else
		{
			FindData2(arrData, iCnt, iSearch);

			cout << "보초법 적용!\n";
			cout << "걸린 시간 : ";
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
		cout << sour << " 탐색\n";

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
			cout << "찾았다!!" << endl;
			return true;
		}

		Sleep(50);
		g_sleeptime += 50;
		system("cls");
	}
	system("cls");
	cout << "못 찾았다.." << endl;

	return false;
}

bool FindData2(int arrdata[], int size, int sour)
{
	system("cls");

	arrdata[size] = sour;

	int i = 0;
	while (true)
	{
		cout << sour << " 탐색\n";

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
		cout << "못 찾았다.." << endl;
		return false;
	}

	cout << "찾았다!!" << endl;
	return true;
}