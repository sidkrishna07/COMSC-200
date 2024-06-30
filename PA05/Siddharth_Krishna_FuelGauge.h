#ifndef SIDDHARTH_KRISHNA_FUELGAUGE_H
#define SIDDHARTH_KRISHNA_FUELGAUGE_H

class FuelGauge {
private:
    int fuel;
    static const int maxFuel = 15;

public:
    FuelGauge();  // Comment 1: This is responsible for initializing the fuel gauge with default fuel level.

    int getFuel() const;  // Comment 2: It is used for returning the current fuel level.

    void incrementFuel(); // Comment 3: This increases the fuel level by one unit which does not exceed the maxFuel.

    void decrementFuel(); // Comment 4: This is for decreasing the fuel level by one unit and making sure it is not falling below zero.
};

#endif 