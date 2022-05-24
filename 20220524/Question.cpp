#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;

//	Q1. ������� ���ӵ� a �� �̷��ӵ� v �� �־����� ��
// ����Ⱑ �̷��ϱ� ���� �ּ� Ȱ�� ���̸� ����ϴ� ���α׷�
// 
// ����ڿ��� m/s ������ v, m/s^2 ������ a�� �Է¹޾�
// �ּ� Ȱ�� ���̸� ���
/*/

double POW(double d)
{
	return d * d;
}

int main()
{
	double dSpeed = 0;
	double dAccel = 0;

	cin >> dSpeed >> dAccel;

	double distance = 0;

	distance = POW(dSpeed) / (2.0 * dAccel);

	cout << distance << endl;

	return 0;
}


int i = 0;
++i -> (i += 1)
i++->	temp = i
		temp += 1
		i = temp;
//*/


//	Q2. ���������� �Ÿ� (��Ÿ���)
/*/

#define ABSOLUTE(t) t < 0 ? t * -1 : t

double POW(double d)
{
	return d * d;
}

double SQRT(double num)
{
	double a = 0, b = 0;

	a = num / 2.0;

	while (a != b)
	{
		b = a;
		a = ((num / b) + b) / 2.0;
	}

	return a;
}

int main()
{
	double dX1, dY1, dX2, dY2;

	cin >> dX1 >> dY1 >> dX2 >> dY2;

	double dXDistance = ABSOLUTE((dX1 - dX2));
	double dYDistance = ABSOLUTE((dY1 - dY2));

	double dDistance = SQRT(POW(dXDistance) + POW(dYDistance));

	cout << dDistance;

	return 0;
}

//*/


//	Q3. p.368 4��
//		a. ȸ����� -> ����
//		b. �Ǹ����� ����
//		c. �������� ����
//		..
//		Q. ����
/*/

#define MAXBUFFER 256
#define CHECKCHAR(t, q) q < 'a' ? (t == q || t == (q + 32)) : (t == q || t == (q - 32))

typedef struct bop
{
	char fullname[MAXBUFFER];
	char title[MAXBUFFER];
	char bopname[MAXBUFFER];
	int preference;
}BOP;

ofstream* Initialize(ofstream* file);
void RegisterInfo(ofstream* file);
void PrintInfo(char _case);

int main()
{
	ofstream outFile;
	Initialize(&outFile);

	char chSel = 0;

	while (true)
	{
		cout << "ȸ�� ���" << endl;
		cout << "a.���  b.�Ǹ���  c.���Կ���  d.ID����  e.�������ο���  q.����" << endl;
		
		cin >> chSel;
		cin.get();

		if (CHECKCHAR(chSel,'A'))
			RegisterInfo(&outFile);
		else if ((chSel > 'A' && chSel < 'F') || (chSel > 'a' && chSel < 'f'))
			PrintInfo(chSel);
		else if (CHECKCHAR(chSel,'Q'))
			break;

		system("pause");
		system("cls");
	}

	outFile.close();

	return 0;
}

void RegisterInfo(ofstream* file)
{
	BOP info;

	cout << "�̸� �Է� : ";
	cin.getline(info.fullname, MAXBUFFER);
	cout << "���� �Է� : ";
	cin.getline(info.title, MAXBUFFER);
	cout << "���̵� �Է� : ";
	cin.getline(info.bopname, MAXBUFFER);
	cout << "�⺻ ���� ���� 0.�Ǹ� 1.���� 2.���̵� : ";
	cin >> info.preference;

	*file << info.fullname << endl;
	*file << info.title << endl;
	*file << info.bopname << endl;
	*file << info.preference << endl;
}

void PrintInfo(char _case)
{
	ifstream inFile;
	inFile.open("BOP_INFO.txt");

	if (!inFile.is_open())
		exit(EXIT_FAILURE);

	BOP Temp;

	while (inFile.good())
	{
		char chThresh[5];
		inFile.getline(Temp.fullname, MAXBUFFER);
		if (Temp.fullname[0] == '\0')
			break;
		inFile.getline(Temp.title, MAXBUFFER);
		inFile.getline(Temp.bopname, MAXBUFFER);
		inFile.getline(chThresh, 5);

		Temp.preference = atoi(chThresh);

		switch (_case)
		{
		case 'B':case 'b':
			cout << Temp.fullname << endl;
			break;
		case 'C':case 'c':
			cout << Temp.title << endl;
			break;
		case 'D':case 'd':
			cout << Temp.bopname << endl;
			break;
		case 'E':case 'e':
			switch (Temp.preference)
			{
			case 0:
				cout << Temp.fullname << endl;
				break;
			case 1:
				cout << Temp.title << endl;
				break;
			case 2:
				cout << Temp.bopname << endl;
				break;
			}
			break;
		default:
			break;
		}
	}

	inFile.close();
}

ofstream* Initialize(ofstream* file)
{
	ifstream inFile;
	inFile.open("BOP_INFO.txt");

	if (!inFile.is_open())
		exit(EXIT_FAILURE);

	BOP Temp;
	vector<BOP> vecTemp;
	char chThresh[5];

	while (inFile.good())
	{
		inFile.getline(Temp.fullname, MAXBUFFER);
		if (Temp.fullname[0] == '\0')
			break;
		inFile.getline(Temp.title, MAXBUFFER);
		inFile.getline(Temp.bopname, MAXBUFFER);
		inFile.getline(chThresh, 5);

		Temp.preference = atoi(chThresh);

		vecTemp.push_back(Temp);
	}

	inFile.close();

	(*file).open("BOP_INFO.txt");

	for (size_t i = 0; i < vecTemp.size(); ++i)
	{
		*file << vecTemp[i].fullname << endl;
		*file << vecTemp[i].title << endl;
		*file << vecTemp[i].bopname << endl;
		*file << vecTemp[i].preference << endl;
	}

	return file;
}

//*/

