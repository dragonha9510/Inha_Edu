#include <iostream>

using namespace std;

//Q1. 키를 정수형 cm 단위로 묻고 그 값을 m, cm 단위로 변환하는 간단한 프로그램
/*/
int main()
{
	int iHeightCM = 0;

	cout << "키를 입력하세요 (cm) : ";
	cin >> iHeightCM;

	cout << iHeightCM / 100 << "m " << iHeightCM % 100 << "cm" << endl;

	return 0;
}
//*/

//Q2. 위도를 도각, 분각, 초각 단위로 요청, 10진수 형식으로 출력하는 프로그램 작성
//	1분각은 60초각 1도각은 60분각
/*/
#define UNIT 60.0f

int main()
{
	float fDegree	= 0.f;
	float fMinutes  = 0.f;
	float fSeconds  = 0.f;
	float fResult	= 0.f;

	cout << "위도를 도, 분, 초 단위로 입력하시오 :\n";
	cout << "먼저, 도각을 입력하시오 : ";
	cin >> fDegree;
	cout << "다음에, 분각을 입력하시오 : ";
	cin >> fMinutes;
	cout << "끝으로, 초각을 입력하시오 : ";
	cin >> fSeconds;

	fResult = fDegree + ((fMinutes / UNIT) + ((fSeconds / UNIT) / UNIT));

	cout << fDegree << "도, " << fMinutes << "분," << fSeconds << "초 = " << fResult << "도";

	return 0;
}
//*/

//Q3. 
/*/
int main()
{
	long long llWorld = 0;
	long long llAmerica = 0;

	cout << "세계 인구수를 입력하시오 : ";
	cin >> llWorld;

	cout << "미국의 인구수를 입력하시오 : ";
	cin >> llAmerica;

	float fPopulation = ((float)llAmerica / (float)llWorld) * 100.f;

	cout << "세계 인구에서 미국이 차지하는 비중은 " << fPopulation << "% 이다." << endl;

	return 0;
}
//*/

//Q4.
/*/
#define EUTOAMERICA(t) 62.14f / (t / 3.875f)

int main()
{
	float fLitter = 0;
	cin >> fLitter;

	cout << (int)(EUTOAMERICA(fLitter));

	return 0;
}

//*/

// Q5.
//*/
int Max4(int a, int b, int c, int d)
{
	int iArr[3] = { b,c,d };
	int iMax = a;

	for (int i = 0; i < 3; ++i)
	{
		if (iMax < iArr[i])
			iMax = iArr[i];
	}

	return iMax;
}

int med3(int a, int b, int c)
{
	int	iRes = a < b ? (c < a ? a : (b < c ? b : c)) : (c < b ? b : (a < c ? a : c));

	return iRes;
}

int main()
{
	int iA, iB, iC;

	cin >> iA >> iB >> iC;

	cout << med3(iA, iB, iC);

	return 0;
}
//*/