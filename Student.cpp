#include "Student.hpp"

bool Student::correctIndex(const int& index_)
{
    double correctIndex = index_ / 100000;
    
    if (correctIndex < 1.0 || correctIndex > 9.9)
        return false;
    return true;   
}

Student::Student(const string & firstName_, const string & lastName_, const std::array<int, 11>& pesel_,
    const string & gender_, const string & adress_, const int& index_)
{
    this->setFirstName(firstName_);
    this->setLastName(lastName_);
    this->setPesel(pesel_);
    this->setGender(gender_);
    this->setAdress(adress_);
    this->setIndex(index_);
}

Student::~Student() {}

void Student::setIndex(const int& index_)
{
    try
    {
        this->index = index_;
        if (!correctIndex(index_))
            throw InvalidIndex();
    }
    catch (InvalidIndex& exception)
    {
        cout << exception.what() << endl;
        cout << exception.format() << endl;
        while (!correctIndex(this->index))
        {
            cout << "Set correct index: \a";
            cin >> this->index;
            if (cin.fail())
            {
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }
        }
    }
}

void Student::showPerson()
{
    cout << "Status: \tstudent";
    Person::showPerson();
    cout << "Index: \t\t" << this->index << endl;
}


