#include<iostream>
#include<set>

using namespace std;

const int M = 200;

int n, m, l;
int favorites[M], longgest[M];
set<int> fset;

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		scanf("%d", &favorites[i]);
		longgest[i] = 0;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int color, max = 0;
		scanf("%d", &color);
		for (int j = 0; j < m; j++)
		{
			if (longgest[j] > max)
			{
				max = longgest[j];
			}
			if (favorites[j] == color)
			{
				longgest[j] = max + 1;
			}
		}
	}
	int max = 0;
	for (int i = 0; i < m; i++)
	{
		if (longgest[i] > max)
			max = longgest[i];
	}
	cout << max << endl;
	return 0;
}