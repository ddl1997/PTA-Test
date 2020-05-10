#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100000;

int nc, np;
int coupons[N];
int products[N];

bool cmp(int a, int b)
{
	return a > b;
}
int main()
{
	cin >> nc;
	for (int i = 0; i < nc; i++)
	{
		scanf("%d", &coupons[i]);
	}
	sort(coupons, coupons + nc, cmp);
	cin >> np;
	for (int i = 0; i < np; i++)
	{
		scanf("%d", &products[i]);
	}
	sort(products, products + np, cmp);
	long long int sum = 0;
	for (int i = 0; i < nc && i < np; i++)
	{
		if (coupons[i] > 0 && products[i] > 0)
			sum += (long long int)coupons[i] * (long long int)products[i];
		else
			break;
	}
	for (int i = 0; nc - i - 1 >= 0 && np - i - 1 >= 0; i++)
	{
		if (coupons[nc - i - 1] < 0 && products[np - i - 1] < 0)
			sum += (long long int)coupons[nc - i - 1] * (long long int)products[np - i - 1];
		else
			break;
	}
	cout << sum;
	return 0;
}

// 排序不等式 正序>乱序>逆序