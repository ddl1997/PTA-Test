#include<iostream>
#include<string>
#include"math.h"
#include<algorithm>

using namespace std;

long long polyCalculate(string str, long long radix)
{
	long long sum = 0;
	for (int i = 0; i < str.length(); i++)
	{
		char digit = str.at(i);
		long long power = pow(radix, str.length() - i - 1);
		if (digit > '9')
			sum += (digit - 'a' + 10) * power;
		else
			sum += (digit - '0') * power;
	}
	return sum;
}

int main()
{
	string n1, n2, know, unknow;
	int tag;
	long long radix, iKnow = 0, iUnknow = 0;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 1)
	{
		know = n1;
		unknow = n2;
	}
	else
	{
		know = n2;
		unknow = n1;
	}
	iKnow = polyCalculate(know, radix);
	int maxDigit = '0';
	for (int i = 0; i < unknow.length(); i++)
	{
		char digit = unknow.at(i);
		if (digit > maxDigit)
			maxDigit = digit;
	}
	if (maxDigit == '0')
	{
		cout << 2;
		return 0;
	}
	else if (maxDigit > '9')
		maxDigit = maxDigit - 'a' + 10;
	else
		maxDigit = maxDigit - '0';
	bool possible = false;
	long long start = maxDigit + 1, end = max(start, iKnow), r;
	while (start <= end) {
		r = (start + end) / 2;
		iUnknow = polyCalculate(unknow, r);
		if (iKnow == iUnknow)
		{
			possible = true;
			break;
		}
		else if (iUnknow < 0 || iKnow < iUnknow)
			end = r - 1;
		else
			start = r + 1;
		
	}
	if (possible)
		cout << r;
	else
		cout << "Impossible";
	
	//cin >> n1;
	return 0;
}
//24/25 10没通过
//注意radix范围题目没有进行限制，只是限制了每一位digit的大小
//在计算未知基数的10进制时注意结果溢出
/*
#include<bits/stdc++.h>
using namespace std;
long long convert(string n,long long r)//转换为十进制
{
	long long sum=0;
	int index=0,temp=0;
	for(auto it=n.rbegin();it!=n.rend();it++)
	{
		temp=isdigit(*it)?*it-'0':*it-'a'+10;
		sum+=temp*pow(r,index++);
	}
	return sum;
}
long long find_r(string n,long long num)//找到令两个数相同的进制数
{
	char it=*max_element(n.begin(),n.end());
	long long low=(isdigit(it)?it-'0':it-'a'+10)+1;
	long long high=max(num,low);
	while(low<=high){
		long long mid=(low+high)/2;
		long long t=convert(n,mid);
		if(t<0||t>num)high=mid-1;
		else if(t==num)return mid;
		else low=mid+1;
	}
	return -1;
}
int main()
{
	string n1,n2;
	long long tag=0,r=0,rr;
	cin>>n1>>n2>>tag>>r;
	rr=tag==1?find_r(n2,convert(n1,r)):find_r(n1,convert(n2,r));
	if(rr!=-1)cout<<rr;
	else cout<<"Impossible";
	return 0;
}
*/