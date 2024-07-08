//Comment 17: The purpose of this file is to define a class for rational numbers and their arithmetic operations.

#ifndef RATIONALNUMBER_H
#define RATIONALNUMBER_H

#include <iostream>

class RationalNumber {
public:
    RationalNumber(int numerator = 0, int denominator = 1);

    void printRational() const;

    RationalNumber operator+(const RationalNumber &rhs) const;
    RationalNumber operator-(const RationalNumber &rhs) const;
    RationalNumber operator*(const RationalNumber &rhs) const;
    RationalNumber operator/(const RationalNumber &rhs) const;
    RationalNumber &operator=(const RationalNumber &rhs);

    bool operator<(const RationalNumber &rhs) const;
    bool operator>(const RationalNumber &rhs) const;
    bool operator<=(const RationalNumber &rhs) const;
    bool operator>=(const RationalNumber &rhs) const;
    bool operator==(const RationalNumber &rhs) const;
    bool operator!=(const RationalNumber &rhs) const;

    friend std::ostream& operator<<(std::ostream& os, const RationalNumber& rn);

private:
    int numerator;
    int denominator;

    void reduce();

    int gcd(int a, int b) const;
};

#endif 
