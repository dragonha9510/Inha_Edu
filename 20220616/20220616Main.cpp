#include <windows.h>
#include <iostream>
#include <vld.h>

using namespace std;

#include "MainDivision0616.h"

int main()
{
	// �� ���
	/*/
	int cnt = 0;
	int iInput = 0;
	cin >> iInput;
	//TriangleWithStar(iInput);
	S(iInput - 1, iInput);
	//*/

	// ���� 1
	/*/
	Class0616Main1();
	//*/

	// ���� 2
	/*/
	Class0616Main2();
	//*/

	// ���� 3
	/*/
	Class0616Main3();
	//*/

	// ���� 4
	//*/
	//Class0616Main4();
	//*/

	// ���� ����
	//*/
	SelectSortMain();
	//*/

	// 3n + 1
	/*/
	for (unsigned long long i = 1; i < (UINT64_MAX - 1) / 3; ++i)
	{
		recursion3n1(i);
		cout << '\n';
	}
	//*/
	return 0;
}