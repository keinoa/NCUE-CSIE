#include <iostream>
#include <string>
using namespace std;
string fuc(int y)
{
	string last = "0000";
	int S_BOX[4][16] =
		{
			{14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7},
			{0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8},
			{4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0},
			{15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13}};
	int x[6];
	int z = 3;
	int c[4];
	x[5] = y / 100000;
	x[4] = (y / 10000) % 10;
	x[3] = (y / 1000) % 10;
	x[2] = (y / 100) % 10;
	x[1] = (y / 10) % 10;
	x[0] = y % 10;
	int a = x[5] * 2 + x[0];
	int b = x[4] * 2 * 2 * 2 + x[3] * 2 * 2 + x[2] * 2 + x[1];
	for (int i = 0; S_BOX[a][b] > 0; i++)
	{
		if (S_BOX[a][b] == 0)
		{
			break;
		}
		c[i] = S_BOX[a][b] % 2;
		S_BOX[a][b] = S_BOX[a][b] / 2;
		if (c[i] == 0)
		{
			last[z] = '0';
		}
		else if (c[i] == 1)
		{
			last[z] = '1';
		}
		z--;
	}
	return last;
}
int main()
{
	int x;
	string ans;
	while (cin >> x)
	{
		ans = fuc(x);
		cout << ans << endl;
	}
}
