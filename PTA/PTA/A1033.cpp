#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct Station{
	double distance, price;
	Station(double d, double p)
	{
		distance = d;
		price = p;
	}
};

double cmax, d, davg;
int n;
vector<Station> stations;

bool cmp_d(Station a, Station b)
{
	return a.distance < b.distance;
}

int findNextCheaper(int pos, int end)
{
	int cheaper = pos + 1;
	bool foundCheaper = false;
	while (cheaper < end)
	{
		if (stations[cheaper].price <= stations[pos].price)
		{
			foundCheaper = true; break;
		}
		cheaper++;
	}
	return foundCheaper ? cheaper : -1;
}

double calculateCost(int start, int end, double remain)
{
	if (start == end) return 0.0;
	int pos = start, nextPos = findNextCheaper(pos, end);
	if (remain == 0)
	{
		if (nextPos < 0)
		{
			if (stations[end].distance - stations[pos].distance < cmax * davg)
			{
				return (stations[end].distance - stations[pos].distance) / davg * stations[pos].price;
			}
			else
			{
				remain = cmax - (stations[pos + 1].distance - stations[pos].distance) / davg;
				return cmax * stations[pos].price + calculateCost(pos + 1, end, remain);
			}
		}
		else
		{
			if (stations[nextPos].distance - stations[pos].distance < cmax * davg)
			{
				return (stations[nextPos].distance - stations[pos].distance) / davg * stations[pos].price + calculateCost(nextPos, end, 0);
			}
			else
			{
				remain = cmax - (stations[pos + 1].distance - stations[pos].distance) / davg;
				return cmax * stations[pos].price + calculateCost(pos + 1, nextPos, remain) + calculateCost(nextPos, end, 0);
			}
		}
	}
	else
	{
		if (nextPos < 0)
		{
			if (stations[end].distance - stations[pos].distance <= cmax * davg)
			{
				double lackGas = (stations[end].distance - stations[pos].distance) / davg - remain;
				return lackGas * stations[pos].price;
			}
			else
			{
				double curCost = (cmax - remain) * stations[pos].price;
				remain = cmax - (stations[pos + 1].distance - stations[pos].distance) / davg;
				return curCost + calculateCost(pos + 1, end, remain);
			}
		}
		else
		{
			if (stations[nextPos].distance - stations[pos].distance <= remain * davg)
			{
				remain = remain - (stations[nextPos].distance - stations[pos].distance) / davg;
				return calculateCost(nextPos, end, remain);
			}
			else if (stations[nextPos].distance - stations[pos].distance <= cmax * davg)
			{
				double lackGas = (stations[nextPos].distance - stations[pos].distance) / davg - remain;
				return lackGas * stations[pos].price + calculateCost(nextPos, end, 0);
			}
			else
			{
				double curCost = (cmax - remain) * stations[pos].price;
				remain = cmax - (stations[pos + 1].distance - stations[pos].distance) / davg;
				return curCost + calculateCost(pos + 1, nextPos, remain) + calculateCost(nextPos, end, 0);
			}
		}
	}
}

int main()
{
	cin >> cmax >> d >> davg >> n;
	for (int i = 0; i < n; i++)
	{
		double dist, price;
		cin >> price >> dist;
		Station s(dist, price);
		stations.push_back(s);
	}
	Station dest(d, 0.0);
	stations.push_back(dest);
	sort(stations.begin(), stations.end(), cmp_d);
	if (stations[0].distance > 0)
	{
		cout << "The maximum travel distance = 0.00" << endl;
		return 0;
	}
	double maxLength = cmax * davg;
	for (int i = 0; i < n; i++)
	{
		if (stations[i + 1].distance - stations[i].distance > maxLength)
		{
			printf("The maximum travel distance = %.2f", stations[i].distance + maxLength);
			return 0;
		}
	}
	printf("%.2f", calculateCost(0, n, 0));
	return 0;
}
