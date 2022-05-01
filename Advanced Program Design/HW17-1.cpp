#include <iostream>

using namespace std;

struct node
{
    int st[1000];
    int pf[1000];
};

int main()
{
    int ST = 0, PF = 0;

	while (cin >> ST >> PF)
	{
//		cin >> ST >> PF;
	    node rig[PF];
	    //student
	    for (int i = 0; i < ST; i++)
	        for (int j = 0; j < PF; j++)
	            cin >> rig[i].st[j];
	    //perfessor
	    for (int i = 0; i < PF; i++)
	        for (int j = 0; j < ST; j++)
	            cin >> rig[i].pf[j];
	    
	    int ans[ST];
	    for (int i = 0; i < PF; i++)
	    {
	    	for (int z = 0; z < ST; z++)
	    	{
	    		if(rig[z].st[i] == -1) continue;
	    		int tmp = 0;
		    	int num = 0;
		    	int cmp[ST];
			    int same[ST];
		    	bool first = true;
	    		for (int j = z; j < ST; j++)
		        {
		        	if (first == true)
		        	{
		        		tmp = rig[j].st[i];
		        		first = false;
					}
		        	cmp[j] = rig[j].st[i];
		        	if (cmp[j] == tmp)
		        	{
		        		same[num] = j;
		        		num++;
					}
					if (rig[tmp].pf[0] == -1) break;
				}
				if (rig[tmp].pf[0] == -1) continue;
				if (num == 1)
				{
					ans[z] = tmp;
					for (int k = 0; k < ST; k++)
						rig[tmp].pf[k] = -1;
					for (int k = 0; k < PF; k++)
						rig[z].st[k] = -1;
				}
				else
				{
					bool end = false;
					int cnt;
					for (int k = 0; k < ST; k++)
					{
						for (int l = 0; l < num; l++)
						{
							if (rig[tmp].pf[k] == same[l])
							{
								cnt = same[l];
								for (int k = 0; k < ST; k++)
									rig[tmp].pf[k] = -1;
								for (int k = 0; k < PF; k++)
									rig[same[l]].st[k] = -1;
								end = true;
								break;
							}
						}
						if (end == true)
						{
							for (int l = 0; l < num; l++)
								rig[same[l]].st[i] = -1;
							break;
						}
					}
					ans[cnt] = tmp;
				}
//				cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
//		    	for (int i = 0; i < ST; i++)
//				{
//					for (int j = 0; j < PF; j++)
//						cout << rig[i].st[j] << " ";
//					cout << endl;	
//				}
//				for (int i = 0; i < PF; i++)
//				{
//					for (int j = 0; j < ST; j++)
//						cout << rig[i].pf[j] << " ";
//					cout << endl;	
//				}	
//				cout <<  "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
			}
	    }
		
	    for (int i = 0; i < ST; i++)
	        cout << ans[i] << " ";
	    cout << endl;
	}
    
}
