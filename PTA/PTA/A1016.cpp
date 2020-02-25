#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

const int N = 1005;
int tolls[24];
struct Bill {
	string name;
	int sd, sh, sm, ed, eh, em;
	int index;
};
struct Record {
	string name;
	int d, h, m;
	int type;
};
Record * records[N][N];
Bill * bills[N][N];
Bill * headB[N];
int rCount[N];
int bCount[N];
int cusCount = 0;

bool cmpR(Record * r1, Record * r2)
{
	if (r1->d == r2->d)
	{
		if (r1->h == r2->h)
			return r1->m < r2->m;
		else
			return r1->h < r2->h;
	}
	else
		return r1->d < r2->d;
}

void sortR()
{
	
	for (int i = 0; i < cusCount; i++)
	{
		for (int x = 0; x < rCount[i]; x++)
		{
			int minX = x;
			for (int y = x; y < rCount[i]; y++)
			{
				if (cmpR(records[i][y], records[i][minX]))
				{
					minX = y;
				}
			}
			Record * temp = records[i][minX];
			records[i][minX] = records[i][x];
			records[i][x] = temp;
		}
	}
}

void sortB()
{

	for (int i = 0; i < cusCount; i++)
	{
		int minI = i;
		for (int j = i; j < cusCount; j++)
		{
			if (headB[j]->name < headB[minI]->name)
			{
				minI = j;
			}
		}
		Bill * temp = headB[minI];
		headB[minI] = headB[i];
		headB[i] = temp;
	}
}

int countCost(int sd, int sh, int sm, int ed, int eh, int em)
{
	int cost = 0;
	int sthour = sd * 24 + sh;
	int edhour = ed * 24 + eh;
	for (int i = sthour; i <= edhour - 1; i++)
	{
		cost += tolls[i % 24] * 60;
	}
	cost -= tolls[sh] * sm;
	cost += tolls[eh] * em;
	return cost;
}

int main()
{
	int n, month;
	for (int i = 0; i < 24; i++)
		cin >> tolls[i];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		headB[i] = NULL;
		rCount[i] = 0;
		bCount[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		string name, time, type;
		cin >> name >> time >> type;
		for (int j = 0; j < n; j++)
		{
			if (records[j][0] == NULL)
			{
				records[j][0] = new Record();
				Record * temp = records[j][0];
				temp->name = name;
				month = stoi(time.substr(0, 2), 0, 10);
				temp->d = stoi(time.substr(3, 2), 0, 10);
				temp->h = stoi(time.substr(6, 2), 0, 10);
				temp->m = stoi(time.substr(9, 2), 0, 10);
				temp->type = type == "on-line" ? 0 : 1;
				rCount[j]++;
				cusCount++;
				break;
			}
			else if (records[j][0]->name == name)
			{
				records[j][rCount[j]] = new Record();
				Record * temp = records[j][rCount[j]];
				temp->name = name;
				month = stoi(time.substr(0, 2), 0, 10);
				temp->d = stoi(time.substr(3, 2), 0, 10);
				temp->h = stoi(time.substr(6, 2), 0, 10);
				temp->m = stoi(time.substr(9, 2), 0, 10);
				temp->type = type == "on-line" ? 0 : 1;
				rCount[j]++;
				break;
			}
		}
	}
	sortR();
	for (int i = 0; i < cusCount; i++)
	{
		headB[i] = new Bill();
		headB[i]->name = records[i][0]->name;
		headB[i]->index = i;
	}
	for (int i = 0; i < cusCount; i++)
	{
		Record *now = NULL, *next = NULL;
		for (int j = 0; j < rCount[i]; j++)
		{
			if (j >= rCount[i] - 1) break;
			now = records[i][j];
			next = records[i][j + 1];
			if (now->type == 0 && next->type == 1)
			{
				bills[i][bCount[i]] = new Bill();
				Bill * b = bills[i][bCount[i]];
				b->name = now->name;
				b->sd = now->d;
				b->sh = now->h;
				b->sm = now->m;
				b->ed = next->d;
				b->eh = next->h;
				b->em = next->m;
				bCount[i]++;
				j++;
			}
		}
	}
	sortB();
	for (int i = 0; i < cusCount; i++)
	{
		if (bCount[headB[i]->index] == 0) continue;
		int index = headB[i]->index;
		string name = headB[i]->name;
		cout << name << " " << setw(2) << setfill('0') << month << endl;
		double total = 0.0;
		for (int j = 0; j < bCount[index]; j++)
		{
			Bill * b = bills[index][j];
			cout << setw(2) << setfill('0') << b->sd << ':'
				<< setw(2) << setfill('0') << b->sh << ':'
				<< setw(2) << setfill('0') << b->sm << " "
				<< setw(2) << setfill('0') << b->ed << ':'
				<< setw(2) << setfill('0') << b->eh << ':'
				<< setw(2) << setfill('0') << b->em << " ";
			int time = (((b->ed - b->sd) * 24 + (b->eh - b->sh)) * 60 + (b->em - b->sm));
			double cost = countCost(b->sd, b->sh, b->sm, b->ed, b->eh, b->em) / 100.0;
			total += cost;
			cout << time << " $" << setiosflags(ios::fixed) << setprecision(2) << cost << endl;
		}
		cout << "Total amount: $" << setiosflags(ios::fixed) << setprecision(2) << total << endl;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			delete records[i][j];
			delete bills[i][j];
		}
		delete headB[i];
	}
	return 0;
}