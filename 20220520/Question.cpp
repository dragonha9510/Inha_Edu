#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

/*/
typedef struct pizza
{
	string CompanyName;
	int iRadius;
	int iWeight;
}PIZZA;


int main()
{
	PIZZA* pPizza = new PIZZA;

	cout << "������ ���� �Է� : ";
	cin >> pPizza->iRadius;

	cin.ignore();
	cout << "������ ȸ�� �� �Է� : ";
	char Name[50];
	cin.getline(Name, 50);
	pPizza->CompanyName = Name;

	cout << "������ �߷� �Է� : ";
	cin >> pPizza->iWeight;

	cout << "�̸� : " << pPizza->CompanyName << endl;
	cout << "�߷� : " << pPizza->iWeight << endl;
	cout << "���� : " << pPizza->iRadius << endl;

	delete pPizza;
	pPizza = nullptr;

	return 0;
}
//*/

/*/
#define LOWERCASESTART 97
#define UPPERTOLOWER(t) t + 32
#define RETURNLOWERASCII(t) t < LOWERCASESTART ? UPPERTOLOWER(t) : t;

bool CheckPalindrome(string testcase)
{
	size_t iLength = testcase.length();
	size_t iMaxIndex = iLength - 1;
	size_t iMinIndex = 0;

	iLength /= 2;

	for (size_t i = 0; i < iLength; ++i)
	{
		int AsciiFront = RETURNLOWERASCII(testcase[iMinIndex + i]);
		int AsciiBack  = RETURNLOWERASCII(testcase[iMaxIndex - i]);

		if (AsciiFront != AsciiBack)
			return false;
	}

	return true;
}

int main()
{
	string Input;

	cin >> Input;

	string output = CheckPalindrome(Input) ? "(��)�� ȸ���Դϴ�." : "�� ȸ���� �ƴմϴ�.";

	cout << Input << output << endl;

	return 0;
}

//*/


// 1 ~ 10������ ������ �Է¹޾� ������ ���� ���·� ���
//    1
//   212
//  32123
// 4321234
//543212345
/*/

void PrintPiramid(int line)
{
	if (line < 1 || line > 10)
		return;

	int iMax = (line * 2) - 1;

	int iFrontIndex = line;
	int iBackIndex = iMax - line;

	for (int i = 0; i < line; ++i)
	{
		--iFrontIndex;
		++iBackIndex;

		for (int j = 0; j < iMax; ++j)
		{
			if (iFrontIndex <= j && iBackIndex > j)
			{
				if (line - j < 1)
					cout << j - line + 2;
				else
					cout << line - j;
			}
			else
				cout << " ";
		}

		if(i != line - 1)
			cout << endl;
	}
}

int main()
{
	int iInput = 0;

	cout << " 1 ~ 10 �� ���� �Է� : ";
	cin >> iInput;

	system("cls");

	PrintPiramid(iInput);

	return 0;
}


//*/

// p.305 ���� 7
/*/

typedef struct Car
{
	string	strName;
	int		iYear = 0;
}car;

int main()
{
	int iNum = 0;

	cout << "�� ���� ���� ������� �����Ͻðڽ��ϱ�? : ";
	cin >> iNum;

	vector<car> vecCar(iNum);

	for (int i = 0; i < iNum; ++i)
	{
		cout << "�ڵ��� #" << i + 1 << " : " << endl;
		cout << "���۾�ü : ";
		cin >> vecCar[i].strName;
		cout << "���۳⵵ : ";
		cin >> vecCar[i].iYear;
	}

	cout << endl;
	cout << "���� ���ϰ� �����ϰ� �ִ� �ڵ��� ����� ������ �����ϴ�." << endl;

	for (int i = 0; i < iNum; ++i)
	{
		cout << vecCar[i].iYear << "���� " << vecCar[i].strName << endl;
	}
	
	system("pause");
	system("cls");

	int iSel = 0;

	while (iSel != -1)
	{
		int deletecar = 0;
		car Temp;

		cout << "1.�����߰� 2.��Ϻ��� 3.�������� -1.����" << endl;
		cin >> iSel;

		switch (iSel)
		{
		case 1:
			cout << "�ڵ��� #" << vecCar.size() + 1 << " : " << endl;
			cout << "���۾�ü : ";
			cin >> Temp.strName;
			cout << "���۳⵵ : ";
			cin >> Temp.iYear;

			vecCar.push_back(Temp);
			break;
		case 2:
			if (vecCar.size() == 0)
			{
				cout << "������ �����ϴ�" << endl;
				break;
			}
			for (size_t i = 0; i < vecCar.size(); ++i)
			{
				cout << "#" << i + 1 << " " << vecCar[i].iYear << "���� " << vecCar[i].strName << endl;
			}
			break;
		case 3:
			if (vecCar.size() == 0)
			{
				cout << "������ �����ϴ�" << endl;
				break;
			}

			cout << "���ϴ� ������ȣ �Է� : ";
			cin >> deletecar;

			vecCar.erase(vecCar.begin() + deletecar - 1);
			cout << "�����Ϸ�" << endl;
			break;
		case -1:
			return 0;
		default:
			cout << "�߸��� �Է�! �ٽ� �Է¹ٶ��ϴ�." << endl;
			break;
		}

		system("pause");
		system("cls");
	}

	return 0;
}

//*/

