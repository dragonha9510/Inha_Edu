#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:6031)

#include <iostream>

using namespace std;

/*/
// Q1.   �� ���� ������ �Է� �޾� �� ���� ���� ����ϴ� ���α׷��� �ۼ��϶�.
//		��, ū ������ ���� ���� �����Ѵ�.
//		case 1. if ~ else ���� �̿�
//		case 2. ���� �����ڸ� �̿�
int main()
{
	//// case 1.

	//int iFirst	= 0;		// �Է¹��� ù ��° ����
	//int iSecond = 0;		// �Է¹��� �� ��° ����

	//scanf("%d", &iFirst);
	//rewind(stdin);			// �Է� ���� ����. 
	//scanf("%d", &iSecond);

	//if (iFirst > iSecond)
	//{
	//	printf("�� ���� �� : %d", iFirst - iSecond);
	//}
	//else
	//{
	//	printf("�� ���� �� : %d", iSecond - iFirst);
	//}

	///////////////////////////////////////////////////////////////////////////////////////
	// case 2.

	int iFirst	= 0;		// �Է¹��� ù ��° ����
	int iSecond = 0;		// �Է¹��� �� ��° ����

	scanf("%d", &iFirst);
	rewind(stdin);			// �Է� ���� ����. 
	scanf("%d", &iSecond);

	printf("�� ���� �� : %d", (iFirst > iSecond ? iFirst - iSecond : iSecond - iFirst));

	return 0;
}
//*/

/*/
// Q2.	 �л��� ��ü ��� ������ ���� ������ ����ϴ� ���α׷� �ۼ�.
//		������ 90�� �̻� A ,
//		������ 80�� �̻� B ,
//		������ 70�� �̻� C ,
//		������ 60�� �̻� D ,
//		�� �̸��� F�� ó��.
// 
//		 ���α׷� ����� ����, ����, ������ ������ �Է� �ް�
//		�� ����� ���Ͽ� ���� ����ǥ�� �������� ������ ����϶�.
//

int main()
{
	const int iClassCnt = 3;

	int iKorean		= 0;	// ���� ����
	int iMath		= 0;	// ���� ����
	int iEnglish	= 0;	// ���� ����
	int iAverage	= 0;	// ��� ����
	char chScore	= ' ';	// ���� ����

	printf("���� ���� �Է� : ");
	scanf("%d", &iKorean);
	rewind(stdin);					// �Է� ���� ����.

	printf("���� ���� �Է� : ");
	scanf("%d", &iEnglish);
	rewind(stdin);

	printf("���� ���� �Է� : ");
	scanf("%d", &iMath);
	rewind(stdin);

	iAverage = (iKorean + iEnglish + iMath) / iClassCnt;		// ��� ���

	if (iAverage >= 90)
	{
		chScore = 'A';
	}
	else if (iAverage >= 80)
	{
		chScore = 'B';
	}
	else if (iAverage >= 70)
	{
		chScore = 'C';
	}
	else if (iAverage >= 60)
	{
		chScore = 'D';
	}
	else
	{
		chScore = 'F';
	}

	printf("��� ������ : %d\n", iAverage);
	printf("���� ������ : %c", chScore);

	return 0;
}
//*/

/*/
// Q3. � �ڿ����� �Է� �޾� ! ( ���丮�� )�� ���ϴ� ���α׷��� �ۼ��϶�

int main()
{
	unsigned long long llNum = 0;		// �ڿ��� �Է¹��� ����
	unsigned long long llFac = 1;		// ��µ� ���丮�� ��� ��.	( * 0 �� 0�̱� ������ 1�� �ʱ�ȭ )

	printf("�ڿ��� �Է� : ");
	scanf("%llu", &llNum);
	rewind(stdin);

	for (unsigned long long i = llNum; i > 0; --i)
	{
		llFac *= i;
	}

	printf("���丮�� �� : %llu", llFac);

	return 0;
}

//*/

/*/
// Q4.	 �� ���� �Է¹޾� �� �� ���̿� �����ϴ� ������ ���� ���ϴ� ���α׷��� �ۼ��϶�

int main()
{
	int iFirst	= 0;				// ù ��° ����	( ū �� )
	int iSecond = 0;				// �� ��° ����  ( ���� �� )
	int iRes	= 0;				// ��� ��.

	printf("�� ���� ������ �Է��Ͽ� �ּ���.");

	printf("ù ��° : ");
	scanf("%d", &iFirst);

	rewind(stdin);					// �Է� ���� �ʱ�ȭ

	printf("�� ��° : ");
	scanf("%d", &iSecond);

	if (iFirst > iSecond ? 0 : 1)	// Swap ( Second �� �� ũ�ٸ� First �� Second �� swap)
	{
		int iTemp = iSecond;
		iSecond = iFirst;
		iFirst	= iTemp;
	}

	for (int i = iFirst;
		i >= iSecond;
		--i) {
		iRes += i;
	}

	printf("�� �� ���̸� ��� ���� �� : %d", iRes);

	return 0;
}
//*/

