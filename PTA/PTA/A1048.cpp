#include<iostream>

using namespace std;

const int MAX = 501;

int coins[MAX];

int main()
{
	for (int i = 0; i < MAX; i++)
		coins[i] = 0;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		int coin;
		scanf("%d", &coin);
		coins[coin]++;
	}
	bool found = false;
	for (int i = 1; i <= m / 2; i++)
	{
		if (coins[i] > 0)
		{
			int lack = m - i;
			if (lack >= MAX) continue;
			if ((lack == i && coins[i] >= 2) || (lack > i && coins[lack] > 0))
			{
				printf("%d %d\n", i, lack);
				found = true;
				break;
			}
		}
	}
	if (!found)
		cout << "No Solution" << endl;
	return 0;
}