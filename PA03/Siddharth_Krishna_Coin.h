#ifndef SIDDHARTH_KRISHNA_COIN_H
#define SIDDHARTH_KRISHNA_COIN_H

#include <string>
using namespace std;

class Coin {
private:
    string sideUp; // Stores either "heads" or "tails"

public:
    // Default constructor
    Coin();

    // Member function to simulate the tossing of the coin
    void toss();

    // Member function to get the current side facing up
    string getSideUp() const;
};

#endif // SIDDHARTH_KRISHNA_COIN_H