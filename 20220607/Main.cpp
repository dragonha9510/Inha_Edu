#include "stdafx.h"

void reverseDisplay(int data)
{
	if (data == 0)
		return;

	cout << data % 10;
	reverseDisplay(data / 10);
}

void reverseDisplay(const string& data)
{
	if (data.empty())
		return;

	string strElse = data;

	cout << strElse.back();
	strElse.pop_back();

	reverseDisplay(strElse);
}

void permutations(const string& str, int i, int length)
{
	string strElse = str;
	if (i == length - 1)
	{
		cout << strElse << endl;
		return;
	}

	for (int j = i; j < length; j++)
	{
		char temp = strElse[i];
		strElse[i] = strElse[j];
		strElse[j] = temp;

		permutations(strElse, i + 1, length);
	}
}

int main()
{
	system("cls");
	/*/
	system("cls");

	CVector3 u(-1, 3, 2);
	CVector3 v(3, -4, 1);

	cout << "1." << endl;
	cout << "(a) u + v = " << u + v << endl;
	cout << "(b) u - v = " << u - v << endl;
	cout << "(c) 3u + 2v = " << (u * 3) + (v * 2) << endl;
	cout << "(d) -2u + v = " << (u * -2) + v << endl;

	cout << endl;
	cout << "2." << endl;
	cout << "u.normalize() : " << u.normalize() << endl;
	cout << "v.normalize() : " << v.normalize() << endl;

	cout << endl;
	cout << "3. " << endl;
	u = CVector3(1, 1, 1);
	v = CVector3(2, 3, 4);
	cout << "(a) u = 1/1/1 v = 2/3/4 angle : " << CVector3::angle(u, v) << endl;

	u = CVector3(1, 1, 0);
	v = CVector3(-2, 2, 0);
	cout << "(b) u = 1/1/0 v = -2/2/0 angle : " << CVector3::angle(u, v) << endl;

	u = CVector3(-1, -1, -1);
	v = CVector3(3, 1, 0);
	cout << "(c) u = -1/-1/-1 v = 3/1/0 angle : " << CVector3::angle(u, v) << endl;

	cout << endl;
	cout << "4." << endl;

	CVector3 A(0, 0, 0);
	CVector3 B(0, 1, 3);
	CVector3 C(5, 1, 0);

	CVector3 AB = B - A;
	CVector3 AC = C - A;

	cout << CVector3::cross(AB, AC, 0) << endl;
	cout << CVector3::cross(AB, AC, 1) << endl;
	//*/

	// 다음 함수를 사용하여 int 값을 역으로 화면에 출력하는 코드를 작성하라.
	// void reverseDisplay(int value)
	//reverseDisplay(12345);

	//cout << endl;

	//reverseDisplay("abcd");

	string strInput;
	
	cin >> strInput;

	permutations(strInput, 0, strInput.length());

	cout << endl;

	return 0;
}