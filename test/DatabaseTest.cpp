#include <../inc/Person.hpp>
#include <../inc/Student.hpp>
#include <../inc/Employee.hpp>
#include <../inc/Database.hpp>
#include <gtest/gtest.h>

struct DatabaseTest : public ::testing::Test
{};

TEST_F(DatabaseTest, check_findByLastName_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);
    //WHEN
    database.addToDatabase(rafal);
    auto found = database.findByLastName("Nowak");
    // THEN
    ASSERT_EQ((*found.begin())->getFirstName(), "Rafal");
}


TEST_F(DatabaseTest, check_findByPesel_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);
    //WHEN
    database.addToDatabase(rafal);
    auto found = database.findByPesel("93011397011");
    // THEN
    ASSERT_EQ((*found.begin())->getFirstName(), "Rafal");
}

TEST_F(DatabaseTest, check_findByAdress_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);
    //WHEN
    database.addToDatabase(rafal);
    auto found = database.findByAdress("Warszawa, 15 Cicha street");
    // THEN
    ASSERT_EQ((*found.begin())->getFirstName(), "Rafal");
}

TEST_F(DatabaseTest, check_findAllStudents_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);
    Person* jan = new Student("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 227401);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 3500);
    Person* michal = new Employee("michal", "szybki", "00302557202", "man", "poznan, 90 spokojna", 5500);
    Person* marcin = new Employee("marcin", "jeziorski", "91051962012", "man", "krakow, 90 spokojna", 3000);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.addToDatabase(michal);
    database.addToDatabase(marcin);
    auto foundStudent = database.findAllStudnents();
    // THEN
    ASSERT_EQ(foundStudent.size(), 2);
}

TEST_F(DatabaseTest, check_findAllEmployees_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);
    Person* jan = new Student("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 227401);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 3500);
    Person* michal = new Employee("michal", "szybki", "00302557202", "man", "poznan, 90 spokojna", 5500);
    Person* marcin = new Employee("marcin", "jeziorski", "91051962012", "man", "krakow, 90 spokojna", 3000);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.addToDatabase(michal);
    database.addToDatabase(marcin);
    auto foundEmployee = database.findAllEmployees();
    // THEN
    ASSERT_EQ(foundEmployee.size(), 3);
}

TEST_F(DatabaseTest, check_sortByLastName_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);
    Person* jan = new Student("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 227401);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 3500);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.sortByLastName();
    // THEN
    ASSERT_EQ(database[0]->getLastName(),"Kowalska");
}

TEST_F(DatabaseTest, check_sortByPesel_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);
    Person* jan = new Student("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 227401);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 3500);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.sortByPesel();
    // THEN
    ASSERT_EQ(database[0]->getLastName(),"Tyski");
}

TEST_F(DatabaseTest, check_sortBySalary_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Employee("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 5000);
    Person* jan = new Employee("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 3000);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 15000);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.sortBySalary();
    // THEN
    ASSERT_EQ(database[0]->getLastName(),"Tyski");
}

TEST_F(DatabaseTest, check_externalFile_methods)
{
    // GIVEN
    Database database;
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);
    Person* jan = new Student("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 227401);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 3500);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.addToExternalFile("../save/DATABASE.txt");
    database.loadFromExternalFile("../save/DATABASE.txt");
    // THEN
    ASSERT_EQ(database.getDatabaseSize(), 3);
}

TEST_F(DatabaseTest, check_removePerson_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Employee("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 5000);
    Person* jan = new Employee("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 3000);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 15000);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.removePerson("93011397011");
    // THEN
    ASSERT_EQ(database.getDatabaseSize(), 2);
}

TEST_F(DatabaseTest, check_changeEmployeeSalary_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Employee("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 5000);
    Person* jan = new Employee("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 3000);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 15000);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.changeEmployeeSalary("93011397011", 7000);
    // THEN
    ASSERT_EQ(database[0]->getSalary(), 7000);
}

TEST_F(DatabaseTest, check_changeAdress_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Employee("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 5000);
    Person* jan = new Employee("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 3000);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 15000);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.changeAdress("93011397011", "Gdansk, 8 Finlandia");
    // THEN
    ASSERT_EQ(database[0]->getAdress(), "Gdansk, 8 Finlandia street");
}

TEST_F(DatabaseTest, check_setRandomData_method)
{
    // GIVEN
    Database database;
    //WHEN
    database.setRandomData();
    // THEN
    ASSERT_EQ(database.getDatabaseSize(), 6);
}

TEST_F(DatabaseTest, check_clearDatabase_method)
{
    // GIVEN
    Database database;
    Person* rafal = new Employee("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 5000);
    Person* jan = new Employee("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 3000);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 15000);
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.clearDatabase();
    // THEN
    ASSERT_EQ(database.getDatabaseSize(), 0);
}
