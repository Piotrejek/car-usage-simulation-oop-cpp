#ifndef CAR_H
#define CAR_H

#include <string>

using namespace std;

class Car {
private:
    int id;
    string carName;
    double fuelLevel;
    int maxFuel;
    double fuelUsage;
    double mileage = 0;
    double engineCondition;
    int maxEngineCondition = 100;
    double engineWear;
    
    string formatNumber(double number);
    
public:
    Car(int id, string carName, double fuelLevel, int maxFuel, double fuelUsage, double engineCondition, double engineWear) {
        this->id = id;
        this->carName = carName;
        this->fuelLevel = fuelLevel;
        this->maxFuel = maxFuel;
        this->fuelUsage = fuelUsage;
        this->engineCondition = engineCondition;
        this->engineWear = engineWear;
    }
        
    string drive(double kilometers);
    string refuel(double liters);
    string fixEngine();
    
    int getId();
    string getCarName();
    double getMileage();
    double getFuelLevel();
    double getEngineCondition();
    int getMaxFuelLevel();
};

#endif