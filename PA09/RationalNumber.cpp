#include "RationalNumber.h"
#include <iostream>
#include <stdexcept>

// Comment 1: This is a constructor that is used to initialize the rational number
RationalNumber::RationalNumber(int numerator, int denominator)
    : numerator(numerator), denominator(denominator) {
    if (denominator == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }
    reduce();
}

// Comment 2: This is used to print the function to display the rational number
void RationalNumber::printRational() const {
    if (denominator == 1) {
        std::cout << numerator;
    } else {
        std::cout << numerator << "/" << denominator;
    }
}

// Comment 3: This is the addition operator overload
RationalNumber RationalNumber::operator+(const RationalNumber &rhs) const {
    int newNumerator = numerator * rhs.denominator + rhs.numerator * denominator;
    int newDenominator = denominator * rhs.denominator;
    return RationalNumber(newNumerator, newDenominator);
}

// Comment 4: This is the subtraction operator overload
RationalNumber RationalNumber::operator-(const RationalNumber &rhs) const {
    int newNumerator = numerator * rhs.denominator - rhs.numerator * denominator;
    int newDenominator = denominator * rhs.denominator;
    return RationalNumber(newNumerator, newDenominator);
}

// Comment 5: This is the multiplication operator overload
RationalNumber RationalNumber::operator*(const RationalNumber &rhs) const {
    int newNumerator = numerator * rhs.numerator;
    int newDenominator = denominator * rhs.denominator;
    return RationalNumber(newNumerator, newDenominator);
}

// Comment 6: This is the division operator overload
RationalNumber RationalNumber::operator/(const RationalNumber &rhs) const {
    if (rhs.numerator == 0) {
        throw std::invalid_argument("Division by zero");
    }
    int newNumerator = numerator * rhs.denominator;
    int newDenominator = denominator * rhs.numerator;
    return RationalNumber(newNumerator, newDenominator);
}

// Comment 7: This is the assignment operator overload
RationalNumber &RationalNumber::operator=(const RationalNumber &rhs) {
    if (this != &rhs) {
        numerator = rhs.numerator;
        denominator = rhs.denominator;
        reduce();
    }
    return *this;
}

// Comment 8: This is the less than operator overload
bool RationalNumber::operator<(const RationalNumber &rhs) const {
    return numerator * rhs.denominator < rhs.numerator * denominator;
}

// Comment 9: This is the greater than operator overload
bool RationalNumber::operator>(const RationalNumber &rhs) const {
    return numerator * rhs.denominator > rhs.numerator * denominator;
}

// Comment 10: This is the less than or equal to operator overload
bool RationalNumber::operator<=(const RationalNumber &rhs) const {
    return numerator * rhs.denominator <= rhs.numerator * denominator;
}

// Comment 11: This is the greater than or equal to operator overload
bool RationalNumber::operator>=(const RationalNumber &rhs) const {
    return numerator * rhs.denominator >= rhs.numerator * denominator;
}

// Comment 12: This is the equality operator overload
bool RationalNumber::operator==(const RationalNumber &rhs) const {
    return numerator * rhs.denominator == rhs.numerator * denominator;
}

// Comment 13: This is the inequality operator overload
bool RationalNumber::operator!=(const RationalNumber &rhs) const {
    return !(*this == rhs);
}

// Comment 14: This is used to reduce the function to simplify the rational number
void RationalNumber::reduce() {
    int gcdValue = gcd(numerator, denominator);
    numerator /= gcdValue;
    denominator /= gcdValue;
    if (denominator < 0) {
        numerator = -numerator;
        denominator = -denominator;
    }
}

// Comment 15: This is the function to calculate the greatest common divisor
int RationalNumber::gcd(int a, int b) const {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Comment 16: This is the overload output stream operator to print the rational number
std::ostream& operator<<(std::ostream& os, const RationalNumber& rn) {
    if (rn.denominator == 1) {
        os << rn.numerator;
    } else {
        os << rn.numerator << "/" << rn.denominator;
    }
    return os;
}