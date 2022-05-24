#include <iostream>
#include <cctype>
#include <fstream>

using namespace std;

int main()
{
	/*/
	cout << "�м��� �ؽ�Ʈ�� �Է��Ͻÿ�, ";
	cout << "�Է��� ���� @�� ǥ�� �Ͻʽÿ�.\n";

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

	cout << "���ĺ� : " << chars << endl;
	cout << "��  �� : " << whitespace << endl;
	cout << "��  �� : " << digits << endl;
	cout << "������ : " << punct << endl;
	cout << "��  Ÿ : " << others << endl;
	//*/

	char automobile[50];
	int year;
	double a_price;
	double d_price;

	ofstream outFile;
	outFile.open("carinfo.txt");

	cout << "�ڵ��� ����Ŀ�� ������ �Է��Ͻÿ� : ";
	cin.getline(automobile, 50);
	cout << "������ �Է��Ͻÿ� : ";
	cin >> year;
	cout << "���� ������ �Է��Ͻÿ� : ";
	cin >> a_price;
	d_price = 0.913 * a_price;

	cout << fixed;
	cout.precision(2);
	cout.setf(ios_base::showpoint);
	cout << "����Ŀ�� ���� : " << automobile << endl;
	cout << "���� : " << year << endl;
	cout << "���� ���� $ " << a_price << endl;
	cout << "���� ���� $ " << d_price << endl;

	outFile << fixed;
	outFile.precision(2);
	outFile.setf(ios_base::showpoint);
	outFile << "����Ŀ�� ���� : " << automobile << endl;
	outFile << "���� : " << year << endl;
	outFile << "���� ���� $ " << a_price << endl;
	outFile << "���� ���� $ " << d_price << endl;

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