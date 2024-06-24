#include "Siddharth_Krishna_Coin.h"
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()

// Default constructor
Coin::Coin() {
    // Initialize random seed
    srand(static_cast<unsigned int>(time(0)));
    // Randomly determine the side of the coin
    toss();
}

// Member function to simulate the tossing of the coin
void Coin::toss() {
    int randomValue = rand() % 2; // Generate a random number: 0 or 1
    if (randomValue == 0) {
        sideUp = "heads";
    } else {
        sideUp = "tails";
    }
}

// Member function to get the current side facing up
string Coin::getSideUp() const {
    return sideUp;
}