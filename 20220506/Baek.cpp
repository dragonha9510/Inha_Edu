#include <iostream>

using namespace std;

int main()
{
    int iA = 0;
    int iRes = 0;
    int iCnt = 0;

    cin >> iA;

    iRes = (((iA / 10) + (iA % 10)) % 10) + ((iA % 10) * 10);
    ++iCnt;

    while (iRes != iA)
    {
        ++iCnt;
        iRes = (((iRes / 10) + (iRes % 10)) % 10) + ((iRes % 10) * 10);
    }

    cout << iCnt << endl;

    return 0;
}