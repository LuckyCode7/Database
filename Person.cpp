#include "Person.hpp"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

bool Person::peselValidation(const std::array<int, 11> p)
{
    if ((9 * p[0] + 7 * p[1] + 3 * p[2] + 1 * p[3] + 9 * p[4] + 7 * p[5] + 3 * p[6] + 1 * p[7] + 9 * p[8] + 7 * p[9]) % 10 == p[10])
        return true;
    return false;
}

void Person::getPesel()
{
    for (int i = 0; i < 11; i++)
        cout << this->PESEL[i];
}

void Person::setPESEL(const std::array<int, 11> pesel)
{
    this->PESEL = pesel;
    int sign;
    while (!peselValidation(this->PESEL))
    {
        cout << "Set correct PESEL: ";
        cout << "-----------\b\b\b\b\b\b\b\b\b\b\b";
        for (int i = 0; i < 11; i++)
        {
            sign = _getch();
            switch (sign)
            {
            case 48:
                PESEL[i] = 0;
                cout << 0;
                break;
            case 49:
                PESEL[i] = 1;
                cout << 1;
                break;
            case 50:
                PESEL[i] = 2;
                cout << 2;
                break;
            case 51:
                PESEL[i] = 3;
                cout << 3;
                break;
            case 52:
                PESEL[i] = 4;
                cout << 4;
                break;
            case 53:
                PESEL[i] = 5;
                cout << 5;
                break;
            case 54:
                PESEL[i] = 6;
                cout << 6;
                break;
            case 55:
                PESEL[i] = 7;
                cout << 7;
                break;
            case 56:
                PESEL[i] = 8;
                cout << 8;
                break;
            case 57:
                PESEL[i] = 9;
                cout << 9;
                break;
            default:
                --i;
                cout << "\a";
                break;
            }
        }
    }
    cout << endl;
}

void Person::setGender(const string& gender_)
{
    if (gender_ != "man" && gender_ != "woman")
    {
        cout << "Incorrect type of gender" << endl;
        do
        {
            cout << "Set gender <man/woman> :";
            cin >> this->gender;
        } while (this->gender != "man" && this->gender != "woman");
    }
    else
        this->gender = gender_;
}

void Person::setFirstName(const string& firstName_)
{
    this->firstName = firstName_;
    this->firstName[0] = toupper(this->firstName[0]);
}

void Person::setLastName(const string & LastName_)
{
    this->lastName = LastName_;
    this->lastName[0] = toupper(this->lastName[0]);
}

void Person::setAdress(const string& adress)
{
    std::size_t found = adress.find(",");
    if (found == std::string::npos)
    {
        cout << "Incorrect address" << endl;
        cout << "Sample adress format: Warsaw, 7 Happy street\nEnter data:" << endl;
        string city;
        string street;
        cout << "Set city: ";
        cin >> city;
        cout << "Set street: ";
        cin >> street;
        city[0] = toupper(city[0]);
        street[0] = toupper(street[0]);
        this->adress = city + " ," + street + " street";
    }
    else
        this->adress = adress;
}

void Person::showPerson()
{
    cout << "First name: " << this->firstName << endl;
    cout << "Last name: " << this->lastName << endl;
    cout << "PESEL: " << this->getPesel << endl;
    cout << "Gender: " << this->gender << endl;
    cout << "Adress: " << this->adress << endl;
}



