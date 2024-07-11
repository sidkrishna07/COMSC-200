#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double balance, double interestRate)
    : Account(balance), interestRate(interestRate) {}

double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
}

std::ostream& operator<<(std::ostream& os, const SavingsAccount& account) {
    os << account.getBalance();
    return os;
}

SavingsAccount& SavingsAccount::operator+=(double amount) {
    credit(amount);
    return *this;
}

SavingsAccount& SavingsAccount::operator-=(double amount) {
    debit(amount);
    return *this;
}

SavingsAccount SavingsAccount::operator+(double amount) const {
    SavingsAccount temp = *this;
    temp += amount;
    return temp;
}

SavingsAccount SavingsAccount::operator-(double amount) const {
    SavingsAccount temp = *this;
    temp -= amount;
    return temp;
}

SavingsAccount& SavingsAccount::operator=(const SavingsAccount& other) {
    if (this != &other) {
        Account::operator=(other);
        interestRate = other.interestRate;
    }
    return *this;
}