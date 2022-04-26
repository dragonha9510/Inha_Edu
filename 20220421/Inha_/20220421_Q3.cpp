#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q3. 임의수 n을 입력 받아서 다음과 같은 형태로 출력하시오.
//*/
//		ex) n = 5
//
//		*   *
//		 * *
//		  *
//		 * *
//		*   *		0, 4 -> 1, 3 -> 2
//
//		ex) n = 4
//		*  *		0, 3 -> 1, 2
//		 **
//		 **
//		*  *

int main()
{
	int iNum = 0;	// 입력받을 변수

	int iFront		= 0;	// 앞 * 위치
	int iBack		= 0;	// 뒤 * 위치

	int iScanTemp = scanf("%d", &iNum);

	iBack = iNum - 1;		// 컴퓨터의 배열은 0 부터 시작 (개수 - 1) 이 마지막

	for (int i = 0; i < iNum; ++i)
	{
		for (int j = 0; j < iNum; ++j)
		{
			if (j == iFront || j == iBack)	// Front와 Back의 자리에만 * 입력
				printf("*");
			else
				printf(" ");
		}

		++iFront;		// Front는 계속 뒤로 이동.
		--iBack;		// Back은 계속 앞으로 이동.

		printf("\n");
	}

	return 0;
}

//*/