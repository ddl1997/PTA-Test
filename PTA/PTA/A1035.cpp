#include<iostream>
#include<string>

using namespace std;

const int N = 1000;

int n, changeCount = 0;
string username[N];
string password[N];
bool isChanged[N];

void parseString(int index)
{
	string p = password[index];
	int length = p.length();
	for (int i = 0; i < length; i++)
	{
		if (p[i] == '1')
		{
			p[i] = '@'; isChanged[index] = true;
		}
		if (p[i] == '0')
		{
			p[i] = '%'; isChanged[index] = true;
		}
		if (p[i] == 'l')
		{
			p[i] = 'L'; isChanged[index] = true;
		}
		if (p[i] == 'O')
		{
			p[i] = 'o'; isChanged[index] = true;
		}
	}
	if (isChanged[index])
	{
		password[index] = p;
		changeCount++;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string u, p;
		cin >> u >> p;
		username[i] = u;
		password[i] = p;
		isChanged[i] = false;
		parseString(i);
	}
	if (changeCount == 0)
	{
		if (n == 1)
			printf("There is 1 account and no account is modified\n");
		else
			printf("There are %d accounts and no account is modified\n", n);
	}
	else
	{
		cout << changeCount << endl;
		for (int i = 0; i < n; i++)
		{
			if (isChanged[i])
				cout << username[i] << " " << password[i] << endl;
		}
	}
	return 0;
}