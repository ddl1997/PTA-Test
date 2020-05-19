#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

int n, k;
map<string, vector<int>> courses;
vector<string> consults;

bool cmp(int a, int b)
{
	return a < b;
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int id, sum;
		scanf("%d %d", &id, &sum);
		for (int i = 0; i < sum; i++)
		{
			string name;
			name.resize(4);
			scanf("%s", &name[0]);
			if (courses.find(name) == courses.end())
			{
				vector<int> c;
				c.push_back(id);
				courses[name] = c;
			}
			else
			{
				courses[name].push_back(id);
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		string name;
		name.resize(4);
		scanf("%s", &name[0]);
		consults.push_back(name);
	}
	for (int i = 0; i < n; i++)
	{
		if (courses.find(consults[i]) == courses.end())
		{
			printf("%s 0\n", consults[i].c_str());
		}
		else
		{
			auto course = courses[consults[i]];
			int size = course.size();
			printf("%s %d", consults[i].c_str(), size);
			sort(course.begin(), course.end());
			for (int j = 0; j < size; j++)
			{
				printf(" %d", course[j]);
			}
			printf("\n");
		}
	}

	return 0;
}