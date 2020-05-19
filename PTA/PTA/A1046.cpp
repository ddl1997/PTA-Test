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

// �����¼i��i+1֮��ľ��룬Ȼ���ѯʱ���������������Ե�ͻᳬʱ����
// ���Ը�Ϊ��¼1��i֮��ľ���D'i��s��t֮��ľ������D't-D's����ѯ��ʱ�临�ӶȾ���O(1)��������ΪO(n)