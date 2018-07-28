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

class InvalidFirstName : public std::invalid_argument
{
public:
    InvalidFirstName()
        : invalid_argument("Incorrect length or type of first name !")
    {}
};

class InvalidLastName : public std::invalid_argument
{
public:
    InvalidLastName()
        : invalid_argument("Incorrect length or type of last name !")
    {}
};

class InvalidAdress : public std::invalid_argument
{
public:
    InvalidAdress()
        : invalid_argument("Incorrect adress format !")
    {}
    const char* format() { return "Correct adress format: (city), (number) (name of the street)"; }
};

class InvalidIndex : public std::invalid_argument
{
public:
    InvalidIndex()
        : invalid_argument("Incorrect type of index !")
    {}
    const char* format() { return "Index must contain 6 numbers. First numern can not be 0"; }
};

class InvalidSalary : public std::invalid_argument
{
public:
    InvalidSalary()
        : invalid_argument("Salary can not be negative!")
    {}
};

