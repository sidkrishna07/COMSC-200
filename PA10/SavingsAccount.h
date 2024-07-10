//Comment 2: The file defines a class called SavingsAccount which inherits from Account class and includes a function to calculate the interest.
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(double initialBalance, double rate);
    double calculateInterest() const;

private:
    double interestRate;
};

#endif