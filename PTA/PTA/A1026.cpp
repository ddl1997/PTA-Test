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
	int atime, stime = -1, p;
	Player(int at, int _p)
	{
		atime = at; p = _p;
	}
};

Table tables[K];
vector<Player> players;
vector<Player> vplayers;
int pos = 0, vpos = 0;

bool cmp(Player a, Player b)
{
	return a.atime < b.atime;
}

int main()
{
	int n, k, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int hour, minute, second, p, type;
		scanf("%d:%d:%d %d %d", &hour, &minute, &second, &p, &type);
		Player player(hour * 3600 + minute * 60 + second, p * 60);
		if (type == 1)
			vplayers.push_back(player);
		else
			players.push_back(player);
	}
	sort(vplayers.begin(), vplayers.end(), cmp);
	/*for (int i = 0; i < players.size(); i++)
		cout << players[i].atime << endl;*/
	sort(players.begin(), players.end(), cmp);
	/*for (int i = 0; i < players.size(); i++)
		cout << players[i].atime << endl;*/
	cin >> k >> m;
	for (int i = 0; i < m; i++)
	{
		int index;
		scanf("%d", &index);
		tables[index - 1].isVip = true;
	}
	vector<Player> served;
	for (int i = 0; i < n; i++)
	{
		int min = 21 * 3600 + 1, minI = 0;
		bool isvip = false;
		for (int j = 0; j < k; j++)
		{
			if (tables[j].time < min || (!isvip && tables[j].time == min && tables[j].isVip))
			{
				min = tables[j].time;
				minI = j;
				isvip = tables[j].isVip;
			}
		}
		if (tables[minI].time > 21 * 3600) break;
		if ((vpos < vplayers.size()) && 
			((isvip && vplayers[vpos].atime <= tables[minI].time && players[vpos].atime <= tables[minI].time) ||
			(vplayers[vpos].atime <= players[vpos].atime) ||
			pos >= players.size()))
		{
			vplayers[vpos].stime = max(tables[minI].time, vplayers[vpos].atime);
			if (vplayers[vpos].p > 2 * 3600)
				tables[minI].time = vplayers[vpos].stime + 2 * 3600;
			else
				tables[minI].time = vplayers[vpos].stime + vplayers[vpos].p;
			served.push_back(vplayers[vpos++]);
		}
		else
		{
			players[pos].stime = max(tables[minI].time, players[pos].atime);
			if (players[pos].p > 2 * 3600)
				tables[minI].time = players[pos].stime + 2 * 3600;
			else
				tables[minI].time = players[pos].stime + players[pos].p;
			served.push_back(players[pos++]);
		}
		tables[minI].sum++;
	}
	int size = served.size();
	for (int i = 0; i < size; i++)
	{
		int ah = served[i].atime / 3600,
			am = (served[i].atime - ah * 3600) / 60,
			as = served[i].atime % 60,
			sh = served[i].stime / 3600,
			sm = (served[i].stime - sh * 3600) / 60,
			ss = served[i].stime % 60;
		printf("%02d:%02d:%02d %02d:%02d:%02d %d\n", ah, am, as, sh, sm, ss, (served[i].stime - served[i].atime) / 60);
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