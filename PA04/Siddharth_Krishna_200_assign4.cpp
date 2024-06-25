// Siddharth_Krishna_200_assign4.cpp

#include "Siddharth_Krishna_HeartRates.h"
#include <iostream>
#include <string>

void getInput(std::string& firstName, std::string& lastName, int& birthMonth, int& birthDay, int& birthYear) {
    std::cout << "Enter first name: ";
    std::cin >> firstName;
    std::cout << "Enter last name: ";
    std::cin >> lastName;
    std::cout << "Enter birth month (1-12): ";
    std::cin >> birthMonth;
    std::cout << "Enter birth day (1-31): ";
    std::cin >> birthDay;
    std::cout << "Enter birth year: ";
    std::cin >> birthYear;
}

void getCurrentDate(int& currentMonth, int& currentDay, int& currentYear) {
    std::cout << "Enter current month (1-12): ";
    std::cin >> currentMonth;
    std::cout << "Enter current day (1-31): ";
    std::cin >> currentDay;
    std::cout << "Enter current year: ";
    std::cin >> currentYear;
}

void printHeartRateInfo(const HeartRates& heartRates, int age) {
    std::cout << "First Name: " << heartRates.getFirstName() << std::endl;
    std::cout << "Last Name: " << heartRates.getLastName() << std::endl;
    std::cout << "Date of Birth: " << heartRates.getBirthMonth() << "/"
              << heartRates.getBirthDay() << "/" << heartRates.getBirthYear() << std::endl;
    std::cout << "Age: " << age << " years" << std::endl;
    std::cout << "Maximum Heart Rate: " << heartRates.getMaximumHeartRate(age) << " beats per minute" << std::endl;
    auto targetHeartRate = heartRates.getTargetHeartRate(age);
    std::cout << "Target Heart Rate Range: " << targetHeartRate.first << " - " << targetHeartRate.second << " beats per minute" << std::endl;
}

int main() {
    std::string firstName, lastName;
    int birthMonth, birthDay, birthYear;
    int currentMonth, currentDay, currentYear;

    // Get user input for personal information
    getInput(firstName, lastName, birthMonth, birthDay, birthYear);

    // Create HeartRates object
    HeartRates heartRates(firstName, lastName, birthMonth, birthDay, birthYear);

    // Get current date from user
    getCurrentDate(currentMonth, currentDay, currentYear);

    // Calculate age
    int age = heartRates.getAge(currentMonth, currentDay, currentYear);

    // Print heart rate information
    printHeartRateInfo(heartRates, age);

    return 0;
}