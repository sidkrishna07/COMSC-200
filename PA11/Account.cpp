#include "Account.h"

Account::Account(double balance) : balance(balance) {}

// Comment 2: This function adds the amount to the balance
void Account::credit(double amount) {
    balance += amount;
}
// Comment 3: This function subtracts the amount from the balance
void Account::debit(double amount) {
    if (amount <= balance) {
        balance -= amount;
    } else {
        std::cout << "Debit amount exceeded account balance." << std::endl;
    }
}

//Comment 4: This function returns the balance
double Account::getBalance() const {
    return balance;
}

// Comment 5: This function overloads the insertion operator
std::ostream& operator<<(std::ostream& os, const Account& account) {
    os << account.balance;
    return os;
}

// Comment 6: This function overloads the += operator
Account& Account::operator+=(double amount) {
    credit(amount);
    return *this;
}

// Comment 7: This function overloads the -= operator
Account& Account::operator-=(double amount) {
    debit(amount);
    return *this;
}

// Comment 8: This function overloads the + operator
Account Account::operator+(double amount) const {
    Account temp = *this;
    temp += amount;
    return temp;
}

// Comment 9: This function overloads the - operator
Account Account::operator-(double amount) const {
    Account temp = *this;
    temp -= amount;
    return temp;
}

// Comment 10: This function overloads the = operator
Account& Account::operator=(const Account& other) {
    if (this != &other) {
        balance = other.balance;
    }
    return *this;
}