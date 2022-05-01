#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

struct find_a{
	double distance;
	string pre_node;
};

find_a ans; 
double node[100][100]; //有向之路徑長
int index_col = 0, index_row = 0;
bool first = true;
string arr[1000][5];
string traffic_len[100][100];
string traffic_limit[100][100]; 

double pre_distance[100]; //紀錄路之間的距離 
string pre_width[100]; //紀錄路之間的路寬 
string pre_limit[100]; //紀錄選擇路之交通限制 

void label_setting(int source, int traffic, double *shortest, int *before, bool *visit, int cnt);
void find_path(int source, int x, int traffic, double *shortest, int *before); 
string to_string(double value);
 
int main() {
    ifstream input;
	input.open("test3.txt");
	if(input == NULL){
		cout << "找不到檔案資料" << endl;
		return 0; 
	}
    
    //	node數 
    int cnt = 0;
	input >> cnt;
	cout << cnt << endl;
	cout << "\n" << "--------------------------------------------------------------------" << "\n" << endl;
	
	//	存入所有data 
	string tmp;
	while(input >> tmp){
		arr[index_row][index_col % 5] = tmp; 
		index_col++;
		index_row = ((index_col % 5 == 0) ? index_row + 1 : index_row);
	}
	//	判斷存入之data是否有格式錯誤 
	cout << "輸入之data: " << endl;
	for(int i = 0; i < index_row; i++){
		int tmp_width[5] = {6, 4, 2, 1.5, 0.5};
		for(int j = 0; j < 5; j++){
			if(char(arr[i][4][j]) == '1' && atof(arr[i][3].c_str()) < tmp_width[j]){
				cout << "輸入錯誤路幅不夠寬: ";
				for(int k = 0; k < 5; k++)
					cout << arr[i][k] << " ";
				return 0;	
			}
		}
		if(arr[i][0] == arr[i][1] || atoi(arr[i][0].c_str()) < 0 || atoi(arr[i][0].c_str()) >= cnt || atoi(arr[i][1].c_str()) < 0 || atoi(arr[i][1].c_str()) >= cnt){
			cout << "node輸入錯誤: ";
			for(int j = 0; j < 5; j++)
				cout << arr[i][j] << " ";
			return 0;	
		}
		else if(atof(arr[i][2].c_str()) <= 0 || atof(arr[i][3].c_str()) <= 0){
			cout << "輸入錯誤距離、路幅值需均為正實數: ";
			for(int j = 0; j < 5; j++)
				cout << arr[i][j] << " ";
			return 0;	
		}
		else{
			for(int j = 0; j < 5; j++)
				cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	
	//	每個node間之距離 
	for(int i = 0; i <= index_row; i++){
		int node_rig[2]; 
		for(int j = 0; j < 2; j++){
			node_rig[j] = atoi(arr[i][j].c_str());
		}
		node[node_rig[0]][node_rig[1]] = atof(arr[i][2].c_str());
		traffic_limit[node_rig[0]][node_rig[1]] = arr[i][4];
		traffic_len[node_rig[0]][node_rig[1]] = arr[i][3];
	}
	cout << "\n" << "--------------------------------------------------------------------" << "\n" << endl;
	cout << "node彼此間距離&交通限制: " << endl;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < cnt; j++){
			if(i == j)
				continue;
			cout << "node" << i << "->node" << j << " : " << node[i][j] << "（" << traffic_limit[i][j] << "）" << endl;
		}
	}
	
	double shortest[cnt]; //紀錄累計之最短路徑 
	int before[cnt]; //紀錄前一節點  
	bool visit[cnt]; //是否拜訪過該路  
	
	
	cout << "\n" << "--------------------------------------------------------------------" << "\n" << endl;
	int node_begin, node_end, traffic;
	while(1){
		cout << "請輸入起始節點( 0 ~ " << cnt-1 << " ): ";
		cin >> node_begin ;
		cout << "請輸入目的節點( 0 ~ " << cnt-1 << " ): ";
		cin >> node_end;
		cout << "請輸入交通方式( 5.巴士、4.轎車、3.機車、2.腳踏車、1.步行 ): ";
		cin >> traffic;
		if(node_begin == node_end || node_begin < 0 || node_begin >= cnt || node_end < 0 || node_end >= cnt || traffic < 1 || traffic > 5){
			cout << "輸入有誤請重新輸入: " << endl;
			continue;
		}
		break;	
	}
	traffic = (traffic == 5) ? 0 : ((traffic == 4) ? 1 : ((traffic == 3) ? 2 : ((traffic == 2) ? 3 : 4)));
//	cout << traffic << endl;
	cout << "\n" << "--------------------------------------------------------------------" << "\n" << endl;
	
	label_setting(node_begin, traffic, shortest, before, visit, cnt);
	find_path(node_begin, node_end, traffic, shortest, before);
	
	ofstream output;
    output.open("t2_out.txt");
	
	if(ans.distance){
		cout << "Answer: \n\n沿途的所有node、累加距離、距離(與下一個node相距)、路幅、通行限制: \n\n" << endl;
		output << "Answer: \n\n沿途的所有node、累加距離、距離(與下一個node相距)、路幅、通行限制: \n\n" << endl;
	}
	
	
	if(ans.distance){
		cout << ans.pre_node << setw(17) << "（node" << node_end << "）" << endl;
		output << ans.pre_node << setw(17) << "（node" << node_end << "）" << endl;
	} 
	if(ans.distance){
		cout << "\n最短路徑長: " << ans.distance << endl;
		output << "\n最短路徑長: " << ans.distance << endl;
	}
	else{
		cout << ans.pre_node <<  endl;
		output << ans.pre_node << endl;
	}
		
	output.close();	
    input.close();
}

