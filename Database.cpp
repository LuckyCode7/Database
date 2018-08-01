#include "Database.hpp"

std::vector<Person*> data;

Database::Database() {}

Database::~Database() {}

void Database::addToDatabase(Person* person) const
{
    bool acces = true;
    for (auto x : data)
    {
        if (x->getPesel() == person->getPesel())
        {
            cout << "Pesel of " << person->getFirstName() << " " << person->getLastName() << " already exists !" << endl;
            acces = false;
            break;
        }
        else
            acces = true;
    }
    if (acces == true)
        data.push_back(person);
}

void Database::showDatabase() const
{
    for (auto x : data)
        x->showPerson();
}

void Database::findLastName(const string& lastName_) const
{
    int lastNamecounter = 0;
    for (auto x : data)
    {
        if (x->getLastName() == lastName_)
        {
            x->showPerson();
            lastNamecounter++;
        }
    }
    if (lastNamecounter == 0)
        cout << "There are no people with lastname: " << lastName_ << " in the database" << endl;
    else
        if (lastNamecounter > 1)
            cout << "Result: found " << lastNamecounter << " people" << endl;
        else
            cout << "Result: found " << lastNamecounter << " person" << endl;
}

void Database::findPesel(const string& pesel_) const
{
    int peselCounter = 0;
    for (auto x : data)
    {
        if (x->getPesel() == pesel_)
        {
            x->showPerson();
            peselCounter++;
        }
    }
    if (peselCounter == 0)
        cout << "There are no people with the given pesel" << endl;
    else
        cout << "Result: found " << peselCounter << " people" << endl;
}

void Database::sortByLastName() const
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two) {return one->getLastName() < two->getLastName(); });
    cout << "Status: sorting completed" << endl;
}

void Database::sortByPesel() const
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two) {return one->getPesel() < two->getPesel(); });
    cout << "Status: sorting completed" << endl;
}

void Database::sortBySalary() const
{
    std::sort(data.begin(), data.end(), [](Person* one, Person* two) {return one->getSalary() < two->getSalary(); });
    cout << "Status: sorting completed" << endl;
}

void Database::addToExternalFile() const
{
    if (data.size())
    {
        std::ofstream outFile("DATABASE.txt", std::ios_base::out | std::ios_base::ate | std::ios_base::app);
        for (auto x : data)
        {
            if (x->getIndex() == 0)
                outFile << "Status:\t\temployee" << endl;
            else
                outFile << "Status:\t\tstudent" << endl;
            outFile << "First name:\t" << x->getFirstName() << endl;
            outFile << "Last name:\t" << x->getLastName() << endl;
            outFile << "Pesel:\t\t" << x->getPesel() << endl;
            outFile << "Gender:\t\t" << x->getGender() << endl;
            outFile << "Adress:\t\t" << x->getAdress() << endl;
            if (x->getIndex() == 0)
                outFile << "Salary:\t\t" << x->getSalary() << "$" << endl << endl;
            else
                outFile << "Index:\t\t" << x->getIndex() << endl << endl;
        }
        outFile.close();
        cout << "Status: save completed" << endl;
    }
    else
        cout << "There are no students in the database" << endl;
}

void Database::loadFromExternalFile() const
{
    try
    {
        std::string textFromFile;
        std::ifstream inFile("DATABASE.txt");
        if (inFile.is_open())
        {
            std::cout << "Studenst loaded from external file: " << std::endl << std::endl;
            while (!inFile.eof())
            {
                getline(inFile, textFromFile);
                cout << textFromFile << std::endl;
            }
        }
        else
            throw InvalidFile();
    }
    catch (InvalidFile& exception)
    {
        cout << exception.what() << endl;
    }
    catch (std::exception& exception)
    {
        cout << exception.what() << endl;
    } 
}



