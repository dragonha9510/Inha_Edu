#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_str(char** pps, int cnt);

void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int Max(int a, int b);

int main()
{
	/*/
	char* pary[3];

	pary[0] = "dog";
	pary[1] = "blacktiger";
	pary[2] = "horse";

	for (int i = 0; i < 3; ++i)
	{
		printf("%p\t", &pary[i]);
		printf("%s\n", pary[i]);
	}


	printf("\n%d\n", (&pary[1] - pary));

	printf("\n%d\n", (&pary[2] - &pary[1]));

	printf("\n%d\n", strlen(pary[1]));
	//*/

	/*/
	int iA		= 10;
	int* pA		= &iA;
	int** ppA	= &pA;

	printf("%d\n", **ppA);
	printf("%d\n", *pA);
	printf("\n");
	printf("%p\n", &iA);
	printf("%p\n", &pA);
	printf("%p\n", &ppA);
	printf("\n");
	printf("%p\n", &(*pA));
	//*/

	/*/
	char* ptr_ary[] = { "eagle", "tiger", "lion", "squirrel" };
	int count;

	count = sizeof(ptr_ary) / sizeof(ptr_ary[0]);
	print_str(ptr_ary, count);
	//*/

	/*/
	int ary[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int(*pa)[4];

	pa = ary;
	for (int i = 0; i < 3; ++i)
	{
		printf("%5d", *(*(pa + i) + i));
	}
	//*/

	/*/
	int sel = 0;

	scanf("%d", &sel);

	switch (sel)
	{
	case 1:
		func(sum);
		break;
	case 2:
		func(mul);
		break;
	case 3:
		func(max);
		break;
	}

	return 0;
	//*/

	/*/
	int* pi = NULL;

	pi = (int*)malloc(sizeof(int));

	if (pi == NULL)
		return -1;

	*pi = 10;

	printf("pi : %d\n", *pi);

	pi = (int*)realloc(pi, 10 * sizeof(int));

	printf("pi : %d\n", *pi);

	free(pi);
	pi = NULL;
	//*/

	char temp[80];
	char* str[3];

	for (int i = 0; i < 3; ++i)
	{
		printf("문자열을 입력하세요 : ");
		gets_s(temp, 80);
		str[i] = (char*)malloc(strlen(temp) + 1);
		strcpy(str[i], temp);
	}

	for (int i = 0; i < 3; ++i)
	{
		printf("%s\n", str[i]);
	}

	for (int i = 0; i < 3; ++i)
		free(str[i]);

	return 0;
}

void print_str(char** pps, int cnt)
{
	for (int i = 0; i < cnt; ++i)
	{
		printf("%s\n", pps[i]);
	}
}

void func(int (*fp)(int, int))
{
	int a, b;
	int res;

	printf("두 정수 입력");
	scanf("%d %d", &a, &b);
	res = fp(a, b);
	printf("결과 : %d\n", res);
}

int sum(int a, int b)
{
	return a + b;
}

int mul(int a, int b)
{
	return a * b;
}

int Max(int a, int b)
{
	return a < b ? b : a;
}