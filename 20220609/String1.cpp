#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "String1.h"

using std::cin;
using std::cout;

int CString::num_strings = 0;

CString::CString(const char* s)
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);

	num_strings++;
}

CString::CString()
{
	len = 4;
	str = new char[1];
	str[0] = '\0';
	num_strings++;
}

CString::CString(const CString& st)
{
	num_strings++;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
}

CString::~CString()
{
	--num_strings;
	if (str != nullptr)
	{
		delete[] str;
		str = nullptr;
	}
}

int CString::find_cnt(char sour)
{
	int iCnt = 0;
	for (int i = 0; i < len; ++i)
	{
		if (str[i] == sour)
			++iCnt;
	}

	return iCnt;
}

CString& CString::stringlow()
{
	for (int i = 0; i < len; ++i)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += ('a' - 'A');
		}
	}

	return *this;
}

CString& CString::stringup()
{
	for (int i = 0; i < len; ++i)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] += ('A' - 'a');
		}
	}

	return *this;
}

CString& CString::operator=(const CString& st)
{
	if (this == &st)
		return *this;

	delete[] str;
	str = nullptr;
	len = st.len;
	str = new char[len + 1];
	std::strcpy(str, st.str);
	return *this;
}

char& CString::operator[](int i)
{
	return str[i];
}

const char& CString::operator[](int i) const
{
	return str[i];
}

CString CString::operator+(const CString& st)
{
	char* temp = new char[len + st.len + 1];
	std::strcpy(temp, str);
	std::strcat(temp, st.str);
	CString strtemp(temp);
	delete[] temp;

	return strtemp;
}

int CString::HowMany()
{
	return num_strings;
}

bool operator<(const CString& st1, const CString& st2)
{
	return std::strcmp(st1.str, st2.str) < 0;
}

bool operator>(const CString& st1, const CString& st2)
{
	return st2 < st1;
}

bool operator==(const CString& st1, const CString& st2)
{
	return std::strcmp(st1.str, st2.str) == 0;
}

ostream& operator<<(ostream& os, const CString& st)
{
	os << st.str;
	return os;
}

istream& operator>>(istream& is, CString& st)
{
	char temp[CString::CINLIM];
	is.get(temp, CString::CINLIM);

	if (is)
		st = temp;

	while (is && is.get() != '\n')
		continue;

	return is;
}

CString operator+(const char* chTemp, CString& st1)
{
	char* temp = new char[std::strlen(chTemp) + st1.len + 1];
	std::strcpy(temp, chTemp);
	std::strcat(temp, st1.str);
	CString strtemp(temp);
	delete[] temp;

	return strtemp;
}