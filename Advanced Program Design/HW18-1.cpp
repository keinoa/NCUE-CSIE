#include <iostream>
#include <string>

using namespace std;

struct node{
	string N[100], S[100];
	int rig, cnt, N_cnt, S_cnt;
};

string fuc( node qua, int size, int i, int j)
{
	string tmp;
	string ans[200];
	bool only = false;
	if (i <= 1 && j <= 1) only = true;
	while (true)
	{
		if (i <= 1 && j <= 1) break;
		else if (i > 1, j <= 1)
		{
			for (int k = 0; k < size; k++)
			{
				if (qua.N[k] == "") continue;
				else ans[k] += qua.N[k];
			}
			i--;
		}
		else if (i <= 1, j > 1)
		{
			for (int k = 0; k < size; k++)
			{
				if (qua.S[k] == "") continue;
				else ans[k] += qua.S[k];
			}
			j--;
		}
		else if (i > 1, j > 1)
		{
			for (int k = 0; k < size; k++)
			{
				if (qua.S[k] == "") ans[k] += qua.N[k];
				else ans[k] += qua.S[k];
			}
			i--;j--;
		}
	}
	if (only == false)
	{
		if (i == 0 && j == 1)
		{
			for (int k = 0; k < size; k++)
			{
				
				if (qua.S[k] == "") continue;
				else 
				{
					ans[k] += qua.S[k] ;
					tmp += ans[k];
				}
			}
		}
		else if (i == 1 && j == 0)
		{
			for (int k = 0; k < size; k++)
			{
				if (qua.S[k] == "")
				{
					ans[k] += qua.N[k] ;
					tmp += ans[k];	
				} 
				else continue;
			}
		}
		else
		{
			for (int k = 0; k < size; k++)
			{
				if (qua.S[k] == "")
					ans[k] += qua.N[k] ;
				else
					ans[k] += qua.S[k] ;
				tmp += ans[k];
			}	
		}
	}
	else
	{
		if (i == 0 && j == 1)
		{
			for (int k = 0; k < size; k++)
			{
				if (qua.S[k] == "") continue;
				else tmp += qua.S[k];
			}
		}
		else if (i == 1 && j == 0)
		{
			for (int k = 0; k < size; k++)
			{
				if (qua.S[k] == "") tmp += qua.N[k];
				else continue;
			}
		}
		else
		{
			for (int k = 0; k < size; k++)
			{
				if (qua.S[k] == "") tmp += qua.N[k];
				else tmp += qua.S[k];	
			}
		}
	}
	
	return tmp;		
}

int main()
{
	string qua;
	int num;
	cin >> qua >> num;
	node Qua;
	Qua.rig = 0;
	Qua.cnt = 1;
	/*~~~~~~~~~~~~~~~~~~~~~~~~存形式~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
	while (true)
	{
		if (Qua.rig >= qua.size())
			break;
		if (qua[Qua.rig] == '(')
		{
			Qua.rig++;
			string tmp = "";
			while (true)
			{
				tmp += qua[Qua.rig];
				Qua.rig++;
				if (qua[Qua.rig] == ')')
				{
					Qua.rig++;
					break;
				}
			}
			if (qua[Qua.rig] == '*')
			{
				Qua.S[Qua.cnt++] = tmp;
				Qua.S_cnt++;
			}
			else
			{
				Qua.N[Qua.cnt++] = tmp;
				Qua.N_cnt++;
			}
			Qua.rig++;	
		}
		else
		{
			string tmp = "";
			while (true)
			{
				tmp += qua[Qua.rig];
				Qua.rig++;
				if (qua[Qua.rig] == '*' || qua[Qua.rig] == 'n')
					break;
			}
			if (qua[Qua.rig] == '*')
			{
				Qua.S[Qua.cnt++] = tmp;
				Qua.S_cnt++;
			}
			else
			{
				Qua.N[Qua.cnt++] = tmp;
				Qua.N_cnt++;
			}
			Qua.rig++;		
		}
	}
	/*~~~~~~~~~~~~~~~~~~~~~~~~存形式~~~~~~~~~~~~~~~~~~~~~~~~~*/  
	
//	for (int i = 0; i < Qua.cnt; i++)
//	{
//		cout << ((Qua.N[i] == "")? Qua.S[i]: Qua.N[i]) << endl;
//	}
	
	/*~~~~~~~~~~~~~~~~~~~~~~~~計算~~~~~~~~~~~~~~~~~~~~~~~~~*/  
	for (int index = 0; index < num; index++)
	{
		string ans;
		cin >> ans;
		int ans_N, ans_star;
		bool end = false;
		string tmp = "";
		for (int i = 0;; i++)
		{
			int break_num = 0;
			for (int k = 0; k < Qua.cnt; k++)
			{
				if (Qua.N[k] == "") 
					continue;
				break_num += (i*Qua.N[k].size());
			}
			if (break_num > ans.size())
				break;
			for (int j = 0;; j++)
			{
				if (i == 0 && j == 0) continue;
				break_num = 0;
				for (int k = 0; k < Qua.cnt; k++)
				{
					if (Qua.N[k] == "") break_num += (j*Qua.S[k].size());
					else break_num += (i*Qua.N[k].size());
				}
				if (break_num > ans.size())
					break;
				tmp = fuc ( Qua, Qua.cnt, i, j);
//				cout << "tmp: " << tmp << ", " << "i: " << i << ", " << "j: " << j << endl;
				if (tmp == ans)
				{
					ans_N = i;
					ans_star = j;
					end = true;
					break;	
				} 
				if (tmp.size() >= ans.size())
					break;
			}
			if (end == true)
				break;
		}	
		if (end == true)
			cout << "Y" << " " << ans_N << " " << ans_star << endl;
		else
			cout << "N" << endl;	
	}
	/*~~~~~~~~~~~~~~~~~~~~~~~~計算~~~~~~~~~~~~~~~~~~~~~~~~~*/ 
}
