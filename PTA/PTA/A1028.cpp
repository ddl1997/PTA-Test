#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

struct Record
{
	int id, grade;
	string name;
	Record(int i, string n, int g)
	{
		id = i;
		name = n;
		grade = g;
	}
};

vector<Record> records;

bool cmp_1(Record a, Record b)
{
	return a.id < b.id;
}

bool cmp_2(Record a, Record b)
{
	return a.name < b.name || (a.name == b.name && a.id < b.id);
}

bool cmp_3(Record a, Record b)
{
	return a.grade < b.grade || (a.grade == b.grade && a.id < b.id);
}

int main()
{
	int n, c;
	cin >> n >> c;
	for (int i = 0; i < n; i++)
	{
		int id, grade;
		string name;
		cin >> id >> name >> grade;
		Record r(id, name, grade);
		records.push_back(r);
	}
	switch (c)
	{
	case 1:
		sort(records.begin(), records.end(), cmp_1); break;
	case 2:
		sort(records.begin(), records.end(), cmp_2); break;
	case 3:
		sort(records.begin(), records.end(), cmp_3); break;
	}
	int size = records.size();
	for (int i = 0; i < size; i++)
	{
		printf("%06d %s %d\n", records[i].id, records[i].name.c_str(), records[i].grade);
	}
	return 0;
}

