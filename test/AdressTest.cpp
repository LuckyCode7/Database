#include <../inc/Adress.hpp>
#include <gtest/gtest.h>

struct AdressTest : public ::testing::Test
{
    Adress adress = Adress("Warszawa","Cicha", 3);
};

TEST_F(AdressTest, check_method_getCity)
{
    ASSERT_EQ(adress.getCity(), "Warszawa");
}

TEST_F(AdressTest, check_method_getStreet)
{
    ASSERT_EQ(adress.getStreet(), "Cicha");
}

TEST_F(AdressTest, check_method_getNumberOfStreet)
{
    ASSERT_EQ(adress.getNumberOfStreet(), 3);
}

TEST_F(AdressTest, check_method_setCity)
{
    //When
    adress.setCity("londyn");
    //Then
    ASSERT_EQ(adress.getCity(), "Londyn");
}

TEST_F(AdressTest, check_method_setStreet)
{
    //When
    adress.setStreet("szybka");
    //Then
    ASSERT_EQ(adress.getStreet(), "Szybka");
}

TEST_F(AdressTest, check_method_setNumberOfStreet)
{
    //When
    adress.setNumberOfStreet(17);
    //Then
    ASSERT_EQ(adress.getNumberOfStreet(), 17);
}

TEST_F(AdressTest, check_method_toString)
{
    ASSERT_EQ(adress.toString(), "Warszawa, 3 Cicha street");
}








