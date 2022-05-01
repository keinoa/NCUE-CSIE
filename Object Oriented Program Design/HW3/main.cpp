/*
��u�T_S0831007_�L�t�� -> Surgery.h & Surgery.cpp
��u�T_S0831037_���f�� -> PatientAccount.h & PatientAccount.cpp
��u�T_S0854046_�c�J�} -> main.cpp 
��u�T_S0854047_���t�Q -> Pharmacy.h & Pharmacy.cpp

�J�쪺���D : 
1.�b main function�� include �Ҧ��� ".h"�ɮ� ���|�X�{���D�A���Oinclude".cpp"�ɴN�|���\ 
2.�]���Q�פ��T��A�ɭP�b���g���L�{���J��ܦh���D�A�p 
  (1)�ʤ֨禡, sol:���򪺰Q�פ��ɻ�  
  (2)updateAccount�禡���ǭȲ��`, sol:�q����b PatientAccount�� get_Patient_Display�����ե� updateCharges��s Total_Cost�A
    �|�P Surgery�M Pharmacy���� updateAccount�̪� updateCharges�o�ͽĬ�A�ɭP Total_Cost���ȳQ�л\�A�̫᪽���b PatientAccount�]�s�W updateAccount
    �b main���եΨӸѨM�����D�C 
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
