#pragma once 
 
#ifndef __MYQUEUE_H__
#define __MYQUEUE_H__
 
class CMyQueue
{
public:
	explicit CMyQueue();
	~CMyQueue();

public:
	int Initialize(size_t size = 10);
	int Enque(string data);
	int Deque(string* data);
	int search(string data);
	int Peek(string* data);
	void Print();
	void Release();

public:
	size_t size() { return m_iSize; }
	size_t capacity() { return m_iCapacity; }
	void clear() { m_iSize = 0; m_iRear = 0; m_iFront = 0; m_iPeek = 0; }

private:
	size_t m_iSize		= 0;
	size_t m_iCapacity	= 0;
	int m_iRear			= 0;
	int m_iFront		= 0;
	int m_iPeek			= 0;
	string* m_pDataArr		= nullptr;
};

#endif // !__MYQUEUE_H__