#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

const int N = 2000;

struct Gang {
	int sum;
	string head;
	Gang(int s, string h)
	{
		sum = s;
		head = h;
	}
};

int n, k, sum = 0;
map<string, int> indexes;
string names[N];
int totalWeights[N];
int roots[N];
int gangs[N];
bool related[N][N];

bool cmp(Gang a, Gang b)
{
	return a.head < b.head;
}

int findRoot(int index)
{
	while (roots[index] != -1) index = roots[index];
	return index;
}

Gang checkGang(int root)
{
	int head = 0, maxR = 0, gangSum = 0;
	for (int i = 0; i < sum; i++)
	{
		if (findRoot(i) == root)
		{
			gangSum++;
			if (totalWeights[i] > maxR)
			{
				head = i;
				maxR = totalWeights[i];
			}
		}
	}
	Gang g(gangSum, names[head]);
	return g;
}

int main()
{
	for (int i = 0; i < N; i++)
	{
		totalWeights[i] = 0;
		roots[i] = -1;
		gangs[i] = 0;
		for (int j = i; j < N; j++)
		{
			related[i][j] = related[j][i] = false;
		}
	}
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		string name1, name2;
		int weight;
		cin >> name1 >> name2 >> weight;
		if (indexes.find(name1) == indexes.end())
		{
			indexes[name1] = sum;
			names[sum++] = name1;
		}
		if (indexes.find(name2) == indexes.end())
		{
			indexes[name2] = sum;
			names[sum++] = name2;
		}
		int id1 = indexes[name1], id2 = indexes[name2];
		related[id1][id2] = related[id2][id1] = true;
		totalWeights[id1] += weight;
		totalWeights[id2] += weight;
	}
	//并查集求连通分量
	for (int i = 0; i < sum; i++)
	{
		for (int j = i; j < sum; j++)
		{
			if (j == i) continue;
			if (related[i][j])
			{
				int rootI = findRoot(i), rootJ = findRoot(j);
				if (rootI != rootJ)
					roots[rootJ] = rootI;
			}
		}
	}

	for (int i = 0; i < sum; i++)
	{
		gangs[findRoot(i)] += totalWeights[i];
	}
	vector<Gang> realGangs;
	for (int i = 0; i < sum; i++)
	{
		if (gangs[i] / 2 > k)
		{
			Gang g = checkGang(i);
			if (g.sum > 2)
				realGangs.push_back(g);
		}
	}

	int gangSum = realGangs.size();
	cout << gangSum << endl;
	if (gangSum > 0)
	{
		sort(realGangs.begin(), realGangs.end(), cmp);
		for (int i = 0; i < gangSum; i++)
		{
			cout << realGangs[i].head << " " << realGangs[i].sum << endl;
		}
	}

	return 0;
}