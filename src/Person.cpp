#include <../inc/Person.hpp>
#include <../inc/Exceptions.hpp>
#include <../inc/PeselValidator.hpp>
#include <../inc/NameValidator.hpp>
#include <../inc/GenderValidator.hpp>
#include <../inc/AdressValidator.hpp>
#include <iostream>

Person::Person(const std::string& firstName_, const std::string& lastName_, const std::string& pesel_,
               const std::string & gender_, const Adress &adress_)
    :firstName(firstName_)
    ,lastName(lastName_)
    ,PESEL(pesel_)
    ,gender(gender_)
    ,adress(adress_)
{}

void Person::setPesel(const std::string& pesel_)
{
    try
    {
        PESEL = pesel_;
        if (!PeselValidator::checkPesel(PESEL))
            throw InvalidPesel(firstName + " " + lastName);
    }
    catch (InvalidPesel& exception)
    {
        std::cout << exception.what() << std::endl;
        exception.message();
        while (!PeselValidator::checkPesel(PESEL))
        {
            std::cout << std::endl << "Set correct PESEL:\a";
            std::cin >> PESEL;
        }
    }
}

void Person::setGender(const std::string& gender_)
{
    try
    {
        gender = gender_;
        if (!GenderValidator::checkGender(gender_))
            throw InvalidGender(firstName + " " + lastName);
    }
    catch (InvalidGender& exception)
    {
        std::cout << exception.what() << std::endl;
        exception.message();
        do
        {
            std::cout << "Set correct gender <man/woman> :\a";
            std::cin >> gender;
        } while (!GenderValidator::checkGender(gender));
    }
}

void Person::setFirstName(const std::string& firstName_)
{
    try
    {
        firstName = firstName_;
        if (!NameValidator::checkName(firstName_))
            throw InvalidFirstName(firstName + " " + lastName);
    }
    catch (InvalidFirstName& exception)
    {
        std::cout << exception.what() << std::endl;
        exception.message();
        while (!NameValidator::checkName(firstName))
        {
            std::cout << "Set correct first name: \a";
            std::cin >> firstName;
        }
    }
    firstName[0] = toupper(firstName[0]);
}

void Person::setLastName(const std::string& lastName_)
{
    try
    {
        lastName = lastName_;
        if (!NameValidator::checkName(lastName_))
            throw InvalidLastName(firstName + " " + lastName);
    }
    catch (InvalidLastName& exception)
    {
        std::cout << exception.what() << std::endl;
        exception.message();
        while (!NameValidator::checkName(lastName))
        {
            std::cout << "Set correct last name: \a";
            std::cin >> lastName;
        }
    }
    lastName[0] = toupper(lastName[0]);

}

void Person::setAdress(const Adress& adress_)
{
    try
    {
        adress = adress_;
        if (!AdressValidator::checkAdress(adress))
            throw InvalidAdress(firstName + " " + lastName);
    }
    catch (InvalidAdress& exception)
    {
        std::cout << exception.what() << std::endl;
        exception.message();
        std::cout << exception.format() << std::endl;
        while(!AdressValidator::checkAdress(adress))
            fillInAdress();
    }
}

void Person::fillInAdress() noexcept
{
    std::string city, street;
    int number;
    std::cout<<"Set city: ";
    std::cin>>city;
    adress.setCity(city);
    std::cout<<"Set street: ";
    std::cin>>street;
    adress.setStreet(street);
    std::cout<<"Set number of street: ";
    std::cin>>number;
    adress.setNumberOfStreet(number);
}

std::string Person::getLastName() const noexcept
{
    return lastName;
}

std::string Person::getFirstName() const noexcept
{
    return firstName;
}

std::string Person::getPesel() const noexcept
{
    return PESEL;
}

std::string Person::getGender() const noexcept
{
    return gender;
}

Adress Person::getAdress() const noexcept
{
    return adress;
}

void Person::toString() const noexcept
{
    std::cout << std::endl << "First name: \t" << firstName << std::endl;
    std::cout << "Last name: \t" << lastName << std::endl;
    std::cout << "PESEL: \t\t" << PESEL << std::endl;
    std::cout << "Gender: \t" << gender << std::endl;
    std::cout << "Adress: \t" << adress.toString() << std::endl;
}

