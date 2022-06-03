#include "stdafx.h"

using namespace std;

#define ERRORCHECK(t) (t == -1 ? true : false)

int main()
{
	CMyStack stcInt;

	if(ERRORCHECK(stcInt.Initialize(3)))
		return -1;

	while (true)
	{
		int iSel = 0;
		int iData = 0;
		int iTemp = 0;

		system("cls");

		cout << "현재 데이터 수 : " << stcInt.Size()
			<< " / " << stcInt.Capacity() << endl;
	
		cout << "(1)푸시 (2)팝 (3)피크 (4)출력 (5)초기화 (6)탐색 (7)IsFull? (8)Capacity (0)종료" << endl;
		cin >> iSel;

		if (!iSel)
			break;
	
		switch (iSel)
		{
		case 1:
			cout << "데이터 : ";
			cin >> iData;
			if (ERRORCHECK(stcInt.Push(iData)))
				cout << "데이터 입력 실패" << endl;
			break;
		case 2:
			if (ERRORCHECK(stcInt.Pop(&iData)))
				cout << "데이터 팝에 실패" << endl;
			else
				cout << "팝 데이터 : " << iData << endl;
			break;
		case 3:
			if (ERRORCHECK(stcInt.Peek(&iData)))
				cout << "데이터 피크 실패" << endl;
			else
				cout << "피크 데이터 : " << iData << endl;
			break;
		case 4:
			stcInt.Print();
			break;
		case 5:
			stcInt.Clear();
			break;
		case 6:
			cout << "데이터 : ";
			cin >> iData;
			iTemp = stcInt.Search(iData);
			if (ERRORCHECK(iTemp))
			{
				cout << "데이터 탐색 실패" << endl;
				break;
			}
			cout << iTemp << " 위치에 데이터가 존재함" << endl;
			break;
		case 7:
			if (stcInt.IsFull())
				cout << "가득 참!" << endl;
			else
				cout << "가득 차지 않았음" << endl;
			break;
		case 8:
			cout << stcInt.Capacity() << endl;
			break;
		}

		system("pause");
	}

	stcInt.Release();

	return 0;
}