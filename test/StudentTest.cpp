#include <../inc/Student.hpp>
#include <gtest/gtest.h>

struct StudentTest : public ::testing::Test
{
    Student student = Student("Jan","Kowalski","93011397011","man", Adress("London","Famous",7), 123456);
};

TEST_F(StudentTest, check_method_getFirstName)
{
    ASSERT_EQ(student.getFirstName(), "Jan");
}

TEST_F(StudentTest, check_method_getLastName)
{
    ASSERT_EQ(student.getLastName(), "Kowalski");
}

TEST_F(StudentTest, check_method_getPesel)
{
    ASSERT_EQ(student.getPesel(), "93011397011");
}

TEST_F(StudentTest, check_method_getGender)
{
    ASSERT_EQ(student.getGender(), "man");
}

TEST_F(StudentTest, check_method_getAdress)
{
    ASSERT_EQ(student.getAdress(), Adress("London","Famous",7));
}

TEST_F(StudentTest, check_method_getIndex)
{
    ASSERT_EQ(student.getIndex(), 123456);
}

TEST_F(StudentTest, check_method_setFirstName)
{
    student.setFirstName("zbyszek");
    ASSERT_EQ(student.getFirstName(), "Zbyszek");
}

TEST_F(StudentTest, check_method_setLastName)
{
    student.setLastName("nowak");
    ASSERT_EQ(student.getLastName(), "Nowak");
}

TEST_F(StudentTest, check_method_setPesel)
{
    student.setPesel("96122729307");
    ASSERT_EQ(student.getPesel(), "96122729307");
}

TEST_F(StudentTest, check_method_setGender)
{
    student.setGender("woman");
    ASSERT_EQ(student.getGender(), "woman");
}

TEST_F(StudentTest, check_method_setAdress)
{
    student.setAdress(Adress("Warszawa", "Cicha", 20));
    ASSERT_EQ(student.getAdress(), Adress("Warszawa", "Cicha", 20));
}

TEST_F(StudentTest, check_method_setIndex)
{
    student.setIndex(123457);
    ASSERT_EQ(student.getIndex(), 123457);
}

TEST_F(StudentTest, check_method_getSalary)
{
    ASSERT_EQ(student.getSalary(), 0);
}
