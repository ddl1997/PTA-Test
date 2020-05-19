#include<iostream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 40000, K = 2501;

//set<string> courses[K];
vector<string> courses[K];

int main()
{
	int n, k;
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		int sum;
		string name;
		cin >> name >> sum;
		for (int j = 0; j < sum; j++)
		{
			int c;
			scanf("%d", &c);
			//courses[c].insert(name);
			courses[c].push_back(name);
		}
	}
	for (int i = 1; i <= k; i++)
	{
		int size = courses[i].size();
		printf("%d %d\n", i, size);
		sort(courses[i].begin(), courses[i].end());
		for (auto j = courses[i].begin(); j != courses[i].end(); j++)
		{
			printf("%s\n", (*j).c_str());
		}
	}
	return 0;
}

// 使用set容器超时
// 参考：https://blog.csdn.net/truexf/article/details/17303263
// 测试：set_vector.cpp