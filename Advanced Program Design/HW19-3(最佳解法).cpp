#include <iostream>
#include <string.h>
#define N 21
using namespace std;

struct node{
	bool M[N];
};

struct tree{
	node F[N];
};

int M, F;          //M, N分別表示左、右側集合的元素數量
int Map[21][21];   //鄰接矩陣存圖
int p[21];         //記錄當前右側元素所對應的左側元素
bool vis[21];      //記錄右側元素是否已被訪問過
bool match(int i)
{
    for (int j = 1; j <= F; ++j)
        if (Map[j][i] && !vis[j]) //有邊且未訪問
        {
            vis[j] = true;                 //記錄狀態為訪問過
            if (p[j] == 0 || match(p[j])) //如果暫無匹配，或者原來匹配的左側元素可以找到新的匹配
            {
                p[j] = i;    //當前左側元素成為當前右側元素的新匹配
                return true;
            }
        }
    return false; //循環結束，仍未找到匹配，返回匹配失敗
}
int Hungarian()
{
    int cnt = 0;
    memset(p, 0, sizeof(p)); //重置元素
    for (int i = 1; i <= M; ++i)
    {
        memset(vis, 0, sizeof(vis)); //重置vis數組
        if (match(i))
            cnt++;
    }
    return cnt;
}

int main()
{
	int cnt;
	cin >> cnt;
	while (cnt--)
	{
		int tmp;
		cin >> M >> F;
		tree matrix[2];
		memset(matrix, 0, sizeof(matrix));
		for (int i = 1; i <= M; i++) // man
		{
			cin >> tmp;
	        for (int j = 1; j <= F; j++)
	        {
	            matrix[0].F[j].M[i] = tmp % 2;
	            tmp /= 2;
	        }
		}
			
		for (int i = 1; i <= F; i++) // woman
		{
			cin >> tmp;
			for (int j = 1; j <= M; j++)
	        {
	            matrix[1].F[i].M[j] = tmp % 2;
	            tmp /= 2;
	        }
		}

		for (int i = 1; i <= F; i++)
			for (int j = 1; j <= M; j++)
				Map[i][j] = (matrix[1].F[i].M[j] == 1 && matrix[0].F[i].M[j] == 1) ? 1 : 0 ; 
				
		int ans = Hungarian();

		cout << ans*10000 << endl;
		
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
//		
//		for (int i = 1; i <= F; i++)
//		{
//			for (int j = 1; j <= M; j++)
//				cout << matrix[2].F[i].M[j] << " ";
//			cout << endl;
//		}
	}
}
