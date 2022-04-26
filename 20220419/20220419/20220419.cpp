// 20220419.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#define _CRT_SECURE_NO_WARNINGS
//#pragma warning(disable:4996)

#include <iostream>
#include <string.h>


int main()
{
/*/
	int a = 10;
	int b = a;
	int c = a + 20;
	double da = 3.5;
	char ch = 'A';

	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);
	printf("변수 da의 값 : %.1lf\n", da);
	printf("변수 ch의 값 : %c\n", ch);

	//

	int a = 0, b, c;

	printf("변수 a의 값 : %d\n", a);
	printf("변수 b의 값 : %d\n", b);
	printf("변수 c의 값 : %d\n", c);

	char fruit[20] = "Strawberry";

	printf("%s \n", fruit);

	strcpy(fruit, "Test");

	printf("%s \n", fruit);

	system("pause");

	int a = 0;
	double d = 0;
	
	int b = scanf("%d %lf", &a, &d);

	if(b < 0)
		return -1;

	printf("%d %lf \n", a, d);

	char name[20];
	char grade;
	int iTemp = scanf("%s", name);

	if(iTemp > 0)
		scanf(" %c", &grade);

	system("cls");

	printf("입력결과 \n");
	printf("%s", name);
	printf("%c", grade);
	
	int a = 0;
	int b = ++a + a + ++a;
	printf("%d", b);

	int a = 10, b = 20;
	int res;

	printf("a = 10, b = 20 \n\n");

	res = (a > b);
	printf("a > b : %d\n", res);
	res = (a >= b);
	printf("a >= b : %d\n", res);
	res = (a <= b);
	printf("a <= b : %d\n", res);
	res = (a < b);
	printf("a < b : %d\n", res);
	res = (a == b);
	printf("a == b : %d\n", res);
	res = (a != b);
	printf("a != b : %d\n", res);

	int a = 20, b = 3;
	double res;

	res = ((double)a) / ((double)b);
	printf("a / b 의 결과 : %1lf\n", res);

	res = (double)(a / b);
	printf("a / b 의 결과 : %1lf\n", res);

	a = (int)res;
	printf("(int) %.1lf 의 결과 : %d\n", res, a);
	
	int a = 10, b = 20, res;

	res = (a > b) ? a : b;
	printf("큰 값 : %d\n", res);

//*/
	int a = 10;
	int b = 12;

	printf("a & b : %d\n", a & b);
	printf("a ^ b : %d\n", a ^ b);
	printf("a | b : %d\n", a | b);
	printf("~a : %d\n", ~a);
	printf("a << 1 : %d\n", a << 1);
	printf("a >> 2 : %d\n", a >> 2);

	return 0;
}