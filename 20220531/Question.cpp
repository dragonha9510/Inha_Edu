#include "stdafx.h"

using namespace std;

//	Q1.	�б��� 100���� �繰�԰� 100���� �л��� �ִ�.
//		��� �繰���� ù ������ �����ִ�.
//		�л��� ���Ƿ� ���鼭
//		s1 �̶�� ù ��° �л��� ��� �繰���� ����.
//		s2 ��� �� ��° �л��� �繰�� L2���� �����Ͽ� �ϳ��� �ǳ� �ٸ鼭 �繰���� �ݴ´�.
//		s3 ��� �� ��° �л��� �繰�� L3���� �����Ͽ� ����° �繰�� ���� ���¸� �����Ѵ�.
//		������ �л����� ��� ���� �� �����ִ� �繰���� ����ϴ� ���α׷� �ۼ�
/*/
#define MAXSTUDENT 100

int main()
{
	for (int i = 0; (i + 1) * (i + 1) <= MAXSTUDENT; ++i)
		cout << "L" << i + 1 << "��������" << endl;

	return 0;
}
//*/

//	Q2.  �� p0(x0, y0) �� ���� p1(x1, y1) ������ ������ �־����� ��
//		�� p2(x2, y2) �� ���� ���� �Ǵ� �����ʿ� �ִ��� �Ǵ��ؼ� ����ϴ� ���α׷�
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
		cout << "����";
	else if (fRes < 0)
		cout << "������";
	else
		cout << "���";

	return 0;
}
//*/

//#define PI 3.14159265358979323846264338327950288419716939937510582097494459230781640262862089986280348253421170679821480865132823066470938446095505822317253594081284811174502841027f
//  Q3.	 �ﰢ���� �� ���� ���̸� �˸� ������ ������ ���� �� �ִ�.
//		�ﰢ���� �� ������ x, y��ǥ�� �Է¹��� �� �ﰢ���� ������ ����ϴ� ���α׷��� �ۼ��϶�.
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

	
	cout << "�� ���� " 
		<< RADIANTODEGREE(acosf(fCosA)) << " , "
		<< RADIANTODEGREE(acosf(fCosB)) << " , "
		<< RADIANTODEGREE(acosf(fCosC)) << " �̴�.";

	return 0;
}
//*/