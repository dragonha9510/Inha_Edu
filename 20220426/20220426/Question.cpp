// 20220426.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

// Q1. p206 도전 실전 예제 .. 재귀호출 이용해서
//*/

int rec_func(int n);

int main()
{
    printf("%d", rec_func(10));
}

int rec_func(int n)
{
    if (n == 0)                     // 매개변수의 값이 0 이라면 재귀 종료
        return n;                   //  -> 더할 값이 없음

    return n + rec_func(n - 1);     // 매개변수 + (매개변수 - 1)
}

//*/

// Q2.   입력받는 값의 절대 값을 구하는 함수 abs()를 구현하라
/*/
//      ex) 정수 입력(종료 -0) : -34
//          절대 값은 : 34

int PrintAbs(int a);        // 절대 값 반환 함수

int main()
{
    int iCnt = 0;           // 입력 값

    PrintAbs(iCnt);

    return 0;
}

int PrintAbs(int a)
{
    printf("정수 입력 (종료 - 0) \t : ");

    if (!scanf("%d", &a))
    {
        printf("잘못된 입력!! \n\n");
        rewind(stdin);
    }

    if (a == 0)
        return a;

    printf("절대 값은 \t \t : %d\n\n", a < 0 ? a : a * -1);

    return PrintAbs(a);
}

//*/

// Q3.   달팽이 한 마리가 한 달이 지나면 어른이 되고
//*/
//      다시 한 달이 지나면 새끼를 낳는다.
//      새로 태어난 달팽이 역시 한 달이 지나면 어른이 되고
//      다시 한달 후 부터 새끼를 낳는다고 가정할때,
//      달팽이가 매달 새끼를 낳으면 1년 후 전체 달팽이 수는 얼마인지 알 수 있도록!
//      (단 , 달팽이는 자웅동체 / 달팽이 수명은 1년 이상!)
// 
// 반복문 Ver.
/*/
int main()
{
    int iSnailCnt           = 0;
    int iSnailChild         = 0;
    int iSnailAdult         = 0;
    const int iYeartoMonth  = 12;

    printf("달팽이는 지금 몇 마리 ? : ");
    scanf("%d", &iSnailAdult);


    for (int i = 0; i <= iYeartoMonth; ++i)
    {
        printf("%d 개월\n", i);

        if (i == 1)
        {
            iSnailChild = iSnailAdult;
        }
        else if (i > 1)
        {
            iSnailAdult += iSnailChild;
            iSnailChild = iSnailCnt;
        }

        iSnailCnt = iSnailAdult;

        printf("어린 달팽이 : %d\n", iSnailChild);
        printf("다큰 달팽이 : %d\n\n", iSnailAdult);
    }

    printf("1년 후.... \n %d 마리!!!", iSnailCnt);

    return 0;
}
//*/

// 재귀 Ver.
/*
int SnailMultiply(int n)
{
    if (n == 0 || n == 1) 
        return 1;

    return SnailMultiply(n - 1) + SnailMultiply(n - 2);
}

int main()
{
    printf("%d 마리 !!", SnailMultiply(12));

    return 0;
}
//*/

