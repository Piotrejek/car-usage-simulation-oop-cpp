# Car Simulation

A simple console application written in C++ that allows you to simulate vehicle management. You can choose from several available cars, drive them, refuel, and repair the engine. The application calculates fuel consumption and engine wear based on the distance traveled.

## Features

* **Change car:** Select one of the preset cars (Passat, Opel, Golf). Each has different parameters for fuel consumption, tank capacity, and engine wear rate.

* **Show stats:** Check the current mileage, fuel level, and engine condition of your selected vehicle.

* **Drive:** Enter a distance, and the program will calculate if you have enough fuel and if the engine can endure the trip.

* **Refuel:** Fill up your gas tank (includes overfill protection).

* **Fix the engine:** Restore the engine's condition to 100% so you can keep traveling safely.

## Requirements

To compile the project, you will need a C++ compiler that supports C++11 (or newer), such as `g++`, `clang++`, or MSVC.

## How to compile and run

### Linux / macOS (using GCC/g++)

1. Open a terminal in the project folder.

2. Compile the code using the following command:

   ```bash
   g++ app.cpp Car.cpp Cars.cpp -o car_simulation
   ```

3. Run the compiled executable:

   ```bash
   ./car_simulation
   ```

### Windows (using MinGW / g++)

1. Open Command Prompt (CMD) or PowerShell in the project folder.

2. Compile the code:

   ```cmd
   g++ app.cpp Car.cpp Cars.cpp -o car_simulation.exe
   ```

3. Run the application:

   ```cmd
   car_simulation.exe
   ```

## File Structure

* `app.cpp` - The main program loop and console menu (user interface).
* `Car.h` / `Car.cpp` - Definition and implementation of the `Car` class, responsible for vehicle logic (handling fuel, engine wear, driving mechanics).
* `Cars.h` / `Cars.cpp` - A collection of predefined car objects available in the simulation (Passat, Opel, Golf).
* `.gitignore` - Tells Git to ignore compiled `.exe` files and configuration folders (like `.vscode/`).