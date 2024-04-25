#include "ElectricEngine.h"

double ElectricEngine::getPrice() const
{
	return Engine::getPrice() + autonomy * 0.01;
}

std::string ElectricEngine::toString() const
{
	return "Electric Engine";
}
