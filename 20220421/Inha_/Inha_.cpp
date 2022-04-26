// Inha_.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <string>

using namespace std;


int main()
{
    string s = "12:00:00AM";
    string strRes = "";

    size_t nPos = s.find('P');
    int iTempTime = 0;

    if (nPos == string::npos)
    {
        // AM
        iTempTime = stoi(s);

        if (iTempTime == 12 || iTempTime < 10)
        {
            iTempTime = iTempTime < 10 ? iTempTime : 0;
            strRes = "0";
        }
    }
    else
    {
        // PM
        iTempTime = stoi(s);

        if (iTempTime != 12)
            iTempTime += 12;
    }

    strRes += to_string(iTempTime);
    
    s.pop_back();
    s.pop_back();

    for (size_t i = strRes.size(); i < s.size(); ++i)
    {
        strRes += s[i];
    }

    cout << strRes << endl;

    return 0;
}
