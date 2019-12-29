#include<iostream>

using namespace std;

const int MAX_CITY_COUNT = 500;
const int MAX_INT = 0x7fffffff;
int cities[MAX_CITY_COUNT];
int dist[MAX_CITY_COUNT][MAX_CITY_COUNT];
int pathCounts[MAX_CITY_COUNT];
int teamSizes[MAX_CITY_COUNT];

int ShortestPath(int citySum, int from, int to)
{
	int length[MAX_CITY_COUNT];
	int visited[MAX_CITY_COUNT];
	for (int i = 0; i < citySum; i++)
	{
		length[i] = i == from ? 0 : MAX_INT;
		visited[i] = 0;
	}
	pathCounts[from] = 1;
	teamSizes[from] = cities[from];

	for (int count = 0; count < citySum; count++)
	{
		int next = -1, minLength = MAX_INT;
		for (int i = 0; i < citySum; i++)
		{
			if (visited[i] == 0 && minLength > length[i])
			{
				minLength = length[i];
				next = i;
			}
		}
		if (next == -1) break;
		visited[next] = 1;
		for (int i = 0; i < citySum; i++)
		{
			if (visited[i] == 0 && dist[next][i] != MAX_INT)
			{
				if (length[i] > length[next] + dist[next][i])
				{
					length[i] = length[next] + dist[next][i];
					pathCounts[i] = pathCounts[next];
					teamSizes[i] = teamSizes[next] + cities[i];
				}
				else if (length[i] == length[next] + dist[next][i])
				{
					pathCounts[i] += pathCounts[next];
					if (teamSizes[i] < teamSizes[next] + cities[i])
						teamSizes[i] = teamSizes[next] + cities[i];
				}
			}
		}
	}
	return length[to];
}

int main()
{
	int citySum, roadSum, from, to;
	cin >> citySum >> roadSum >> from >> to;
	for (int i = 0; i < citySum; i++)
	{
		cin >> cities[i];
		pathCounts[i] = 0;
		teamSizes[i] = 0;
	}
	for (int i = 0; i < citySum; i++)
		for (int j = 0; j < citySum; j++)
			dist[i][j] = i == j ? 0 : MAX_INT;
	for (int i = 0; i < roadSum; i++)
	{
		int f, t, dis;
		cin >> f >> t >> dis;
		dist[f][t] = dis;
		dist[t][f] = dis;
	}

	ShortestPath(citySum, from, to);
	cout << pathCounts[to] << " " << teamSizes[to];
    return 0;
}

