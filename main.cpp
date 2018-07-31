#include <iostream>
#include "Student.hpp"
#include "Employee.hpp"
#include "Database.hpp"
using namespace std;

int main()
{
    Database database;
    array<int, 11> pesel1 = { 4,4,0,5,1,4,0,1,3,5,9};
    Student student("rafal", "nowak", pesel1, "man", "warszawa, 15 cicha", 123456);
    Person* person1 = &student;
   
    Employee employee("ula", "kowlaksa", pesel1, "woman", "kalisz, 4 grunwaldzka", 3500);
    Person* person2 = &employee;

    database.addToDatabase(person1);
    database.addToDatabase(person2);

    //database.showDatabase();
    //database.findLastName("Nowak");
    database.findPesel(pesel1);


    system("PAUSE");
    return 0;
}