#pragma once

#include <string>
#include <vector>
#include <optional>
#include "../Entity/Car.h"

class Service {
private:
    std::vector<Car*> cars;

public:
    Car* addCar(const std::string& bodyStyle, const std::string& engineType, std::optional<int> autonomy);
    std::vector<Car*> getCars() const;
    std::vector<Car*> getCarsWithMaxPrice(const double& maxPrice) const;
    bool writeToFile(const std::string& filename, std::vector<Car*> cars) const;
    ~Service();
};