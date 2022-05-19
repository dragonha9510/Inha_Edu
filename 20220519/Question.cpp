#include <iostream>
#include <vld.h>

using namespace std;

/*/
typedef struct candybar
{
	char chName[20];
	float fWeight = 0.f;
	int iCalorie = 0;
}CANDYBAR;

CANDYBAR MakeCandy();
int AddCandy(CANDYBAR** dest, CANDYBAR newcandy, int* size);
int PrintCandyBar(CANDYBAR* sour, int size);

int main()
{
	int iSel = 0;
	int iSize = 0;

	CANDYBAR* listCandy = nullptr;

	while (true)
	{
		cout << "1. ĵ�� �߰� 2. ĵ�� ��� else. ����" << endl;
		cin >> iSel;

		switch (iSel)
		{
		case 1:
			iSize = AddCandy(&listCandy, MakeCandy(), &iSize);
			break;
		case 2:
			PrintCandyBar(listCandy, iSize);
			break;
		default:
			delete[] listCandy;
			listCandy = nullptr;

			return 0;
		}

		system("pause");
		system("cls");
	}

	return 0;
}

CANDYBAR MakeCandy()
{
	CANDYBAR NewCandy;

	cin.ignore();

	cout << "��ǥ �Է� : ";
	cin.getline(NewCandy.chName, sizeof(NewCandy.chName));

	cout << "���� �Է� : ";
	cin >> NewCandy.fWeight;

	cout << "Į�θ� �Է� : ";
	cin >> NewCandy.iCalorie;

	return NewCandy;
}

int AddCandy(CANDYBAR** dest, CANDYBAR newcandy, int* size)
{
	if (*size == 0)
	{
		*dest = new CANDYBAR;
		**dest = newcandy;
		++(*size);
		return 1;
	}

	CANDYBAR* Temp = *dest;

	*dest = new CANDYBAR[++(*size)];

	for (int i = 0; i < (*size) - 1; ++i)
	{
		(*dest)[i] = Temp[i];
	}
	(*dest)[(*size) - 1] = newcandy;

	if (*size > 2)
	{
		delete[] Temp;
		Temp = nullptr;
	}
	else
	{
		delete Temp;
		Temp = nullptr;
	}

	return *size;
}

int PrintCandyBar(CANDYBAR* sour, int size)
{
	CANDYBAR* Temp = sour;

	for (int i = 0; i < size; ++i)
	{
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
		cout << "��ǥ : " << Temp->chName << endl;
		cout << "���� : " << Temp->fWeight << endl;
		cout << "Į�θ� : " << Temp->iCalorie << endl;
		cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

		++Temp;
	}

	return 0;
}

//*/


/*/

int sumof(int a, int b)
{
	int Res = 0;
	int Center = 0;
	int Mul = 1;

	if (a <= 0 || b <= 0)
		return 0;

	if (a < b)
	{
		int Temp = a;
		a = b;
		b = Temp;
	}

	if ((a - b) % 2 == 0)
	{
		Center = (a + b) / 2;
		Mul = 0;
	}

	Mul += (a - b) / 2;

	Res = ((a + b) * Mul) + Center;

	return Res;
}

int main()
{
	cout << sumof(5, 5) << endl;
	return 0;
}

//*/


void nrpira(int n) 
{
	int Max			= n * 2 - 1; // �� �� ( ��� �� )
	int Start		= 0;		 // ���� ��ġ
	int End			= Max;		 // �� ��ġ
	int Num			= 1;		 // ��� ��
	int Direction	= 1;		 // ����

	for (int i = 0; i < Max; ++i) 
	{
		for (int j = 0; j < Max; ++j) 
		{
			if (j < Start || End <= j)	// start ���� �۰� End ���� ũ�ų� ������
				cout << " ";			// ���� ���
			else
				cout << Num;	// ������ ��ġ�� �� ���
		}

		if (i >= (Max / 2))		// ������ �����ٸ�
			Direction = -1;		// ���� ��ȯ

		Num		+= Direction;
		Start	+= Direction;
		End		-= Direction;

		cout << endl;			// ù �� ������ ����
	}
}

int main()
{
	nrpira(10);

	return 0;
}