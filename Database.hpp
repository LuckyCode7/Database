#include "Person.hpp"

class Database
{
public:
    Database();
    ~Database();
    void addToDatabase(Person*);
    void showDatabase();
    void findLastName(const string&);
    void findPesel(const string&);
    void sortByLastName();
    void sortByPesel();
    void sortBySalary();
};
