#include "stdafx0610.h"

int main()
{
	int iSel = 0;

	while (true)
	{
		cout << "0.수업 1.문제풀이 2.알고리즘" << endl;
		cout << "-1 종료 => 입력 (";
		cin >> iSel;

		if (iSel == -1)
			break;

		switch (iSel)
		{
		case 0:
			cout << "0.클래스의 상속" << endl;
			cout << "9.이전메뉴" << endl;
			cout << "-1 종료 => 입력 (";
			cin >> iSel;
			switch (iSel)
			{
			case 0:
				usett1();
				break;
			case 9:
				break;
			case -1:
				return 0;
			default:
				break;
			}
			break;
		case 1:
			cout << "0.클래스의 상속 (rect, circle, point)" << endl;
			cout << "1.원반옮기기" << endl;
			cout << "9.이전메뉴" << endl;
			cout << "-1 종료 => 입력 (";
			cin >> iSel;
			switch (iSel)
			{
			case 0:
				ObjectTest();
				break;
			case 1:
				MovePlate();
				break;
			case 9:
				break;
			case -1:
				return 0;
			default:
				break;
			}
			break;
		case 2:
			break;
		default:
			break;
		}

		system("pause");
		system("cls");
	}

	return 0;
}
