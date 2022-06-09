#include <iostream>
#include <vld.h>
#include "ExampleMain.h"
#include "string1.h"

const int ArSize = 10;
const int MaxLen = 81;

using std::cout;
using std::cin;
using std::endl;

int Example1()
{
	CString name;
	cout << "이름 : ";
	cin >> name;

	cout << name << "님 영어 속담" << ArSize << "개 입력 바람 : " << endl;
	CString sayings[ArSize];

	char temp[MaxLen];

	int total = 0;

	for (int i = 0; i < ArSize; ++i)
	{
		cout << i + 1 << ": ";
		cin.get(temp, MaxLen);
		while (cin && cin.get() != '\n')
			continue;

		if (!cin || temp[0] == '\0')
		{
			total = i;
			break;
		}
		else
			sayings[i] = temp;
	}

	if (total > 0)
	{
		cout << "입력된 속담" << endl;

		for (int i = 0; i < total; ++i)
			cout << sayings[i][0] << ": " << sayings[i] << endl;

		int shortest = 0;
		int first = 0;

		for (int i = 1; i < total; ++i)
		{
			if (sayings[i].length() < sayings[shortest].length())
				shortest = i;
			if (sayings[i] < sayings[first])
				first = i;
		}

		cout << "가장 짧은 속담 : " << endl << sayings[shortest] << endl;
		cout << "사전 순으로 가장 앞에 나오는 속담 : " << endl << sayings[first] << endl;

		cout << CString::HowMany() << "개의 CString 객체를 사용했습니다." << endl;
	}
	else
		cout << "입력 끝!" << endl;

	return 0;
}

int Question2()
{
	CString s1(" and I am a C++ Student.");
	CString s2 = "영문 이름을 입력하십시오 : ";
	CString s3;

	cout << s2;
	cin >> s3;

	s2 = "My name is " + s3;

	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "다음 문자열에는 \n" << s2 << "\n문자 'A'가 " << s2.find_cnt('A') << "개 들어있습니다." << endl;
	s1 = "red";

	CString rgb[3] = { CString(s1), CString("green"), CString("blue") };

	cout << "삼원색 이름 하나만 입력 : ";
	CString ans;
	bool success = false;

	while (cin >> ans)
	{
		ans.stringlow();

		for (int i = 0; i < 3; ++i)
		{
			if (ans == rgb[i])
			{
				cout << "정답!" << endl;
				success = true;
				break;
			}
		}

		if (success)
			break;
		else
			cout << "틀렸습니다.." << endl;
	}
	
	cout << "종료" << endl;

	return 0;
}