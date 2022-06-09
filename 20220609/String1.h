#pragma once 
 
#ifndef __STRING1_H__
#define __STRING1_H__
 
#include <iostream>

using std::ostream;
using std::istream;

class CString
{
private:
	char* str;
	int len;
	static int num_strings;
	static const int CINLIM = 80;
	
public: // 생성자
	CString(const char* s);
	CString();
	CString(const CString& st);
	~CString();
	
public: // 기타 Method
	int length() const { return len; }
	int find_cnt(char sour);
	CString& stringlow();
	CString& stringup();

public: // 오버로딩 연산자
	CString& operator=(const CString& st);
	char& operator[](int i);
	const char& operator[](int i) const;
	CString operator+(const CString& st);

public: // 오버로딩 연산자 프렌드
	friend bool operator<(const CString& st1, const CString& st2);
	friend bool operator>(const CString& st1, const CString& st2);
	friend bool operator==(const CString& st1, const CString& st2);
	friend ostream& operator<<(ostream& os, const CString& st);
	friend istream& operator>>(istream& is, CString& st);

	friend CString operator+(const char* chTemp, CString& st1);

public: // Static
	static int HowMany();
};

#endif // !__STRING1_H__