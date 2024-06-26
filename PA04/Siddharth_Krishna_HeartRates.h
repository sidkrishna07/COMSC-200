// Comment 21: This  file defines the HeartRates class which is responsible for manging personal data and calculates heart rate information.
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
    
    HeartRates(const std::string& firstName, const std::string& lastName, int birthMonth, int birthDay, int birthYear);

    
    void setFirstName(const std::string& firstName);
    std::string getFirstName() const;

    
    void setLastName(const std::string& lastName);
    std::string getLastName() const;

    
    void setBirthMonth(int birthMonth);
    int getBirthMonth() const;

    
    void setBirthDay(int birthDay);
    int getBirthDay() const;

    
    void setBirthYear(int birthYear);
    int getBirthYear() const;

    
    int getAge(int currentMonth, int currentDay, int currentYear) const;

    
    int getMaximumHeartRate(int age) const;

    
    std::pair<int, int> getTargetHeartRate(int age) const;
};

#endif 