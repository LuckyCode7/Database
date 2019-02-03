#pragma once
#include<../inc/DataValidator.hpp>
#include<../inc/Adress.hpp>

class AdressValidator : public DataValidator
{
private:
    static bool checkCityAndStreetLetters(const Adress& adress) noexcept;
    static bool checkCityAndStreetSize(const Adress& adress) noexcept;
     static bool checkNumberOfStreet(const Adress& adress) noexcept;
  public:
    static bool checkAdress(const Adress& adress)  noexcept;
};
