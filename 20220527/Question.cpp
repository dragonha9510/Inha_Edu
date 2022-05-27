#include <iostream>
#include <vld.h>
#include <new>

using namespace std;

// Q1. AABB ( ���� �ܺ� �Ǵ� ���� )
/*/
#define HALFSCALE(t) t * 0.5f
#define ABS(t) (t < 0 ? t * -1.f : t)

namespace COLLISION
{
	enum AABB { COL, IN, OUT, AABBEND };
}

typedef struct rectPoint
{
	float fX1;
	float fX2;
	float fY1;
	float fY2;
}RECTPOINT;

typedef struct rect
{
	float fX;
	float fY;

	float fWidth;
	float fHeight;
}RECT;

COLLISION::AABB AABBCollision(const RECT& a, const RECT& b);

int main()
{
	RECT rcFirst;
	RECT rcSecond;

	cout << "ù ��° �簢��" << endl;
	cout << "��ǥ (x, y) -> �� -> ���� �� �Է�" << endl;
	cin >> rcFirst.fX >> rcFirst.fY >> rcFirst.fWidth >> rcFirst.fHeight;

	cout << endl;

	cout << "�� ��° �簢��" << endl;
	cout << "��ǥ (x, y) -> �� -> ���� �� �Է�" << endl;
	cin >> rcSecond.fX >> rcSecond.fY >> rcSecond.fWidth >> rcSecond.fHeight;

	cout << endl << "��� : ";

	switch (AABBCollision(rcFirst, rcSecond))
	{
	case COLLISION::COL:
		cout << "���ƴ�!" << endl;
		break;
	case COLLISION::IN:
		cout << "���ο� �ִ�!" << endl;
		break;
	case COLLISION::OUT:
		cout << "�Ȱ��ƴ�.." << endl;
		break;
	}

	return 0;
}

COLLISION::AABB AABBCollision(const RECT& a, const RECT& b)
{
	float AScale = a.fHeight * a.fWidth;
	float BScale = b.fHeight * b.fWidth;

	RECT Big = AScale < BScale ? b : a;
	RECT Small = AScale < BScale ? a : b;

	RECTPOINT BigPoint =
	{	Big.fX - HALFSCALE(Big.fWidth),
		Big.fX + HALFSCALE(Big.fWidth),
		Big.fY - HALFSCALE(Big.fHeight),
		Big.fY + HALFSCALE(Big.fHeight) };
	RECTPOINT SmallPoint =
	{ Small.fX - HALFSCALE(Small.fWidth),
		Small.fX + HALFSCALE(Small.fWidth),
		Small.fY - HALFSCALE(Small.fHeight),
		Small.fY + HALFSCALE(Small.fWidth) };

	// AABB �浹 Ȯ��
	bool CollisionA = false;
	bool CollisionB = false;

	if (ABS((a.fX - b.fX)) <= HALFSCALE(a.fWidth) + HALFSCALE(b.fWidth))
		CollisionA = true;
	
	if (ABS((a.fY - b.fY)) <= HALFSCALE(a.fHeight) + HALFSCALE(b.fHeight))
		CollisionB = true;

	if (CollisionA && CollisionB)
	{
		if (BigPoint.fX1 <= SmallPoint.fX1 && BigPoint.fX2 >= SmallPoint.fX2)
		{
			if (BigPoint.fY1 <= SmallPoint.fY1 && BigPoint.fY2 >= SmallPoint.fY2)
				return COLLISION::IN;
		}

		return COLLISION::COL;
	}

	return COLLISION::OUT;
}

//float fSmallScale = AScale < BScale ? AScale : BScale;

//RECT Big = AScale < BScale ? b : a;
//RECT Small = AScale < BScale ? a : b;


//float fCollisionScale =
//((HALFSCALE(a.fWidth) + HALFSCALE(b.fWidth)) - ABS((a.fX - b.fX)))
//* ((HALFSCALE(a.fHeight) + HALFSCALE(b.fHeight)) - ABS((a.fY - b.fY)));


/*/

