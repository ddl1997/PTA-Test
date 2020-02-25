#include<iostream>
#include<string>
//#include<stdlib.h> qsort()

using namespace std;

const int N = 10001, K = 100;

struct Customer {
	int arrT, proT; // in seconds
};
Customer *cus[N];
int windows[K];
int pos = 0, cusCount = 0;

int findMinW(int k)
{
	int index = 0, min = windows[0];
	for (int i = 0; i < k; i++)
	{
		if (windows[i] < min)
		{
			index = i;
			min = windows[i];
		}
	}
	return index;
}

void sort(int n)
{
	for (int i = 0; i < n; i++)
	{
		int minI = i;
		for (int j = i; j < n; j++)
		{
			if (cus[j]->arrT < cus[minI]->arrT)
				minI = j;
		}
		Customer *temp = cus[i];
		cus[i] = cus[minI];
		cus[minI] = temp;
	}
}

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string arrive;
		int proT;
		cin >> arrive >> proT;
		int arrT = stoi(arrive.substr(0, 2)) * 60 * 60 + stoi(arrive.substr(3, 2)) * 60 + stoi(arrive.substr(6, 2));
		if (arrT <= 17 * 60 * 60)
		{
			cus[pos] = new Customer();
			cus[pos]->arrT = arrT;
			cus[pos]->proT = (proT > 60 ? 60 : proT) * 60;
			pos++;
			cusCount++;
		}
	}
	double wait = 0;
	for (int i = 0; i < k; i++)
		windows[i] = 8 * 60 * 60;
	if (cusCount == 0)
	{
		printf("0.0");
		return 0;
	}
	sort(cusCount); //stdlib.h qsort()
	for (int i = 0; i < cusCount; i++)
	{
		Customer * c = cus[i];
		int w = findMinW(k);
		int waitTime = windows[w] - c->arrT;
		if (waitTime >= 0) //这里注意窗口的时间要分情况讨论
		{
			wait += waitTime;
			windows[w] += c->proT;
		}
		else
		{
			windows[w] = c->arrT + c->proT;
		}
	}

	double avg = wait / (cusCount * 60.0);
	printf("%.1f", avg);
	return 0;
}
// 处理时间超过1个小时按照1个小时计算，超出的不处理