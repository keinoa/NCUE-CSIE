#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void quicksort(double* arr, int left, int right, int max, int queue)
{
	if (left < right)
	{
		
		double pivot = arr[left]; //��wpivot�� 
		int l = left;
		int r = right + 1;
		while (1)
		{
			while (l < r && arr[++l] < pivot);
			while (0 < r && arr[--r] > pivot);
			if (l >= r) break;
			swap(arr[l], arr[r]);
		}
		swap(arr[left], arr[r]); //pivot�\�줤�� 
		
		cout << "step " << queue << " : ";
		for (int i = 0; i < max; i++)
			(i != max - 1) ? cout << arr[i] << " -> " : cout << arr[i] << endl;
			
		quicksort(arr, left, r - 1, max, queue + 1); //�����~���
		quicksort(arr, r + 1, right, max, queue + 1); //�k���~���
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
	cout << "�Ы��H�U��ܿ�J :\n\n1. ����ֳt�ƧǪk\n2. ���洡�J�ƧǪk\n3. �{������\n" << endl;
	
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
				cout << "\n�ֳt�ƧǪk(Quick_sort)�L�{ : \n" << endl;
				quicksort(num_quick, 0, cnt - 1, cnt, 1);
				cout << "\n�ֳt�ƧǪk(Quick_sort)�Ѥp��j : \n" << endl;
				for(int i = 0; i < cnt; i++)
					 ((i + 1) != cnt ) ? cout << setw(8) << num_quick[i] << " -> " : cout << setw(8) << num_quick[i] << endl;
				cout << "\n�Ҧ��ƭӼ� : " << cnt << endl;
				cout << "�̤j���� : " << num_quick[cnt-1] << endl;
				cout << "�̤p���� : " << num_quick[0] << endl;
				break;
			case '2':
				cout << endl;
				cout << "\n���J�ƧǪk(insertion_sort)�L�{ : \n" << endl;
				insertionsort(num_insert, cnt - 1);
				cout << "\n���J�ƧǪk(insertion_sort)�Ѥp��j : \n" << endl;
				for(int i = 0; i < cnt; i++)
					 ((i + 1) != cnt ) ? cout << setw(8) << num_insert[i] << " -> " : cout << setw(8) << num_insert[i] << endl;
				cout << "\n�Ҧ��ƭӼ� : " << cnt << endl;
				cout << "�̤j���� : " << num_insert[cnt-1] << endl;
				cout << "�̤p���� : " << num_insert[0] << endl;
				break;
			case '3':
				end = true;
				cout << "\n\n�{�������C" << endl;
				input.clear();
				input.close();
				break;
			default:
				cout << "\n\n��J���~�Э��աC" << endl;
				break;
		}
		if(end == true)
			break;
	}
}
