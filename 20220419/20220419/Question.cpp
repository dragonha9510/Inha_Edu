
#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#include <iostream>
#include <string.h>

using namespace std;

// Q1 . 나이를 입력 받아서 해당 나이의 연령대를 출력하자.

/*//Q1

int main()
{
	int iScanTemp;				// scanf 반환 값 처리를 위한 변수

	int iAge = 0;				// 입력될 나이
	int iAgeGroup = 0;			// 입력된 나이의 연령대

	printf("나이를 입력해 주세요 : ");

	iScanTemp =scanf("%d", &iAge);

	while (iAge == 0)
	{
		system("cls");
		printf("잘못된 입력입니다 다시 입력해주세요. \n 나이를 입력해 주세요 : ");
	}

	iAgeGroup = iAge / 10;

	printf("당신은 %d 대 입니다.", iAgeGroup * 10);
	printf("당신은 %d 년생 입니다.", 2023 - iAge);

	return 0;
}

//*/

// Q2 . 인간 수명이 100년 이라고 가정하고, 담배 한 개피를 피면 수명이 3시간 40분 단축된다고 한다.
//      어떤 사람이 성인이 된 이후 N년간 하루에 M개피씩 담배를 피웠다면 수명은 얼마나 단축되었고
//      몇 살까지 살 수 있는가?
//         -> 줄어든 수명 : 일 시 분
//         -> 기대   수명 : 살 일 시 분  
//		   -> N = 20, M = 3

/*// Q2

#define YEAR 365				// 1년 365일
#define DAY 24					// 하루 24시간
#define MINUTE 60				// 1시간 -> 60분
#define SMOKETIME 220			// 담배로 인한 수명단축 3시간 40분
#define MAXIMUMLIFE 52560000    // 100살까지의 분
#define ADULT 19				// 성인 20살 부터 -> 19세까진 흡연 불가.

int main()
{
	int iScnafTemp = 0;			// scanf 반환 값 처리를 위한 변수

	int iAge = 0;				// 나이
	int iAgeMinute = 0;			// 나이 (분 단위)
	int iSmokeCnt = 0;			// 하루의 흡연량
	int iLifeExpectancy = 0;	// 기대 수명
	int iWasteLife = 0;			// 줄어든 수명

	printf("나이를 입력해 주세요 : ");
	iScnafTemp = scanf("%d", &iAge);

	while (iAge == 0)		// 0살 입력
	{
		system("cls");
		printf("잘못된 입력입니다 다시 입력해주세요. \n 나이를 입력해 주세요 : ");
	}

	if(iAge <= 19)
	{
		printf("미성년자는 조사 참여 대상이 아닙니다.");
		system("pause");
		
		return -1;
	}

	printf("\n하루 흡연량을 입력해 주세요 : ");
	iScnafTemp = scanf("%d", &iSmokeCnt);

	system("cls");

	// 나이 분으로 변환
	iAgeMinute = iAge * YEAR * DAY * MINUTE;
	iSmokeCnt *= SMOKETIME;
	iWasteLife = iSmokeCnt * ((iAge - ADULT) * YEAR);
	iLifeExpectancy = MAXIMUMLIFE - iWasteLife;

	int iLeftAge = 0;		// 남은 나이
	int iYear = 0;			// 년
	int iDay = 0;			// 일
	int iHour = 0;			// 시
	int iMinute = 0;		// 분

	///////////////////////////////////////////
	// 분을 시간으로 변경
	///////////////////////////////////////////
	
	iMinute = iWasteLife % MINUTE;
	iHour = (iWasteLife / MINUTE) % DAY;
	iDay = ((iWasteLife / MINUTE) / DAY) % YEAR;
	iYear = ((iWasteLife / MINUTE) / DAY) / YEAR;

	printf("당신의 줄어든 수명은 : %d 년 %d 일 %d 시간 %d분", iYear, iDay, iHour, iMinute);

	iMinute = iLifeExpectancy % MINUTE;
	iHour = (iLifeExpectancy / MINUTE) % DAY;
	iDay = ((iLifeExpectancy / MINUTE) / DAY) % YEAR;
	iLeftAge = ((iLifeExpectancy / MINUTE) / DAY) / YEAR;

	printf("당신의  기대  수명은 : %d 살 %d 일 %d 시간 %d분", iLeftAge, iDay, iHour, iMinute);
}

//*/

