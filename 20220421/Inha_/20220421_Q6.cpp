#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q6.	���� ���� �����ϴ� ��� A �� Z �� ���ϴ� ���α׷��� �ۼ��϶�

int main()
{
	int iNum = 0;

	while (iNum >= 0)
	{
		printf("�� �ڸ��� ���� �Է� (���� : -1) : ");
		scanf("%d", &iNum);

		if (iNum < 0)
			break;

		if ((iNum % 11 == 0) && iNum >= 10 && iNum < 100)
		{
			for (int i = 0; i <= iNum % 10; ++i)
			{
				printf("A = %d , Z = %d\n", i, (iNum % 10) - i);
			}
		}
		else if ((iNum % 11 == 0) && iNum >= 10 && iNum < 199)
		{
			int iTemp = 10;
			for (int i = (iNum % 10) + 1; i < 10; ++i)
			{
				printf("A = %d , Z = %d\n", i, --iTemp);
			}
		}
		else
		{
			printf("���� �������� �ʽ��ϴ� �ٽ� �Է� ���ּ���. \n");
		}
	}

	return 0;
}