#include "TurboEngine.h"

double TurboEngine::getPrice() const
{
	return Engine::getPrice() + 100;
}

std::string TurboEngine::toString() const
{
	return "Turbo Engine";
}
