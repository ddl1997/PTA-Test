#include<iostream>
#include<string>
#include<math.h>

using namespace std;

const int N = 11;
int sum[N];

int count_one(int n)
{
	if (n == 0) return 0;
	int exp = to_string(n).length() - 1;
	if (exp == 0) return 1;
	int exponent = pow(10, exp), num = n / exponent, count = sum[exp];
	for (int i = 1; i <= num; i++)
	{
		if (i == num)
		{
			if (i == 1)
			{
				count += n % exponent + 1;
			}
			count += count_one(n % exponent);
		}
		else
		{
			if (i == 1)
				count += pow(10, exp);
			count += sum[exp];
		}
	}
	return count;
}

int main()
{
	sum[0] = 0;
	for (int i = 1; i < N; i++)
		sum[i] = 10 * sum[i - 1] + pow(10, i - 1);
	int n;
	cin >> n;
	cout << count_one(n) << endl;
	return 0;
}

// 思路：将数字拆成几部分求解。比如n=211，就将211拆成1-99、100-199和200-211。先初始化一个1-9、1-99、1-999……的“1”个数的数组。