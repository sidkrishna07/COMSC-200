// Comment 11: This file uses DeckOfCards class by creating, shuffling, and also ddealing all cards in a proper formatted manner.
#include <iostream>
#include "Siddharth_Krishna_DeckOfCards.h"
#include <iomanip>

int main() {
    DeckOfCards deck;
    deck.shuffle();

    int count = 0;
    while (deck.moreCards()) {
        std::cout << std::setw(20) << std::left << deck.dealCard().toString();
        count++;
        if (count % 4 == 0) {
            std::cout << std::endl;
        }
    }

    return 0;
}