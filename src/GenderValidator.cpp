#include <../inc/GenderValidator.hpp>

std::string GenderValidator::man = "man";
std::string GenderValidator::woman = "woman";

bool GenderValidator::checkGender(const std::string &gender) noexcept
{
    if (gender != man && gender != woman)
        return false;
    else
        return true;
}
