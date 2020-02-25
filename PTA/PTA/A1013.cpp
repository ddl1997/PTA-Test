#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;

const int N = 1001;

int highways[N][N];
//int root[N];

int findRoot(int root[], int index)
{
	while (root[index] != -1)
		index = root[index];
	return index;
}

int findWays(int lost, int n)
{
	int root[N];
	for (int i = 1; i <= n; i++)
		root[i] = -1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			if (i != lost && j != lost && highways[i][j] == 1)
			{
				int iRoot = findRoot(root, i);
				int jRoot = findRoot(root, j);
				if (iRoot != jRoot)
					root[jRoot] = iRoot;
			}
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i++)
		if (i != lost && root[i] == -1) count++;
	return count - 1;
}

int main()
{
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			highways[i][j] = 0;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		scanf("%d", &from);//cin/cout在数据量很大的条件下，效率远低于scanf/printf。
		scanf("%d", &to);
		//cin >> from >> to;
		highways[from][to] = 1;
		highways[to][from] = 1;
	}
	int losts[N];
	for (int i = 0; i < k; i++)
		cin >> losts[i];
	for (int i = 0; i < k; i++)
	{
		cout << findWays(losts[i], n);
		if (i < k - 1) cout << endl;
	}
	//cin >> n;
	return 0;
}