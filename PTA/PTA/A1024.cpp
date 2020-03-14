#include<iostream>
#include<string>

using namespace std;

void operation(string & number)
{
	string result = "";
	bool r = false;
	int size = number.size();
	for (int i = number.size() - 1; i >= 0; i--)
	{
		int d = (number[i] - '0') + (number[size - i - 1] - '0') + (r ? 1 : 0);
		r = d >= 10;
		d = r ? d % 10 : d;
		result = (char)(d + '0') + result;
	}
	result = r ? '1' + result : result;
	number = result;
}

bool isPalindromic(string number)
{
	int size = number.size();
	for (int i = 0; i < size / 2; i++)
		if (number[i] != number[size - i - 1])
			return false;
	return true;
}

int main()
{
	string number;
	int k;
	cin >> number >> k;
	int times = 0;
	for (; times < k && !isPalindromic(number); times++)
		operation(number);
	cout << number << endl << times;
	return 0;
}