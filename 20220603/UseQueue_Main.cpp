#include "stdafx.h"

int main()
{
	system("cls");
	CMyQueue que;

	if (que.Initialize(64) == -1)
	{
		cout << "���� ����" << endl;
		return 0;
	}

	while (true)
	{
		int m, x;

		cout << "���� ������ �� : " << que.size() << " / " << que.capacity() << endl;
		cout << "1.��ť 2.��ť 3.��ũ 4.��� 5.Ŭ���� 6.�˻� 0.���� : ";
		cin >> m;

		if (m == 0)
			break;

		switch (m)
		{
		case 1:
			cout << "������ : ";
			cin >> x;
			if (que.Enque(x) == -1)
				cout << "��ť ����" << endl;
			break;
		case 2:
			if (que.Deque(&x) == -1)
				cout << "��ť ����" << endl;
			else
				cout << "��ť�� ������ : " << x << endl;
			break;
		case 3:
			if (que.Peek(&x) == -1)
				cout << "��ũ ����" << endl;
			else
				cout << "��ũ�� ������ : " << x << endl;
			break;
		case 4:
			que.Print();
			break;
		case 5:
			que.clear();
			break;
		case 6:
			cout << "������ : ";
			cin >> x;
			if (que.search(x) == -1)
				cout << "�˻� ����!" << endl;
			break;
		}

		cout << endl;
	}

	return 0;
}