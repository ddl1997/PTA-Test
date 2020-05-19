#include<iostream>
#include<set>
#include<vector>
#include<algorithm>
#include<time.h>

using namespace std;

const int SIZE = 1e6;

int main()
{
	set<int> s;
	vector<int> v;

	clock_t start = clock();
	for (int i = SIZE; i >= 0; i--)
	{
		s.insert(i);
	}
	for (auto i = s.begin(); i != s.end(); i++)
	{
		int j = *i;
	}
	clock_t end = clock();
	cout << end - start << endl;

	start = clock();
	for (int i = SIZE; i >= 0; i--)
	{
		v.push_back(i);
	}
	sort(v.begin(), v.end());
	for (auto i = v.begin(); i != v.end(); i++)
	{
		int j = *i;
	}
	end = clock();
	cout << end - start << endl;

	return 0;
}

// [1e4]
// set: 82
// vector: 29
// [1e5]
// set: 729
// vector: 209
// [1e6]
// set: 7943
// vector: 2173
// [1e7]
// set: 
// vector:
// [1e8]
// set: 
// vector: