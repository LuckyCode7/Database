#pragma once
#include "Person.hpp"

class Student : public Person
{
private:
    int index;
    bool correctIndex(const int&);
public:
    Student(const string& firstName_, const string& lastName_, const string& pesel,
        const string& gender, const string& adress, const int& index);
    ~Student();
    void setIndex(const int&);
    void showPerson();
    int getSalary() const;
    int getIndex() const;
};
