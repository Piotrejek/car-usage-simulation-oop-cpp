#include<iostream>
#include<limits>
#include "Car.h"

using namespace std;

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