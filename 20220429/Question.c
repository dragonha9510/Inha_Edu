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

//*/
#define ARR2DSIZE		10		// �� ���� �迭�� ������
#define ARRSIZE			4		// �迭�� Index�� �� ������

int main()
{
	int iCnt = 0;									// �迭�� ũ�⸸ŭ �ο��� Index ��
	int iArr[ARR2DSIZE][ARRSIZE] = { 0 };			// ���� �迭

	for (int i = 0; i < ARR2DSIZE; ++i)				// 1 ~ �迭�� ũ�� �� �ο�
	{
		for (int j = 0; j < ARRSIZE; ++j)
		{
			iArr[i][j] = ++iCnt;
		}
	}

	int iRes[ARRSIZE][ARR2DSIZE] = { 0 };			// 2, 4 -> 4, 2 �迭 ����

	for (unsigned int i = 0; i < ARR2DSIZE; ++i)	// Rotation
	{
		for (unsigned int j = 0; j < ARRSIZE; ++j)
		{
			iRes[j][ARR2DSIZE - 1 - i] = iArr[i][j];
		}
	}

	for (unsigned int i = 0; i < ARRSIZE; ++i)		// ��� ���
	{
		for (unsigned int j = 0; j < ARR2DSIZE; ++j)
		{
			printf("%d\t", iRes[i][j]);
		}

		printf("\n");	// ���� ������ ����
	}

	return 0;
}
//*/