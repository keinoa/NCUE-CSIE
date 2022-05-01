// S0831037 資工三 陳柏維 

#include <iostream>
#include <string>
using namespace std;

#ifndef PatientAccount_h
#define PatientAccount_h

class PatientAccount{
	private:
		int days;
		int patient_number;
		string patient_name;
		double daily_rate;
		double Patient_Cost;
		double surgery_cost;
		double pharmacy_cost;
		
	public:
		double Total_Cost;
		PatientAccount(double dr = 0, int num = 0, int day = 0, string name = "");
		double get_daily_rate();
		int get_patient_number();
		int get_days();
		string get_patient_name();
		double get_Patient_Display();
		void updateCharges(double charge);
		void display();
		void updateAccount(PatientAccount& patientAccount, double cost);
};

#endif /* PatientAccount_h */

