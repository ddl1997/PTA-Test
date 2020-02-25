#include<iostream>

using namespace std;

struct Result {
	bool re;
	Result * next = NULL;;
};

int reverse(int n, int d)
{
	int out = 0;
	while (n > 0)
	{
		out *= d;
		out += n % d;
		n /= d;
	}
	return out;
}

bool isPrime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i <= n / 2; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	Result * head = new Result();
	head->next = new Result();
	Result * next = head->next;
	int n, d;
	scanf("%d", &n);
	while (n > 0)
	{
		scanf("%d", &d);
		int re = reverse(n, d);
		next->re =  isPrime(n) && isPrime(re);
		next->next = new Result();
		next = next->next;
		scanf("%d", &n);
	}
	next = head->next;
	while (true)
	{
		if (next->next == NULL)
		{
			delete next;
			break;
		}
		if (next->re)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
		Result * temp = next->next;
		delete next;
		next = temp;
	}
	delete head;
	return 0;
}