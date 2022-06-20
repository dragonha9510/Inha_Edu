#include <windows.h>
#include <iostream>
#include <vld.h>

using namespace std;

#include "MainDivision0616.h"

int main()
{
	// 별 찍기
	/*/
	int cnt = 0;
	int iInput = 0;
	cin >> iInput;
	//TriangleWithStar(iInput);
	S(iInput - 1, iInput);
	//*/

	// 수업 1
	/*/
	Class0616Main1();
	//*/

	// 수업 2
	/*/
	Class0616Main2();
	//*/

	// 수업 3
	/*/
	Class0616Main3();
	//*/

	// 수업 4
	//*/
	//Class0616Main4();
	//*/

	// 선택 정렬
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