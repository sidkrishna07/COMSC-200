#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"

class SavingsAccount : public Account {
public:
    SavingsAccount(double balance = 0.0, double interestRate = 0.0);
    double calculateInterest() const;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const SavingsAccount& account);
    SavingsAccount& operator+=(double amount);
    SavingsAccount& operator-=(double amount);
    SavingsAccount operator+(double amount) const;
    SavingsAccount operator-(double amount) const;
    SavingsAccount& operator=(const SavingsAccount& other);

private:
    double interestRate;
};

#endif