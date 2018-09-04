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

TEST_F(StudentTest, check_method_getLastName)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN call getLastName method
    // THEN
    ASSERT_EQ(student.getLastName(), "Kowalski");
}

TEST_F(StudentTest, check_method_getFirstName)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN call getFirstName method
    // THEN
    ASSERT_EQ(student.getFirstName(), "Jan");
}

TEST_F(StudentTest, check_method_getPesel)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN call getPesel method
    // THEN
    ASSERT_EQ(student.getPesel(), "93011397011");
}

TEST_F(StudentTest, check_method_getGender)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN call getGender method
    // THEN
    ASSERT_EQ(student.getGender(), "man");
}

TEST_F(StudentTest, check_method_getAdress)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN call getAdress method
    // THEN
    ASSERT_EQ(student.getAdress(), "London, 7 Famous");
}

TEST_F(StudentTest, check_method_setPesel)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN
    student.setPesel("96122729307");
    // THEN
    ASSERT_EQ(student.getPesel(), "96122729307");
}

TEST_F(StudentTest, check_method_setGender)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN
    student.setGender("woman");
    // THEN
    ASSERT_EQ(student.getGender(), "woman");
}

TEST_F(StudentTest, check_method_setFirstName)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN
    student.setFirstName("Dawid");
    // THEN
    ASSERT_EQ(student.getFirstName(), "Dawid");
}

TEST_F(StudentTest, check_method_setLastName)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN
    student.setLastName("Wysocki");
    // THEN
    ASSERT_EQ(student.getLastName(), "Wysocki");
}

TEST_F(StudentTest, check_method_setAdress)
{
    // GIVEN
    Student student("Jan","Kowalksi","93011397011","man", "London, 7 Famous", 123456);
    // WHEN
    student.setAdress("Warsaw, 88 Szybka");
    // THEN
    ASSERT_EQ(student.getAdress(), "Warsaw, 88 Szybka");
}

