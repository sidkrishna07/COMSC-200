#include "SavingsAccount.h"

//Comment 12: This constructor initializes the balance and interest rate
SavingsAccount::SavingsAccount(double balance, double interestRate)
    : Account(balance), interestRate(interestRate) {}

//Comment 13: This function calculates the interest
double SavingsAccount::calculateInterest() const {
    return getBalance() * interestRate;
}

//Comment 14: This function overloads the insertion operator
std::ostream& operator<<(std::ostream& os, const SavingsAccount& account) {
    os << account.getBalance();
    return os;
}

//Comment 15: This function overloads the += operator
SavingsAccount& SavingsAccount::operator+=(double amount) {
    credit(amount);
    return *this;
}

//Comment 16: This function overloads the -= operator
SavingsAccount& SavingsAccount::operator-=(double amount) {
    debit(amount);
    return *this;
}

//Comment 17: This function overloads the + operator
SavingsAccount SavingsAccount::operator+(double amount) const {
    SavingsAccount temp = *this;
    temp += amount;
    return temp;
}

//Comment 18: This function overloads the - operator
SavingsAccount SavingsAccount::operator-(double amount) const {
    SavingsAccount temp = *this;
    temp -= amount;
    return temp;
}

//Comment 19: This function overloads the = operator
SavingsAccount& SavingsAccount::operator=(const SavingsAccount& other) {
    if (this != &other) {
        Account::operator=(other);
        interestRate = other.interestRate;
    }
    return *this;
}