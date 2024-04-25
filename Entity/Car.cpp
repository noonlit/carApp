#include <iostream>
#include <sstream>
#include "Car.h"

double Car::computePrice() const
{
	double basePrice = 7000 + engine->getPrice();

	if (numberOfDoors == 2) {
		return basePrice;
	}

	if (numberOfDoors == 4) {
		return basePrice + 1500;
	}

	// ... in this case, it's just an engine
	return engine->getPrice();
}

int Car::getNumberOfDoors() const
{
	return numberOfDoors;
}

std::string Car::toString() const
{
	std::stringstream ss;

	ss << "The car has " << numberOfDoors << " doors, the engine type is " << engine->toString()
		<< " and the car price is " << computePrice() << "\n";

	return ss.str();
}
