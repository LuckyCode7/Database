#pragma once
#include <string>

using std::string;

class Person
{
private:
    string firstName;
    string lastName;
    string PESEL;
    string gender;
    string adress;
    bool checkPesel(const string&) const;
    bool checkName(const string&) const;
    bool checkAdress(const string&) const;
    void setCorrectAdressFormat();
    bool checkGender(const string&) const;
public:
    Person(const string & firstName_, const string & lastName_, const string& pesel_,
        const string & gender_, const string & adress_);
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
    virtual void setIndex(const int&) = 0;
    virtual int getIndex() const = 0;
    virtual void showPerson() const;
};