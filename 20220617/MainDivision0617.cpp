#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>
#include <windows.h>
#include "StopWatch.h"
#include "MainDivision0617.h"

using namespace std;

int Class0617Main1()
{
	const char* state1 = "Florida";
	const char* state2 = "Kansas";
	const char* state3 = "Euphoria";

	int len = strlen(state2);

	cout << "���� �ε��� ���� : " << endl;

	int cnt;
	for (cnt = 0; cnt <= len; ++cnt)
	{
		cout.write(state2, cnt);
		cout << endl;
	}

	cout << "���� �ε��� ���� : \n";
	for (cnt = len; cnt > 0; --cnt)
		cout.write(state2, cnt) << endl;

	cout << "���ڿ� ���� �ʰ� : \n";
	cout.write(state2, static_cast<streamsize>(len + 5)) << endl;

	return 0;
}

int Class0617Main2()
{
	cout << "�� �Է� : ";

	int sum = 0;
	int input;

	while (cin >> input)
	{
		cout << input;
		sum += input;
	}

	cout << "���������� �Է��� �� = " << input << endl;
	cout << "�հ� = " << sum << endl;

	return 0;
}

int Class0617Main3()
{
	string filename;

	cout << "�� ������ ���� �̸��� �Է� : ";
	cin >> filename;

	ofstream fout(filename.c_str());

	fout << "��й�ȣ ���� ����. \n";
	cout << "��й�ȣ �Է� �ٶ� : ";
	float secret;
	cin >> secret;
	
	fout << "������ ��� ��ȣ�� " << secret << "�Դϴ�.\n";
	fout.close();

	ifstream fin(filename.c_str());
	cout << filename << " ������ ������ ������ �����ϴ� : \n";
	char ch;
	while (fin.get(ch))
		cout << ch;

	cout << "���α׷� ����." << endl;
	fin.close();

	return 0;
}

const int LIM = 20;
struct planet
{
	char name[LIM];
	double population;
	double g;
};

const char* file = "planets.dat";
inline void eatline() { while (cin.get() != '\n') continue; }

