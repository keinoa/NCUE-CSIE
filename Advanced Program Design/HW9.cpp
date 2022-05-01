#include <iostream>
using namespace std;
int main()
{
	int r, c;
	int can = 0, cant = 0;
	cin >> r >> c;
	int qua[1000][20];
	bool cmp[1000][20];
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cmp[i][j] = false;
			cin >> qua[i][j];
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (qua[i][j] == 5 || qua[i][j] == -1)
			{
				if (qua[i - 1][j - 1] == 5)
				{
					qua[i][j] = -1;
					qua[i - 1][j - 1] = -1;
				}
				if (qua[i - 1][j] == 5)
				{
					qua[i][j] = -1;
					qua[i - 1][j] = -1;
				}
				if (qua[i][j - 1] == 5)
				{
					qua[i][j] = -1;
					qua[i][j - 1] = -1;
				}
				if (qua[i + 1][j + 1] == 5)
				{
					qua[i][j] = -1;
					qua[i + 1][j + 1] = -1;
				}
				if (qua[i + 1][j - 1] == 5)
				{
					qua[i][j] = -1;
					qua[i + 1][j - 1] = -1;
				}
				if (qua[i - 1][j + 1] == 5)
				{
					qua[i][j] = -1;
					qua[i - 1][j + 1] = -1;
				}
				if (qua[i + 1][j] == 5)
				{
					qua[i][j] = -1;
					qua[i + 1][j] = -1;
				}
				if (qua[i][j + 1] == 5)
				{
					qua[i][j] = -1;
					qua[i][j + 1] = -1;
				}
			}
		}
	}
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (qua[i][j] == 5)
			{
				if (i - 1 >= 0 && j - 1 >= 0)
					cmp[i - 1][j - 1] = true;
				if (i - 1 >= 0)
					cmp[i - 1][j] = true;
				if (j - 1 >= 0)
					cmp[i][j - 1] = true;
				if (i + 1 < r && j + 1 < c)
					cmp[i + 1][j + 1] = true;
				if (i + 1 < r && j - 1 >= 0)
					cmp[i + 1][j - 1] = true;
				if (i - 1 >= 0 && j + 1 < c)
					cmp[i - 1][j + 1] = true;
				if (i + 1 < r)
					cmp[i + 1][j] = true;
				if (j + 1 < c)
					cmp[i][j + 1] = true;
			}
		}
	}
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	//	cout << endl;
	//	for( int i = 0 ; i < r ; i++ )
	//	{
	//		cout << "qua : ";
	//		for( int j = 0 ; j < c ; j++ )
	//		{
	//			cout << qua[i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	//	for( int i = 0 ; i < r ; i++ )
	//	{
	//		cout << "cmp : ";
	//		for( int j = 0 ; j < c ; j++ )
	//		{
	//			cout << cmp[i][j] << " ";
	//		}
	//		cout << endl;
	//	}
	//	cout << endl;
	/*~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (cmp[i][j] == 1 && qua[i][j] == 1)
				can++;
			else if (cmp[i][j] == false && qua[i][j] == 1)
				cant++;
		}
	}
	cout << can << " " << cant << endl;
}
