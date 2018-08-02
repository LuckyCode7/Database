#include "Person.hpp"
#include "Exceptions.hpp"

bool Person::checkPesel(const string& pesel) const
{
    if (pesel.size() != 11)
        return false;
    for (int i = 0; i < pesel.size(); i++)
    {
        if (isalpha(pesel[i]))
          return false;
    }
    std::array<int, 11> p;
    for (int i = 0; i < pesel.size(); i++)
    {
       const  char* letter = &pesel[i];
       p[i] = *letter - '0';
    }
    if ((9 * p[0] + 7 * p[1] + 3 * p[2] + 1 * p[3] + 9 * p[4] + 7 * p[5] + 3 * p[6] + 1 * p[7] + 9 * p[8] + 7 * p[9]) % 10 == p[10])
        return true;
    return false;
}

bool Person::checkName(const string & name) const
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

bool Person::checkAdress(const string& adress) const
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
    this->adress += " street";
}

bool Person::checkGender(const string & gender) const
{
    if (gender != "man" && gender != "woman")
        return false;
    return true;
}

void Person::setPesel(const string& pesel)
{
    try
    {
        this->PESEL = pesel;
        if (!checkPesel(this->PESEL))
            throw InvalidPesel();
    }
    catch (InvalidPesel& exception)
    {
        cout << exception.what() << endl;

        while (!checkPesel(this->PESEL))
        {
            cout << endl << "Set correct "<<this->firstName<<" "<<this->lastName<<"'s PESEL:\a";
            cin >> this->PESEL;
        }
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
        this->adress = city + ", " + ss.str() + " " + street;
    }
    setCorrectAdressFormat();
}

string Person::getLastName() const
{
    return this->lastName;
}

string Person::getFirstName() const
{
    return this->firstName;
}

string Person::getPesel() const
{
    return this->PESEL;
}

string Person::getGender() const
{
    return this->gender;
}

string Person::getAdress() const
{
    return this->adress;
}

void Person::showPerson() const
{
    cout << endl << "First name: \t" << this->firstName << endl;
    cout << "Last name: \t" << this->lastName << endl;
    cout << "PESEL: \t\t" << this->PESEL << endl;
    cout << "Gender: \t" << this->gender << endl;
    cout << "Adress: \t" << this->adress << endl;
}



