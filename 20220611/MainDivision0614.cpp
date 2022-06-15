#include "stdafx0614.h"

#define MAXPERCENT 100.0

enum ITEM { A, B, C, D, E, F, G, H, I, J, K, ITEM_END };

void ItemGet(int testcase)
{
	srand((unsigned int)time(NULL));

	int iCase = testcase;
	int iCurPercent = 0;
	string strItemName = "ABCDEFGHIJK";
	const int iItemOri[ITEM_END] = { 1,3,3,5,5,5,10,10,10,10,38 };
	int iItemCur[ITEM_END] = { 1,3,3,5,5,5,10,10,10,10,38 };
	int iItemRes[ITEM_END] = {};

	double dByOne = (double)iCase / MAXPERCENT;

	while (dByOne > 0)
	{
		int iN = iCase > (int)MAXPERCENT ? (int)MAXPERCENT : iCase;
		int iMax = (int)MAXPERCENT;

		for (int i = 0; i < iN; ++i)
		{
			int iChoose = rand() % iMax;

			for (int j = 0; j < ITEM_END; ++j)
			{
				iCurPercent += iItemCur[j];

				if (iChoose < iCurPercent)
				{
					--iMax;
					--iItemCur[j];
					++iItemRes[j];
					iCurPercent = 0;
					break;
				}
			}
		}

		memcpy(iItemCur, iItemOri, sizeof(int) * ITEM_END);
		--dByOne;
		iCase -= (int)MAXPERCENT;
	}

	// result 출력
	for (int i = 0; i < ITEM_END; ++i)
		cout << strItemName[i] << " 아이템\t" << iItemRes[i] << endl;
}

int TimeTest()
{
	int iCase = 0;

	cout << "반복 횟수";
	cin >> iCase;

	CStopWatch checkSec;

	checkSec.Start();
	ItemGet(iCase);
	checkSec.Stop();

	cout << endl;
	
	double dSecond = (int)checkSec.getElapsedTime();
	cout << "걸린 시간 : " << checkSec.getElapsedTime() << endl;
	cout << "초 단위 : " << dSecond / 1000.0 << endl;

	return 0;
}


int* SocialFriend(int N, int relation[][2], int size)
{
	CSocialAccount* pSocial = new CSocialAccount[N];

	for (int i = 0; i < N; ++i)
		pSocial[i].Init(i, size);
	int* result = new int[N];
	int iSize = size;

	for (int i = 0; i < size; ++i)
	{
		pSocial[relation[i][0] - 1].AddFriend(pSocial[relation[i][1] - 1]);
		pSocial[relation[i][1] - 1].AddFriend(pSocial[relation[i][0] - 1]);
	}

	for (int i = 0; i < N; ++i)
	{
		result[i] = pSocial[i].getMyFriend();
	}

	delete[] pSocial;
	pSocial = nullptr;

	return result;
}

#define CHESS 8

void makeCase8Queen(int ypos, int* Pos, int& res)
{
	if (ypos == CHESS)
	{
		cout << endl;
		cout << endl;
		for (int x = 0; x < CHESS; ++x)
		{
			for (int y = 0; y < CHESS; ++y)
			{
				if (Pos[y] == x)
					cout << "■";
				else
					cout << "□";
			}
			cout << endl;
		}
		++res;
		return;
	}

	bool bCanPlace = true;
	for (int x = 0; x < CHESS; ++x)
	{
		bCanPlace = true;

		for (int y = 0; y < ypos; ++y)
		{							
			if (/*Pos[y] == x || */(abs(x - Pos[y]) == abs(ypos - y)))
			{
				bCanPlace = false;
				break;
			}
		}

		if (bCanPlace)
		{
			Pos[ypos] = x;
			makeCase8Queen(ypos + 1, Pos, res);
		}
	}
}

int ChessQueen()
{
	int iPos[CHESS] = { -1,-1,-1,-1,-1,-1,-1,-1 };

	int queencase = 0;

	makeCase8Queen(0, iPos, queencase);

	cout << queencase << endl;
	return 0;
}

int Class0614_1()
{
	const int LIM = 4;
	CWaiter bob("홍길동", 314L, 5);
	CSinger bev("조수미", 522L, 3);

	CWaiter w_temp;
	CSinger s_temp;

	CWorker* pw[LIM] = { &bob, &bev, &w_temp, &s_temp };

	int i;
	for (i = 2; i < LIM; ++i)
		pw[i]->Set();
	for (i = 0; i < LIM; ++i)
	{
		pw[i]->Show();
		cout << endl;
	}

	return 0;
}
