#include "stdafx.h"
#include "MyQueue.h" 

CMyQueue::CMyQueue()
{
}

CMyQueue::~CMyQueue()
{
    Release();
}

int CMyQueue::Initialize(size_t size)
{
    if (size < 0)
    {
        cout << "�Էµ� ũ�� 0, �ٽ� �Ҵ� ���ּ���." << endl;
        return -1;
    }

    m_pDataArr = new int[size];

    if (m_pDataArr == nullptr)
    {
        cout << "�Ҵ� ����" << endl;
        exit(-1);
        return -1;
    }

    m_iCapacity = size;
    return 0;
}

int CMyQueue::Enque(int data)
{
    if (m_iSize == m_iCapacity)
    {
        cout << "���� ��!" << endl;
        return -1;
    }

    ++m_iSize;
    m_iPeek = m_iRear;
    m_pDataArr[m_iRear++] = data;

    if (m_iRear == m_iCapacity)
        m_iRear = 0;

    return 0;
}

int CMyQueue::Deque(int* data)
{
    if (m_iSize < 1)
    {
        cout << "�������!" << endl;
        return -1;
    }

    --m_iSize;
    *data = m_pDataArr[m_iFront++];

    if (m_iFront == m_iCapacity)
        m_iFront = 0;

    return 0;
}

int CMyQueue::search(int data)
{
	if (m_iSize == 0)
	{
		cout << "�������" << endl;
		return -1;
	}

	for (size_t iCnt = 0, i = m_iFront; iCnt < m_iSize; ++iCnt)
	{
        if (data == m_pDataArr[i])
        {
            cout << iCnt << " ��° �ε����� ����" << endl;
            return 0;
        }

		if (++i >= m_iCapacity)
			i = 0;
	}

    return -1;
}

int CMyQueue::Peek(int* data)
{
    if (m_iSize < 1)
    {
        cout << "�������!" << endl;
        return -1;
    }

    *data = m_pDataArr[m_iPeek];

    return 0;
}

void CMyQueue::Print()
{
    if (m_iSize == 0)
    {
        cout << "�������" << endl;
        return;
    }

    for (size_t iCnt = 0, i = m_iFront; iCnt < m_iSize; ++iCnt)
    {
        cout << m_pDataArr[i] << " ";

        if (++i >= m_iCapacity)
            i = 0;
    }
    cout << endl;
}

void CMyQueue::Release()
{
    if (m_pDataArr == nullptr)
        return;

    delete[] m_pDataArr;
    m_pDataArr = nullptr;
}