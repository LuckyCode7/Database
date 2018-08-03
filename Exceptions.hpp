#pragma once
#include <stdexcept>
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

class InvalidPesel : public std::invalid_argument
{
    string person;
public:
    InvalidPesel(const string& person_)
        : invalid_argument("Invalid PESEL !")
        ,person(person)
    {}
    void message() { cout << "Person " << person << endl; }
};

class InvalidGender : public std::invalid_argument
{
    string person;
public:
    InvalidGender(const string& person_)
        : invalid_argument("Invalid gender !")
        ,person(person_)
    {}
    void message() { cout << "Person " << person << endl; }
};

class InvalidFirstName : public std::invalid_argument
{
    string person;
public:
    InvalidFirstName(const string& person_)
        : invalid_argument("Incorrect length or type of first name !")
        ,person(person_)
    {}
    void message() { cout << "Current name: " << person << endl; }
};

class InvalidLastName : public std::invalid_argument
{
    string person;
public:
    InvalidLastName(const string& person_)
        : invalid_argument("Incorrect length or type of last name !")
        ,person(person_)
    {}
    void message() { cout << "Current name: " << person << endl; }
};

class InvalidAdress : public std::invalid_argument
{
    string person;
public:
    InvalidAdress(const string& person_)
        : invalid_argument("Incorrect adress format !")
        ,person(person_)
    {}
    const char* format() { return "Correct adress format: (city), (number) (name of the street)"; }
    void message() { cout << "Set correct: " << person << " adress" << endl; }
};

class InvalidIndex : public std::invalid_argument
{
    string person;
public:
    InvalidIndex(const string& person_)
        : invalid_argument("Incorrect type of index !")
        ,person(person_)
    {}
    const char* format() { return "Index must contain 6 numbers. First numern can not be 0"; }
    void message() { cout << "Person " << person << endl; }
};

class InvalidSalary : public std::invalid_argument
{
    string person;
public:
    InvalidSalary(const string& person_)
        : invalid_argument("Salary can not be negative !")
        ,person(person_)
    {}
    void message() { cout << "Person " << person << endl; }
};

class InvalidFile : public std::invalid_argument
{
public:
    InvalidFile()
        : invalid_argument("Can not open the file !")
    {}
};

