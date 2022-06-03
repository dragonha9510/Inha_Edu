#include "stdafx.h"
#include "MyStack.h" 

CMyStack::CMyStack()
{
}

CMyStack::~CMyStack()
{
	Release();
}

int CMyStack::Initialize(int cnt)
{
	ptr = 0;
	stk = new int[cnt];

	if (stk == nullptr)
		return -1;

	max = cnt;

	return 0;
}

int CMyStack::Push(int x)
{
	if (ptr >= max)
	{
		int maxtemp = max;
		int* temp = new int[max];

		if (temp == nullptr)
			return -1;

		for (int i = 0; i < max; ++i)
			temp[i] = stk[i];

		delete[] stk;
		stk = nullptr;

		max += max / 2;

		stk = new int[max];

		if (stk == nullptr)
		{
			delete[] temp;
			temp = nullptr;
			return -1;
		}

		for (int i = 0; i < maxtemp; ++i)
			stk[i] = temp[i];
	}

	stk[ptr++] = x;

	return 0;
}

int CMyStack::Pop(int* x)
{
	if (IsEmpty())
		return -1;

	*x = stk[--ptr];

	return 0;
}

int CMyStack::Peek(int* x)
{
	if (IsEmpty())
		return -1;

	*x = stk[ptr - 1];

	return 0;
}

void CMyStack::Clear()
{
	ptr = 0;
}

int CMyStack::Capacity()
{
	return max;
}

int CMyStack::Size()
{
	return ptr;
}

int CMyStack::IsEmpty()
{
	return (ptr <= 0);
}

int CMyStack::IsFull()
{
	return (ptr >= max);
}

int CMyStack::Search(int x)
{
	for (int i = ptr - 1; i >= 0; --i)
	{
		if (stk[i] == x)
			return i;
	}

	return -1;
}

void CMyStack::Print()
{
	for (int i = 0; i < ptr; ++i)
		cout << stk[i];

	cout << endl;
}

void CMyStack::Release()
{
	if (stk != nullptr)
	{
		delete[] stk;
		stk = nullptr;
	}
}

