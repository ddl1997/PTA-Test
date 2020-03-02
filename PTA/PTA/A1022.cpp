#include<iostream>
#include<string>
#include<vector>
#include<map>

using namespace std;

const int N = 10001, M = 1001;

struct Index {
	string key;
	vector<int> books;
	int type;
};

vector<int> titles[N];
vector<int> authors[N];
vector<int> keywords[M];
vector<int> publishers[M];
vector<int> years[2001];
map<string, int> tmap;
map<string, int> amap;
map<string, int> kmap;
map<string, int> pmap;
map<string, int> ymap;

int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *) b;
}

int main()
{
	int n, m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string title, author, keyword, publisher, year;
		int id;
		scanf("%d%*c", &id);
		getline(cin, title);
		getline(cin, author);
		getline(cin, keyword);
		getline(cin, publisher);
		getline(cin, year);
		{
			//title
			auto iter = tmap.find(title);
			if (iter != tmap.end())
				titles[iter->second].push_back(id);
			else
			{
				int size = tmap.size();
				titles[size].push_back(id);
				tmap[title] = size;
			}
		}
		{
			//author
			auto iter = amap.find(author);
			if (iter != amap.end())
				authors[iter->second].push_back(id);
			else
			{
				int size = amap.size();
				authors[size].push_back(id);
				amap[author] = size;
			}
		}
		{
			//key words
			vector<string> keys;
			int lastspace = -1;
			for (int k = 0; k < keyword.length(); k++)
			{
				if (k == keyword.length() - 1)
				{
					keys.push_back(keyword.substr(lastspace + 1, k - lastspace));
				}
				else if (keyword[k] == ' ')
				{
					keys.push_back(keyword.substr(lastspace + 1, k - lastspace - 1));
					lastspace = k;
				}
			}
			for (int j = 0; j < keys.size(); j++)
			{
				auto iter = kmap.find(keys[j]);
				if (iter != kmap.end())
					keywords[iter->second].push_back(id);
				else
				{
					int size = kmap.size();
					keywords[size].push_back(id);
					kmap[keys[j]] = size;
				}
			}
		}
		{
			//publisher
			auto iter = pmap.find(publisher);
			if (iter != pmap.end())
				publishers[iter->second].push_back(id);
			else
			{
				int size = pmap.size();
				publishers[size].push_back(id);
				pmap[publisher] = size;
			}
		}
		{
			//year
			auto iter = ymap.find(year);
			if (iter != ymap.end())
				years[iter->second].push_back(id);
			else
			{
				int size = ymap.size();
				years[size].push_back(id);
				ymap[year] = size;
			}
		}
	}
	cin >> m;
	Index result[M];
	for (int i = 0; i < m; i++)
	{
		string key;
		int type;
		scanf("%d: ", &type);
		getline(cin, key);
		switch (type)
		{
		case 1: {
			auto iter = tmap.find(key);
			if (iter != tmap.end())
				result[i].books = titles[iter->second];
			break;
		}
		case 2: {
			auto iter = amap.find(key);
			if (iter != amap.end())
				result[i].books = authors[iter->second];
			break;
		}
		case 3: {
			auto iter = kmap.find(key);
			if (iter != kmap.end())
				result[i].books = keywords[iter->second];
			break;
		}
		case 4: {
			auto iter = pmap.find(key);
			if (iter != pmap.end())
				result[i].books = publishers[iter->second];
			break;
		}
		case 5: {
			auto iter = ymap.find(key);
			if (iter != ymap.end())
				result[i].books = years[iter->second];
			break;
		}
		default: {}
		}
		result[i].key = key;
		result[i].type = type;
	}
	for (int i = 0; i < m; i++)
	{
		printf("%d: %s\n", result[i].type, result[i].key.c_str());
		if (result[i].books.size() == 0)
			printf("Not Found\n");
		else
		{
			int size = result[i].books.size();
			qsort(&(result[i].books.data()[0]), size, sizeof(int), cmp);
			for (int j = 0; j < size; j++)
				printf("%07d\n", result[i].books[j]);// 输出的id要保证为7位。
		}
	}
	return 0;
}

// （1）类似id的数据如果用int（或数字类型）存储，则输出时需要进行补全；
// （2）当数据量较大（接近或超过10^4）时，要注意内存的限制；
// （3）当要读取的字符串中包含空格时，可以使用getline(cin, str)，读取一行后不需要处理回车换行
// （4）更简洁的代码（利用set）：

//#include<iostream>
//#include<string>
//#include<cstring>
//#include<set>
//#include<map>
//using namespace std;
//map<string, set<int>> T, A, K, P, Y;
//
//void finding(map<string, set<int>>& m, string& s) {
//	if (m.find(s) == m.end())cout << "Not Found" << endl;
//	else {
//		for (set<int>::iterator it = m[s].begin(); it != m[s].end(); it++) {
//			printf("%07d\n", *it);
//		}
//	}
//}
//
//int main() {
//	int n; scanf("%d", &n);
//	int id;
//	string t, a, k, p, y;
//	for (int i = 0; i < n; i++) {
//		scanf("%d%*c", &id);
//		getline(cin, t); T[t].insert(id);
//		getline(cin, a); A[a].insert(id);
//		while (cin >> k) {
//			K[k].insert(id);
//			if (getchar() == '\n')break;
//		}
//		getline(cin, p); P[p].insert(id);
//		getline(cin, y); Y[y].insert(id);
//	}
//	string temp;
//	int m; scanf("%d", &m);
//	int ch;
//	for (int i = 0; i < m; i++) {
//		scanf("%d: ", &ch);
//		getline(cin, temp);
//		cout << ch << ": " << temp << endl;
//		if (ch == 1)finding(T, temp);
//		else if (ch == 2)finding(A, temp);
//		else if (ch == 3)finding(K, temp);
//		else if (ch == 4)finding(P, temp);
//		else finding(Y, temp);
//	}
//
//	return 0;
//}