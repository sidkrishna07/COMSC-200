// Comment 1: This file contains the class definition for the Account class. 
#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account {
public:
    Account(double balance = 0.0);
    void credit(double amount);
    void debit(double amount);
    double getBalance() const;

    
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