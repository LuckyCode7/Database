#pragma once
#include <../inc/DataValidator.hpp>

class PeselValidator : public DataValidator
{
private:
    static bool checkPeselSize(const std::string& pesel)  noexcept;
    static bool checkNumbersDependencies(const std::string& pesel) noexcept;
  public:
    static bool checkPesel(const std::string& pesel)  noexcept;
};
