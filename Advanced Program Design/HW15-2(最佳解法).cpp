#include <iostream>

using namespace std;

static int getf(int* f, int x)
{
	if (f[x] == x)
        return x;
    else
	{
    	f[x] = getf(f, f[x]);
        return f[x];
	}
}

static void merge(int* f, int x, int y)
{
	int t1 = getf(f, x);
    int t2 = getf(f, y);
    if (t1 != t2)
        f[t2] = t1;
}

int main()
{
	int line, clsmat;
	while (cin >> clsmat >> line)
	{
		int f[10000];
		int clues[10000][2];
		for(int i = 0 ; i < clsmat; i++)
	    	f[i] = i;
	    	
		for (int i = 0 ; i < line ; i++)
			cin >> clues[i][0] >> clues[i][1];
			
		for(int i = 0; i < line; i++)
	    	merge(f, clues[i][0], clues[i][1]);
	    
//		for (int i = 0 ; i < clsmat ; i++)
//		{
//			cout << f[i] << " ";
//		}			
//		cout << endl;
			
		int sum = 0;
		for(int i = 0; i < clsmat; i++)
		    if (f[i] == i) 
		        sum += 1;
		
		cout << sum << endl; 
	}
}
