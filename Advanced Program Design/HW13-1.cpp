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

int compare_max(node arr, int i, int j)
{
	int m = 0;
	for (int index = 0, a = i + 1; index < j - i - 1; index++, a++)
	{
		int rig = arr.ans[i].arr[a] + arr.ans[a].arr[j] + arr.ans[i].rig * arr.ans[a].rig * arr.ans[j].rig;
		if (rig > m)
			m = rig;
	}
	return m;
}

int compare_min(node arr, int i, int j)
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
	while (size <= len)
	{
		for (int i = 0; i < len - 2; i++)
		{
			for (int j = i + size - 1; j < len; j++)
			{
				if (j - i < size)
				{
					if (sel == true)
						arr.ans[i].arr[j] = compare_max(arr, i, j);
					else
						arr.ans[i].arr[j] = compare_min(arr, i, j);
				}
				else
					break;
			}
		}
		size++;
	}
	return arr;
}

int main()
{
	cmp qua;
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
		arr = compute(arr, len, size, true);
		max = arr.ans[0].arr[len - 1];
		arr = compute(arr, len, size, false);
		min = arr.ans[0].arr[len - 1];
		cout << max << " " << min << endl;
	}
}
