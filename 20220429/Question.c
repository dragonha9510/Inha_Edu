#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Q1.	 ��� ��ȯ
//		������ ���� A����� B��İ� ���� ���°� �ǵ��� �϶�.
//
//		A			B			A			B
//		1 2 3 4		5 1			1 2 3		7 4 1
//      5 6 7 8		6 2			4 5 6		8 5 2
//					7 3			7 8 9		9 6 3
//					8 4
/*/
#define ARR2DSIZE		3			// �� ���� �迭�� ������
#define ARRSIZE			3			// �迭�� Index�� �� ������
#define REALCOUNT(t)	t + 1		// ��ǻ�ʹ� 0 ���� ����� 1 ���� 

int main()
{
	int iArr[ARR2DSIZE][ARRSIZE] = { 0 };			// ���� �迭
	int iRes[ARRSIZE][ARR2DSIZE] = { 0 };			// 2, 4 -> 4, 2 �迭 ����

	for (int i = 0; i < ARR2DSIZE; ++i)				// iArr�� �� �ο� �ϸ鼭 iRes �� Rotation
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			iArr[i][j] = (i * ARRSIZE) + REALCOUNT(j);
			iRes[j][ARR2DSIZE - REALCOUNT(i)] = iArr[i][j];
		}
	}

	for (int i = 0; i < ARRSIZE; ++i)		// ��� ���
	{
		for (int j = 0; j < ARR2DSIZE; ++j)
		{
			printf("%d\t", iRes[i][j]);
		}

		printf("\n");	// ���� ������ ����
	}

	return 0;
}
//*/

// Q2.	 �迭�� ���ڸ� ������ ���� ������� ä�������� �ۼ�
//		�ð�������� 1 ~ 9 (������) [m][n] �� 2���� �迭�� ���ڰ� ä�������� �Ѵ�.
//
//		ex) 1 2 3		00 01 02 12 22 21 20 10 11	//  1  2  3  4	00 01 02 03 13 23 33 32 31 30 20 10 11 12 22 21
//			8 9 4									// 12 13 14  5
//			7 6 5									// 11 16 15  6
//													// 10  9  8  7 
/*/
#define VERTICAL		3			// �� ���� �迭�� ������
#define HORIZONTAL		3			// �迭�� Index�� �� ������

#define STRAIGTH		1
#define REVERSE			-1

#define GOTOVERT		1
#define GOTOHORI		0

#define MAXINDEXNUM(t)	t - 1

int main()
{
	int iArr[VERTICAL][HORIZONTAL] = { 0 };			// ���� �迭

	int iHori = 0;
	int iVert = 0;

	int iMaxH = MAXINDEXNUM(HORIZONTAL);
	int iMaxV = MAXINDEXNUM(VERTICAL);
	int iMinH = 0;
	int iMinV = 0;

	int iCnt = 0;
	int iRot = GOTOHORI;
	int iRevH = STRAIGTH;
	int iRevV = STRAIGTH;


	while ((VERTICAL * HORIZONTAL) > iCnt)
	{
		iArr[iVert][iHori] = ++iCnt;

		if (!iRot)
		{
			if (iRevH == 1)
			{
				if (iHori < iMaxH)
				{
					++iHori;
				}
				if (iMaxH == iHori)
				{
					iRevH = REVERSE;
					iRot = GOTOVERT;
					--iMaxH;
				}
			}
			else
			{
				if (iHori > iMinH)
				{
					--iHori;
				}
				if (iHori == iMinH)
				{
					iRevH = STRAIGTH;
					iRot = GOTOVERT;
					iMinH++;
				}
			}
		}
		//
		else
		{
			if (iRevV == 1)
			{
				if (iVert < iMaxV)
				{
					++iVert;
				}
				if (iMaxV == iVert)
				{
					iRevV = REVERSE;
					iRot = GOTOHORI;
					iMinV++;
				}
			}
			else
			{
				if (iVert > iMinV)
				{
					--iVert;
				}
				if (iVert == iMinV)
				{				
					iRevV = STRAIGTH;
					iRot = GOTOHORI;
					--iMaxV;
				}
			}
		}
	}

	for (int i = 0; i < VERTICAL; ++i)
	{
		for (int j = 0; j < HORIZONTAL; ++j)
		{
			printf("%d\t", iArr[i][j]);
		}
		printf("\n");
	}

	return 0;
}
//*/

// Q3.	 �迭�� ���ڸ� ������ ���� ������� ä����
//		ex) 1 2 6		00 01 10 20 11 02 12 21 22
//			3 5 7		0	1		2		 3  4
//			4 8 9
// 
//*/
#define VERTICAL		10			// �� ���� �迭�� ������
#define HORIZONTAL		2			// �迭�� Index�� �� ������
#define CHECKEVEN(t)	!(t % 2)	// ¦���� 1 Ȧ���� 0
#define MAXINDEX(t)		t - 1		// ũ���� -1 �� �ִ� �ε���

int main()
{
	int iHori = 0;			// arr[][v]
	int iVert = 0;			// arr[v][]

	int iCnt = 0;			// Loop�� �� ����
	int iCheckCross = 0;	//00 01 10 20 11 02 12 21 22  ��ǥ ���� ¦���� �� ����
							// 0   1	  2       3   4        ���� Ȧ���� �� ���ϴ�
	int iRes[VERTICAL][HORIZONTAL] = { 0 };

	while (iCnt < VERTICAL * HORIZONTAL)
	{
		iRes[iVert][iHori] = ++iCnt;
		iCheckCross = iVert + iHori;

		if (CHECKEVEN(iCheckCross))	// ����
		{
			if (iHori != MAXINDEX(HORIZONTAL) && iVert == 0)
				++iHori;			// ��� �� ��� ������
			else if (iHori == (HORIZONTAL - 1))
				++iVert;			// ���� �� ��� �Ʒ���
			else
			{						// �⺻ �������� �̵�
				--iVert;
				++iHori;
			}
		}
		else						// ���ϴ�
		{
			if (iVert != MAXINDEX(VERTICAL) && iHori == 0)
				++iVert;			// ���� �� ��� �Ʒ���
			else if (iVert == MAXINDEX(VERTICAL))
				++iHori;			// �ϴ� �� ��� ������
			else
			{						// �⺻ ���ϴ����� �̵�
				++iVert;
				--iHori;
			}
		}
	}

	for (int i = 0; i < VERTICAL; ++i)	// ���
	{
		for (int j = 0; j < HORIZONTAL; ++j)
			printf("%d\t", iRes[i][j]);
		printf("\n");
	}

	return 0;
}
//*/