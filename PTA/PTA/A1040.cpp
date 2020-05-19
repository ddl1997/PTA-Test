#include<iostream>
#include<string>

using namespace std;

string str;

int findSymmetricOdd(int median)
{
	int length = str.length(), bias = 0;
	while (median - bias >= 0 && median + bias < length && str[median - bias] == str[median + bias]) bias++;
	return bias * 2 - 1;
}

int findSymmetricEven(int medianL)
{
	int length = str.length(), max = 0, bias = 0;
	while (medianL - bias >= 0 && medianL + 1 + bias < length && str[medianL - bias] == str[medianL + 1 + bias]) bias++;
	return bias * 2;
}

int main()
{
	getline(cin, str);
	int max = 0, length = str.length();
	for (int i = 0; i < length; i++)
	{
		int odd = findSymmetricOdd(i), even = findSymmetricEven(i);
		max = max > odd ? max : odd;
		max = max > even ? max : even;
	}
	cout << max << endl;
	return 0;
}

// 动态规划解法：子串的长度&起始下标
/*
#include <iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
#define maxn 1010
string S;
int dp[maxn][maxn];
int main()
{
	getline(cin,S);
	int len=S.length();
	int ans=1;
	for(int i=0;i<len;i++)
	{
		dp[i][i]=1;
		if(i<len-1)
		{
		if(S[i]==S[i+1])
			{
				dp[i][i+1]=1;
				ans=2;
			}
		}
	}
	for(int L=3;L<=len;L++)
	{
		for(int i=0;i+L-1<len;i++)
		{
			int j=i+L-1;
			if(S[i]==S[j]&&dp[i+1][j-1])
			{
				dp[i][j]=1;
				ans=L;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
*/