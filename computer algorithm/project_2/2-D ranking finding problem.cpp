#include <algorithm>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>

using namespace std;
 
struct node{
	double x, y;
	int index;
	
	bool operator<(const node &other) const {
		if (this->x != other.x) // x由小排到大 
			return this->x < other.x;
		return this->y > other.y; // y則由大排到小 
	}
}; 

int min_rank = pow(2, 31) - 1;
int max_rank = -1 * pow(2, 31);
int ranks[10000];
node points[10000], buffer[10000], ans[10000];

 void Rank2D(int lower, int upper, int cnt, int l, int u) 
 {
	if (upper - lower <= 1) // 只有一點 
	{
		cout << "only one point! " << endl; 
		cout << endl; 
		return;
	} 	
	int middle = (lower + upper) >> 1; // 中線分左右半邊 
	int counts = 0;
	int i = lower, j = middle, k = lower;
	
	cout << "Now Middle : " << middle << "\n" << endl;
	
	// 遞回 
	cout << "Middle左半邊 : " << endl; 
	Rank2D(lower, middle, cnt, l, u); // 中線左半邊 
	cout << "Middle右半邊 : " << endl; 
	Rank2D(middle, upper, cnt, l, u); // 中線右半邊 
	
	while (i < middle || j < upper) 
	{
		if (i == middle) {
			buffer[k] = points[j]; 
			ranks[buffer[k].index] += counts;
			min_rank = (ranks[buffer[k].index] < min_rank) ? ranks[buffer[k].index] : min_rank; 
			max_rank = (ranks[buffer[k].index] > max_rank) ? ranks[buffer[k].index] : max_rank; 
			j++; k++;
		}
		else if (j == upper) {
			buffer[k] = points[i];
			i++; k++;
		}
		else if (points[i].y < points[j].y) { // 僅需比較y 
			buffer[k] = points[i]; 
			counts++;
			i++; k++;
		}
		else {
			buffer[k] = points[j]; 
			ranks[buffer[k].index] += counts;
			min_rank = (ranks[buffer[k].index] < min_rank) ? ranks[buffer[k].index] : min_rank; 
			max_rank = (ranks[buffer[k].index] > max_rank) ? ranks[buffer[k].index] : max_rank;
			j++; k++;
		}
	}
	
	for (i = lower; i < upper; ++i)
		points[i] = buffer[i];
		
	cout << "Now Middle : " << middle << "\n" << endl;	
		
	cout << "Point State : \n" << endl;	
	for (int z = 0; z < cnt ; z++)
    	cout << "x = " << setw(5) << points[z].x << ", y = " << setw(5) << points[z].y << endl;
    cout << endl;
			
    for (int z = 0; z < cnt ; z++)
    	(z != cnt-1) 
		? cout << "Rank(" << z+1 << ") = " << ranks[z] << ", " 
		: cout << "Rank(" << z+1 << ") = " << ranks[z] << endl;
			
	if (middle != (l+u/2)) cout << "\n-------------------------------------------\n" << endl;
}

int main() {
	int cnt = 0;
    double tmp;
    ifstream input;
    input.open("test2.txt");
    for (;input >> tmp; cnt++){
    	points[cnt].index = cnt;
    	ans[cnt].x = tmp; points[cnt].x = tmp;
    	input >> tmp;
    	ans[cnt].y = tmp; points[cnt].y = tmp;
	}
	
	// 將所有點按照 x 值由小到大排序，x 值一樣的則將 y 值由大到小排 (The function inside the struct node) 
	sort(points, points + cnt); 
	
	cout << "Origin : " << setw(31) << "Sorted : \n" << endl;
	for (int x = 0; x < cnt; x++)
			cout << "x = " << setw(4) << ans[x].x << ", y = " << setw(4) << ans[x].y << setw(17) << "x = " << setw(4) << points[x].x << ", y = " << setw(4) << points[x].y << endl;
	cout << "\n-----------------------------------------------------------------\n" << endl;
	
	cout << "Compute Process : " << endl;
	Rank2D(0, cnt, cnt, 0, cnt);
	cout << "\n-----------------------------------------------------------------\n" << endl;
	
	cout << "Ans Points : \n" << endl;
    for (int i = 0; i < cnt ; i++)
    	cout << "Point " << setw(2) << i+1 << " : " << "x = " << setw(5) << ans[i].x << ", y = " << setw(5) << ans[i].y  << ", Rank = " << setw(2) << ranks[i] << endl;
    cout << "\nAns : \n" << endl;
	cout << setw(16) << "Points Count : " << setw(4) << cnt << endl;
    cout << setw(16) << "Largest Rank : " << setw(4) << max_rank << endl;
    cout << setw(16) << "Smallest Rank : " << setw(4) << min_rank << endl; 
    
    float avg_rank = 0;
    for (int i = 0; i < cnt ; i++)
    	avg_rank += ranks[i];
    avg_rank /= cnt;
	cout << setw(16) << "Average Rank : " << setw(4) << setprecision(2) << avg_rank << endl; 	
	
    input.close();
}
