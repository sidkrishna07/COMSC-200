#include "Siddharth_Krishna_Die.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function prototypes
void playGame();
bool userWantsToContinue();

int main() {
    srand(static_cast<unsigned int>(time(0))); // Seed the random number generator

    playGame();

    return 0;
}

// Main function to play the game
void playGame() {
    Die die1(6); // Create the first die with 6 sides
    Die die2(6); // Create the second die with 6 sides

    int userTotal = 0;
    int computerTotal = 0;

    // Computer's initial roll (hidden)
    die1.roll();
    die2.roll();
    computerTotal = die1.getValue() + die2.getValue();

    cout << "Welcome to the Dice Blackjack Game!" << endl;

    // User's turn
    while (userWantsToContinue() && userTotal <= 21) {
        die1.roll();
        die2.roll();
        int rollTotal = die1.getValue() + die2.getValue();
        userTotal += rollTotal;
        cout << "You rolled: " << die1.getValue() << " and " << die2.getValue() << " (Total: " << rollTotal << ")" << endl;
        cout << "Your total points: " << userTotal << endl;
        cout << endl;

        if (userTotal > 21) {
            cout << "You exceeded 21. You lose!" << endl;
            cout << "--------------------------------" << endl;
            cout << "Game Over" << endl;
            cout << "Press any key to continue . . ." << endl;
            return;
        }
    }

    // Reveal computer's total
    cout << "--------------------------------" << endl;
    cout << "The computer had " << computerTotal << " points." << endl;
    cout << "You had " << userTotal << " points." << endl;
    cout << endl;

    // Determine the winner
    if (computerTotal > 21) {
        cout << "The computer exceeded 21." << endl;
        cout << "Congratulations! You won!" << endl;
    } else if (userTotal > computerTotal) {
        cout << "Congratulations! You won!" << endl;
    } else if (userTotal < computerTotal) {
        cout << "Better luck next time." << endl;
    } else {
        cout << "It's a tie!" << endl;
    }

    cout << "--------------------------------" << endl;
    cout << endl;
    cout << "Game Over" << endl;
}

// Function to ask the user if they want to continue playing
bool userWantsToContinue() {
    char choice;
    cout << "Would you like to roll the dice?" << endl;
    cout << "Enter Y for yes or N for no: ";
    cin >> choice;
    cout << endl;

    return (choice == 'Y' || choice == 'y');
}

//DONE

