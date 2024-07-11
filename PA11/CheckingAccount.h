#ifndef CHECKINGACCOUNT_H
#define CHECKINGACCOUNT_H

#include "Account.h"

class CheckingAccount : public Account {
public:
    CheckingAccount(double balance = 0.0, double fee = 0.0);
    void chargeFee();

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const CheckingAccount& account);
    CheckingAccount& operator+=(double amount);
    CheckingAccount& operator-=(double amount);
    CheckingAccount operator+(double amount) const;
    CheckingAccount operator-(double amount) const;
    CheckingAccount& operator=(const CheckingAccount& other);

private:
    double fee;
};

#endif