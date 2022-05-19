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

	cout << "안녕하세요! 저는 " << chName[1] << "입니다! 실례지만 성함이?\n";
	cin >> chName[0];

	cout << "아, " << chName[0] << "씨! 당신의 이름은 " << strlen(chName[0]) << "자 입니다만 \n";
	cout << sizeof(chName[0]) << "바이트 크기의 배열에 저장되었습니다. \n";
	cout << "이름의 시작이 " << chName[0][0] << "이군요! \n";
	chName[1][3] = '\0';

	cout << "제 이름의 시작 세 글자는 다음과 같습니다 : ";
	cout << chName[1] << endl;
	//*/
	//////////////////////////////////////////////////////////////////////////
	
	/*/
	//char charr1[20];
	//char charr2[20] = "jaguar";

	//string str1;
	//string str2 = "panther";

	//cout << "고양이과의 동물 한 종을 입력하시오 : ";
	//cin.get(charr1, 20);
	//cin.ignore();
	//cout << "고양이과의 또 다른 동물 한 종을 입력하시오 : ";
	//cin.get(charr2, 20);

	//cout << "아래 동물들은 모두 고양이과 입니다 : \n";

	//cout << charr1 << " " << charr2 << " " << str1 << " " << str2 << endl;

	//cout << charr2 << "에서 세 번째 글자 : " << charr2[2] << endl;
	//cout << str2 << "에서 세 번째 글자 : " << str2[2] << endl;
	//*/
	//////////////////////////////////////////////////////////////////////////
	
	/*/
	string s1 = "penguin";
	string s2, s3;

	cout << "string 객체를 string 객체에 대입할 수 있다 : s2 = s1\n";
	s2 = s1;

	cout << "s1 : " << s1 << ", s2 : " << s2 << endl;
	cout << "string 객체에 C 스타일 문자열을 대입할 수 있다. \n";

	cout << "s2 = \"Buzzard\"\n";
	s2 = "Buzzard";

	cout << "s2 : " << s2 << endl;

	cout << "string 객체들을 결합할 수 있다 : s3 = s1 + s2 \n";
	s3 = s1 + s2;

	cout << "s3 : " << s3 << endl;

	cout << "string 객체들을 추가할 수 있다.\n";
	s1 += s2;

	cout << "s1 += s2 --> s1 = " << s1 << endl;

	s2 += " for a day";

	cout << "s2 += \" for a day\" --> s2 = " << s2 << endl;
	//*/
	//////////////////////////////////////////////////////////////////////////
	
	/*/
	char chArr[20];
	string str;

	cout << "입력 이전에 charr에 있는 문자열의 길이 : " << strlen(chArr) << endl;
	cout << "입력 이전에 str에 있는 문자열의 길이   : " << str.size() << endl;

	cout << "텍스트 한 행을 입력하시오 : \n";
	cin.getline(chArr, 20);

	cout << "입력한 텍스트 : " << chArr << endl;
	cout << "또 다른 텍스트 한 행을 입력하시오 : \n";

	getline(cin, str);

	cout << "입력한 텍스트 : " << str << endl;
	cout << "입력 이후에 chArr에 있는 문자열의 길이 : " << strlen
	//*/
	//////////////////////////////////////////////////////////////////////////
	 
	/*/
	//int nights = 1001;
	//int* pt = new int;
	//*pt = 1001;

	//cout << "nights의 값 = ";
	//cout << nights << " : 메모리 위치 " << &nights << endl;
	//cout << "int 형";

	//cout << "값 = " << *pt << " : 메모리 위치 = " << pt << endl;

	//double* pd = new double;
	//*pd = 10000001.0;

	//cout << "double 형";
	//cout << "값 = " << *pd << " : 메모리 위치 = " << pd << endl;
	//cout << "포인터 pd 의 메모리 위치 : " << &pd << endl;
	//cout << "pt의 크기 = " << sizeof(pt) << endl;
	//cout << "*pt의 크기 = " << sizeof(*pt) << endl;
	//cout << "pd의 크기 = " << sizeof(pd) << endl;
	//cout << "*pd의 크기 = " << sizeof(*pd) << endl;

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

	//cout << "동물의 종류 입력 : ";
	//cin >> animal;

	//ps = animal;
	//cout << ps << "s! \n";
	//cout << "strcpy() 사용 전 : \n";
	//cout << (int*)animal << ": " << animal << endl;
	//cout << (int*)ps << ": " << ps << endl;

	//ps = new char[strlen(animal) + 1];
	//strcpy_s(ps, sizeof(animal) + 1, animal);

	//cout << "strcpy() 사용 후 : \n";
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