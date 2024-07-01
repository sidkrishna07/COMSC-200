// Comment 6: This header file is responsible for defining the DeckOfCards class that manages a deck of playing cards which includes shuffling and dealing.
#ifndef SIDDHARTH_KRISHNA_DECKOFCARDS_H
#define SIDDHARTH_KRISHNA_DECKOFCARDS_H

#include <vector>
#include "Siddharth_Krishna_Card.h"

class DeckOfCards {
public:
    DeckOfCards();
    void shuffle();
    Card dealCard();
    bool moreCards() const;

private:
    std::vector<Card> deck;
    int currentCard;
};

#endif