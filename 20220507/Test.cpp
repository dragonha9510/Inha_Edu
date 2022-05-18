#include <iostream>

using namespace std;

int main()
{
	int iCnt = 0;

	cin >> iCnt;

	int iMin = 0;
	int iMax = 0;
	int iNum = 0;

	cin >> iNum;
	iMax = iNum;
	iMin = iNum;

	for (int i = 0; i < iCnt - 1; ++i)
	{
		cin >> iNum;
	
		iMin > iNum ? (iMin = iNum) : (iMax < iNum ? (iMax = iNum) : false);
	}

	cout << iMin << " " << iMax;

	return 0;
}