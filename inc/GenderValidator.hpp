#pragma once
#include <../inc/DataValidator.hpp>

class GenderValidator : public DataValidator
{
private:
    static std::string man;
    static std::string woman;
  public:
    static bool checkGender(const std::string& gender)  noexcept;
};
