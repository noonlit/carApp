#pragma once
#include "Engine.h"

class Car
{
private:
	int numberOfDoors;
	Engine* engine;

public:
	Car(int _numberOfDoors, Engine* _engine) : numberOfDoors(_numberOfDoors), engine(_engine) {};

	double computePrice() const;
	int getNumberOfDoors() const;
	std::string toString() const;
};