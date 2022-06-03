#include "stdafx.h"

using namespace std;

//	Q1.	학교에 100개의 사물함과 100명의 학생이 있다.
//		모든 사물함은 첫 날에는 닫혀있다.
//		학생이 교실로 들어가면서
//		s1 이라는 첫 번째 학생은 모든 사물함을 연다.
//		s2 라는 두 번째 학생은 사물함 L2부터 시작하여 하나씩 건너 뛰면서 사물함을 닫는다.
//		s3 라는 세 번째 학생은 사물함 L3부터 시작하여 세번째 사물함 마다 상태를 변경한다.
//		마지막 학생까지 모두 들어갔을 때 열려있는 사물함을 출력하는 프로그램 작성
/*/
#define MAXSTUDENT 100

int main()
{
	for (int i = 0; (i + 1) * (i + 1) <= MAXSTUDENT; ++i)
		cout << "L" << i + 1 << "열려있음" << endl;

	return 0;
}
//*/

//	Q2.  점 p0(x0, y0) 로 부터 p1(x1, y1) 까지의 직선이 주어졌을 때
//		점 p2(x2, y2) 가 선의 왼쪽 또는 오른쪽에 있는지 판단해서 출력하는 프로그램
/*/
typedef struct mypoint
{
	float x;
	float y;

	mypoint operator-(mypoint a)
	{
		mypoint temp;
		temp.x = this->x - a.x;
		temp.y = this->y - a.y;

		return temp;
	}

	mypoint operator=(mypoint a)
	{
		this->x = a.x;
		this->y = a.y;

		return *this;
	}
}MYPOINT;

int main()
{
	MYPOINT a, b, c;

	cin >> a.x >> a.y;
	cin >> b.x >> b.y;
	cin >> c.x >> c.y;

	c = c - a;
	b = b - a;

	float fRes = (b.x * c.y) - (b.y * c.x);

	if (fRes > 0)
		cout << "왼쪽";
	else if (fRes < 0)
		cout << "오른쪽";
	else
		cout << "가운데";

	return 0;
}
//*/

//#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640262862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027f
//  Q3.	 삼각형의 세 변의 길이를 알면 세개의 내각을 구할 수 있다.
//		삼각형의 세 꼭짓점 x, y좌표를 입력받은 후 삼각형의 각도를 계산하는 프로그램을 작성하라.
//*/
#define PI 3.1415926535897932384626f
#define POW(t) (t * t)
#define RADIANTODEGREE(t) t * 180.f / PI 

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

class CPoint
{
public:
	CPoint() {}
	~CPoint() {}

private:
	CPoint operator-(CPoint a)
	{
		CPoint temp;
		temp.x = this->x - a.x;
		temp.y = this->y - a.y;

		return temp;
	}
	CPoint operator=(CPoint a)
	{
		this->x = a.x;
		this->y = a.y;

		return *this;
	}

public:
	float GetDistance(CPoint* Dest)
	{
		CPoint Temp = (*this) - *Dest;

		float fDistance = SQRT(POW(Temp.x) + POW(Temp.y));

		return fDistance;
	}
	void SetXY(float X, float Y)
	{
		x = X;
		y = Y;
	}

private:
	float x = 0;
	float y = 0;
};

int main()
{
	CPoint point[3];

	for (int i = 0; i < 3; ++i)
	{
		float iX, iY;

		cin >> iX >> iY;
		point[i].SetXY(iX, iY);
	}

	float fSide[3] =
	{ 
		point[0].GetDistance(&point[1]),
		point[1].GetDistance(&point[2]),
		point[2].GetDistance(&point[0]) 
	};

	float fCosA = (POW(fSide[2]) + POW(fSide[0]) - POW(fSide[1])) / (2.f * fSide[2] * fSide[0]);
	float fCosB = (POW(fSide[0]) + POW(fSide[1]) - POW(fSide[2])) / (2.f * fSide[0] * fSide[1]);
	float fCosC = (POW(fSide[1]) + POW(fSide[2]) - POW(fSide[0])) / (2.f * fSide[1] * fSide[2]);

	
	cout << "세 각은 " 
		<< RADIANTODEGREE(acosf(fCosA)) << " , "
		<< RADIANTODEGREE(acosf(fCosB)) << " , "
		<< RADIANTODEGREE(acosf(fCosC)) << " 이다.";

	return 0;
}
//*/