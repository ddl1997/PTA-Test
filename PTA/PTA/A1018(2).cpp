// 9/10 7
#include<iostream>
#include<vector>
using namespace std;

const int N = 501;
const int Max = 2147483647;

int roads[N][N];
int capacity[N];
int distances[N] = { 0 };
int cmax;
int pre[N], need[N], collect[N];
int minNeed[N], minCol[N];
bool checked[N] = { false };

void dijkstra(int e, int n) {
	for (int count = 0; count <= n; count++)
	{
		int current = -1, min = Max;
		for (int i = 0; i <= n; i++)
		{
			if (!checked[i] && distances[i] < min)
			{
				current = i;
				min = distances[i];
			}
		}
		if (current == -1) return;
		checked[current] = true;
		for (int i = 0; i <= n; i++)
		{
			if (!checked[i] && roads[current][i] >= 0)
			{
				if (distances[current] + roads[current][i] < distances[i])
				{
					distances[i] = distances[current] + roads[current][i];
					pre[i] = current;
					if (capacity[i] >= cmax / 2)
					{
						collect[i] = capacity[i] - cmax / 2 + collect[current];
						need[i] = need[current];
					}
					else
					{
						int cost = cmax / 2 - capacity[i];
						if (collect[current] > cost)
						{
							collect[i] = collect[current] - cost;
							need[i] = need[current];
						}
						else
						{
							need[i] = need[current] + cost - collect[current];
							collect[i] = 0;
						}
					}
					minNeed[i] = need[i];
					minCol[i] = collect[i];
				}
				else if (distances[current] + roads[current][i] == distances[i])
				{
					int cneed, ccol;
					if (capacity[i] >= cmax / 2)
					{
						ccol = capacity[i] - cmax / 2 + collect[current];
						cneed = need[current];
					}
					else
					{
						int cost = cmax / 2 - capacity[i];
						if (collect[current] > cost)
						{
							ccol = collect[current] - cost;
							cneed = need[current];
						}
						else
						{
							cneed = need[current] + cost - collect[current];
							ccol = 0;
						}
					}
					if (cneed < minNeed[i] || (cneed == minNeed[i] && ccol < minCol[i]))
					{
						pre[i] = current;
						need[i] = minNeed[i] = cneed;
						collect[i] = minCol[i] = ccol;
					}
				}
			}
		}
	}
}

int main()
{
	int n, sp, m;
	cin >> cmax >> n >> sp >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> capacity[i];
		distances[i] = Max;
		need[i] = collect[i] = 0;
		minNeed[i] = minCol[i] = Max;
		checked[i] = false;
	}
	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= n; j++)
			roads[i][j] = -1;
	for (int i = 0; i < m; i++)
	{
		int s1, s2, length;
		scanf("%d %d %d", &s1, &s2, &length);
		roads[s1][s2] = roads[s2][s1] = length;
	}
	dijkstra(sp, n);
	printf("%d ", minNeed[sp]);
	int current = sp;
	vector<int> path;
	while (current != 0)
	{
		path.push_back(current);
		current = pre[current];
	}
	path.push_back(current);
	for (int i = path.size() - 1; i >= 0; i--)
	{
		if (i == 0)
			printf("%d", path[i]);
		else
			printf("%d->", path[i]);
	}
	printf(" %d", minCol[sp]);
	return 0;
}