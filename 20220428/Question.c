#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

// ����	1193
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
			printf("����� �ܾ��� ���� �� : %d", iMax + MINUSNULL);
	}

	return 0;
}
//*/

// Make Q1 .

// Q1. scanf_ver
/*/
// Enter -> Ctrl + Z -> Enter -> Ctrl + Z �� �Է��ؾ���								// Ctrl + Z 2�� ����
// ���ڿ� -> Ctrl + Z  -> Enter -> Ctrl + Z -> Enter -> Ctrl + Z  -> Enter �� ����	// Ctrl + Z 3�� ����
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
			printf("����� �ܾ��� ���� �� : %d", iMax);
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