#include<iostream>
#include<vector>

using namespace std;

int counts[10001];
vector<int> players;

int main()
{
	for (int i = 0; i < 10001; i++)
		counts[i] = 0;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int bet;
		scanf("%d", &bet);
		players.push_back(bet);
		counts[bet]++;
	}
	int winner = -1;
	for (int i = 0; i < n; i++)
	{
		if (counts[players[i]] == 1)
		{
			winner = players[i];
			break;
		}
	}
	if (winner > 0)
		cout << winner << endl;
	else
		cout << "None" << endl;
	
	return 0;
}