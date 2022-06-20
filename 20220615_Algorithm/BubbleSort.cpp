#include <iostream>
#include <windows.h>
using namespace std;
#include "StopWatch.h"


void bubblesort(int arr[], int size);
void bubblesort2(int arr[], int size);
void bubblesort3(int arr[], int size);
void bubblesort4(int arr[], int size);
int bubleStartIdx(int arr[], int size, int start);
bool PrintBubble(int arr[], int size, int position = -1, bool bswap = true);

#define MAXARR 8
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	srand((unsigned int)time(NULL));
	CStopWatch timer;

	int iArr[MAXARR] = {6,4,3,7,1,9,2,8};
	int iArr2[MAXARR] = { 6,4,3,7,1,9,2,8 };
	int iArr3[MAXARR] = { 6,4,3,7,1,9,2,8 };
	int iArr4[MAXARR] = { 6,4,3,7,1,9,2,8 };
	
	//for (int i = 0; i < MAXARR; ++i)
	//{
	//	iArr4[i] = iArr2[i] = iArr3[i] = iArr[i] =(MAXARR - i);
	//}

	int timetest[4];
	
	timer.Start();
	bubblesort(iArr, MAXARR);
	timer.Stop();
	cout << "걸린시간 : " << (timetest[0] = timer.getElapsedTime()) << '\n';

	cout << '\n';

	timer.Start();
	bubblesort2(iArr2, MAXARR);
	timer.Stop();
	cout << "걸린시간 : " << (timetest[1] = timer.getElapsedTime()) << '\n';

	timer.Start();
	bubblesort3(iArr3, MAXARR);
	timer.Stop();
	cout << "걸린시간 : " << (timetest[2] = timer.getElapsedTime()) << '\n';

	timer.Start();
	bubblesort4(iArr4, MAXARR);
	timer.Stop();
	cout << "걸린시간 : " << (timetest[3] = timer.getElapsedTime()) << '\n';

	cout << "0 : " << timetest[0] << '\n';
	cout << "1 : " << timetest[1] << '\n';
	cout << "2 : " << timetest[2] << '\n';
	cout << "3 : " << timetest[3] << '\n';

	return 0;
}

bool PrintBubble(int arr[], int size, int position, bool bswap)
{
	for (int i = 0; i < size; ++i)
	{
		if (i == position)
			cout << arr[i] << (bswap ? " + " : " - ");
		else
			cout << arr[i] << "   ";
	}

	cout << '\n';

	return bswap;
}

int bubleStartIdx(int arr[], int size, int start)
{
	for (int i = start; i < size - 1; ++i)
		if (arr[i] > arr[i + 1])
			return i;

	return size - 1;
}

void bubblesort(int arr[], int size)
{
	for (int i = 0; i < size - 1; ++i)
	{
		bool bChange = false;

		for (int j = size - 1; j > i; --j)
		{
			if (PrintBubble(arr, size, j - 1, arr[j - 1] > arr[j]))
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;

				bChange = true;
			}
		}

		if (!bChange)
			break;
	}
}

void bubblesort2(int arr[], int size)
{
	for (int i = 0; i < size - 1;)
	{
		bool bChange = false;

		for (int j = size - 1; j > (i = bubleStartIdx(arr, size, i)); --j)
		{
			if (PrintBubble(arr, size, j - 1, arr[j - 1] > arr[j]))
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;

				bChange = true;
			}
		}

		if (!bChange)
			break;
	}
}

void bubblesort3(int arr[], int size)
{
	for (int i = 0; i < size - 1;)
	{
		int last = size - 1;
		for (int j = size - 1; j > i; --j)
		{
			if (PrintBubble(arr, size, j - 1, arr[j - 1] > arr[j]))
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;

				last = j;
			}
		}

		i = last;
	}
}

void bubblesort4(int arr[], int size)
{
	int cnt = 0;
	int i = 0;
	for (int j = size - 1; j > (i = bubleStartIdx(arr, size, i)); --j)
	{
		if (PrintBubble(arr, size, j - 1, arr[j - 1] > arr[j]))
		{
			int temp = arr[j - 1];
			arr[j - 1] = arr[j];
			arr[j] = temp;

			j = size - ++cnt;
		}
		else
			cnt = 1;
	}
}