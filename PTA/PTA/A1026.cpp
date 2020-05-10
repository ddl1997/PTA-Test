#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 10000, K = 100;
struct Table {
	int time = 8 * 3600, sum = 0;
	bool isVip = false;
};

struct Player {
	int atime, stime = -1, cost;
	bool vip;
	Player(int at, int c, bool v)
	{
		atime = at; cost = c; vip = v;
	}
};

int n, k, m, pcount = 0;
Table tables[K];
vector<Player> players;
vector<Player> vplayers;
bool isServed[N];

bool cmp(Player a, Player b)
{
	return a.atime < b.atime;
}

bool cmp_s(Player a, Player b)
{
	return a.stime < b.stime;
}

int findPos(int pos, int minI, int minT)
{
	int index = pos, vipI = -1;
	bool hasVip = false;
	if (tables[minI].isVip && players[pos].atime < minT)
	{
		for (int i = pos; i < pcount; i++)
		{
			if (!hasVip && !isServed[i] && players[i].vip && players[i].atime <= minT)
			{
				hasVip = true;
				vipI = i;
				break;
			}
		}
		
		index = hasVip ? vipI : pos;
	}
	return index;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int hour, minute, second, p, type;
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &p, &type);
		if (hour * 3600 + minute * 60 + second < 21 * 3600)
		{
			if (p > 120) p = 120; //最多2小时
			Player player(hour * 3600 + minute * 60 + second, p * 60, type);
			players.push_back(player);
			isServed[pcount++] = false;
		}
	}
	sort(players.begin(), players.end(), cmp);
	cin >> k >> m;
	for (int i = 0; i < m; i++)
	{
		int index;
		scanf("%d", &index);
		tables[index - 1].isVip = true;
	}

	vector<Player> served;
	int pos = 0;
	while (pos < pcount)
	{
		int minT = 21 * 3600, minI = -1;
		for (int i = 0; i < k; i++)
		{
			if (tables[i].time < minT)
			{
				minT = tables[i].time;
				minI = i;
			}
		}
		if (minI < 0) break;

		// vip用户为什么要用最小编号的vip桌位，不是应该用最小编号的桌位吗 
		// "For any pair of players, if there are some tables open when they arrive, 
		// they will be assigned to the available table with the smallest number."

		int minVI = -1;
		for (int i = 0; i < k; i++)
		{
			if (tables[i].isVip && tables[i].time == minT)
			{
				minVI = i; break;
			}
		}

		int index = findPos(pos, minI, minT);
		if (players[index].vip && minVI >= 0)
			minI = minVI;

		if (tables[minI].time < players[index].atime)
			players[index].stime = players[index].atime;
		else
			players[index].stime = tables[minI].time;
		tables[minI].time = players[index].stime + players[index].cost;
		tables[minI].sum++;
		served.push_back(players[index]);
		isServed[index] = true;
		while (pos < pcount && isServed[pos]) pos++;
	}

	sort(served.begin(), served.end(), cmp_s);
	int size = served.size();
	for (int i = 0; i < size; i++)
	{
		int ah = served[i].atime / 3600,
			am = (served[i].atime % 3600) / 60,
			as = served[i].atime % 60,
			sh = served[i].stime / 3600,
			sm = (served[i].stime % 3600) / 60,
			ss = served[i].stime % 60;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", ah, am, as, sh, sm, ss, (served[i].stime - served[i].atime + 30) / 60);
	}
	for (int i = 0; i < k; i++)
	{
		if (i == 0)
			printf("%d", tables[i].sum);
		else
			printf(" %d", tables[i].sum);
	}

	return 0;
}