#ifndef CAR_H
#define CAR_H

#include <string>

class Car {
private:
    double fuelLevel = 50;
    int maxFuel = 90;
    double fuelUsage = 8;
    double mileage = 0;
    double engineCondition = 100;
    int maxEngineCondition = 100;
    double engineWear = 1;

    std::string formatNumber(double number);

public:
    std::string drive(double kilometers);
    std::string refuel(double liters);
    std::string fixEngine();

    double getMileage();
    double getFuelLevel();
    double getEngineCondition();
    int getMaxFuelLevel();
};

#endif