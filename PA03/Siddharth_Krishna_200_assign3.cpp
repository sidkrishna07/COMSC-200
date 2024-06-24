#include <iostream>
#include <iomanip>
#include "Siddharth_Krishna_Coin.h"

using namespace std;

void playRound(Coin &quarter, Coin &dime, Coin &nickel, double &playerBalance, double &computerBalance, int round);
void displayResults(double playerBalance, double computerBalance, int round);

int main() {
    // Comment 1: Responsible for creating the coin objects for the uarter, dime, and nickel
    Coin quarter, dime, nickel;
    
    // Comment 2: This shows the initial balances
    double playerBalance = 0.0;
    double computerBalance = 0.0;

    // Comment 3: It is the set precision for all floating point output
    cout << fixed << setprecision(2);

    // Comment 4: This shows initial balances with a newline for separation
    cout << "Your starting balance: $" << playerBalance << endl;
    cout << "The computer's starting balance: $" << computerBalance << endl; // Removed extra newline

    int round = 1;
    // Comment 5: Response for playing rounds until one or both players reach a balance of $1.00 or more
    while (playerBalance < 1.00 && computerBalance < 1.00) {
        playRound(quarter, dime, nickel, playerBalance, computerBalance, round);
        displayResults(playerBalance, computerBalance, round);
        round++;
    }

    // Comment 6: Used for determining and displaying what the outcome of the game is
    cout << "\nYour ending balance: $" << playerBalance << endl;
    cout << "The computer's ending balance: $" << computerBalance << "\n\n"; 

    // Comment 7: This is the game logic based on provided rules
    if (playerBalance >= 1.00 && computerBalance >= 1.00) {
        if (playerBalance == computerBalance) {
            cout << "Tie! Nobody wins." << endl;
        } else if (playerBalance < computerBalance) {
            cout << "Congratulations! You won." << endl;
        } else {
            cout << "Sorry! The computer won." << endl;
        }
    } else if (playerBalance >= 1.00) {
        cout << "Congratulations! You won." << endl;
    } else {
        cout << "Sorry! The computer won." << endl;
    }

    // Comment 8: Prompt to continue text when running program
    cout << "\nPress any key to continue . . ." << endl;

    return 0;
}

// Comment 9: This function is used to play a round and update balances
void playRound(Coin &quarter, Coin &dime, Coin &nickel, double &playerBalance, double &computerBalance, int round) {
    // Comment 10: Toss coins for player
    quarter.toss();
    dime.toss();
    nickel.toss();

    if (quarter.getSideUp() == "heads") playerBalance += 0.25;
    if (dime.getSideUp() == "heads") playerBalance += 0.10;
    if (nickel.getSideUp() == "heads") playerBalance += 0.05;

    // Comment 11: Toss coins for computer
    quarter.toss();
    dime.toss();
    nickel.toss();

    if (quarter.getSideUp() == "heads") computerBalance += 0.25;
    if (dime.getSideUp() == "heads") computerBalance += 0.10;
    if (nickel.getSideUp() == "heads") computerBalance += 0.05;
}

// Comment 12: Function is for displaying the current results after each round
void displayResults(double playerBalance, double computerBalance, int round) {
    cout << "\nYour balance after round " << round << ": $" << playerBalance << endl;
    cout << "The computer's balance after round " << round << ": $" << computerBalance << endl;
}