/*// Q2
//#define YEAR 365				// 1년 365일
//#define DAY 24				// 하루 24시간
//#define MINUTE 60				// 1시간 -> 60분
//#define SMOKETIME 220			// 담배로 인한 수명단축 3시간 40분
//#define MAXIMUMLIFE 52560000  // 100살까지의 분
//#define ADULT 19				// 성인 20살 부터 -> 19세까진 흡연 불가.

int main()
{
	const int ciYEAR		= 365;			// 1년 365일
	const int ciDAY			= 24;			// 하루 24시간
	const int ciMINUTE		= 60;			// 1시간 -> 60분
	const int ciSMOKETIME	= 220;			// 담배로 인한 수명단축 3시간 40분
	const int ciMAXIMUMLIFE = 52560000;		// 100살까지의 분

	int iScnafTemp	= 0;						// scanf 반환 값 처리를 위한 변수

	int iSmokeYear		= 0;				// 몇년간
	int iSmokeCnt		= 0;				// 하루의 흡연량
	int iLifeExpectancy = 0;				// 기대 수명
	int iWasteLife		= 0;				// 줄어든 수명

	printf("몇 년간 흡연했는지 입력해 주세요 : ");
	iScnafTemp = scanf("%d", &iSmokeYear);

	printf("\n하루 흡연량을 입력해 주세요 : ");
	iScnafTemp = scanf("%d", &iSmokeCnt);

	// 지금까지의 흡연량 계산
	iSmokeCnt *= ciSMOKETIME;
	iWasteLife = iSmokeCnt * (iSmokeYear * ciYEAR);

	// 기대 수명 계산 (100살 기준)
	iLifeExpectancy = ciMAXIMUMLIFE - iWasteLife;

	int iLeftAge	= 0;		// 남은 나이
	int iYear		= 0;		// 년
	int iDay		= 0;		// 일
	int iHour		= 0;		// 시
	int iMinute		= 0;		// 분

	///////////////////////////////////////////
	//       분을 시간, 일, 년으로 변경       //
	///////////////////////////////////////////

	iMinute = iWasteLife % ciMINUTE;
	iHour	= (iWasteLife / ciMINUTE) % ciDAY;
	iDay	= ((iWasteLife / ciMINUTE) / ciDAY) % ciYEAR;
	iYear	= ((iWasteLife / ciMINUTE) / ciDAY) / ciYEAR;
	
	printf("\n 당신의 줄어든 수명은 : %d 년 %d 일 %d 시간 %d분 \n", iYear, iDay, iHour, iMinute);

	iMinute	 = iLifeExpectancy % ciMINUTE;
	iHour	 = (iLifeExpectancy / ciMINUTE) % ciDAY;
	iDay	 = ((iLifeExpectancy / ciMINUTE) / ciDAY) % ciYEAR;
	iLeftAge = ((iLifeExpectancy / ciMINUTE) / ciDAY) / ciYEAR;

	printf("당신의  기대  수명은 : %d 살 %d 일 %d 시간 %d분 \n", iLeftAge, iDay, iHour, iMinute);

	system("pause");
}

//*/

// Q3 . 사용자로부터 정수 3개를 입력받아 저장하고
//		조건 연산자를 사용하여 이들 변수 중 가장 큰 값을 출력하는 프로그램

/*//
int main()
{
	int iScanfTemp = 0;	//Scanf 반환 값 처리 변수

	int iFirst	= 0;	// 첫번째 입력 정수
	int iSecond = 0;	// 두번째 입력 정수
	int iThird  = 0;	// 세번째 입력 정수

	printf("무작위 정수 3가지 입력 부탁드립니다.\n");
	iScanfTemp = scanf("%d %d %d", &iFirst, &iSecond, &iThird);

	iFirst = (iFirst > iSecond) ? 
	((iFirst > iThird) ? iFirst : iThird) : 
	((iSecond > iThird) ? iSecond : iThird);

	printf("가장 큰 값 : %d", iFirst);

	return 0;
}
/*/