#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

const int N = 10000;

int n;
string segments[N];

bool cmp(string a, string b)
{
	return a > b;
}

bool isPrefix(string a, string b)
{
	int al = a.length(), bl = b.length();
	if (al == bl) return a == b;
	else if (al > bl)
		return a.substr(0, bl) == b;
	else
		return b.substr(0, al) == a;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> segments[i];
	}
	sort(segments, segments + n, cmp);
	string min = "";
	while (n > 0)
	{

		string minS = segments[n - 1];
		if (n == 1)
		{
			min += minS; break;
		}
		string bigger = segments[n - 2];
		if (!isPrefix(minS, bigger))
		{
			min += minS;
		}
		else if (minS + bigger >= bigger + minS)
		{
			min += bigger;
			segments[n - 1] = bigger;
			segments[n - 2] = minS;
		}
		else
		{
			min += minS;
		}
		n--;
	}
	while (min.length() > 1 && min[0] == '0')
	{
		min = min.substr(1, min.length() - 1);
	}
	cout << min << endl;
	return 0;
}

// 对自己的方法没验证正确性，没想到一次过了
// 应用了贪心算法，如果将函数cmp改成 return a + b < b + a; 可以进一步精简代码
// 主要是确定类似 1 12 123 1234 这种在前缀上存在联系的顺序