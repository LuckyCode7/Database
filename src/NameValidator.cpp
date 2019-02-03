#include <../inc/NameValidator.hpp>

bool NameValidator::checkName(const std::string& name)  noexcept
{
    if(checkMinimumStringSize(name, 2))
    {
        return isDigit(name);
    }
    else return false;
}
