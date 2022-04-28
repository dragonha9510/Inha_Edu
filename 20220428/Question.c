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

// Q2.	 "I am a boy. i am Happy!" 문자열에서
//		boy 의 주소를 출력하고 boy 를 girl 로 변경
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

	printf("Boy 의 주소 : %p\n", ChangePos);

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

// Q3.	 p353 도전 실전 문제
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


void sortWord(char* pArr[], int arrSize);			// 문자 정렬 ( 사전 순서 )
int CheckCapital(char* ch);							// return ascii
int CheckSameWord(char* chFront, char* chBack);		// 둘을 바꾸면 1, 안바꾸면 0

int main()
{
	char chFirst[CHARBUFFMAX]	= INITCHAR;
	char chSecond[CHARBUFFMAX]	= INITCHAR;
	char chThird[CHARBUFFMAX]	= INITCHAR;

	char* ptrArr[NUMOFWORD] = {chFirst, chSecond, chThird};

	printf("세 단어 입력 : ");
	
	for (int i = INITNULL; i < NUMOFWORD; ++i)
		scanf("%s", ptrArr[i]);

	sortWord(ptrArr, NUMOFWORD);

	for(int i = INITNULL; i < NUMOFWORD; ++i)
		printf("%s, ", ptrArr[i]);

	return 0;
}

int CheckCapital(char* ch)
{	// 대문자라면 소문자를 기준으로  Ascii코드 값 반환
	return *ch <= 'Z' ? TOLOWERCASE(*ch) : *ch;
}

int CheckSameWord(char* chFront, char* chBack)
{	// 같은 글자일때 그 다음 글자 비교 앞 단어가 더 크다면 변경, (완전히 같을 땐 길면 변경)
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
		{	// 앞 단어 앞 글자가 더 클때
			ptrTemp				= pArr[i];
			pArr[i]				= pArr[NEXTINDEX(i)];
			pArr[NEXTINDEX(i)]	= ptrTemp;

			iBreak = FALSE;
		}
		else if (CheckCapital(pArr[i]) == CheckCapital(pArr[NEXTINDEX(i)]))
		{	// 앞글자가 같을 때 단어 전체 비교 ( 알파벳 순서 우선, 그 다음 길이 )
			if (CheckSameWord(pArr[i], pArr[1 + (i)]))
			{
				ptrTemp				= pArr[i];
				pArr[i]				= pArr[NEXTINDEX(i)];
				pArr[NEXTINDEX(i)]	= ptrTemp;

				iBreak = FALSE;
			}
		}

		if (CHECKOVERFLOW(NEXTINDEX(i), arrSize))
		{	// 배열의 [i + 1] 번째가 배열의 크기를 벗어난다면
			if (iBreak)
			{	// 모두 바뀌었다면 (iBreak가 1) 반복문 종료
				break;
			}

			// 반복문 다시 처음부터시작
			i = RESETLOOP;
		}

		iBreak = TRUE;	// 변경사항이있다면 0 으로 내려옴
	}					
}
//*/