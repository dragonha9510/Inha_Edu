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

		cout << "횟수 : " << iCollectCnt << " / 실패 : " << iFailCnt << endl;

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
			cout << Answer << " 정답!  총 " << iFailCnt << "번 실패 " 
				<< iCollectCnt << " 번 만에 정답!!";
			system("pause");
			break;
		}

		cout << "입력 : ";
		cin >> chInput;
		++iCollectCnt;

		for (size_t i = 0; i < iLength; ++i)
		{
			if ((LOWERCASE(Answer[i]) == LOWERCASE(chInput)))
			{
				if (bCollect[i])
					cout << chInput << "은 이미 입력되었습니다." << endl;
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
		cout << "1.단어추가 2.방금입력한단어삭제 3.게임시작 4.단어목록 0.종료";
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
			// 게임 시작
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

#define MINUSCHECKBREAK(t) if (t < 0){cout << "금액은 음수가 될 수 없음!" << endl;break;}
#define MAXDEPOSIT 20000000

int main()
{
	CBankAccount bankacc;

	bankacc.Initialize("홍길동", 93350, 0);

	int iSel = 0;

	while (true)
	{
		cout << "1.정보확인 2.입금 3.출금 0.종료" << endl;
		cin >> iSel;

		switch (iSel)
		{
		case 1:
			bankacc.PrintInfo();
			break;
		case 2:
			cout << "입금할 금액 입력 (최대 20,000,000원) : ";
			cin >> iSel;
			MINUSCHECKBREAK(iSel);
			if (iSel > MAXDEPOSIT)
				cout << "반환 금액 : " << iSel - MAXDEPOSIT;
			iSel = iSel > MAXDEPOSIT ? MAXDEPOSIT : iSel;
			if (-1 == bankacc.Deposit(iSel))
			{
				cout << "입금 실패" << endl;
				cout << "반환 금액 : " << iSel << endl;
			}
			bankacc.PrintBalance();
			break;
		case 3:
			cout << "출금할 금액 입력 : ";
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
