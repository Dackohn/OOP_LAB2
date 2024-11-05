#include "Barista.h"
#include <iostream>
#include <memory>

using namespace std; 

void Barista::showMenuAndMakeCoffee() {
    vector<unique_ptr<Coffee::Coffee>> coffees;
    int choice;

    cout << "Welcome to the Coffee Shop!" << endl;
    cout << "Please choose a coffee to make:" << endl;
    cout << "1. Americano" << endl;
    cout << "2. Cappuccino" << endl;
    cout << "3. Pumpkin Spice Latte" << endl;
    cout << "4. Syrup Cappuccino" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    Coffee::Intensity intensity;
    int intensityChoice;
    cout << "Choose intensity (1. Light, 2. Medium, 3. Strong): ";
    cin >> intensityChoice;
    intensity = (intensityChoice == 1) ? Coffee::Intensity::LIGHT : (intensityChoice == 2) ? Coffee::Intensity::NORMAL : Coffee::Intensity::STRONG;

    switch (choice) {
        case 1: {
            int waterAmount;
            cout << "Enter water amount (ml): ";
            cin >> waterAmount;
            coffees.push_back(make_unique<Coffee::Americano>(intensity, waterAmount));
            break;
        }
        case 2: {
            int milkAmount;
            cout << "Enter milk amount (ml): ";
            cin >> milkAmount;
            coffees.push_back(make_unique<Coffee::Cappuccino>(intensity, milkAmount));
            break;
        }
        case 3: {
            int milkAmount, pumpkinSpiceAmount;
            cout << "Enter milk amount (ml): ";
            cin >> milkAmount;
            cout << "Enter pumpkin spice amount (mg): ";
            cin >> pumpkinSpiceAmount;
            coffees.push_back(make_unique<Coffee::PumpkinSpiceLatte>(intensity, milkAmount, pumpkinSpiceAmount));
            break;
        }
        case 4: {
            int milkAmount;
            int syrupChoice;
            Coffee::SyrupType syrup;
            cout << "Enter milk amount (ml): ";
            cin >> milkAmount;
            cout << "Choose syrup type (1. Macadamia, 2. Vanilla, 3. Coconut, 4. Caramel, 5. Chocolate, 6. Popcorn): ";
            cin >> syrupChoice;
            syrup = static_cast<Coffee::SyrupType>(syrupChoice - 1);
            coffees.push_back(make_unique<Coffee::SyrupCappuccino>(intensity, milkAmount, syrup));
            break;
        }
        default:
            cout << "Invalid choice." << endl;
            return;
    }

    for (const auto& coffee : coffees) {
        cout << "\n" << endl;
        //coffee->printDetails();
        //cout << "\n" << endl;
        coffee->make();
        cout << "-----" << endl;
    }
}
