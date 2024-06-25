// Siddharth_Krishna_HeartRates.h

#ifndef SIDHARTH_KRISHNA_HEARTRATES_H
#define SIDHARTH_KRISHNA_HEARTRATES_H

#include <string>

class HeartRates {
private:
    std::string firstName;
    std::string lastName;
    int birthMonth;
    int birthDay;
    int birthYear;

public:
    // Constructor
    HeartRates(const std::string& firstName, const std::string& lastName, int birthMonth, int birthDay, int birthYear);

    // Setter and Getter for first name
    void setFirstName(const std::string& firstName);
    std::string getFirstName() const;

    // Setter and Getter for last name
    void setLastName(const std::string& lastName);
    std::string getLastName() const;

    // Setter and Getter for birth month
    void setBirthMonth(int birthMonth);
    int getBirthMonth() const;

    // Setter and Getter for birth day
    void setBirthDay(int birthDay);
    int getBirthDay() const;

    // Setter and Getter for birth year
    void setBirthYear(int birthYear);
    int getBirthYear() const;

    // Function to calculate and return age
    int getAge(int currentMonth, int currentDay, int currentYear) const;

    // Function to calculate and return maximum heart rate
    int getMaximumHeartRate(int age) const;

    // Function to calculate and return target heart rate range
    std::pair<int, int> getTargetHeartRate(int age) const;
};

#endif // SIDHARTH_KRISHNA_HEARTRATES_H