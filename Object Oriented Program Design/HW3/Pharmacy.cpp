//S0854047 ���t�Q
 
#include "Pharmacy.h"

Pharmacy::Pharmacy(){
    for (int i = 0; i < 5; i++) {
        PharmacyCost[i] = (i+1) * 100;
    }
}

int Pharmacy::getPharmacyType(){
    int choice;
	cout << "\n----------Medication Menu----------" << endl;
    cout << "1: �Ī�A\t" << this->PharmacyCost[0] << " ��" << endl;
    cout << "2: �Ī�B\t" << this->PharmacyCost[1] << " ��" << endl;
    cout << "3: �Ī�C\t" << this->PharmacyCost[2] << " ��" << endl;
    cout << "4: �Ī�D\t" << this->PharmacyCost[3] << " ��" << endl;
    cout << "5: �Ī�E\t" << this->PharmacyCost[4] << " ��" << endl;
    cout<<"\nChoice a type of Pharmacy (1~5): ";
    cin>>choice;
    while (choice<1||choice>5) {
        cout<<"�п�J1~5"<<endl;
        
        cout<<"Choose a type of Pharmacy (1~5): ";
        cin>>choice;
    }
    return choice;
}

void Pharmacy::updateAccount(PatientAccount& patientAccount, int type){
    patientAccount.updateCharges(PharmacyCost[type-1]);
}


