#pragma once 
 
#ifndef __Stack_H__
#define __Stack_H__
 
class CStack
{
public:
	CStack();
	~CStack();

public:
	int Initialize(int cnt = 1);
	int Push(string x);
	int Pop(string* x);
	int Peek(string* x);
	void Clear();
	int Capacity();
	int Size();
	int IsEmpty();
	int IsFull();
	int Search(string x);
	void Print();
	void Release();

private:
	int max = 0;
	int ptr = 0;
	string* stk = nullptr;
};

#endif // !__Stack_H__