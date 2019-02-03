#include <../inc/AdressValidator.hpp>

bool AdressValidator::checkCityAndStreetLetters(const Adress &adress) noexcept
{
    if(!DataValidator::isDigit(adress.getCity()) ||
        !DataValidator::isDigit(adress.getStreet()))
        return false;
    else return true;
}

bool AdressValidator::checkCityAndStreetSize(const Adress &adress) noexcept
{
    if(!DataValidator::checkMinimumStringSize(adress.getCity(),2) ||
       !DataValidator::checkMinimumStringSize(adress.getStreet(), 2))
        return false;
    else return true;
}

bool AdressValidator::checkNumberOfStreet(const Adress &adress) noexcept
{
    if(adress.getNumberOfStreet() < 1)
        return false;
    else return true;
}

bool AdressValidator::checkAdress(const Adress &adress) noexcept
{
    if(checkCityAndStreetLetters(adress))
    {
        if(checkCityAndStreetSize(adress))
        {
            return checkNumberOfStreet(adress);
        }
        else return false;
    }
    else return false;
}
