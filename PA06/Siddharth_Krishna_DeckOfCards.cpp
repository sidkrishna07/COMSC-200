#include <algorithm>
#include <random>
#include <ctime>
#include "Siddharth_Krishna_DeckOfCards.h"

// Comment 7: This is a constructor that initializes the deck with 52 cards which iterates through suits and faces.
DeckOfCards::DeckOfCards() : currentCard(0) {
    for (int suit = 0; suit < 4; ++suit) {
        for (int face = 0; face < 13; ++face) {
            deck.emplace_back(face, suit);
        }
    }
}

// Comment 8: This is responsible for shuffling through the deck using a random number generator along with the current time.
void DeckOfCards::shuffle() {
    std::shuffle(deck.begin(), deck.end(), std::default_random_engine(static_cast<unsigned int>(std::time(nullptr))));
    currentCard = 0;
}

// Comment 9: This is supposed to deal the next card from the deck which is responsible for incrementing the current card index.
Card DeckOfCards::dealCard() {
    if (moreCards()) {
        return deck[currentCard++];
    }
    return Card(-1, -1); 
}

// Comment 10: This checks if there are more cards left to deal in the deck.
bool DeckOfCards::moreCards() const {
    return currentCard < deck.size();
}