#include<iostream>
#include<algorithm>

using namespace std;

const int N = 100002, M = 10000;

int n, m, cycle = 0, n_to_1;
int distances[N], min_dis[M];

int main()
{
	cin >> n;
	distances[0] = 0;
	for (int i = 0; i < n; i++)
	{
		int dis;
		scanf("%d", &dis);
		distances[i + 1] = distances[i] + dis;
		cycle += dis;
	}
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		int from, to;
		scanf("%d %d", &from, &to);
		int start = min(from, to), end = max(from, to), dis = distances[end - 1] - distances[start - 1];
		min_dis[i] = min(dis, cycle - dis);
	}
	for (int i = 0; i < m; i++)
		cout << min_dis[i] << endl;
	return 0;
}

// 如果记录i和i+1之间的距离，然后查询时遍历，第三个测试点就会超时……
// 所以改为记录1和i之间的距离D'i，s和t之间的距离就是D't-D's，查询的时间复杂度就是O(1)，而遍历为O(n)