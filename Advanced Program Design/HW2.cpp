#include <iostream>

using namespace std;

int fuc(int LowerBound, int UpperBound)
{
	int i = 0;
	int sum = 0;
	int ct[1000];
	ct[0] = LowerBound;
	sum = LowerBound;
	if (sum == 1)
	{
		return 1;
	}
	while (true)
	{
		if (ct[i] % 2 == 0)
		{
			ct[i + 1] = ct[i] / 2;
			sum += ct[i + 1];
		}
		else
		{
			ct[i + 1] = ct[i] * 3 + 1;
			sum += ct[i + 1];
		}
		if (ct[i + 1] == 1)
		{
			return sum;
		}
		i++;
	}
}
int main()
{
	int counter = 0;
	int RAM = 0, last = 0;
	cin >> counter;
	int LowerBound[counter];
	int UpperBound[counter];
	for (int i = 0; i < counter; i++)
	{
		cin >> LowerBound[i] >> UpperBound[i];
	}
	for (int i = 0; i < counter; i++)
	{
		for (int j = LowerBound[i]; j <= UpperBound[i]; j++)
		{
			if (RAM < fuc(j, UpperBound[i]))
			{
				RAM = fuc(j, UpperBound[i]);
				last = j;
			}
		}
		cout << RAM << "  " << last << endl;
		RAM = 0;
	}
}
