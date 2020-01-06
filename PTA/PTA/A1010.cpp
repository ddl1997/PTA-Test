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