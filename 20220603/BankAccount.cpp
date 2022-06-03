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
		cout << "이미 계좌가 개설되어 있습니다." << endl;
		return -1;
	}

    if (accountnumber < 0 || balance < 0)
    {
        cout << "계좌번호와 잔액은 음수가 될 수 없음 !" << endl;
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
        cout << "예금주 정보가 존재하지 않음" << endl;
        return -1;
    }

    cout << "--------------------------" << endl;
    cout << "예금주   : " << m_strName << endl;
    cout << "계좌번호 : " << m_iAccountNumber << endl;
    cout << "잔액     : " << m_iBalance << endl;
	cout << "--------------------------" << endl;

    return 0;
}

int CBankAccount::Deposit(int amount)
{
    if (m_iBalance + amount > UINT32_MAX)
    {
        cout << "계좌 최대 금액 초과" << endl;
        return -1;
    }

    m_iBalance += amount;

    return 0;
}

int CBankAccount::Withdraw(int amount)
{
    if ((int)m_iBalance < amount)
    {
        cout << "잔액 부족 !" << endl;
        return -1;
    }

    m_iBalance -= amount;

    return 0;
}