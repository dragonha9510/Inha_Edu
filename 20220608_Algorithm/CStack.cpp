#include "stdafx.h"
#include "CStack.h" 

CStack::CStack()
{
}

CStack::~CStack()
{
	Release();
}

int CStack::Initialize(int cnt)
{
	ptr = 0;
	stk = new string[cnt];

	if (stk == nullptr)
		return -1;

	max = cnt;

	return 0;
}

int CStack::Push(string x)
{
	if (ptr >= max)
	{
		int maxtemp = max;
		string* temp = new string[max];

		if (temp == nullptr)
			return -1;

		for (int i = 0; i < max; ++i)
			temp[i] = stk[i];

		delete[] stk;
		stk = nullptr;

		max += max / 2;

		stk = new string[max];

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

int CStack::Pop(string* x)
{
	if (IsEmpty())
		return -1;

	*x = stk[--ptr];

	return 0;
}

int CStack::Peek(string* x)
{
	if (IsEmpty())
		return -1;

	*x = stk[ptr - 1];

	return 0;
}

void CStack::Clear()
{
	ptr = 0;
}

int CStack::Capacity()
{
	return max;
}

int CStack::Size()
{
	return ptr;
}

int CStack::IsEmpty()
{
	return (ptr <= 0);
}

int CStack::IsFull()
{
	return (ptr >= max);
}

int CStack::Search(string x)
{
	for (int i = ptr - 1; i >= 0; --i)
	{
		if (stk[i] == x)
			return i;
	}

	return -1;
}

void CStack::Print()
{
	for (int i = 0; i < ptr; ++i)
		cout << stk[i] << " ";

	cout << endl;
}

void CStack::Release()
{
	if (stk != nullptr)
	{
		delete[] stk;
		stk = nullptr;
	}
}

