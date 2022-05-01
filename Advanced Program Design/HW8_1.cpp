#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	int count1, count2, ans;
	while (cin >> count1)
	{
		for (int i = 0; i < count1; i++)
		{
			cin >> count2;
			int x[30000], y[30000], area[30000];
			for (int j = 0; j < count2; j++)
			{
				cin >> x[j] >> y[j];
				area[j] = x[j] * y[j];
				if (x[j] > y[j])
					swap(x[j], y[j]);
			}
			for (int j = count2 - 1; j > 0; j--)
			{
				for (int k = 0; k <= j - 1; k++)
				{
					if (area[k] > area[k + 1])
					{
						swap(x[k], x[k + 1]);
						swap(y[k], y[k + 1]);
						swap(area[k], area[k + 1]);
					}
				}
			}
			int cmp = 0;
			for (int j = 1; j < count2; j++)
			{
				ans = 1;
				int r1 = x[j], r2 = y[j];
				for (int k = j - 1; k >= 0; k--)
				{
					if (r1 >= x[k] && r2 >= y[k])
					{
						r1 = x[k];
						r2 = y[k];
						ans++;
					}
				}
				if (cmp < ans)
					cmp = ans;
			}
			cout << cmp << endl;
		}
	}
}
