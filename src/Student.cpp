#include <../inc/Student.hpp>
#include <../inc/Exceptions.hpp>
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::endl;
using std::string;

bool Student::correctIndex(const int index_) const noexcept
{
    double correctIndex = index_ / 100000;    
    if (correctIndex < 1.0 || correctIndex > 9.9)
        return false;
    return true;   
}

Student::Student(const string & firstName_, const string & lastName_, const string& pesel_,
    const string & gender_, const Adress & adress_, const int index_)
    :Person(firstName_,lastName_,pesel_,gender_,adress_)
    ,index(index_)
{}

Student::~Student() {}

void Student::setIndex(const int index_)
{
    try
    {
        index = index_;
        if (!correctIndex(index_))
            throw InvalidIndex(getFirstName() + " " + getLastName());
    }
    catch (InvalidIndex& exception)
    {
        cout << exception.what() << endl;
        exception.message();
        cout << exception.format() << endl;
        while (!correctIndex(index))
        {
            cout << "Set correct index: \a";
            cin >> index;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
    }
}

void Student::toString() const noexcept
{
    cout << "Status: \tstudent";
    Person::toString();
    cout << "Index: \t\t" << index << endl << endl;
}

int Student::getSalary() const noexcept
{
    return 0; 
}

int Student::getIndex() const noexcept
{
    return index;
}

void Student::setSalary(const int)
{}


