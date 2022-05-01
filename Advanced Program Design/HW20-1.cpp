#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

//(a) 不考慮最後是否每位小姐剛好與一位先生配對的限制，請問讓所有先生都最滿意的「速配程度」
//總分為何?
//(b) 不考慮最後是否每位先生剛好與一位小姐配對的限制，請問讓所有小姐都最滿意的「速配程度」
//總分為何?
//(c) 如果主辦單位不希望讓任何人有遺珠之憾，要求每一個小姐只能與一位先生配對，而且每一個先
//生也只能與一位小姐配對，請問滿足以上狀況的最高「速配程度」總分為何?


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
	
	for (int x = 0; x < size; ++ x) label_y[x] = 0; /*一開始女生的配對值是 0 */
	for (int x = 0; x < size; ++ x) {
		for (int y = 0; y < size; ++ y) {
			if (matrix[x][y] != 1000000000) {
				label_x[x] = std::max(label_x[x], matrix[x][y]);
				/*一開始男生的配對值是每一列的最大值 */
			}
		}
	}
	for (int x = 0; x < size; ++ x) {
		match_x[x] = -1; /*一開始男生都還未配對 */
		match_y[x] = -1; /*一開始女生都還未配對 */
	}

	for (int x = 0; x < size; ++ x) {
		while (true) {
			for (int i = 0; i < size; ++ i) {
				visited_x[i] = false;
				visited_y[i] = false;
			}

			if (DFS(x, size)) {
				break; /* 現階段處理的男生可以找到最佳拍檔 */
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
			/* 找出這一輪所有有關的男生中可以被調降最少的權重值 */
			if (difference == inf) {
				return -inf;
			}
	
			for (int x = 0; x < size; ++ x) {
				if (visited_x[x]) {
					label_x[x] -= difference;
				}
			} /* 將這一輪所有有被拜訪到的男生權種值減去 difference */
	
			for (int y = 0; y < size; ++ y){
				if (visited_y[y]) {
					label_y[y] += difference;
				} /* 將這一輪所有有被拜訪到的女生權種值加上 difference */
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
