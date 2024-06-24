// Comment 13: This program is doing a simulation of a coin toss where a player and a computer toss coins to reach a balance of $1.00 or more.

#ifndef SIDDHARTH_KRISHNA_COIN_H
#define SIDDHARTH_KRISHNA_COIN_H

#include <string>
using namespace std;

class Coin {
private:
    string sideUp;

public:
    Coin();
    void toss();
    string getSideUp() const;
};

#endif 