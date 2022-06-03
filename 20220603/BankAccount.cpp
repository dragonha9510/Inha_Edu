#include "stdafx.h"
#include "BankAccount.h" 

CBankAccount::CBankAccount()
{
    m_iAccountNumber = 0;
    m_iBalance = 0;
    m_strName = "NULL";
}

CBankAccount::~CBankAccount()
{
}

int CBankAccount::Initialize(string name, int accountnumber, int balance)
{
    if(m_bIsExist)
	{
		cout << "�̹� ���°� �����Ǿ� �ֽ��ϴ�." << endl;
		return -1;
	}

    if (accountnumber < 0 || balance < 0)
    {
        cout << "���¹�ȣ�� �ܾ��� ������ �� �� ���� !" << endl;
        return -1;
    }

    m_strName = name;
    m_iAccountNumber = accountnumber;
    m_iBalance = balance;
    m_bIsExist = true;

    return 0;
}

int const CBankAccount::PrintInfo()
{
    if (!m_bIsExist)
    {
        cout << "������ ������ �������� ����" << endl;
        return -1;
    }

    cout << "--------------------------" << endl;
    cout << "������   : " << m_strName << endl;
    cout << "���¹�ȣ : " << m_iAccountNumber << endl;
    cout << "�ܾ�     : " << m_iBalance << endl;
	cout << "--------------------------" << endl;

    return 0;
}

int CBankAccount::Deposit(int amount)
{
    if (m_iBalance + amount > UINT32_MAX)
    {
        cout << "���� �ִ� �ݾ� �ʰ�" << endl;
        return -1;
    }

    m_iBalance += amount;

    return 0;
}

int CBankAccount::Withdraw(int amount)
{
    if ((int)m_iBalance < amount)
    {
        cout << "�ܾ� ���� !" << endl;
        return -1;
    }

    m_iBalance -= amount;

    return 0;
}