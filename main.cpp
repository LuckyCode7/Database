#include <iostream>
#include "Student.hpp"
#include "Employee.hpp"
#include "Database.hpp"
using namespace std;

int main()
{
    Database database;
   
    Student student("rafal", "nowak", "93011397014", "man", "warszawa, 15 cicha", 123456);
    Person* person1 = &student;

    Student student2("Jan", "tyski", "25040751910", "man", "warszawa, 7 cicha", 227401);
    Person* person3 = &student2;
   
    Employee employee("ula", "kowlaksa", "44051401359", "woman", "kalisz, 4 grunwaldzka", 3500);
    Person* person2 = &employee;

    Employee employee2("michal", "maly", "00302557202", "man", "poznan, 90 spokojna", 5500);
    Person* person4 = &employee2;

    Employee employee3("marcin", "duzy", "91051962012", "man", "krakow, 90 spokojna", 3000);
    Person* person5 = &employee3;

    database.addToDatabase(person1);
    database.addToDatabase(person2);
    database.addToDatabase(person3);
    database.addToDatabase(person4);
    database.addToDatabase(person5);

    //database.showDatabase();

    //database.findLastName("Nowak");
    //database.findPesel("9301139701");

    //database.sortByLastName();
    //database.showDatabase();

     //database.sortByPesel();
     //database.showDatabase();

    database.sortBySalary();
    database.showDatabase();

    system("PAUSE");
    return 0;
}