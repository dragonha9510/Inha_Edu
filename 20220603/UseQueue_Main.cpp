#include "stdafx.h"

int main()
{
	system("cls");
	CMyQueue que;

	if (que.Initialize(64) == -1)
	{
		cout << "생성 실패" << endl;
		return 0;
	}

	while (true)
	{
		int m, x;

		cout << "현재 데이터 수 : " << que.size() << " / " << que.capacity() << endl;
		cout << "1.인큐 2.디큐 3.피크 4.출력 5.클리어 6.검색 0.종료 : ";
		cin >> m;

		if (m == 0)
			break;

		switch (m)
		{
		case 1:
			cout << "데이터 : ";
			cin >> x;
			if (que.Enque(x) == -1)
				cout << "인큐 실패" << endl;
			break;
		case 2:
			if (que.Deque(&x) == -1)
				cout << "디큐 실패" << endl;
			else
				cout << "디큐한 데이터 : " << x << endl;
			break;
		case 3:
			if (que.Peek(&x) == -1)
				cout << "피크 실패" << endl;
			else
				cout << "피크한 데이터 : " << x << endl;
			break;
		case 4:
			que.Print();
			break;
		case 5:
			que.clear();
			break;
		case 6:
			cout << "데이터 : ";
			cin >> x;
			if (que.search(x) == -1)
				cout << "검색 실패!" << endl;
			break;
		}

		cout << endl;
	}

	return 0;
}