#pragma once

#include <iostream>
#include <string>

using namespace std;

class CReport
{
public:
	CReport(const string s) : str(s) { cout << "��ü ����!" << endl;}
	~CReport() { cout << "��ü ����!" << endl; }
public:
	void comment() const { cout << str << endl; }
private: 
	string str;
};