/*/
// Q5.	 ����ڷκ��� ���� ������ m �� n �� �Է� �޾�
//		n �� ��ŭ m �� ����� ����ϴ� ���α׷��� �ۼ�.

int main()
{
	int iFirst	= 0;		// N ( ���� )
	int iSecond = 0;		// M ( ���� �� )

	printf("���� �Է� : ");
	scanf("%d", &iFirst);

	rewind(stdin);			// �Է� ���� �ʱ�ȭ

	printf("���� �� �Է� : ");
	scanf("%d", &iSecond);

	for (int i = 0; i < iFirst; ++i)
	{
		// * 0 = 0 �̱� ������ (i + 1) 1 ���� ����.
		printf("%d \n", iSecond * (i + 1));
	}

	return 0;
}

//*/

/*/
// Q5.	 ����ڷκ��� ��� ������ �Է¹޾� �� ���� ��� ���� ������.
//		����ڰ� 0�� �Է� �Ҷ����� ��� �Ǿ�� �ϸ�, 0 �� �ԷµǸ�
//		�Էµ� ��� ������ ���� ����Ѵ�.

int main()
{
	int iSum	= 0;	// �Է� ���� ����.
	int iResult = 0;	// ����� ������ ����.

	do
	{
		printf("�Է��ϴ� ��� ���� ���� �帳�ϴ�. \n");
		printf("��� ���� �� ���� : 0 \n �Է� : ");

		scanf("%d", &iSum);
		rewind(stdin);

		iResult += iSum;		// ��� ������ ���� ��� ����

		system("cls");			// cmd â�� �ʱ�ȭ
	} while (iSum != 0);

	printf("���� !  ��� �� -> %d", iResult);

	return 0;
}
//*/

//*/
// Q7.	 1 �̻� 100 �̸��� ���� m �� n �� ����� ����ϴ� ���α׷��� �ۼ��϶�.
//		��, m �� ����̸鼭 n �� ����� ������ �ѹ��� ����ؾ� �Ѵ�.
//		ex) m = 7, n = 9 -> 7, 9, 14, 18, 27, 28, 35, 36 ~~ 63

int main()
{
	int iFirst	= 0;	// M		���� ��
	int iSecond = 0;	// N		ū ��

	while (1)			// �ԷµǴ� ���� �������� While���� �����ϱ� ������ �׻� TRUE
	{
		printf("1 �̻��� ������ �� �� �Է��� �ּ���. \n");

		printf("�Է� : ");
		scanf("%d", &iFirst);

		rewind(stdin);

		printf("�Է� : ");
		scanf("%d", &iSecond);

		if ((iFirst >= 1 && iSecond >= 1) 
			&& (iFirst < 100 && iSecond < 100))
			break;

		system("cls");

		printf("�ϳ��� ���� Ȥ�� ��� ������ 0 Ȥ�� 100�� �ʰ��� ���Դϴ�. �ٽ� �Է����ּ���. \n");
	}

	if (iFirst > iSecond ? 1 : 0)		// Swap : ���� ���� First�� ū ���� Second�� Swap
	{
		int iTemp	= iSecond;
		iSecond		= iFirst;
		iFirst		= iTemp;
	}

	int iFRes		= 0;	// ���� ���� ������� ����ϱ� ���� ����
	int iSRes		= 0;	// ū ���� ������� ����ϱ� ���� ����
	int iMulF		= 0;	// ���� ���� ����� ���ϱ� ���� ����
	int iMulS		= 0;	// ū ���� ����� ���ϱ� ���� ����

	iFRes = iFirst;			// iFirst * 1 = iFirst
	iSRes = iSecond;		// iSecond * 1 = iSecond
	iMulS = 1;				// iSecond�� ��� ���� ó���� ���� 1���� ���� ���ǹ� ��� �� ����

	while (1)
	{
		if (iSRes > 100 && iFRes > 100)		// First�� Second�� ��� 100�� �Ѿ��ٸ� ����
			break;

		iFRes = iFirst * (++iMulF);			// �� ����� ���
		iSRes = iSecond * iMulS;

		if (iFRes > iSRes)					// ��� ���� ������ ���� ���ǹ� iSecond�� iFirst����
		{									// ���� ���� ����� ������Ű�� iSecond�� ����Ѵ�.
			++iMulS;						// iSecond�� ��� ����.

			if (iSRes % iFirst)				// iFirst�� ������ ������ ������� �ʴ´� 
			{								// ( �ش� ���� iFRes �� ����Ѵ�. )
				if(iSRes < 100)				// iSRes �� 100 �̻��� ���� ������� �ʱ� ���� ����ó��
					printf("%d\n", iSRes);
			}
		}

		if(iFRes < 100)						// iFRes �� 100 �̻��� ���� ������� �ʱ� ���� ����ó��
			printf("%d\n", iFRes);
	}

	return 0;
}

//*/

/*/
// Q8 �����

int main()
{
	int iInput = 0;

	scanf("%d", &iInput);

	for (int i = 0; i < iInput; ++i)
	{
		for (int j = iInput; j > 0; --j)
		{
			if (i + 1 < j)
				printf(" ");
			else
				printf("*");
		}
		cout << endl;
	}

	printf("\n");


	for (int i = 0; i < iInput; ++i)
	{
		for (int j = 0; j < iInput; ++j)
		{
			if (i < j)
				printf(" ");
			else
				printf("*");
		}
		cout << endl;
	}
}

//*/