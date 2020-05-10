#include<iostream>
#include<string>

using namespace std;

const int MAXL = 80;
string output[MAXL / 3 + 1];

string getSpaces(int sum)
{
	string result = "";
	for (int i = 0; i < sum; i++)
		result = result + " ";
	return result;
}

int main()
{
	string input;
	cin >> input;
	int n = input.length(), length = n + 2;
	int n1 = length / 3, n2 = length / 3 + length % 3, n3 = length / 3;
	for (int i = 0; i < n1 - 1; i++)
	{
		cout << input[i] + getSpaces(n2 - 2) + input[n - i - 1] << endl;
	}
	cout << input.substr(n1 - 1, n2) << endl;
	return 0;
}