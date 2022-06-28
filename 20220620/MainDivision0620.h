#pragma once

// Q1.	 입력 파일이름과 출력파일이름을 입력하면
//		임의의 수를 더해 암호화하여 출력하라.
//		ex) Input Source filename : source.txt
//			Input Encoding filename : encoding.txt
//			더해진 임의수를 encoding.txt맨 앞에 기입!

void SecureFileOut(bool bEn = true);

// Q2.	 암호화된 파일을 복호화 하는 프로그램
//		사용자가 입력파일 이름과 출력파일 이름을 입력하면
//		입력파일의 암호가 풀린 버전을 출력파일에 저장
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