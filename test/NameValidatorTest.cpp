#include <../inc/NameValidator.hpp>
#include <gtest/gtest.h>

struct NameValidatorTest : public ::testing::Test
{};

TEST_F(NameValidatorTest, check_method_checkName_when_name_is_too_short)
{
    ASSERT_FALSE(NameValidator::checkName("J"));
}

TEST_F(NameValidatorTest, check_method_checkName_when_name_length_is_proper)
{
    ASSERT_TRUE(NameValidator::checkName("Tom"));
}

TEST_F(NameValidatorTest, check_method_checkName_when_name_contains_numbers)
{
    ASSERT_FALSE(NameValidator::checkName("Tom2"));
}
