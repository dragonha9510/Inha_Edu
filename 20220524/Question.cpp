#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cctype>
#include <fstream>
#include <vector>

using namespace std;

//	Q1. 비행기의 가속도 a 와 이륙속도 v 가 주어졌을 때
// 비행기가 이륙하기 위한 최소 활주 길이를 계산하는 프로그램
// 
// 사용자에게 m/s 단위의 v, m/s^2 단위의 a를 입력받아
// 최소 활주 길이를 출력
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


//	Q2. 두점사이의 거리 (피타고라스)
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


//	Q3. p.368 4번
//		a. 회원등록 -> 저장
//		b. 실명으로 열람
//		c. 직함으로 열람
//		..
//		Q. 종료
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
		cout << "회원 명부" << endl;
		cout << "a.등록  b.실명열람  c.직함열람  d.ID열람  e.설정으로열람  q.종료" << endl;
		
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

	cout << "이름 입력 : ";
	cin.getline(info.fullname, MAXBUFFER);
	cout << "직함 입력 : ";
	cin.getline(info.title, MAXBUFFER);
	cout << "아이디 입력 : ";
	cin.getline(info.bopname, MAXBUFFER);
	cout << "기본 열람 설정 0.실명 1.직함 2.아이디 : ";
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

void PrintPrimeNumber(int ia = 0);		// 소수를 출력하는 함수
int GetNumber();						// 정수를 입력받을 함수
int CheckPrime(int ia);					// 소수인지 확인하는 함수

int main()
{
	arrPrime[iIndex++] = 2;
	PrintPrimeNumber(GetNumber());		// 정수를 받아서 소수를 출력하자

	cout << endl;
	cout << "걸린 시간 : ";
	cout << clock() - iTime << endl;

	return 0;
}

void PrintPrimeNumber(int ia)
{
	int iCnt = 1;
	printf("%d\t", 2);

	for (int i = 3; i <= ia; ++i)	// 소수는 2부터 입력한 수까지 홀수만 확인한다.
	{									// 짝수는 전부 2로 나누어짐
		if (CheckPrime(i))
		{								// 소수라면 0 이 아닌 값을 반환 if 문 실행
			printf("%d\t", i);

			++iCnt;						// 5 번 출력했다면 개행

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
		printf("2 이상의 정수를 입력 바랍니다 : ");

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