#include "stdafx0610.h"
#include "MainDivision.h"

#include <vector>
#include <list>

int usett1()
{
	CTableTennisPlayer player1("Tara", "Boomdea", false);
	CRatedPlayer rplayer1(1140, "Mallory", "Duck", true);

	rplayer1.Name();
	if (rplayer1.HasTable())
		cout << ": 탁구대가 있다." << endl;
	else
		cout << ": 탁구대가 없다." << endl;

	player1.Name();
	if (player1.HasTable())
		cout << ": 탁구대가 있다." << endl;
	else
		cout << ": 탁구대가 없다." << endl;

	cout << "이름 : ";
	rplayer1.Name();
	cout << "; 랭킹 : " << rplayer1.Rating() << endl;

	CRatedPlayer rplayer2(1212, player1);
	cout << "이름 : ";
	rplayer2.Name();
	cout << "; 랭킹 : " << rplayer2.Rating() << endl;

	return 0;
}

int ObjectTest()
{
	C2D_Object* Obj1 = new CRectangle2D(1,1,3,3);
	CRectangle2D* Obj2 = new CRectangle2D(0,0,1,1);
	CCircle2D* Obj3 = new CCircle2D(0, 0, 0.2);
	CMyPoint* Obj4 = new CMyPoint(4, 4);

	vector<C2D_Object*> vecObj;

	vecObj.push_back(Obj1);
	vecObj.push_back(Obj2);
	vecObj.push_back(Obj3);
	vecObj.push_back(Obj4);

	Obj3->getArea();

	CRectangle2D* playerAtkRange = new CRectangle2D(0, 0, 0.5, 0.5);

	for (size_t i = 1; i < vecObj.size(); ++i)
	{
		if (vecObj[0]->Contains(*vecObj[i]))
			cout << "Contains" << endl;
		else
			cout << "실패" << endl;
	}

	for (size_t i = 0; i < vecObj.size(); ++i)
	{
		delete vecObj[i];
		vecObj[i] = nullptr;
	}

	vecObj.clear();
	vecObj.shrink_to_fit();

	return 0;
}

enum POSITION {A = 0,B,C,POSITION_END};

int cnt = 1;

void moveLogic(int size, POSITION a, POSITION b, POSITION c, int maxsize , int* arr[])
{
	if (size == 1)
	{
		cout << 1 << "번을 " << a << "에서 " << b << " 로 옮김" << endl;

		//arr[b][maxsize - size] = arr[a][size - 1];
		//arr[a][size - 1] = 0;
		//cout << endl;
		//for (int i = 0; i < 3; ++i)
		//{
		//	cout << "(" << arr[0][i] << ")\t";
		//	cout << "(" << arr[1][i] << ")\t";
		//	cout << "(" << arr[2][i] << ")\t";
		//	cout << endl;
		//}
		//cout << endl;

		cnt++;
	}
	else
	{
		moveLogic(size - 1, a, c, b, maxsize, arr);

		cout << arr[a][size - 1] << "번을 " << a << "에서 " << b << " 로 옮김" << endl;
		//arr[b][maxsize - size] = arr[a][size - 1];
		//arr[a][size - 1] = 0;

		//cout << endl;
		//for (int i = 0; i < 3; ++i)
		//{
		//	cout << "(" << arr[0][i] << ")\t";
		//	cout << "(" << arr[1][i] << ")\t";
		//	cout << "(" << arr[2][i] << ")\t";
		//	cout << endl;
		//}
		//cout << endl;

		cnt++;

		moveLogic(size - 1, c, b, a, maxsize, arr);
	}
}

int MovePlate()
{
	system("cls");

	int iInput = 0;

	cin >> iInput;

	int* pArr[POSITION_END];
	for (int i = 0; i < POSITION_END; ++i)
		pArr[i] = new int[iInput];

	for (int i = 0; i < iInput; ++i)
	{
		pArr[A][i] = i + 1;
		pArr[B][i] = 0;
		pArr[C][i] = 0;
	}

	moveLogic(iInput, A, C, B, iInput, pArr);

	cout << cnt - 1 << "회 : 최소 이동" << endl;

	for (int i = 0; i < POSITION_END; ++i)
		delete[] pArr[i];

	return 0;
}