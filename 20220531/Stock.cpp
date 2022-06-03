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
		cout << "�ֽ� ���� ������ �� �� �����Ƿ�, " << company << " shares �� 0���� �����մϴ�." << endl;
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
		cout << "���� �ֽ� ���� ������ �� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�. " << endl;
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
		cout << "�ŵ� �ֽ� ���� ������ �� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�." << endl;
	else if (num > shares)
		cout << "���� �ֽĺ��� ���� �ֽ��� �ŵ��� �� �����Ƿ�, �ŷ��� ��ҵǾ����ϴ�." << endl;
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
	cout << "ȸ�� �� : " << company
		<< "�ֽ� �� : " << shares << endl
		<< "�ְ�    : $" << share_val
		<< "�ֽ� �� ��ġ : $" << total_val << endl;
}
