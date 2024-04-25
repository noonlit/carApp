// carApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include "Ui/MenuItem.h"
#include "Ui/ConsoleMenu.h"
#include "Service/Service.h"
#include "Validator/Validator.h"
#include "Helper/StringHelper.h"

Car* addCar(Validator& validator, Service& service)
{
    std::string bodyStyle;

    while (true) {
        std::cout << "Does the car have 2 or 4 doors? ";
        std::cin >> bodyStyle;

        if (!validator.isValidBodyStyle(bodyStyle)) {
            std::cout << "Body style is invalid. Please try again.\n";
            continue;
        }

        break;
    }

    std::string engineType;
    while (true) {
        std::cout << "Is the car's engine type turbo or electric? ";
        std::cin >> engineType;
        engineType = StringHelper::toLower(engineType);

        if (!validator.isValidEngineType(engineType)) {
            std::cout << "Engine type is invalid. Please try again.\n";
            continue;
        }

        break;
    }

    if (engineType == "turbo") {
        return service.addCar(bodyStyle, engineType, std::nullopt);
    }

    std::string autonomy;
    int autonomyInt;

    while (true) {
        std::cout << "What is the car's autonomy, expressed as a number? ";
        std::cin >> autonomy;

        try {
            autonomyInt = std::stoi(autonomy);
        } catch (...) {
            std::cout << "Autonomy is not a number. Please try again.\n";
            continue;
        }

        if (!validator.isValidAutonomy(autonomyInt)) {
            std::cout << "Autonomy is invalid. Please try again.\n";
            continue;
        }

        break;
    }

    return service.addCar(bodyStyle, engineType, autonomyInt);
}

void saveCars(Validator& validator, Service& service)
{
    std::string maxPrice;
    double maxPriceDouble;

    while (true) {
        std::cout << "What is the maximum price? ";
        std::cin >> maxPrice;

        try {
            maxPriceDouble = std::stod(maxPrice);
        }
        catch (...) {
            std::cout << "Maximum price is not a valid number. Please try again.\n";
            continue;
        }

        break;
    }

    std::string filename;

    while (true) {
        std::cout << "What is the name of the file? ";
        std::cin >> filename;


        if (!validator.fileCanBeCreated(filename)) {
            std::cout << "This file cannot be created. Please try again.\n";
            continue;
        }

        break;
    }

    std::vector<Car*> cars = service.getCarsWithMaxPrice(maxPriceDouble);

    if (cars.empty()) {
        std::cout << "There are no cars that match the criteria.\n";

        return;
    }


    if (service.writeToFile(filename, cars)) {
        std::cout << "Car data has been saved to the given file.\n";
    } else {
        std::cout << "Could not write to file.\n";
    }

}

int main()
{
    // Build menu choices
    std::string addCarChoiceId = "1";
    MenuItem addCarChoice(addCarChoiceId, "Add a car");
    std::string showCarsChoiceId = "2";
    MenuItem showCarsChoice(showCarsChoiceId, "Show all cars");
    std::string saveCarsWithMaxPriceChoiceId = "3";
    MenuItem saveCarsChoice(saveCarsWithMaxPriceChoiceId, "Save cars below a price to a file");

    std::vector<MenuItem> menuOptions = { addCarChoice, showCarsChoice, saveCarsChoice };

    ConsoleMenu menu(menuOptions);
    Validator validator;
    Service service;

    std::string choice;

    do {
        menu.display();

        choice = menu.getUserChoice();

        bool matched = false;
        for (const auto& item : menuOptions) {
            if (item.getId() == choice) {
                matched = true;

                // #1: Add car
                if (choice == addCarChoiceId) {
                    Car* car = addCar(validator, service);

                    if (car == nullptr) {
                        std::cout << "There were errors. Please try again.\n";
                        break;
                    }

                    std::cout << car->toString();
                }

                // #2: Show all cars
                if (choice == showCarsChoiceId) {
                    std::vector<Car*> cars = service.getCars();

                    if (cars.empty()) {
                        std::cout << "There are no cars.\n";
                    }

                    for (const auto& car : cars) {
                        std::cout << car->toString();
                    }
                }

                // #3: Save cars to file
                if (choice == saveCarsWithMaxPriceChoiceId) {
                    saveCars(validator, service);
                }

            }
        }

        if (!matched && choice != ConsoleMenu::EXIT_OPTION) {
            std::cout << "Invalid choice. Please retry.\n";
        }
    } while (choice != ConsoleMenu::EXIT_OPTION);

    return 0;
}