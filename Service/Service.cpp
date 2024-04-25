#include <string>
#include <optional>
#include <algorithm>
#include <fstream>
#include "Service.h"
#include "..\Entity\Car.h"
#include "..\Entity\Engine.h"
#include "..\Entity\ElectricEngine.h"
#include "..\Entity\TurboEngine.h"

Car* Service::addCar(const std::string& bodyStyle, const std::string& engineType, std::optional<int> autonomy)
{
	Engine* engine;

	if (engineType == "electric" && autonomy.has_value()) {
		engine = new ElectricEngine(autonomy.value());
	} else if (engineType == "turbo") {
		engine = new TurboEngine();
	} else {
		return nullptr;
	}

	int numberOfDoors = std::stoi(bodyStyle);

	Car* car = new Car(numberOfDoors, engine);

	cars.push_back(car);

	return car;
}

std::vector<Car*> Service::getCars() const
{
	return cars;
}

std::vector<Car*> Service::getCarsWithMaxPrice(const double& maxPrice) const
{
	std::vector<Car*> carsWithMaxPrice = std::vector<Car*>();

	// filter by max price
	for (const auto& car : cars) {
		if (car->computePrice() < maxPrice) {
			carsWithMaxPrice.push_back(car);
		}
	}

	// sort by number of doors
	std::sort(carsWithMaxPrice.begin(), carsWithMaxPrice.end(), [](Car* car1, Car* car2) {
		return car1->getNumberOfDoors() < car2->getNumberOfDoors();
		});

	return carsWithMaxPrice;
}

bool Service::writeToFile(const std::string& filename, std::vector<Car*> cars) const
{
	std::ofstream outFile(filename);

	if (outFile.is_open()) {
		for (const auto& car : cars) {
			outFile << car->toString() << std::endl;
		}

		outFile.close();
		
		return true;
	}

	return false;

}
