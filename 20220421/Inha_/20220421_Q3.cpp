#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q3. ���Ǽ� n�� �Է� �޾Ƽ� ������ ���� ���·� ����Ͻÿ�.
//*/
//		ex) n = 5
//
//		*   *
//		 * *
//		  *
//		 * *
//		*   *		0, 4 -> 1, 3 -> 2
//
//		ex) n = 4
//		*  *		0, 3 -> 1, 2
//		 **
//		 **
//		*  *

int main()
{
	int iNum = 0;	// �Է¹��� ����

	int iFront		= 0;	// �� * ��ġ
	int iBack		= 0;	// �� * ��ġ

	int iScanTemp = scanf("%d", &iNum);

	iBack = iNum - 1;		// ��ǻ���� �迭�� 0 ���� ���� (���� - 1) �� ������

	for (int i = 0; i < iNum; ++i)
	{
		for (int j = 0; j < iNum; ++j)
		{
			if (j == iFront || j == iBack)	// Front�� Back�� �ڸ����� * �Է�
				printf("*");
			else
				printf(" ");
		}

		++iFront;		// Front�� ��� �ڷ� �̵�.
		--iBack;		// Back�� ��� ������ �̵�.

		printf("\n");
	}

	return 0;
}

//*/