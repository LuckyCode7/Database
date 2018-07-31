#include <iostream>
#include "Student.hpp"
#include "Employee.hpp"
#include "Database.hpp"
using namespace std;

int main()
{
    Database database;
    array<int, 11> pesel1 = { 4,4,0,5,1,4,0,1,3,5,9 };
    array<int, 11> pesel2 = { 9,3,0,1,1,3,9,7,0,1,4 };
    array<int, 11> pesel3 = { 2,5,0,4,0,7,5,1,9,1,0 };
    array<int, 11> pesel4 = { 0,0,3,0,2,5,5,7,2,0,2 };
    array<int, 11> pesel5 = { 9,1,0,5,1,9,6,2,0,1,2 };

    Student student("rafal", "nowak", pesel2, "man", "warszawa, 15 cicha", 123456);
    Person* person1 = &student;

    Student student2("Jan", "tyski", pesel3, "man", "warszawa, 7 cicha", 227401);
    Person* person3 = &student2;
   
    Employee employee("ula", "kowlaksa", pesel1, "woman", "kalisz, 4 grunwaldzka", 3500);
    Person* person2 = &employee;

    Employee employee2("michal", "maly", pesel4, "man", "poznan, 90 spokojna", 5500);
    Person* person4 = &employee2;

    Employee employee3("marcin", "duzy", pesel5, "man", "krakow, 90 spokojna", 3000);
    Person* person5 = &employee3;

    database.addToDatabase(person1);
    database.addToDatabase(person2);
    database.addToDatabase(person3);
    database.addToDatabase(person4);
    database.addToDatabase(person5);

    //database.showDatabase();

    //database.findLastName("Nowak");
    //database.findPesel(pesel1);

    //database.sortByLastName();
   // database.showDatabase();

   // database.sortByPesel();
    //database.showDatabase();

    database.sortBySalary();
    database.showDatabase();

    system("PAUSE");
    return 0;
}