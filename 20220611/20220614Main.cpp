#include "stdafx0614.h"

int main()
{
	//Q1
	//TimeTest();

	//Q2
	/*/
	int N = 5;
	int Test[3][2];

	Test[0][0] = 1;
	Test[0][1] = 2;
	Test[1][0] = 1;
	Test[1][1] = 3;
	Test[2][0] = 3;
	Test[2][1] = 4;

	// 1,2
	// 1,3
	// 3,4
	// 
	// 1 234
	// 2 134
	// 3 142
	// 4 132
	// 5 

	int* res = SocialFriend(N, Test, 3);

	for (int i = 0; i < N; ++i)
		cout << i + 1 << "의 친구수 : " << res[i] << endl;

	delete[] res;
	res = nullptr;
	//*/

	//C1
	//Class0614_1();

	//Q3
	ChessQueen();

	return 0;
}