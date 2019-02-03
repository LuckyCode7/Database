#include <../inc/Employee.hpp>
#include <gtest/gtest.h>

struct EmployeeTest : public ::testing::Test
{
    Employee employee = Employee("Jan","Kowalski","93011397011","man", Adress("London","Famous",7), 5000);
};

TEST_F(EmployeeTest, check_method_getFirstName)
{
    ASSERT_EQ(employee.getFirstName(), "Jan");
}

TEST_F(EmployeeTest, check_method_getLastName)
{
    ASSERT_EQ(employee.getLastName(), "Kowalski");
}

TEST_F(EmployeeTest, check_method_getPesel)
{
    ASSERT_EQ(employee.getPesel(), "93011397011");
}

TEST_F(EmployeeTest, check_method_getGender)
{
    ASSERT_EQ(employee.getGender(), "man");
}

TEST_F(EmployeeTest, check_method_getAdress)
{
    ASSERT_EQ(employee.getAdress(), Adress("London","Famous",7));
}

TEST_F(EmployeeTest, check_method_getIndex)
{
    ASSERT_EQ(employee.getIndex(), 0);
}

TEST_F(EmployeeTest, check_method_setFirstName)
{
    employee.setFirstName("zbyszek");
    ASSERT_EQ(employee.getFirstName(), "Zbyszek");
}

TEST_F(EmployeeTest, check_method_setLastName)
{
    employee.setLastName("nowak");
    ASSERT_EQ(employee.getLastName(), "Nowak");
}

TEST_F(EmployeeTest, check_method_setPesel)
{
    employee.setPesel("96122729307");
    ASSERT_EQ(employee.getPesel(), "96122729307");
}

TEST_F(EmployeeTest, check_method_setGender)
{
    employee.setGender("woman");
    ASSERT_EQ(employee.getGender(), "woman");
}

TEST_F(EmployeeTest, check_method_setAdress)
{
    employee.setAdress(Adress("Warszawa", "Cicha", 20));
    ASSERT_EQ(employee.getAdress(), Adress("Warszawa", "Cicha", 20));
}

TEST_F(EmployeeTest, check_method_setSalary)
{
    employee.setSalary(6500);
    ASSERT_EQ(employee.getSalary(), 6500);
}

TEST_F(EmployeeTest, check_method_getSalary)
{
    ASSERT_EQ(employee.getSalary(), 5000);
}





