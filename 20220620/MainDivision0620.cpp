#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include "MainDivision0620.h"
#include "StopWatch.h"

using namespace std;


namespace SW
{
	void Copy_arr(int* iarr1, int* iarr2, int size)
	{
		for (int i = 0; i < size; ++i)
			iarr2[i] = iarr1[i];
	}

	void Swap_arr(int* iarr, int index1, int index2)
	{
		int temp = iarr[index1];
		iarr[index1] = iarr[index2];
		iarr[index2] = temp;
	}

	void Quick_sort(int* iarr, int start_index, int end_index)
	{
		int pivot_index = start_index;
		bool direction = true;
		int temp_index;
		for (int i = end_index; i != pivot_index;)
		{
			if (direction)
			{
				if (iarr[pivot_index] > iarr[i])
				{
					temp_index = pivot_index;
					Swap_arr(iarr, pivot_index, i);
					pivot_index = i;
					direction = false;
					i = temp_index + 1;
				}
				--i;
			}
			if (!direction)
			{
				if (iarr[pivot_index] < iarr[i])
				{
					temp_index = pivot_index;
					Swap_arr(iarr, pivot_index, i);
					pivot_index = i;
					direction = true;
					i = temp_index - 1;
				}
				++i;
			}
		}

		if (start_index != pivot_index)
			Quick_sort(iarr, start_index, pivot_index - 1);

		if (end_index != pivot_index)
			Quick_sort(iarr, pivot_index + 1, end_index);
	}
}

void SecureFileOut(bool bEn)
{
	srand(unsigned int(time(NULL)));

	int SecureKey = (rand() % 99999) + 1;

	char chSourTemp[256];
	char chDestTemp[256];
	cout << "Input Source filename : ";
	cin >> chSourTemp;

	if (bEn)
		cout << "Input Encoding filename : ";
	else
		cout << "Input Decoding filename : ";

	cin >> chDestTemp;

	fstream fRead;
	fRead.open(chSourTemp, ios_base::in | ios_base::out | ios_base::binary);

	if (fRead.is_open())
	{
		cout << (bEn ? "파일 열림 암호화 시작" : "파일 열림 복호화 시작") << endl;

		ofstream fWrite(chDestTemp, ios_base::binary);
		char temp;

		if (bEn)
		{
			int Digit = SecureKey;
			int cnt = 0;

			while (Digit > 0)
			{
				Digit = Digit / 10;
				++cnt;
			}
			
			fWrite << (cnt - 1);
			fWrite << SecureKey;
		}
		else
		{
			SecureKey = 0;
			int isGreater = 0;
			fRead.read(&temp, 1);
			isGreater = temp - '0';

			fRead.read(&temp, 1);

			int iDigit = 1;

			for (int i = 0; i < isGreater; ++i)
				iDigit *= 10;

			for (int i = 0; i < isGreater; ++i)
			{
				SecureKey += (temp - '0') * iDigit;
				iDigit /= 10;
				fRead.read(&temp, 1);
			}

			SecureKey += temp - '0';
		}

		if (SecureKey == 0)
		{
			fRead.close();
			fWrite.close();
			exit(EXIT_FAILURE);
		}

		while (!fRead.eof())
		{
			fRead.read(&temp, 1);

			if (fRead.eof())
			{
				fRead.clear();
				break;
			}

			// 암호화 키코드 SecureKey
			temp += (bEn ? SecureKey : SecureKey * -1);

			fWrite << temp;
		}

		fWrite.close();
	}
	else
	{
		cerr << chSourTemp << " 파일을 열 수 없습니다. \n";
		exit(EXIT_FAILURE);
	}

	fRead.close();
}

void OperationalFileOut()
{
	int SecureKey = 0;

	char chInputTemp[256];
	char chOperationalTemp[256];
	cout << "Input Source filename : ";
	cin >> chInputTemp;
	cout << "Input Decoding filename : ";
	cin >> chOperationalTemp;

	fstream fRead;
	fRead.open(chInputTemp, ios_base::in | ios_base::out | ios_base::binary);

	if (fRead.is_open())
	{	// 파일 열림 복호화 시작
		cout << "파일 열림 복호화 시작" << endl;
		char temp;
		fRead.read(&temp, 1);
		
		if (temp - '0')
		{
			SecureKey = temp - '0';

			ofstream fWrite(chOperationalTemp, ios_base::binary);

			while (true)
			{
				fRead.read(&temp, 1);

				if (fRead.eof())
				{
					fRead.clear();
					break;
				}

				// 암호화 키코드 SecureKey
				temp -= SecureKey;

				fWrite << temp;
			}

			fWrite.close();
		}
	}
	else
	{
		cerr << chInputTemp << " 파일을 열 수 없습니다. \n";
		exit(EXIT_FAILURE);
	}

	fRead.close();
}


void shell_sort(int arr[], int n) 
{
	int	shell = n;

	while (shell /= 2)
	{
		if ((shell % 2) == 0)
			++shell;

		for (int i = 0; i < shell; ++i)
		{
			int key;
			for (int j = i + shell, k = 0; j <= n - 1; j = j + shell)
			{
				key = arr[j];

				for (k = j - shell; k >= i && arr[k] > key; k = k - shell)
				{
					arr[k + shell] = arr[k];
				}

				arr[k + shell] = key;
			}
		}
	}
}



void ShellSortInsert(int arr[], int n)
{
	int shell = n + (n % 2);

	while (shell /= 2)
	{
		for (int i = shell, j = 0; i < n; ++i)
		{
			int temp = arr[i];

			for (j = i - shell; j >= 0 && arr[j] > temp; j -= shell)
				arr[j + shell] = arr[j];

			arr[j + shell] = temp;
		}
	}
}


