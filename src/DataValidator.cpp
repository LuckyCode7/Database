#include <../inc/DataValidator.hpp>
#include <algorithm>

bool DataValidator::isAlpha(const std::string &input)  noexcept
{
    bool flag {true};
    std::find_if(std::begin(input), std::end(input), [&](const char letter)
    {
        if(isalpha(letter))
        {
            flag = false;
            return false;
        }
    });
    return true;
}

bool DataValidator::isDigit(const std::string &input)  noexcept
{
    bool flag {true};
    std::find_if(std::begin(input), std::end(input), [&](const char letter)
    {
        if(isdigit(letter))
        {
            flag = false;
            return false;
        }
    });
    return flag;
}

bool DataValidator::checkMinimumStringSize(const std::string &input, const int minSize)  noexcept
{
    if (input.size() < minSize)
        return false;
    else return true;
}
