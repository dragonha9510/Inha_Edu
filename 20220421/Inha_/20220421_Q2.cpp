#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

// Q2. ���Ǽ� n�� �Է� �޾Ƽ� ������ ���� ���·� ����Ͻÿ�.
//*/
//		ex) n = 5
//
//		*   *
//		** **
//		*****
//		** **
//		*   *		0, 4 -> 1, 3 -> 2
//
//		ex) n = 4
//		*  *		0, 3 -> 1, 2
//		****
//		****
//		*  *

int main()
{
	int iNum		= 0;	// �Է¹��� ����

	int iFront		= 0;	// �� * ��ġ
	int iBack		= 0;	// �� * ��ġ
	int iReverse	= 0;	// ����
	int iOddCheck	= 0;	// ¦ Ȧ Ȯ��	Ȧ����� 1 ¦����� 0

	int iScanTemp = scanf("%d", &iNum);

	iBack		= iNum - 1;
	iOddCheck	= iNum % 2;

	for (int i = 0; i < iNum; ++i)
	{
		for (int j = 0; j < iNum; ++j)
		{
			if (j <= iFront || j >= iBack)	// ���� Front�� Back��ġ �յڸ� ���
				printf("*");				// * �� ä���.
			else
				printf(" ");
		}

		if (!iReverse)						// �������� �ʾ��� ��
		{
			if (iOddCheck)					// Ȧ�����
			{
				++iFront;
				--iBack;

				if (iFront == iBack)		// ���������� ����. ���� ���� ����
				{
					iReverse = 1;
				}
			}
			else							// ¦�����
			{
				++iFront;
				--iBack;

				if (iFront > iBack)			// ���������� Front�� Back�� ������ ��
				{
					iReverse = 1;
					--iFront;
					++iBack;
				}
			}
		}
		else								// ���� ����
		{
			--iFront;
			++iBack;
		}

		printf("\n");
	}

	return 0;
}

//*/