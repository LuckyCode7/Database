#include <../inc/AdressValidator.hpp>
#include <gtest/gtest.h>

struct AdressValidatorTest : public ::testing::Test
{};

TEST_F(AdressValidatorTest, check_method_checkAdress_when_city_name_is_incorrect)
{
    Adress adress = Adress("Warszawa3", "Szybka", 8);
    ASSERT_FALSE(AdressValidator::checkAdress(adress));
}

TEST_F(AdressValidatorTest, check_method_checkAdress_when_city_name_is_correct)
{
    Adress adress = Adress("Warszawa", "Szybka", 8);
    ASSERT_TRUE(AdressValidator::checkAdress(adress));
}

TEST_F(AdressValidatorTest, check_method_checkAdress_when_street_name_is_incorrect)
{
    Adress adress = Adress("Warszawa", "Szybka1", 8);
    ASSERT_FALSE(AdressValidator::checkAdress(adress));
}

TEST_F(AdressValidatorTest, check_method_checkAdress_when_street_name_is_correct)
{
    Adress adress = Adress("Warszawa", "Szybka", 8);
    ASSERT_TRUE(AdressValidator::checkAdress(adress));
}

TEST_F(AdressValidatorTest, check_method_checkAdress_when_street_number_is_incorrect)
{
    Adress adress = Adress("Warszawa", "Szybka", 0);
    ASSERT_FALSE(AdressValidator::checkAdress(adress));
}

TEST_F(AdressValidatorTest, check_method_checkAdress_when_street_number_is_correct)
{
    Adress adress = Adress("Warszawa", "Szybka", 1);
    ASSERT_TRUE(AdressValidator::checkAdress(adress));
}






