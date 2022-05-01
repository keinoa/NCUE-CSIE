#include <iostream>
#include <string>

using namespace std;

struct node
{
	int size;
	string str;
};

node fuc(string s)
{
	int len = s.length();
	int index, maxL = 0, begin = 0, c = 0;
	string rig[500];
	node ans;
	for (index = 0; index < len; index++)
	{
		int right = index, left = index;
		if (index + 1  < len)
			while (index < len && s[index + 1] == s[index])
			{
				index++;
				right++;
			}
		while (right < len && left >= 0 && s[right] == s[left])
		{
			right++;
			left--;
		}
		right--, left++;
		if (right - left + 1 >= maxL)
		{
			maxL = right - left + 1;
			begin = left;
			rig[c] = s.substr(begin, maxL);
			c++;
		}
	}
	ans.size = s.substr(begin, maxL).size();
	for (index = 0; index < c; index++)
	{
		if (rig[c - 1].size() > rig[index].size())
			continue;
		if (index == c - 1)
			ans.str += rig[index];
		else
			ans.str = ans.str + rig[index] + ", ";
	}
	return ans;
}

int main()
{
	string qua;
	while (cin >> qua)
	{
		if (qua.size() == 1)
		{
			cout << "0" << endl;
			continue;
		}
		node ans = fuc(qua);
		if (ans.size == 1)
		{
			cout << "0" << endl;
			continue;
		}
		cout << ans.size << " " << ans.str << endl;
	}
}
