#pragma once
#include <string>
#include "Engine.h"

class ElectricEngine : public Engine
{
private:
	int autonomy;

public:
	ElectricEngine(int _autonomy) : Engine(), autonomy(_autonomy) {};
	double getPrice() const override;
	std::string toString() const override;
};