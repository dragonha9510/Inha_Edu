#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <Windows.h>		// Sleep() ���
#include <conio.h>			// _kbhit() ���

//Q6.	 p232 ��ҹ��� ��ȯ ���α׷�.
//		�޴� : 1.�빮�ڷ� ��ȯ , 2. �ҹ��ڷ� ��ȯ, 0. ����
//
/*/
int CharConvert(int a, char* ch)
{
	int iCnt = 0;

	switch (a)
	{
	case 1:
		for (unsigned int i = 0; i < strlen(ch); ++i)
		{
			if (ch[i] <= 'z' && ch[i] >= 'a')
			{
				ch[i] -= 32;
				++iCnt;
			}
		}
		break;
	case 2:
		for (unsigned int i = 0; i < strlen(ch); ++i)
		{
			if (ch[i] <= 'Z' && ch[i] >= 'A')
			{
				ch[i] += 32;
				++iCnt;
			}
		}
		break;
	case 0:
		return -1;
	default:
		break;
	}

	printf("��ȯ�� ���ڿ�\t: ");
	puts(ch);

	return iCnt;
}

int main()
{
	int iSel = 0;
	char chChange[256];

	while (1)
	{
		printf("1. �빮�ڷ�! , 2. �ҹ��ڷ�! , 0. ����\n");
		scanf("%d", &iSel);

		rewind(stdin);

		if (iSel == 0)
			return 0;

		printf("���ڿ� �Է�\t: ");
		gets_s(chChange, 256);

		printf("��ȯ�� ���� ��\t: %d\n",CharConvert(iSel, chChange));

		system("pause");
		system("cls");
	}

	return 0;
}
//*/


// Q7.   ���ڿ��� �Է� �޾Ƽ� ������ ���ڿ��� �귯������ ��µǴ� ���α׷�
/*
#define CHARMAX 256

int main()
{
	char chTest[CHARMAX] = "";		// �Է¹��� ���ڿ�
	char Temp = ' ';				// SWAP �� ���� �ӽ� ����

	gets_s(chTest, CHARMAX);
	strcat(chTest, " ");

	while (!_kbhit())
	{
		puts(chTest);

		for (int i = 0; i < CHARMAX; ++i)
		{
			if (chTest[i + 1] == '\0')	// NULL �϶� ���� �ݺ�
			{
				chTest[i] = Temp;		// NULL �� �ٷ� �� ���ڸ� ù���ڷ� ����.
				break;
			}
			Temp = chTest[i];			// �ѱ��ھ� ������!
			chTest[i] = chTest[i + 1];
			chTest[i + 1] = Temp;
		}

		Sleep(150);				// ��� (150ms)
		system("cls");			// ȭ�� �����
	}

	return 0;
}
//*/