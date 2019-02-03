#include <../inc/PeselValidator.hpp>
#include <array>

bool PeselValidator::checkPeselSize(const std::string &pesel) noexcept
{
    if (pesel.size() != 11)
        return false;
    else return true;
}

bool PeselValidator::checkNumbersDependencies(const std::string &pesel) noexcept
{
    std::array<int, 11> p;
    for (unsigned int i = 0; i < pesel.size(); i++)
        p[i] = pesel[i] - '0';
    if ((9 * p[0] + 7 * p[1] + 3 * p[2] + 1 * p[3] + 9 * p[4] + 7 * p[5] + 3 * p[6] + 1 * p[7] + 9 * p[8] + 7 * p[9]) % 10 == p[10])
        return true;
    else return false;
}

bool PeselValidator::checkPesel(const std::string &pesel) noexcept
{
    if(checkPeselSize(pesel))
    {
        if(PeselValidator::isAlpha(pesel))
        {
            return checkNumbersDependencies(pesel);
        }
        else return false;
    }
    else return false;
}
