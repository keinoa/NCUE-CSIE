#include <iostream>
#include <string>

using namespace std;

struct hw2{
	double score;
	string name;
};

float valid_detect(float num){
	while(!((cin >> num) && num == (int)num && num > 0)){
		cout << "���~! �п�J��0�j�������: ";
		cin.clear();
	}
	return num;
}

double valid_detect(double num){
	while(!((cin >> num) && num == (int)num && num >= 0)){
		cout << "���~! �п�J�����: ";
		cin.clear();
	}
	return num;
}

double sort_avg(hw2 *self, int cnt){
	for(int i = 0 ; i < cnt - 1; i++){
		for(int j = 0 ; j < cnt - i - 1; j++){
			if(self[j].score < self[j+1].score){
				hw2 tmp = self[j];
				self[j] = self[j+1];
				self[j+1] = tmp;				
			}
		}
	}
	double avg = 0;
	for(int i = 0; i < cnt; i++){
		avg += self[i].score;
	}
	return avg / cnt;
}

main(){
	float num;
	cout << "�п�J��ƭӼ�: ";
	num = valid_detect(num);
	int cnt = int(num);
	hw2 *self = new hw2[cnt];
	for(int i = 0; i < cnt; i++){
		cout << "�п�J student #" << i + 1 << " �W�r: ";
		cin >> self[i].name;
		cout << "�п�J student #" << i + 1 << " ����: ";
		self[i].score = valid_detect(self[i].score);
	}
	
	double avg = sort_avg(self, cnt);
	cout << "\n�H���ƱƧ�: " << endl;
	
	for(int i = 0; i < cnt; i++){
		cout << "student #" << i + 1 << " �W�r: " << self[i].name << ", ����: " << self[i].score << " ��" << endl;
	}
	cout << "\n��������: " << avg << endl; 
	cout << "�̰����ǥ�: " << self[0].name << ", �o��: " << self[0].score << " ��" << endl;
	cout << "�̧C���ǥ�: " << self[cnt-1].name << ", �o��: " << self[cnt-1].score << " ��" << endl;
}
