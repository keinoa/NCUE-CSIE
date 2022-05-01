#include <iostream>
#include <string>

using namespace std;

struct node
{
    string str;
    char c;
};

int main()
{
    node qua[100];
    int qua_len = 0;
    int N_len = 0, S_len = 0;
    string qua_type = "", rig = "";
    
    cin >> qua_type;
    for (int i = 0; i < qua_type.size(); i++)
    {
        if (qua_type[i] == '*' || qua_type[i] == 'n')
        {
            qua[qua_len].str = rig; //text
            qua[qua_len].c = qua_type[i]; //sign
            if (qua[qua_len].c == '*')
	            S_len += qua[qua_len++].str.size();
	        else // == 'n'
	            N_len += qua[qua_len++].str.size();
            rig.clear();
            continue;
        }
        else if (qua_type[i] == '(' || qua_type[i] == ')')
        {
            continue;
        }
        rig += qua_type[i];
    }
    
    cout << N_len << endl;
	cout << S_len << endl;
    
    string cmp;
    string ans;
    int num;
    int N_ans_cnt, S_ans_cnt;
    
    cin >> num;
    for (int index = 0; index < num; index++)
    {
    	bool end = false;
        cin >> cmp;

        int tmp = cmp.size() - N_len;
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
            for (int j = 0; j < qua_len; j++)
            {
                if (qua[j].c == 'n')
                    for (int k = 0; k < N_ans_cnt; k++)
                        ans += qua[j].str;
                else // == '*'
                    for (int k = 0; k < S_ans_cnt; k++)
                        ans += qua[j].str;
            }
//            cout << "ans: " << ans << endl; 
            if (ans == cmp)
            {
                cout << "Y" << " " << N_ans_cnt << " " << S_ans_cnt << endl;
                end = true;
                break;
            }
        }
        if (!end)
        {
            cout << "N" << endl;
        }
    }
}
