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
    bool checkPesel(const string& pesel_) const;
    bool checkName(const string& name_) const;
    bool checkAdress(const string& adress_) const;
    void setCorrectAdressFormat();
    bool checkGender(const string& gender_) const;
public:
    Person(const string & firstName_, const string & lastName_, const string& pesel_,
        const string & gender_, const string & adress_);
    virtual ~Person() {}
    void setPesel(const string& pesel_);
    void setGender(const string& gender_);
    void setFirstName(const string& firstName_);
    void setLastName(const string& lastName_);
    void setAdress(const string& adress_);
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