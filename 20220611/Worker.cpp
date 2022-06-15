#include "stdafx0614.h"
#include "Worker.h" 

CWorker::~CWorker()
{
}

void CWorker::Set()
{
	cout << "��� �̸��� �Է��Ͻʽÿ� : ";
	getline(cin, fullname);
	cout << "��� ��ȣ�� �Է��Ͻʽÿ� : ";
	cin >> id;
	while (cin.get() != '\n')
		continue;
}

void CWorker::Show() const
{
	cout << "��� �̸� : " << fullname << '\n';
	cout << "��� ��ȣ : " << id << '\n';
}

void CWaiter::Set()
{
	CWorker::Set();
	cout << "������ ����� �Է��Ͻʽÿ� : ";
	cin >> panache;
	while (cin.get() != '\n')
		continue;
}

void CWaiter::Show() const
{
	cout << "���� : ������\n";
	CWorker::Show();
	cout << "������ ��� : " << panache << '\n';
}

const char* CSinger::pv[] = { "other", "alto", "contralto", "soprano", "bass", "baritone", "tenor" };

void CSinger::Set()
{
	CWorker::Set();
	cout << "������ ��Ҹ� ���� ��ȣ�� �Է��Ͻʽÿ�::\n";
	
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
		cout << "0���� ũ�ų� ���� " << Vtypes << "���� ���� ���� �Է��Ͻʽÿ�." << endl;

	while (cin.get() != '\n')
		continue;
}

void CSinger::Show() const
{
	cout << "���� : ����\n";
	CWorker::Show();
	cout << "��Ҹ� ���� : " << pv[voice] << endl;
}