// p.305 ���� 8
/*/

int main()
{
	char chWord[25];
	int iWordCnt = 0;
	
	while (1)
	{
		cin >> chWord;

		if (!strcmp(chWord, "done"))
			break;

		++iWordCnt;
	}

	cout << "�� " << iWordCnt << " �ܾ �ԷµǾ����ϴ�.";

	return 0;
}

//*/

// vector
//*/
int main()
{
	vector<int> vecInt;

	vecInt.reserve(5);
	for(int i = 0; i < 15; ++i)
		vecInt.push_back(i + 1);

	cout << endl;

	for (size_t i = 0; i < vecInt.size(); ++i)
	{
		cout << vecInt[i];
	}
	cout << endl;

	cout << vecInt.size() << endl;		// 7    6	 5
	cout << vecInt.capacity() << endl;	// 10   10   10

	vecInt.clear();
	vecInt.shrink_to_fit();

	return 0;
}
//*/

// 10 ������ 2 ~ 36������ ��ȯ
/*/
string ChangeNotation(int sour, int notation)
{
	string strRes;
	int iNum = sour;
	
	while (iNum >= notation)
	{
		strRes += (iNum % notation) > 9 ? (iNum % notation) - 10 + 'A' : (iNum % notation) + '0';
		iNum /= notation;
	}

	strRes += (iNum % notation) > 9 ? (iNum % notation) - 10 + 'A' : (iNum % notation) + '0';

	for (size_t i = 0; i < strRes.length() / 2; ++i)
	{
		char temp = strRes[i];
		strRes[i] = strRes[strRes.length() - 1 - i];
		strRes[strRes.length() - 1 - i] = temp;
	}

	return strRes;
}

int main()
{
	int iDecimal = 0;
	int iNotation = 0;

	cout << "��ȯ�ϰ���� 10���� �Է� : ";
	cin >> iDecimal;

	cout << "��ȯ�Ϸ��� ���� �Է� : ";
	cin >> iNotation;

	cout << endl;

	cout << ChangeNotation(iDecimal, iNotation);

	return 0;
}
//*/

// ���δٸ� ������ ��ȯ

/*/
string ChangeDecimalNotation(int sour, int notation)
{
	string strRes;
	int iNum = sour;

	while (iNum > 0)
	{
		strRes += (iNum % notation) > 9 ? (iNum % notation) - 10 + 'A' : (iNum % notation) + '0';
		iNum /= notation;
	}

	for (size_t i = 0; i < strRes.length() / 2; ++i)
	{
		char temp = strRes[i];
		strRes[i] = strRes[strRes.length() - 1 - i];
		strRes[strRes.length() - 1 - i] = temp;
	}

	return strRes;
}

string ChangeNotation(string sour, int sournotation = 10, int destnotation = 2)
{
	string strRes;
	string strSour = sour;
	size_t iLength = strSour.length();

	int iPow = 0;
	int iSourNum = 0;

	for (size_t i = iLength; i > 0 ; --i)
	{
		iPow = sournotation;

		for (size_t j = 1; j < iLength - i; ++j)
			iPow *= sournotation;

		iSourNum += (strSour[i - 1] >= 'A' ? 
			(strSour[i - 1] - 'A' + 10) : (strSour[i - 1] - '0')) * (i == iLength ? 1 : iPow);
	}

	strRes = ChangeDecimalNotation(iSourNum, destnotation);

	return strRes;
}

int main()
{
	string strNum;
	int iFromNotation = 0;
	int iToNotation = 0;

	cout << "���� ���� : ";
	cin >> iFromNotation;

	cout << "��ȯ�� �� : ";
	cin >> strNum;

	cout << "��ȯ ���� : ";
	cin >> iToNotation;

	cout << "��ȯ�� �� : " << ChangeNotation(strNum, iFromNotation, iToNotation);

	return 0;
}
//*/