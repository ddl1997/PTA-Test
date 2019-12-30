#include<iostream>
#include<string>

using namespace std;

typedef struct {
	string id;
	int inTime;
	int outTime;
} Record;

int TimeToInt(string time)
{
	return ((char)time[0] - '0') * 60 * 60 * 10 + 
		   ((char)time[1] - '0') * 60 * 60 + 
		   ((char)time[3] - '0') * 60 * 10 + 
		   ((char)time[4] - '0') * 60 + 
		   ((char)time[6] - '0') * 10 + 
		   ((char)time[7] - '0');
}

int main()
{
	int m;
	cin >> m;
	string first, last;
	int min = 0x7fffffff, max = 0;
	for (int i = 0; i < m; i++)
	{
		string id, inTime, outTime;
		cin >> id >> inTime >> outTime;
		int in = TimeToInt(inTime), out = TimeToInt(outTime);
		if (in < min)
		{
			min = in;
			first = id;
		}
		if (out > max)
		{
			max = out;
			last = id;
		}
	}
	cout << first << " " << last;
	//cin >> m;
	return 0;
}