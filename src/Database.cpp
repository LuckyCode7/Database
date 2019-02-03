#include <../inc/Database.hpp>
#include <../inc/Student.hpp>
#include <../inc/Employee.hpp>
#include <../inc/Exceptions.hpp>
#include <../inc/RandomData.hpp>
#include <iostream>
#include <algorithm>
#include <ctime>
#include <fstream>

void Database::checkPeronalData(Person* person) const
{
    person->setFirstName(person->getFirstName());
    person->setLastName(person->getLastName());
    person->setGender(person->getGender());
    person->setAdress(person->getAdress());
    if (person->getSalary() == 0)
        person->setIndex(person->getIndex());
    else
        person->setSalary(person->getSalary());
}

bool Database::addToDatabase(Person* person) noexcept
{
    checkPeronalData(person);
    if (getIterator(person->getPesel()) == data.end())
    {
        data.emplace_back(person);
        return true;
    }
    else return false;
}

void Database::showDatabase() const noexcept
{
    for (const auto& person : data)
        person->toString();
}

std::set<Person*> Database::find(std::function<bool(Person*)> predicate) const noexcept
{
    std::set<Person*> People;
    for (auto iter = data.begin(); iter != data.end(); ++iter)
    {
        auto found = std::find_if(iter, data.end(), predicate);
        if (found != data.end())
            People.insert(*found);
    }
    return People;
}

std::vector<Person*>::iterator Database::getIterator(const std::string& pesel_) noexcept
{
    return std::find_if(data.begin(), data.end(), [=](const Person* item)
    {
        return item->getPesel() == pesel_;
    });
}

std::set<Person*> Database::findByLastName(const std::string& lastName_) const noexcept
{
    std::string temp =lastName_;
    temp[0] = toupper(temp[0]);
    return find([=](const Person* item)
    {
        return item->getLastName() == temp;
    });
}

std::set<Person*> Database::findByPesel(const std::string& pesel_) const noexcept
{
    return find([=](const Person* item)
    {
        return item->getPesel() == pesel_;
    });
}

std::set<Person*> Database::findByAdress(const Adress& adress_) const noexcept
{
    return find([=](const Person* item)
    {
        return item->getAdress() == adress_;
    });
}

std::set<Person*> Database::findAllStudnents() const noexcept
{  
    return find([](const Person* item)
    {
        return item->getIndex() != 0;
    });
}

std::set<Person*> Database::findAllEmployees() const noexcept
{
    return find([](const Person* item)
    {
        return item->getIndex() == 0;
    });
}

void Database::sortByLastName() noexcept
{
    std::sort(data.begin(), data.end(), [](const Person* one, const Person* two)
    {
        return one->getLastName() < two->getLastName();
    });
}

void Database::sortByPesel() noexcept
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two)
    {
        return one->getPesel() < two->getPesel();
    });
}

void Database::sortBySalary() noexcept
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two)
    {
        return one->getSalary() < two->getSalary();
    });
}

void Database::addToExternalFile(const std::string& fileName) const noexcept
{
    std::ofstream outFile(fileName);
    for (auto x = data.begin(); x != data.end(); x++)
    {
        outFile << (*x)->getFirstName() << "|"
                << (*x)->getLastName() << "|"
                << (*x)->getPesel() << "|"
                << (*x)->getGender() << "|"
                << (*x)->getAdress().toString() << "|"
                << (*x)->getSalary() << "|"
                << (*x)->getIndex() << "|" << endl;
    }
    outFile.close();
}

void Database::removePerson(const std::string& pesel_) noexcept
{
    if (getIterator(pesel_) != data.end())
    {
        data.erase(getIterator(pesel_));
    }
}

void Database::changeEmployeeSalary(const std::string& pesel_, const int& salary_)
{
    if (getIterator(pesel_) != data.end())
    {
        (*getIterator(pesel_))->setSalary(salary_);
    }
}

void Database::changeAdress(const std::string & pesel_, const Adress & adress_)
{
    if (getIterator(pesel_) != data.end())
    {
        (*getIterator(pesel_))->setAdress(adress_);
    }
}

void Database::setRandomData() noexcept
{
    using namespace RandomData;
    clearDatabase();
    srand(time(0));
    std::vector<int> i(randomUniqueNumber().begin(), randomUniqueNumber().end());
    for(unsigned int j = 0; j<6; j++)
    {
        if(j < 3)
            addToDatabase(new Student(randomFirstName[rand() % 10], randomLastName[rand() % 10],
                    randomPesel[i[j]], randomGender[rand() % 2],
                    randomAdress[rand() % 10], randomIndex[rand() % 10]));
        else
            addToDatabase(new Employee(randomFirstName[rand() % 10], randomLastName[rand() % 10],
                    randomPesel[i[j]], randomGender[rand() % 2],
                    randomAdress[rand() % 10], randomSalary[rand() % 10]));
    }
}

Person* Database::operator[](const int& whichPerson) const
{
    return data[whichPerson];
}

int Database::getDatabaseSize() const noexcept
{
    return data.size();
}

void Database::clearDatabase() noexcept
{
    for (const auto& x : data) delete x;
    data.clear();
}



