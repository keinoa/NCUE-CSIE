#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

int main() {
    string max, min;
    int star;
	while( cin >> max >> min >> star )
	{
		star += 64;
		if( max.size() < min.size() )
			swap(max, min);
			
		int max_len = max.size();
		int min_len = min.size();
		
		int arr[max_len+1][min_len+1];
		int cnt[max_len+1][min_len+1];
		
		for (int i = 0; i <= max_len; i++ )
			for (int j = 0; j <= min_len; j++ )
			{
				arr[i][j] = 0;
				cnt[i][j] = 1;
			}
		
		for(int i = 1; i <= max_len; i++)
		{
			for(int j = 0; j <= i ; j++)
			{
				if( i == j )
					for(int k = 1; k <= i; k++) 
						arr[i][j] += abs(max[k-1] - min[k-1]);
				else if( i >= j && (i - j) <= (max_len - min_len) )
				{
					int rig0 = arr[i-1][j-1] + abs(max[i-1] - min[j-1]);
					int rig1 = arr[i-1][j] + abs(star - max[i-1]);
					
					if(j != 0)
					{
						if(rig0 > rig1)
							arr[i][j] = rig0;
						else
							arr[i][j] = rig1;
							
						if(rig0 > rig1)
							cnt[i][j] = cnt[i-1][j-1];
						else if(rig0 < rig1)
							cnt[i][j] = cnt[i-1][j];
						else
							cnt[i][j] = cnt[i-1][j] + cnt[i-1][j-1];	
					}
					else
						arr[i][j] = rig1;
				}
			}
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		for(int i = 0; i <= max_len; i++)
		{
			for(int j = 0; j <= min_len ; j++)
			{
				cout << arr[i][j] << " ";
			}
			cout << endl;
		}
		cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		cout << arr[max_len][min_len] << " " << cnt[max_len][min_len] << endl;				
				 
	}
}
