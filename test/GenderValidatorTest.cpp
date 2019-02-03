#include <../inc/GenderValidator.hpp>
#include <gtest/gtest.h>

struct GenderValidatorTest : public ::testing::Test
{};

TEST_F(GenderValidatorTest, check_method_checkGender_when_gender_is_man)
{
    ASSERT_TRUE(GenderValidator::checkGender("man"));
}

TEST_F(GenderValidatorTest, check_method_checkGender_when_gender_is_woman)
{
    ASSERT_TRUE(GenderValidator::checkGender("woman"));
}

TEST_F(GenderValidatorTest, check_method_checkGender_when_gender_is_incorrect)
{
    ASSERT_FALSE(GenderValidator::checkGender("manx"));
}








