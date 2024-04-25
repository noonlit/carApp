#include <fstream>
#include "Validator.h"

bool Validator::isValidBodyStyle(const std::string& bodyStyle) const
{
	return bodyStyle == "4" || bodyStyle == "2";
}

bool Validator::isValidEngineType(const std::string& engineType) const
{
	return engineType == "turbo" || engineType == "electric";
}

bool Validator::isValidAutonomy(const int autonomy) const
{
	return autonomy > 0;
}

bool Validator::fileCanBeCreated(const std::string& filename) const
{
	std::ofstream file(filename);

	return file.good();
}
