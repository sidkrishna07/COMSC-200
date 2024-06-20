#ifndef SIDDHARTH_KRISHNA_DIE_H
#define SIDDHARTH_KRISHNA_DIE_H

#include <cstdlib>
#include <ctime>

class Die {
private:
    int sides; // Comment 1: Number of sides on the die
    int value; // Comment 2: The die's value

public:
    // Comment 3: Constructor which is used for initilaize die with number of sides and also does the intiiall roll
    Die(int numSides);

    // Comment 4: Responsible for seting the number of sides and performing a roll
    void setSides(int numSides);

    // Comment 5: Simulates the rolling of the die
    void roll();

    // Comment 6: Its job is to return the number of sides
    int getSides() const;

    // Comment 7: It returns the die's value
    int getValue() const;
};

#endif // SIDDHARTH_KRISHNA_DIE_H