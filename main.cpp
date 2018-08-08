#include "Student.hpp"
#include "Employee.hpp"
#include "Database.hpp"
#include <iostream>
#include <vector>

int main()
{
    Database database;

    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);

    Person* jan = new Student("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 227401);

    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 3500);

    Person* michal = new Employee("michal", "szybki", "00302557202", "man", "poznan, 90 spokojna", 5500);

    Person* marcin = new Employee("marcin", "nowak", "91051962012", "man", "krakow, 90 spokojna", 3000);

    /// TEST:

    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.addToDatabase(michal);
    database.addToDatabase(marcin);

    //database.showDatabase();
    
    //for (auto x : database.findByLastName("Nowak")) x->showPerson();
    //for (auto x : database.findByPesel("91051962012")) x->showPerson();
    //for (auto x : database.findByAdress("Warszawa, 7 Cicha street")) x->showPerson();
    //for (auto x : database.findAllStudnents()) x->showPerson();
    //for (auto x : database.findAllEmployees()) x->showPerson();
    
    //database.sortByLastName();
    //database.showDatabase();

    //database.sortByPesel();
    //database.showDatabase();

    //database.sortBySalary();
    //database.showDatabase();

    //database.addToExternalFile("DATABASE.txt");
    //database.loadFromExternalFile("DATABASE.txt");
    //database.showDatabase();

    //database.removePerson("93011397011");
    //database.showDatabase();

    //database.changeEmployeeSalary("44051401359", 99);
    //database.showDatabase();

    //database.changeAdress("93011397014", "Gdansk, 8 finlandia");
    //database.showDatabase();

    //database.setRandomData();
    //database.showDatabase();
   
    database.clearDatabase();

    system("PAUSE");
    return 0;
}