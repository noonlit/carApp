#pragma once

#include <string>

class MenuItem {
private:
    std::string id;
    std::string label;

public:
    MenuItem(const std::string& _id, const std::string& _label) : id(_id), label(_label) {};

    std::string getId() const;
    std::string getLabel() const;
};