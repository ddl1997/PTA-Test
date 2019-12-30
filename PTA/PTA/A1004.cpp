#include<iostream>

using namespace std;

const int N = 100;
struct {
	int depth;
	int k;
	int children[N];
} nodes[N];

void CountDepth(int no)
{
	if (nodes[no].k == 0)
		return;
	for (int i = 0; i < nodes[no].k; i++)
	{
		int child = nodes[no].children[i];
		nodes[child].depth = nodes[no].depth + 1;
		CountDepth(child);
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		nodes[i].depth = i == 1 ? 0 : -1;
		nodes[i].k = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int no, k;
		cin >> no >> k;
		nodes[no].k = k;
		for (int j = 0; j < k; j++)
		{
			int child;
			cin >> child;
			nodes[no].children[j] = child;
		}
	}
	CountDepth(1);
	int leafCount[N];
	int maxDepth = 0;
	for (int i = 0; i < n; i++)
		leafCount[i] = 0;
	for (int i = 1; i <= n; i++)
	{
		if (nodes[i].depth != -1 && nodes[i].k == 0)
		{
			leafCount[nodes[i].depth]++;
			if (nodes[i].depth > maxDepth)
				maxDepth = nodes[i].depth;
		}
	}
	for (int i = 0; i <= maxDepth; i++)
	{
		cout << leafCount[i] << (i == maxDepth ? "" : " ");
	}
	//cin >> n;
}
//节点输入的序号顺序可能是乱序，导致错误。