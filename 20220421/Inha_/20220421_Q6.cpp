#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q6.	다음 식을 만족하는 모든 A 와 Z 를 구하는 프로그램을 작성하라

int main()
{
	int iNum = 0;

	while (iNum >= 0)
	{
		printf("두 자리수 정수 입력 (종료 : -1) : ");
		scanf("%d", &iNum);

		if (iNum < 0)
			break;

		if ((iNum % 11 == 0) && iNum >= 10 && iNum < 100)
		{
			for (int i = 0; i <= iNum % 10; ++i)
			{
				printf("A = %d , Z = %d\n", i, (iNum % 10) - i);
			}
		}
		else if ((iNum % 11 == 0) && iNum >= 10 && iNum < 199)
		{
			int iTemp = 10;
			for (int i = (iNum % 10) + 1; i < 10; ++i)
			{
				printf("A = %d , Z = %d\n", i, --iTemp);
			}
		}
		else
		{
			printf("식을 만족하지 않습니다 다시 입력 해주세요. \n");
		}
	}

	return 0;
}