// S0831037 ��u�T ���f�� 

#include "PatientAccount.h"

PatientAccount::PatientAccount(double dr, int num, int day, string name){
	this->daily_rate = dr;
	this->patient_number = num;
	this->days = day;
	this->patient_name = name;
}

double PatientAccount::get_daily_rate(){
	cout << "4.�п�J��|�C��O��: ";
	cin >> daily_rate;
	return daily_rate;
}

int PatientAccount::get_days(){
	cout << "2.�п�J��|�Ѽ�: ";
	cin >> days;
	return days;
}

int PatientAccount::get_patient_number(){
	cout << "3.�п�J�f�H�s��(Please input integer): ";
	cin >> patient_number;
	return patient_number;
}

string PatientAccount::get_patient_name(){
	cout << "1.�п�J�f�H�W��: ";
	cin >> patient_name;
	return patient_name;
}

double PatientAccount::get_Patient_Display(){
	PatientAccount Patient(get_daily_rate(), get_patient_number(), get_days(), get_patient_name());

	Patient_Cost = days * daily_rate;
	cout << "# ��|�`�O�� => $"<<Patient_Cost<<endl; 
	return Patient_Cost;
}

void PatientAccount::updateAccount(PatientAccount& patientAccount, double cost){
    patientAccount.updateCharges(cost);
}


void PatientAccount::updateCharges(double charge){
	bool check;
	if(check==true){
		surgery_cost=charge;
		check=false;
	}
	else{
		pharmacy_cost=charge;
		check=true;
	}
	Total_Cost += charge;
}

void PatientAccount::display(){
	cout << "\n******************************************"<<endl;
	cout << "-�f�H�s��:        " << patient_number << endl;
	cout << "-�f�H�W��:        " << patient_name << endl;
	cout << "-��|�Ѽ�:        " << days << " ��" << endl;
	cout << "-��|�C��O��:    $ " << daily_rate << endl;
	cout << "-��N�O��:	  $ " << surgery_cost << endl;
	cout << "-�Ī��O��:    	  $ " << pharmacy_cost << endl;
	cout << "=> �`��O:        $ " << Total_Cost << endl;
	cout << "\n******************************************"<<endl;
}
