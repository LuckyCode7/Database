#include <../inc/Employee.hpp>
#include <gtest/gtest.h>

struct EmployeeTest : public ::testing::Test
{};

TEST_F(EmployeeTest, check_method_getSalary)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN call getSalary
    // THEN
    ASSERT_EQ(employee.getSalary(), 5000);
}

TEST_F(EmployeeTest, check_method_getIndex)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN call getIndex
    // THEN
    ASSERT_EQ(employee.getIndex(), 0);
}

TEST_F(EmployeeTest, check_method_setSalary)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN
    employee.setSalary(8000);
    // THEN
    ASSERT_EQ(employee.getSalary(), 8000);
}

TEST_F(EmployeeTest, check_method_setIndex)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN
    employee.setIndex(123456);
    // THEN
    ASSERT_EQ(employee.getIndex(), 0);
}

TEST_F(EmployeeTest, check_method_getLastName)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN call getLastName method
    // THEN
    ASSERT_EQ(employee.getLastName(), "Kowalksi");
}

TEST_F(EmployeeTest, check_method_getFirstName)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN call getFirstName method
    // THEN
    ASSERT_EQ(employee.getFirstName(), "Jan");
}

TEST_F(EmployeeTest, check_method_getPesel)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN call getPesel method
    // THEN
    ASSERT_EQ(employee.getPesel(), "93011397011");
}

TEST_F(EmployeeTest, check_method_getGender)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN call getGender method
    // THEN
    ASSERT_EQ(employee.getGender(), "man");
}

TEST_F(EmployeeTest, check_method_getAdress)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN call getAdress method
    // THEN
    ASSERT_EQ(employee.getAdress(), "London, 7 Famous");
}

TEST_F(EmployeeTest, check_method_setPesel)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN
    employee.setPesel("96122729307");
    // THEN
    ASSERT_EQ(employee.getPesel(), "96122729307");
}

TEST_F(EmployeeTest, check_method_setGender)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN
    employee.setGender("woman");
    // THEN
    ASSERT_EQ(employee.getGender(), "woman");
}

TEST_F(EmployeeTest, check_method_setFirstName)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN
    employee.setFirstName("Dawid");
    // THEN
    ASSERT_EQ(employee.getFirstName(), "Dawid");
}

TEST_F(EmployeeTest, check_method_setLastName)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN
    employee.setLastName("Wysocki");
    // THEN
    ASSERT_EQ(employee.getLastName(), "Wysocki");
}

TEST_F(EmployeeTest, check_method_setAdress)
{
    // GIVEN
    Employee employee("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 5000);
    // WHEN
    employee.setAdress("Warsaw, 88 Szybka");
    // THEN
    ASSERT_EQ(employee.getAdress(), "Warsaw, 88 Szybka street");
}





