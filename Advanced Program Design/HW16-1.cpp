#include <iostream>

using namespace std;

int main()
{
	long int cnt ;
	cin >> cnt ;
	for (int i = 0 ; i < cnt ; i++)
	{
		int qua[10000];
		int rig[10000];
		int ans[10000];
		int len = 0;
		for (int j = 0;;j++)
		{
			len = j;
			cin >> qua[j];
			char ch = getchar();
			if(ch == '\n')
				break;
		}
		
		int count = 0, rigster = 0;
		rig[count] = 0; 
		for (int index = 0 ; index <= len; index++)
        {
        	int right = index, left = index;
        	
            while (left >= 0)
                if (qua[left--] > qua[index])
                    count++;
            while (right <= len)
                if (qua[right++] < qua[index])
                    count++;
                    
            if (rig[rigster-1] <= count) 
			{
                rig[rigster] = count;
                ans[rigster] = index;
                rigster++;
            }
            count = 0;
    	}
    	
		for (int j = 0; j < rigster; j++) 
		{
            if (rig[j] >= rig[rigster-1]) 
			{
                if (j == rigster-1)
                    cout << qua[ans[j]] << " ";
                else
                    cout << qua[ans[j]] << ", ";
            }
        }
        cout << rig[rigster-1] << endl;
	}
}
