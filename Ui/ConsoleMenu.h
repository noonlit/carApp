#pragma once

#include <iostream>
#include <vector>
#include <limits>
#include "MenuItem.h"

class ConsoleMenu {
private:
    std::vector<MenuItem> options;

public:
    const static std::string EXIT_OPTION;

    ConsoleMenu(const std::vector<MenuItem>& _options) : options(_options) {};

    void display() const;
    std::string getUserChoice() const;
    size_t getNumOptions() const;
};