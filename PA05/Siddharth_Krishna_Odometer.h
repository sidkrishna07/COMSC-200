// Comment 14: This defines the odometer class which tracks the vehicle mileage and works with the FuelGauge class to manage fuel consumption
#ifndef SIDDHARTH_KRISHNA_ODOMETER_H
#define SIDDHARTH_KRISHNA_ODOMETER_H

#include "Siddharth_Krishna_FuelGauge.h"

class Odometer {
private:
    int mileage;  
    static const int maxMileage = 999999;  
    FuelGauge* fuelGauge;  

public:
    Odometer(FuelGauge* fg);  
    int getMileage() const;  
    void incrementMileage();  
};

#endif 