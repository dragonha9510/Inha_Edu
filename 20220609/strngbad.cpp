#define _CRT_SECURE_NO_WARNINGS

#include <cstring>
#include "strngbad.h"

using std::cout;

int CStringBad::num_strings = 0;

CStringBad::CStringBad(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_strings++;
	cout << num_strings << ": \"" << str << "\" ��ü ����\n";
}

CStringBad::CStringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" ����Ʈ ��ü ����\n";
}

CStringBad::~CStringBad()
{
	cout << "\"" << str << "\" ��ü �Ҹ�, ";
	--num_strings;
	cout << "���� ��ü �� : " << num_strings << "\n";

	delete[] str;
	str = nullptr;
}

std::ostream& operator<<(std::ostream& os, const CStringBad& st)
{
	os << st.str;
	return os;
}