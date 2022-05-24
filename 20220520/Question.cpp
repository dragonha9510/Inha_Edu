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

	cout << "피자의 지름 입력 : ";
	cin >> pPizza->iRadius;

	cin.ignore();
	cout << "피자의 회사 명 입력 : ";
	char Name[50];
	cin.getline(Name, 50);
	pPizza->CompanyName = Name;

	cout << "피자의 중량 입력 : ";
	cin >> pPizza->iWeight;

	cout << "이름 : " << pPizza->CompanyName << endl;
	cout << "중량 : " << pPizza->iWeight << endl;
	cout << "지름 : " << pPizza->iRadius << endl;

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

	string output = CheckPalindrome(Input) ? "(은)는 회문입니다." : "은 회문이 아닙니다.";

	cout << Input << output << endl;

	return 0;
}

//*/


// 1 ~ 10까지의 정수를 입력받아 다음과 같은 형태로 출력
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

	cout << " 1 ~ 10 중 정수 입력 : ";
	cin >> iInput;

	system("cls");

	PrintPiramid(iInput);

	return 0;
}


//*/

// p.305 문제 7
/*/

typedef struct Car
{
	string	strName;
	int		iYear = 0;
}car;

int main()
{
	int iNum = 0;

	cout << "몇 대의 차를 목록으로 관리하시겠습니까? : ";
	cin >> iNum;

	vector<car> vecCar(iNum);

	for (int i = 0; i < iNum; ++i)
	{
		cout << "자동차 #" << i + 1 << " : " << endl;
		cout << "제작업체 : ";
		cin >> vecCar[i].strName;
		cout << "제작년도 : ";
		cin >> vecCar[i].iYear;
	}

	cout << endl;
	cout << "현재 귀하가 보유하고 있는 자동차 목록은 다음과 같습니다." << endl;

	for (int i = 0; i < iNum; ++i)
	{
		cout << vecCar[i].iYear << "년형 " << vecCar[i].strName << endl;
	}
	
	system("pause");
	system("cls");

	int iSel = 0;

	while (iSel != -1)
	{
		int deletecar = 0;
		car Temp;

		cout << "1.차량추가 2.목록보기 3.차량삭제 -1.종료" << endl;
		cin >> iSel;

		switch (iSel)
		{
		case 1:
			cout << "자동차 #" << vecCar.size() + 1 << " : " << endl;
			cout << "제작업체 : ";
			cin >> Temp.strName;
			cout << "제작년도 : ";
			cin >> Temp.iYear;

			vecCar.push_back(Temp);
			break;
		case 2:
			if (vecCar.size() == 0)
			{
				cout << "차량이 없습니다" << endl;
				break;
			}
			for (size_t i = 0; i < vecCar.size(); ++i)
			{
				cout << "#" << i + 1 << " " << vecCar[i].iYear << "년형 " << vecCar[i].strName << endl;
			}
			break;
		case 3:
			if (vecCar.size() == 0)
			{
				cout << "차량이 없습니다" << endl;
				break;
			}

			cout << "원하는 차량번호 입력 : ";
			cin >> deletecar;

			vecCar.erase(vecCar.begin() + deletecar - 1);
			cout << "삭제완료" << endl;
			break;
		case -1:
			return 0;
		default:
			cout << "잘못된 입력! 다시 입력바랍니다." << endl;
			break;
		}

		system("pause");
		system("cls");
	}

	return 0;
}

//*/

// p.305 문제 8
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

	cout << "총 " << iWordCnt << " 단어가 입력되었습니다.";

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

// 10 진수를 2 ~ 36진수로 변환
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

	cout << "변환하고싶은 10진수 입력 : ";
	cin >> iDecimal;

	cout << "변환하려는 진수 입력 : ";
	cin >> iNotation;

	cout << endl;

	cout << ChangeNotation(iDecimal, iNotation);

	return 0;
}
//*/

// 서로다른 진수를 변환

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

	cout << "현재 진수 : ";
	cin >> iFromNotation;

	cout << "변환할 값 : ";
	cin >> strNum;

	cout << "변환 진수 : ";
	cin >> iToNotation;

	cout << "변환된 값 : " << ChangeNotation(strNum, iFromNotation, iToNotation);

	return 0;
}
//*/