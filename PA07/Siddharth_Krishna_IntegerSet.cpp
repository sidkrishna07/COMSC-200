//Comment 2: This includes the necessary headers needed for this program.
#include <iostream>
#include <vector>
#include "Siddharth_Krishna_IntegerSet.h"

//Comment 3: This is the default constructor for the IntegerSet class
IntegerSet::IntegerSet() : set(101, false) {}

//Comment 4: This is a constructor for the IntegerSet class which intializes set with given elements
IntegerSet::IntegerSet(const int elements[], int size) : set(101, false) {
    for (int i = 0; i < size; ++i) {
        if (elements[i] >= 0 && elements[i] <= 100) {
            set[elements[i]] = true;
        } else {
            std::cout << "Invalid insert attempted!" << std::endl;
        }
    }
}

//Comment 5: This returns the union of two IntegerSet objects
IntegerSet IntegerSet::unionOfSets(const IntegerSet& other) const {
    IntegerSet result;
    for (int i = 0; i < 101; ++i) {
        result.set[i] = set[i] || other.set[i];
    }
    return result;
}

//Comment 6: It is responsible for returning the intersection of two IntegerSet objects
IntegerSet IntegerSet::intersectionOfSets(const IntegerSet& other) const {
    IntegerSet result;
    for (int i = 0; i < 101; ++i) {
        result.set[i] = set[i] && other.set[i];
    }
    return result;
}

//comment 7: This inserts an element into the set
void IntegerSet::insertElement(int k) {
    if (k >= 0 && k <= 100) {
        set[k] = true;
    } else {
        std::cout << "Invalid Element" << std::endl;
    }
}

//comment 8: It deletes an element from the set
void IntegerSet::deleteElement(int k) {
    if (k >= 0 && k <= 100) {
        set[k] = false;
    }
}

//comment 9: This is responsible for printing the set
void IntegerSet::printSet() const {
    bool empty = true;
    std::cout << "{ ";
    for (int i = 0; i < 101; ++i) {
        if (set[i]) {
            std::cout << i << " ";
            empty = false;
        }
    }
    if (empty) {
        std::cout << "---";
    }
    std::cout << "}" << std::endl;
}

//comment 10: Thhis checks if there are two IntegerSet objects that are equal
bool IntegerSet::isEqualTo(const IntegerSet& other) const {
    for (int i = 0; i < 101; ++i) {
        if (set[i] != other.set[i]) {
            return false;
        }
    }
    return true;
}

//comment 11: It takes user input in order to populate the set
void IntegerSet::inputSet() {
    int element;
    std::cout << "Enter an element (-1 to end): ";
    while (true) {
        std::cin >> element;
        if (element == -1) break;
        insertElement(element);
        std::cout << "Enter an element (-1 to end): ";
    }
    std::cout << "Entry complete" << std::endl;
}