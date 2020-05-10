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

// ���Լ��ķ���û��֤��ȷ�ԣ�û�뵽һ�ι���
// Ӧ����̰���㷨�����������cmp�ĳ� return a + b < b + a; ���Խ�һ���������
// ��Ҫ��ȷ������ 1 12 123 1234 ������ǰ׺�ϴ�����ϵ��˳��