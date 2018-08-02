#include "Database.hpp"
#include "Student.hpp"
#include "Employee.hpp"

namespace randomData
{
    std::array<string, 10> randomFirstName = { "rafal", "marek", "maciek", "piotrek", "ula",
        "klaudia", "dominika", "tomek", "jan", "darek" };

    std::array<string, 10> randomLastName = { "szybki", "wolny", "bystry", "michalewski", "miejski",
        "nowy", "podlejski", "wawrzynek", "lichy", "staszewski" };

    std::array<string, 10> randomPesel = { "93011397014", "25040751910", "44051401359", "00302557202", "91051962012",
        "76871321706", "98111588700", "08260128313", "96122729307", "04231446613" };

    std::array<string, 2> randomGender = { "man", "woman" };

    std::array<string, 10> randomAdress = { "warszawa, 15 cicha", "warszawa, 7 cicha", "kalisz, 4 grunwaldzka", "poznan, 90 spokojna",
        "krakow, 90 spokojna", "lodz, 99 bloska", "kielce, 1 powstancow", "gdynia, 67 lokietka", "wroclaw, 3 podwawelska", "wroclaw, 4 prosta" };

    std::array<int, 10> randomIndex = { 123456, 467894, 378904, 234799, 456734, 678903, 136009, 567112, 789034, 996615 };

    std::array<int, 10> randomSalary = { 1000,2000,3000,4000,5000,6000,7000,8000,9000,10000 };

    std::set<int> number;
}

std::vector<Person*> data;

Database::Database() {}

Database::~Database() {}

void Database::randomUniqueNumber() const
{
    int temporaryNumber;
    srand(time(0));
    while (randomData::number.size() != 6)
    {
        temporaryNumber = rand() % 10;
        randomData::number.insert(temporaryNumber);
    }
}

void Database::foundPersonResult(const int& result) const
{
    if (result == 0)
        cout << "Result: no recrods found" << endl;
    else
        cout << "Result: found " << result << " records" << endl;
}

bool Database::fileOperationResult() const
{
    if (data.size())
    {
        cout << "Result: save completed" << endl;
        return true;
    }
    else
    {
        cout << "Result: database is empty !" << endl;
        return false;
    }
}

void Database::modificationResult(bool result, const string& pesel_) const
{
    if (result)
        cout << "Result: operation completed" << endl;
    else
        cout << "There is no person with the given pesel: " << pesel_ << endl;
}

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
    foundPersonResult(lastNamecounter);
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
    foundPersonResult(peselCounter);
}

void Database::sortByLastName() const
{
    if (data.size() > 1)
    {
        std::sort(data.begin(), data.end(), [](Person* one, Person* two) {return one->getLastName() < two->getLastName(); });
        cout << "Status: sorting completed" << endl;
    }
}

void Database::sortByPesel() const
{
    if (data.size() > 1)
    {
        std::sort(data.begin(), data.end(), [](Person* one, Person* two) {return one->getPesel() < two->getPesel(); });
        cout << "Status: sorting completed" << endl;
    }
}

void Database::sortBySalary() const
{
    if (data.size() > 1)
    {
        std::sort(data.begin(), data.end(), [](Person* one, Person* two) {return one->getSalary() < two->getSalary(); });
        cout << "Status: sorting completed" << endl;
    }
}

void Database::addToExternalFile() const
{
    if (fileOperationResult())
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
    }
}

void Database::loadFromExternalFile() const
{
    try
    {
        std::string textFromFile;
        std::ifstream inFile("DATABASE.txt");
        if (inFile.is_open())
        {
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

void Database::removePerson(const string& pesel_) const
{
    bool correctPesel = false;
    for (auto x = data.begin(); x != data.end(); x++)
    {
        if ((*x)->getPesel() == pesel_)
        {
            data.erase(x);
            correctPesel = true;
            break;
        }
    }
    modificationResult(correctPesel, pesel_);
}

void Database::changeEmployeeSalary(const string& pesel_, const int& salary_) const
{
    bool correctPesel = false;
    for (auto x = data.begin(); x != data.end(); x++)
    {
        if ((*x)->getPesel() == pesel_ && (*x)->getIndex() == 0)
        {
            correctPesel = true;
            (*x)->setSalary(salary_);
            break;
        }
    }
    modificationResult(correctPesel, pesel_);
}

void Database::changeAdress(const string & pesel_, const string & adress_) const
{
    bool correctPesel = false;
    for (auto x = data.begin(); x != data.end(); x++)
    {
        if ((*x)->getPesel() == pesel_)
        {
            (*x)->setAdress(adress_);
            correctPesel = true;
            break;
        }
    }
    modificationResult(correctPesel, pesel_);
}

void Database::setRandomData() const
{
    using namespace randomData;
    std::array<int, 6> i;
    int j = 0;
    randomUniqueNumber();
    for (auto x : number)
    {
        i[j] = x;
        j++;
    }
    clearDatabase();
    srand(time(0));
    static Student s1(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[0]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomIndex[rand() % 10]);
    static Student s2(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[1]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomIndex[rand() % 10]);
    static Student s3(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[2]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomIndex[rand() % 10]);
    static Employee e1(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[3]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomSalary[rand() % 10]);
    static Employee e2(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[4]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomSalary[rand() % 10]);
    static Employee e3(randomFirstName[rand() % 10], randomLastName[rand() % 10], randomPesel[i[5]], randomGender[rand() % 2],
        randomAdress[rand() % 10], randomSalary[rand() % 10]);

    addToDatabase(&s1);
    addToDatabase(&s2);
    addToDatabase(&s3);
    addToDatabase(&e1);
    addToDatabase(&e2);
    addToDatabase(&e3);
}

void Database::clearDatabase() const
{
    data.clear();
}



