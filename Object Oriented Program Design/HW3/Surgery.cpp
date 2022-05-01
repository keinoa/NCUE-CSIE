//S0831007 �L�t�� 

#include "Surgery.h"

Surgery::Surgery(){
    for (int i = 0; i < 5; i++) {
        surgeryCost[i] = 500 + (i+1) * 100;
    }
}

int Surgery::getSurgeryType(){
    int choice;
    cout<<"\n---------Type of surgery---------"<<endl;
    cout<<"1: ��NA\t"<<this->surgeryCost[0]<<" ��"<<endl;
    cout<<"2: ��NB\t"<<this->surgeryCost[1]<<" ��"<<endl;
    cout<<"3: ��NC\t"<<this->surgeryCost[2]<<" ��"<<endl;
    cout<<"4: ��ND\t"<<this->surgeryCost[3]<<" ��"<<endl;
    cout<<"5: ��NF\t"<<this->surgeryCost[4]<<" ��"<<endl;
//    cout<<"--------------------------------"<<endl;
    cout<<"\nChoice a type of surgery (1~5): ";
    cin>>choice;
    while (choice<1||choice>5) {
        cout<<"Legal value are 1~5"<<endl;
        
        cout<<"Choice a type of surgery (1~5): ";
        cin>>choice;
    }
    return choice;
}

void Surgery::updateAccount(PatientAccount& patientAccount, int type){
    patientAccount.updateCharges(surgeryCost[type-1]);
}
