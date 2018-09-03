#include <../inc/Employee.hpp>.hpp>
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






