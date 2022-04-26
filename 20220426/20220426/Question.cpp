// 20220426.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

// Q1. p206 ���� ���� ���� .. ���ȣ�� �̿��ؼ�
//*/

int rec_func(int n);

int main()
{
    printf("%d", rec_func(10));
}

int rec_func(int n)
{
    if (n == 0)                     // �Ű������� ���� 0 �̶�� ��� ����
        return n;                   //  -> ���� ���� ����

    return n + rec_func(n - 1);     // �Ű����� + (�Ű����� - 1)
}

//*/

// Q2.   �Է¹޴� ���� ���� ���� ���ϴ� �Լ� abs()�� �����϶�
/*/
//      ex) ���� �Է�(���� -0) : -34
//          ���� ���� : 34

int PrintAbs(int a);        // ���� �� ��ȯ �Լ�

int main()
{
    int iCnt = 0;           // �Է� ��

    PrintAbs(iCnt);

    return 0;
}

int PrintAbs(int a)
{
    printf("���� �Է� (���� - 0) \t : ");

    if (!scanf("%d", &a))
    {
        printf("�߸��� �Է�!! \n\n");
        rewind(stdin);
    }

    if (a == 0)
        return a;

    printf("���� ���� \t \t : %d\n\n", a < 0 ? a : a * -1);

    return PrintAbs(a);
}

//*/

// Q3.   ������ �� ������ �� ���� ������ ��� �ǰ�
//*/
//      �ٽ� �� ���� ������ ������ ���´�.
//      ���� �¾ ������ ���� �� ���� ������ ��� �ǰ�
//      �ٽ� �Ѵ� �� ���� ������ ���´ٰ� �����Ҷ�,
//      �����̰� �Ŵ� ������ ������ 1�� �� ��ü ������ ���� ������ �� �� �ֵ���!
//      (�� , �����̴� �ڿ���ü / ������ ������ 1�� �̻�!)
// 
// �ݺ��� Ver.
/*/
int main()
{
    int iSnailCnt           = 0;
    int iSnailChild         = 0;
    int iSnailAdult         = 0;
    const int iYeartoMonth  = 12;

    printf("�����̴� ���� �� ���� ? : ");
    scanf("%d", &iSnailAdult);


    for (int i = 0; i <= iYeartoMonth; ++i)
    {
        printf("%d ����\n", i);

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

        printf("� ������ : %d\n", iSnailChild);
        printf("��ū ������ : %d\n\n", iSnailAdult);
    }

    printf("1�� ��.... \n %d ����!!!", iSnailCnt);

    return 0;
}
//*/

// ��� Ver.
/*
int SnailMultiply(int n)
{
    if (n == 0 || n == 1) 
        return 1;

    return SnailMultiply(n - 1) + SnailMultiply(n - 2);
}

int main()
{
    printf("%d ���� !!", SnailMultiply(12));

    return 0;
}
//*/

// Q4.   ��Ģ������ ���� ���α׷��� �ۼ��϶�.
/*/
//      ������´� ������ ����.
//      ���ϴ� ���� ����
//      1 : ����   2 : ����   3 : ����   4 : ������   0 : ����
//      �� ������ �Է��Ͻÿ� : 
//      "����" ����� xx �Դϴ�.

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
    int iScanfCheck = 0;                    // Scanf�� �ùٸ��� �۵��ߴ��� Ȯ��
    
    printf("���ϴ� ������ �����Ͻÿ�\n");
    printf("1 : ����, 2 : ����, 3 : ����, 4 : ������, 0 : ����\n");

    iScanfCheck = scanf("%d", &a);

    if (a > 4 || a < 0 || iScanfCheck == 0) // �Է¹��� ��� or �߸��� �Է�
        return a = -1;

    if (a == 0)                             // 0 �Է½� ����
        return a;

    return a;                               // �ùٸ� ����� �Էµ� a �� ��ȯ
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
    int iB = 0;                             // ���� ����

    int iScanfCheck = 0;                    // Scanf�� �ùٸ��� �۵��ߴ��� Ȯ��

    printf("�� ������ �Է��Ͻÿ� : ");
    iScanfCheck = scanf("%d", &iA);
    rewind(stdin);

    if (!iScanfCheck)                       // �߸��� �Է� -1 ��ȯ
        return a = -1;

    iScanfCheck = scanf("%d", &iB);
    rewind(stdin);

    if (!iScanfCheck)                       // �߸��� �Է� -1 ��ȯ
        return a = -1;

    switch (a)
    {
    case 1:
        printf("\"����\" ����� %d �Դϴ�.\n", GetPlus(iA, iB));
        break;
    case 2:
        printf("\"����\" ����� %d �Դϴ�.\n", GetMinus(iA, iB));
        break;
    case 3:
        printf("\"����\" ����� %d �Դϴ�.\n", GetMul(iA, iB));
        break;
    case 4:
        printf("\"������\" ����� %.4f �Դϴ�.\n", GetDiv((float)iA, (float)iB));
        break;
    default:
        printf("�߸��� �Է�!!");
        a = -1;
        break;
    }

    return a;
}

int PlayCalculator()
{
    int iNum = 0;           // �Է� ����

    iNum = CalculatorSel(iNum);

    if (0 == iNum)          // 0 ����, 0���� �۴ٸ� �߸��� �Է�
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
    printf("�߸��� �Է�! \n\n");
    system("pause");
    system("cls");

    return;
}
//*/

// Q5.   ���̰� 5�� int�� �迭�� �����ϰ�, ����ڷκ��� 5���� ������ �Է¹޴´�.
//      ������ ������ ����ϴ� ���α׷��� �ۼ��϶�.
//      1. �Էµ� ���� �� �ִ� ��
//      2. ............. �ּ� ��
//      3. �Էµ� �������� ��
// ���� : min/max�� �ʱ� �� ����, ÷�ڰ� �迭�� ũ�⸦ ���� �ʵ���
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

    printf("1. �Էµ� ���� �� �ִ� ��\t: %d\n", iMax);
    printf("2. ...............�ּ� ��\t: %d\n", iMin);
    printf("3. \t�Էµ� ���� �� ��\t: %d\n", iSum);

    return 0;
}
//*/