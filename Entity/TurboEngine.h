#pragma once
#include "Engine.h"

class TurboEngine : public Engine
{
public:
	double getPrice() const override;
	std::string toString() const override;
};

