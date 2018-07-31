#include <iostream>
#include "Student.hpp"
#include "Employee.hpp"
#include "Database.hpp"
using namespace std;

int main()
{
    Database database;
    array<int, 11> pesel1 = { 9,6,0,4,0,1,0,2,4,9,5 };
    Student student("rafal", "nowak", pesel1, "man", "warszawa, 15 cicha", 123456);
    Person* person1 = &student;
   
    Employee employee("ula", "kowlaksa", pesel1, "woman", "kalisz, 4 grunwaldzka", 3500);
    Person* person2 = &employee;

    database.addToDatabase(person1);
    database.addToDatabase(person2);

    database.showDatabase();

    system("PAUSE");
    return 0;
}