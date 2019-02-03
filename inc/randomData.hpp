#pragma once
#include <../inc/Adress.hpp>
#include <array>
#include <unordered_set>
#include <string>

namespace RandomData
{
    std::array<std::string, 10> randomFirstName = { "rafal", "marek", "maciek", "piotrek", "ula",
        "klaudia", "dominika", "tomek", "jan", "darek" };

    std::array<std::string, 10> randomLastName = { "szybki", "wolny", "bystry", "michalewski", "miejski",
        "nowy", "podlejski", "wawrzynek", "lichy", "staszewski" };

    std::array<std::string, 10> randomPesel = { "93011397014", "25040751910", "44051401359", "00302557202", "91051962012",
        "76871321706", "98111588700", "08260128313", "96122729307", "04231446613" };

    std::array<std::string, 2> randomGender = { "man", "woman" };

    std::array<Adress, 10> randomAdress = { Adress("warszawa","cicha",5), Adress("warszawa","cicha",7), Adress("kalisz","grunwaldzka",4), Adress("Poznan","spokojna",90),
        Adress("krakow","morska",13), Adress("lodz","boska",9), Adress("Kielce","powstancow",13), Adress("gdynia","lokietka",41), Adress("wroclaw","podwawelska",3), Adress("wroclaw","prosta",4) };

    std::array<int, 10> randomIndex = { 123456, 467894, 378904, 234799, 456734, 678903, 136009, 567112, 789034, 996615 };

    std::array<int, 10> randomSalary = { 1000,2000,3000,4000,5000,6000,7000,8000,9000,10000 };

    std::unordered_set<int> uniqueRandomNumbers;
}
