#include <iostream>
#include <string>
#include <cstring>

#include <array>
#include <vector>

#include <vld.h>

using namespace std;

int main()
{
	/*/
	const int iSize = 15;
	char chName[2][iSize];

	strcpy_s(chName[1], "C++owboy");

	cout << "�ȳ��ϼ���! ���� " << chName[1] << "�Դϴ�! �Ƿ����� ������?\n";
	cin >> chName[0];

	cout << "��, " << chName[0] << "��! ����� �̸��� " << strlen(chName[0]) << "�� �Դϴٸ� \n";
	cout << sizeof(chName[0]) << "����Ʈ ũ���� �迭�� ����Ǿ����ϴ�. \n";
	cout << "�̸��� ������ " << chName[0][0] << "�̱���! \n";
	chName[1][3] = '\0';

	cout << "�� �̸��� ���� �� ���ڴ� ������ �����ϴ� : ";
	cout << chName[1] << endl;
	//*/
	//////////////////////////////////////////////////////////////////////////
	
	/*/
	//char charr1[20];
	//char charr2[20] = "jaguar";

	//string str1;
	//string str2 = "panther";

	//cout << "����̰��� ���� �� ���� �Է��Ͻÿ� : ";
	//cin.get(charr1, 20);
	//cin.ignore();
	//cout << "����̰��� �� �ٸ� ���� �� ���� �Է��Ͻÿ� : ";
	//cin.get(charr2, 20);

	//cout << "�Ʒ� �������� ��� ����̰� �Դϴ� : \n";

	//cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;

	//cout << charr2 << "���� �� ��° ���� : " << charr2[2] << endl;
	//cout << str2 << "���� �� ��° ���� : " << str2[2] << endl;
	//*/
	//////////////////////////////////////////////////////////////////////////
	
	/*/
	string s1 = "penguin";
	string s2, s3;

	cout << "string ��ü�� string ��ü�� ������ �� �ִ� : s2 = s1\n";
	s2 = s1;

	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;
	cout << "string ��ü�� C ��Ÿ�� ���ڿ��� ������ �� �ִ�. \n";

	cout << "s2 = \"Buzzard\"\n";
	s2 = "Buzzard";

	cout << "s2 : " << s2 << endl;

	cout << "string ��ü���� ������ �� �ִ� : s3 = s1 + s2 \n";
	s3 = s1 + s2;

	cout << "s3 : " << s3 << endl;

	cout << "string ��ü���� �߰��� �� �ִ�.\n";
	s1 += s2;

	cout << "s1 += s2 --> s1 = " << s1 << endl;

	s2 += " for a day";

	cout << "s2 += \" for a day\" --> s2 = " << s2 << endl;
	//*/
	//////////////////////////////////////////////////////////////////////////
	
	/*/
	char chArr[20];
	string str;

	cout << "�Է� ������ charr�� �ִ� ���ڿ��� ���� : " << strlen(chArr) << endl;
	cout << "�Է� ������ str�� �ִ� ���ڿ��� ����   : " << str.size() << endl;

	cout << "�ؽ�Ʈ �� ���� �Է��Ͻÿ� : \n";
	cin.getline(chArr, 20);

	cout << "�Է��� �ؽ�Ʈ : " << chArr << endl;
	cout << "�� �ٸ� �ؽ�Ʈ �� ���� �Է��Ͻÿ� : \n";

	getline(cin, str);

	cout << "�Է��� �ؽ�Ʈ : " << str << endl;
	cout << "�Է� ���Ŀ� chArr�� �ִ� ���ڿ��� ���� : " << strlen
	//*/
	//////////////////////////////////////////////////////////////////////////
	 
	/*/
	//int nights = 1001;
	//int* pt = new int;
	//*pt = 1001;

	//cout << "nights�� �� = ";
	//cout << nights << " : �޸� ��ġ " << &nights << endl;
	//cout << "int ��";

	//cout << "�� = " << *pt << " : �޸� ��ġ = " << pt << endl;

	//double* pd = new double;
	//*pd = 10000001.0;

	//cout << "double ��";
	//cout << "�� = " << *pd << " : �޸� ��ġ = " << pd << endl;
	//cout << "������ pd �� �޸� ��ġ : " << &pd << endl;
	//cout << "pt�� ũ�� = " << sizeof(pt) << endl;
	//cout << "*pt�� ũ�� = " << sizeof(*pt) << endl;
	//cout << "pd�� ũ�� = " << sizeof(pd) << endl;
	//cout << "*pd�� ũ�� = " << sizeof(*pd) << endl;

	//delete pt;
	//pt = nullptr;

	//delete pd;
	//pd = nullptr;
	//*/
	//////////////////////////////////////////////////////////////////////////
	
	/*/
	//char animal[20] = "bear";
	//const char* bird = "wren";
	//char* ps = nullptr;

	//cout << animal << " and " << bird << "\n";

	//cout << "������ ���� �Է� : ";
	//cin >> animal;

	//ps = animal;
	//cout << ps << "s! \n";
	//cout << "strcpy() ��� �� : \n";
	//cout << (int*)animal << ": " << animal << endl;
	//cout << (int*)ps << ": " << ps << endl;

	//ps = new char[strlen(animal) + 1];
	//strcpy_s(ps, sizeof(animal) + 1, animal);

	//cout << "strcpy() ��� �� : \n";
	//cout << (int*)animal << ": " << animal << endl;
	//cout << (int*)ps << ": " << ps << endl;

	//printf("%s", animal);
	//printf("%p", animal);

	//delete[] ps;
	//ps = nullptr;

	//system("pause");
	//*/
	//////////////////////////////////////////////////////////////////////////
	
	//*/
	double a1[4] = { 1.2, 2.4, 3.6, 4.8 };

	vector<double> a2(4);

	a2[0] = 1.0 / 3.0;
	a2[1] = 1.0 / 5.0;
	a2[2] = 1.0 / 7.0;
	a2[3] = 1.0 / 9.0;

	array<double, 4> a3 = { 3.14,2.72, 1.62,1.41 };
	array<double, 4> a4;

	a4 = a3;
	
	cout << "a1[2] : " << a1[2] << " at " << &a1[2] << endl;
	cout << "a2[2] : " << a2[2] << " at " << &a2[2] << endl;
	cout << "a3[2] : " << a3[2] << " at " << &a3[2] << endl;
	cout << "a4[2] : " << a4[2] << " at " << &a4[2] << endl;

	//*/
	
	return 0;
}