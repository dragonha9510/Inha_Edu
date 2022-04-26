// 20220420.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <iostream>

int main()
{
	// scanf 입력
	/*/
	int a = 0;
	if (scanf("%d", &a) == 0)
	{
		printf("잘못된 입력");
		return -1;
	}

	printf("a : %d", a);
	//*/

	// 짝수 홀수 if문
	/*/
	int iA = 0;
	
	int iBreak = scanf("%d", &iA);
	
	while (iBreak == 0)
	{
		printf("정수 입력");

		rewind(stdin);
		iBreak = scanf("%d", &iA);
	}

	printf("입력된 수 : %d", iA);

	if (iA % 2)
		printf("홀수!");
	else if (iA == 0)
		printf("0 입니다");
	else
		printf("짝수!");
	//*/

	// 반복문 While
	/*/
	int iA = 0;

	while (iA < 10)
	{
		printf("%d\t", iA);
		++iA;
		printf("%d\n", iA);
	}
	//*/

	// 반복문 For
	/*/
	int a = 1;
	
	for (int i = 0; i < 3; ++i)
	{
		a = a * 2;
	}

	printf("a : %d\n", a);
	//*/

	// 반복문 While ( or Do While )
	/*/
	int iA = 0;

	while (iA <= 0)
	{
		printf("음수를 입력 : ");
		scanf("%d", &iA);
		rewind(stdin);
		system("cls");

		if (iA == 0)
			break;
	}

	printf("양수를 입력했습니다 다음! \n");

	for (int i = 0; i < 5; ++i)
	{
		printf("Be happy\n");
	}

	printf("Complete.");
	//*/

	// 별 찍기 ( 이중 for 문 )
	/*/
	for (int i = 0; i < 5; ++i)
	{
		for (int j = 5; j > 0; --j)
		{
			if (i + 1 < j)
				printf(" ");
			else
				printf("*");
		}
		printf("\n");
	}
	//*/

	// 구구단
	/*/
	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			printf("%d * %d = %d\n",i + 2, j + 1, (i + 2) * (j + 1));
		}
	}
	//*/

	return 0;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
