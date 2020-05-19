#include<set>
#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	set<char> remove_c;
	int l1 = s1.length(), l2 = s2.length();
	for (int i = 0; i < l2; i++)
	{
		remove_c.insert(s2[i]);
	}
	for (int i = 0; i < l1; i++)
	{
		if (remove_c.find(s1[i]) == remove_c.end())
			printf("%c", s1[i]);
	}
	cout << endl;
	return 0;
}