#include "Person.hpp"

class Database
{
public:
    Database();
    ~Database();
    void addToDatabase(Person*) const;
    void showDatabase() const;
    void findLastName(const string&) const;
    void findPesel(const string&) const;
    void sortByLastName() const;
    void sortByPesel() const;
    void sortBySalary() const;
    void addToExternalFile() const;
    void loadFromExternalFile() const;
    void removePerson(const string&) const;
    void changeEmployeeSalary(const string& pesel_, const int& salary_) const;
    void changeAdress(const string& pesel_, const string& adress_) const;
};
