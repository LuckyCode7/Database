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
