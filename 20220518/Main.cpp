#include <iostream>

using namespace std;

int main()
{
	cout << "\a암호명 \"화려한 외출\" 작전이 개시되었습니다!\n";
	cout << "8 자리 비밀번호를 입력하시오 : ________\b\b\b\b\b\b\b\b";

	long Code;

	cin >> Code;

	cout << "\a입력 비밀번호 " << Code << " 입니다." << endl;
	cout << "\a 비밀번호가 맞습니다! z3 계획을 진행하십시오!\n";

	return 0;
}