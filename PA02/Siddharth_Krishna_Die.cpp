#include "Siddharth_Krishna_Die.h"

// Comment 10: Constructor which intializes die with given number of sides and performs the initial roll
Die::Die(int numSides) {
    sides = numSides;
    roll();
}

// Comment 11: Setting the number of sides and performing the roll
void Die::setSides(int numSides) {
    sides = numSides;
    roll();
}

// Comment 12: Responsible for actually simulating the rolling of the die
void Die::roll() {
    value = (rand() % sides) + 1;
}

// Comment 13: It is supposed to Return the number of sides
int Die::getSides() const {
    return sides;
}

// Comment 14: It is supposed to return the die's value
int Die::getValue() const {
    return value;
}