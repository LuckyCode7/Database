#include "Employee.hpp"

Employee::Employee(const string & firstName_, const string & lastName_, const string& pesel_,
    const string & gender_, const string & adress_, const int & salary_)
{
    this->setFirstName(firstName_);
    this->setLastName(lastName_);
    this->setPesel(pesel_);
    this->setGender(gender_);
    this->setAdress(adress_);
    this->setSalary(salary_);
}

Employee::~Employee() {}

void Employee::setSalary(const int& salary_)
{
    try
    {
        this->salary = salary_;
        if (salary_ < 0)
            throw InvalidSalary();
    }
    catch (InvalidSalary& exception)
    {
        cout << exception.what() << endl;
        while (this->salary < 0)
        {
            cout << "Set correct salary: \a";
            cin >> this->salary;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
    }
}

void Employee::showPerson()
{
    cout << "Status: \temployee";
    Person::showPerson();
    cout << "Index: \t\t" << this->salary << "$" << endl << endl;
}

int Employee::getSalary() const
{
    return this->salary;
}

