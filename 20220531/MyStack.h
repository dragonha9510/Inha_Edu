#pragma once 
 
#ifndef __MYSTACK_H__
#define __MYSTACK_H__
 
class CMyStack
{
public:
	explicit CMyStack();
	virtual	~CMyStack();

public:
	int Initialize(int cnt = 1);
	int Push(int x);
	int Pop(int* x);
	int Peek(int* x);
	void Clear();
	int Capacity();
	int Size();
	int IsEmpty();
	int IsFull();
	int Search(int x);
	void Print();
	void Release();

private:
	int max = 0;
	int ptr = 0;
	int* stk = nullptr;
};

#endif // !__MYSTACK_H__