#include <iostream>
#include <windows.h>
#include <vld.h>

using namespace std;


//	선 1의 두 점 (x1, y1) 과 (x2, y2),
//  선 2의 두 점 (x3, y3) 과 (x4, y4) 가 주어진다.
//  두 선의 교차점을 구하는 프로그램을 작성하라.
/*/

typedef struct point
{
	double x;
	double y;

	bool operator==(point a)
	{
		if (x == a.x && y == a.y)
			return true;

		return false;
	}
	bool operator!=(point a)
	{
		if (x != a.x || y != a.y)
			return true;

		return false;
	}
	bool operator<(point a)
	{
		if (x < a.x && y < a.y)
			return true;

		return false;
	}
	bool operator>(point a)
	{
		if (x > a.x && y > a.y)
			return true;

		return false;
	}
	bool operator<=(point a)
	{
		if (x <= a.x && y <= a.y)
			return true;

		return false;
	}
	bool operator>=(point a)
	{
		if (x >= a.x && y >= a.y)
			return true;

		return false;
	}
}POINT;

bool GetCrossPoint(POINT a[], POINT* dest);
double POW(double d);
double SQRT(double num);
double GetDistance(POINT a, POINT b);
bool CheckSameLine(POINT a[]);
double GetDistance(POINT a, POINT b);

int main()
{
	POINT arr[4];

	for (int i = 0; i < 4; ++i)
	{
		cout << "x" << i + 1 << " y" << i + 1 << " 입력 : ";
		cin >> arr[i].x >> arr[i].y;
	}

	if (arr[0] == arr[1] || arr[2] == arr[3])
		cout << "선이 아닙니다." << endl;

	POINT poCrossPoint;

	if (CheckSameLine(arr))
	{
		if ((arr[0] == arr[2] || arr[0] == arr[3]) && (arr[1] != arr[2] && arr[1] != arr[3]))
			cout << "교차점 은 (" << arr[0].x << ", " << arr[0].y << ") 이다." << endl;
		else if ((arr[1] == arr[2] || arr[1] == arr[3]) && (arr[0] != arr[2] && arr[0] != arr[3]))
			cout << "교차점 은 (" << arr[1].x << ", " << arr[1].y << ") 이다." << endl;
		else
			cout << "두 선은 겹칩니다." << endl;
	}
	else if (!GetCrossPoint(arr, &poCrossPoint))
		cout << "두 선은 교차하지 않는다." << endl;
	else
		cout << "교차점 은 (" << poCrossPoint.x << ", " << poCrossPoint.y << ") 이다." << endl;

	return 0;
}

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

double GetDistance(POINT a, POINT b)
{
	return SQRT(POW(a.x - b.x) + POW(a.y - b.y));
}

bool CheckSameLine(POINT a[])
{
	double m = (a[0].y - a[1].y) / (a[0].x - a[1].x);
	double n = a[0].y - (m * a[0].x);

	double m2 = (a[2].y - a[3].y) / (a[2].x - a[3].x);
	double n2 = a[2].y - (m * a[2].x);

	bool bCheck = isfinite(m);
	bCheck = isnan(n);

	if (m == m2 && n == n2)
		return true;
	else if (isfinite(m) == isfinite(m2) && isnan(n) == isnan(n2) && !isfinite(m) && isnan(n))
		return true;

	int iCheckCnt = 0;

	for (int i = 2; i < 4; ++i)
	{
		if (a[i].y == (m * a[i].x) - n)
			++iCheckCnt;
	}

	if (iCheckCnt == 2)
	{
		double dFront = a[0].x < a[1].x ? a[0].x : a[1].x;
		double dBack = a[0].x < a[1].x ? a[1].x : a[0].x;

		double dFront2 = a[2].x < a[3].x ? a[2].x : a[3].x;
		double dBack2 = a[2].x < a[3].x ? a[3].x : a[2].x;

		if (dFront > dFront2 || dBack < dFront2)
		{
			if (dFront > dBack2 || dBack < dBack2)
				return false;
		}

		return true;
	}

	if ((a[0] == a[2] || a[0] == a[3]) && (a[1] != a[2] && a[1] != a[3]))
		return true;
	else if ((a[1] == a[2] || a[1] == a[3]) && (a[0] != a[2] && a[0] != a[3]))
		return true;
	return false;
}

bool GetCrossPoint(POINT a[], POINT* dest)
{
	double dX[2];
	double dY[2];
	double dLine[2];
	for (int i = 0; i < 2; ++i)
	{
		dY[i] = a[(i * 2) + 1].y - a[i * 2].y;
		dX[i] = a[i * 2].x - a[(i * 2) + 1].x;
		dLine[i] = (dY[i] * a[i * 2].x) + (dX[i] * a[i * 2].y);
	}

	double dDeterminant = (dY[0] * dX[1]) - (dY[1] * dX[0]);

	if (dDeterminant == 0)
		return false;

	double destX = ((dLine[0] * dX[1]) - (dX[0] * dLine[1]));
	double destY = ((dY[0] * dLine[1]) - (dLine[0] * dY[1]));

	dest->x = destX / dDeterminant;
	dest->y = destY / dDeterminant;

	for (int i = 0; i < 2; ++i)
	{
		POINT front = a[i * 2];
		POINT back = a[i * 2 + 1];

		if (front > back)
		{
			POINT temp = front;
			front = back;
			back = temp;
		}

		if (front > *dest || back < *dest)
		{
			return false;
		}
	}

	if (GetDistance(a[0], a[1]) < GetDistance(a[0], *dest) 
		|| GetDistance(a[2], a[3]) < GetDistance(a[3], *dest))
		return false;

	return true;
}

//*/

