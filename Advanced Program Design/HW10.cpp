#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

typedef struct fuc
{
	string animal, local;
	int num;
} fuc;

fuc a[1000];

int main()
{
	int count;
	cin >> count;
	for (int i = 0; i < count; i++)
		cin >> a[i].animal >> a[i].num >> a[i].local;
	for (int i = 0; i < count; i++)
	{
		int r;
		for (int j = i + 1; j < count; j++)
		{
			if (a[i].animal == "")
				continue;
			if (a[i].animal == a[j].animal && a[i].local == a[j].local)
			{
				a[i].num += a[j].num;
				a[j].animal = "";
				a[j].local = "";
			}
		}
	}
	for (int i = 0; i < count; i++)
	{
		if (a[i].animal == "")
			continue;
		cout << a[i].local << " : ";
		cout << a[i].animal << " " << a[i].num;
		for (int j = i + 1; j < count; j++)
		{
			if (a[j].animal == "")
				continue;
			if (a[i].local == a[j].local)
			{
				if (i == 0)
				{
					cout << ", " << a[j].animal << " " << a[j].num;
					a[j].animal = "";
					a[j].local = "";
				}
				else
				{
					cout << ", " << a[j].animal << " " << a[j].num;
					a[j].animal = "";
					a[j].local = "";
				}
			}
		}
		cout << endl;
	}
}
