#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	size_t a, b;
	double num, sqrt_num;
	while (cin >> a >> b)
	{
		int counter = 0;
		for (int i = a; i < b; i++)
		{
			for (int j = i + 1; j < b; j++)
			{
				num = pow(i, 2) + pow(j, 2);
				sqrt_num = sqrt(num);
				if (num > pow(b, 2))
					break;
				if ((int)sqrt_num == sqrt_num)
					counter++;
			}
		}
		cout << counter << endl;
	}
}
