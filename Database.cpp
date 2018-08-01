#include "Database.hpp"

std::vector<Person*> data;

Database::Database() {}

Database::~Database() {}

void Database::addToDatabase(Person* person)
{
    bool acces = true;
    for (auto x : data)
    {
        if (x->getPesel() == person->getPesel())
        {
            cout << "Pesel of " << person->getFirstName() << " " << person->getLastName() << " already exists !" << endl;
            acces = false;
            break;
        }
        else
            acces = true;
    }
    if (acces == true)
        data.push_back(person);
}

void Database::showDatabase()
{
    for (auto x : data)
        x->showPerson();
}

void Database::findLastName(const string& lastName_)
{
    int lastNamecounter = 0;
    for (auto x : data)
    {
        if (x->getLastName() == lastName_)
        {
            x->showPerson();
            lastNamecounter++;
        }
    }
    if (lastNamecounter == 0)
        cout << "There are no people with lastname: " << lastName_ << " in the database" << endl;
    else
        if (lastNamecounter > 1)
            cout << "Result: found " << lastNamecounter << " people" << endl;
        else
            cout << "Result: found " << lastNamecounter << " person" << endl;
}

void Database::findPesel(const string& pesel_)
{
    int peselCounter = 0;
    for (auto x : data)
    {
        if (x->getPesel() == pesel_)
        {
            x->showPerson();
            peselCounter++;
        }
    }
    if (peselCounter == 0)
        cout << "There are no people with the given pesel" << endl;
    else
        cout << "Result: found " << peselCounter << " people" << endl;
}

void Database::sortByLastName()
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two) {return one->getLastName() < two->getLastName(); });
    cout << "Status: sorting completed" << endl;
}

void Database::sortByPesel()
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two) {return one->getPesel() < two->getPesel(); });
    cout << "Status: sorting completed" << endl;
}

void Database::sortBySalary()
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two) {return one->getSalary() < two->getSalary(); });
    cout << "Status: sorting completed" << endl;
}


