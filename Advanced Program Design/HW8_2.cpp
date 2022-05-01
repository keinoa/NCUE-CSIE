#include <iostream>
#include <algorithm>
using namespace std;
typedef struct node
{
	int x, y, area;
} node;

node qua[50000];

int main()
{
	int count1, count2, ans;
	while (cin >> count1)
	{
		for (int i = 0; i < count1; i++)
		{
			cin >> count2;
			for (int j = 0; j < count2; j++)
			{
				cin >> qua[j].x >> qua[j].y;
				qua[j].area = qua[j].x * qua[j].y;
				if (qua[j].x > qua[j].y)
				{
					swap(qua[j].x, qua[j].y);
				}
			}
			for (int j = count2 - 1; j > 0; j--)
			{
				for (int k = 0; k <= j - 1; k++)
				{
					if (qua[k].area > qua[k + 1].area)
					{
						swap(qua[k].x, qua[k + 1].x);
						swap(qua[k].y, qua[k + 1].y);
						swap(qua[k].area, qua[k + 1].area);
					}
				}
			}
			//�ݼg�P�_
			int debug = 0;
			for (int j = 1; j < count2; j++)
			{
				ans = 1;
				int r1 = qua[j].x, r2 = qua[j].y;
				bool a = true, b = true;
				for (int k = j - 1; k >= 0; k--)
				{
					if (r1 >= qua[k].x && r2 >= qua[k].y)
					{
						r1 = qua[k].x;
						r2 = qua[k].y;
						ans++;
					}
				}
				if (debug < ans)
					debug = ans;
			}
			cout << debug << endl;
		}
	}
}
