#include "Siddharth_Krishna_Die.h"

// Constructor that accepts the number of sides and performs an initial roll
Die::Die(int numSides) {
    sides = numSides;
    roll();
}

// Sets the number of sides and performs a roll
void Die::setSides(int numSides) {
    sides = numSides;
    roll();
}

// Simulates the rolling of the die
void Die::roll() {
    value = (rand() % sides) + 1;
}

// Returns the number of sides
int Die::getSides() const {
    return sides;
}

// Returns the die's value
int Die::getValue() const {
    return value;
}