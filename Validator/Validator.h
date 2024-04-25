#pragma once
#include <string>

class Validator {
public:
    bool isValidBodyStyle(const std::string& bodyStyle) const;
    bool isValidEngineType(const std::string& engineType) const;
    bool isValidAutonomy(const int autonomy) const;
    bool fileCanBeCreated(const std::string& filename) const;
};