//	Q4.
int iTime = 0;

int iIndex = 0;
int arrPrime[100000] = { 0 };

void PrintPrimeNumber(int ia = 0);		// �Ҽ��� ����ϴ� �Լ�
int GetNumber();						// ������ �Է¹��� �Լ�
int CheckPrime(int ia);					// �Ҽ����� Ȯ���ϴ� �Լ�

int main()
{
	arrPrime[iIndex++] = 2;
	PrintPrimeNumber(GetNumber());		// ������ �޾Ƽ� �Ҽ��� �������

	cout << endl;
	cout << "�ɸ� �ð� : ";
	cout << clock() - iTime << endl;

	return 0;
}

void PrintPrimeNumber(int ia)
{
	int iCnt = 1;
	printf("%d\t", 2);

	for (int i = 3; i <= ia; ++i)	// �Ҽ��� 2���� �Է��� ������ Ȧ���� Ȯ���Ѵ�.
	{									// ¦���� ���� 2�� ��������
		if (CheckPrime(i))
		{								// �Ҽ���� 0 �� �ƴ� ���� ��ȯ if �� ����
			printf("%d\t", i);

			++iCnt;						// 5 �� ����ߴٸ� ����

			if (iCnt == 5)
			{
				iCnt = 0;
				printf("\n");
			}
		}
	}
}

int GetNumber()
{
	int iRes = 0;
	int iBreak = 0;

	while (!iBreak)
	{
		printf("2 �̻��� ������ �Է� �ٶ��ϴ� : ");

		iBreak = scanf("%d", &iRes);

		if (iBreak != 0 && iRes >= 2)
			break;
		else
			iBreak = 0;
	}

	iTime = clock();

	return iRes;
}

int CheckPrime(int ia)
{
	for (int i = 0; arrPrime[i] * arrPrime[i] <= ia; ++i)
	{
		if (ia % arrPrime[i] == 0)
			return 0;
	}

	arrPrime[iIndex++] = ia;
	return ia;
}