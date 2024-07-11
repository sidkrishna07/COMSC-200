#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(double balance, double fee)
    : Account(balance), fee(fee) {}

void CheckingAccount::chargeFee() {
    debit(fee);
}

std::ostream& operator<<(std::ostream& os, const CheckingAccount& account) {
    os << account.getBalance();
    return os;
}

CheckingAccount& CheckingAccount::operator+=(double amount) {
    credit(amount);
    return *this;
}

CheckingAccount& CheckingAccount::operator-=(double amount) {
    debit(amount);
    return *this;
}

CheckingAccount CheckingAccount::operator+(double amount) const {
    CheckingAccount temp = *this;
    temp += amount;
    return temp;
}

CheckingAccount CheckingAccount::operator-(double amount) const {
    CheckingAccount temp = *this;
    temp -= amount;
    return temp;
}

CheckingAccount& CheckingAccount::operator=(const CheckingAccount& other) {
    if (this != &other) {
        Account::operator=(other);
        fee = other.fee;
    }
    return *this;
}