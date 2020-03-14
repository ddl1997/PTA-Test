#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

const int N = 100, K = 300;
struct Node {
	long long id;
	int score, localRank;
	Node(long long _id, int _score)
	{
		id = _id;
		score = _score;
	}
};

vector<Node> locations[N];
int pos[N];

bool cmp(Node a, Node b)
{
	return (a.score > b.score) || (a.score == b.score && a.id < b.id);
}

int main()
{
	int n, count = 0;
	cin >> n;
	fill(pos, pos + N, 0);
	for (int i = 0; i < n; i++)
	{
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			long long id;
			int score;
			scanf("%lld %d", &id, &score);
			Node n(id, score);
			locations[i].push_back(n);
		}
		count += k;
	}
	cout << count << endl;
	for (int i = 0; i < n; i++)
	{
		sort(locations[i].begin(), locations[i].end(), cmp);
		int size = locations[i].size();
		for (int j = 0; j < size; j++)
		{
			if (j == 0)
				locations[i][j].localRank = 1;
			else if (locations[i][j].score == locations[i][j - 1].score)
				locations[i][j].localRank = locations[i][j - 1].localRank;
			else
				locations[i][j].localRank = j + 1;
		}
	}
	int lastscore = -1, lastrank = 0;
	for (int i = 0; i < count; i++)
	{
		int score = 0, l = 0;
		long long id = 9999999999999;
		for (int j = 0; j < n; j++)
		{
			if (pos[j] == locations[j].size()) continue;
			if (locations[j][pos[j]].score > score || (locations[j][pos[j]].score == score && locations[j][pos[j]].id < id))
			{
				score = locations[j][pos[j]].score;
				id = locations[j][pos[j]].id;
				l = j;
			}
		}
		int rank = locations[l][pos[l]].score == lastscore ? lastrank : i + 1;
		printf("%013lld %d %d %d\n", locations[l][pos[l]].id, rank, l + 1, locations[l][pos[l]].localRank);
		lastscore = locations[l][pos[l]].score;
		lastrank = rank;
		pos[l]++;
	}

	return 0;
}