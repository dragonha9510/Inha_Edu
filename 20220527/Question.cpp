#include <iostream>
#include <vld.h>
#include <map>
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

// Q3. ������ �鸸 �� ������ ���� �ùķ��̼� �ϰ�
//		�ո�� �޸��� ���� ����ϴ� ���α׷� �ۼ�.
/*/
#define MILLION 100

int POW(int a, int b)
{
	int res = 1;

	for (int i = 0; i < b; ++i)
		res *= a;

	return res;
}

int main()
{
	srand((unsigned int)time(NULL));

	int iFront = 0;
	int iBack = 0;
	int iCheckPrint = 0;
	int iCnt = 0;

	while (true)
	{
		iFront = 0;
		iBack = 0;
		iCheckPrint = 0;
		iCnt = 0;

		for (int i = 0; i < MILLION; ++i)
		{
			//if (i == iCheckPrint)
			//{
			//	//if (i != 0)
			//	//{
			//	//	cout << i << " ��°.. \t�ո� : " << ((double)iFront / (double)(iFront + iBack)) * 100.0 <<
			//	//		"% \t�޸� : " << ((double)iBack / (double)(iFront + iBack)) * 100.0 << "%" << endl;
			//	//}

			//	iCheckPrint = POW(10, ++iCnt);
			//}

			if (rand() % 2)
				++iFront;
			else
				++iBack;

		}

		cout << MILLION << " ��°.. \t�ո� : " << ((double)iFront / (double)MILLION) * 100.0 <<
			"% \t�޸� : " << ((double)iBack / (double)MILLION) * 100.0 << "%" << endl;

		if ((double)iFront / (double)MILLION >= 60.0 || (double)iBack / (double)MILLION >= 60.0)
			break;
	}
	return 0;
}
//*/

// Q4. ������ ����� ������ ���� ��
//	���		������		Ȯ��		������		Ȯ��
//	5star	A			1%
//	4star	B			3		C			3
//  3star	D			5		E			5
//			F			5
//	2star	G			10		H			10
//			I			10		J			10
//	1star	K			38
//*/

#define MAXPERCENT 100.0

enum ITEM { A, B, C, D, E, F, G, H, I, J, K, ITEM_END };

int main()
{
	srand((unsigned int)time(NULL));

	int iCase = 0;
	int iCurPercent = 0;
	string strItemName = "ABCDEFGHIJK";
	const int iItemOri[ITEM_END] = { 1,3,3,5,5,5,10,10,10,10,38 };
	int iItemCur[ITEM_END] = { 1,3,3,5,5,5,10,10,10,10,38 };
	int iItemRes[ITEM_END] = {};

	cout << "�ݺ� Ƚ��";
	cin >> iCase;

	double dByOne = (double)iCase / MAXPERCENT;

	while (dByOne > 0)
	{
		int iN = iCase > (int)MAXPERCENT ? (int)MAXPERCENT : iCase;
		int iMax = (int)MAXPERCENT;

		for (int i = 0; i < iN; ++i)
		{
			int iChoose = rand() % iMax;

			for (int j = 0; j < ITEM_END; ++j)
			{
				iCurPercent += iItemCur[j];
				 
				if (iChoose < iCurPercent)
				{
					--iMax;
					--iItemCur[j];
					++iItemRes[j];
					iCurPercent = 0;
					break;
				}
			}
		}

		memcpy(iItemCur, iItemOri, sizeof(int) * ITEM_END);
		--dByOne;
		iCase -= (int)MAXPERCENT;
	}

	// result ���
	for (int i = 0; i < ITEM_END; ++i)
		cout << strItemName[i] << " ������\t" << iItemRes[i] << endl;
}

//*/

// Q5. p.128 ���� 9. bsearchx() �Լ��� �����϶� ( ������ ���� )
/*/

#define ABS(t) (t) < 0 ? (t) * -1 : t

int int_cmp(const int* a, const int* b);
void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*));

int main()
{
	int* pArr = 0;
	int iSize = 0;
	int iSearch = 0;

	cout << "�迭 ũ�� : ";
	cin >> iSize;

	pArr = new int[iSize];

	cout << "���� �Է� : ";

	for (int i = 0; i < iSize; ++i)
	{
		do 
		{
			cin >> pArr[i];
		} while (pArr[i] < pArr[i - 1]);
	}

	cout << "�˻� �� �� : ";
	cin >> iSearch;

	int* pRes = nullptr;
	pRes = ((int*)bsearchx(&iSearch, pArr, iSize, sizeof(int), (int(*)(const void*, const void*))int_cmp));

	cout << endl;
	cout << "���̽� ���� �ּ� : " << pArr << endl;
	
	if (pRes == nullptr)
		cout << "ã�� ���� �����ϴ�." << endl;
	else
	{
		cout << "���� �� ��� �� : " << *pRes << endl;
		cout << "���� �� ��� �ּ� : " << pRes << endl;
	}

	delete[] pArr;
	pArr = nullptr;

	return 0;
}

int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

void* bsearchx(const void* key, const void* base, size_t nmemb, size_t size, int(*compare)(const void*, const void*))
{
	int front = 0;
	int back = nmemb - 1;
	int Index = back / 2;
	int iCnt = 0;
	bool bFind = false;

	while (true)
	{
		switch (compare(key, ((int*)base + Index)))
		{
		case -1:
			back = Index - 1;
			break;
		case 0:
			bFind = true;
			break;
		case 1:
			front = Index + 1;
			break;
		}

		if (ABS((front - back)) == 1)
		{
			++iCnt;

			if (iCnt == 2)
				return nullptr;
		}

		if (bFind)
			break;

		Index = front + ((back - front) / 2);
	}

	int iRes = Index;

	for (int i = Index; *((int*)base + i) == *((int*)base + Index); --i)
		iRes = i;
	
	return ((int*)base + iRes);
}

//*/