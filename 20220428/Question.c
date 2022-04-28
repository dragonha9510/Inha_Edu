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

// Q2.	 "I am a boy. i am Happy!" ���ڿ�����
//		boy �� �ּҸ� ����ϰ� boy �� girl �� ����
/*/
#define INITNULL		0
#define INITCHAR		"\0"
#define ZERO			0
#define MINUSNULL		-1
#define PLUSNULL		+1
#define CHARBUFFMAX		255
#define TRUE			1

int GetLength(char* word);
char* FindWord(char* origin, char* sour);
char* SaveSentence(char* origin, char* sour);
char* ChangeWord(char* origin, char* dest, char* sour);

int main()
{
	char chSentence[CHARBUFFMAX] = "I am a girl. I am Happy!";

	printf("%s", ChangeWord(chSentence, "girl", "boy"));

	return ZERO;
}

int GetLength(char* word)
{
	int iCnt = INITNULL;
	int iLength = INITNULL;

	while (TRUE)
	{
		if (*(word + iCnt) == '\0')
		{
			iCnt = ZERO;
			break;
		}
		++iCnt;
		++iLength;
	}

	return iLength;
}

char* FindWord(char* origin, char* sour)
{
	int iCnt = INITNULL;
	int iLength = INITNULL;
	int iBreak = ZERO;

	iLength = GetLength(origin);

	for (int i = INITNULL; i < iLength; ++i)
	{
		if (*(origin + iCnt) == *sour)
		{
			for (int j = INITNULL; j < GetLength(sour); ++j)
			{
				if (*((origin + iCnt) + j) != *(sour + j))
				{
					iBreak = ZERO;
					break;
				}

				iBreak = TRUE;
			}

			if (iBreak)
				return (origin + iCnt);
		}

		++iCnt;
	}

	return origin;
}

char* SaveSentence(char* origin, char* sour)
{
	int iCnt = INITNULL;
	int iLength = INITNULL;
	int iBreak = ZERO;

	iLength = GetLength(origin);

	for (int i = INITNULL; i < iLength; ++i)
	{
		if (*(origin + iCnt) == *sour)
		{
			for (int j = 0; j < GetLength(sour); ++j)
			{
				if (*((origin + iCnt) + j) != *(sour + j))
				{
					iBreak = ZERO;
					break;
				}

				iBreak = TRUE;
			}

			if (iBreak)
				return ((origin + iCnt) + GetLength(sour));
		}

		++iCnt;
	}

	return origin;
}

char* ChangeWord(char* origin, char* dest, char* sour)
{
	char* ChangePos = FindWord(origin, dest);
	char* ptrBackSentence = SaveSentence(ChangePos, dest);

	printf("Boy �� �ּ� : %p\n", ChangePos);

	char BackSentence[CHARBUFFMAX] = "Test";

	for (int i = 0; i < GetLength(ptrBackSentence); ++i)
	{
		*(BackSentence + i) = *(ptrBackSentence + i);
	}

	for (int i = INITNULL; i < GetLength(sour); ++i)
	{
		*(ChangePos++) = *(sour + i);
	}

	for (int i = INITNULL; i < GetLength(BackSentence); ++i)
	{
		*(ChangePos++) = *(BackSentence + i);
	}

	return origin;
}
//*/

#define SWAP(a, b, temp)\
temp = a;\
a = b;\
b = temp\

// Q3.	 p353 ���� ���� ����
//*/
#define INITNULL		0
#define INITCHAR		"\0"
#define CHARNULL		'\0'
#define RESETLOOP		-1
#define CHARBUFFMAX		255
#define TRUE			1
#define FALSE			0
#define TOLOWERCASE(t)	t + 32
#define NEXTINDEX(t)	t + 1
#define CHECKOVERFLOW(integer, size) integer == (size - 1) ? TRUE : FALSE

// Constraint
#define NUMOFWORD		3


void sortWord(char* pArr[], int arrSize);			// ���� ���� ( ���� ���� )
int CheckCapital(char* ch);							// return ascii
int CheckSameWord(char* chFront, char* chBack);		// ���� �ٲٸ� 1, �ȹٲٸ� 0

int main()
{
	char chFirst[CHARBUFFMAX]	= INITCHAR;
	char chSecond[CHARBUFFMAX]	= INITCHAR;
	char chThird[CHARBUFFMAX]	= INITCHAR;

	char* ptrArr[NUMOFWORD] = {chFirst, chSecond, chThird};

	printf("�� �ܾ� �Է� : ");
	
	for (int i = INITNULL; i < NUMOFWORD; ++i)
		scanf("%s", ptrArr[i]);

	sortWord(ptrArr, NUMOFWORD);

	for(int i = INITNULL; i < NUMOFWORD; ++i)
		printf("%s, ", ptrArr[i]);

	return 0;
}

int CheckCapital(char* ch)
{	// �빮�ڶ�� �ҹ��ڸ� ��������  Ascii�ڵ� �� ��ȯ
	return *ch <= 'Z' ? TOLOWERCASE(*ch) : *ch;
}

int CheckSameWord(char* chFront, char* chBack)
{	// ���� �����϶� �� ���� ���� �� �� �ܾ �� ũ�ٸ� ����, (������ ���� �� ��� ����)
	if (*(NEXTINDEX(chFront)) == CHARNULL)
		return FALSE;

	else if (*(NEXTINDEX(chBack)) == CHARNULL)
		return TRUE;

	if (CheckCapital(NEXTINDEX(chFront)) == CheckCapital(NEXTINDEX(chBack)))
		return CheckSameWord(NEXTINDEX(chFront), NEXTINDEX(chBack));

	else if (CheckCapital(NEXTINDEX(chFront)) > CheckCapital(NEXTINDEX(chBack)))
		return TRUE;

	return FALSE;
}

void sortWord(char* pArr[], int arrSize)
{
	char* ptrTemp	= INITNULL;
	int iBreak		= TRUE;

	for (int i = INITNULL; i < arrSize; ++i)
	{
		if (CheckCapital(pArr[i]) > CheckCapital(pArr[NEXTINDEX(i)]))
		{	// �� �ܾ� �� ���ڰ� �� Ŭ��
			ptrTemp				= pArr[i];
			pArr[i]				= pArr[NEXTINDEX(i)];
			pArr[NEXTINDEX(i)]	= ptrTemp;

			iBreak = FALSE;
		}
		else if (CheckCapital(pArr[i]) == CheckCapital(pArr[NEXTINDEX(i)]))
		{	// �ձ��ڰ� ���� �� �ܾ� ��ü �� ( ���ĺ� ���� �켱, �� ���� ���� )
			if (CheckSameWord(pArr[i], pArr[1 + (i)]))
			{
				ptrTemp				= pArr[i];
				pArr[i]				= pArr[NEXTINDEX(i)];
				pArr[NEXTINDEX(i)]	= ptrTemp;

				iBreak = FALSE;
			}
		}

		if (CHECKOVERFLOW(NEXTINDEX(i), arrSize))
		{	// �迭�� [i + 1] ��°�� �迭�� ũ�⸦ ����ٸ�
			if (iBreak)
			{	// ��� �ٲ���ٸ� (iBreak�� 1) �ݺ��� ����
				break;
			}

			// �ݺ��� �ٽ� ó�����ͽ���
			i = RESETLOOP;
		}

		iBreak = TRUE;	// ����������ִٸ� 0 ���� ������
	}					
}
//*/