#include <iostream>
using namespace std;

class patient{
	public :
		char user_choice; // 1 or 2
		double in_patient_days, daily_rate, medication_charges, services_charges, total_charges;
		
		void Set_Choice(char letter){
		    cin >> letter;
		    // Error check algorithim
		    while (letter != '1' && letter != '2')
		    {
		        // Explain error
		        cout << "ERROR: enter 1 or 2: ";
		        // Clear input stream
		        cin.clear();
		        // Receive input again
		        cin >> letter;
		    }
		    this->user_choice = letter;
		}
		
		double Valid_Detect(double num){
		    while(!(cin >> num) || num < 0)
		    {
		        cout << "Error. Number must not be "
		             << " 0 or greater:";
		        cin.clear();
		    }
		    return num;
		}
		
		double Total(double m, double s){
		     return m + s;
		}
		
		double Total(double i, double d, double m, double s){
		     return i * d + m + s;
		}
};

int main()
{
	patient obj;
	
    cout << "Where you admitted as an in-patient or an out-patient?\n" << endl
         << "Enter 1. in-patient 2. out-patient: ";
     
    obj.Set_Choice(obj.user_choice);
	
	if(obj.user_choice == '1'){
		cout << "Number of days spent in the hospital: ";
        obj.in_patient_days = obj.Valid_Detect(obj.in_patient_days);
        cout << "The daily rate: $ ";
        obj.daily_rate = obj.Valid_Detect(obj.daily_rate);
	}
	cout << "Hospital medication charges: $ ";
	obj.medication_charges = obj.Valid_Detect(obj.medication_charges);
    cout << "Charges for hospital services: $ ";
    obj.services_charges = obj.Valid_Detect(obj.services_charges);
    
	obj.total_charges = (obj.user_choice == '1') 
	? obj.Total(obj.in_patient_days, obj.daily_rate, obj.medication_charges, obj.services_charges) 
	: obj.Total(obj.medication_charges, obj.services_charges);
	
	cout << "\nÁ`ªá¶O = $ " << obj.total_charges << endl;
}

