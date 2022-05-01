//S0831007

#include "PatientAccount.h"

#ifndef Surgery_h
#define Surgery_h

class Surgery{
private:
    int surgeryType;
    double surgeryCost[5];
public:
    Surgery();
    int getSurgeryType();
    void updateAccount(PatientAccount& patientAccount, int type);
};

#endif /* Surgery_h */
