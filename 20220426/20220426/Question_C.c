#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <Windows.h>		// Sleep() 사용
#include <conio.h>			// _kbhit() 사용

//Q6.	 p232 대소문자 변환 프로그램.
//		메뉴 : 1.대문자로 변환 , 2. 소문자로 변환, 0. 종료
//
/*/
int CharConvert(int a, char* ch)
{
	int iCnt = 0;

	switch (a)
	{
	case 1:
		for (unsigned int i = 0; i < strlen(ch); ++i)
		{
			if (ch[i] <= 'z' && ch[i] >= 'a')
			{
				ch[i] -= 32;
				++iCnt;
			}
		}
		break;
	case 2:
		for (unsigned int i = 0; i < strlen(ch); ++i)
		{
			if (ch[i] <= 'Z' && ch[i] >= 'A')
			{
				ch[i] += 32;
				++iCnt;
			}
		}
		break;
	case 0:
		return -1;
	default:
		break;
	}

	printf("변환된 문자열\t: ");
	puts(ch);

	return iCnt;
}

int main()
{
	int iSel = 0;
	char chChange[256];

	while (1)
	{
		printf("1. 대문자로! , 2. 소문자로! , 0. 종료\n");
		scanf("%d", &iSel);

		rewind(stdin);

		if (iSel == 0)
			return 0;

		printf("문자열 입력\t: ");
		gets_s(chChange, 256);

		printf("변환된 문자 수\t: %d\n",CharConvert(iSel, chChange));

		system("pause");
		system("cls");
	}

	return 0;
}
//*/


// Q7.   문자열을 입력 받아서 광고판 문자열이 흘러가듯이 출력되는 프로그램
/*
#define CHARMAX 256

int main()
{
	char chTest[CHARMAX] = "";		// 입력받을 문자열
	char Temp = ' ';				// SWAP 을 위한 임시 변수

	gets_s(chTest, CHARMAX);
	strcat(chTest, " ");

	while (!_kbhit())
	{
		puts(chTest);

		for (int i = 0; i < CHARMAX; ++i)
		{
			if (chTest[i + 1] == '\0')	// NULL 일때 까지 반복
			{
				chTest[i] = Temp;		// NULL 의 바로 앞 문자를 첫문자로 변경.
				break;
			}
			Temp = chTest[i];			// 한글자씩 앞으로!
			chTest[i] = chTest[i + 1];
			chTest[i + 1] = Temp;
		}

		Sleep(150);				// 대기 (150ms)
		system("cls");			// 화면 지우기
	}

	return 0;
}
//*/