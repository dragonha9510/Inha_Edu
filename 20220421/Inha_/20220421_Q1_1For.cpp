#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q1. 구구단 출력 1, 2, 3 줄바꾸고 4, 5, 6 ~ 120120120120
// Q1. For문 1개 사용
//*
int main()
{
	int iNum		= 0;
	int iNumTemp	= 0;
	int iNumMul		= 0;
	int iBreak		= 0;

	int iScanTemp = scanf("%d", &iNum);

	iNumTemp	= iNum - 1;
	iNumMul		= 2;

	for (int i = 0; i < 9; ++i)
	{
		if (iNumTemp <= 0)
			break;

		if (iNumTemp <= 3)
		{
			switch (iNumTemp % 3)
			{
			case 1:
				printf("%d X %d = %d \n", iNumMul, (i + 1), iNumMul * (i + 1));
				break;
			case 2:
				printf("%d X %d = %d \t", iNumMul, (i + 1), iNumMul * (i + 1));
				printf("%d X %d = %d \n", (iNumMul + 1), (i + 1), (iNumMul + 1) * (i + 1));
				break;
			default:
				printf("%d X %d = %d \t", iNumMul, (i + 1), iNumMul * (i + 1));
				printf("%d X %d = %d \t", (iNumMul + 1), (i + 1), (iNumMul + 1) * (i + 1));
				printf("%d X %d = %d \n", (iNumMul + 2), (i + 1), (iNumMul + 2) * (i + 1));
				break;
			}
		}
		else
		{
			printf("%d X %d = %d \t", iNumMul, (i + 1), iNumMul * (i + 1));
			printf("%d X %d = %d \t", (iNumMul + 1), (i + 1), (iNumMul + 1) * (i + 1));
			printf("%d X %d = %d \n", (iNumMul + 2), (i + 1), (iNumMul + 2) * (i + 1));
		}

		if (i == 8)
		{
			printf("--------------------------------------------------------------\n");

			iNumTemp -= 3;
			i = 0;

			iNumMul += 3;
		}
	}
}
//*/