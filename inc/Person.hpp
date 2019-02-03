#pragma once
#include <../inc/Adress.hpp>
#include <string>

class Person
{
private:
    std::string firstName;
    std::string lastName;
    std::string PESEL;
    std::string gender;
    Adress adress;
    void fillInAdress() noexcept;
public:
    Person(const std::string & firstName_, const std::string & lastName_, const std::string& pesel_,
           const std::string & gender_, const Adress & adress_);
    Person(const Person&) = default;
    Person& operator=(const Person&) = default;
    virtual ~Person() {}
    void setPesel(const std::string& pesel_);
    void setGender(const std::string& gender_);
    void setFirstName(const std::string& firstName_);
    void setLastName(const std::string& lastName_);
    void setAdress(const Adress &adress_);
    std::string getLastName() const noexcept;
    std::string getFirstName() const noexcept;
    std::string getPesel() const noexcept;
    std::string getGender() const noexcept;
    Adress getAdress() const noexcept;
    virtual int getSalary() const noexcept = 0;
    virtual void setSalary(const int) = 0;
    virtual void setIndex(const int) = 0;
    virtual int getIndex() const noexcept = 0;
    virtual void toString() const noexcept;
};
