#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

// Comment 8: This is responsible for represening a bank account and has methods for managing the account balance.
class CheckingAccount : public Account {
public:
    CheckingAccount(double initialBalance, double fee); 
    void credit(double amount); 
    bool debit(double amount); 

private:
    double transactionFee; 
};

#endif