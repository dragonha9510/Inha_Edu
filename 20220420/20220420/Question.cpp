#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <iostream>

using namespace std;

/*/
// Q1.   두 개의 정수를 입력 받아 두 수의 차를 출력하는 프로그램을 작성하라.
//		단, 큰 수에서 작은 수를 빼야한다.
//		case 1. if ~ else 문을 이용
//		case 2. 조건 연산자를 이용
int main()
{
	//// case 1.

	//int iFirst	= 0;		// 입력받을 첫 번째 변수
	//int iSecond = 0;		// 입력받을 두 번째 변수

	//scanf("%d", &iFirst);
	//rewind(stdin);			// 입력 버퍼 비우기. 
	//scanf("%d", &iSecond);

	//if (iFirst > iSecond)
	//{
	//	printf("두 수의 차 : %d", iFirst - iSecond);
	//}
	//else
	//{
	//	printf("두 수의 차 : %d", iSecond - iFirst);
	//}

	///////////////////////////////////////////////////////////////////////////////////////
	// case 2.

	int iFirst	= 0;		// 입력받을 첫 번째 변수
	int iSecond = 0;		// 입력받을 두 번째 변수

	scanf("%d", &iFirst);
	rewind(stdin);			// 입력 버퍼 비우기. 
	scanf("%d", &iSecond);

	printf("두 수의 차 : %d", (iFirst > iSecond ? iFirst - iSecond : iSecond - iFirst));

	return 0;
}
//*/

/*/
// Q2.	 학생의 전체 평균 점수에 대한 학점을 출력하는 프로그램 작성.
//		성적이 90점 이상 A ,
//		성적이 80점 이상 B ,
//		성적이 70점 이상 C ,
//		성적이 60점 이상 D ,
//		그 미만은 F로 처리.
// 
//		 프로그램 실행시 국어, 영어, 수학의 점수를 입력 받고
//		그 평균을 구하여 위의 점수표를 기준으로 학점을 출력하라.
//

int main()
{
	const int iClassCnt = 3;

	int iKorean		= 0;	// 국어 점수
	int iMath		= 0;	// 수학 점수
	int iEnglish	= 0;	// 영어 점수
	int iAverage	= 0;	// 평균 점수
	char chScore	= ' ';	// 최종 점수

	printf("국어 점수 입력 : ");
	scanf("%d", &iKorean);
	rewind(stdin);					// 입력 버퍼 비우기.

	printf("영어 점수 입력 : ");
	scanf("%d", &iEnglish);
	rewind(stdin);

	printf("수학 점수 입력 : ");
	scanf("%d", &iMath);
	rewind(stdin);

	iAverage = (iKorean + iEnglish + iMath) / iClassCnt;		// 평균 계산

	if (iAverage >= 90)
	{
		chScore = 'A';
	}
	else if (iAverage >= 80)
	{
		chScore = 'B';
	}
	else if (iAverage >= 70)
	{
		chScore = 'C';
	}
	else if (iAverage >= 60)
	{
		chScore = 'D';
	}
	else
	{
		chScore = 'F';
	}

	printf("평균 점수는 : %d\n", iAverage);
	printf("최종 학점은 : %c", chScore);

	return 0;
}
//*/

/*/
// Q3. 어떤 자연수를 입력 받아 ! ( 팩토리얼 )을 구하는 프로그램을 작성하라

int main()
{
	unsigned long long llNum = 0;		// 자연수 입력받을 변수
	unsigned long long llFac = 1;		// 출력될 팩토리얼 계산 값.	( * 0 은 0이기 때문에 1로 초기화 )

	printf("자연수 입력 : ");
	scanf("%llu", &llNum);
	rewind(stdin);

	for (unsigned long long i = llNum; i > 0; --i)
	{
		llFac *= i;
	}

	printf("팩토리얼 값 : %llu", llFac);

	return 0;
}

//*/

/*/
// Q4.	 두 수를 입력받아 두 수 사이에 존재하는 정수의 합을 구하는 프로그램을 작성하라

int main()
{
	int iFirst	= 0;				// 첫 번째 정수	( 큰 수 )
	int iSecond = 0;				// 두 번째 정수  ( 작은 수 )
	int iRes	= 0;				// 결과 값.

	printf("두 개의 정수를 입력하여 주세요.");

	printf("첫 번째 : ");
	scanf("%d", &iFirst);

	rewind(stdin);					// 입력 버퍼 초기화

	printf("두 번째 : ");
	scanf("%d", &iSecond);

	if (iFirst > iSecond ? 0 : 1)	// Swap ( Second 가 더 크다면 First 와 Second 를 swap)
	{
		int iTemp = iSecond;
		iSecond = iFirst;
		iFirst	= iTemp;
	}

	for (int i = iFirst;
		i >= iSecond;
		--i) {
		iRes += i;
	}

	printf("두 수 사이를 모두 더한 값 : %d", iRes);

	return 0;
}
//*/

