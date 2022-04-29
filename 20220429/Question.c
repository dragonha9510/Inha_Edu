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

//*/
#define ARR2DSIZE		10		// 몇 개의 배열을 쓸건지
#define ARRSIZE			4		// 배열의 Index가 몇 개인지

int main()
{
	int iCnt = 0;									// 배열의 크기만큼 부여할 Index 값
	int iArr[ARR2DSIZE][ARRSIZE] = { 0 };			// 최초 배열

	for (int i = 0; i < ARR2DSIZE; ++i)				// 1 ~ 배열의 크기 값 부여
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			iArr[i][j] = ++iCnt;
		}
	}

	int iRes[ARRSIZE][ARR2DSIZE] = { 0 };			// 2, 4 -> 4, 2 배열 변경

	for (unsigned int i = 0; i < ARR2DSIZE; ++i)	// Rotation
	{
		for (unsigned int j = 0; j < ARRSIZE; ++j)
		{
			iRes[j][ARR2DSIZE - 1 - i] = iArr[i][j];
		}
	}

	for (unsigned int i = 0; i < ARRSIZE; ++i)		// 결과 출력
	{
		for (unsigned int j = 0; j < ARR2DSIZE; ++j)
		{
			printf("%d\t", iRes[i][j]);
		}

		printf("\n");	// 행이 끝나면 개행
	}

	return 0;
}
//*/