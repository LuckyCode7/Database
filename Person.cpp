#include "Person.hpp"
#include "Exceptions.hpp"

bool Person::checkPesel(const std::array<int, 11> p)
{
    if ((9 * p[0] + 7 * p[1] + 3 * p[2] + 1 * p[3] + 9 * p[4] + 7 * p[5] + 3 * p[6] + 1 * p[7] + 9 * p[8] + 7 * p[9]) % 10 == p[10])
        return true;
    return false;
}

bool Person::checkName(const string & name)
{
    if (name.size() < 3)
        return false;
    for (int i = 0; i < name.size(); i++)
    {
        if (!isalpha(name[i]))
            return false;
    }
    return true;
}

bool Person::checkAdress(const string& adress)
{
    std::size_t found = adress.find(",");

    if ((found == std::string::npos))
        return false;
    else
        if (isdigit(adress[found + 2]) == false)
            return false;
        else
            return true;
}

void Person::setCorrectAdressFormat()
{
    int numeralCounter = 0;
    std::size_t found = adress.find(",");
    this->adress[0] = toupper(this->adress[0]);
    for (int i = 0; i < this->adress.size(); i++)
    {
        if (isdigit(this->adress[i]))
            numeralCounter++;
    }
    switch (numeralCounter)
    {
    case 1:
        this->adress[found + 4] = toupper(this->adress[found + 4]);
        break;
    case 2:
        this->adress[found + 5] = toupper(this->adress[found + 5]);
        break;
    case 3:
        this->adress[found + 6] = toupper(this->adress[found + 6]);
        break;
    case 4:
        this->adress[found + 7] = toupper(this->adress[found + 7]);
        break;
    }
}

bool Person::checkGender(const string & gender)
{
    if (gender != "man" && gender != "woman")
        return false;
    return true;
}

void Person::showPesel()
{
    for (int i = 0; i < 11; i++)
        cout << "[" << this->PESEL[i] << "]";
}

void Person::setPesel(const std::array<int, 11> pesel)
{
    try
    {
        this->PESEL = pesel;
        if (!checkPesel(this->PESEL))
            throw InvalidPesel();
    }
    catch (InvalidPesel& exception)
    {
        int sign;
        cout << exception.what() << endl;

        while (!checkPesel(this->PESEL))
        {
            cout << endl << "Set correct PESEL: \a";
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
}

void Person::setGender(const string& gender_)
{
    try
    {
        this->gender = gender_;
        if (!checkGender(gender_))
            throw InvalidGender();
    }
    catch (InvalidGender& exception)
    {
        cout << exception.what() << endl;
        do
        {
            cout << "Set  correct gender <man/woman> :\a";
            cin >> this->gender;
        } while (!checkGender(this->gender));
    }
}

void Person::setFirstName(const string& firstName_)
{
    try
    {
        this->firstName = firstName_;
        if (!checkName(firstName_))
            throw InvalidFirstName();
    }
    catch (InvalidFirstName& exception)
    {
        cout << exception.what() << endl;
        while (!checkName(this->firstName))
        {
            cout << "Set correct first name: \a";
            cin >> this->firstName;
        }
    }
    this->firstName[0] = toupper(this->firstName[0]);
}

void Person::setLastName(const string & lastName_)
{
    {
        try
        {
            this->lastName = lastName_;
            if (!checkName(lastName_))
                throw InvalidLastName();
        }
        catch (InvalidLastName& exception)
        {
            cout << exception.what() << endl;
            while (!checkName(this->lastName))
            {
                cout << "Set correct first name: \a";
                cin >> this->lastName;
            }
        }
        this->lastName[0] = toupper(this->lastName[0]);
    }
}

void Person::setAdress(const string& adress)
{
    try
    {
        this->adress = adress;
        if (!(checkAdress(adress)))
            throw InvalidAdress();
    }
    catch (InvalidAdress& exception)
    {
        string city;
        int number;
        string street;
        std::stringstream ss;
        cout << exception.what() << endl;
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
        this->adress = city + ", " + ss.str() + " " + street + " street";
        cout << this->adress << endl;
    }
    setCorrectAdressFormat();
}

string Person::getLastName() const
{
    return this->lastName;
}

std::array<int, 11> Person::getPesel() const
{
    return this->PESEL;
}

void Person::showPerson()
{
    cout << endl << "First name: \t" << this->firstName << endl;
    cout << "Last name: \t" << this->lastName << endl;
    cout << "PESEL: \t\t"; this->showPesel(); cout << endl;
    cout << "Gender: \t" << this->gender << endl;
    cout << "Adress: \t" << this->adress << endl;
}



