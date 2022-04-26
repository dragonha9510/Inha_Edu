// 20220426.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
    // 배열
    /*/
    int iArr[5] = {};

    for (int i = 0; i < 5; ++i)
    {
        scanf("%d", &iArr[i]);
    }
    //*/

    // sizeof
    /*/
    int iA = 0;
    int iArr[5] = {};
    int iTypeSize = 0;

    cout << sizeof(iA) << endl;
    cout << sizeof(iArr) << endl;
    cout << sizeof(iArr[0]) << endl;

    if(typeid(iA) == typeid(int))
    {
        iTypeSize = sizeof(iA);
    }
    //*/

    // 문자열 전용 출력 함수 gets, puts
    char str[80];

    printf("문자열 입력 : ");
    gets_s(str);                      // 입력
    printf("입력된 문자열 : ");
    puts(str);                      // 출력

    return 0;
}