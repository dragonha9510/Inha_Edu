#pragma once

#include <iostream>
#include <string>

using namespace std;

class CReport
{
public:
	CReport(const string s) : str(s) { cout << "按眉 积己!" << endl;}
	~CReport() { cout << "按眉 昏力!" << endl; }
public:
	void comment() const { cout << str << endl; }
private: 
	string str;
};