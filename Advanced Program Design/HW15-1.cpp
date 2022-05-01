#include <iostream>

using namespace std;

int main()
{
	int line, clsmat;
	while (cin >> clsmat >> line)
	{
		int arr[10000];
		int clues[10000][2];
		
		for (int i = 0 ; i < line ; i++)
		{
			cin >> clues[i][0] >> clues[i][1];
			if( clues[i][0] > clues[i][1] )
				swap(clues[i][0], clues[i][1]);
		}
			
		for (int i = 0 ; i < clsmat ; i++)
			arr[i] = i;
			
		for (int i = 0 ; i < line ; i++)
		{
			int rig0, rig1;
			if(arr[clues[i][0]] == clues[i][0])
				rig0 = clues[i][0];
			else
			{
				int rig2 = arr[clues[i][0]];
				while(true)
				{
					if(arr[rig2] == rig2)
					{
						rig0 = rig2;
						break;
					}
					rig2 = arr[rig2];	
				}
			}
			if(arr[clues[i][1]] == clues[i][1])
				rig1 = clues[i][1];
			else
			{
				int rig2 = arr[clues[i][1]];
				while(true)
				{
					if(arr[rig2] == rig2)
					{
						rig1 = rig2;
						break;
					}
					rig2 = arr[rig2];	
				}
			}
			if( rig0 != rig1 )
				arr[rig1] = rig0;
		}
		
//		for (int i = 0 ; i < clsmat ; i++)
//		{
//			cout << i << " ";
//		}			
//		cout << endl;
//		for (int i = 0 ; i < clsmat ; i++)
//		{
//			cout << arr[i] << " ";
//		}			
//		cout << endl;

		int ans = 0;
		for (int i = 0 ; i < clsmat ; i++)
			if( arr[i] == i )
				ans++;
		cout << ans << endl;
	}
}
