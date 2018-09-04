#include <../inc/Database.hpp>
#include <../inc/Student.hpp>
#include <../inc/Employee.hpp>
#include <../inc/Exceptions.hpp>
#include <../inc/randomData.hpp>
#include <iostream>
#include <array>
#include <set>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <sstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

Database::Database() {}

Database::~Database() {}

void Database::checkPeronalData(Person* person)
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

void Database::randomUniqueNumber() const
{
    srand(time(0));
    while (randomData::number.size() != 6)
    {
        int temporaryNumber = rand() % 10;
        randomData::number.insert(temporaryNumber);
    }
}

bool Database::addToDatabase(Person* person)
{
    checkPeronalData(person);
    if (getIterator(person->getAdress()) == data.end())
    {
        data.emplace_back(person);
        return true;
    }
    return false;
}

void Database::showDatabase() const
{
    for (auto x : data)
        x->showPerson();
}

std::set<Person*> Database::find(std::function<bool(Person*)> what) const
{
    std::set<Person*> People;
    for (auto iter = data.begin(); iter != data.end(); ++iter)
    {
        auto found = std::find_if(iter, data.end(), what);
        if (found != data.end())
            People.insert(*found);
    }
    return People;
}

std::vector<Person*>::iterator Database::getIterator(const string& pesel_)
{
    return std::find_if(data.begin(), data.end(), [=](const Person* item) 
    {
        return item->getPesel() == pesel_; 
    });
}

std::set<Person*> Database::findByLastName(const string& lastName_) const
{
    string temp = lastName_;
    temp[0] = toupper(temp[0]);
    return find([=](const Person* item)
    {
        return item->getLastName() == temp; 
    });
}

std::set<Person*> Database::findByPesel(const string& pesel_) const
{
    return find([=](const Person* item)
    {
        return item->getPesel() == pesel_; 
    });
}

std::set<Person*> Database::findByAdress(const string& adress_) const
{
    return find([=](const Person* item)
    {
        return item->getAdress() == adress_; 
    });
}

std::set<Person*> Database::findAllStudnents() const
{
    {
        return find([](const Person* item)->bool
        {
            return item->getIndex() != 0;
        });
    }
}

std::set<Person*> Database::findAllEmployees() const
{
    {
        return find([](const Person* item)->bool
        {
            return item->getIndex() == 0;
        });
    }
}

void Database::sortByLastName()
{
    std::sort(data.begin(), data.end(), [](const Person* one, const Person* two) 
    {
        return one->getLastName() < two->getLastName(); 
    });
}

void Database::sortByPesel()
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two) 
    {
        return one->getPesel() < two->getPesel();
    });
}

void Database::sortBySalary()
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two) 
    {
        return one->getSalary() < two->getSalary(); 
    });
}

void Database::addToExternalFile(const string& fileName) const
{
    std::ofstream outFile(fileName);
    for (auto x = data.begin(); x != data.end(); x++)
    {
        outFile << (*x)->getFirstName() << "|"
            << (*x)->getLastName() << "|"
            << (*x)->getPesel() << "|"
            << (*x)->getGender() << "|"
            << (*x)->getAdress() << "|"
            << (*x)->getSalary() << "|"
            << (*x)->getIndex() << "|" << endl;
    }
    outFile.close();
}

void Database::loadFromExternalFile(const string& fileName)
{
    data.clear();
    string longLine;
    string shortLine;
    std::vector<string> textFromFile;
    std::ifstream inFile(fileName);
    try
    {
        if (inFile.is_open())
        {
            while (getline(inFile, longLine))
            {
                std::stringstream ss(longLine);
                while (getline(ss, shortLine, '|'))
                {
                    textFromFile.emplace_back(shortLine);
                }
                if (std::stoi(textFromFile[5]) == 0)
                {
                    Person* student = new Student(textFromFile[0], textFromFile[1], textFromFile[2], textFromFile[3],
                        textFromFile[4], std::stoi(textFromFile[6]));
                    addToDatabase(student);
                }
                else
                {
                    Person* employee = new Employee(textFromFile[0], textFromFile[1], textFromFile[2], textFromFile[3],
                        textFromFile[4], std::stoi(textFromFile[5]));
                    addToDatabase(employee);
                }
                textFromFile.clear();
            }
        }
        else throw InvalidFile();
    }
    catch (InvalidFile& exception)
    {
        cout << exception.what() << endl;
    }
    catch (std::exception& exception)
    {
        cout << exception.what() << endl;
    }
}

void Database::removePerson(const string& pesel_)
{
    if (getIterator(pesel_) != data.end())
    {
        data.erase(getIterator(pesel_));
    }
}

void Database::changeEmployeeSalary(const string& pesel_, const int& salary_)
{
    if (getIterator(pesel_) != data.end())
    {
        (*getIterator(pesel_))->setSalary(salary_);
    }
}

void Database::changeAdress(const string & pesel_, const string & adress_)
{
    if (getIterator(pesel_) != data.end())
    {
        (*getIterator(pesel_))->setAdress(adress_);
    }
}

void Database::setRandomData()
{
    clearDatabase();
    srand(time(0));
    using namespace randomData;
    randomUniqueNumber();
    std::vector<int> i(number.begin(), number.end());

    Person* s1  = new Student(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[0]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomIndex[rand() % 10]);
    Person* s2 = new Student(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[1]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomIndex[rand() % 10]);
    Person* s3 = new Student(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[2]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomIndex[rand() % 10]);
    Person* e1 = new Employee(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[3]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomSalary[rand() % 10]);
    Person* e2 = new Employee(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[4]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomSalary[rand() % 10]);
    Person* e3 = new Employee(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[5]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomSalary[rand() % 10]);

    addToDatabase(s1);
    addToDatabase(s2);
    addToDatabase(s3);
    addToDatabase(e1);
    addToDatabase(e2);
    addToDatabase(e3);
}

void Database::clearDatabase()
{
    for (auto x : data)
        delete x;
    data.clear();
}



