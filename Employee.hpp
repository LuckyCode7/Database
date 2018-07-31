#pragma once
#include "Person.hpp"

class Employee : public Person
{
private:
    int salary;
public:
    Employee(const string& firstName_, const string& lastName_, const std::array<int, 11>& pesel,
        const string& gender, const string& adress, const int& salary);
    ~Employee();
    void setSalary(const int&);
    void showPerson();
    int getSalary() const;
};
