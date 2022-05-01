#include <iostream>
#include <string>
#include <math.h>
using namespace std;
int main()
{
	int counter = 0, total = 0;
	string x, y;
	cin >> counter;
	int sum[counter];
	for (int i = 0; i < counter; i++)
	{
		cin >> x;
		cin >> y;
		int size_x = x.size();
		sum[i] = 0;
		for (int j = 0; j < size_x; j++)
		{
			total = x[j] - y[j];
			if (total < 0)
			{
				total *= (-1);
			}
			sum[i] += total;
		}
	}
	for (int i = 0; i < counter; i++)
	{
		cout << sum[i] << endl;
	}
}
