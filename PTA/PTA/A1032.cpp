#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100000;

int s1, s2, n;
int nextAddr[N];
vector<int> str1, str2;

int main()
{
	cin >> s1 >> s2 >> n;
	if (s1 == -1 || s2 == -1) // 特殊输入
	{
		printf("-1\n");
		return 0;
	}
	if (s1 == s2) // 特殊输入
	{
		printf("%05d", s1);
		return 0;
	}
	else 
	for (int i = 0; i < n; i++)
	{
		int from, to;
		char data;
		scanf("%d %c %d", &from, &data, &to);
		nextAddr[from] = to;
	}
	int next = s1;
	while (next != -1)
	{
		str1.push_back(next);
		next = nextAddr[next];
	}
	next = s2;
	while (next != -1)
	{
		str2.push_back(next);
		next = nextAddr[next];
	}
	while (str1[str1.size() - 1] == str2[str2.size() - 1])
	{
		str1.pop_back();
		str2.pop_back();
		if (str1.size() == 0 || str2.size() == 0) break;
	}
	int output;
	if (str1.size() == 0)
		output = nextAddr[str1[str2.size() - 1]];
	else
		output = nextAddr[str1[str1.size() - 1]];
	if (output >= 0)
		printf("%05d", output);
	else
		printf("%d", output);
	
	return 0;
}