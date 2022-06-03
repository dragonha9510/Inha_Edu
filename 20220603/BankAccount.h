#pragma once 
 
#ifndef __BANKACCOUNT_H__
#define __BANKACCOUNT_H__

class CBankAccount
{
public:
	explicit CBankAccount();
	virtual ~CBankAccount();

public:
	int Initialize(string name = "È«±æµ¿", int accountnumber = 0, int balance = 0);
	int const PrintInfo();
	int Deposit(int amount);
	int Withdraw(int amount);
	void PrintBalance() { cout << "ÀÜ¾× : " << m_iBalance << endl; }

private:
	bool			m_bIsExist = false;
	string			m_strName;
	unsigned int	m_iAccountNumber;
	unsigned int	m_iBalance;
};

#endif // !__BANKACCOUNT_H__