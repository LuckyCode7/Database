#include "Database.hpp"

std::vector<Person*> data;

Database::Database(){}

Database::~Database(){}

void Database::addToDatabase(Person* person)
{
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
        cout << "Result: found " << lastNamecounter << " people" << endl;
}

void Database::findPesel(const std::array<int, 11>& pesel_)
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


