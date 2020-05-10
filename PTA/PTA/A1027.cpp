#include<iostream>
#include<string>

using namespace std;

char base13[13] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C' };

string toBase13(int dec)
{
	if (dec == 0) return "00";
	string result = "";
	while (dec > 0)
	{
		int temp = dec % 13;
		result = base13[temp] + result;
		dec /= 13;
	}
	return result.length() > 1 ? result : '0' + result;
}

int main()
{
	int r, g, b;
	cin >> r >> g >> b;
	cout << "#" << toBase13(r) << toBase13(g) << toBase13(b) << endl;
	return 0;
}