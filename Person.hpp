#pragma once
#include "Exceptions.hpp"
#include <string>
#include <iostream>
#include <array>
#include <cctype>
#include <sstream>
#include <limits>
#include <vector>
#include <algorithm>
#include <fstream>
#include<exception>
#include <ctime>
#include <set>

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
    bool checkPesel(const string&) const;
    bool checkName(const string&) const;
    bool checkAdress(const string&) const;
    void setCorrectAdressFormat();
    bool checkGender(const string&) const;
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
    string getGender() const;
    string getAdress() const;
    virtual int getSalary() const = 0;
    virtual void setSalary(const int&) = 0;
    virtual int getIndex() const = 0;
    virtual void showPerson() const;
};