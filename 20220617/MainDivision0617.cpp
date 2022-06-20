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

	cout << "루프 인덱스 증가 : " << endl;

	int cnt;
	for (cnt = 0; cnt <= len; ++cnt)
	{
		cout.write(state2, cnt);
		cout << endl;
	}

	cout << "루프 인덱스 감소 : \n";
	for (cnt = len; cnt > 0; --cnt)
		cout.write(state2, cnt) << endl;

	cout << "문자열 길이 초과 : \n";
	cout.write(state2, static_cast<streamsize>(len + 5)) << endl;

	return 0;
}

int Class0617Main2()
{
	cout << "수 입력 : ";

	int sum = 0;
	int input;

	while (cin >> input)
	{
		cout << input;
		sum += input;
	}

	cout << "마지막으로 입력한 값 = " << input << endl;
	cout << "합계 = " << sum << endl;

	return 0;
}

int Class0617Main3()
{
	string filename;

	cout << "새 파일을 위한 이름을 입력 : ";
	cin >> filename;

	ofstream fout(filename.c_str());

	fout << "비밀번호 노출 주의. \n";
	cout << "비밀번호 입력 바람 : ";
	float secret;
	cin >> secret;
	
	fout << "귀하의 비밀 번호는 " << secret << "입니다.\n";
	fout.close();

	ifstream fin(filename.c_str());
	cout << filename << " 파일의 내용은 다음과 같습니다 : \n";
	char ch;
	while (fin.get(ch))
		cout << ch;

	cout << "프로그램 종료." << endl;
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
		cout << file << " 파일의 현재 내용은 다음과 같습니다." << endl;

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
			cerr << file << " 파일을 읽다가 에러 발생. \n";
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		cerr << file << " 파일을 열 수 없습니다. \n";
		exit(EXIT_FAILURE);
	}

	cout << "수정할 레코드 번호 : ";
	long rec;
	cin >> rec;
	eatline();
	if (rec < 0 || rec >= ct)
	{
		cerr << "잘못된 번호 !" << endl;
		exit(EXIT_FAILURE);
	}
	streampos place = rec * sizeof pl;
	finout.seekg(place);

	if (finout.fail())
	{
		cerr << "레코드 찾다 에러" << endl;
		exit(EXIT_FAILURE);
	}

	finout.read((char*)&pl, sizeof pl);
	cout << "현재 레코드 내용 : \n";

	cout << rec << " : " << setw(LIM) << pl.name << " : "
		<< setprecision(0) << setw(12) << pl.population
		<< setprecision(2) << setw(6) << pl.g << endl;

	if (finout.eof())
		finout.clear();

	cout << "행성의 이름을 입력하십시오 : ";
	cin.get(pl.name, LIM);
	eatline();
	cout << "행성의 인구를 입력 : ";
	cin >> pl.population;
	cout << "중력 가속도 입력 : ";
	cin >> pl.g;

	finout.seekp(place);
	finout.write((char*)&pl, sizeof pl) << flush;
	if (finout.fail())
	{
		cerr << "쓰다 에러 발생.\n";
		exit(EXIT_FAILURE);
	}

	ct = 0;
	finout.seekg(0);
	cout << file << " 파일의 개정된 내용은 다음과 같습니다 : \n";
	while (finout.read((char*)&pl, sizeof pl))
	{
		cout << ct++ << " : " << setw(LIM) << pl.name << " : "
			<< setprecision(0) << setw(12) << pl.population
			<< setprecision(2) << setw(6) << pl.g << endl;
	}
	finout.close();
	cout << "종료";
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
	{	// 파일 열림 분할 시작
		char chNewName[50][256];
		int FileNum = 0;

		cout << "파일 열림 분할 시작" << endl;

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
		cerr << chInputTemp << " 파일을 열 수 없습니다. \n";
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
	{	// 파일 열림 합체 시작
		cout << "파일 열림 합체 시작" << endl;

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
		cerr << chOutPut << " 파일을 열 수 없습니다. \n";
		exit(EXIT_FAILURE);
	}

	fWrite.close();

	return true;
}

int Class0617Question1()
{
	// 파일 분할 테스트
	FileSplit();

	// 파일 합체 테스트
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

	cout << "걸린 시간 : " << timer.getElapsedTime() << endl;

	delete[] arr;
	arr = nullptr;
	return 0;
}
