#include<iostream>
#include<vector>
using namespace std;

const int N = 501;
const int Max =  2147483647;

int roads[N][N];
int capacity[N];
int distances[N] = { 0 };
int cmax;
vector<int> pre[N], path, dfs;
int minCost = Max, minGet = Max;
bool checked[N] = {false};

void getPath(int sp)
{
	dfs.push_back(sp);
	if (sp == 0)
	{
		int cost = 0, get = 0;
		for (int i = dfs.size() - 2; i >= 0; i--)
		{
			int partCost = cmax / 2 - capacity[dfs[i]];
			if (partCost < 0)
				get += -partCost;
			else
			{
				if (get > partCost)
					get -= partCost;
				else
				{
					cost += partCost - get;
					get = 0;
				}
			}
		}
		if (cost < minCost)
		{
			minCost = cost;
			minGet = get;
			path = dfs;
		}
		else if (cost == minCost && get < minGet)
		{
			minGet = get;
			path = dfs;
		}
		dfs.pop_back();
		return;
	}
	for (int i = 0; i < pre[sp].size(); i++)
		getPath(pre[sp][i]);
	dfs.pop_back();
}

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
					pre[i].clear();
					pre[i].push_back(current);
				}
				else if (distances[current] + roads[current][i] == distances[i])
				{
					pre[i].push_back(current);
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
	getPath(sp);
	printf("%d ", minCost);
	for (int i = path.size() - 1; i >= 0; i--)
	{
		if (i == 0)
			printf("%d", path[i]);
		else
			printf("%d->", path[i]);
	}
	printf(" %d", minGet);
	return 0;
}
// �����������Ҫ�����������⣺
// ��1������������⡣�ڵ������г���·���ϣ�����ڵ�����������г��޷����䵽ǰ��ڵ㣬���Ӧ���á���õġ��͡�ȱ�ٵġ�������������¼���ڹ�����
// ���г������ı仯��
// ��2���ڳ�ʼ���ڵ�֮������road����ʱ������ѭ����Ӧȡ��n����i/j <= n������ < n��