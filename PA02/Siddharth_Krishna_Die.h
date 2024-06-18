#ifndef SIDDHARTH_KRISHNA_DIE_H
#define SIDDHARTH_KRISHNA_DIE_H

#include <cstdlib>
#include <ctime>

class Die {
private:
    int sides; // Number of sides on the die
    int value; // The die's value

public:
    // Constructor that accepts the number of sides and performs an initial roll
    Die(int numSides);

    // Sets the number of sides and performs a roll
    void setSides(int numSides);

    // Simulates the rolling of the die
    void roll();

    // Returns the number of sides
    int getSides() const;

    // Returns the die's value
    int getValue() const;
};

#endif // SIDDHARTH_KRISHNA_DIE_H