#pragma once
#include <string>

class Engine
{
protected:
	double basePrice = 3000;

public:
	virtual double getPrice() const;
	virtual std::string toString() const = 0;
};