#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q5.  2 �̻��� ������ �Է� �޾� 2���� �Է¹��� ���������� ��� �Ҽ��� ���.
//		��, ���ٿ� 5���� ����Ѵ�.

void PrintPrimeNumber(int ia = 0);		// �Ҽ��� ����ϴ� �Լ�
int GetNumber();						// ������ �Է¹��� �Լ�

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
		if ((i % 2) && (i % 3) && (i % 5) && (i % 7) 
			|| i == 2 || i == 3 || i == 5 || i == 7)				// �Ҽ���� 0 �� �ƴ� ���� ��ȯ if �� ����
		{
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
	int iRes = 0;
	int iBreak = 0;

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