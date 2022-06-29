#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <windows.h>
#include <vld.h>
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

#define SORTTESTCASE 1000000

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
		for (int j = 0; j < (SORTTESTCASE / RAND_MAX) + 1; ++j)
			iRand += rand();
		iArr3[i] = iArr2[i] = iArr[i] = (iRand % SORTTESTCASE) + 1;
	}

	cout << "측정 시작" << endl;
	cout << endl;

	timer.Start();
	CountingSortBook(iArr, 0, SORTTESTCASE - 1);
	timer.Stop();

	cout << "도수 책 : " << endl;
	cout << timer.getElapsedTime() << endl;

	cout << endl;
	timer.Start();
	HeapSortBook(iArr2, SORTTESTCASE);
	timer.Stop();

	cout << "힙책 : " << endl;
	cout << timer.getElapsedTime() << endl;

	cout << endl;
	timer.Start();
	CountingSort(iArr3, SORTTESTCASE, SORTTESTCASE);
	timer.Stop();

	//for (int i = 0; i < SORTTESTCASE; ++i)
	//	cout << iArr3[i] << " ";
	//cout << endl;

	cout << "도수내꺼 : " << endl;
	cout << timer.getElapsedTime() << endl;

	delete[] iArr;
	iArr = nullptr;
	delete[] iArr2;
	iArr2 = nullptr;
	delete[] iArr3;
	iArr3 = nullptr;
	// 
	// 
	//const unsigned int testcase = 10;
	//srand((unsigned int)time(NULL));
	//int iArr[testcase] = {1,5,4,7,8,9,1,4,2,6 };
	//					// 1 1 2 4 4 5 6 7 8 9

	//cout << "start" << endl;
	//for (int i = 0; i < testcase; ++i)
	//	cout << (iArr[i] = rand() % testcase) << " ";
	//cout << endl;

	//CountingSort(iArr, testcase, testcase);

	//cout << endl;
	//cout << "end" << endl;
	//for (int i = 0; i < testcase; ++i)
	//	cout << iArr[i] << " ";
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

void MergeSort(int arr[], int n)
{
	if (n == 1)
		return;
	
	int iFrontSize = n / 2;
	int* pFrontArr = new int[iFrontSize];
	int* pBackArr = new int[n - iFrontSize];

	int frontidx = 0;
	int backidx = 0;

	for (int i = 0; i < n; ++i)
	{
		if (i < iFrontSize)
			pFrontArr[frontidx++] = arr[i];

		else
			pBackArr[backidx++] = arr[i];
	}
	
	MergeSort(pFrontArr, iFrontSize);
	MergeSort(pBackArr, n - iFrontSize);

	frontidx = 0;
	backidx = 0;

	for (int i = 0; i < n; ++i)
	{
		if (pFrontArr[frontidx] < pBackArr[backidx])
		{
			if (frontidx == iFrontSize)
				arr[i] = pBackArr[backidx++];
			else
				arr[i] = pFrontArr[frontidx++];
		}
		else
		{
			if (backidx == n - iFrontSize)
				arr[i] = pFrontArr[frontidx++];
			else
				arr[i] = pBackArr[backidx++];
		}
	}

	delete[] pFrontArr;
	pFrontArr = nullptr;

	delete[] pBackArr;
	pBackArr;
}

void _Merge(int arr[], int n, int start, int end, int origin[])
{
	int iCenter = ((start + end) / 2);

	if (iCenter == 0 || start == end)
		return;

	_Merge(arr, n, start, iCenter, origin);
	_Merge(arr, n, iCenter + 1, end, origin);

	int frontidx = start;
	int backidx = iCenter + 1;

	for (int i = start; i < end + 1; ++i)
	{
		if (arr[frontidx] < arr[backidx])
		{
			if (frontidx == iCenter + 1)
				origin[i] = arr[backidx++];
			else
				origin[i] = arr[frontidx++];
		}
		else
		{
			if (backidx == end + 1)
				origin[i] = arr[frontidx++];
			else
				origin[i] = arr[backidx++];
		}
	}
}
void MergeSort2(int arr[], int n)
{
	if (n == 1)
		return;

	int* pTemp = new int[n];
	memcpy(pTemp, arr, sizeof(int) * n);

	_Merge(pTemp, n, 0, n - 1, arr);

	delete[] pTemp;
}

