#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

// Q1.	 행렬 전환
//		다음과 같은 A행렬을 B행렬과 같은 형태가 되도록 하라.
//
//		A			B			A			B
//		1 2 3 4		5 1			1 2 3		7 4 1
//      5 6 7 8		6 2			4 5 6		8 5 2
//					7 3			7 8 9		9 6 3
//					8 4
/*/
#define ARR2DSIZE		3			// 몇 개의 배열을 쓸건지
#define ARRSIZE			3			// 배열의 Index가 몇 개인지
#define REALCOUNT(t)	t + 1		// 컴퓨터는 0 부터 사람은 1 부터 

int main()
{
	int iArr[ARR2DSIZE][ARRSIZE] = { 0 };			// 최초 배열
	int iRes[ARRSIZE][ARR2DSIZE] = { 0 };			// 2, 4 -> 4, 2 배열 변경

	for (int i = 0; i < ARR2DSIZE; ++i)				// iArr에 값 부여 하면서 iRes 로 Rotation
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			iArr[i][j] = (i * ARRSIZE) + REALCOUNT(j);
			iRes[j][ARR2DSIZE - REALCOUNT(i)] = iArr[i][j];
		}
	}

	for (int i = 0; i < ARRSIZE; ++i)		// 결과 출력
	{
		for (int j = 0; j < ARR2DSIZE; ++j)
		{
			printf("%d\t", iRes[i][j]);
		}

		printf("\n");	// 행이 끝나면 개행
	}

	return 0;
}
//*/

// Q2.	 배열에 숫자를 다음과 같은 방법으로 채워지도록 작성
//		시계방향으로 1 ~ 9 (달팽이) [m][n] 의 2차원 배열에 숫자가 채워지도록 한다.
//
//		ex) 1 2 3		00 01 02 12 22 21 20 10 11	//  1  2  3  4	00 01 02 03 13 23 33 32 31 30 20 10 11 12 22 21
//			8 9 4									// 12 13 14  5
//			7 6 5									// 11 16 15  6
//													// 10  9  8  7 
/*/
#define VERTICAL		3			// 몇 개의 배열을 쓸건지
#define HORIZONTAL		3			// 배열의 Index가 몇 개인지

#define STRAIGTH		1
#define REVERSE			-1

#define GOTOVERT		1
#define GOTOHORI		0

#define MAXINDEXNUM(t)	t - 1

int main()
{
	int iArr[VERTICAL][HORIZONTAL] = { 0 };			// 최초 배열

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

// Q3.	 배열에 숫자를 다음과 같은 방법으로 채워라
//		ex) 1 2 6		00 01 10 20 11 02 12 21 22
//			3 5 7		0	1		2		 3  4
//			4 8 9
// 
//*/
#define VERTICAL		10			// 몇 개의 배열을 쓸건지
#define HORIZONTAL		2			// 배열의 Index가 몇 개인지
#define CHECKEVEN(t)	!(t % 2)	// 짝수면 1 홀수면 0
#define MAXINDEX(t)		t - 1		// 크기의 -1 은 최대 인덱스

int main()
{
	int iHori = 0;			// arr[][v]
	int iVert = 0;			// arr[v][]

	int iCnt = 0;			// Loop와 값 대입
	int iCheckCross = 0;	//00 01 10 20 11 02 12 21 22  좌표 합이 짝수일 때 우상단
							// 0   1	  2       3   4        합이 홀수일 때 좌하단
	int iRes[VERTICAL][HORIZONTAL] = { 0 };

	while (iCnt < VERTICAL * HORIZONTAL)
	{
		iRes[iVert][iHori] = ++iCnt;
		iCheckCross = iVert + iHori;

		if (CHECKEVEN(iCheckCross))	// 우상단
		{
			if (iHori != MAXINDEX(HORIZONTAL) && iVert == 0)
				++iHori;			// 상단 벽 찍고 옆으로
			else if (iHori == (HORIZONTAL - 1))
				++iVert;			// 우측 벽 찍고 아래로
			else
			{						// 기본 우상단으로 이동
				--iVert;
				++iHori;
			}
		}
		else						// 좌하단
		{
			if (iVert != MAXINDEX(VERTICAL) && iHori == 0)
				++iVert;			// 좌측 벽 찍고 아래로
			else if (iVert == MAXINDEX(VERTICAL))
				++iHori;			// 하단 벽 찍고 옆으로
			else
			{						// 기본 좌하단으로 이동
				++iVert;
				--iHori;
			}
		}
	}

	for (int i = 0; i < VERTICAL; ++i)	// 출력
	{
		for (int j = 0; j < HORIZONTAL; ++j)
			printf("%d\t", iRes[i][j]);
		printf("\n");
	}

	return 0;
}
//*/