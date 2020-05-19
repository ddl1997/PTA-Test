#include<iostream>
#include<vector>

using namespace std;

const int N = 1001;

int n;
int preorder[N];

bool normal_cmp(int a, int b)
{
	return a < b;
}

bool mi_cmp(int a, int b)
{
	return a >= b;
}

bool isbst(int start, int end, bool (* cmp)(int, int))
{
	if (start >= end)
		return true;
	int right = start + 1;
	while (right <= end && cmp(preorder[right], preorder[start])) right++;
	int i = right;
	while (i <= end)
	{
		if (cmp(preorder[i], preorder[start])) return false;
		i++;
	}
	return isbst(start + 1, right - 1, cmp) && isbst(right, end, cmp);
}

vector<int> get_postorder(int start, int end, bool(*cmp)(int, int))
{
	vector<int> postorder;
	if (start > end);
	else if (start == end)
	{
		postorder.push_back(preorder[start]);
	}
	else
	{
		int right = start + 1;
		while (right <= end && cmp(preorder[right], preorder[start])) right++;
		auto left_order = get_postorder(start + 1, right - 1, cmp);
		auto right_order = get_postorder(right, end, cmp);
		int lsize = left_order.size(), rsize = right_order.size();
		for (int i = 0; i < lsize; i++)
		{
			postorder.push_back(left_order[i]);
		}
		for (int i = 0; i < rsize; i++)
		{
			postorder.push_back(right_order[i]);
		}
		postorder.push_back(preorder[start]);
	}
	return postorder;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		scanf("%d", &preorder[i]);
	if (isbst(0, n - 1, normal_cmp))
	{
		cout << "YES" << endl;
		auto order = get_postorder(0, n - 1, normal_cmp);
		int size = order.size();
		for (int i = 0; i < size; i++)
		{
			if (i < size - 1)
				printf("%d ", order[i]);
			else
				printf("%d\n", order[i]);
		}
	}
	else if (isbst(0, n - 1, mi_cmp))
	{
		cout << "YES" << endl;
		auto order = get_postorder(0, n - 1, mi_cmp);
		int size = order.size();
		for (int i = 0; i < size; i++)
		{
			if (i < size - 1)
				printf("%d ", order[i]);
			else
				printf("%d\n", order[i]);
		}
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}