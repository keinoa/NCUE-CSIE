/*
資工三_S0831007_林聖凱 -> Surgery.h & Surgery.cpp
資工三_S0831037_陳柏維 -> PatientAccount.h & PatientAccount.cpp
資工三_S0854046_盧泇良 -> main.cpp 
資工三_S0854047_邱聖崴 -> Pharmacy.h & Pharmacy.cpp

遇到的問題 : 
1.在 main function中 include 所有的 ".h"檔案 都會出現問題，但是include".cpp"檔就會成功 
2.因為討論不確實，導致在撰寫的過程中遇到很多問題，如 
  (1)缺少函式, sol:後續的討論中補齊  
  (2)updateAccount函式的傳值異常, sol:從原先在 PatientAccount中 get_Patient_Display直接調用 updateCharges更新 Total_Cost，
    會與 Surgery和 Pharmacy中的 updateAccount裡的 updateCharges發生衝突，導致 Total_Cost的值被覆蓋，最後直接在 PatientAccount也新增 updateAccount
    在 main中調用來解決此問題。 
*/

#include <bits/stdc++.h>
#include "PatientAccount.cpp"
#include "Surgery.cpp"
#include "Pharmacy.cpp"

int main(){
	int cnt = 1;
	char again;
	do{
		cout<<endl;
		cout<<"("<<cnt<<").-------------------------------------------------------------------"<<endl;
		cout<<endl;
		PatientAccount info_1;
		Surgery info_2;
		Pharmacy info_3;
		
		info_1.updateAccount(info_1, info_1.get_Patient_Display());
		info_2.updateAccount(info_1, info_2.getSurgeryType());
		info_3.updateAccount(info_1, info_3.getPharmacyType());
		info_1.display();
		
		cout<<"Do you want to try another patient?(y/n):";
		cin>>again;
		cnt++;
		info_1.Total_Cost=0;
	}while(again=='y');
	return 0;
}
