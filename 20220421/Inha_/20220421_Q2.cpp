#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q2. 임의수 n을 입력 받아서 다음과 같은 형태로 출력하시오.
//*/
//		ex) n = 5
//
//		*   *
//		** **
//		*****
//		** **
//		*   *		0, 4 -> 1, 3 -> 2
//
//		ex) n = 4
//		*  *		0, 3 -> 1, 2
//		****
//		****
//		*  *

int main()
{
	int iNum		= 0;	// 입력받을 변수

	int iFront		= 0;	// 앞 * 위치
	int iBack		= 0;	// 뒤 * 위치
	int iReverse	= 0;	// 역행
	int iOddCheck	= 0;	// 짝 홀 확인	홀수라면 1 짝수라면 0

	int iScanTemp = scanf("%d", &iNum);

	iBack		= iNum - 1;
	iOddCheck	= iNum % 2;

	for (int i = 0; i < iNum; ++i)
	{
		for (int j = 0; j < iNum; ++j)
		{
			if (j <= iFront || j >= iBack)	// 현재 Front와 Back위치 앞뒤를 모두
				printf("*");				// * 로 채운다.
			else
				printf(" ");
		}

		if (!iReverse)						// 교차하지 않았을 때
		{
			if (iOddCheck)					// 홀수라면
			{
				++iFront;
				--iBack;

				if (iFront == iBack)		// 교차지점이 같다. 만난 순간 역행
				{
					iReverse = 1;
				}
			}
			else							// 짝수라면
			{
				++iFront;
				--iBack;

				if (iFront > iBack)			// 교차지점은 Front가 Back을 지났을 때
				{
					iReverse = 1;
					--iFront;
					++iBack;
				}
			}
		}
		else								// 역행 구문
		{
			--iFront;
			++iBack;
		}

		printf("\n");
	}

	return 0;
}

//*/