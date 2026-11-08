#include<iostream>
#include<sstream>
#include<iomanip>
#include<limits>

using namespace std;

class Car {
private:
    double fuelLevel = 50;
    int maxFuel = 90;
    double fuelUsage = 8;
    double mileage = 0;
    double engineCondition = 100;
    int maxEngineCondition = 100;
    double engineWear = 1;

    string formatNumber(double number) {
        stringstream stream;
        stream << fixed << setprecision(2) << number;
        return stream.str();
    }
    
public:
    string drive(double kilometers) {
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

    string refuel(double liters) {
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

    string fixEngine() {
        string message;
        
        if (engineCondition == maxEngineCondition) {
            message = "Your engine is brand new and doesn't need to be repaired";
        } else {
            engineCondition = maxEngineCondition;
            message = "Your engine have been fixed to 100%";
        }

        return message;
    }

    double getMileage() { return mileage; }
    double getFuelLevel() { return fuelLevel; }
    double getEngineCondition() { return engineCondition; }
    int getMaxFuelLevel() { return maxFuel; }
};

double getValidDouble(string promptMessage) {
    double number;

    while (!(cin >> number)) {
        cout << endl;
        cout << "Invalid input. Try again..." << endl;
        cout << promptMessage;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return number;
}

int getValidInt(string promptMessage) {
    int number;

    while (!(cin >> number)) {
        cout << endl;
        cout << "Invalid input. Try again..." << endl;
        cout << promptMessage;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    return number;
}

int main(int argc, char const *argv[])
{
    Car opel;

    cout << "Car Simulation" << endl;

    while (true) {
        cout << "1. Show stats" << endl;
        cout << "2. Drive" << endl;
        cout << "3. Refuel" << endl;
        cout << "4. Fix the engine" << endl;
        cout << "5. Exit" << endl << endl;

        string promptMessage = "Enter a number: ";
        cout << promptMessage;
        int choice = getValidInt(promptMessage);

        switch (choice) {
            case 1: {
                double mileage = opel.getMileage();            
                double fuelLevel = opel.getFuelLevel();
                double engineCondition = opel.getEngineCondition();
                int maxFuel = opel.getMaxFuelLevel();

                cout << endl << "Car mileage: " << mileage << "km" << endl;
                cout << "Fuel level: " << fuelLevel << "l" << " / " << maxFuel << "l" << endl;
                cout << "Engine condition: " << engineCondition << "%" << endl << endl;

                break;
            }

            case 2: {
                cout << endl;
                string promptMessage = "How many kilometers to go?: ";
                cout << promptMessage;

                double kilometers = getValidDouble(promptMessage);
                cout << endl;

                string message = opel.drive(kilometers);
                cout << "----------------------------------" << endl;
                cout << message << endl;
                cout << "----------------------------------" << endl << endl;

                break;
            }

            case 3: {
                cout << endl;
                string promptMessage = "How many liters to fill?: ";
                cout << promptMessage;

                double liters = getValidDouble(promptMessage);
                cout << endl;
                
                string message = opel.refuel(liters);
                cout << message << endl << endl;

                break;
            }

            case 4: {
                cout << endl;
                string message = opel.fixEngine();
                cout << message << endl << endl;
                
                break;
            }

            case 5: return 0;
            
            default:
                cout << endl;
        
                break;
        }
    }

    return 0;
}