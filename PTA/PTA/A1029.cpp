#include<iostream>

using namespace std;

const int N = 200000;

long int first[N];
long int second[N];
long int merged[N + 1];

int main()
{
	int n1, n2;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		scanf("%ld", &first[i]);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		scanf("%ld", &second[i]);
	}
	int end = (n1 + n2) / 2, i1 = 0, i2 = 0;
	while (i1 + i2 <= end)
	{
		if (i1 >= n1)
			merged[i1 + i2] = second[i2++];
		else if (i2 >= n2)
			merged[i1 + i2] = first[i1++];
		else if (first[i1] < second[i2])
			merged[i1 + i2] = first[i1++];
		else
			merged[i1 + i2] = second[i2++];
	}
	if ((n1 + n2) % 2 == 0)
		//printf("%ld", (merged[(n1 + n2) / 2 - 1] + merged[(n1 + n2) / 2]) / 2);
		printf("%ld", merged[(n1 + n2) / 2 - 1]); // ż������λ��ȡ���
	else
		printf("%ld", merged[(n1 + n2) / 2]);
	return 0;
}

/*
  ˫����������ռ�ÿռ���
#include<bits/stdc++.h>
using namespace std;
int main()
{
	queue<int> a,b;
	int n,m,M,i,t,cnt=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&t);
		a.push(t);
	}
	a.push(INT_MAX);
	scanf("%d",&m);
	M=(n+m-1)/2;
	for(i=0;i<m;i++)
	{
		scanf("%d",&t);
		b.push(t);
		if(cnt==M)     //�����Ҫ����b.push(t)֮��,b.pop()֮ǰ
		{
			printf("%d", min(a.front(), b.front()));
			return 0;
		}
		if(a.front()<b.front())
			a.pop();
		else
			b.pop();
		cnt++;
	}
	b.push(INT_MAX);
	while(cnt<M)
	{
		if(a.front()<b.front())
			a.pop();
		else
			b.pop();
		cnt++;
	}
	printf("%d",min(a.front(),b.front()));
	return 0;
}
*/