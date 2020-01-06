#include<iostream>
#include<iomanip>//用于保留位数

using namespace std;

const int K = 10;
const int N = 1001;
int firstE[K];
float firstC[K];
int secondE[K];
float secondC[K];
float result[2 * N];

int main()
{
	int k1, k2;
	for (int i = 0; i < 2 * N; i++)
		result[i] = 0;
	cin >> k1;
	for (int i = 0; i < k1; i++)
		cin >> firstE[i] >> firstC[i];
	cin >> k2;
	for (int i = 0; i < k2; i++)
		cin >> secondE[i] >> secondC[i];

	for (int i = 0; i < k1; i++)
		for (int j = 0; j < k2; j++)
			result[firstE[i] + secondE[j]] += firstC[i] * secondC[j];
	int resultSum = 0;
	for (int i = 0; i < 2 * N; i++)
		if (result[i] != 0)
			resultSum++;
	cout << resultSum;
	for (int i = 2 * N - 1; i >= 0; i--)
		if (result[i] != 0)
			cout << " " << i << " " << setiosflags(ios::fixed) << setprecision(1) << result[i];//setprecision(n)与setiosflags(ios::fixed)合用，控制小数点右边的数字个数
	//cin >> k1;
	return 0;
}