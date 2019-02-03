#include<../inc/Adress.hpp>
#include <iostream>

void Adress::setCity(const std::string& city_) noexcept
{
    city = city_;
    city[0] = toupper(city[0]);
}

void Adress::setStreet(const std::string& street_) noexcept
{
    street = street_;
    street[0] = toupper(street[0]);
}

void Adress::setNumberOfStreet(const int number) noexcept
{   
    numberOfStreet = number;
}

Adress::Adress(const std::string &city_, const std::string street_, const int numberOfStreet_)
    :city(city_)
    ,street(street_)
    ,numberOfStreet(numberOfStreet_)
{}

bool Adress::operator==(const Adress &adress_) const noexcept
{
    if(adress_.city == city &&
       adress_.street == street &&
       adress_.numberOfStreet == numberOfStreet)
        return true;
    else return false;
}

std::string Adress::getCity() const noexcept
{
    return city;
}

std::string Adress::getStreet() const noexcept
{
    return street;
}

std::string Adress::toString() const noexcept
{
    return city + ", " + std::to_string(numberOfStreet) + " " + street + " street";
}

int Adress::getNumberOfStreet() const noexcept
{
    return numberOfStreet;
}
