#pragma once
#include <../inc/Person.hpp>

class Employee : public Person
{
private:
    int salary;
public:
    Employee(const std::string& firstName_, const std::string& lastName_, const std::string& pesel_,
        const std::string& gender_, const Adress& adress_, const int salary_);
    ~Employee();
    void setSalary(const int salary_) override;
    void toString() const noexcept override;
    int getSalary() const noexcept override;
    int getIndex() const noexcept override;
    void setIndex(const int index_) noexcept;
};
