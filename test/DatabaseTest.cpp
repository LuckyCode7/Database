#include <../inc/Person.hpp>
#include <../inc/Student.hpp>
#include <../inc/Employee.hpp>
#include <../inc/Database.hpp>
#include <gtest/gtest.h>

struct DatabaseTest : public ::testing::Test
{};

TEST_F(DatabaseTest, check_database_methods)
{
    // GIVEN
    Database database;
    Person* rafal = new Student("rafal", "nowak", "93011397011", "man", "warszawa, 15 cicha", 123457);
    Person* jan = new Student("Jan", "tyski", "08260128313", "man", "warszawa, 7 cicha", 227401);
    Person* ula = new Employee("ula", "kowalska", "44051401359", "woman", "kalisz, 4 grunwaldzka", 3500);
    Person* michal = new Employee("michal", "szybki", "00302557202", "man", "poznan, 90 spokojna", 5500);
    Person* marcin = new Employee("marcin", "jeziorski", "91051962012", "man", "krakow, 90 spokojna", 3000);

    database.addToDatabase(rafal);
    database.addToDatabase(jan);
    database.addToDatabase(ula);
    database.addToDatabase(michal);
    database.addToDatabase(marcin);

    //WHEN
    auto found1 = database.findByLastName("Nowak");
    // THEN
    ASSERT_EQ((*found1.begin())->getFirstName(), "Rafal");

    //WHEN
    auto found2 = database.findByPesel("08260128313");
    // THEN
    ASSERT_EQ((*found2.begin())->getFirstName(), "Jan");

    //WHEN
    auto found3 = database.findByAdress("Kalisz, 4 Grunwaldzka street");
    // THEN
    ASSERT_EQ((*found3.begin())->getFirstName(), "Ula");
}






