#include "stdafx.h"

using namespace std;



//Q1
/*/
#define LOWERCASE(t) (t <= 'Z' ? t + 32 : t)

void HANGMAN(vector<string>& table)
{
	int iTemp = rand() % table.size();

	int iCollectLength = 0;
	int iCollectCnt = 0;
	int iFailCnt = 0;

	char chInput = '\0';
	const string Answer = table[iTemp];
	size_t iLength = Answer.length();

	bool bCheck = false;
	bool* bCollect = new bool[iLength];
	memset(bCollect, false, iLength);

	while (true)
	{
		system("cls");

		cout << "Ƚ�� : " << iCollectCnt << " / ���� : " << iFailCnt << endl;

		for (size_t i = 0; i < iLength; ++i)
		{
			if (!bCollect[i])
				cout << "*";
			else
				cout << Answer[i];
		}
		cout << endl;

		if (iCollectLength == iLength)
		{
			cout << endl;
			cout << Answer << " ����!  �� " << iFailCnt << "�� ���� " 
				<< iCollectCnt << " �� ���� ����!!";
			system("pause");
			break;
		}

		cout << "�Է� : ";
		cin >> chInput;
		++iCollectCnt;

		for (size_t i = 0; i < iLength; ++i)
		{
			if ((LOWERCASE(Answer[i]) == LOWERCASE(chInput)))
			{
				if (bCollect[i])
					cout << chInput << "�� �̹� �ԷµǾ����ϴ�." << endl;
				else
					bCollect[i] = true, bCheck = true, ++iCollectLength;
			}
		}

		if (!bCheck)
			++iFailCnt;

		bCheck = false;
	}

	delete[] bCollect;
	bCollect = nullptr;
}

int main()
{
	srand((unsigned int)time(NULL));

	vector<string> vecWordTable;
	string strInput;

	int iSel = 0;

	while (true)
	{
		cout << "1.�ܾ��߰� 2.����Է��Ѵܾ���� 3.���ӽ��� 4.�ܾ��� 0.����";
		cin >> iSel;

		switch (iSel)
		{
		case 1:
			cin >> strInput;
			vecWordTable.push_back(strInput);
			break;
		case 2:
			vecWordTable.pop_back();
			break;
		case 3:
			// ���� ����
			HANGMAN(vecWordTable);
			break;
		case 4:
			for (size_t i = 0; i < vecWordTable.size(); ++i)
				cout << vecWordTable[i] << endl;

			system("pause");
			break;
		case 0:
			return 0;
		default:
			break;
		}

		system("cls");
	}

	return 0;
}
//*/

//*/

#define MINUSCHECKBREAK(t) if (t < 0){cout << "�ݾ��� ������ �� �� ����!" << endl;break;}
#define MAXDEPOSIT 20000000

int main()
{
	CBankAccount bankacc;

	bankacc.Initialize("ȫ�浿", 93350, 0);

	int iSel = 0;

	while (true)
	{
		cout << "1.����Ȯ�� 2.�Ա� 3.��� 0.����" << endl;
		cin >> iSel;

		switch (iSel)
		{
		case 1:
			bankacc.PrintInfo();
			break;
		case 2:
			cout << "�Ա��� �ݾ� �Է� (�ִ� 20,000,000��) : ";
			cin >> iSel;
			MINUSCHECKBREAK(iSel);
			if (iSel > MAXDEPOSIT)
				cout << "��ȯ �ݾ� : " << iSel - MAXDEPOSIT;
			iSel = iSel > MAXDEPOSIT ? MAXDEPOSIT : iSel;
			if (-1 == bankacc.Deposit(iSel))
			{
				cout << "�Ա� ����" << endl;
				cout << "��ȯ �ݾ� : " << iSel << endl;
			}
			bankacc.PrintBalance();
			break;
		case 3:
			cout << "����� �ݾ� �Է� : ";
			cin >> iSel;
			MINUSCHECKBREAK(iSel);
			bankacc.Withdraw(iSel);
			bankacc.PrintBalance();
			break;
		case 0:
			return 0;
		default:
			break;
		}

		cin.ignore();
		cin.clear();
		system("pause");
		system("cls");
	}

	return 0;
}
//*/
