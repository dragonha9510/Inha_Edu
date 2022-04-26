#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q5.  2 이상의 정수를 입력 받아 2부터 입력받은 정수까지의 모든 소수를 출력.
//		단, 한줄에 5개씩 출력한다.

void PrintPrimeNumber(int ia = 0);		// 소수를 출력하는 함수
int GetNumber();						// 정수를 입력받을 함수

int main()
{
	PrintPrimeNumber(GetNumber());		// 정수를 받아서 소수를 출력하자

	return 0;
}

void PrintPrimeNumber(int ia)
{
	int iCnt = 0;

	for (int i = 2; i <= ia; ++i)		// 소수는 2부터 입력한 수까지 확인한다.
	{
		if ((i % 2) && (i % 3) && (i % 5) && (i % 7) 
			|| i == 2 || i == 3 || i == 5 || i == 7)				// 소수라면 0 이 아닌 값을 반환 if 문 실행
		{
			printf("%d\t", i);

			++iCnt;						// 5 번 출력했다면 개행

			if (iCnt == 5)
			{
				iCnt = 0;
				printf("\n");
			}
		}
	}
}

int GetNumber()
{
	int iRes = 0;
	int iBreak = 0;

	while (!iBreak)
	{
		printf("2 이상의 정수를 입력 바랍니다 : ");
		iBreak = scanf("%d", &iRes);

		if (iBreak != 0 && iRes >= 2)
			break;
		else
			iBreak = 0;
	}

	return iRes;
}