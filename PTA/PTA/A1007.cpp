#include<iostream>

using namespace std;

const int K = 10000;
int numbers[K];

int main()
{
	int k;
	cin >> k;
	bool allNegative = true;
	for (int i = 0; i < k; i++)
	{
		cin >> numbers[i];
		if (numbers[i] >= 0)
			allNegative = false;
	}
	if (allNegative)
	{
		cout << 0 << " " << numbers[0] << " " << numbers[k - 1];
		return 0;
	}
	int max = numbers[0], startI = 0, endI = 0;
	for (int i = 0; i < k; i++)
	{
		int sum = 0;
		for (int j = i; j < k; j++)
		{
			sum += numbers[j];
			if (sum > max)
			{
				max = sum;
				startI = i;
				endI = j;
			}
		}
	}
	cout << max << " " << numbers[startI] << " " << numbers[endI];
	//cin >> k;
	return 0;
}
//直接求解
//更高效：https://www.cnblogs.com/Jawen/p/11320338.html