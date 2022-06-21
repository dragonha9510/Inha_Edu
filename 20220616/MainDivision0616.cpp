#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
#include "MainDivision0616.h"
#include "Report.h"
#include "StopWatch.h"

using namespace std;

void S(int k,int m,int c){for(int j=0;j<m;++j)cout<<((j==(m-1)||j==k)?"*":((j>k&&(j<(m-1)))?"+":" "));cout<<endl;if(++c!=m)S(k+((c>(m/2))?1:-1),m,c);return;}

void Class0616Main1()
{
	{
		auto_ptr<CReport> ps(new CReport("auto_ptr"));
		ps->comment();
	}
	{
		shared_ptr<CReport> ps(new CReport("shared_ptr"));
		ps->comment();
		weak_ptr<CReport> pw(ps);
	}
	{
		unique_ptr<CReport> ps(new CReport("unique_ptr"));
		ps->comment();
	}
}

struct Review 
{
	string title;
	int rating;
};

bool FillReview(Review& rr);
void ShowReview(const Review& rr);

void Class0616Main2()
{
	vector<Review> books;
	Review temp;
	while (FillReview(temp))
		books.push_back(temp);

	int num = books.size();
	if (num > 0)
	{
		cout << "압도적 감사! 당신은 다음과 같이 입력!" << endl
			<< "등급\t제목\n";
		for (int i = 0; i < num; ++i)
			ShowReview(books[i]);
		cout << "한번 더 출력! : \n"
			<< "등급\t제목\n";
		vector<Review>::iterator pr;
		for (pr = books.begin(); pr != books.end(); ++pr)
			ShowReview(*pr);
		vector<Review> oldlist(books);
		if (num > 3)
		{
			//원소 2개 삭제
			books.erase(books.begin() + 1, books.begin() + 3);
			cout << "삭제 후! : " << endl;
			for (pr = books.begin(); pr != books.end(); ++pr)
				ShowReview(*pr);
			//원소 1개 삽입
			books.insert(books.begin(), oldlist.begin() + 1, oldlist.begin() + 2);
			cout << "삽입 후! : " << endl;
			for (pr = books.begin(); pr != books.end(); ++pr)
				ShowReview(*pr);
		}
		books.swap(oldlist);
		cout << "oldlist와 books를 교체 후! : \n";
		for (pr = books.begin(); pr != books.end(); ++pr)
			ShowReview(*pr);
	}
	else
		cout << "입력한 것이 없어, 얻은 것이 없다!" << endl;
}

void Class0616Main3()
{
	int casts[10] = { 6,7,2,9,4,11,8,7,10,5 };
	vector<int> dice(10);

	copy(casts, casts + 10, dice.begin());

	cout << "주사위 휘리릭" << endl;
	ostream_iterator<int, char> out_iter(cout, " ");
	copy(dice.begin(), dice.end(), out_iter);
	cout << endl;
	cout << "역방향 이터 사용 : " << endl;
	copy(dice.rbegin(), dice.rend(), out_iter);
	cout << endl;
	cout << "역방향 이터 명시적 사용 : " << endl;
	vector<int>::reverse_iterator ri;
	for (ri = dice.rbegin(); ri != dice.rend(); ++ri)
		cout << *ri << ' ';
	cout << endl;
}

void output(const string& s) { cout << s << " "; }

void Class0616Main4()
{
	string s1[4] = { "fine", "fish", "fashion", "fate" };
	string s2[2] = { "busy", "bats" };
	string s3[2] = { "silly", "singers" };

	vector<string> words(4);
	copy(s1, s1 + 4, words.begin());
	for_each(words.begin(), words.end(), output);
	cout << endl;

	copy(s2, s2 + 2, back_insert_iterator<vector<string>>(words));
	for_each(words.begin(), words.end(), output);
	cout << endl;

	copy(s3, s3 + 2, insert_iterator<vector<string>>(words, words.begin()));
	for_each(words.begin(), words.end(), output);
	cout << endl;
}

bool PrintBubbleSort(int arr[], int size, int position, bool bswap)
{
	for (int i = 0; i < size; ++i)
	{
		if (i == position)
			cout << arr[i] << (bswap ? " + " : " - ");
		else
			cout << arr[i] << "   ";
	}

	cout << '\n';

	return bswap;
}

void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1;)
	{
		int last = size - 1;
		for (int j = size - 1; j > i; --j)
		{
			//if (PrintBubbleSort(arr, size, j - 1, arr[j - 1] > arr[j]))
			if (arr[j - 1] > arr[j])
			{
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;

				last = j;
			}
		}

		i = last;
	}
}

