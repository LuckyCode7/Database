#pragma once
#include <string>
#include <iostream>
#include <array>
#include <stdlib.h>
#include <conio.h>
#include <cctype>

using std::string;

class Person
{
private:
    string firstName;
    string lastName;
    std::array<int, 11> PESEL;
    string gender;
    string adress;
    bool peselValidation(const std::array<int, 11>);
public:
    virtual ~Person() = 0;
    void setPESEL(const std::array<int, 11>);
    void setGender(const string&);
    void setFirstName(const string&);
    void setLastName(const string&);
    void setAdress(const string&);
};