/*/
#define ARRAYMAX 5

template<typename T>
T maxn(T arr[], size_t size = ARRAYMAX);

template<>
const char* maxn<const char*>(const char* str[], size_t size);

template<typename T>
size_t makeArray(T*& arr);

template<>
size_t makeArray<char*>(char**& arr);

int main()
{
	int iArr[ARRAYMAX] = { 1,3,5,7,9 };
	double dArr[ARRAYMAX] = { 0.5,2.5,1.7,-3.5,-9.9 };

	cout << "원소 5개 최대 값" << endl;
	cout << "int 형 : " << maxn(iArr) << endl;
	cout << "double 형 : " << maxn(dArr) << endl;

	int* piArr = nullptr;
	double* pdArr = nullptr;

	size_t size = makeArray(piArr);

	cout << "int형 최대 값 : " << maxn(piArr, size) << endl;

	delete[] piArr;
	piArr = nullptr;

	size = makeArray(pdArr);

	cout << "double형 최대 값 : " << maxn(pdArr, size) << endl;

	delete[] pdArr;
	pdArr = nullptr;

	char** pchArr = nullptr;

	size = makeArray(pchArr);

	cout << "가장 긴 문자열 : " << maxn(pchArr, size) << endl;
	cout << "가장 긴 문자열의 주소 : " << reinterpret_cast<void*>(maxn(pchArr, size)) << endl;

	for (size_t i = 0; i < size; ++i)
	{
		delete[] pchArr[i];
		pchArr[i] = nullptr;
	}

	delete[] pchArr;
	pchArr = nullptr;

	return 0;
}

template<typename T>
T maxn(T arr[], size_t size)
{
	T max = 0;

	for (size_t i = 0; i < size; ++i)
	{
		if (max < arr[i])
			max = arr[i];
	}

	return max;
}

template<>
char* maxn<char*>(char* str[], size_t size)
{
	size_t max = 0;
	int iRes = 0;
	for (size_t i = 0; i < size; ++i)
	{
		size_t len = strlen(str[i]);

		if (max < len)
		{
			max = len;
			iRes = i;
		}
	}

	return str[iRes];
}

template<>
size_t makeArray<char*>(char**& arr)
{
	size_t iSize = 0;

	cout << "배열 크기 입력 : ";
	cin >> iSize;

	arr = new char*[iSize];

	if (arr == nullptr)
		exit(-1);

	cout << "원소 입력 : ";
	for (size_t i = 0; i < iSize; ++i)
	{
		char tempstr[255];
		cin >> tempstr;
		
		int iCnt = 0;
		for (int j = 0; tempstr[j] != '\0'; ++j)
			++iCnt;

		arr[i] = new char[iCnt + 1];
		strcpy_s(arr[i], iCnt + 1, tempstr);
	}

	return iSize;
}

template<typename T>
size_t makeArray(T*& arr)
{
	size_t iSize = 0;

	cout << "배열 크기 입력 : ";
	cin >> iSize;

	arr = new T[iSize];

	if (arr == nullptr)
		exit(-1);

	cout << "원소 입력 : ";
	for (size_t i = 0; i < iSize; ++i)
	{
		cin >> arr[i];
	}

	return iSize;
}

//*/

/*/

#define ARRAYNUM 44

void sorting(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		if (arr[i] > arr[i + 1])
		{
			int temp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = temp;
			i = -1;
		}
	}
}

int search_idx(const int arr[], int size, int n)
{
	int iKey = size;
	int iNextkey = size / 2;

	bool bInit = false;

	iKey -= iNextkey;

	while (true)
	{
		system("cls");

		cout << "   ";

		for (int i = 0; i < size; ++i)
		{
			cout << i << " ";
			if (i < 10)
				cout << ' ';
		}
		cout << endl;

		cout << "   ";

		for (int i = 0; i < iKey - iNextkey; ++i)
			cout << "   ";
		for (int i = iKey - iNextkey; i < iKey + iNextkey + 1; ++i)
		{
			if (i < 0)
				continue;

			if (i == iKey)
				cout << "+  ";
			else if (i == iKey - iNextkey)
				cout << "<= ";
			else if (i == iKey + iNextkey - 1)
			{
				if (!bInit)
				{
					cout << "=> ";
					bInit = true;
					++i;
				}
				else
					cout << "   ";
			}
			else if (bInit && i == iKey + iNextkey)
				cout << "=> ";
			else
				cout << "   ";
		}

		cout << endl;

		if(iKey < 10)
			cout << iKey << "  ";
		else
			cout << iKey << " ";

		for (int i = 0; i < size; ++i)
		{
			cout << arr[i] << ' ';
			if (i + 1 < 10)
				cout << ' ';
		}

		Sleep(500);

		if (arr[iKey] == n)
			return iKey;

		iNextkey /= 2;

		if (iNextkey == 0)
		{
			if (iKey == size - 1 || iKey == 0)
				return -1;

			iNextkey = 1;
		}

		iKey = n < arr[iKey] ? iKey - iNextkey : iKey + iNextkey;
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	system("cls");

	int iArr[ARRAYNUM];

	for (int i = 0; i < ARRAYNUM; ++i)
	{
		iArr[i] = (rand() % ARRAYNUM) + 1;

		cout << iArr[i] << ' ';
		if (i + 1 < 10)
			cout << ' ';
	}

	sorting(iArr, ARRAYNUM);

	int iWantSearch = 0;

	cin >> iWantSearch;

	int iResult = search_idx(iArr, ARRAYNUM, iWantSearch);

	cout << endl;

	if (iResult == -1)
		cout << "검색 결과가 존재하지 않습니다." << endl;
	else
		cout << "iArr[" << iResult << "] 에 있습니다." << endl;

	return 0;
}

//*/