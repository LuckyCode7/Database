#include <../inc/PeselValidator.hpp>
#include <gtest/gtest.h>

struct PeselValidatorTest : public ::testing::Test
{};

TEST_F(PeselValidatorTest, check_method_checkPesel_when_pesel_size_is_incorrect)
{
    ASSERT_FALSE(PeselValidator::checkPesel("930113970111"));
}

TEST_F(PeselValidatorTest, check_method_checkPesel_when_pesel_contains_letters)
{
    ASSERT_FALSE(PeselValidator::checkPesel("9301139701j"));
}

TEST_F(PeselValidatorTest, check_method_checkPesel_when_pesel_is_proper)
{
    ASSERT_TRUE(PeselValidator::checkPesel("08260128313"));
}


