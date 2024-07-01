// Comment 1: This file defines the card class and it also represents the playing card with its value and suit and how it can turn it into a string.
#ifndef SIDDHARTH_KRISHNA_CARD_H
#define SIDDHARTH_KRISHNA_CARD_H

#include <string>

class Card {
public:
    Card(int face, int suit);
    std::string toString() const;

private:
    int face;
    int suit;
    static const std::string faces[13];
    static const std::string suits[4];
};

#endif 