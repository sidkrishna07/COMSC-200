// Comment 1: This file is responsible for defining the Account class that represents a bank account and has methods for managing the account balance.
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
public:
    Account(double balance = 0.0);
    void credit(double amount);
    void debit(double amount);
    double getBalance() const;

    // Overloaded operators
    friend std::ostream& operator<<(std::ostream& os, const Account& account);
    Account& operator+=(double amount);
    Account& operator-=(double amount);
    Account operator+(double amount) const;
    Account operator-(double amount) const;
    Account& operator=(const Account& other);

private:
    double balance;
};

#endif