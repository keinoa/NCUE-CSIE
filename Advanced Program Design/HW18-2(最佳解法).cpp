#include <iostream>
#include <string>

using namespace std;

struct node
{
    string str;
	char sign;
};

int main()
{
	string qua_type;
	int num;
	cin >> qua_type >> num;
	
	node transfer[100];
	string rig = "";
	int S_len = 0, N_len = 0;
	int len = 0;
	for (int i = 0; i < qua_type.size(); i++)
	{
		if (qua_type[i] == '*' || qua_type[i] == 'n')
		{
			transfer[len].str = rig;
			transfer[len].sign = qua_type[i];
			if (transfer[len].sign == '*')
				S_len += transfer[len++].str.size();
			else
				N_len += transfer[len++].str.size(); 
			rig.clear();
			continue;	
		}
		if (qua_type[i] == '(' || qua_type[i] == ')')
			continue;
		rig += qua_type[i];
	}
	
//	for (int i = 0; i < len; i++)
//	{
//		cout << transfer[i].str << " ";
//	}
//	cout << endl;
//	for (int i = 0; i < len; i++)
//	{
//		cout << transfer[i].sign << " ";
//	}
//	cout << endl;
//	cout << N_len << endl;
//	cout << S_len << endl;

	int N_ans_cnt, S_ans_cnt;
	string cmp, ans;
	
	for (int index = 0; index < num; index++)
	{
		bool end = false;
		cin >> cmp;
		int tmp = cmp.size() - N_len; // N >= 1 
		for (int i = 1; tmp >= 0; i++)
		{
			ans.clear();
			if ((cmp.size() - N_len * i) % S_len == 0)
			{
				N_ans_cnt = i;
				S_ans_cnt = (cmp.size() - N_len * i) / S_len;
			}
			else
			{
				tmp = cmp.size() - N_len * (i + 1);
				continue;
			}
			for (int j = 0; j < len; j++)
			{
				if (transfer[j].sign == 'n')
					for (int k = 0; k < N_ans_cnt; k++)
						ans += transfer[j].str;
				else
					for (int k = 0; k < S_ans_cnt; k++)
						ans += transfer[j].str;
			}
			if (ans == cmp)
			{
				end = true;
				break;
			}
		}
		((!end) ? (cout << "N" << endl) : (cout << "Y" << " " << N_ans_cnt << " " << S_ans_cnt << endl));
	}
}
