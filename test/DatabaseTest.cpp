#include <../inc/Student.hpp>
#include <../inc/Person.hpp>
#include <../inc/Employee.hpp>
#include <../inc/Database.hpp>
#include <gtest/gtest.h>

struct DatabaseTest : public ::testing::Test
{
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", Adress("warszawa", "cicha", 15), 123457);
    Person* jan = new Student("Jan", "tyski", "08260128313", "man", Adress("warszawa", "spokojna", 12), 227401);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", Adress("krakow", "cicha", 10), 3500);
    Person* michal = new Employee("michal", "szybki", "00302557202", "man", Adress("gdansk", "cicha", 9), 5500);
    Person* marcin = new Employee("marcin", "jeziorski", "91051962012", "man", Adress("lublin", "szybka", 1), 3000);
};

TEST_F(DatabaseTest, check_findByLastName_method)
{
    // GIVEN
    Database database;
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
    //WHEN
    database.addToDatabase(rafal);
    auto found = database.findByAdress(Adress("warszawa", "cicha", 15));
    // THEN
    ASSERT_EQ((*found.begin())->getFirstName(), "Rafal");
}

TEST_F(DatabaseTest, check_findAllStudents_method)
{
    // GIVEN
    Database database;
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
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.sortBySalary();
    // THEN
    ASSERT_EQ(database[2]->getLastName(),"Kowalska");
}

TEST_F(DatabaseTest, check_removePerson_method)
{
    // GIVEN
    Database database;
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
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.changeEmployeeSalary("44051401359", 7000);
    // THEN
    ASSERT_EQ(database[2]->getSalary(), 7000);
}

TEST_F(DatabaseTest, check_changeAdress_method)
{
    // GIVEN
    Database database;
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.changeAdress("93011397011", Adress("Gdansk", "Finlandia", 8));
    // THEN
    ASSERT_EQ(database[0]->getAdress(), Adress("Gdansk", "Finlandia", 8));
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
    //WHEN
    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.clearDatabase();
    // THEN
    ASSERT_EQ(database.getDatabaseSize(), 0);
}
