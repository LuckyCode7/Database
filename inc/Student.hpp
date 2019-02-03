#pragma once
#include <../inc/Person.hpp>

class Student : public Person
{
private:
    int index;
    bool correctIndex(const int index_) const noexcept;
public:
    Student(const std::string& firstName_, const std::string& lastName_, const std::string& pesel,
        const std::string& gender, const Adress &adress, const int index);
    ~Student();
    void setIndex(const int index_) override;
    void toString() const noexcept override;
    int getSalary() const noexcept override;
    int getIndex() const noexcept override;
    void setSalary(const int) override;
};
