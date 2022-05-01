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

bool find(tree *match, bool *used, int *girl, int index, int M)
{
	for (int j = 0; j < M; j++)
	{ 
		if (match[0].F[index].M[j] && match[1].F[index].M[j] && !used[j])
		{ 
			used[j] = true;
			if (girl[j] == 0 || find(match, used, girl, girl[j], M))
			{ 
				girl[j] = index;
				return true;
			}
		}
	}
	return false;
}

int Hungarian(tree *match, bool *used, int *girl , int F, int M)
{ 
	int ans = 0;
	memset(girl, 0, sizeof(girl)); 
	for (int i = 0; i < F; i++)
	{
		memset(used, 0, sizeof(used)); 
		if (find(match, used, girl, i, M))
			ans++; 
	}
	return ans;
}

int main()
{
	int cnt;
	cin >> cnt;
	while (cnt--)
	{
		int M, F, tmp;
		cin >> M >> F;
		tree matrix[3];
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
	                tmp /= 2;
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
	                tmp /= 2;
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
//			cout << "matrix(0)" << " ";
//			for (int j = 0; j < M; j++)
//				cout << matrix[0].F[i].M[j] << " ";
//			cout << endl;
//		}
//
//		for (int i = 0; i < F; i++)
//		{
//			cout << "matrix(1)" << " ";
//			for (int j = 0; j < M; j++)
//				cout << matrix[1].F[i].M[j] << " ";
//			cout << endl;
//		}
		
//		for (int i = 0; i < F; i++)
//			for (int j = 0; j < M; j++)
//				matrix[2].F[i].M[j] = matrix[1].F[i].M[j] & matrix[0].F[i].M[j];
		
		bool used[N];	  
		int girl[N];
		int ans = Hungarian(matrix, used, girl, M, F);

		cout << ans*10000 << endl;
	}
}
