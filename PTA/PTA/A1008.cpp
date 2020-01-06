#include<iostream>
using namespace std;

int main()
{
	int n, sum = 0, now = 0, last = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> now;
		sum = sum + (now - last >= 0 ? (now - last) * 6 : (last - now) * 4) + 5;
		last = now;
	}
	cout << sum;
}