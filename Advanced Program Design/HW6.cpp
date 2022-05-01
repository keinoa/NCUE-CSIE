#include <iostream>
#include <string>
using namespace std;
int node(string data)
{
	if (data == "1B")
		return 1;
	else if (data == "2B")
		return 2;
	else if (data == "3B")
		return 3;
	else if (data == "HR")
		return 4;
	else
		return 0;
}
int main()
{
	bool base[4];
	int x[9][100], fail;
	string debug;
	int counter, win;
	for (int i = 0; i < 9; i++)
	{
		cin >> fail;
		for (int j = 0; j < fail; j++)
		{
			cin >> debug;
			x[i][j] = node(debug);
		}
	}
	cin >> fail;
	win = 0;
	counter = 0;
	for (int i = 1; i < 4; i++)
		base[i] = 0;
	for (int j = 0; j < 100 && counter < fail; j++)
	{
		for (int i = 0; i < 9 && counter < fail; i++)
		{
			if (x[i][j] == 1)
			{
				if (base[3] == 1)
				{
					win++;
					base[3] = 0;
				}
				if (base[2] == 1)
				{
					base[3] = base[2];
					base[2] = 0;
				}
				if (base[1] == 1)
					base[2] = base[1];
				base[1] = 1;
			}
			else if (x[i][j] == 2)
			{
				if (base[3] == 1)
					win++;
				if (base[2] == 1)
					win++;
				for (int i = 2; i < 4; i++)
					base[i] = 0;
				if (base[1] == 1)
				{
					base[3] = base[1];
					base[1] = 0;
				}
				base[2] = 1;
			}
			else if (x[i][j] == 3)
			{
				if (base[3] == 1)
					win++;
				if (base[2] == 1)
					win++;
				if (base[1] == 1)
					win++;
				for (int i = 1; i < 3; i++)
					base[i] = 0;
				base[3] = 1;
			}
			else if (x[i][j] == 4)
			{
				if (base[3] == 1)
					win++;
				if (base[2] == 1)
					win++;
				if (base[1] == 1)
					win++;
				for (int i = 1; i < 4; i++)
					base[i] = 0;
				win++;
			}
			else
			{
				counter++;
				if (counter % 3 == 0)
				{
					for (int i = 1; i < 4; i++)
						base[i] = 0;
				}
			}
		}
	}
	cout << win << endl;
}
