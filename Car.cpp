#include "Car.h"
#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

string Car::formatNumber(double number) {
    stringstream stream;
    stream << fixed << setprecision(2) << number;
    return stream.str();
}

string Car::drive(double kilometers) {
    double maxKmFuel = (fuelLevel * 100) / fuelUsage;
    double maxKmEnginge = (engineCondition * 100) / engineWear;
    
    double actualKm = kilometers;

    if (maxKmFuel < actualKm) {
        actualKm = maxKmFuel;
    }
    if (maxKmEnginge < actualKm) {
        actualKm = maxKmEnginge;
    }

    mileage += actualKm;
    fuelLevel -= (actualKm * fuelUsage) / 100;
    engineCondition -= (actualKm * engineWear) / 100;

    string message;

    if (actualKm < kilometers) {
        if (actualKm == maxKmFuel && actualKm == maxKmEnginge) {
            message = "Your vechicle ran out of fuel and has broken engine after: " + formatNumber(actualKm) + "km";
        } else if (actualKm == maxKmFuel) {
            message = "You ran out of fuel after: " + formatNumber(actualKm) + "km";
        } else if (actualKm == maxKmEnginge) {
            message = "Your engine has broken down after: " + formatNumber(actualKm) + "km";
        }
    } else {
        message = "You have arrived your destination";
    }

    return message;
}

string Car::refuel(double liters) {
    string message;

    if (liters <= 0) {
        message = "You can't drink fuel";
    } else if (liters + fuelLevel >= maxFuel) {
        fuelLevel = maxFuel;
        message = "You've exceeded maximum amount of fuel - set to " + to_string(maxFuel) + "l";
    } else {
        fuelLevel += liters;
        message = "You've filled up the tank with " + formatNumber(liters) + "l";
    }

    return message;
}

string Car::fixEngine() {
    string message;
    
    if (engineCondition == maxEngineCondition) {
        message = "Your engine is brand new and doesn't need to be repaired";
    } else {
        engineCondition = maxEngineCondition;
        message = "Your engine have been fixed to 100%";
    }

    return message;
}

int Car::getId() { return id; }
string Car::getCarName() { return carName; }
double Car::getMileage() { return mileage; }
double Car::getFuelLevel() { return fuelLevel; }
double Car::getEngineCondition() { return engineCondition; }
int Car::getMaxFuelLevel() { return maxFuel; }