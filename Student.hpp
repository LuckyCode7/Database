#pragma once
#include "Person.hpp"

class Student : public Person
{
private:
    int index;
public:
    Student(const string& firstName_, const string& lastName_, const std::array<int, 11>& pesel,
        const string& gender, const string& adress, int index);
    ~Student();

};
