#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

int main()
{
	/*/
	cout << "분석할 텍스트를 입력하시오, ";
	cout << "입력의 끝을 @로 표시 하십시오.\n";

	char ch;

	int whitespace = 0;
	int digits = 0;
	int chars = 0;
	int punct = 0;
	int others = 0;

	cin.get(ch);
	while (ch != '@')
	{
		if (isalpha(ch))
			++chars;
		else if (isspace(ch))
			++whitespace;
		else if (isdigit(ch))
			++digits;
		else if (ispunct(ch))
			++punct;
		else
			++others;
		cin.get(ch);
	}

	cout << "알파벳 : " << chars << endl;
	cout << "공  백 : " << whitespace << endl;
	cout << "숫  자 : " << digits << endl;
	cout << "구두점 : " << punct << endl;
	cout << "기  타 : " << others << endl;
	//*/

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "자동차 메이커와 차종을 입력하시오 : ";
	cin.getline(automobile, 50);
	cout << "연식을 입력하시오 : ";
	cin >> year;
	cout << "구입 가격을 입력하시오 : ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "메이커와 차종 : " << automobile << endl;
	cout << "연식 : " << year << endl;
	cout << "구입 가격 $ " << a_price << endl;
	cout << "현재 가격 $ " << d_price << endl;

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "메이커와 차종 : " << automobile << endl;
	outFile << "연식 : " << year << endl;
	outFile << "구입 가격 $ " << a_price << endl;
	outFile << "현재 가격 $ " << d_price << endl;

	outFile.close();

	ifstream inFile;
	inFile.open("carinfo.txt");

	if (!inFile.is_open())
		exit(EXIT_FAILURE);

	string Test;

	while (inFile.good())
	{
		inFile.getline(automobile, 50);
		cout << automobile << endl;
	}	

	inFile.close();

	return 0;
}