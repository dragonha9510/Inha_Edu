#include "stdafx.h"
// ((4*2+12)*(123+7))					2600
// ((-2*(-1-1))-3.9)+(6/((3+3)/6.0))	6.1
// ((4/3*6))							8
// ((15-2*3*4+5))						-4

int main()
{
	string strInput;

	cin >> strInput;

	strInput = "(" + strInput + ")";

	CMyQueue queCal;
	CStack stkCal;
	CStack stkRes;

	queCal.Initialize(strInput.length());
	stkCal.Initialize(strInput.length());
	stkRes.Initialize(strInput.length());

	bool bOper = false;
	string strTemp;

	for (size_t i = 0; i < strInput.length(); ++i)
	{
		if (strInput[i] == ' ')
			continue;
		else if ((strInput[i] >= '0' && strInput[i] <= '9') || strInput[i] == '.')
		{
			strTemp.push_back(strInput[i]);
			bOper = true;
		}
		else
		{
			if (!bOper && strInput[i] == '-')
			{
				strTemp.push_back(strInput[i]);
				continue;
			}

			if (strTemp.size())
			{
				queCal.Enque(strTemp);
				strTemp.clear();
			}

			stkCal.Peek(&strTemp);
			if (stkCal.Size())
			{
				char temp = strInput[i];

				if (((strTemp[0] == '/' || strTemp[0] == '*') && (temp == '+' || temp == '-')))
				{
					stkCal.Pop(&strTemp);
					queCal.Enque(strTemp);
					stkCal.Peek(&strTemp);
				}

				if(((strTemp[0] == '+' || strTemp[0] == '-') && (temp == '+' || temp == '-'))
					|| (((strTemp[0] == '/' || strTemp[0] == '*') && (temp == '*' || temp == '/'))))
				{
					stkCal.Pop(&strTemp);
					queCal.Enque(strTemp);
				}
			}
			strTemp = strInput[i];
			stkCal.Push(strTemp);

			stkCal.Peek(&strTemp);
			if (strTemp[0] == ')')
			{			
				bOper = true;

				stkCal.Pop(&strTemp);
				while (true)
				{
					stkCal.Pop(&strTemp);

					if (strTemp[0] == '(')
						break;

					queCal.Enque(strTemp);
				}
			}
			else
				bOper = false;

			strTemp.clear();
		}

		stkCal.Print();
		queCal.Print();
	}

	while (stkCal.Size())
	{
		stkCal.Pop(&strTemp);
		if (strTemp[0] != '\0')
			queCal.Enque(strTemp);
	}

	string res;
	string num1, num2;
	double dRes = 0;

	while (queCal.size())
	{
		queCal.Deque(&res);

		if (res.size() != 1)
			stkRes.Push(res);
		else
		{
			switch (res[0])
			{
			case '+':
				stkRes.Pop(&num1);
				stkRes.Pop(&num2);

				dRes = stod(num2) + stod(num1);
				res = to_string(dRes);

				stkRes.Push(res);
				break;
			case '-':
				stkRes.Pop(&num1);
				stkRes.Pop(&num2);

				dRes = stod(num2) - stod(num1);
				res = to_string(dRes);

				stkRes.Push(res);
				break;
			case '*':
				stkRes.Pop(&num1);
				stkRes.Pop(&num2);

				dRes = stod(num2) * stod(num1);
				res = to_string(dRes);

				stkRes.Push(res);
				break;
			case '/':
				stkRes.Pop(&num1);
				stkRes.Pop(&num2);

				dRes = stod(num2) / stod(num1);
				res = to_string(dRes);

				stkRes.Push(res);
				break;
			default:
				stkRes.Push(res);
				break;
			}
		}
	}

	string strRes;
	stkRes.Pop(&strRes);
	dRes = stod(strRes);

	cout << dRes << endl;

	return 0;
}