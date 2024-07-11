#include "Account.h"

Account::Account(double balance) : balance(balance) {}

void Account::credit(double amount) {
    balance += amount;
}

void Account::debit(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        std::cout << "Debit amount exceeded account balance." << std::endl;
    }
}

double Account::getBalance() const {
    return balance;
}

std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << account.balance;
    return os;
}

Account& Account::operator+=(double amount) {
    credit(amount);
    return *this;
}

Account& Account::operator-=(double amount) {
    debit(amount);
    return *this;
}

Account Account::operator+(double amount) const {
    Account temp = *this;
    temp += amount;
    return temp;
}

Account Account::operator-(double amount) const {
    Account temp = *this;
    temp -= amount;
    return temp;
}

Account& Account::operator=(const Account& other) {
    if (this != &other) {
        balance = other.balance;
    }
    return *this;
}