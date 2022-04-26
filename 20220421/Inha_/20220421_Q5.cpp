#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q5.  2 �̻��� ������ �Է� �޾� 2���� �Է¹��� ���������� ��� �Ҽ��� ���.
//		��, ���ٿ� 5���� ����Ѵ�.

void PrintPrimeNumber(int ia = 0);		// �Ҽ��� ����ϴ� �Լ�
int GetNumber();						// ������ �Է¹��� �Լ�
int CheckPrime(int ia);					// �Ҽ����� Ȯ���ϴ� �Լ�

int main() 
{
	PrintPrimeNumber(GetNumber());		// ������ �޾Ƽ� �Ҽ��� �������

	return 0;
}

void PrintPrimeNumber(int ia) 
{
	int iCnt = 0;
	for (int i = 2; i <= ia; ++i)		// �Ҽ��� 2���� �Է��� ������ Ȯ���Ѵ�.
	{
		if (CheckPrime(i))
		{								// �Ҽ���� 0 �� �ƴ� ���� ��ȯ if �� ����
			printf("%d\t", i);

			++iCnt;						// 5 �� ����ߴٸ� ����

			if (iCnt == 5) 
			{
				iCnt = 0;
				printf("\n");
			}
		}
	}
}

int GetNumber() 
{
	int iRes	= 0;
	int iBreak	= 0;

	while (!iBreak) 
	{
		printf("2 �̻��� ������ �Է� �ٶ��ϴ� : ");

		iBreak = scanf("%d", &iRes);

		if (iBreak != 0 && iRes >= 2)
			break;
		else
			iBreak = 0;
	} 

	return iRes;
}

int CheckPrime(int ia) 
{
	for (int i = 2; i <= (ia / 2); ++i)		// ia�� ���� ��ŭ �˻��Ѵ�.
		if (ia % i == 0)					//	ex ) ia = 10   >> 2, 3, 4, 5
			return 0;						// 		2�� ������ ���� ������ ���� ( 0 ��ȯ )
	
	return ia;								//	ex ) ia = 17   >> 2, 3...7, 8
}											//		���������� ���� ���� ������ ���� ( ia�� �״�� ��ȯ )