void Merge(int arr[], int start, int end, int temp[])
{
	int center = (start + end) / 2;
	int frontidx = start;
	int backidx = center + 1;
	int tmpCnt = frontidx;

	while (frontidx <= center && backidx <= end)
		temp[tmpCnt++] = arr[frontidx] <= arr[backidx] ? arr[frontidx++] : arr[backidx++];

	if (frontidx > center)
	{
		for (int i = backidx; i <= end; ++i)
			temp[tmpCnt++] = arr[i];
	}
	else
	{
		for (int i = frontidx; i <= center; ++i)
			temp[tmpCnt++] = arr[i];
	}

	for (int i = start; i <= end; ++i)
		arr[i] = temp[i];
}

void _MergeSort3(int arr[], int start, int end, int temp[])
{
	if(start == end) 
		return;

	int center = (start + end) / 2;

	_MergeSort3(arr, start, center, temp);
	_MergeSort3(arr, center + 1, end, temp);
	Merge(arr, start, end, temp);
}

void MergeSort3(int arr[], int n)
{
	int* temp = new int[n];

	_MergeSort3(arr, 0, n - 1, temp);

	delete[] temp;
	temp = nullptr;
}

void __mergesort(int arr[], int left, int right, int buff[])
{
	if (left < right)
	{
		int center = (left + right) / 2;
		int p = 0;
		int i;
		int j = 0;
		int k = left;

		__mergesort(arr, left, center, buff);
		__mergesort(arr, center + 1, right, buff);
		for (i = left; i <= center; ++i)
			buff[p++] = arr[i];
		while (i <= right && j < p)
			arr[k++] = (buff[j] <= arr[i]) ? buff[j++] : arr[i++];
		while (j < p)
			arr[k++] = buff[j++];
	}
}

int mergesort(int arr[], int n)
{
	int* buff = nullptr;
	if ((buff = (int*)calloc(n, sizeof(int))) == NULL)
		return -1;
	
	__mergesort(arr, 0, n - 1, buff);
	free(buff);
	return 0;
}

#define SWAP(type, a, b) {type temp = a; a = b; b = temp;}

void Heap(int arr[], int parent, int n)
{
	int child = (parent * 2) + 1;

	while (child < n)
	{
		if (child + 1 < n && arr[child] < arr[child + 1])
			++child;

		if (arr[parent] < arr[child])
			SWAP(int, arr[parent], arr[child]);

		parent = child;
		child = (parent * 2) + 1;
	}
}

void HeapSort(int arr[], int n)
{
	for (int i = n / 2; i >= 0; --i)
		Heap(arr, i, n);
	for (int i = n - 1; i > 0; --i)
	{
		SWAP(int, arr[0], arr[i]);
		Heap(arr, 0, i - 1);
	}
}

void downheap(int arr[], int left, int right)
{
	int temp = arr[left];
	int child;
	int parent;
	for (parent = left; parent < (right + 1) / 2; parent = child)
	{
		int cl = parent * 2 + 1;
		int cr = cl + 1;
		child = (cr <= right && arr[cr] > arr[cl]) ? cr : cl;
		if (temp >= arr[child])
			break;
		arr[parent] = arr[child];
	}
	arr[parent] = temp;
}

void HeapSortBook(int arr[], int n)
{
	int i;
	for (i = (n - 1) / 2; i >= 0; --i)
		downheap(arr, i, n - 1);
	for (i = n - 1; i > 0; --i)
	{
		SWAP(int, arr[0], arr[i]);
		downheap(arr, 0, i - 1);
	}
}

void CountingSort(int arr[], int n, int range)
{
	int* pCount = new int[range];
	int* pNewArr = new int[n];

	ZeroMemory(pCount, sizeof(int) * range);
	//ZeroMemory(pNewArr, sizeof(int) * n);

	for (int i = 0; i < n; ++i)
		pCount[arr[i]]++;

	for (int i = 1; i < n; ++i)
		pCount[i] += pCount[i - 1];

	for (int i = n - 1; i >= 0; --i)
		pNewArr[--pCount[arr[i]]] = arr[i];

	memcpy(arr, pNewArr, sizeof(int) * n);

	delete[] pCount;
	pCount = nullptr;
	delete[] pNewArr;
	pNewArr = nullptr;
}

void CountingSortBook(int a[], int n, int max)
{
	int i;
	int* f = (int*)calloc(max + 1, sizeof(int));
	int* b = (int*)calloc(n, sizeof(int));

	for (i = 0; i <= max; ++i) f[i] = 0;
	for (i = 0; i < n; ++i) ++f[a[i]];
	for (i = 1; i <= max; ++i) f[i] += f[i - 1];
	for (i = n - 1; i >= 0; --i) b[--f[a[i]]] = a[i];
	for (i = 0; i < n; ++i) a[i] = b[i];

	free(b);
	free(f);
}

