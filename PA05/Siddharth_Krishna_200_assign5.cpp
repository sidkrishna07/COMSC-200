#include <iostream>
#include "Siddharth_Krishna_FuelGauge.h"
#include "Siddharth_Krishna_Odometer.h"

int main() {
    // Comment 9: This is used to create a FuelGauge object
    FuelGauge fuelGauge;

    // Comment 10: This is for filling the FuelGauge to maximum capacity
    for (int i = 0; i < 15; i++) {
        fuelGauge.incrementFuel();
    }

    // Comment 11: This is responsible for creating an Odometer object linked to the FuelGauge
    Odometer odometer(&fuelGauge);

    // Comment 12: This is a loop until the car runs out of fuel
    while (fuelGauge.getFuel() > 0) {
        odometer.incrementMileage();  // Comment 13: This line is responsible for inccrementing the mileage

        // Comment 13: This is where it is being printed - the current mileage and fuel level
        std::cout << "Mileage: " << odometer.getMileage() << "\n";
        std::cout << "Fuel level: " << fuelGauge.getFuel() << " gallons\n";
        std::cout << "-----------------------------\n";
    }

    
    std::cout << "Fuel ran out" << std::endl;

    return 0;
}