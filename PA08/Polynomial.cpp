#include "Polynomial.h"
#include <algorithm>
#include <iostream>

// Constructor
Polynomial::Polynomial() {}

// Destructor
Polynomial::~Polynomial() {}

// Add term to the polynomial
void Polynomial::addTerm(int coefficient, int exponent) {
    if (coefficient != 0) {
        terms.push_back(Term(coefficient, exponent));
        combineLikeTerms();
    }
}

// Combine like terms in the polynomial
void Polynomial::combineLikeTerms() {
    std::sort(terms.begin(), terms.end(), [](const Term& a, const Term& b) {
        return a.exponent > b.exponent;
    });

    std::vector<Term> combined;
    for (size_t i = 0; i < terms.size(); ++i) {
        if (combined.empty() || combined.back().exponent != terms[i].exponent) {
            combined.push_back(terms[i]);
        } else {
            combined.back().coefficient += terms[i].coefficient;
        }
    }
    terms = combined;
}

// Operator +
Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result = *this;
    for (const Term& term : other.terms) {
        result.addTerm(term.coefficient, term.exponent);
    }
    return result;
}

// Operator -
Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result = *this;
    for (const Term& term : other.terms) {
        result.addTerm(-term.coefficient, term.exponent);
    }
    return result;
}

// Operator +=
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

// Operator -=
Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

// Operator =
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        terms = other.terms;
    }
    return *this;
}

// Enter terms into the polynomial
void Polynomial::enterTerms() {
    int numTerms;
    std::cout << "Enter number of polynomial terms: ";
    std::cin >> numTerms;
    for (int i = 0; i < numTerms; ++i) {
        int coefficient, exponent;
        std::cout << "\nEnter coefficient: ";
        std::cin >> coefficient;
        std::cout << "Enter exponent: ";
        std::cin >> exponent;
        addTerm(coefficient, exponent);
    }
    std::cout << std::endl;  // Add extra newline here
}

// Print the polynomial
void Polynomial::printPolynomial() const {
    if (terms.empty()) {
        std::cout << "0";
        return;
    }

    bool first = true;
    // Print constant term first if it exists
    for (const auto& term : terms) {
        if (term.exponent == 0) {
            std::cout << term.coefficient;
            first = false;
            break;
        }
    }

    // Print the rest of the terms
    for (const auto& term : terms) {
        if (term.exponent != 0 && term.coefficient != 0) {
            if (term.coefficient > 0 && !first) {
                std::cout << "+";
            }
            std::cout << term.coefficient;
            if (term.exponent > 1) {
                std::cout << "x^" << term.exponent;
            } else if (term.exponent == 1) {
                std::cout << "x";
            }
            first = false;
        }
    }
    std::cout << std::endl;
}

// Overload << operator for output
std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    if (poly.terms.empty()) {
        os << "0";
        return os;
    }

    bool first = true;
    // Print constant term first if it exists
    for (const auto& term : poly.terms) {
        if (term.exponent == 0) {
            os << term.coefficient;
            first = false;
            break;
        }
    }

    // Print the rest of the terms
    for (const auto& term : poly.terms) {
        if (term.exponent != 0 && term.coefficient != 0) {
            if (term.coefficient > 0 && !first) {
                os << "+";
            }
            os << term.coefficient;
            if (term.exponent > 1) {
                os << "x^" << term.exponent;
            } else if (term.exponent == 1) {
                os << "x";
            }
            first = false;
        }
    }
    return os;
}