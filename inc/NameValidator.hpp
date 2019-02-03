#pragma once
#include <../inc/DataValidator.hpp>

class NameValidator : public DataValidator
{
  public:
    static bool checkName(const std::string& name)  noexcept;
};
