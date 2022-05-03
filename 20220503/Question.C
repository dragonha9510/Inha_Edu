#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//	 Q1. 야구게임
//		세개의 숫자를 입력받고
//			1. 숫자가 있지만 위치가 다름	== 볼
//			2. 숫자와 위치가 맞으면		== 스트라이크
//			3. 숫자와 위치가 전부 틀리면	== 아웃
/*/
#include <windows.h>	// srand, rand
#include <time.h>		// time
#include <conio.h>		// getch	

#define BASEBALL				3
#define GAMEOVER				3
#define TRUE					1
#define FALSE					0
#define BETWEENZEROTONINE(t)	(t % 9) + 1
#define ESCAPEKEY				27
#define MAXPLAY					9

int MakeRandomBase(int iarr[], int size);
int CheckGameNum(int iarr[], int size);
void WrongInputMsg();

int main()
{
	srand((unsigned int)time(NULL));		// srand = rand함수의 시드값 부여
											// 시드는 시간으로 한다.
	int iBase[BASEBALL] = { 0 };			// 랜덤으로 3개의 정수
	int iGame[BASEBALL] = { 0 };			// 입력되는 3개의 정수

	int iStrike		= 0;					// strike 개수
	int iBall		= 0;					// ball 개수
	int iOut		= 0;					// out 횟수

	int iCnt		= 0;					// 게임 횟수
	int iCheckScanf = 0;					// 입력 확인

	if (!MakeRandomBase(iBase, BASEBALL))	// Random 3개 만들기
		return FALSE;

	// 실제 게임에선 해당 for문 주석처리 필요 TEST용 답지
	//for (int i = 0; i < BASEBALL; ++i)
	//	printf("%d\t", iBase[i]);

	printf("\n");

	while (TRUE)
	{
		iStrike = 0;
		iBall = 0;

		printf("%d > ", ++iCnt);
		iCheckScanf = scanf("%d %d %d", &iGame[0], &iGame[1], &iGame[2]);

		// 입력된 값에 중복 or 0 이 있는지 확인 없다면 scanf반환값 그대로 (문자열 입력시 Eroor 출력)
		iCheckScanf = (CheckGameNum(iGame, BASEBALL) == FALSE ? FALSE : iCheckScanf);

		if (iCheckScanf <= FALSE)
		{
			WrongInputMsg();
			rewind(stdin);
			--iCnt;
			continue;
		}

		for (int i = 0; i < BASEBALL; ++i)
		{
			if (iBase[i] == iGame[i])
				++iStrike;

			for (int j = 0; j < BASEBALL; ++j)
			{
				if (j != i && iBase[i] == iGame[j])
					++iBall;
			}
		}

		if (!iStrike && !iBall)
			++iOut;

		printf("\t=> %d Strike, %d Ball, %d Out \n", iStrike, iBall, iOut);

		if (iStrike == BASEBALL)
		{
			printf("!!!!!!!! YOU WIN !!!!!!!!");
		}
		else if (iOut == GAMEOVER || iCnt > MAXPLAY)
		{
			printf("..... YOU LOSE");
		}

		if (iStrike == BASEBALL || iOut == GAMEOVER)
		{
			printf("\n한번 더 하려면 아무키, 종료하려면 ESC 입력 \n");

			rewind(stdin);
			int isESC = _getch();

			if (isESC == ESCAPEKEY)
				return TRUE;
			else
			{
				system("cls");
				if (!MakeRandomBase(iBase, BASEBALL))	// Random 3개 만들기
					return FALSE;
				iOut = 0;
				iCnt = 0;
			}
		}
	}

	return TRUE;
}

void WrongInputMsg()
{
	printf("잘못된 입력입니다. 중복되었거나, 0을 입력했거나 또는 정수형이 아닙니다.\n");
}

int CheckGameNum(int iarr[], int size)
{
	int iRes = 0;
	for (int i = 0; i < size; ++i)
	{
		iRes = iarr[i] == 0 ? FALSE : TRUE;
		// 입력된 값이 0이라면 FALSE return
		if (iRes == FALSE)
			return iRes;
	}

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (i != j && iarr[i] == iarr[j])	// 중복된 값이라면 FALSE return
				return iRes = FALSE;
		}
	}

	return iRes; // 남은 모든 경우 TRUE
}

int MakeRandomBase(int iarr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		while (iarr[i] == 0)	// 0이 아닌 값을 우선 받음.
			iarr[i] = BETWEENZEROTONINE(rand());

		for (int j = 0; j < i; ++j)	// 뽑은 값이 중복인지 확인
		{
			if ((i != j) && (iarr[i] == iarr[j]))
			{
				while (iarr[i] == iarr[j])
				{	// 중복이라면 다시 Rand
					iarr[i] = BETWEENZEROTONINE(rand());
				}
			}
		}
	}

	return TRUE;
}
//*/