/*/
// Q5.	 사용자로부터 양의 정수를 m 과 n 을 입력 받아
//		n 개 만큼 m 의 배수를 출력하는 프로그램을 작성.

int main()
{
	int iFirst	= 0;		// N ( 개수 )
	int iSecond = 0;		// M ( 기준 값 )

	printf("개수 입력 : ");
	scanf("%d", &iFirst);

	rewind(stdin);			// 입력 버퍼 초기화

	printf("기준 값 입력 : ");
	scanf("%d", &iSecond);

	for (int i = 0; i < iFirst; ++i)
	{
		// * 0 = 0 이기 때문에 (i + 1) 1 부터 시작.
		printf("%d \n", iSecond * (i + 1));
	}

	return 0;
}

//*/

/*/
// Q5.	 사용자로부터 계속 정수를 입력받아 그 값을 계속 더해 나간다.
//		사용자가 0을 입력 할때까지 계속 되어야 하며, 0 이 입력되면
//		입력된 모든 정수의 합을 출력한다.

int main()
{
	int iSum	= 0;	// 입력 받을 변수.
	int iResult = 0;	// 결과를 저장할 변수.

	do
	{
		printf("입력하는 모든 값을 더해 드립니다. \n");
		printf("결과 보기 및 종료 : 0 \n 입력 : ");

		scanf("%d", &iSum);
		rewind(stdin);

		iResult += iSum;		// 결과 변수에 값을 계속 더함

		system("cls");			// cmd 창을 초기화
	} while (iSum != 0);

	printf("종료 !  결과 값 -> %d", iResult);

	return 0;
}
//*/

//*/
// Q7.	 1 이상 100 미만인 정수 m 과 n 의 배수를 출력하는 프로그램을 작성하라.
//		단, m 의 배수이면서 n 의 배수인 정수는 한번만 출력해야 한다.
//		ex) m = 7, n = 9 -> 7, 9, 14, 18, 27, 28, 35, 36 ~~ 63

int main()
{
	int iFirst	= 0;	// M		작은 수
	int iSecond = 0;	// N		큰 수

	while (1)			// 입력되는 값을 기준으로 While문을 종료하기 때문에 항상 TRUE
	{
		printf("1 이상의 정수를 두 번 입력해 주세요. \n");

		printf("입력 : ");
		scanf("%d", &iFirst);

		rewind(stdin);

		printf("입력 : ");
		scanf("%d", &iSecond);

		if ((iFirst >= 1 && iSecond >= 1) 
			&& (iFirst < 100 && iSecond < 100))
			break;

		system("cls");

		printf("하나의 정수 혹은 모든 정수가 0 혹은 100을 초과한 값입니다. 다시 입력해주세요. \n");
	}

	if (iFirst > iSecond ? 1 : 0)		// Swap : 작은 수를 First에 큰 수를 Second에 Swap
	{
		int iTemp	= iSecond;
		iSecond		= iFirst;
		iFirst		= iTemp;
	}

	int iFRes		= 0;	// 작은 수의 배수들을 출력하기 위한 변수
	int iSRes		= 0;	// 큰 수의 배수들을 출력하기 위한 변수
	int iMulF		= 0;	// 작은 수의 배수를 구하기 위한 변수
	int iMulS		= 0;	// 큰 수의 배수를 구하기 위한 변수

	iFRes = iFirst;			// iFirst * 1 = iFirst
	iSRes = iSecond;		// iSecond * 1 = iSecond
	iMulS = 1;				// iSecond의 경우 예외 처리를 위해 1부터 시작 조건문 통과 후 증가

	while (1)
	{
		if (iSRes > 100 && iFRes > 100)		// First와 Second가 모두 100을 넘었다면 종료
			break;

		iFRes = iFirst * (++iMulF);			// 각 배수를 계산
		iSRes = iSecond * iMulS;

		if (iFRes > iSRes)					// 출력 순서 정렬을 위한 조건문 iSecond가 iFirst보다
		{									// 작을 때에 배수를 증가시키고 iSecond를 출력한다.
			++iMulS;						// iSecond의 배수 증가.

			if (iSRes % iFirst)				// iFirst와 동일한 배수라면 출력하지 않는다 
			{								// ( 해당 값은 iFRes 가 출력한다. )
				if(iSRes < 100)				// iSRes 가 100 이상의 값을 출력하지 않기 위한 예외처리
					printf("%d\n", iSRes);
			}
		}

		if(iFRes < 100)						// iFRes 가 100 이상의 값을 출력하지 않기 위한 예외처리
			printf("%d\n", iFRes);
	}

	return 0;
}

//*/

/*/
// Q8 별찍기

int main()
{
	int iInput = 0;

	scanf("%d", &iInput);

	for (int i = 0; i < iInput; ++i)
	{
		for (int j = iInput; j > 0; --j)
		{
			if (i + 1 < j)
				printf(" ");
			else
				printf("*");
		}
		cout << endl;
	}

	printf("\n");


	for (int i = 0; i < iInput; ++i)
	{
		for (int j = 0; j < iInput; ++j)
		{
			if (i < j)
				printf(" ");
			else
				printf("*");
		}
		cout << endl;
	}
}

//*/