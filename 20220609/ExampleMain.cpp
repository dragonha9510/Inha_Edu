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
	cout << "�̸� : ";
	cin >> name;

	cout << name << "�� ���� �Ӵ�" << ArSize << "�� �Է� �ٶ� : " << endl;
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
		cout << "�Էµ� �Ӵ�" << endl;

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

		cout << "���� ª�� �Ӵ� : " << endl << sayings[shortest] << endl;
		cout << "���� ������ ���� �տ� ������ �Ӵ� : " << endl << sayings[first] << endl;

		cout << CString::HowMany() << "���� CString ��ü�� ����߽��ϴ�." << endl;
	}
	else
		cout << "�Է� ��!" << endl;

	return 0;
}

int Question2()
{
	CString s1(" and I am a C++ Student.");
	CString s2 = "���� �̸��� �Է��Ͻʽÿ� : ";
	CString s3;

	cout << s2;
	cin >> s3;

	s2 = "My name is " + s3;

	cout << s2 << ".\n";
	s2 = s2 + s1;
	s2.stringup();
	cout << "���� ���ڿ����� \n" << s2 << "\n���� 'A'�� " << s2.find_cnt('A') << "�� ����ֽ��ϴ�." << endl;
	s1 = "red";

	CString rgb[3] = { CString(s1), CString("green"), CString("blue") };

	cout << "����� �̸� �ϳ��� �Է� : ";
	CString ans;
	bool success = false;

	while (cin >> ans)
	{
		ans.stringlow();

		for (int i = 0; i < 3; ++i)
		{
			if (ans == rgb[i])
			{
				cout << "����!" << endl;
				success = true;
				break;
			}
		}

		if (success)
			break;
		else
			cout << "Ʋ�Ƚ��ϴ�.." << endl;
	}
	
	cout << "����" << endl;

	return 0;
}