#include <../inc/Employee.hpp>
#include <../inc/Exceptions.hpp>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Employee::Employee(const string & firstName_, const string & lastName_, const string& pesel_,
    const string & gender_, const string & adress_, const int & salary_)
    :Person(firstName_, lastName_, pesel_, gender_, adress_)
    ,salary(salary_)
{}

Employee::~Employee() {}

void Employee::setSalary(const int& salary_)
{
    try
    {
        salary = salary_;
        if (salary_ < 0)
            throw InvalidSalary(getFirstName() + " " + getLastName());
    }
    catch (InvalidSalary& exception)
    {
        cout << exception.what() << endl;
        exception.message();
        while (salary < 0)
        {
            cout << "Set correct salary: \a";
            cin >> salary;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
    }
}

void Employee::showPerson() const
{
    cout << "Status: \temployee";
    Person::showPerson();
    cout << "Salary: \t" << salary << "$" << endl << endl;
}

int Employee::getSalary() const
{
    return salary;
}

int Employee::getIndex() const
{
    return 0;
}

void Employee::setIndex(const int& index_) {}


