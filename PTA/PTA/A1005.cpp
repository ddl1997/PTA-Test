#include<iostream>
#include<string>

using namespace std;

string numbers[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

int main()
{
	int sum = 0;
	string number;
	cin >> number;
	int length = number.length();
	for (int i = 0; i < length; i++)
	{
		sum += ((char)number[i] - '0');
	}
	int stack[101];
	int top = 0;
	do {
		stack[top] = sum % 10;
		top++;
		sum /= 10;
	} while (sum != 0);
	for (top--; top >= 0; top--)
		cout << numbers[stack[top]] << (top == 0 ? "" : " ");
	//cin >> number;
	return 0;
}