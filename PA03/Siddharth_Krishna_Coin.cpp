// Comment 14: This program is simulating a coin toss game where a player and a computer toss coins to reach a balance of $1.00 or more

#include "Siddharth_Krishna_Coin.h"
#include <cstdlib>
#include <ctime>

Coin::Coin() {
    srand(static_cast<unsigned int>(time(0)));
    toss();
}

void Coin::toss() {
    int randomValue = rand() % 2;
    if (randomValue == 0) {
        sideUp = "heads";
    } else {
        sideUp = "tails";
    }
}

string Coin::getSideUp() const {
    return sideUp;
}