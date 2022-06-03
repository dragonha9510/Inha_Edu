#include "stdafx.h"
#include "Stock.h" 

CStock::CStock()
{
	company = "no name";
	shares = 0;
	share_val = 0.0;
	total_val = 0.0;
}

CStock::~CStock()
{
}

void CStock::acquire(const string& co, long n, double pr)
{
	company = co;
	if (n < 0)
	{
		cout << "주식 수는 음수가 될 수 없으므로, " << company << " shares 를 0으로 설정합니다." << endl;
		shares = 0;
	}
	else
		shares = n;

	share_val = pr;
	set_tot();

}

void CStock::buy(long num, double price)
{
	if (num < 0)
		cout << "매입 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다. " << endl;
	else
	{
		shares += num;
		share_val = price;
		set_tot();
	}
}

void CStock::sell(long num, double price)
{
	if (num < 0)
		cout << "매도 주식 수는 음수가 될 수 없으므로, 거래가 취소되었습니다." << endl;
	else if (num > shares)
		cout << "보유 주식보다 많은 주식을 매도할 수 없으므로, 거래가 취소되었습니다." << endl;
	else
	{
		shares -= num;
		share_val = price;
		set_tot();
	}
}

void CStock::update(double price)
{
	share_val = price;
	set_tot();
}

void CStock::show()
{
	cout << "회사 명 : " << company
		<< "주식 수 : " << shares << endl
		<< "주가    : $" << share_val
		<< "주식 총 가치 : $" << total_val << endl;
}
