#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// S0831037

int main()
{
	string max, min;
	int star;
	while (cin >> max >> min >> star)
	{
		star += 64;
		if (max.size() < min.size())
			swap(max, min);
		int n = max.size(), m = min.size();
		int arr[200][200];
		int compare[200][200];

		for (int i = 0; i <= n; i++)
			for (int j = 0; j <= m + 1; j++)
			{
				arr[i][j] = 0;
				compare[i][j] = 1;//總共幾個 
			}

		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= i && j <= n; j++)
			{
				if (i == j)
					for (int k = 1; k <= i; k++)
						arr[i][j] += abs(max[k - 1] - min[k - 1]);
				else if (i >= j && (i-j) <= (n-m))
				{
					int rig0 = arr[i - 1][j - 1] + abs(max[i - 1] - min[j - 1]);
					int rig1 = arr[i - 1][j] + abs(star - max[i - 1]);
					if (j != 0)
					{
						if( rig0 > rig1 )
							arr[i][j] = rig0;
						else
							arr[i][j] = rig1;
							
						if ( rig0 < rig1 )
							compare[i][j] = compare[i - 1][j];
						else if ( rig0 > rig1 )
							compare[i][j] = compare[i - 1][j - 1];
						else 
							compare[i][j] = compare[i - 1][j - 1] + compare[i - 1][j];
					}
					else
						arr[i][j] = rig1;
				}
			}
		}
//		cout << "-------------------------test---------------------------" << endl;
//		for (int i = 0; i <= n; i++)
//		{
//			for (int j = 0; j <= m; j++)
//			{
//				cout << arr[i][j] << " ";
//			}
//			cout << endl;
//		}
//		cout << "-------------------------test---------------------------" << endl;
		cout << arr[n][m] << " " << compare[n][m] << endl;
	}
}
