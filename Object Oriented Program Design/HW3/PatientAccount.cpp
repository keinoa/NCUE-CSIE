// S0831037 資工三 陳柏維 

#include "PatientAccount.h"

PatientAccount::PatientAccount(double dr, int num, int day, string name){
	this->daily_rate = dr;
	this->patient_number = num;
	this->days = day;
	this->patient_name = name;
}

double PatientAccount::get_daily_rate(){
	cout << "4.請輸入住院每日費用: ";
	cin >> daily_rate;
	return daily_rate;
}

int PatientAccount::get_days(){
	cout << "2.請輸入住院天數: ";
	cin >> days;
	return days;
}

int PatientAccount::get_patient_number(){
	cout << "3.請輸入病人編號(Please input integer): ";
	cin >> patient_number;
	return patient_number;
}

string PatientAccount::get_patient_name(){
	cout << "1.請輸入病人名稱: ";
	cin >> patient_name;
	return patient_name;
}

double PatientAccount::get_Patient_Display(){
	PatientAccount Patient(get_daily_rate(), get_patient_number(), get_days(), get_patient_name());

	Patient_Cost = days * daily_rate;
	cout << "# 住院總費用 => $"<<Patient_Cost<<endl; 
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
	cout << "-病人編號:        " << patient_number << endl;
	cout << "-病人名稱:        " << patient_name << endl;
	cout << "-住院天數:        " << days << " 天" << endl;
	cout << "-住院每日費用:    $ " << daily_rate << endl;
	cout << "-手術費用:	  $ " << surgery_cost << endl;
	cout << "-藥物費用:    	  $ " << pharmacy_cost << endl;
	cout << "=> 總花費:        $ " << Total_Cost << endl;
	cout << "\n******************************************"<<endl;
}
