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

int M, F;          //M, N���O��ܥ��B�k�����X�������ƶq
int Map[21][21];   //�F���x�}�s��
int p[21];         //�O����e�k�������ҹ�������������
bool vis[21];      //�O���k�������O�_�w�Q�X�ݹL
bool match(int i)
{
    for (int j = 1; j <= F; ++j)
        if (Map[j][i] && !vis[j]) //����B���X��
        {
            vis[j] = true;                 //�O�����A���X�ݹL
            if (p[j] == 0 || match(p[j])) //�p�G�ȵL�ǰt�A�Ϊ̭�Ӥǰt�����������i�H���s���ǰt
            {
                p[j] = i;    //��e��������������e�k���������s�ǰt
                return true;
            }
        }
    return false; //�`�������A�������ǰt�A��^�ǰt����
}
int Hungarian()
{
    int cnt = 0;
    memset(p, 0, sizeof(p)); //���m����
    for (int i = 1; i <= M; ++i)
    {
        memset(vis, 0, sizeof(vis)); //���mvis�Ʋ�
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
