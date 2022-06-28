#pragma once

// Q1.	 �Է� �����̸��� ��������̸��� �Է��ϸ�
//		������ ���� ���� ��ȣȭ�Ͽ� ����϶�.
//		ex) Input Source filename : source.txt
//			Input Encoding filename : encoding.txt
//			������ ���Ǽ��� encoding.txt�� �տ� ����!

void SecureFileOut(bool bEn = true);

// Q2.	 ��ȣȭ�� ������ ��ȣȭ �ϴ� ���α׷�
//		����ڰ� �Է����� �̸��� ������� �̸��� �Է��ϸ�
//		�Է������� ��ȣ�� Ǯ�� ������ ������Ͽ� ����
//		ex) Input Source filename : encoding.txt
//			Input Decoding filename : dest.txt

void OperationalFileOut();


// Algorithm

void ShellSort(int arr[], int n);
void ShellSortMain();

void QuickSort(int arr[], int n, int start, int end);
void QuickSort2(int arr[], int n, int start, int end);
void QuickSortBook(int arr[], int left, int right);

void MergeSort(int arr[], int n);
void MergeSort2(int arr[], int n);
void MergeSort3(int arr[], int n);
void __mergesort(int arr[], int left, int right, int buff[]);
int mergesort(int arr[], int n);

void HeapSort(int arr[], int n);
void HeapSortBook(int arr[], int n);

void CountingSort(int arr[], int n, int range);
void CountingSortBook(int a[], int n, int max);


// Search Algorithm
void SearchMain();
bool BruteForce(char sour[], char search[], int len, int searchlen);