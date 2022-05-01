#include <iostream>
#include <string>

using namespace std;

struct hw2{
	double score;
	string name;
};

float valid_detect(float num){
	while(!((cin >> num) && num == (int)num && num > 0)){
		cout << "錯誤! 請輸入比0大之正整數: ";
		cin.clear();
	}
	return num;
}

double valid_detect(double num){
	while(!((cin >> num) && num == (int)num && num >= 0)){
		cout << "錯誤! 請輸入正整數: ";
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
	cout << "請輸入資料個數: ";
	num = valid_detect(num);
	int cnt = int(num);
	hw2 *self = new hw2[cnt];
	for(int i = 0; i < cnt; i++){
		cout << "請輸入 student #" << i + 1 << " 名字: ";
		cin >> self[i].name;
		cout << "請輸入 student #" << i + 1 << " 分數: ";
		self[i].score = valid_detect(self[i].score);
	}
	
	double avg = sort_avg(self, cnt);
	cout << "\n以分數排序: " << endl;
	
	for(int i = 0; i < cnt; i++){
		cout << "student #" << i + 1 << " 名字: " << self[i].name << ", 分數: " << self[i].score << " 分" << endl;
	}
	cout << "\n平均分數: " << avg << endl; 
	cout << "最高分學生: " << self[0].name << ", 得分: " << self[0].score << " 分" << endl;
	cout << "最低分學生: " << self[cnt-1].name << ", 得分: " << self[cnt-1].score << " 分" << endl;
}
