// Comment 1: This file is responsible for defining the Account class that represents a bank account and has methods for managing the account balance.
#ifndef ACCOUNT_H
#define ACCOUNT_H

class Account {
public:
    Account(double initialBalance);
    void credit(double amount);
    bool debit(double amount);
    double getBalance() const;

private:
    double balance;
};

#endif

