// Comment 1: This file has integerSet class, which represents a set of integers and has various operations on sets such as union, intersection, insertion, deletion, printing, and comparison.
#ifndef INTEGERSET_H
#define INTEGERSET_H

#include <vector>

class IntegerSet {
private:
    std::vector<bool> set;

public:
    IntegerSet();
    IntegerSet(const int elements[], int size);
    IntegerSet unionOfSets(const IntegerSet& other) const;
    IntegerSet intersectionOfSets(const IntegerSet& other) const;
    void insertElement(int k);
    void deleteElement(int k);
    void printSet() const;
    bool isEqualTo(const IntegerSet& other) const;
    void inputSet();
};

#endif