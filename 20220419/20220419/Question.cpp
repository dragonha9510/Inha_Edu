
#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#include <iostream>
#include <string.h>

using namespace std;

// Q1 . ���̸� �Է� �޾Ƽ� �ش� ������ ���ɴ븦 �������.

/*//Q1

int main()
{
	int iScanTemp;				// scanf ��ȯ �� ó���� ���� ����

	int iAge = 0;				// �Էµ� ����
	int iAgeGroup = 0;			// �Էµ� ������ ���ɴ�

	printf("���̸� �Է��� �ּ��� : ");

	iScanTemp =scanf("%d", &iAge);

	while (iAge == 0)
	{
		system("cls");
		printf("�߸��� �Է��Դϴ� �ٽ� �Է����ּ���. \n ���̸� �Է��� �ּ��� : ");
	}

	iAgeGroup = iAge / 10;

	printf("����� %d �� �Դϴ�.", iAgeGroup * 10);
	printf("����� %d ��� �Դϴ�.", 2023 - iAge);

	return 0;
}

//*/

// Q2 . �ΰ� ������ 100�� �̶�� �����ϰ�, ��� �� ���Ǹ� �Ǹ� ������ 3�ð� 40�� ����ȴٰ� �Ѵ�.
//      � ����� ������ �� ���� N�Ⱓ �Ϸ翡 M���Ǿ� ��踦 �ǿ��ٸ� ������ �󸶳� ����Ǿ���
//      �� ����� �� �� �ִ°�?
//         -> �پ�� ���� : �� �� ��
//         -> ���   ���� : �� �� �� ��  
//		   -> N = 20, M = 3

/*// Q2

#define YEAR 365				// 1�� 365��
#define DAY 24					// �Ϸ� 24�ð�
#define MINUTE 60				// 1�ð� -> 60��
#define SMOKETIME 220			// ���� ���� ������� 3�ð� 40��
#define MAXIMUMLIFE 52560000    // 100������� ��
#define ADULT 19				// ���� 20�� ���� -> 19������ �� �Ұ�.

int main()
{
	int iScnafTemp = 0;			// scanf ��ȯ �� ó���� ���� ����

	int iAge = 0;				// ����
	int iAgeMinute = 0;			// ���� (�� ����)
	int iSmokeCnt = 0;			// �Ϸ��� ����
	int iLifeExpectancy = 0;	// ��� ����
	int iWasteLife = 0;			// �پ�� ����

	printf("���̸� �Է��� �ּ��� : ");
	iScnafTemp = scanf("%d", &iAge);

	while (iAge == 0)		// 0�� �Է�
	{
		system("cls");
		printf("�߸��� �Է��Դϴ� �ٽ� �Է����ּ���. \n ���̸� �Է��� �ּ��� : ");
	}

	if(iAge <= 19)
	{
		printf("�̼����ڴ� ���� ���� ����� �ƴմϴ�.");
		system("pause");
		
		return -1;
	}

	printf("\n�Ϸ� ������ �Է��� �ּ��� : ");
	iScnafTemp = scanf("%d", &iSmokeCnt);

	system("cls");

	// ���� ������ ��ȯ
	iAgeMinute = iAge * YEAR * DAY * MINUTE;
	iSmokeCnt *= SMOKETIME;
	iWasteLife = iSmokeCnt * ((iAge - ADULT) * YEAR);
	iLifeExpectancy = MAXIMUMLIFE - iWasteLife;

	int iLeftAge = 0;		// ���� ����
	int iYear = 0;			// ��
	int iDay = 0;			// ��
	int iHour = 0;			// ��
	int iMinute = 0;		// ��

	///////////////////////////////////////////
	// ���� �ð����� ����
	///////////////////////////////////////////
	
	iMinute = iWasteLife % MINUTE;
	iHour = (iWasteLife / MINUTE) % DAY;
	iDay = ((iWasteLife / MINUTE) / DAY) % YEAR;
	iYear = ((iWasteLife / MINUTE) / DAY) / YEAR;

	printf("����� �پ�� ������ : %d �� %d �� %d �ð� %d��", iYear, iDay, iHour, iMinute);

	iMinute = iLifeExpectancy % MINUTE;
	iHour = (iLifeExpectancy / MINUTE) % DAY;
	iDay = ((iLifeExpectancy / MINUTE) / DAY) % YEAR;
	iLeftAge = ((iLifeExpectancy / MINUTE) / DAY) / YEAR;

	printf("�����  ���  ������ : %d �� %d �� %d �ð� %d��", iLeftAge, iDay, iHour, iMinute);
}

//*/

