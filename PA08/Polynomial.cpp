#include "Polynomial.h"
#include <algorithm>
#include <iostream>

// Comment 2: This is a constructor that initializes an empty polynomial object.
Polynomial::Polynomial() {}

// Comment 3: This is a destructor that cleans up the polynomial object.
Polynomial::~Polynomial() {}

// Comment 4: This adds a term to the polynomial if the coefficient is not zero and then combines like terms.
void Polynomial::addTerm(int coefficient, int exponent) {
    if (coefficient != 0) {
        terms.push_back(Term(coefficient, exponent));
        combineLikeTerms();
    }
}

// Comment 5: This is responsible for combining like terms by adding coefficients of terms with the same exponent.
void Polynomial::combineLikeTerms() {
    // Sorts the terms in descending order by exponent.
    std::sort(terms.begin(), terms.end(), [](const Term& a, const Term& b) {
        return a.exponent > b.exponent;
    });

    // Comment6: This combines terms with the same exponent.
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

// Comment 7: This overloads the + operator to add two polynomials and return the result.
Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result = *this;
    for (const Term& term : other.terms) {
        result.addTerm(term.coefficient, term.exponent);
    }
    return result;
}

// Comment 8: This overloads the - operator to subtract one polynomial from another and return the result.
Polynomial Polynomial::operator-(const Polynomial& other) const {
    Polynomial result = *this;
    for (const Term& term : other.terms) {
        result.addTerm(-term.coefficient, term.exponent);
    }
    return result;
}

// Comment 9: This overloads the += operator to add another polynomial to this polynomial.
Polynomial& Polynomial::operator+=(const Polynomial& other) {
    *this = *this + other;
    return *this;
}

// Comment 10: This overloads the -= operator to subtract another polynomial from this polynomial.
Polynomial& Polynomial::operator-=(const Polynomial& other) {
    *this = *this - other;
    return *this;
}

// Comment 11: This overloads the = operator to assign one polynomial to another.
Polynomial& Polynomial::operator=(const Polynomial& other) {
    if (this != &other) {
        terms = other.terms;
    }
    return *this;
}

// Comment 12: This prompts tuser to enter terms for the polynomial and adds them.
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
    std::cout << std::endl;
}

// Comment 13: This prints the polynomial
void Polynomial::printPolynomial() const {
    if (terms.empty()) {
        std::cout << "0";
        return;
    }

    bool first = true;
    
    for (const auto& term : terms) {
        if (term.exponent == 0) {
            std::cout << term.coefficient;
            first = false;
            break;
        }
    }

    
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

//Comment 14: This overloads the << operator to print the polynomial to an output stream.
std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
    if (poly.terms.empty()) {
        os << "0";
        return os;
    }

    bool first = true;
    
    for (const auto& term : poly.terms) {
        if (term.exponent == 0) {
            os << term.coefficient;
            first = false;
            break;
        }
    }

    // Comment 15: This is responsible for printing rest of terms.
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