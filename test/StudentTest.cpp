#include <../inc/Student.hpp>
#include <gtest/gtest.h>

struct StudentTest : public ::testing::Test
{};

TEST_F(StudentTest, check_method_getIndex)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN call getIndex
    // THEN
    ASSERT_EQ(student.getIndex(), 123456);
}

TEST_F(StudentTest, check_method_getSalary)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN call getSalary
    // THEN
    ASSERT_EQ(student.getSalary(), 0);
}

TEST_F(StudentTest, check_method_setIndex)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN
    student.setIndex(222222);
    // THEN
    ASSERT_EQ(student.getIndex(), 222222);
}

TEST_F(StudentTest, check_method_setSalary)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN
    student.setSalary(5000);
    // THEN
    ASSERT_EQ(student.getSalary(), 0);
}




