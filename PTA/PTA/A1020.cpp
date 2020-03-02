#include<iostream>
#include<vector>
using namespace std;

const int N = 30;
int postOrder[N], inOrder[N], levelOrder[N];

struct Node {
	Node * left = NULL, * right = NULL;
	int val;
};

void parse(int ps, int is, int size, Node * root)
{
	int rootI = ps + size - 1;
	root->val = postOrder[rootI];
	for (int i = 0; i < size; i++)
	{
		if (inOrder[is + i] == root->val)
		{
			rootI = is + i;
			break;
		}
	}
	int leftsize = rootI - is, rightsize = size - rootI + is - 1;
	if (leftsize > 0)
	{
		root->left = new Node();
		parse(ps, is, leftsize, root->left);
	}
	if (rightsize > 0)
	{
		root->right = new Node();
		parse(ps + rootI - is, rootI + 1, rightsize, root->right);
	}
}

void getLevelOrder(Node * root)
{
	int next = 0, length = 0, count = 0;
	Node *queue[N];
	queue[next++] = root;
	length++;
	while (length > 0)
	{
		int pos = next - length, size = length;
		for (int i = 0; i < size; i++)
		{
			levelOrder[count++] = queue[pos + i]->val;
			length--;
			if (queue[pos + i]->left != NULL)
			{
				queue[next++] = queue[pos + i]->left;
				length++;
			}
			if (queue[pos + i]->right != NULL)
			{
				queue[next++] = queue[pos + i]->right;
				length++;
			}
		}
	}
}

void deleteTree(Node * root)
{
	if (root == NULL) return;
	deleteTree(root->left);
	deleteTree(root->right);
	delete root;
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> postOrder[i];
	for (int i = 0; i < n; i++)
		cin >> inOrder[i];
	Node * root = new Node();;
	parse(0, 0, n, root);
	getLevelOrder(root);
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
			cout << levelOrder[i];
		else
			cout << ' ' << levelOrder[i];
	}
	deleteTree(root);
	return 0;
}