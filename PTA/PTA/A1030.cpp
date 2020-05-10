#include<iostream>
#include<vector>

using namespace std;

const int N = 500, INF = 1000;
int n, m, s, d;
int distances[N][N];
int costs[N][N];
vector<int> froms[N];
bool visited[N];
int lengths[N];
int minCost = INF * INF;
vector<int> path;

void shortestPath()
{
	int next = s;
	lengths[s] = 0;
	while (next >= 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (visited[i] || i == next) continue;
			if (lengths[next] + distances[next][i] < lengths[i])
			{
				lengths[i] = lengths[next] + distances[next][i];
				froms[i].clear();
				froms[i].push_back(next);
			}
			else if (lengths[next] + distances[next][i] == lengths[i])
			{
				froms[i].push_back(next);
			}
		}
		visited[next] = true;
		int min = INF;
		next = -1;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && lengths[i] < min)
			{
				next = i;
				min = lengths[i];
			}
		}
	}
}

void dfs()
{
	vector<int> temp;
	temp.push_back(d);
	int size = temp.size();
	while (size > 0)
	{
		int pos = temp[size - 1];
		if (pos == s)
		{
			int cost = 0;
			for (int i = 0; i < size - 1; i++)
			{
				cost += costs[temp[i]][temp[i + 1]];
			}
			if (cost < minCost)
			{
				minCost = cost;
				path = temp;
			}
		}
		int pSize = froms[pos].size();
		if (pSize == 0)
		{
			temp.pop_back();
		}
		else
		{
			temp.push_back(froms[pos][pSize - 1]);
			froms[pos].pop_back();
		}
		size = temp.size();
	}
}

int main()
{
	cin >> n >> m >> s >> d;
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
		lengths[i] = INF;
		for (int j = 0; j < n; j++)
			distances[i][j] = costs[i][j] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		int from, to, distance, cost;
		scanf("%d %d %d %d", &from, &to, &distance, &cost);
		distances[from][to] = distances[to][from] = distance;
		costs[from][to] = costs[to][from] = cost;
	}
	shortestPath();
	dfs();

	for (int i = path.size() - 1; i >= 0; i--)
		printf("%d ", path[i]);
	printf("%d %d", lengths[d], minCost);
	return 0;
}