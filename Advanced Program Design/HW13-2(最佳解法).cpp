#include <iostream>

using namespace std;

struct cmp
{
	int arr[100];
	int rig, cnt0, cnt1;
};

struct node
{
	cmp ans[100];
};

int compare_max(node arr, int size, int i, int j)
{
	int m = 0;
	for (int index = 0, a = i + 1; index < j - i - 1; index++, a++)
	{
		int rig = arr.ans[i].arr[a] + arr.ans[a].arr[j] + arr.ans[i].rig * arr.ans[a].rig * arr.ans[j].rig;
		//		cout << rig << " ";
		if (rig > m)
			m = rig;
	}
	//	cout << endl;
	return m;
}

int compare_min(node arr, int size, int i, int j)
{
	int m = 999999;
	for (int index = 0, a = i + 1; index < j - i - 1; index++, a++)
	{
		int rig = arr.ans[i].arr[a] + arr.ans[a].arr[j] + arr.ans[i].rig * arr.ans[a].rig * arr.ans[j].rig;
		if (rig < m)
			m = rig;
	}
	return m;
}

node compute(node arr, int len, int size, bool sel)
{
	int ans;
	while (size <= len)
	{
		for (int i = 0; i < len - 2; i++)
		{
			for (int j = i + size - 1; j < len; j++)
			{
				if (j - i < size)
				{
					if (sel == true)
					{
						if (j - i == 3)
						{
							if ((arr.ans[i].arr[j - 1] + arr.ans[i].rig * arr.ans[i + size - 2].rig * arr.ans[i + size - 1].rig) > (arr.ans[i + 1].arr[j] + arr.ans[i].rig * arr.ans[i + 1].rig * arr.ans[i + size - 1].rig))
								arr.ans[i].arr[j] = arr.ans[i].arr[j - 1] + arr.ans[i].rig * arr.ans[i + size - 2].rig * arr.ans[i + size - 1].rig;
							else
								arr.ans[i].arr[j] = arr.ans[i + 1].arr[j] + arr.ans[i].rig * arr.ans[i + 1].rig * arr.ans[i + size - 1].rig;
						}
						else if (j - i >= 4)
						{
							arr.ans[i].arr[j] = compare_max(arr, size, i, j);
						}
					}
					else
					{
						if (j - i == 3)
						{
							if ((arr.ans[i].arr[j - 1] + arr.ans[i].rig * arr.ans[i + size - 2].rig * arr.ans[i + size - 1].rig) < (arr.ans[i + 1].arr[j] + arr.ans[i].rig * arr.ans[i + 1].rig * arr.ans[i + size - 1].rig))
								arr.ans[i].arr[j] = arr.ans[i].arr[j - 1] + arr.ans[i].rig * arr.ans[i + size - 2].rig * arr.ans[i + size - 1].rig;
							else
								arr.ans[i].arr[j] = arr.ans[i + 1].arr[j] + arr.ans[i].rig * arr.ans[i + 1].rig * arr.ans[i + size - 1].rig;
						}
						else if (j - i >= 4)
						{
							arr.ans[i].arr[j] = compare_min(arr, size, i, j);
						}
					}
				}
				else
					break;
			}
		}
		size++;
	}
	ans = arr.ans[0].arr[len - 1];
	return arr;
}

int main()
{
	cmp qua;
	//	while( cin >> qua.cnt0 )
	//	{
	cin >> qua.cnt0;
	for (int index = 0; index < qua.cnt0; index++)
	{
		cin >> qua.cnt1;
		int len = qua.cnt1;
		node arr;
		for (int i = 0; i < len; i++)
			cin >> arr.ans[i].rig;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (j - i < 2)
					arr.ans[i].arr[j] = 0;
				else if (j - i < 3)
					arr.ans[i].arr[j] = arr.ans[i].rig * arr.ans[i + 1].rig * arr.ans[i + 2].rig;
				else
					break;
			}
		}
		int size = 4, max, min;
		bool sel = true;
		arr = compute(arr, len, size, sel);
		max = arr.ans[0].arr[len - 1];
					cout << "---------------------- max Test_line----------------------" << endl;
					for( int i = 0 ; i < len ; i++ )
					{
						cout << "J" << i << " : " ;
						for( int j = 0 ; j < len ; j++ )
						{
							cout << arr.ans[i].arr[j] << " " ;
						}
						cout << endl;
					}
					cout << "---------------------- max Test_line----------------------" << endl;
		sel = false;
		arr = compute(arr, len, size, sel);
		min = arr.ans[0].arr[len - 1];
					cout << "---------------------- min Test_line----------------------" << endl;
					for( int i = 0 ; i < len ; i++ )
					{
						cout << "J" << i << " : " ;
						for( int j = 0 ; j < len ; j++ )
						{
							cout << arr.ans[i].arr[j] << " " ;
						}
						cout << endl;
					}
					cout << "---------------------- min Test_line----------------------" << endl;
		cout << max << " " << min << endl;
	}
	//	}
}
