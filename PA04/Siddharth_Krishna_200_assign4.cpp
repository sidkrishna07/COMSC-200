#include "Siddharth_Krishna_HeartRates.h"
#include <iostream>
#include <string>
#include <utility>

void getInput(std::string& firstName, std::string& lastName, int& birthMonth, int& birthDay, int& birthYear) {
    std::cout << "Please enter first and last name (separated by spaces): " << std::endl;
    std::cin >> firstName >> lastName;
    std::cout << "Please enter month, day, and year of birth (separated by spaces): " << std::endl;
    std::cin >> birthMonth >> birthDay >> birthYear;
}

void getCurrentDate(int& currentMonth, int& currentDay, int& currentYear) {
    std::cout << "Please enter today's month, day, and year: " << std::endl;
    std::cin >> currentMonth >> currentDay >> currentYear;
}

void printPersonalInfo(const HeartRates& heartRates) {
    std::cout << "First Name: " << heartRates.getFirstName() << std::endl;
    std::cout << "Last Name: " << heartRates.getLastName() << std::endl;
    std::cout << "Date of Birth: " << heartRates.getBirthMonth() << "/"
              << heartRates.getBirthDay() << "/" << heartRates.getBirthYear() << std::endl;
}

void printHeartRateInfo(const HeartRates& heartRates, int age) {
    std::cout << "Age: " << age << std::endl;
    std::cout << "Maximum Heart Rate: " << heartRates.getMaximumHeartRate(age) << std::endl;
    std::pair<int, int> targetHeartRate = heartRates.getTargetHeartRate(age);
    std::cout << "Target Heart Rate: " << targetHeartRate.first << "-" << targetHeartRate.second << std::endl;
}

int main() {
    std::string firstName, lastName;
    int birthMonth, birthDay, birthYear;
    int currentMonth, currentDay, currentYear;

    getInput(firstName, lastName, birthMonth, birthDay, birthYear);

    HeartRates heartRates(firstName, lastName, birthMonth, birthDay, birthYear);

    printPersonalInfo(heartRates);

    getCurrentDate(currentMonth, currentDay, currentYear);

    int age = heartRates.getAge(currentMonth, currentDay, currentYear);

    printHeartRateInfo(heartRates, age);

    return 0;
}