int Class0617Main4()
{
	planet pl;
	cout << fixed;

	fstream finout;
	finout.open(file, ios_base::in | ios_base::out | ios_base::binary);

	int ct = 0;
	if (finout.is_open())
	{
		finout.seekg(0);
		cout << file << " ������ ���� ������ ������ �����ϴ�." << endl;

		while (finout.read((char*)&pl, sizeof pl))
		{
			cout << ct++ << " : " << setw(LIM) << pl.name << " : "
				<< setprecision(0) << setw(12) << pl.population
				<< setprecision(2) << setw(6) << pl.g << endl;
		}

		if (finout.eof())
			finout.clear();
		else
		{
			cerr << file << " ������ �дٰ� ���� �߻�. \n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " ������ �� �� �����ϴ�. \n";
		exit(EXIT_FAILURE);
	}

	cout << "������ ���ڵ� ��ȣ : ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "�߸��� ��ȣ !" << endl;
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl;
	finout.seekg(place);

	if (finout.fail())
	{
		cerr << "���ڵ� ã�� ����" << endl;
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&pl, sizeof pl);
	cout << "���� ���ڵ� ���� : \n";

	cout << rec << " : " << setw(LIM) << pl.name << " : "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;

	if (finout.eof())
		finout.clear();

	cout << "�༺�� �̸��� �Է��Ͻʽÿ� : ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "�༺�� �α��� �Է� : ";
	cin >> pl.population;
	cout << "�߷� ���ӵ� �Է� : ";
	cin >> pl.g;

	finout.seekp(place);
	finout.write((char*)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "���� ���� �߻�.\n";
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);
	cout << file << " ������ ������ ������ ������ �����ϴ� : \n";
	while (finout.read((char*)&pl, sizeof pl))
	{
		cout << ct++ << " : " << setw(LIM) << pl.name << " : "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "����";
	return 0;
}

bool FileSplit()
{
	char chInputTemp[256];
	int size = 0;
	cout << "Enter File name : ";
	cin >> chInputTemp;
	cout << "Enter File size : ";
	cin >> size;

	fstream finout;
	finout.open(chInputTemp, ios_base::in | ios_base::out | ios_base::binary);

	if (finout.is_open())
	{	// ���� ���� ���� ����
		char chNewName[50][256];
		int FileNum = 0;

		cout << "���� ���� ���� ����" << endl;

		while (true)
		{
			if (finout.eof())
			{
				finout.clear();
				break;
			}

			char chFileNum[10] = ".";
			char ch1[2] = { (char)('0' + ((FileNum + 1) / 10)), '\0' };
			char ch2[2] = { (char)('0' + ((FileNum + 1) % 10)), '\0' };
			strcat(chFileNum, ch1);
			strcat(chFileNum, ch2);

			strcpy(chNewName[FileNum], chInputTemp);
			strcat(chNewName[FileNum], chFileNum);
			ofstream fWrite(chNewName[FileNum]);

			int cnt = 0;
			char temp;
			while (finout.read(&temp, 1))
			{
				fWrite << temp;
				++cnt;
				if (cnt == size)
					break;
			}
			++FileNum;
			fWrite.close();
		}
	}
	else
	{
		cerr << chInputTemp << " ������ �� �� �����ϴ�. \n";
		exit(EXIT_FAILURE);
	}

	finout.close();

	return true;
}

bool FileJoin()
{
	int iFileNum = 0;
	cout << "Enter File Number : ";
	cin >> iFileNum;

	char chNewName[50][256];
	for (int i = 0; i < iFileNum; ++i)
	{
		cout << "Enter Source File : ";
		cin >> chNewName[i];
	}

	char chOutPut[256];
	cout << "Enter Target File : ";
	cin >> chOutPut;

	ofstream fWrite(chOutPut);

	if (fWrite.is_open())
	{	// ���� ���� ��ü ����
		cout << "���� ���� ��ü ����" << endl;

		for (int i = 0; i < iFileNum; ++i)
		{
			fstream fRead(chNewName[i]);

			int cnt = 0;
			char temp;
			while (fRead.read(&temp, 1))
				fWrite << temp;

			fRead.close();
		}
	}
	else
	{
		cerr << chOutPut << " ������ �� �� �����ϴ�. \n";
		exit(EXIT_FAILURE);
	}

	fWrite.close();

	return true;
}

int Class0617Question1()
{
	// ���� ���� �׽�Ʈ
	FileSplit();

	// ���� ��ü �׽�Ʈ
	FileJoin();

	return 0;
}

// 6,4,1,7,3,9,8
bool PrintInsertSort(int arr[], int n, int start, int end, bool res = true)
{
	if (res)
	{
		for (int i = 0; i < n; ++i)
		{
			if (i == start)
				cout << "\"" << arr[i] << "\"";
			else if (i == end)
				cout << "\"" << arr[i] << "\"";
			else
				cout << " " << arr[i] << " ";
		}
		cout << endl;
	}
	return res;
}

void InsertSort(int arr[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			//if (PrintInsertSort(arr, n, i, j, (arr[i] < arr[j])))
			if(arr[i] < arr[j])
			{
				int back = arr[i];
				for (int k = i - 1; k >= j; --k)
				{
					arr[k + 1] = arr[k];
					//PrintInsertSort(arr, n, k + 1, k); 
				}
				arr[j] = back;
				//PrintInsertSort(arr, n, j, j);
				//cout << endl;
				break;
			}
		}
	}
}

#define INSERTARRMAX 100000

int Class0617Algorithm()
{
	srand((unsigned int)time(NULL));
	int* arr = new int[INSERTARRMAX];

	for (int i = 0; i < INSERTARRMAX; ++i)
		arr[i] = rand() % INSERTARRMAX;

	CStopWatch timer;

	timer.Start();
	InsertSort(arr, INSERTARRMAX);
	timer.Stop();

	cout << "�ɸ� �ð� : " << timer.getElapsedTime() << endl;

	delete[] arr;
	arr = nullptr;
	return 0;
}
