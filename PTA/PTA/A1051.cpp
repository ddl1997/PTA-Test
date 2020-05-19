#include<iostream>

using namespace std;

const int M = 1000, N = 1000, K = 1000;

int m, n, k;
int sequences[K][N], stacks[K][N];
bool results[K];

int main()
{
	cin >> m >> n >> k;
	for (int i = 0; i < k; i++)
	{
		results[i] = true;
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &sequences[i][j]);
		}
	}
	for (int i = 0; i < k; i++)
	{
		int pos = 0, cur = 0, push = 1;
		bool over = false;
		while (pos >= 0 && push <= n)
		{
			stacks[i][pos] = push++;
			while (pos >= 0 && cur < n && stacks[i][pos] == sequences[i][cur])
			{
				cur++;
				pos--;
			}
			pos++;
			if (pos >= m)
			{
				over = true;
				break;
			}
		}
		cout << (!over && pos == 0 && cur == n ? "YES" : "NO") << endl;
	}
}

// �Լ�û������˼·���������������١���
// ����˼·����ģ����ջ�ͳ�ջ�Ĺ��̡