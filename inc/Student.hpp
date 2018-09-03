#pragma once
#include <../inc/Person.hpp>

class Student : public Person
{
private:
    int index;
    bool correctIndex(const int& index_) const;
public:
    Student(const string& firstName_, const string& lastName_, const string& pesel,
        const string& gender, const string& adress, const int& index);
    ~Student();
    void setIndex(const int& index_);
    void showPerson() const;
    int getSalary() const;
    int getIndex() const;
    void setSalary(const int&);
};
