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
	cout << num_strings << ": \"" << str << "\" 按眉 积己\n";
}

CStringBad::CStringBad()
{
	len = 4;
	str = new char[4];
	std::strcpy(str, "C++");
	num_strings++;
	cout << num_strings << ": \"" << str << "\" 叼弃飘 按眉 积己\n";
}

CStringBad::~CStringBad()
{
	cout << "\"" << str << "\" 按眉 家戈, ";
	--num_strings;
	cout << "巢篮 按眉 荐 : " << num_strings << "\n";

	delete[] str;
	str = nullptr;
}

std::ostream& operator<<(std::ostream& os, const CStringBad& st)
{
	os << st.str;
	return os;
}