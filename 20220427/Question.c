#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>		// Sleep() ���
#include <conio.h>			// _kbhit() ���

// Q1.	 int �� num1, num2 �� ����� ���ÿ� 10, 20 ���� �ʱ�ȭ
//		int �� ������ ptr1, ptr2 �� ����, �� num1�� num2 �� ����Ű���� �Ѵ�.
//		ptr1 �� ptr2 �� �̿��ؼ� num1 �� 10 ���� num2 �� 10 �����ϰ� �Ѵ�.
//		�� �� ptr1�� ptr2 �� ����Ű�� ����� �ٲ۴�.
//		���������� ptr1 �� ptr2 �� ����Ű�� ������ ������ ���.
//		AND... �� ������ ����� ���� ��� �� Ȯ���Ѵ�.
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

// Q2.	 261p ���� ���� ����
/*/
void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main()
{
	double max, mid, min;

	printf("�Ǽ� �� 3�� �Է� : ");
	scanf("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);		// ���� �Լ�
	printf("���ĵ� �� ��� : %.1lf, %.1lf, %.1lf\n", max, mid, min);
	
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

// Q3.	 ������ ���ڿ� ��� ���α׷��� �����͸� �̿��� �ڵ�� �ٲ� ���ۼ�
/*/
#define CHARMAX 256

char* CharInput(char* ch);			// �Է¹��� ���ڿ��� �ּҸ� ��ȯ
void Flowsignboard(char* ch);		// �帣�� ������ ������
char SwapCharPTR(char* a, char* b);	// Char�� �����͸� �޾� �� Swap
									// Swap �� �� ���ڸ� ��ȯ

int main()
{
	char chSign[CHARMAX] = "";		// �Է¹��� ���ڿ�

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
	char Temp = ' ';				// SWAP �� ���� �ӽ� ����

	while (!_kbhit())
	{
		puts(ch);

		for (int i = 0; i < CHARMAX; ++i)
		{
			if ((ch + i + 1) == '\0')	// NULL �϶� ���� �ݺ�
			{
				*(ch + i) = Temp;		// NULL �� �ٷ� �� ���ڸ� ù���ڷ� ����.
				break;
			}
			Temp = SwapCharPTR(ch + 1, ch + i + 1);
		}

		Sleep(150);				// ��� (150ms)
		system("cls");			// ȭ�� �����
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

// Q4.	 ���̰� 6�� int�� �迭 Arr�� ���� 1,2,3,4,5,6���� �ʱ�ȭ
//		�ʱ�ȭ �� ���� �迭�� ����� ���� ������ 6,5,4,3,2,1 ��
//		��, �迭�� �Ǿ�, �ǵ� �����ͺ��� �ΰ��� �����ؼ� �ٲٱ�.
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
//		������ ���� �Է¹޾Ƽ� ������ ����ϴ� ���α׷�.
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