#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// 백준	1193
/*/
#define INITNULL 0
#define CHECKEVEN(t) t % 2
#define FRONT(t) t / t

int main()
{
	int iNum		= INITNULL;
	int iSum		= INITNULL;
	int iCheckEven	= INITNULL;

	scanf("%d", &iNum);

	for (int i = INITNULL; iSum < iNum; ++i)
	{
		iSum += i;
		iCheckEven = i;
	}

	CHECKEVEN(iCheckEven) ?
		printf("%d/%d", FRONT(iCheckEven) + (iSum - iNum), iCheckEven - (iSum - iNum)) :
		printf("%d/%d", iCheckEven - (iSum - iNum), FRONT(iCheckEven) + (iSum - iNum));
}
//*/

// Q1.
/*/
#define INITNULL		0
#define ZERO			0
#define MINUSNULL		-1

int main()
{
	int iCnt = INITNULL;
	int iMax = INITNULL;
	char chBuff = INITNULL;

	while (chBuff != EOF)
	{
		chBuff = getchar();

		++iCnt;

		if (chBuff == '\n')
		{
			iMax = iMax < iCnt ? iCnt : iMax;

			iCnt = ZERO;
		}
		else if (chBuff == EOF)
			printf("가장긴 단어의 글자 수 : %d", iMax + MINUSNULL);
	}

	return 0;
}
//*/

// Make Q1 .

// Q1. scanf_ver
/*/
// Enter -> Ctrl + Z -> Enter -> Ctrl + Z 로 입력해야함								// Ctrl + Z 2번 종료
// 문자열 -> Ctrl + Z  -> Enter -> Ctrl + Z -> Enter -> Ctrl + Z  -> Enter 도 가능	// Ctrl + Z 3번 종료
#define INITNULL		0
#define INITCHAR		"\0"
#define ZERO			0
#define MINUSNULL		-1
#define CHARBUFFMAX		255
#define TRUE			1

int main()
{
	int iCnt				 = INITNULL;
	int iMax				 = INITNULL;
	int iBreak				 = INITNULL;
	char chBuff[CHARBUFFMAX] = INITCHAR;

	while (iBreak != EOF)
	{
		iBreak = scanf("%[^\n]s", chBuff);
		rewind(stdin);

		if (iBreak == EOF)
		{
			printf("가장긴 단어의 글자 수 : %d", iMax);
			break;
		}

		for (int i = INITNULL; TRUE; ++i)
		{
			if (*(chBuff + i) == '\0')
			{
				iMax = iMax < iCnt ? iCnt : iMax;
				iCnt = ZERO;
				break;
			}

			++iCnt;
		}
	}

	return 0;
}
//*/

// Q2.
//*/