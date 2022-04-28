#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>		// Sleep() 사용
#include <conio.h>			// _kbhit() 사용

// Q1.	 int 형 num1, num2 를 선언과 동시에 10, 20 으로 초기화
//		int 형 포인터 ptr1, ptr2 를 선언, 각 num1과 num2 를 가르키도록 한다.
//		ptr1 과 ptr2 를 이용해서 num1 은 10 증가 num2 는 10 감소하게 한다.
//		이 후 ptr1과 ptr2 가 가리키는 대상을 바꾼다.
//		마지막으로 ptr1 과 ptr2 가 가리키는 변수의 내용을 출력.
//		AND... 각 변수에 저장된 값도 출력 및 확인한다.
/*/
// 

void SwapPTR(int** a, int** b)
{
	int* ptrTemp = *a;
	*a = *b;
	*b = ptrTemp;
	ptrTemp = NULL;
}

void SwapValue(int* a, int* b)
{
	int iTemp = *a;
	*a = *b;
	*b = iTemp;
}

int main()
{
	int num1 = 10;
	int num2 = 20;

	int* ptr1 = &num1;
	int* ptr2 = &num2;

	*ptr1 += 10;
	*ptr2 -= 10;

	SwapPTR(&ptr1, &ptr2);

	printf("num1\t:\t%d\n", num1);
	printf("num2\t:\t%d\n", num2);
	printf("ptr1\t:\t%d\n", *ptr1);
	printf("ptr2\t:\t%d\n", *ptr2);

	SwapValue(&num1, &num2);
	printf("\n");
	printf("num1\t:\t%d\n", num1);
	printf("num2\t:\t%d\n", num2);

	return 0;
}

//*/

// Q2.	 261p 도전 실전 예제
/*/
void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main()
{
	double max, mid, min;

	printf("실수 값 3개 입력 : ");
	scanf("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);		// 정렬 함수
	printf("정렬된 값 출력 : %.1lf, %.1lf, %.1lf\n", max, mid, min);
	
	return 0;
}

void swap(double* pa, double* pb)
{
	double temp;
	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void line_up(double* maxp, double* midp, double* minp)
{
	if (*midp < *minp)
	{
		swap(midp, minp);

		if (*midp > *maxp)
			swap(maxp, midp);
	}
}
//*/

// Q3.	 광고판 문자열 출력 프로그램을 포인터를 이용한 코드로 바꿔 재작성
/*/
#define CHARMAX 256

char* CharInput(char* ch);			// 입력받은 문자열의 주소를 반환
void Flowsignboard(char* ch);		// 흐르는 광고판 구현부
char SwapCharPTR(char* a, char* b);	// Char형 포인터를 받아 값 Swap
									// Swap 후 앞 글자를 반환

int main()
{
	char chSign[CHARMAX] = "";		// 입력받을 문자열

	Flowsignboard(CharInput(chSign));

	return 0;
}

char* CharInput(char* ch)
{
	gets_s(ch, CHARMAX);
	strcat(ch, " ");

	return ch;
}

void Flowsignboard(char* ch)
{
	char Temp = ' ';				// SWAP 을 위한 임시 변수

	while (!_kbhit())
	{
		puts(ch);

		for (int i = 0; i < CHARMAX; ++i)
		{
			if ((ch + i + 1) == '\0')	// NULL 일때 까지 반복
			{
				*(ch + i) = Temp;		// NULL 의 바로 앞 문자를 첫문자로 변경.
				break;
			}
			Temp = SwapCharPTR(ch + 1, ch + i + 1);
		}

		Sleep(150);				// 대기 (150ms)
		system("cls");			// 화면 지우기
	}
}

char SwapCharPTR(char* a, char* b)
{
	char ptrTemp = *a;
	*a = *b;
	*b = ptrTemp;

	return ptrTemp;
}

//*/

// Q4.	 길이가 6인 int형 배열 Arr을 선언 1,2,3,4,5,6으로 초기화
//		초기화 한 다음 배열에 저장된 값의 순서가 6,5,4,3,2,1 로
//		단, 배열의 맨앞, 맨뒤 포인터변수 두개를 선언해서 바꾸기.
//*/
int flip(int* front, int* back);

int main()
{
	int iArr[6] = { 1,2,3,4,5,6 };

	flip(iArr, iArr + 5);

	for (int i = 0; i < 6; ++i)
		printf("%d\t", iArr[i]);

	return 0;
}

int flip(int* front, int* back)
{
	int Temp = 0;
	int iSize = ((back - front) + 1) / 2;

	for (int i = 0; i < iSize; ++i)
	{
		Temp = *(front + i);
		*(front + i) = *(back - i);
		*(back - i) = Temp;
	}

	return 0;
}
//*/

// Q4 - 1.
//		임의의 값을 입력받아서 뒤집어 출력하는 프로그램.
/*/
#define CHARMAX 256

int flip(char* front, char* back);
int strLength(char* ch);
char* CharInput(char* ch);

int main()
{
	char chArr[256];

	CharInput(chArr);

	flip(chArr, chArr + (strLength(chArr) - 1));

	printf("%s", chArr);

	return 0;
}


int flip(char* front, char* back)
{
	char Temp = 0;
	int iSize = ((back - front)) / 2;

	for (int i = 0; i < iSize; ++i)
	{
		Temp = *(front + i);
		*(front + i) = *(back - i);
		*(back - i) = Temp;
	}

	return 0;
}

char* CharInput(char* ch)
{
	gets_s(ch, CHARMAX);

	return ch;
}

int strLength(char* ch)
{
	int iCnt = 0;

	for (int i = 0; i < CHARMAX; ++i)
	{
		if (*(ch + i) == '\0')
			return iCnt;

		++iCnt;
	}

	return 0;
}
//*/