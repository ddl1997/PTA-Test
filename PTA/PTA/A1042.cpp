#include<iostream>
#include<string>

using namespace std;

string cards[54] = {"S1", "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "S10", "S11", "S12", "S13",
					"H1", "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "H10", "H11", "H12", "H13", 
					"C1", "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "C10", "C11", "C12", "C13", 
					"D1", "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "D10", "D11", "D12", "D13", 
					"J1", "J2"};

int trans[54];
int deck[54];

void shuffle()
{
	int temp[54];
	for (int i = 0; i < 54; i++)
	{
		temp[trans[i] - 1] = deck[i];
	}
	/*for (int i = 0; i < 54; i++)
	{
		deck[i] = temp[i];
	}*/
	copy(begin(temp), end(temp), begin(deck));
	// memcpy memmove std::copy std::array
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 54; i++)
	{
		cin >> trans[i];
		deck[i] = i;
	}
	for (int i = 0; i < n; i++)
	{
		shuffle();
	}
	for (int i = 0; i < 54; i++)
	{
		if (i == 0)
			cout << cards[deck[i]];
		else
			cout << " " + cards[deck[i]];
	}

	return 0;
}