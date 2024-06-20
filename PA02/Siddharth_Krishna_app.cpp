#include "Siddharth_Krishna_Die.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Comment 15: The function containing the main logic that is running this game
void playGame();
bool userWantsToContinue();

int main() {
    // Comment 16: This is the random number generator and is responsible for starting the game
    srand((time(0)));

    playGame();

    return 0;
}

// Comment 17: Creates die with sides and also intializes the user total score, computer score and to also  check if dice were rolled
void playGame() {
    Die die1(6); 
    Die die2(6); 

    int userTotal = 0; 
    int computerTotal = 0; 
    bool diceRolled = false; 

    cout << "Let's play a game of 21!" << endl;
    cout << endl;
    cout << "--------------------------------" << endl;

    // Comment 18: Loop that is used to continue the game until user wants to stop or if it exceeds 21 points and rolls first and second die and updates scores and calcu
    while (userWantsToContinue() && userTotal <= 21) {
        diceRolled = true;
        die1.roll();
        die2.roll();
        computerTotal += die1.getValue() + die2.getValue();

        die1.roll();
        die2.roll();
        int rollTotal = die1.getValue() + die2.getValue();
        userTotal += rollTotal;
        cout << "You have " << userTotal << " points." << endl;
        cout << endl;

        // Comment 19: This is where the checking is happening if user has exceeded 21 points
        if (userTotal > 21) {
            cout << "--------------------------------" << endl;
            cout << "The computer had " << computerTotal << " points." << endl;
            cout << "You had " << userTotal << " points." << endl;
            cout << endl;
            cout << "Better luck next time." << endl;
            cout << endl;
            cout << "--------------------------------" << endl;
            cout << endl;
            cout << "Game Over" << endl;
            cout << endl;
            cout << "Press any key to continue . . ." << endl;
            return;
        }
    }

    // Comment 20: Displayign the final results if dice were rolled
    if (diceRolled) {
        cout << "--------------------------------" << endl;
        cout << "The computer had " << computerTotal << " points." << endl;
        cout << "You had " << userTotal << " points." << endl;
        // Comment 21: Check if  the user has lost or tied with the computer
        if (userTotal <= 21 && userTotal <= computerTotal) {
            cout << endl;
            cout << "Better luck next time." << endl;
        }
        cout << endl;
        // Comment 22: Check if the user has won against the computer
        if (userTotal > computerTotal && userTotal <= 21) {
            cout << "Congratulations! You won!" << endl;
            cout << endl;
        }
        cout << "--------------------------------" << endl;
    } else {
        cout << "--------------------------------" << endl;
        cout << endl;
    }
    cout << "Game Over" << endl;
    cout << endl;
    cout << "Press any key to continue . . ." << endl;
}

// Comment 23: This is used to check if the user wants to continue playing
bool userWantsToContinue() {
    char choice;
    cout << "Would you like to roll the dice?" << endl;
    cout << "Enter Y for yes or N for no: ";
    cin >> choice;
    cout << endl;

    return (choice == 'Y' || choice == 'y');
}