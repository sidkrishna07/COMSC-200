#include "Siddharth_Krishna_Card.h"

// Comment 2: This initializes the static array holding the names of the card faces.
const std::string Card::faces[13] = {
    "Ace", "Deuce", "Three", "Four", "Five", "Six",
    "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"
};

// Comment 3: This initializes the static array that is holding the names of the card suits.
const std::string Card::suits[4] = {
    "Hearts", "Diamonds", "Clubs", "Spades"
};

// Comment 4: This constructor initializes a card with a given face and suit.
Card::Card(int face, int suit) : face(face), suit(suit) {}

// Comment 5: This is a method that is responsible for returning a string representation of the card as it is combining the face and suit.
std::string Card::toString() const {
    return faces[face] + " of " + suits[suit];
}