// Q4.   사칙연산을 위한 프로그램을 작성하라.
/*/
//      출력형태는 다음과 같다.
//      원하는 연산 선택
//      1 : 덧셈   2 : 뺄셈   3 : 곱셈   4 : 나눗셈   0 : 종료
//      두 정수를 입력하시오 : 
//      "덧셈" 결과는 xx 입니다.

int     CalculatorSel(int a);
int     GetPlus(int a, int b);
int     GetMinus(int a, int b);
int     GetMul(int a, int b);
float   GetDiv(float a, float b);
int     CalculatorRes(int a);

int     PlayCalculator();

void    WrongInput();

int main()
{
    return PlayCalculator();
}

int CalculatorSel(int a)
{
    int iScanfCheck = 0;                    // Scanf가 올바르게 작동했는지 확인
    
    printf("원하는 연산을 선택하시오\n");
    printf("1 : 덧셈, 2 : 뺄셈, 3 : 곱셈, 4 : 나눗셈, 0 : 종료\n");

    iScanfCheck = scanf("%d", &a);

    if (a > 4 || a < 0 || iScanfCheck == 0) // 입력범위 벗어남 or 잘못된 입력
        return a = -1;

    if (a == 0)                             // 0 입력시 종료
        return a;

    return a;                               // 올바른 종료시 입력된 a 값 반환
}

int GetPlus(int a, int b)
{
    return a + b;
}

int GetMinus(int a, int b)
{
    return a - b;
}

int GetMul(int a, int b)
{
    return a * b;
}

float GetDiv(float a, float b)
{
    return a / b;
}

int CalculatorRes(int a)
{
    int iA = 0;
    int iB = 0;                             // 연산 변수

    int iScanfCheck = 0;                    // Scanf가 올바르게 작동했는지 확인

    printf("두 정수를 입력하시오 : ");
    iScanfCheck = scanf("%d", &iA);
    rewind(stdin);

    if (!iScanfCheck)                       // 잘못된 입력 -1 반환
        return a = -1;

    iScanfCheck = scanf("%d", &iB);
    rewind(stdin);

    if (!iScanfCheck)                       // 잘못된 입력 -1 반환
        return a = -1;

    switch (a)
    {
    case 1:
        printf("\"덧셈\" 결과는 %d 입니다.\n", GetPlus(iA, iB));
        break;
    case 2:
        printf("\"뺄셈\" 결과는 %d 입니다.\n", GetMinus(iA, iB));
        break;
    case 3:
        printf("\"곱셈\" 결과는 %d 입니다.\n", GetMul(iA, iB));
        break;
    case 4:
        printf("\"나눗셈\" 결과는 %.4f 입니다.\n", GetDiv((float)iA, (float)iB));
        break;
    default:
        printf("잘못된 입력!!");
        a = -1;
        break;
    }

    return a;
}

int PlayCalculator()
{
    int iNum = 0;           // 입력 변수

    iNum = CalculatorSel(iNum);

    if (0 == iNum)          // 0 종료, 0보다 작다면 잘못된 입력
        return iNum;
    else if (iNum < 0)
    {
        WrongInput();
    }
    else
    {
        CalculatorRes(iNum);
        system("pause");
        system("cls");
    }

    return PlayCalculator();
}

void WrongInput()
{
    rewind(stdin);
    printf("잘못된 입력! \n\n");
    system("pause");
    system("cls");

    return;
}
//*/

// Q5.   길이가 5인 int형 배열을 선언하고, 사용자로부터 5개의 정수를 입력받는다.
//      다음의 내용을 출력하는 프로그램을 작성하라.
//      1. 입력된 정수 중 최대 값
//      2. ............. 최소 값
//      3. 입력된 정수들의 합
// 주의 : min/max의 초기 값 주의, 첨자가 배열의 크기를 넘지 않도록
/*/
int main()
{
    int iArr[5] = { 0 };
    int iMin = 0;
    int iMax = 0;
    int iSum = 0;
    unsigned int iArrSize = sizeof(iArr) / sizeof(iArr[0]);

    for (unsigned int i = 0; i < iArrSize; ++i)
    {
        scanf("%d", &iArr[i]);

        if (iMin > iArr[i] || iMin == 0)
        {
            iMin = iArr[i];
        }

        if (iMax < iArr[i])
        {
            iMax = iArr[i];
        }

        iSum += iArr[i];
    }

    printf("1. 입력된 정수 중 최대 값\t: %d\n", iMax);
    printf("2. ...............최소 값\t: %d\n", iMin);
    printf("3. \t입력된 정수 의 합\t: %d\n", iSum);

    return 0;
}
//*/