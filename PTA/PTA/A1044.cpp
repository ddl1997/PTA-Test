#include<iostream>

using namespace std;

const int N = 100001;

struct chain {
	int start, end;
};

int n, m, minV = 1e9, option_count = 0;
int diamonds[N];
chain options[N];

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &diamonds[i]);
		
	}
	for (int i = 0; i < n; i++)
	{
		int pos = i, value = 0;
		while (pos < n && value < m)
		{
			value += diamonds[pos];
			pos++;
		}
		if (value >= m && value <= minV)
		{
			if (value < minV)
				option_count = 0;
			options[option_count].start = i;
			options[option_count].end = pos - 1;
			option_count++;
			minV = value; 
		}
		else if (value < m)
			break;
	}
	
	for (int i = 0; i < option_count; i++)
	{
		printf("%d-%d\n", options[i].start + 1, options[i].end + 1);
	}
	return 0;
}