//	 Q2. 다음과 같은 두 개의 int형 포인터 변수와 길이가 5인 int형 배열을 선언
//		int* maxPtr;
//		int* minPtr;
//		int arr[5];
//		
//		MaxAndMin 이란 함수를 정의하고 이를 호출하여
//		위 배열과 두 포인터를 변수로 전달, 이 함수의 호출이 완료되면, 포인터 변수 
//		maxPtr에는 가장 큰 값이 저장된 배열 요소의 주소 값,
//		minPtr에는 가장 작은 배열 요소의 주소값이 저장
//
//		결과 출력 >
//				arr 주소 값, 최대 최소의 주소 값
/*/
void MaxAndMin(int** max, int** min, int arr[], int arrsize);

int main()
{
	int iArr[5] = { 5,3,1,4,2 };
	int* ptrMax = NULL;
	int* ptrMin = NULL;

	int iArrSize = sizeof(iArr) / sizeof(iArr[0]);

	MaxAndMin(&ptrMax, &ptrMin, iArr, iArrSize);

	printf("arr 주소 값,\t%p\n", iArr);
	printf("최대 값 주소,\t%p\t%d\n", ptrMax, *ptrMax);
	printf("최소 값 주소,\t%p\t%d\n", ptrMin, *ptrMin);

	return 0;
}

void MaxAndMin(int** max, int** min, int arr[], int arrsize)
{
	int iMin = arr[0];
	*min = &arr[0];

	int iMax = 0;

	for (int i = 0; i < arrsize; ++i)
	{
		if (iMax < arr[i])
		{
			iMax = arr[i];
			*max = &arr[i];
		}

		if (iMin > arr[i])
		{
			iMin = arr[i];
			*min = &arr[i];
		}
	}
}
//*/

//	 Q3. 도전 실전 예제 p448
/*/
void swap(char* ch, void* a, void* b);

int main()
{
	int iA = 0;
	int iB = 0;

	double dA = 0;
	double dB = 0;

	printf("첫 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &iA, &dA);
	printf("두 번째 사람의 나이와 키 입력 : ");
	scanf("%d %lf", &iB, &dB);

	swap("int", &iA, &iB);
	swap("double", &dA, &dB);

	printf("첫 번째 사람의 나이와 키 : %d, %.1lf\n", iA, dA);
	printf("두 번째 사람의 나이와 키 : %d, %.1lf", iB, dB);

	return 0;
}

void swap(char* ch, void* a, void* b)
{
	if (!strcmp(ch, "int"))
	{
		int Temp = *(int*)a;
		*(int*)a = *(int*)b;
		*(int*)b = Temp;
	}
	else
	{
		double Temp = *(double*)a;
		*(double*)a = *(double*)b;
		*(double*)b = Temp;
	}
}
//*/

//	 Q4. 사용자로부터 문자열을 입력 받아 단어를 역으로 출력하는 프로그램
//		Quit 입력시 종료
/*/
#define BUFFERMAX 80

int main()
{
	char chInput[BUFFERMAX] = {'\0'};
	char chTemp[BUFFERMAX] = {'\0'};
	char* chBase;
	char* ptrCh;

	while (1)
	{
		printf("문자열 입력 : ");
		gets_s(chInput, BUFFERMAX);
		chBase = (char*)malloc(strlen(chInput) + 1);
		strcpy(chBase, chInput);

		if (!strcmp(chBase, "Quit"))
		{
			free(chBase);
			break;
		}   // 종료

		int iCnt = 0;

		for (int i = BUFFERMAX - 1; i >= 0; --i)
		{
			if (chInput[i - 1] == ' ' || i == 0)
			{
				for (int j = 0; j < BUFFERMAX; ++j)
				{
					if ('\0' == chInput[i + j] || ' ' == chInput[i + j])
					{
						iCnt += j;
						break;
					}
					chTemp[iCnt + j] = chInput[i + j];
				}
				chTemp[iCnt++] = ' ';
			}
		}

		chTemp[iCnt] = '\0';

		ptrCh = (char*)malloc(strlen(chTemp) + 1);
		strcpy(ptrCh, chTemp);

		printf("%s\n", ptrCh);

		free(chBase);
		free(ptrCh);
	}

	return 0;
}
//*/

//*/
#define BUFFERMAX 80

char* strTok(char* str, char* delimiters);
int strLen(char* str);

int main()
{
	char chInput[BUFFERMAX] = { '\0' };
	char chTemp[BUFFERMAX] = { '\0' };
	char* ptrCh;

	while (1)
	{
		printf("문자열 입력 : ");
		gets_s(chInput, BUFFERMAX);
		ptrCh = (char*)malloc(strLen(chInput) + 1);
		memset(ptrCh, 0, strLen(chInput) + 1);
		strcpy(ptrCh, chInput);

		if (!strcmp(ptrCh, "Quit"))
		{
			free(ptrCh);
			break;
		}   // 종료

		char* chTemp = strTok(ptrCh, " ");
		while (chTemp != NULL)
		{
			printf("%s\n", chTemp);
			chTemp = strTok(NULL, " ");
		}

		free(ptrCh);
	}
	return 0;
}

int strLen(char* str) 
{
	int cnt = 0;
	while (str[cnt] != '\0') 
	{
		++cnt;
	}
	return cnt;
}

char* strTok(char* str, char* delimiters)
{
	static char* temp = NULL;

	if (!temp && str != NULL)
		temp = str;
	else if (!temp && str == NULL)
		return NULL;

	char* tempCutCh = temp;

	while (1) 
	{ 
		if (*tempCutCh == *delimiters)
		{
			*tempCutCh = '\0';
			return temp;
		}
		else if (*tempCutCh == '\0')
		{
			temp = NULL;
			return NULL;
		}

		++tempCutCh;
	}

	return str;
}
//*/