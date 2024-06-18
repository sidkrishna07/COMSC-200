#include <iostream>
using namespace std;

const int COLS = 5;

// Comment 1: The purpose of this is to declare the function prototypes for the operations needed to be done on a 2D array
int getTotal(int [][COLS], int);
double getAverage(int [][COLS], int);
int getRowTotal(int [][COLS], int);
int getColumnTotal(int [][COLS], int, int);
int getHighestInRow(int [][COLS], int);
int getLowestInRow(int [][COLS], int);

int main() {
    // Comment 2: This value would be the constant for the number of rows in the 2D array
    const int ROWS = 4;
    
    // Comment 3: It is used for actually initializing the 2D array with test data
    int testArray[4][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };

    // Comment 4: It is helpful for displaying the total of all values in the array
    cout << "The total of the array elements is " << getTotal(testArray, ROWS) << endl;

    // Comment 5: It shows the average of all values in the array
    cout << "The average value of an element is " << getAverage(testArray, ROWS) << endl;

    // Comment 6: This displays the total of the values which are present in row 0
    cout << "The total of row 0 is " << getRowTotal(testArray, 0) << endl;

    // Comment 7: This displays the total of the values in column 2
    cout << "The total of col 2 is " << getColumnTotal(testArray, 2, ROWS) << endl;

    // Comment 8: This displays the highest value which is present in row 2
    cout << "The highest value in row 2 is " << getHighestInRow(testArray, 2) << endl;

    // Comment 9: This displays the lowest value in row 2
    cout << "The lowest value in row 2 is " << getLowestInRow(testArray, 2) << endl;


    return 0;
}


// Comment 10: This function is used for calculating and returning the total of all values in the 2D array
int getTotal(int array[][COLS], int rows) {
    int total = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < COLS; j++) {
            total += array[i][j];
        }
    }
    return total;
}

// Comment 11: This function is used for calculating and returning the average of all values which are in the 2D array
double getAverage(int array[][COLS], int rows) {
    int total = getTotal(array, rows);
    return static_cast<double>(total) / (rows * COLS);
}

// Comment 12: This function helps with calculating and returning the total of values which are in a specified row
int getRowTotal(int array[][COLS], int rowToTotal) {
    int total = 0;
    for (int j = 0; j < COLS; j++) {
        total += array[rowToTotal][j];
    }
    return total;
}

// Comment 13: This function is responsible for calculating and returning the total of values in a specified column
int getColumnTotal(int array[][COLS], int colToTotal, int rows) {
    int total = 0;
    for (int i = 0; i < rows; i++) {
        total += array[i][colToTotal];
    }
    return total;
}

// Comment 14: This function helps with finding and returning the highest value in a specified row
int getHighestInRow(int array[][COLS], int rowToSearch) {
    int highest = array[rowToSearch][0];
    for (int j = 1; j < COLS; j++) {
        if (array[rowToSearch][j] > highest) {
            highest = array[rowToSearch][j];
        }
    }
    return highest;
}

// Comment 15: This function is supposed to find and return the lowest value in a specified row
int getLowestInRow(int array[][COLS], int rowToSearch) {
    int lowest = array[rowToSearch][0];
    for (int j = 1; j < COLS; j++) {
        if (array[rowToSearch][j] < lowest) {
            lowest = array[rowToSearch][j];
        }
    }
    return lowest;
}