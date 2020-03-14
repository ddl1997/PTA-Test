#include<iostream>
#include<string>

using namespace std;

int main()
{
	int digit[10];
	fill(digit, digit + 10, 0);
	string number;
	cin >> number;
	for (int i = 0; i < number.length(); i++)
	{
		digit[number[i] - '0']++;
	}
	string doubled = "";
	bool r = false;
	for (int i = number.length() - 1; i >= 0; i--)
	{
		int d = (number[i] - '0') * 2 + (r ? 1 : 0);
		r = d >= 10;
		d = r ? d % 10 : d;
		doubled = (char)(d + '0') + doubled;
		digit[d]--;
	}
	if (r)
	{
		doubled = '1' + doubled;
		digit[1]--;
	}
	for (int i = 0; i < 10; i++)
	{
		if (digit[i] != 0)
		{
			cout << "No" << endl << doubled;
			return 0;
		}
	}
	cout << "Yes" << endl << doubled;
	return 0;
}