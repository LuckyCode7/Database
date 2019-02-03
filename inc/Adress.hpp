#pragma once
#include <string>

class Adress
{
private:
    std::string city;
    std::string street;
    int numberOfStreet;
public:
    Adress() = default;
    Adress(const std::string& city_, const std::string street_, const int numberOfStreet);
    ~Adress() = default;
    Adress(const Adress&) = default;
    Adress& operator=(const Adress&) = default;
    bool operator==(const Adress& adress_) const noexcept;
    void setCity(const std::string& city_) noexcept;
    void setStreet(const std::string& street_) noexcept;
    void setNumberOfStreet(const int number) noexcept;
    std::string getCity() const noexcept;
    std::string getStreet() const noexcept;
    std::string toString() const noexcept;
    int getNumberOfStreet() const noexcept;
};
