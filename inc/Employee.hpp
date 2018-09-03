#pragma once
#include "Person.hpp"

class Employee : public Person
{
private:
    int salary;
public:
    Employee(const string& firstName_, const string& lastName_, const string& pesel_,
        const string& gender_, const string& adress_, const int& salary_);
    ~Employee();
    void setSalary(const int& salary_);
    void showPerson() const;
    int getSalary() const;
    int getIndex() const;
    void setIndex(const int& index_);
};
