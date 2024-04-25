#include "StringHelper.h"

std::string StringHelper::toLower(const std::string& str)
{
    std::string result;
    for (char c : str) {
        result += std::tolower(c);
    }
    return result;
}
