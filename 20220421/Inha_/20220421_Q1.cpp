#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define PLUSONE(i) i + 1

using namespace std;

// Q1. ������ ��� 1, 2, 3 �ٹٲٰ� 4, 5, 6 ~
//*
int main()
{
	int iNum	= 0;			// �Է� ���� ����
	int iCnt	= 0;			// �����ܿ��� �Է¹��� ������ ���ϱ� ���� �߰� ����
	int iBreak	= 0;			// break�� ���� ���� ( bool )

	int iTemp = scanf("%d", &iNum);
	
	iCnt = 2;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (iNum < (j + iCnt))
			{
				iBreak = 1;
				continue;
			}

			printf("%d X %d = %d \t", j + iCnt, PLUSONE(i), (i + 1) * (j + iCnt));
		}

		printf("\n");

		if (i == 8)
		{
			iCnt += 3;
			i = 0;

			if (iBreak == 1)
				break;

			printf("-------------------------------------------");
			printf("\n");
		}
	}

	return 0;
}
//*/