/*// Q2
//#define YEAR 365				// 1�� 365��
//#define DAY 24				// �Ϸ� 24�ð�
//#define MINUTE 60				// 1�ð� -> 60��
//#define SMOKETIME 220			// ���� ���� ������� 3�ð� 40��
//#define MAXIMUMLIFE 52560000  // 100������� ��
//#define ADULT 19				// ���� 20�� ���� -> 19������ �� �Ұ�.

int main()
{
	const int ciYEAR		= 365;			// 1�� 365��
	const int ciDAY			= 24;			// �Ϸ� 24�ð�
	const int ciMINUTE		= 60;			// 1�ð� -> 60��
	const int ciSMOKETIME	= 220;			// ���� ���� ������� 3�ð� 40��
	const int ciMAXIMUMLIFE = 52560000;		// 100������� ��

	int iScnafTemp	= 0;						// scanf ��ȯ �� ó���� ���� ����

	int iSmokeYear		= 0;				// ��Ⱓ
	int iSmokeCnt		= 0;				// �Ϸ��� ����
	int iLifeExpectancy = 0;				// ��� ����
	int iWasteLife		= 0;				// �پ�� ����

	printf("�� �Ⱓ ���ߴ��� �Է��� �ּ��� : ");
	iScnafTemp = scanf("%d", &iSmokeYear);

	printf("\n�Ϸ� ������ �Է��� �ּ��� : ");
	iScnafTemp = scanf("%d", &iSmokeCnt);

	// ���ݱ����� ���� ���
	iSmokeCnt *= ciSMOKETIME;
	iWasteLife = iSmokeCnt * (iSmokeYear * ciYEAR);

	// ��� ���� ��� (100�� ����)
	iLifeExpectancy = ciMAXIMUMLIFE - iWasteLife;

	int iLeftAge	= 0;		// ���� ����
	int iYear		= 0;		// ��
	int iDay		= 0;		// ��
	int iHour		= 0;		// ��
	int iMinute		= 0;		// ��

	///////////////////////////////////////////
	//       ���� �ð�, ��, ������ ����       //
	///////////////////////////////////////////

	iMinute = iWasteLife % ciMINUTE;
	iHour	= (iWasteLife / ciMINUTE) % ciDAY;
	iDay	= ((iWasteLife / ciMINUTE) / ciDAY) % ciYEAR;
	iYear	= ((iWasteLife / ciMINUTE) / ciDAY) / ciYEAR;
	
	printf("\n ����� �پ�� ������ : %d �� %d �� %d �ð� %d�� \n", iYear, iDay, iHour, iMinute);

	iMinute	 = iLifeExpectancy % ciMINUTE;
	iHour	 = (iLifeExpectancy / ciMINUTE) % ciDAY;
	iDay	 = ((iLifeExpectancy / ciMINUTE) / ciDAY) % ciYEAR;
	iLeftAge = ((iLifeExpectancy / ciMINUTE) / ciDAY) / ciYEAR;

	printf("�����  ���  ������ : %d �� %d �� %d �ð� %d�� \n", iLeftAge, iDay, iHour, iMinute);

	system("pause");
}

//*/

// Q3 . ����ڷκ��� ���� 3���� �Է¹޾� �����ϰ�
//		���� �����ڸ� ����Ͽ� �̵� ���� �� ���� ū ���� ����ϴ� ���α׷�

/*//
int main()
{
	int iScanfTemp = 0;	//Scanf ��ȯ �� ó�� ����

	int iFirst	= 0;	// ù��° �Է� ����
	int iSecond = 0;	// �ι�° �Է� ����
	int iThird  = 0;	// ����° �Է� ����

	printf("������ ���� 3���� �Է� ��Ź�帳�ϴ�.\n");
	iScanfTemp = scanf("%d %d %d", &iFirst, &iSecond, &iThird);

	iFirst = (iFirst > iSecond) ? 
	((iFirst > iThird) ? iFirst : iThird) : 
	((iSecond > iThird) ? iSecond : iThird);

	printf("���� ū �� : %d", iFirst);

	return 0;
}
/*/