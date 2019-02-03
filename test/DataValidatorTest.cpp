#include <../inc/DataValidator.hpp>
#include <gtest/gtest.h>

struct DataValidatorTest : public ::testing::Test
{};

TEST_F(DataValidatorTest, check_method_isDigit_when_there_is_no_numbers)
{
    ASSERT_TRUE(DataValidator::isDigit("Adress"));
}

TEST_F(DataValidatorTest, check_method_isDigit_when_there_are_numbers)
{
    ASSERT_FALSE(DataValidator::isDigit("Adress1"));
}

TEST_F(DataValidatorTest, check_method_isAlpha_when_there_is_no_letters)
{
    ASSERT_TRUE(DataValidator::isAlpha("1234"));
}

TEST_F(DataValidatorTest, check_method_isAlpha_when_there_are_some_letters)
{
    ASSERT_FALSE(DataValidator::isDigit("123k"));
}

TEST_F(DataValidatorTest, check_method_checkMinimumStringSize_when_string_size_is_ok)
{
    ASSERT_TRUE(DataValidator::checkMinimumStringSize("test", 3));

}
TEST_F(DataValidatorTest, check_method_checkMinimumStringSize_when_string_size_is_too_short)
{
    ASSERT_FALSE(DataValidator::checkMinimumStringSize("test", 5));
}






