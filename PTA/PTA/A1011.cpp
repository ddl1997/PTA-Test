#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	double m[3] = {0, 0, 0};
	char its[3];
	char select[3] = {'W', 'T', 'L'};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			double temp;
			cin >> temp;
			if (m[i] < temp)
			{
				m[i] = temp;
				its[i] = select[j];
			}
		}
	}
	double profit = (m[0] * m[1] * m[2] * 0.65 - 1) * 2;
	cout << its[0] << " " << its[1] << " " << its[2] << " " << setiosflags(ios::fixed) << setprecision(2) << profit;
	//cin >> m[0];
	return 0;
}
