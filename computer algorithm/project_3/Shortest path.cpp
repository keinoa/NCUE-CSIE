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
double node[100][100]; //���V�����|��
int index_col = 0, index_row = 0;
bool first = true;
string arr[1000][5];
string traffic_len[100][100];
string traffic_limit[100][100]; 

double pre_distance[100]; //�������������Z�� 
string pre_width[100]; //���������������e 
string pre_limit[100]; //������ܸ�����q���� 

void label_setting(int source, int traffic, double *shortest, int *before, bool *visit, int cnt);
void find_path(int source, int x, int traffic, double *shortest, int *before); 
string to_string(double value);
 
int main() {
    ifstream input;
	input.open("test3.txt");
	if(input == NULL){
		cout << "�䤣���ɮ׸��" << endl;
		return 0; 
	}
    
    //	node�� 
    int cnt = 0;
	input >> cnt;
	cout << cnt << endl;
	cout << "\n" << "--------------------------------------------------------------------" << "\n" << endl;
	
	//	�s�J�Ҧ�data 
	string tmp;
	while(input >> tmp){
		arr[index_row][index_col % 5] = tmp; 
		index_col++;
		index_row = ((index_col % 5 == 0) ? index_row + 1 : index_row);
	}
	//	�P�_�s�J��data�O�_���榡���~ 
	cout << "��J��data: " << endl;
	for(int i = 0; i < index_row; i++){
		int tmp_width[5] = {6, 4, 2, 1.5, 0.5};
		for(int j = 0; j < 5; j++){
			if(char(arr[i][4][j]) == '1' && atof(arr[i][3].c_str()) < tmp_width[j]){
				cout << "��J���~���T�����e: ";
				for(int k = 0; k < 5; k++)
					cout << arr[i][k] << " ";
				return 0;	
			}
		}
		if(arr[i][0] == arr[i][1] || atoi(arr[i][0].c_str()) < 0 || atoi(arr[i][0].c_str()) >= cnt || atoi(arr[i][1].c_str()) < 0 || atoi(arr[i][1].c_str()) >= cnt){
			cout << "node��J���~: ";
			for(int j = 0; j < 5; j++)
				cout << arr[i][j] << " ";
			return 0;	
		}
		else if(atof(arr[i][2].c_str()) <= 0 || atof(arr[i][3].c_str()) <= 0){
			cout << "��J���~�Z���B���T�Ȼݧ��������: ";
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
	
	//	�C��node�����Z�� 
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
	cout << "node�������Z��&��q����: " << endl;
	for(int i = 0; i < cnt; i++){
		for(int j = 0; j < cnt; j++){
			if(i == j)
				continue;
			cout << "node" << i << "->node" << j << " : " << node[i][j] << "�]" << traffic_limit[i][j] << "�^" << endl;
		}
	}
	
	double shortest[cnt]; //�����֭p���̵u���| 
	int before[cnt]; //�����e�@�`�I  
	bool visit[cnt]; //�O�_���X�L�Ӹ�  
	
	
	cout << "\n" << "--------------------------------------------------------------------" << "\n" << endl;
	int node_begin, node_end, traffic;
	while(1){
		cout << "�п�J�_�l�`�I( 0 ~ " << cnt-1 << " ): ";
		cin >> node_begin ;
		cout << "�п�J�ت��`�I( 0 ~ " << cnt-1 << " ): ";
		cin >> node_end;
		cout << "�п�J��q�覡( 5.�ڤh�B4.�⨮�B3.�����B2.�}�񨮡B1.�B�� ): ";
		cin >> traffic;
		if(node_begin == node_end || node_begin < 0 || node_begin >= cnt || node_end < 0 || node_end >= cnt || traffic < 1 || traffic > 5){
			cout << "��J���~�Э��s��J: " << endl;
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
		cout << "Answer: \n\n�u�~���Ҧ�node�B�֥[�Z���B�Z��(�P�U�@��node�۶Z)�B���T�B�q�歭��: \n\n" << endl;
		output << "Answer: \n\n�u�~���Ҧ�node�B�֥[�Z���B�Z��(�P�U�@��node�۶Z)�B���T�B�q�歭��: \n\n" << endl;
	}
	
	
	if(ans.distance){
		cout << ans.pre_node << setw(17) << "�]node" << node_end << "�^" << endl;
		output << ans.pre_node << setw(17) << "�]node" << node_end << "�^" << endl;
	} 
	if(ans.distance){
		cout << "\n�̵u���|��: " << ans.distance << endl;
		output << "\n�̵u���|��: " << ans.distance << endl;
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

    shortest[source] = 0;              // �]�w�_�I���̵u���|����
    before[source] = source;    // �]�w�_�I�O��ڡ]���ˬ��ۤv�^
    visit[source] = true;       // �N�_�I�[�J��̵u���|��

    for (int k = 0; k < cnt - 1; k++)   // �N�Ѿl�Ҧ��I�[�J��̵u���|��
    {
        // �q�J�����̵u���|��A��X�@���s�~�ӥB�O�̵u����
        int a = -1, b = -1;
		string limit = "", width = "";
        double dis = -1;
		double min = 10000000000;

        // ��@�Ӥw�b�̵u���|��W���I
        for (int i = 0; i < cnt; i++)
            if (visit[i])
                // ��@�Ӥ��b�̵u���|��W���I
                for (int j = 0; j < cnt; j++)
                    if (!visit[j])
                    {
                    	if (shortest[i] + node[i][j] < min && node[i][j] != 0 && char(traffic_limit[i][j][traffic]) == '1')
                        {
                            a = i;  // �O���o�@����
                            b = j;
                            min = shortest[i] + node[i][j];
                            dis = node[i][j];
                            width = traffic_len[i][j];
                            limit = traffic_limit[i][j];
                        }
//                    	cout << char(traffic_limit[i][j][traffic]) << " " << a << " " << b << endl;
					}
                        
        // �_�I���s�q���̵u���|���w�䧹
        if (a == -1 || b == -1) break;
        //      // ���s�q�Y�O�̵u���|���׵L����
        //      if (min == 1e9) break;
		pre_distance[b] = dis;
		pre_width[b] = width;
		pre_limit[b] = limit;
        shortest[b] = min;         // �x�s�Ѱ_�I��b�I���̵u���|����
        before[b] = a;      // b�I�O��a�I�����L�h��
        visit[b] = true;    // ��b�I�[�J��̵u���|�𤧤�
    }
}

void find_path(int source, int x, int traffic, double *shortest, int *before)   // �L�X�Ѱ_�I��x�I���̵u���|
{
	if(before[x] == -1){
		ans.pre_node = "�q'node" + to_string(source) + "'�X�o��ܡ]" + ((traffic == 0) ? "�ڤh" : ((traffic == 1) ? "�⨮" : ((traffic == 2) ? "����" : ((traffic == 3) ? "�}��" : "�B��")))) + "�^��@��q�覡�S�����i�H��F'node" + to_string(x) + "'";
		ans.distance = 0;
		return;
	}
	
    if (x != before[x]) 
        find_path(source, before[x], traffic, shortest, before);
	
	if(first){
		first = 0;
	}
	else{
		ans.pre_node += "�]node" + to_string(before[x]) + "�B"  + to_string(shortest[x])  + "�B" + to_string(pre_distance[x]) + "�B" + pre_width[x] + "�B" + pre_limit[x]  + "�^"  + "\n\n"  + "              ��" + "\n\n";  
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
