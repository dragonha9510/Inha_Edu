#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <new>

using namespace std;

/*/
const int BUF = 512;
const int N = 5;
char buffer[BUF];

int main()
{
	double* pd1;
	double* pd2;

	cout << "new와 위치 지정 new의 첫 번째 호출:\n";
	pd1 = new double[N];
	pd2 = new(buffer)double[N];

	for (int i = 0; i < N; ++i)
		pd2[i] = pd1[i] = 1000 + 20.0 * i;

	cout << "메모리 주소 :\n" << pd1 << " : 힙\t" << (void*)buffer << " : 정적" << endl;

	cout << "메모리 내용 :\n";

	for (int i = 0; i < N; ++i)
	{
		cout << i + 1 << "\t" << &pd1[i] << " / " << pd1[i] << "\t";
		cout << i + 1 << "\t" << &pd2[i] << " / " << pd2[i] << endl;
	}

	cout << "\nnew와 위치 지정 new의 두 번째 호출 :\n";

	double* pd3 = nullptr;
	double* pd4 = nullptr;

	pd3 = new double[N];
	pd4 = new(buffer)double[N];

	for (int i = 0; i < N; ++i)
		pd4[i] = pd3[i] = 1000 + 40.0 * i;

	cout << "메모리 내용 : \n";

	for (int i = 0; i < N; ++i)
	{
		cout << i + 1 << "\t" << &pd3[i] << " / " << pd3[i] << "\t";
		cout << i + 1 << "\t" << &pd4[i] << " / " << pd4[i] << endl;
	}

	cout << "\nnew와 위치 지정 new의 세 번째 호출\n";
	delete[] pd1;
	pd1 = nullptr;

	pd1 = new double[N];
	pd2 = new(buffer + N * sizeof(double))double[N];

	for (int i = 0; i < N; ++i)
		pd2[i] = pd1[i] = 1000 + 60.0 * i;

	cout << "메모리 내용 : \n";

	for (int i = 0; i < N; ++i)
	{
		cout << i + 1 << "\t" << &pd1[i] << " / " << pd1[i] << "\t";
		cout << i + 1 << "\t" << &pd2[i] << " / " << pd2[i] << endl;
	}

	delete[] pd1;
	delete[] pd3;

	system("pause");

	return 0;
}
//*/

int int_cmp(const int* a, const int* b)
{
	if (*a < *b)
		return -1;
	else if (*a > *b)
		return 1;
	else
		return 0;
}

int main()
{
	int nx, ky;
	int* x;
	int* p;

	puts("bsearch 함수를 이용하여 검색");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	printf("오름 차순으로 입력하시오. \n");
	printf("x[0] : ");
	scanf("%d", &x[0]);

	for (int i = 1; i < nx; ++i)
	{
		do
		{
			printf("x[%d] : ", i);
			scanf("%d", &x[i]);
		} while (x[i] < x[i - 1]);
	}

	printf("검색값 : ");
	scanf("%d", &ky);

	p = (int*)bsearch(&ky, x, nx, sizeof(int), (int(*)(const void*, const void*))int_cmp);

	if (p == NULL)
		puts("검색 실패");
	else
		printf("%d은(는) x[%d]에 있습니다.\n", ky, (int)(p - x));

	free(x);
	
	return 0;
}