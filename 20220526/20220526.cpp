#include <iostream>
#include <string>

using namespace std;

//*/
int Add_Ten(int& a);
int Add_Ten(int a);
int Add_Ten(int* a);

int main()
{
	int iTest = 0;
	
	cout << "Test      : " << iTest << endl;
	cout << "Test + 10 : " << Add_Ten(iTest) << endl;
	cout << "Test      : " << iTest << endl;

	return 0;
}

int Add_Ten(int& a)
{
	return a += 10;
}

int Add_Ten(int* a)
{
	return *a += 10;
}

int Add_Ten(int a)
{
	return a + 10;
}
//*/

/*/

void swapr(int& a, int& b);
void swapp(int* p, int* q);
void swapv(int a, int b);

int main()
{
	int wallet1 = 3000;
	int wallet2 = 3500;

	cout << "���� 1 = " << wallet1 << "��" << endl;
	cout << "���� 2 = " << wallet2 << "��" << endl;

	cout << "������ �̿��Ͽ� ������� ��ȯ : " << endl;

	swapr(wallet1, wallet2);
	cout << "���� 1 = " << wallet1 << "��" << endl;
	cout << "���� 2 = " << wallet2 << "��" << endl;

	cout << "�����͸� �̿��Ͽ� ������� ��ȯ : " << endl;

	swapp(&wallet1, &wallet2);
	cout << "���� 1 = " << wallet1 << "��" << endl;
	cout << "���� 2 = " << wallet2 << "��" << endl;

	cout << "������ ���� ��ȯ �õ� : " << endl;

	swapv(wallet1, wallet2);
	cout << "���� 1 = " << wallet1 << "��" << endl;
	cout << "���� 2 = " << wallet2 << "��" << endl;
}

void swapr(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

void swapp(int* p, int* q)
{
	int temp;
	temp = *p;
	*p = *q;
	*q = temp;
}
void swapv(int a, int b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}



//*/

/*/

string version1(const string& s1, const string& s2) {
	string temp;
	temp = s2 + s1 + s2;
	return temp;
}

const string& version2(string& s1, const string& s2) {
	s1 = s2 + s1 + s2;
	return s1;
}

const string& version3(string& s1, const string& s2) {
	static string temp;
	temp = s2 + s1 + s2;
	return temp;
}

int main()
{
	string input;
	string copy;
	string result;

	cout << "���ڿ��� �Է��Ͻÿ� : ";
	getline(cin, input);
	copy = input;
	cout << "�Է��� ���ڿ� : " << input << endl;

	result = version1(input, "***");
	cout << "�ٲ� ���ڿ� : " << result << endl;
	cout << "���� ���ڿ� : " << input << endl;
	cout << endl;

	result = version2(input, "###");
	cout << "�ٲ� ���ڿ� : " << result << endl;
	cout << "���� ���ڿ� : " << input << endl;
	cout << endl;

	cout << "���� ���ڿ� �缳��" << endl;
	input = copy;
	result = version3(input, "@@@");
	cout << "�ٲ� ���ڿ� : " << result << endl;
	cout << "���� ���ڿ� : " << input << endl;
	
	return 0;
}

//*/

/*/

template<typename T>
void Swap(T& a, T& b);

struct job
{
	char name[40];
	double salary;
	int floor;
};

template<> void Swap<job>(job& j1, job& j2);
void Show(job& j);

int main()
{
	cout.precision(2);
	cout.setf(ios::fixed, ios::floatfield);

	int i = 10, j = 20;
	cout << "i, j = " << i << ", " << j << ".\n";
	cout << "�����Ϸ��� ������ int�� ��ȯ�⸦ ����ϸ�\n";
	Swap(i, j);
	cout << "���� i, j = " << i << ", " << j << endl;

	job sue = { "Susan Yaffee", 73000.60, 7 };
	job sidney = { "Sidney Taffee", 78060.72, 9 };

	cout << "job ��ȯ �� : " << endl;
	Show(sue);
	Show(sidney);

	Swap(sue, sidney);

	cout << "job ��ȯ �� : " << endl;
	Show(sue);
	Show(sidney);

	return 0;
}

template<typename T>
void Swap(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template<>
void Swap<job>(job& j1, job& j2)
{
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;

	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}

void Show(job& j)
{
	cout << j.name << ": (" << j.floor << "���� ����) "
		<< "$" << j.salary << endl;
}

//*/