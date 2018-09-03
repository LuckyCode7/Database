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




