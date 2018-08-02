#include "Student.hpp"
#include "Employee.hpp"
#include "Database.hpp"

int main()
{
    Database database;

    Student rafal("rafal", "nowak", "93011397014", "man", "warszawa, 15 cicha", 123456);
    Person* person1 = &rafal;

    Student jan("Jan", "tyski", "25040751910", "man", "warszawa, 7 cicha", 227401);
    Person* person3 = &jan;

    Employee ula("ula", "kowlaksa", "44051401359", "woman", "kalisz, 4 grunwaldzka", 3500);
    Person* person2 = &ula;

    Employee michal("michal", "maly", "00302557202", "man", "poznan, 90 spokojna", 5500);
    Person* person4 = &michal;

    Employee marcin("marcin", "duzy", "91051962012", "man", "krakow, 90 spokojna", 3000);
    Person* person5 = &marcin;

    database.addToDatabase(person1);
    database.addToDatabase(person2);
    database.addToDatabase(person3);
    database.addToDatabase(person4);
    database.addToDatabase(person5);

    database.showDatabase();

    database.findLastName("Nowak");
    database.findPesel("9301139701");

    database.sortByLastName();
    database.showDatabase();

    database.sortByPesel();
    database.showDatabase();

    database.sortBySalary();
    database.showDatabase();

    database.addToExternalFile();
    database.loadFromExternalFile();

    database.removePerson("93011397013");
    database.showDatabase();

    database.changeEmployeeSalary("44051401359", -7500);
    database.showDatabase();

    database.changeAdress("93011397014", "Gdansk, 8 finlandia");
    database.showDatabase();

    database.setRandomData();
    database.showDatabase();

    system("PAUSE");
    return 0;
}