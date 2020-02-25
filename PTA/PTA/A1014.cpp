#include<iostream>
#include<iomanip>

using namespace std;

const int N = 20, M = 10, K = 1001;
int windows[N][M];
int nextI[N];
int wait[N];
int customers[K];
int startTime[N];
int leaveTime[K];
int n, m, k, q;
int maxTime = 540;

void init()
{
	for (int i = 0; i < n; i++)
	{
		nextI[i] = 0;
		wait[i] = 0;
		startTime[i] = 0;
	}
	for (int i = 1; i <= k; i++)
		leaveTime[i] = -1;
}

void insert(int index)
{
	int w = 0, minLine = wait[0];
	for (int i = 1; i < n; i++)
	{
		if (wait[i] < minLine)
		{
			w = i;
			minLine = wait[i];
		}
	}
	if (minLine < m)
	{
		windows[w][nextI[w]] = index;
		nextI[w] = (nextI[w] + 1) % m;
		wait[w]++;
	}
	else
	{
		int eI = 0, eT = customers[windows[0][nextI[0]]] + startTime[0];
		for (int i = 1; i < n; i++)
		{
			if (customers[windows[i][nextI[i]]] + startTime[i] < eT)
			{
				eI = i;
				eT = windows[i][nextI[i]] + startTime[i];
			}
		}
		int cus = windows[eI][nextI[eI]];
		startTime[eI] = leaveTime[cus] = startTime[eI] + customers[cus];
		windows[eI][nextI[eI]] = index;
		nextI[eI] = (nextI[eI] + 1) % m;
	}

}

void process()
{
	for (int i = 0; i < n; i++)
	{
		int first = (nextI[i] - wait[i] + m) % m;
		for (int j = 0; j < wait[i]; j++)
		{
			int pos = (first + j) % m;
			int index = windows[i][pos];
			startTime[i] = leaveTime[index] = startTime[i] + customers[index];
		}
	}
}

int main()
{
	init();
	cin >> n >> m >> k >> q;
	for (int i = 1; i <= k; i++)
	{
		cin >> customers[i];
		insert(i);
	}
	process();
	int queries[K];
	for (int i = 0; i < q; i++)
		cin >> queries[i];
	for (int i = 0; i < q; i++)
	{
		int index = queries[i];
		if (leaveTime[index] - customers[index] >= maxTime)
			cout << "Sorry" << endl;
		else
		{
			int h = leaveTime[index] / 60 + 8;
			int m = leaveTime[index] % 60;
			cout << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m << endl;
		}
	}
	return 0;
}
//17:00后来的客户结果为Sorry，而不是17:00后结束的客户结果为Sorry。
//Note that since the bank is closed everyday after 17:00, for those customers who cannot be served before 17:00, you must output Sorry instead.
//【5/6】