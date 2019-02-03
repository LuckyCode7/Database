#include <../inc/Employee.hpp>
#include <../inc/Exceptions.hpp>
#include <iostream>
#include <limits>

Employee::Employee(const std::string & firstName_, const std::string & lastName_, const std::string& pesel_,
    const std::string & gender_, const Adress &adress_, const int salary_)
    :Person(firstName_, lastName_, pesel_, gender_, adress_)
    ,salary(salary_)
{}

Employee::~Employee() {}

void Employee::setSalary(const int salary_)
{
    try
    {
        salary = salary_;
        if (salary_ < 0)
            throw InvalidSalary(getFirstName() + " " + getLastName());
    }
    catch (InvalidSalary& exception)
    {
        std::cout << exception.what() << std::endl;
        exception.message();
        while (salary < 0)
        {
            std::cout << "Set correct salary: \a";
            std::cin >> salary;
            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
    }
}

void Employee::toString() const noexcept
{
    std::cout << "Status: \temployee";
    Person::toString();
    std::cout << "Salary: \t" << salary << "$" << std::endl << std::endl;
}

int Employee::getSalary() const noexcept
{
    return salary;
}

int Employee::getIndex() const noexcept
{
    return 0;
}

void Employee::setIndex(const int index_) noexcept
{}


