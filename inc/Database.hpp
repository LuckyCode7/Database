#include <../inc/Person.hpp>
#include <set>
#include <vector>
#include <functional>

class Database
{
private:
    void checkPeronalData(Person* person) const;
    std::set<Person*> find(std::function<bool(Person*)> predicate) const noexcept;
    std::vector<Person*>::iterator getIterator(const std::string& pesel_) noexcept;
    std::vector<Person*> data;
public:
    Database() = default;
    Database(const Database&) = default;
    Database& operator=(const Database&) = default;
    Database(Database&&) = default;
    Database& operator=(Database&&) = default;
    ~Database() = default;
    bool addToDatabase(Person* person) noexcept;
    void toString() const noexcept;
    std::set<Person*> findByLastName(const std::string& lastName_) const noexcept;
    std::set<Person*> findByPesel(const std::string& pesel_) const noexcept;
    std::set<Person*> findByAdress(const Adress &adress_) const noexcept;
    std::set<Person*> findAllStudnents() const noexcept;
    std::set<Person*> findAllEmployees() const noexcept;
    void sortByLastName() noexcept;
    void sortByPesel() noexcept;
    void sortBySalary() noexcept;
    void addToExternalFile(const std::string& fileName) const noexcept;
    void removePerson(const std::string& pesel_) noexcept;
    void changeEmployeeSalary(const std::string& pesel_, const int& salary_);
    void changeAdress(const std::string& pesel_, const Adress& adress_);
    void setRandomData() noexcept;
    int getDatabaseSize() const noexcept;
    Person* operator[](const int& whichPerson) const;
    void clearDatabase() noexcept;
};
