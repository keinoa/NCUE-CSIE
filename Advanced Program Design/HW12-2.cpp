#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	string qua;
	while (cin >> qua)
	{
		int c = 0;
		string rig[100];
		string res = "", temp = "", tem = "";
		reverse(tem.begin(), tem.end());
		if (qua == tem)
		{
			cout << qua.size() << " " << qua << endl;
			continue;
		}
		for (int i = 0; i < qua.size(); i++)
		{
			if (res.size() > qua.size() - i)
				break;
			for (int j = i; j < qua.size(); j++)
			{
				temp = temp + qua[j];
				tem = temp;
				reverse(tem.begin(), tem.end());
				if (temp != tem || temp.size() < res.size())
					continue;
				if (res.size() <= temp.size())
				{
					res = temp;
					rig[c] = temp;
					c++;
				}
			}
			temp = "";
		}
		if (res.size() == 1)
		{
			cout << "0" << endl;
			continue;
		}
		cout << res.size() << " ";
		for (int i = 0; i < c; i++)
		{
			if (rig[i].size() < rig[c - 1].size())
				continue;
			if (i == c - 1)
				cout << rig[i] << endl;
			else
				cout << rig[i] << ", ";
		}
	}
}
