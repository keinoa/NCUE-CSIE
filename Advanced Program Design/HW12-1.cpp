#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct node
{
	string str;
	int num;
};

node longestPalindrome(string s)
{
	node a;
	string rig[100];
	string res = "";
	string temp = "";
	int c = 0;
	int length = s.size();
	a.num = 0;
	a.str = "";
	if (length == 1)
		return a;
	for (int i = 0; i < length; i++)
	{
		for (int j = i; j < length; j++)
		{
			temp = temp + s[j];
			string tem = temp;
			reverse(tem.begin(), tem.end());
			if (temp != tem || temp.size() < res.size())
				continue;
			if (res.size() <= temp.size())
			{
				res = temp;
				rig[c] = res;
				c++;
			}
		}
		a.num = res.size();
		temp = "";
	}
	if (res.size() == 1)
		return a;
	for (int i = 0; i < c; i++)
	{
		if (rig[i].size() >= rig[c - 1].size())
		{
			if (rig[i].size() < rig[c - 1].size())
				continue;
			if (a.str == "")
				a.str = rig[i];
			else
				a.str = a.str + ", " + rig[i];
		}
	}
	return a;
}

int main()
{

	string qua;
	node ans;
	while (cin >> qua)
	{
		ans = longestPalindrome(qua);
		if (ans.num == 1)
			cout << "0" << endl;
		else
		{
			cout << ans.num << " ";
			cout << ans.str << endl;
		}
	}
}