void ShellSort(int arr[], int n)
{
	int shell = n;
	int min = 0;

	while (shell /= 2)
	{
		for (int i = shell; i < n; ++i)
		{
			int Temp = arr[i];
			min = i - shell;

			while (min >= 0 && arr[min] > Temp)
			{
				arr[min + shell] = arr[min];
				min -= shell;
			}

			arr[min + shell] = Temp;
		}
	}
}

#define SORTTESTCASE 10000000

void ShellSortMain()
{
	srand((unsigned int)time(NULL));
	CStopWatch timer;

	int* iArr = new int[SORTTESTCASE];
	int* iArr2 = new int[SORTTESTCASE];
	int* iArr3 = new int[SORTTESTCASE];

	for (int i = 0; i < SORTTESTCASE; ++i)
	{
		int iRand = 0;
		for (int j = 0; j < SORTTESTCASE / RAND_MAX; ++j)
			iRand = rand();
		iArr3[i] = iArr2[i] = iArr[i] = (iRand % SORTTESTCASE) + 1;
	}

	cout << endl;

	timer.Start();
	QuickSort(iArr, SORTTESTCASE, 0, SORTTESTCASE - 1);
	timer.Stop();

	cout << "퀵 + 0 : " << endl;
	cout << timer.getElapsedTime() << endl;

	cout << endl;
	timer.Start();
	QuickSort2(iArr2, SORTTESTCASE, 0, SORTTESTCASE - 1);
	timer.Stop();

	cout << "퀵 + 1 : " << endl;
	cout << timer.getElapsedTime() << endl;

	//cout << endl;
	//timer.Start();
	//SW::Quick_sort(iArr3, 0, SORTTESTCASE - 1);
	//timer.Stop();

	//cout << "퀵성운 : " << endl;
	//cout << timer.getElapsedTime() << endl;

	delete[] iArr;
	iArr = nullptr;
	delete[] iArr2;
	iArr2 = nullptr;
	delete[] iArr3;
	iArr3 = nullptr;

	//int iArr[9] = { 1,7,5,6,2,3,4,8,9 };
	//int iArr2[9] = { 1,8,7,4,5,7,6,3,9 };
	//int iArr3[9] = { 5,8,2,4,5,7,9,8,9 };
	//for (int i = 0; i < 9; ++i)
	//	cout << iArr[i] << " ";
	//cout << endl;
	//QuickSort(iArr, 9, 0, 8);
	//for (int i = 0; i < 9; ++i)
	//	cout << iArr[i] << " ";
	//cout << endl;
	//cout << "----------" << endl;
	//cout << endl;

	//QuickSort(iArr2, 9, 0, 8);
	//for (int i = 0; i < 9; ++i)
	//	cout << iArr2[i] << " ";
	//cout << endl;
	//cout << "----------" << endl;
	//cout << endl;

	//QuickSort(iArr3, 9, 0, 8);
	//for (int i = 0; i < 9; ++i)
	//	cout << iArr3[i] << " ";
	//cout << endl;
	//cout << "----------" << endl;
	//cout << endl;
}

void QuickSort(int arr[], int n, int start, int end)
{
	if (end - start <= 1)
		return;

	int pivotidx = ((end - start) / 2)/* + ((end - start) % 2)*/;
	int pivot = arr[pivotidx + start];
	int left = 0;
	int right = 0;
	bool bLeft = false;
	bool bRight = false;

	for (left = start, right = end; left <= right && left != right;)
	{
		if (arr[left] < pivot && bLeft == false)
			++left;
		else if(arr[left] >= pivot && bLeft == false)
			bLeft = true;

		if (arr[right] > pivot && bRight == false)
			--right;
		else if(arr[right] <= pivot && bRight == false)
			bRight = true;

		if (bLeft && bRight)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			bLeft = false;
			bRight = false;

			if (arr[left] == arr[right])
			{
				++left;
				--right;
			}
		}
	}

	QuickSort(arr, n, start, right);
	QuickSort(arr, n, left, end);
}

void QuickSort2(int arr[], int n, int start, int end)
{
	if (end - start <= 1)
		return;

	int pivotidx = ((end - start) / 2) + ((end - start) % 2);
	int pivot = arr[pivotidx + start];
	int left = 0;
	int right = 0;
	bool bLeft = false;
	bool bRight = false;

	for (left = start, right = end; left <= right && left != right;)
	{
		if (arr[left] < pivot && bLeft == false)
			++left;
		else if (arr[left] >= pivot && bLeft == false)
			bLeft = true;

		if (arr[right] > pivot && bRight == false)
			--right;
		else if (arr[right] <= pivot && bRight == false)
			bRight = true;

		if (bLeft && bRight)
		{
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;

			bLeft = false;
			bRight = false;

			if (arr[left] == arr[right])
			{
				++left;
				--right;
			}
		}
	}

	QuickSort2(arr, n, start, right);
	QuickSort2(arr, n, left, end);
}


void QuickSortBook(int arr[], int left, int right)
{
	int pl = left;
	int pr = right;
	int x = arr[(pl + pr) / 2];

	do {
		while (arr[pl] < x) pl++;
		while (arr[pr] > x) pr--;

		if (pl <= pr)
		{
			int temp = arr[pl];
			arr[pl] = arr[pr];
			arr[pr] = temp;

			pl++;
			pr--;
		}
	} while (pl <= pr);

	if (left < pr) QuickSortBook(arr, left, pr);
	if (pl < right) QuickSortBook(arr, pl, right);
}
