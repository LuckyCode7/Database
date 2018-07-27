#pragma once
#include <stdexcept>

class InvalidPesel : public std::invalid_argument
{
public:
    InvalidPesel()
        : invalid_argument("Invalid PESEL !")
    {}
};

class InvalidGender : public std::invalid_argument
{
public:
    InvalidGender()
        : invalid_argument("Invalid gender !")
    {}
};

