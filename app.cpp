#include<iostream>
#include<limits>
#include "Car.h"
#include "Cars.h"

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

void changeCar(Car*& selectedCar) {
    cout << "0. Passat" << endl;
    cout << "1. Opel" << endl;
    cout << "2. Golf" << endl;
    string promptMessage = "Choose a car: ";
    cout << promptMessage;
    int carChoice = getValidInt(promptMessage);
    cout << endl;

    switch (carChoice) {
        case 0:
            selectedCar = &passat;
            break;
        
        case 1:
            selectedCar = &opel;
            break;

        case 2:
            selectedCar = &golf;
            break;

        default:
            cout << "Invalid car choice!" << endl << endl;
            return;
    }
}

int main(int argc, char const *argv[])
{
    cout << "Car Simulation" << endl;

    Car* selectedCar = &passat;

    while (true) {
        cout << "Car selected right now: " << selectedCar->getCarName() << endl << endl;

        cout << "0. Change car" << endl;
        cout << "1. Show stats" << endl;
        cout << "2. Drive" << endl;
        cout << "3. Refuel" << endl;
        cout << "4. Fix the engine" << endl;
        cout << "5. Exit" << endl << endl;

        string promptMessage = "Enter a number: ";
        cout << promptMessage;
        int choice = getValidInt(promptMessage);
        cout << endl;

        switch (choice) {
            case 0: {
                changeCar(selectedCar);
                break;
            }

            case 1: {
                string carName = selectedCar->getCarName();
                double mileage = selectedCar->getMileage();            
                double fuelLevel = selectedCar->getFuelLevel();
                double engineCondition = selectedCar->getEngineCondition();
                int maxFuel = selectedCar->getMaxFuelLevel();

                cout << "Car name: " << carName << endl;
                cout << "Car mileage: " << mileage << "km" << endl;
                cout << "Fuel level: " << fuelLevel << "l" << " / " << maxFuel << "l" << endl;
                cout << "Engine condition: " << engineCondition << "%" << endl << endl;
                break;
            }

            case 2: {
                string promptMessage = "How many kilometers to go?: ";
                cout << promptMessage;

                double kilometers = getValidDouble(promptMessage);
                cout << endl;

                string message = selectedCar->drive(kilometers);
                cout << "----------------------------------" << endl;
                cout << message << endl;
                cout << "----------------------------------" << endl << endl;
                break;
            }

            case 3: {
                string promptMessage = "How many liters to fill?: ";
                cout << promptMessage;

                double liters = getValidDouble(promptMessage);
                cout << endl;
                
                string message = selectedCar->refuel(liters);
                cout << message << endl << endl;
                break;
            }

            case 4: {
                string message = selectedCar->fixEngine();
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