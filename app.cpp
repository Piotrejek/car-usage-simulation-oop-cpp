#include<iostream>

using namespace std;

class Car {
private:
    double fuelLevel = 90;
    double mileage = 0;
    double engineCondition = 100;
    int fuelUsage = 8;
    int engineWear = 1;
    
public:
    string drive(int kilometers) {
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
                message = "Your vechicle ran out of fuel and has broken engine after: " + to_string(actualKm) + "km";
            } else if (actualKm == maxKmFuel) {
                message = "You ran out of fuel after: " + to_string(actualKm) + "km";
            } else if (actualKm == maxKmEnginge) {
                message = "Your engine has broken down after: " + to_string(actualKm) + "km";
            }
        } else {
            message = "You have arrived your destination";
        }

        return message;
    }

    double getMileage() { return mileage; }
    double getFuelLevel() { return fuelLevel; }
    double getEngineCondition() { return engineCondition; }
};


int main(int argc, char const *argv[])
{
    Car opel;

    cout << "Car Simulation" << endl;

    while (true) {
        cout << "1. Show stats" << endl;
        cout << "2. Drive" << endl;
        cout << "3. Fueling" << endl;
        cout << "4. Fix the engine" << endl << endl;
        cout << "Enter a number: ";

        int choice;
        cin >> choice;
        switch (choice) {
            case 1: {
                double mileage = opel.getMileage();            
                double fuelLevel = opel.getFuelLevel();
                double engineCondition = opel.getEngineCondition();

                cout << endl << "Car mileage: " << mileage << "km" << endl;
                cout << "Fuel level: " << fuelLevel << "l" << endl;
                cout << "Engine condition: " << engineCondition << "%" << endl << endl;
                break;
            }

            case 2: {
                cout << endl;
                cout << "How many kilometers to go?: ";
                int kilometers;
                cin >> kilometers;
                cout << endl;
                string message = opel.drive(kilometers);
                cout << "----------------------------------" << endl;
                cout << message << endl;
                cout << "----------------------------------" << endl << endl;
                break;
            }

            default:
                break;
        }
    }

    return 0;
}
