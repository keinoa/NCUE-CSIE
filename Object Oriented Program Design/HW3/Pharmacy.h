//S0854047 ªô¸t´Q 

#include "PatientAccount.h"

#ifndef Pharmacy_h
#define Pharmacy_h

class Pharmacy{
private:
    int PharmacyType;
    double PharmacyCost[5];
public:
    Pharmacy();
    int getPharmacyType();
    void updateAccount(PatientAccount& patientAccount, int type);
};

#endif