bool SearchWord(char sour[], char search[], int len, int searchlen, int idx, int searchidx, bool res)
{
	for (int i = 0; i < len; ++i)
		cout << sour[i];

	cout << endl;
	
	// + ? | 출력
	for (int i = 0; i < idx + searchidx; ++i)
		cout << " ";

	if (res)
		cout << "+";
	else
		cout << "|";

	cout << endl;
	for (int i = 0; i < idx; ++i)
		cout << " ";
	for (int j = 0; j < searchlen; ++j)
		cout << search[j];

	cout << endl;

	return res;
}

bool SearchWord2(char sour[], char search[], int len, int searchlen, int idx, int searchidx, bool res)
{
	for (int i = 0; i < len; ++i)
		cout << sour[i];

	cout << endl;

	// + ? | 출력
	for (int i = 0; i < idx; ++i)
		cout << " ";

	if (res)
		cout << "+";
	else
		cout << "|";

	cout << endl;

	for (int i = 0; i < idx - searchidx; ++i)
		cout << " ";
	for (int j = 0; j < searchlen; ++j)
		cout << search[j];

	cout << endl;

	return res;
}

#define SEARCHTESTCASE 10000000
void SearchMain()
{
	//char* chArr = new char[SEARCHTESTCASE];

	//for (int i = 0; i < SEARCHTESTCASE - 8; ++i)
	//{
	//	chArr[i] = (i % 2) ? 'A' : 'B';
	//}

	//chArr[SEARCHTESTCASE - 9] = 'A';
	//chArr[SEARCHTESTCASE - 8] = 'B';
	//chArr[SEARCHTESTCASE - 7] = 'A';
	//chArr[SEARCHTESTCASE - 6] = 'B';
	//chArr[SEARCHTESTCASE - 5] = 'A';
	//chArr[SEARCHTESTCASE - 4] = 'A';
	//chArr[SEARCHTESTCASE - 3] = 'B';
	//chArr[SEARCHTESTCASE - 2] = 'A';
	//chArr[SEARCHTESTCASE - 1] = '\0';

	char chArr[20] = "ABCABAB ABABABAABAC";
	char chSearch[9] = "ABABAABA";

	CStopWatch timer;

	timer.Start();
	if (KMPSearch(chArr, chSearch, 19, 8))
		cout << "찾았땅" << endl;
	timer.Stop();

	cout << "KMP : " << timer.getElapsedTime() << endl;
	cout << endl;

	//timer.Start();
	//if (BruteForce(chArr, chSearch, SEARCHTESTCASE - 1, 8))
	//	cout << "찾았땅" << endl;
	//timer.Stop();

	//cout << "BTF : " << timer.getElapsedTime() << endl;
}

bool BruteForce(char sour[], char search[], int len, int searchlen)
{
	if (len < searchlen)
		return false;

	int iCnt = 0;
	for (int i = 0; i < len; ++i)
	{
		for (int j = 0; j < searchlen; ++j)
		{
			if (i + j >= len)
				return false;
			//else if (SearchWord(sour, search, len, searchlen, i, j, sour[i + j] == search[j]))
			else if(sour[i + j] == search[j])
				++iCnt;
			else
			{
				iCnt = 0;
				break;
			}
		}

		if (iCnt == searchlen)
		{
			cout << i << "에서 찾음" << endl;
			return true;
		}
	}

	return false;
}

bool KMPSearch(char sour[], char search[], int len, int searchlen)
{
	bool bRes = false;
	if (len < searchlen)
		return false;

	int* pTable = new int[searchlen];
	for (int i = 0; i < searchlen; ++i) pTable[i] = 0;

	int iIdx = 0;
	int TableValue = 0;
	for (int i = 0, j = 1; i < searchlen && j < searchlen;)
	{
		if (search[iIdx] == search[j])
		{
			++iIdx;
			pTable[j++] = ++TableValue;
		}
		else
		{
			TableValue = 0;

			if (iIdx == 0)
			{
				++j;
				++i;
				continue;
			}

			iIdx = pTable[iIdx - 1];
		}
	}

	for (int i = 0, j = 0; i < len;)
	{
		if (SearchWord2(sour, search, len, searchlen, i, j, sour[i] == search[j]))
		//if(sour[i] == search[j])
		{
			++i;
			++j;

			if (j == searchlen)
			{
				cout << i - searchlen << "에서 찾음" << endl;
				bRes = true;
				break;
			}
		}
		else
		{
			if (j != 0)
			{
				j = pTable[j - 1];
				continue;
			}
			i++;
		}
	}

	delete[] pTable;
	pTable = nullptr;

	return bRes;
}
