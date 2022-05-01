#include <iostream>

using namespace std;

int main()
{
	int cnt ;
	cin >> cnt ;
	for (int i = 0 ; i < cnt ; i++)
	{
		int qua[10000];
		int rig[10000];
		int len = 0;
		for (int j = 0;;j++)
		{
			len = j;
			cin >> qua[j];
			char ch = getchar();
			if(ch == '\n')
				break;
		}
		
		for (int index = 0; index <= len; index++)
		{
			int count = 0;
			for (int j = index; j <= len ; j++)
				if(qua[index] > qua[j])
					count++;
			for (int j = index; j >= 0 ; j--)
				if(qua[index] < qua[j])
					count++;
			rig[index] = count;		
		} 
		
		int max = 0;
		for (int j = 0; j <= len ; j++)
			if(rig[j] > max)
				max = rig[j];
		
		int ans[10000];
		int k = 0;
		for (int j = 0; j <= len ; j++)
			if(rig[j] == max)
				ans[k++] = qua[j];
		
		for (int j = 0; j < k ; j++)
		{
			if( j == k-1 )
				cout << ans[j] << " " ;
			else
				cout << ans[j] << ", " ;
		}
			
		cout << max << endl;
		
		for (int j = 0; j <= len ; j++)
		{
			qua[j] = 0;
			rig[j] = 0;
		}
	}
}
