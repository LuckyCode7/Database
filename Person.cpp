#include "Person.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <array>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool Person::checkPesel(const string& pesel_) const
{
    if (pesel_.size() != 11)
        return false;
    for (int i = 0; i < pesel_.size(); i++)
    {
        if (isalpha(pesel_[i]))
          return false;
    }
    std::array<int, 11> p;
    for (int i = 0; i < pesel_.size(); i++)
    {
       const  char* letter = &pesel_[i];
       p[i] = *letter - '0';
    }
    if ((9 * p[0] + 7 * p[1] + 3 * p[2] + 1 * p[3] + 9 * p[4] + 7 * p[5] + 3 * p[6] + 1 * p[7] + 9 * p[8] + 7 * p[9]) % 10 == p[10])
        return true;
    return false;
}

bool Person::checkName(const string& name_) const
{
    if (name_.size() < 3)
        return false;
    for (int i = 0; i < name_.size(); i++)
    {
        if (isdigit(name_[i]))
            return false;
    }
    return true;
}

bool Person::checkAdress(const string& adress_) const
{
    std::size_t found = adress_.find(",");

    if ((found == std::string::npos))
        return false;
    else
        if (isdigit(adress_[found + 2]) == false)
            return false;
        else
            return true;
}

void Person::setCorrectAdressFormat()
{
    int numeralCounter = 0;
    std::size_t found = adress.find(",");
    adress[0] = toupper(adress[0]);
    for (int i = 0; i < adress.size(); i++)
    {
        if (isdigit(adress[i]))
            numeralCounter++;
    }
    switch (numeralCounter)
    {
    case 1:
        adress[found + 4] = toupper(adress[found + 4]);
        break;
    case 2:
        adress[found + 5] = toupper(adress[found + 5]);
        break;
    case 3:
        adress[found + 6] = toupper(adress[found + 6]);
        break;
    case 4:
        adress[found + 7] = toupper(adress[found + 7]);
        break;
    }
    adress += " street";
}

bool Person::checkGender(const string& gender_) const
{
    if (gender_ != "man" && gender_ != "woman")
        return false;
    else
        return true;
}

Person::Person(const string& firstName_, const string& lastName_, const string& pesel_,
    const string & gender_, const string & adress_)
    :firstName(firstName_)
    ,lastName(lastName_)
    ,PESEL(pesel_)
    ,gender(gender_)
    ,adress(adress_)
{}

void Person::setPesel(const string& pesel_)
{
    try
    {
        PESEL = pesel_;
        if (!checkPesel(PESEL))
            throw InvalidPesel(firstName + " " + lastName);
    }
    catch (InvalidPesel& exception)
    {
        cout << exception.what() << endl;
        exception.message();
        while (!checkPesel(PESEL))
        {
            cout << endl << "Set correct PESEL:\a";
            cin >> PESEL;
        }
    }
}

void Person::setGender(const string& gender_)
{
    try
    {
        this->gender = gender_;
        if (!checkGender(gender_))
            throw InvalidGender(firstName + " " + lastName);
    }
    catch (InvalidGender& exception)
    {
        cout << exception.what() << endl;
        exception.message();
        do
        {
            cout << "Set correct gender <man/woman> :\a";
            cin >> gender;
        } while (!checkGender(gender));
    }
}

void Person::setFirstName(const string& firstName_)
{
    try
    {
        firstName = firstName_;
        if (!checkName(firstName_))
            throw InvalidFirstName(firstName + " " + lastName);
    }
    catch (InvalidFirstName& exception)
    {
        cout << exception.what() << endl;
        exception.message();
        while (!checkName(firstName))
        {
            cout << "Set correct first name: \a";
            cin >> firstName;
        }
    }
    firstName[0] = toupper(firstName[0]);
}

void Person::setLastName(const string& lastName_)
{
    {
        try
        {
            lastName = lastName_;
            if (!checkName(lastName_))
                throw InvalidLastName(firstName + " " + lastName);
        }
        catch (InvalidLastName& exception)
        {
            cout << exception.what() << endl;
            exception.message();
            while (!checkName(lastName))
            {
                cout << "Set correct last name: \a";
                cin >> lastName;
            }
        }
        lastName[0] = toupper(lastName[0]);
    }
}

void Person::setAdress(const string& adress_)
{
    try
    {
        adress = adress_;
        if (!(checkAdress(adress)))
            throw InvalidAdress(firstName + " " + lastName);
    }
    catch (InvalidAdress& exception)
    {
        string city;
        int number;
        string street;
        std::stringstream ss;
        cout << exception.what() << endl;
        exception.message();
        cout << exception.format() << endl;
        cout << "Set city: \a";
        cin >> city;
        do
        {
            cout << "Set number of street: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cin >> number;
        } while (cin.fail() || number < 0);
        cout << "Set street: ";
        cin >> street;
        city[0] = toupper(city[0]);
        street[0] = toupper(street[0]);
        ss << number;
        this->adress = city + ", " + ss.str() + " " + street;
    }
    setCorrectAdressFormat();
}

string Person::getLastName() const
{
    return lastName;
}

string Person::getFirstName() const
{
    return firstName;
}

string Person::getPesel() const
{
    return PESEL;
}

string Person::getGender() const
{
    return gender;
}

string Person::getAdress() const
{
    return adress;
}

void Person::showPerson() const
{
    cout << endl << "First name: \t" << firstName << endl;
    cout << "Last name: \t" << lastName << endl;
    cout << "PESEL: \t\t" << PESEL << endl;
    cout << "Gender: \t" << gender << endl;
    cout << "Adress: \t" << adress << endl;
}



