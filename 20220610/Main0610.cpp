#include "stdafx0610.h"

int main()
{
	int iSel = 0;

	while (true)
	{
		cout << "0.���� 1.����Ǯ�� 2.�˰���" << endl;
		cout << "-1 ���� => �Է� (";
		cin >> iSel;

		if (iSel == -1)
			break;

		switch (iSel)
		{
		case 0:
			cout << "0.Ŭ������ ���" << endl;
			cout << "9.�����޴�" << endl;
			cout << "-1 ���� => �Է� (";
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
			cout << "0.Ŭ������ ��� (rect, circle, point)" << endl;
			cout << "1.���ݿű��" << endl;
			cout << "9.�����޴�" << endl;
			cout << "-1 ���� => �Է� (";
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
