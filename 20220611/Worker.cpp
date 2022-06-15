#include "stdafx0614.h"
#include "Worker.h" 

CWorker::~CWorker()
{
}

void CWorker::Set()
{
	cout << "사원 이름을 입력하십시오 : ";
	getline(cin, fullname);
	cout << "사원 번호를 입력하십시오 : ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void CWorker::Show() const
{
	cout << "사원 이름 : " << fullname << '\n';
	cout << "사원 번호 : " << id << '\n';
}

void CWaiter::Set()
{
	CWorker::Set();
	cout << "웨이터 등급을 입력하십시오 : ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void CWaiter::Show() const
{
	cout << "직종 : 웨이터\n";
	CWorker::Show();
	cout << "웨이터 등급 : " << panache << '\n';
}

const char* CSinger::pv[] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

void CSinger::Set()
{
	CWorker::Set();
	cout << "가수의 목소리 유형 번호를 입력하십시오::\n";
	
	int i = 0;
	for (i = 0; i < Vtypes; ++i)
	{
		cout << i << " : " << pv[i] << " ";
		if (i % 4 == 3)
			cout << endl;
	}

	if (i % 4 != 0)
		cout << endl;
	while (cin >> voice && (voice < 0 || voice >= Vtypes))
		cout << "0보다 크거나 같고 " << Vtypes << "보다 작은 값을 입력하십시오." << endl;

	while (cin.get() != '\n')
		continue;
}

void CSinger::Show() const
{
	cout << "직종 : 가수\n";
	CWorker::Show();
	cout << "목소리 유형 : " << pv[voice] << endl;
}
