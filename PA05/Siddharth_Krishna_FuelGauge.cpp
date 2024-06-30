#include "Siddharth_Krishna_FuelGauge.h"

// Comment 5: This constructor is responsible for initializing the fuel to 0
FuelGauge::FuelGauge() : fuel(0) {}

// Comment 6: This is responsible for returning the current fuel level
int FuelGauge::getFuel() const {
    return fuel;
}

// Comment 7: This is needed so that it can increment the fuel by 1 gallon up to the maximum capacity available
void FuelGauge::incrementFuel() {
    if (fuel < maxFuel) {
        fuel++;
    }
}

// Comment 8: This is for decrementing the fuel by 1 gallon not below 0
void FuelGauge::decrementFuel() {
    if (fuel > 0) {
        fuel--;
    }
}