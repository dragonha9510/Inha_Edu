#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

class _char
{
public:
	_char(char* a)
	{
		m_chTest = a;
		for (int i = 0; true; ++i)
		{
			if (*(a + i) == '\0')
				break;

			++m_iLength;
		}
	}
	_char(char a)
	{
		m_chTest = &a;

	}
	~_char() 
	{
		m_chTest = nullptr;
	}
public:
	char* operator+ (char* a)
	{
		char* Temp = m_chTest;
		int iTempLength = 0;

		for (int i = 0; true; ++i)
		{
			if (*(a + i) == '\0')
				break;

			++iTempLength;
		}

		strcat_s(Temp, m_iLength + iTempLength + 1, a);

		return Temp;
	}
private:
	char* m_chTest = nullptr;
	int m_iLength = 0;
};
//*/

#define CHARMAX 255

int main()
{
	char chTempA[CHARMAX] = "Line";
	char chTempB[CHARMAX] = "Apple";
	_char chA = chTempA;
	_char chB = chTempB;

	printf("%s\n", chA + chTempB);
}

//*/