#include <iostream>
#include <vector>
#include "ConsoleMenu.h"

const std::string ConsoleMenu::EXIT_OPTION = "q";

void ConsoleMenu::display() const {
    std::cout << "Menu:\n";
    for (size_t i = 0; i < options.size(); ++i) {
        std::cout << options[i].getId() << ": " << options[i].getLabel() << std::endl;
    }
    std::cout << "To exit, type " << ConsoleMenu::EXIT_OPTION << '.' << std::endl;
}

std::string ConsoleMenu::getUserChoice() const {
    std::string choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;

    return choice;
}

size_t ConsoleMenu::getNumOptions() const {
    return options.size();
}
