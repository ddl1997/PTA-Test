#include<iostream>
#include<vector>

using namespace std;

const int N = 10001;

struct Node {
	int v;
	Node * next = NULL;
};

int n, maxH = 0;
Node * vertics[N]; // �ڽӾ����ڴ�����
int connect[N], root[N], maxHeight[N];
bool checked[N];
vector<int> temp;

int getRoot(int node)
{
	if (root[node] == -1)
		return node;
	else
		return getRoot(root[node]);
}

void dfs(int node)
{
	checked[node] = true;
	temp.push_back(node);
	if (temp.size() > 1 && connect[node] == 1)
	{
		int height = temp.size() - 1;
		if (height > maxHeight[temp[0]])
			maxHeight[temp[0]] = height;
	}
	else
	{
		for (Node * i = vertics[node]; i != NULL; i = i->next)
			if (!checked[i->v])
				dfs(i->v);
	}
	temp.pop_back();
}

void calculateHeight(int node)
{
	fill(checked, checked + N, false);
	//dfs
	dfs(node);
	/*temp.push_back(node); // ��ʱ
	checked[node] = true;
	while (temp.size() > 0)
	{
		node = temp[temp.size() - 1];
		checked[node] = true;
		int next = 0;
		for (Node * i = vertics[node]; i != NULL; i = i->next)
		{
			if (!checked[i->v])
			{
				next = i->v;
				temp.push_back(next);
				break;
			}
		}
		if (next == 0)
		{
			int height = temp.size() - 1;
			if (height > maxHeight[temp[0]])
				maxHeight[temp[0]] = height;
			temp.pop_back();
		}
	}*/
}

void deleteGraph()
{
	for (int i = 0; i <= n; i++)
	{
		Node * j = vertics[i];
		while (j != NULL)
		{
			Node * temp = j;
			j = temp->next;
			delete temp;
		}
	}
}

int main()
{
	cin >> n;
	if (n == 1) // ֻ��һ����������
	{
		cin >> n;
		cout << n;
		return 0;
	}
	for (int i = 0; i <= n; i++)
		vertics[i] = NULL;
	fill(connect, connect + N, 0);
	fill(maxHeight, maxHeight + N, 0);
	for (int i = 0; i < n - 1; i++)
	{
		int v1, v2;
		scanf("%d %d", &v1, &v2);
		Node * head1 = new Node();
		head1->v = v2;
		head1->next = vertics[v1];
		vertics[v1] = head1;
		Node * head2 = new Node();
		head2->v = v1;
		head2->next = vertics[v2];
		vertics[v2] = head2;
		connect[v1]++;
		connect[v2]++;
	}
	int count = 0;
	fill(root, root + N, -1);
	for (int i = 1; i <= n; i++)
	{
		for (Node * j = vertics[i]; j != NULL; j = j->next)
		{
			int iRoot = getRoot(i), jRoot = getRoot(j->v);
			if (iRoot != jRoot)
				root[j->v] = iRoot;
		}
	}
	for (int i = 1; i <= n; i++)
		if (root[i] == -1)
			count++;
	if (count > 1)
	{
		printf("Error: %d components", count);
		deleteGraph();
		return 0;
	}
	vector<int> nodes;
	for (int i = 1; i <= n; i++)
	{
		if (connect[i] == 1)
			nodes.push_back(i);
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		calculateHeight(nodes[i]);
		if (maxHeight[nodes[i]] > maxH)
			maxH = maxHeight[nodes[i]];
	}
	for (int i = 0; i < nodes.size(); i++)
	{
		if (maxHeight[nodes[i]] == maxH)
			printf("%d\n", nodes[i]);
	}
	deleteGraph();
	return 0;
}

// ��������ͼ��N����������ҪN-1���߲��ܹ�����ͨͼ�������Ŀ������ͼ����Ҫ�����Ƿ��������ֻ��Ҫ����Ƿ���ͨ��
// ���ڶ���࣬���٣�ͼ�Ĵ洢Ӧ�����ڽӱ�����ᳬ�ڴ����ƣ���ʹ����С�����ݸ�ʽ��1B�����ڽӾ������ͼ�Ĵ洢��
// ���Ҫ�õ�10000 * 10000B = 100MB���ڴ棬������64MB�����ƣ���