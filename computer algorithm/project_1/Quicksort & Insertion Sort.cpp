#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void quicksort(double* arr, int left, int right, int max, int queue)
{
	if (left < right)
	{
		
		double pivot = arr[left]; //選定pivot值 
		int l = left;
		int r = right + 1;
		while (1)
		{
			while (l < r && arr[++l] < pivot);
			while (0 < r && arr[--r] > pivot);
			if (l >= r) break;
			swap(arr[l], arr[r]);
		}
		swap(arr[left], arr[r]); //pivot擺到中間 
		
		cout << "step " << queue << " : ";
		for (int i = 0; i < max; i++)
			(i != max - 1) ? cout << arr[i] << " -> " : cout << arr[i] << endl;
			
		quicksort(arr, left, r - 1, max, queue + 1); //左邊繼續排
		quicksort(arr, r + 1, right, max, queue + 1); //右邊繼續排
	}
}

void insertionsort(double* arr, int size) 
{
	for (int i = 0; i < size; i++) 
	{
		int j = i + 1;
		double tmp = arr[j];
		while (j > 0 && tmp < arr[j - 1]) 
		{
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = tmp;
		
		cout << "step " << i+1 << " : ";
		for (int k = 0; k < size + 1; k++)
			(k != size) ? cout << arr[k] << " -> " : cout << arr[k] << endl; 
	}
}

void swap(int a, int b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

int main()
{
	char sel;
	bool end = false;
	cout << "請按以下選擇輸入 :\n\n1. 執行快速排序法\n2. 執行插入排序法\n3. 程式結束\n" << endl;
	
	int cnt = 0;
    double tmp, num_quick[2000], num_insert[2000];
    ifstream input;
    input.open("test1.txt");
    while (input >> tmp)
    {
    	num_quick[cnt] = tmp;
    	num_insert[cnt++] = tmp;
	}
    input.close();
    
	while(cin >> sel)
	{
		switch (sel){
			case '1':
				cout << endl;
				cout << "\n快速排序法(Quick_sort)過程 : \n" << endl;
				quicksort(num_quick, 0, cnt - 1, cnt, 1);
				cout << "\n快速排序法(Quick_sort)由小到大 : \n" << endl;
				for(int i = 0; i < cnt; i++)
					 ((i + 1) != cnt ) ? cout << setw(8) << num_quick[i] << " -> " : cout << setw(8) << num_quick[i] << endl;
				cout << "\n所有數個數 : " << cnt << endl;
				cout << "最大的數 : " << num_quick[cnt-1] << endl;
				cout << "最小的數 : " << num_quick[0] << endl;
				break;
			case '2':
				cout << endl;
				cout << "\n插入排序法(insertion_sort)過程 : \n" << endl;
				insertionsort(num_insert, cnt - 1);
				cout << "\n插入排序法(insertion_sort)由小到大 : \n" << endl;
				for(int i = 0; i < cnt; i++)
					 ((i + 1) != cnt ) ? cout << setw(8) << num_insert[i] << " -> " : cout << setw(8) << num_insert[i] << endl;
				cout << "\n所有數個數 : " << cnt << endl;
				cout << "最大的數 : " << num_insert[cnt-1] << endl;
				cout << "最小的數 : " << num_insert[0] << endl;
				break;
			case '3':
				end = true;
				cout << "\n\n程式結束。" << endl;
				input.clear();
				input.close();
				break;
			default:
				cout << "\n\n輸入錯誤請重試。" << endl;
				break;
		}
		if(end == true)
			break;
	}
}
