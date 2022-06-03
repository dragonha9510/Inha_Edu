#pragma once 
 
#ifndef __STOCK_H__
#define __STOCK_H__

class CStock
{
private:
	explicit CStock();
	virtual ~CStock();

public:
	CStock(const string& co, long n, double pr)
		:company(co), shares(n < 0 ? 0 : n), share_val(pr)
	{
		set_tot();
	}

public:
	void acquire(const string& co, long n, double pr);
	void buy(long num, double price);
	void sell(long num, double price);
	void update(double price);
	void show();

private:
	void set_tot() { total_val = shares * share_val; }

private:
	string company;
	long shares;
	double share_val;
	double total_val;
};

#endif // !__STOCK_H__