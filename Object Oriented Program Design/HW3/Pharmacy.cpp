//S0854047 邱聖崴
 
#include "Pharmacy.h"

Pharmacy::Pharmacy(){
    for (int i = 0; i < 5; i++) {
        PharmacyCost[i] = (i+1) * 100;
    }
}

int Pharmacy::getPharmacyType(){
    int choice;
	cout << "\n----------Medication Menu----------" << endl;
    cout << "1: 藥物A\t" << this->PharmacyCost[0] << " 元" << endl;
    cout << "2: 藥物B\t" << this->PharmacyCost[1] << " 元" << endl;
    cout << "3: 藥物C\t" << this->PharmacyCost[2] << " 元" << endl;
    cout << "4: 藥物D\t" << this->PharmacyCost[3] << " 元" << endl;
    cout << "5: 藥物E\t" << this->PharmacyCost[4] << " 元" << endl;
    cout<<"\nChoice a type of Pharmacy (1~5): ";
    cin>>choice;
    while (choice<1||choice>5) {
        cout<<"請輸入1~5"<<endl;
        
        cout<<"Choose a type of Pharmacy (1~5): ";
        cin>>choice;
    }
    return choice;
}

void Pharmacy::updateAccount(PatientAccount& patientAccount, int type){
    patientAccount.updateCharges(PharmacyCost[type-1]);
}


