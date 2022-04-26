#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define PLUSONE(i) i + 1

using namespace std;

// Q1. 구구단 출력 1, 2, 3 줄바꾸고 4, 5, 6 ~
//*
int main()
{
	int iNum	= 0;			// 입력 받을 변수
	int iCnt	= 0;			// 구구단에서 입력받은 정수와 비교하기 위한 추가 변수
	int iBreak	= 0;			// break를 위한 변수 ( bool )

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
