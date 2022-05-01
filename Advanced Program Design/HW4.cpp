#include <iostream>
#include <algorithm>

using namespace std;

typedef struct value
{
	int x;
	int y;
} Value;

bool fuc(Value a, Value b)
{
	if (a.x == b.x)
		return (a.y > b.y);
	else
		return (a.x < b.x);
}

Value num[10000];

int main()
{
	int counter, sum, little, big;
	while (cin >> counter)
	{
		sum = 0;
		for (int i = 0; i < counter; i++)
		{
			cin >> num[i].x;
			cin >> num[i].y;
		}
		sort(num, num + counter, fuc);
		for (int i = 0; i < counter; i++)
		{
			little = num[i].x;
			big = num[i].y;
			while ((i + 1) < counter && num[i + 1].x < big)
			{
				if (num[i + 1].y <= big)
					i++;
				else
				{
					big = num[i + 1].y;
					i++;
				}
			}
			sum = sum + big - little;
		}
		cout << sum << endl;
	}
}
