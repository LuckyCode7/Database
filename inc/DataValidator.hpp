#pragma once
#include <string>

class DataValidator
{
public:
    static bool isAlpha(const std::string& input)  noexcept;
    static bool isDigit(const std::string &input) noexcept;
    static bool checkMinimumStringSize(const std::string& input, const int minSize) noexcept;
};
