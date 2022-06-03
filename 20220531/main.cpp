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

		cout << "���� ������ �� : " << stcInt.Size()
			<< " / " << stcInt.Capacity() << endl;
	
		cout << "(1)Ǫ�� (2)�� (3)��ũ (4)��� (5)�ʱ�ȭ (6)Ž�� (7)IsFull? (8)Capacity (0)����" << endl;
		cin >> iSel;

		if (!iSel)
			break;
	
		switch (iSel)
		{
		case 1:
			cout << "������ : ";
			cin >> iData;
			if (ERRORCHECK(stcInt.Push(iData)))
				cout << "������ �Է� ����" << endl;
			break;
		case 2:
			if (ERRORCHECK(stcInt.Pop(&iData)))
				cout << "������ �˿� ����" << endl;
			else
				cout << "�� ������ : " << iData << endl;
			break;
		case 3:
			if (ERRORCHECK(stcInt.Peek(&iData)))
				cout << "������ ��ũ ����" << endl;
			else
				cout << "��ũ ������ : " << iData << endl;
			break;
		case 4:
			stcInt.Print();
			break;
		case 5:
			stcInt.Clear();
			break;
		case 6:
			cout << "������ : ";
			cin >> iData;
			iTemp = stcInt.Search(iData);
			if (ERRORCHECK(iTemp))
			{
				cout << "������ Ž�� ����" << endl;
				break;
			}
			cout << iTemp << " ��ġ�� �����Ͱ� ������" << endl;
			break;
		case 7:
			if (stcInt.IsFull())
				cout << "���� ��!" << endl;
			else
				cout << "���� ���� �ʾ���" << endl;
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