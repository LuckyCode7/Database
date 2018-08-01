#pragma once
#include <string>
#include <iostream>
#include <array>
#include <stdlib.h>
#include <conio.h>
#include <cctype>
#include <sstream>
#include <limits>
#include "Exceptions.hpp"
#include <vector>
#include <algorithm>
#include <cstdlib>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Person
{
protected:
    string firstName;
    string lastName;
    string PESEL;
    string gender;
    string adress;
private:
    bool checkPesel(const string&);
    bool checkName(const string&);
    bool checkAdress(const string&);
    void setCorrectAdressFormat();
    bool checkGender(const string&);
    void showPesel();
public:
    virtual ~Person() {}
    void setPesel(const string&);
    void setGender(const string&);
    void setFirstName(const string&);
    void setLastName(const string&);
    void setAdress(const string&);
    string getLastName() const;
    string getFirstName() const;
    string getPesel() const;
    virtual int getSalary() const = 0;
    virtual void showPerson();
};