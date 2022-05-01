#include <iostream>
#include <cstring>
#define N 50
using namespace std;

struct node{
	bool M[N];
};

struct tree{
	node F[N];
};

bool search(tree *matrix, bool map[N][N], bool *TF, int F, int M, int index)
{
    long tmp = 0;
    bool found = true;
    for (int i = 0; i < M; i++)
    {
        if (matrix[0].F[index].M[i] && matrix[1].F[index].M[i])
        {
            if (map[index][i])
            {
                tmp = i;
                map[index][i] = 0;
                found = false;
                continue;
            }
            map[index][i] = 1;
            if (TF[i])
            {
                for (int j = 0; j < F; j++)
                {
                    if (map[j][i] == 1)
                    {
                        if (search(matrix, map, TF, F, M, j))
                            return true;
                        else
                        {
                            map[index][i] = 0;
                            break;
                        }
                    }
                }
                continue;
            }
            TF[i] = true;
            return true;
        }
    }
    if (!found)
    {
        map[index][tmp] = 1;
    }
    return false;
}

int Hungarian(tree *matrix, int F, int M)
{
	int cnt = 0;
	bool TF[N*2]; //判斷該男是否被選中過 
	bool map[N][N];
	memset(map, 0, sizeof(map));
	memset(TF, 0, sizeof(TF));  
	for (int i = 0; i < F; i++)
	{
		if(search(matrix, map, TF, F, M, i))
			cnt++;
	}
	return cnt;
}

int main()
{
	long cnt;
	cin >> cnt;
	while (cnt--)
	{
		int  M, F, tmp;
		cin >> M >> F;
		tree matrix[2];
		memset(matrix, 0, sizeof(matrix));
		for (int i = 0; i < M; i++) // man
		{
			cin >> tmp;
	        bool end = false;
	        for (int j = 0; j < F; j++)
	        {
	            int tmp2 = 0;
	            if (tmp != 1)
	            {
	                tmp2 = tmp % 2;
	                tmp = tmp / 2;
	            }
	            else
	            {
	                if (tmp == 1 && !end)
	                {
	                    tmp2 = 1;
	                    end = true;
	                }
	                else
	                    tmp2 = 0;
	            }
	            matrix[0].F[j].M[i] = tmp2;
	        }
		}
			
		for (int i = 0; i < F; i++) // woman
		{
			cin >> tmp;
			bool end = false;
	        for (int j = 0; j < M; j++)
	        {
	            int tmp2 = 0;
	            if (tmp != 1)
	            {
	                tmp2 = tmp % 2;
	                tmp = tmp / 2;
	            }
	            else
	            {
	                if (tmp == 1 && !end)
	                {
	                    tmp2 = 1;
	                    end = true;
	                }
	                else
	                    tmp2 = 0;
	            }
	            matrix[1].F[i].M[j] = tmp2;
	        }
		}
		
//		for (int i = 0; i < F; i++)
//		{
//			for (int j = 0; j < M; j++)
//				cout << matrix[0].F[i].M[j] << " ";
//			cout << endl;
//		}
//
//		for (int i = 0; i < F; i++)
//		{
//			for (int j = 0; j < M; j++)
//				cout << matrix[1].F[i].M[j] << " ";
//			cout << endl;
//		}
        
		int ans = Hungarian(matrix, F, M);
		
		cout << ans*10000 << endl;
	}
}