void label_setting(int source, int traffic, double *shortest, int *before, bool *visit, int cnt)
{
    for (int i = 0; i < cnt; i++) visit[i] = false;

    shortest[source] = 0;              // 設定起點的最短路徑長度
    before[source] = source;    // 設定起點是樹根（父親為自己）
    visit[source] = true;       // 將起點加入到最短路徑樹

    for (int k = 0; k < cnt - 1; k++)   // 將剩餘所有點加入到最短路徑樹
    {
        // 從既有的最短路徑樹，找出一條連外而且是最短的邊
        int a = -1, b = -1;
		string limit = "", width = "";
        double dis = -1;
		double min = 10000000000;

        // 找一個已在最短路徑樹上的點
        for (int i = 0; i < cnt; i++)
            if (visit[i])
                // 找一個不在最短路徑樹上的點
                for (int j = 0; j < cnt; j++)
                    if (!visit[j])
                    {
                    	if (shortest[i] + node[i][j] < min && node[i][j] != 0 && char(traffic_limit[i][j][traffic]) == '1')
                        {
                            a = i;  // 記錄這一條邊
                            b = j;
                            min = shortest[i] + node[i][j];
                            dis = node[i][j];
                            width = traffic_len[i][j];
                            limit = traffic_limit[i][j];
                        }
//                    	cout << char(traffic_limit[i][j][traffic]) << " " << a << " " << b << endl;
					}
                        
        // 起點有連通的最短路徑都已找完
        if (a == -1 || b == -1) break;
        //      // 不連通即是最短路徑長度無限長
        //      if (min == 1e9) break;
		pre_distance[b] = dis;
		pre_width[b] = width;
		pre_limit[b] = limit;
        shortest[b] = min;         // 儲存由起點到b點的最短路徑長度
        before[b] = a;      // b點是由a點延伸過去的
        visit[b] = true;    // 把b點加入到最短路徑樹之中
    }
}

void find_path(int source, int x, int traffic, double *shortest, int *before)   // 印出由起點到x點的最短路徑
{
	if(before[x] == -1){
		ans.pre_node = "從'node" + to_string(source) + "'出發選擇（" + ((traffic == 0) ? "巴士" : ((traffic == 1) ? "轎車" : ((traffic == 2) ? "機車" : ((traffic == 3) ? "腳踏車" : "步行")))) + "）當作交通方式沒有路可以到達'node" + to_string(x) + "'";
		ans.distance = 0;
		return;
	}
	
    if (x != before[x]) 
        find_path(source, before[x], traffic, shortest, before);
	
	if(first){
		first = 0;
	}
	else{
		ans.pre_node += "（node" + to_string(before[x]) + "、"  + to_string(shortest[x])  + "、" + to_string(pre_distance[x]) + "、" + pre_width[x] + "、" + pre_limit[x]  + "）"  + "\n\n"  + "              ↓" + "\n\n";  
    	ans.distance = shortest[x];
	}
}

string to_string(double value){
	stringstream tmp;  
  	tmp << value;  
	string tmp_str;  
	tmp >> tmp_str; 
	return tmp_str;
}