bool PrintSelectSort(int arr[], int n, int a, int b, bool r)
{
	if (r)
	{
		for (int i = 0; i < n; ++i)
		{
			cout << arr[i] << "\t";
		}
		cout << endl;

		for (int i = 0; i < n; ++i)
		{
			if (i == a)
				cout << "*";
			else if (i == b)
				cout << "+";

			cout << "\t";
		}
		cout << endl;
	}
	return r;
}

void SelectSort(int arr[], int n)
{
	for (int j = 0; j < n; ++j)
	{
		int sel = j;

		for (int i = j + 1; i < n; ++i)
		{
			if (arr[i] < arr[sel])
			{
				sel = i;
			}
		}
		//if (PrintSelectSort(arr, n, j, sel, (sel != j)))
		if (sel != j)
		{
			int iTemp = arr[j];
			arr[j] = arr[sel];
			arr[sel] = iTemp;
		}
	}
}

#define SORTTESTCASE 700000
void SelectSortMain()
{
	srand((unsigned int)time(NULL));
	CStopWatch timer;

	int* iArr = new int[SORTTESTCASE];
	int* iArr2 = new int[SORTTESTCASE];
	int* iArr3 = new int[SORTTESTCASE];

	for (int i = 0; i < SORTTESTCASE; ++i)
		iArr3[i] = iArr2[i] = iArr[i] = (rand() % SORTTESTCASE) + 1;

	//timer.Start();
	//SelectSort(iArr, SORTTESTCASE);
	//timer.Stop();

	//cout << endl;
	//cout << "선택 정렬 걸린 시간 : " << timer.getElapsedTime() << endl;

	//

	timer.Start();
	ShellSortInsert2(iArr2, SORTTESTCASE);
	timer.Stop();

	cout << endl;
	cout << "셸 정렬 (4중) 걸린 시간 : " << timer.getElapsedTime() << endl;

	//

	timer.Start();
	ShellSortInsert(iArr3, SORTTESTCASE);
	timer.Stop();

	cout << endl;
	cout << "셸 정렬 (3중) 걸린 시간 : " << timer.getElapsedTime() << endl;

	delete[] iArr;
	iArr = nullptr;
	delete[] iArr2;
	iArr2 = nullptr;
	delete[] iArr3;
	iArr3 = nullptr;
}

#define SWAP(a, b) {int swaptemp = a; a = b; b = swaptemp;}
void ShellSortBubble(int arr[], int n)
{
	int shell = n + (n % 2);

	while (shell /= 2)
	{
		for (int i = 0; i < shell; ++i)
		{
			for (int j = shell + i; j < n; j += shell)
			{
				if (arr[j - shell] > arr[j])
				{
					SWAP(arr[j - shell], arr[j]);
					j = shell + i;
				}
			}
		}
	}
}

void ShellSortInsert(int arr[], int n)
{
	int shell = n + (n % 2);

	while (shell /= 2)
	{
		for (int i = shell, j = 0; i < n; ++i)
		{
			int temp = arr[i];

			for (j = i - shell; j >= 0 && arr[j] > temp; j -= shell)
				arr[j + shell] = arr[j];

			arr[j + shell] = temp;
		}
	}
}

void ShellSortInsert2(int arr[], int n)
{
	int	shell = n;

	while (shell /= 2)
	{
		if ((shell % 2) == 0)
			++shell;

		for (int i = 0; i < shell; ++i)
		{
			int key;
			for (int j = i + shell, k = 0; j <= n - 1; j = j + shell)
			{
				key = arr[j];

				for (k = j - shell; k >= i && arr[k] > key; k = k - shell)
				{
					arr[k + shell] = arr[k];
				}

				arr[k + shell] = key;
			}
		}
	}
}

void recursion3n1(unsigned long long k)
{
	if (k == 1)
	{
		cout << k << ' ';
		return;
	}

	cout << k << ' ';
	recursion3n1((k % 2) ? ((3 * k) + 1) : (k / 2));
}

bool FillReview(Review& rr)
{
	cout << "책 제목 입력! (끝내려면 quit 입력) : ";
	getline(cin, rr.title);
	if (rr.title == "quit")
		return false;

	cout << "책 등급 ( 0 ~ 10 ) 을 입력! : ";
	cin >> rr.rating;

	if (!cin)
		return false;

	while (cin.get() != '\n')
		continue;

	return true;
}

void ShowReview(const Review& rr)
{
	cout << rr.rating << '\t' << rr.title << endl;
}