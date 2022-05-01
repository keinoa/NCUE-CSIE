#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//(a) ���Ҽ{�̫�O�_�C��p�j��n�P�@����Ͱt�諸����A�а����Ҧ����ͳ��̺��N���u�t�t�{�סv
//�`������?
//(b) ���Ҽ{�̫�O�_�C����ͭ�n�P�@��p�j�t�諸����A�а����Ҧ��p�j���̺��N���u�t�t�{�סv
//�`������?
//(c) �p�G�D���줣�Ʊ�������H����]���ѡA�n�D�C�@�Ӥp�j�u��P�@����Ͱt��A�ӥB�C�@�ӥ�
//�ͤ]�u��P�@��p�j�t��A�аݺ����H�W���p���̰��u�t�t�{�סv�`������?


int matrix[100][100];
int label_x[100], label_y[100];
int match_x[100], match_y[100];
bool visited_x[100], visited_y[100];
const int inf = 1000000000;

bool DFS(int x, int size ) {
	visited_x[x] = true;
	for (int y = 0; y < size; ++ y)
		if (!visited_y[y]) {
			if (label_x[x] + label_y[y] == matrix[x][y]) {
			visited_y[y] = true;
				if (match_y[y] == -1 || DFS(match_y[y], size)) {
					match_x[x] = y; match_y[y] = x;
					return true;
				}
			}
		}
	return false;
}

int solution_a(int size) {
	int ans = 0;
	for (int i = 0; i < size; i++)
	{
		int tmp = 0;
		for (int j = 0; j < size; j++)
		{
			tmp = (matrix[i][j] > tmp) ? matrix[i][j] : tmp;
		}
		ans += tmp;
	}
	return ans;
}
	
int solution_b(int size) {
	int ans = 0;
	for (int i = 0; i < size; i++)
	{
		int tmp = 0;
		for (int j = 0; j < size; j++)
		{
			tmp = (matrix[j][i] > tmp) ? matrix[j][i] : tmp;
		}
		ans += tmp;
	}
	return ans;
}

int solution_c(int size) {
	int solution = 0;
	
	for (int x = 0; x < size; ++ x) label_y[x] = 0; /*�@�}�l�k�ͪ��t��ȬO 0 */
	for (int x = 0; x < size; ++ x) {
		for (int y = 0; y < size; ++ y) {
			if (matrix[x][y] != 1000000000) {
				label_x[x] = std::max(label_x[x], matrix[x][y]);
				/*�@�}�l�k�ͪ��t��ȬO�C�@�C���̤j�� */
			}
		}
	}
	for (int x = 0; x < size; ++ x) {
		match_x[x] = -1; /*�@�}�l�k�ͳ��٥��t�� */
		match_y[x] = -1; /*�@�}�l�k�ͳ��٥��t�� */
	}

	for (int x = 0; x < size; ++ x) {
		while (true) {
			for (int i = 0; i < size; ++ i) {
				visited_x[i] = false;
				visited_y[i] = false;
			}

			if (DFS(x, size)) {
				break; /* �{���q�B�z���k�ͥi�H���̨Ω��� */
			}
		
			int difference = inf;
		
			for (int x = 0; x < size; ++ x) {
				if (visited_x[x]) {
					for (int y = 0; y < size; ++ y) {
						if (!visited_y[y]) {
							if (matrix[x][y] != inf) {
								difference = min(difference, label_x[x] + label_y[y] - matrix[x][y]);
							}
						}
					}
				}
			}
			/* ��X�o�@���Ҧ��������k�ͤ��i�H�Q�խ��̤֪��v���� */
			if (difference == inf) {
				return -inf;
			}
	
			for (int x = 0; x < size; ++ x) {
				if (visited_x[x]) {
					label_x[x] -= difference;
				}
			} /* �N�o�@���Ҧ����Q���X�쪺�k���v�حȴ�h difference */
	
			for (int y = 0; y < size; ++ y){
				if (visited_y[y]) {
					label_y[y] += difference;
				} /* �N�o�@���Ҧ����Q���X�쪺�k���v�حȥ[�W difference */
			}
		}
	}

	for (int x = 0; x < size; ++ x) {
		solution += matrix[x][match_x[x]];
	}
	return solution;
}


int main() {
	int cnt;
	cin >> cnt;
	while (cnt--) {
		int size;
		cin >> size;
		int a_ans = 0, b_ans = 0, c_ans = 0;
//		int matrix[size][size];
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
				cin >> matrix[i][j];
		
				
		
		a_ans = solution_a(size);
		b_ans = solution_b(size);
		c_ans = solution_c(size);
		
		cout << a_ans << " " << b_ans << " " << c_ans << endl;
	}
}
