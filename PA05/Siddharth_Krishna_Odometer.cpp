// Comment 15: This file is responmsible for implementing the Odometer class, initializing the mileage, returning the current mileage, and incrementing mileage while managing the fuel consumption
#include "Siddharth_Krishna_Odometer.h"

Odometer::Odometer(FuelGauge* fg) : mileage(0), fuelGauge(fg) {}


int Odometer::getMileage() const {
    return mileage;
}

void Odometer::incrementMileage() {
    if (mileage < maxMileage) {
        mileage++;
    } else {
        mileage = 0;
    }
    
    if (mileage % 24 == 0) {
        fuelGauge->decrementFuel();
    }
}