// Q2. SphereCollision ( ���� �ܺ� �Ǵ� ���� )
/*/
#define ABS(t) ((t) < 0 ? (t) * -1.f : (t))

enum class SPHERECOL { COL, COLIN, COLOUT, SPHEREEND };

typedef struct point
{
	float x;
	float y;
}POINT;

typedef struct sphere
{
	POINT position;
	float fRadius;
}SPHERE;

float POW(float d);
float SQRT(float num);
SPHERECOL CollisionSphere(SPHERE& a, SPHERE& b);

int main()
{
	SPHERE spFirst;
	SPHERE spSecond;

	cout << "ù ��° ��" << endl;
	cout << "��ǥ (x, y) -> ������ �Է�" << endl;
	cin >> spFirst.position.x >> spFirst.position.y >> spFirst.fRadius;

	cout << endl;

	cout << "�� ��° ��" << endl;
	cout << "��ǥ (x, y) -> ������ �Է�" << endl;
	cin >> spSecond.position.x >> spSecond.position.y >> spSecond.fRadius;

	switch (CollisionSphere(spFirst, spSecond))
	{
	case SPHERECOL::COL:
		cout << "�浹." << endl;
		break;
	case SPHERECOL::COLIN:
		cout << "���ο� �ִ�." << endl;
		break;
	case SPHERECOL::COLOUT:
		cout << "�浹���� �ʾҴ�." << endl;
		break;
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

SPHERECOL CollisionSphere(SPHERE& a, SPHERE& b)
{
	float fDistX = ABS(a.position.x - b.position.x);
	float fDistY = ABS(a.position.y - b.position.y);
	float fSumRad = a.fRadius + b.fRadius;

	float fDistance = SQRT(POW(fDistX) + POW(fDistY));

	if (fDistance <= fSumRad)
	{
		if (fDistance + (a.fRadius < b.fRadius ? a.fRadius : b.fRadius) <= fSumRad)
			return SPHERECOL::COLIN;

		return SPHERECOL::COL;
	}

	return SPHERECOL::COLOUT;
}
//*/

const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
	double* pd1;
	double* pd2;

	cout << "new�� ��ġ ���� new�� ù ��° ȣ��:\n";
	pd1 = new double[N];
	pd2 = new(buffer)double[N];

	for (int i = 0; i < N; ++i)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;

	cout << "�޸� �ּ� :\n" << pd1 << " : ��\t" << (void*)buffer << " : ����" << endl;

	cout << "�޸� ���� :\n";
	
	for (int i = 0; i < N; ++i)
	{
		cout << i + 1 << "\t" << &pd1[i] << " / " << pd1[i] << "\t";
		cout << i + 1 << "\t" << &pd2[i] << " / " << pd2[i] << endl;
	}

	cout << "\nnew�� ��ġ ���� new�� �� ��° ȣ�� :\n";
	
	double* pd3 = nullptr;
	double* pd4 = nullptr;

	pd3 = new double[N];
	pd4 = new(buffer)double[N];

	for (int i = 0; i < N; ++i)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;

	cout << "�޸� ���� : \n";
	
	for (int i = 0; i < N; ++i)
	{
		cout << i + 1 << "\t" << &pd3[i] << " / " << pd3[i] << "\t";
		cout << i + 1 << "\t" << &pd4[i] << " / " << pd4[i] << endl;
	}

	cout << "\nnew�� ��ġ ���� new�� �� ��° ȣ��\n";
	delete[] pd1;
	pd1 = nullptr;

	pd1 = new double[N];
	pd2 = new(buffer + N * sizeof(double))double[N];

	for (int i = 0; i < N; ++i)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;

	cout << "�޸� ���� : \n";

	for(int i = 0; i < N; ++i)
	{
		cout << i + 1 << "\t" << &pd1[i] << " / " << pd1[i] << "\t";
		cout << i + 1 << "\t" << &pd2[i] << " / " << pd2[i] << endl;
	}

	delete[] pd1;
	delete[] pd3;

	system("pause");

	return 0;
}