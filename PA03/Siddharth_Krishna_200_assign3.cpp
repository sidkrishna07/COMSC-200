#include <iostream>
#include "Siddharth_Krishna_Coin.h"

using namespace std;

// Function prototypes
void playRound(Coin &quarter, Coin &dime, Coin &nickel, double &playerBalance, double &computerBalance);
void displayResults(double playerBalance, double computerBalance);

int main() {
    // Create Coin objects for quarter, dime, and nickel
    Coin quarter, dime, nickel;
    
    // Initial balances
    double playerBalance = 0.0;
    double computerBalance = 0.0;

    // Display initial balances
    cout << "Starting balance - Player: $" << playerBalance << " Computer: $" << computerBalance << endl;

    // Play rounds until one or both players reach a balance of $1.00 or more
    while (playerBalance < 1.00 && computerBalance < 1.00) {
        playRound(quarter, dime, nickel, playerBalance, computerBalance);
        displayResults(playerBalance, computerBalance);
    }

    // Determine and display the outcome of the game
    if (playerBalance >= 1.00 && computerBalance >= 1.00) {
        if (playerBalance < computerBalance) {
            cout << "Player wins with a lower balance of $" << playerBalance << " compared to Computer's $" << computerBalance << "!" << endl;
        } else if (computerBalance < playerBalance) {
            cout << "Computer wins with a lower balance of $" << computerBalance << " compared to Player's $" << playerBalance << "!" << endl;
        } else {
            cout << "It's a tie with both Player and Computer having $" << playerBalance << "!" << endl;
        }
    } else if (playerBalance >= 1.00) {
        cout << "Player wins with a balance of $" << playerBalance << "!" << endl;
    } else {
        cout << "Computer wins with a balance of $" << computerBalance << "!" << endl;
    }

    return 0;
}

// Function to play a round and update balances
void playRound(Coin &quarter, Coin &dime, Coin &nickel, double &playerBalance, double &computerBalance) {
    // Toss coins for player
    quarter.toss();
    dime.toss();
    nickel.toss();

    if (quarter.getSideUp() == "heads") playerBalance += 0.25;
    if (dime.getSideUp() == "heads") playerBalance += 0.10;
    if (nickel.getSideUp() == "heads") playerBalance += 0.05;

    // Toss coins for computer
    quarter.toss();
    dime.toss();
    nickel.toss();

    if (quarter.getSideUp() == "heads") computerBalance += 0.25;
    if (dime.getSideUp() == "heads") computerBalance += 0.10;
    if (nickel.getSideUp() == "heads") computerBalance += 0.05;
}

// Function to display the current results after each round
void displayResults(double playerBalance, double computerBalance) {
    cout << "Current balance - Player: $" << playerBalance << " Computer: $" << computerBalance << endl;
}