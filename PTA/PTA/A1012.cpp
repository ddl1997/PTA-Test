#include<iostream>
#include<map>

using namespace std;

const int N = 2000, M = 2000;
struct Grade{
	int id;
	int grade[4];
	int rank[4];
};
Grade grades[N];
int ids[M];
map<int, int> maps;
char courses[4] = { 'A', 'C', 'M', 'E' };

void sort(int pos, int length)
{
	for (int i = 0; i < length; i++)
	{
		int max = grades[i].grade[pos];
		int mPos = i;
		for (int j = i + 1; j < length; j++)
		{
			if (grades[j].grade[pos] > max)
			{
				max = grades[j].grade[pos];
				mPos = j;
			}
		}
		Grade temp = grades[i];
		grades[i] = grades[mPos];
		grades[mPos] = temp;
		if (i > 0 && grades[i].grade[pos] == grades[i - 1].grade[pos])
			grades[i].rank[pos] = grades[i - 1].rank[pos];
		else
			grades[i].rank[pos] = i + 1;
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> grades[i].id >> grades[i].grade[1] >> grades[i].grade[2] >> grades[i].grade[3];
		grades[i].grade[0] = (grades[i].grade[1] + grades[i].grade[2] + grades[i].grade[3]) / 3;
	}
	for (int i = 0; i < m; i++)
	{
		cin >> ids[i];
	}
	sort(0, n);
	sort(1, n);
	sort(2, n);
	sort(3, n);
	for (int i = 0; i < n; i++)
		maps[grades[i].id] = i;
	for (int i = 0; i < m; i++)
	{
		auto ite = maps.find(ids[i]);
		if (ite != maps.end())
		{
			int index = ite->second;
			Grade grade = grades[index];
			int min = grade.rank[0];
			int mPos = 0;
			for (int j = 1; j < 4; j++)
				if (grade.rank[j] < min)
				{
					min = grade.rank[j];
					mPos = j;
				}
			cout << min << " " << courses[mPos];
		}
		else
			cout << "N/A";
		if (i < m - 1) cout << endl;
	}
	//cin >> m;
	return 0;
}