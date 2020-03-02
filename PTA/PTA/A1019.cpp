#include<iostream>
#include<vector>

using namespace std;

int main()
{
	long n, b;
	cin >> n >> b;
	vector<long> number;
	while (n > 0)
	{
		long a = n % b;
		number.push_back(a);
		n /= b;
	}
	bool isPalindromic = true;
	int size = number.size();
	for (int i = 0; i < size / 2; i++)
	{
		if (number[i] != number[size - 1 - i])
		{
			isPalindromic = false;
			break;
		}
	}
	if (isPalindromic)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	for (int i = size - 1; i > 0; i--)
		cout << number[i] << ' ';
	cout << number[0];
	return 0;
}