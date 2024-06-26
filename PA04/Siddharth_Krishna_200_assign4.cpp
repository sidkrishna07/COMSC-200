#include "Siddharth_Krishna_HeartRates.h"
#include <iostream>
#include <string>
#include <utility>

// Comment 1: This function asks the user to enter their first name, last name, and date of birth.
void getInput(std::string& firstName, std::string& lastName, int& birthMonth, int& birthDay, int& birthYear) {
    // Comment 2: It displays a message asking the user to enter their first and last name separated by spaces.
    std::cout << "Please enter first and last name (separated by spaces): " << std::endl;
    std::cin >> firstName >> lastName;
    // Comment 3: It displays a message asking the user to enter their birth month, day, and year separated by spaces.
    std::cout << "Please enter month, day, and year of birth (separated by spaces): " << std::endl;
    std::cin >> birthMonth >> birthDay >> birthYear;
}

// Comment 4: This function asks the user to enter the current date, including the current month, day, and year.
void getCurrentDate(int& currentMonth, int& currentDay, int& currentYear) {
    // Comment 5: It displays a message asking the user to enter today's month, day, and year.
    std::cout << "Please enter today's month, day, and year: " << std::endl;
    std::cin >> currentMonth >> currentDay >> currentYear;
}

// Comment 6: This function prints the personal information stored in the HeartRates object.
void printPersonalInfo(const HeartRates& heartRates) {
    // Comment 7: It outputs the first name of the person stored in the HeartRates object.
    std::cout << "First Name: " << heartRates.getFirstName() << std::endl;
    // Comment 8: It outputs the last name of the person stored in the HeartRates object.
    std::cout << "Last Name: " << heartRates.getLastName() << std::endl;
    // Comment 9: It outputs the date of birth of the person stored in the HeartRates object in month/day/year.
    std::cout << "Date of Birth: " << heartRates.getBirthMonth() << "/"
              << heartRates.getBirthDay() << "/" << heartRates.getBirthYear() << std::endl;
}

// Comment 10: This function prints the heart rate information, along with the age, maximum heart rate, and target heart rate range.
void printHeartRateInfo(const HeartRates& heartRates, int age) {
    // Comment 11: Outputs the age of the person calculated using the getAge function.
    std::cout << "Age: " << age << std::endl;
    // Comment 12: It Outputs the maximum heart rate of the person calculated using the getMaximumHeartRate function.
    std::cout << "Maximum Heart Rate: " << heartRates.getMaximumHeartRate(age) << std::endl;
    // Comment 13: It calculates and output the target heart rate range of the person using the getTargetHeartRate function.
    std::pair<int, int> targetHeartRate = heartRates.getTargetHeartRate(age);
    std::cout << "Target Heart Rate: " << targetHeartRate.first << "-" << targetHeartRate.second << std::endl;
}

int main() {
    std::string firstName, lastName;
    int birthMonth, birthDay, birthYear;
    int currentMonth, currentDay, currentYear;

    // Comment 14: Responsible for calling the getInput function to get the personal information from the user.
    getInput(firstName, lastName, birthMonth, birthDay, birthYear);

    // Comment 15: It creates a HeartRates object using the input provided by the user.
    HeartRates heartRates(firstName, lastName, birthMonth, birthDay, birthYear);

    // Comment 16: It calls the printPersonalInfo function to print the user's personal information.
    printPersonalInfo(heartRates);

    // Comment 17: It Calls the getCurrentDate function to get the current date from the user.
    getCurrentDate(currentMonth, currentDay, currentYear);

    // Comment 18: This calculates the user's age by calling the getAge function with the current date.
    int age = heartRates.getAge(currentMonth, currentDay, currentYear);

    // Comment 19: It call the printHeartRateInfo function to print the heart rate information which also includes the person's age, maximum heart rate, and target heart rate range.
    printHeartRateInfo(heartRates, age);

    // Comment 20: It returns 0 to indicate that the program executed successfully.
    return 0;
}