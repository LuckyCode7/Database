#include "Person.hpp"
#include <set>
#include <vector>
#include<functional>

class Database
{
private:
    void checkPeronalData(Person* person);
    void randomUniqueNumber()const;
    std::set<Person*> find(std::function<bool(Person*)> what) const;
    std::vector<Person*>::iterator getIterator(const string& pesel_);
    std::vector<Person*> data;
public:
    Database();
    ~Database();
    bool addToDatabase(Person* person);
    void showDatabase() const;
    std::set<Person*> findByLastName(const string& lastName_) const;
    std::set<Person*> findByPesel(const string& pesel_) const;
    std::set<Person*> findByAdress(const string& adress_) const;
    std::set<Person*> findAllStudnents() const;
    std::set<Person*> findAllEmployees() const;
    void sortByLastName();
    void sortByPesel();
    void sortBySalary();
    void addToExternalFile(const string& fileName) const;
    void loadFromExternalFile(const string& fileName);
    void removePerson(const string& pesel_);
    void changeEmployeeSalary(const string& pesel_, const int& salary_);
    void changeAdress(const string& pesel_, const string& adress_);
    void setRandomData();
    void clearDatabase();
};
